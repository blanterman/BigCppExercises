#include "ccc_win.h"
#include "ccc_time.h"
#include <cstdlib>
#include <ctime>

/**
	A clock that can draw its face
*/
class Clock
{
public:
	/**
		Constructs a clock with a given center and radius
		@param c center of clock face
		@param r radius of clock face
	*/
	Clock(Point c, double r);

	/**
		Sets the time for the clock
	*/
	void set_time(Time t);

	/**
		Draws the clock face, ticks, and hands
	*/
	void draw() const;

private:
	/**
		Draw a tick mark (Hour or Minute mark).
		@param angle the angle of the tick mark
		@param length the length of the tick mark
	*/
	void draw_tick(double angle, double length) const;
	/**
		Draw the clock hands at the current time
	*/
	void draw_hands() const;

	Time current_time;
	Point center;
	double radius;
};

Clock::Clock(Point c, double r)
{
	center = c;
	radius = r;
}

void Clock::set_time(Time t)
{
	current_time = t;
}

void Clock::draw_tick(double angle, double length) const
{
	Point from(center.get_x() + (radius - length) * cos(angle), center.get_y() + (radius - length) * sin(angle));
	Point to(center.get_x() + (radius) * cos(angle), center.get_y() + (radius) * sin(angle));
	cwin << Line(from, to);
}

void Clock::draw_hands() const
{
	const double PI = 3.14159265358979323;
	const double HR_LENGTH = 3.0;
	const double MIN_LENGTH = 5.5;
	const double NUM_MINUTES = 60.0;
	const double NUM_HOURS = 12.0;

	double angle_hour_hand = -(((double(current_time.get_hours()) + double(current_time.get_minutes()) / NUM_MINUTES)/ NUM_HOURS) * 2.0 * PI - PI / 2.0);
	Point from = center;
	Point toH(center.get_x() + HR_LENGTH * cos(angle_hour_hand), center.get_y() + HR_LENGTH * sin(angle_hour_hand));
	cwin << Line(from, toH);

	double angle_min_hand = -((double(current_time.get_minutes()) / NUM_MINUTES) * 2.0 * PI - PI / 2.0);
	Point toM(center.get_x() + MIN_LENGTH * cos(angle_min_hand), center.get_y() + MIN_LENGTH * sin(angle_min_hand));
	cwin << Line(from, toM);
}

void Clock::draw() const
{
	const double PI = 3.14159265358979323;
	const double NUM_TICKS = 60.0;
	const double TICK_LEN = 0.5;
	const int LARGE_TICK_INTERVAL = 5;
	const double LARGE_TICK_LEN = 1.0;

	cwin << Circle(center, radius);

	for (int i = 0; i < NUM_TICKS; i++)
	{
		if (i % LARGE_TICK_INTERVAL == 0)
		{
			draw_tick(2 * PI / NUM_TICKS * i, LARGE_TICK_LEN);
		}
		else 
		{
			draw_tick(2 * PI / NUM_TICKS * i, TICK_LEN);
		}
	}
	draw_hands();

	// Draw the numbers
	Point p12(-.25, 5.7);
	cwin << Message(p12, 12);
	Point p1(2.6, 5);
	cwin << Message(p1, 1);
	Point p2(4.5, 3.2);
	cwin << Message(p2, 2);
	Point p3(5, 0.32);
	cwin << Message(p3, 3);
	Point p4(4.28, -2.17);
	cwin << Message(p4, 4);
	Point p5(2.25, -4.0);
	cwin << Message(p5, 5);
	Point p6(-.25, -5.0);
	cwin << Message(p6, 6);
	Point p7(-2.8, -4.2);
	cwin << Message(p7, 7);
	Point p8(-4.8, -2.3);
	cwin << Message(p8, 8);
	Point p9(-5.6, 0.32);
	cwin << Message(p9, 9);
	Point p10(-4.8, 3.15);
	cwin << Message(p10, 10);
	Point p11(-3.0, 4.8);
	cwin << Message(p11, 11);
}

/**
	The player of the Clock Game
*/
class Player
{
public:
	/**
		Constructs a player with no name and a level of 1
	*/
	Player();
	/**
		Constructs a player with given name and level
		@param n name of the Player
		@param 
	*/
	Player(std::string n, int l);
	/**
		Increments the players score and increments the level when needed
	*/
	void increment_score();
	/**
		Returns the players level
	*/
	int get_level() const;
	/**
		Returns the player's name
	*/
	std::string get_name() const;
private:
	std::string name;
	int level;
	int score;
};

