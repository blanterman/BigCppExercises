#include "ccc_win.h"
#include "House.h"

House::House()
{
	house_number = 0.0;
	location = Point(0.0, 0.0);
}

House::House(double hn, Point loc)
{
	house_number = hn;
	location = loc;
}

Point House::get_location() const
{
	return location;
}

void House::plot(double corr) const
{
	if(corr > 1.0)
		corr = 1.0; // puts an upper limit on size change

	//Constructs and draws the house out of points and lines
	Point br = location;
	br.move(corr, 0.0);
	Point tl = location;
	tl.move(0.0, corr);
	Point tr = location;
	tr.move(corr, corr);
	Point t = location;
	t.move(0.5 * corr, 1.5 * corr);
	Line b(location, br);
	Line l(location, tl);
	Line r(br, tr);
	Line u(tl, tr);
	Line rl(tl, t);
	Line rr(tr, t);
	cwin << b << l << r << u << rl << rr;
	cwin << Message(location, house_number);
}