Player::Player()
{
	score = 0;
	level = 1;
}

Player::Player(std::string n, int l)
{
	name = n;
	level = l;
	score = 0;
}

void Player::increment_score()
{
	score++;
	if (score % 5 == 0)
	{
		level++;
		if (level > 5)
		{
			level = 5;
		}
	}
}

std::string Player::get_name() const
{
	return name;
}

int Player::get_level() const
{
	return level;
}

/**
	The Clock Game
*/
class Game
{
public:
	/**
		Constructs the game with a default player
	*/
	Game();
	/**
		Plays the game while the player wants to continue
	*/
	void play_game();
	/**
		Reads Player name and level
	*/
	void read_player_information();
	/**
		Plays a round with upto two tries
	*/
	void play_round();
private:
	/**
		Makes a random time depending on the level
		@return the random time
	*/
	Time random_time();
	/**
		Gets a time input from the user
		@return the time guessed by the user
	*/
	Time get_guess();
	/**
		Formats the time into a string for display
		@param t time to be formatted
		@return string time formatted as: hh:mm or h:mm
	*/
	std::string format_time(Time t);
	Player player;
};

/**
	Set s the seed of the random number generator
*/
void rand_seed()
{
	srand(time(NULL));
}

/**
	Returns a random integer in a range
	@param a the bottom of the range
	@param b the top of the range
	@return a random number x, a <= x <= b
*/
int rand_int(int a, int b)
{
	return a + rand() % (b - a + 1);
}

Game::Game()
{
}

void Game::play_game()
{
	rand_seed();
	read_player_information();
	std::string response;
	do
	{
		play_round();
		response = cwin.get_string("Press Enter to continue.");
	} 
	while (true);
}

void Game::read_player_information()
{
	std::string name = cwin.get_string("What is your name?");
	int level = 6;
	do
	{
		level = cwin.get_int("What level do you want to start on? (1 - 5)");
	} 
	while (1 > level || level > 5);
	player = Player(name, level);
}

void Game::play_round()
{
	cwin.clear();
	Time time_to_guess = random_time();
	Point clk_center(0.0, 0.0);
	const double CLOCK_RADIUS = 7.0;
	Clock clk(clk_center, CLOCK_RADIUS);
	clk.set_time(time_to_guess);
	clk.draw();

	std::string text;
	std::string time_string;
	Time guess = get_guess();
	if (time_to_guess.seconds_from(guess) != 0)
	{
		text = "Please try again:";
		cwin << Message(Point(-CLOCK_RADIUS, CLOCK_RADIUS + 1), text);
		guess = get_guess();
	}
	if (time_to_guess.seconds_from(guess) != 0)
	{
		time_string = format_time(time_to_guess);
		text = "Sorry, " + player.get_name() + ". That is incorrect. Correct time: " + time_string + ".";
	}
	else
	{
		text = "Congratulations, " + player.get_name() + "! That is correct.";
		player.increment_score();
	}
	cwin.clear();
	clk.draw();
	cwin << Message(Point(-CLOCK_RADIUS, CLOCK_RADIUS + 1), text);
}

Time Game::random_time()
{
	int level = player.get_level();
	int minutes;
	if (level == 1)
	{
		minutes = 0;
	}
	else if (level == 2)
	{
		minutes = 30 * rand_int(0, 1);
	}
	else if (level == 3)
	{
		minutes = 15 * rand_int(0, 3);
	}
	else if (level == 4)
	{
		minutes = 5 * rand_int(0, 11);
	}
	else
	{
		minutes = rand_int(0, 59);
	}
	int hours = rand_int(1, 12);

	return Time(hours, minutes, 0);
}

Time Game::get_guess()
{
	int hours;
	do
	{
		hours = cwin.get_int("Please enter hours (1 - 12)");
	} 
	while (1 > hours || hours > 12);
	int minutes;
	do
	{
		minutes = cwin.get_int("Please enter minutes (0 - 59)");
	} while (0 > minutes || minutes > 59);

	return Time(hours, minutes, 0);
}

std::string Game::format_time(Time t)
{
	bool leading_zero = (0 <= t.get_minutes() && t.get_minutes() <= 9);
	std::string minutes;
	if (leading_zero)
	{
		minutes = "0" + to_string(t.get_minutes());
	}
	else
	{
		minutes = to_string(t.get_minutes());
	}
	return to_string(t.get_hours()) + ":" + minutes;
}


int ccc_win_main()
{
	Game clock_game;
	clock_game.play_game();

	return 0;
}