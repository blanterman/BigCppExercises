/* This is a case study from Big C++ Chapter 13.7 for printing an invoice.
Requirements
The task of this program is to print out an invoice. An invoice describes the 
charges for a set of products in certain quantities. (complexities such as 
dates, taxes, and invoice and customer numbers are omitted.) the progrtam 
simply prints the billing address, all line items, and the amount due. Each 
line item contains the description and the unit price of a product, the 
quantity ordered, and the total price.

                  I N V O I C E 
   Sam's Small Appliances
   100 Main street
   Anytown, CA 98765

   Description					Price   Qty   total
   Toaster						29.95    3	  89.85
   Hair dryer					24.95	 1    24.95
   Car vacuum					19.99    2	  39.98

   AMOUNT DUE: $154.78

Also, in the interest of simplicity, no user interface is required. Simply use 
a test harness that adds items to the invoice and then prints it.


Bryson Lanterman 20210324
*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

/**
	Describes a product with a description and a price.
*/
class Product
{
public:
	Product();
	Product(std::string desc, double uPrice);
	/**
		Gets the description of the product
		@return the description of the product
	*/
	std::string get_description() const;
	/**
		Gets the unit price of the product
		@return the unit price of the product
	*/
	double get_unit_price() const;
private:
	std::string description;
	double unitPrice;
};

Product::Product()
{
	unitPrice = 0.0;
}

Product::Product(std::string desc, double uPrice)
{
	description = desc;
	unitPrice = uPrice;
}

std::string Product::get_description() const
{
	return description;
}

double Product::get_unit_price() const
{
	return unitPrice;
}

/**
	Describes a quantity of an article to purchase and its price.
*/
class Item
{
public:
	Item();
	Item(Product p, int q);
	/**
		Computes the total cost of this item
		@return the total price
	*/
	double get_total_price() const;
	/**
		prints this item
	*/
	void print() const;
private:
	Product prod;
	int quantity;
};

Item::Item()
{
	quantity = 0;
}

Item::Item(Product p, int q)
{
	prod = p;
	quantity = q;
}

double Item::get_total_price() const
{
	return prod.get_unit_price() * quantity;
}

void Item::print() const
{
	const int COLUMN_WIDTH = 30;
	std::string description = prod.get_description();

	std::cout << description;

	//pad with spaces to fill column

	int pad = COLUMN_WIDTH - description.length();
	for (int i = 1; i <= pad; i++)
	{
		std::cout << " ";
	}

	std::cout << prod.get_unit_price() 
		<< "   " << quantity 
		<< "    " << get_total_price() 
		<< "\n";

}

/**
	Describes a mailing address
*/
class Address
{
public:
	Address();
	Address(std::string n, std::string s, std::string c, std::string st, std::string z);
	/**
		Prints the address
	*/
	void print() const;
private:
	std::string name;
	std::string street;
	std::string city;
	std::string state;
	std::string zip;
};

Address::Address()
{

}

Address::Address(std::string n, std::string s, std::string c, std::string st, std::string z)
{
	name = n;
	street = s;
	city = c;
	state = st;
	zip = z;
}

void Address::print() const
{
	std::cout << name << "\n" 
		<< street << "\n" 
		<< city << ", " << state << " " << zip << "\n";
}

/**
	Describes the invoice for a set of purchased products
*/
class Invoice
{
public:
	Invoice(Address a);
	/**
		Adds a charge for a product to this invoice.
		@param p the product that the customer ordered
		@param quantity the quantity of the product
	*/
	void add(Product p, int quantity);
	/**
		Prints the invoice
	*/
	void print() const;
private:
	std::vector<Item> items;
	Address billing_address;
};

Invoice::Invoice(Address a)
{
	billing_address = a;
}

void Invoice::add(Product p, int quantity)
{
	Item item(p, quantity);
	items.push_back(item);
}

void Invoice::print() const
{
	std::cout << "                   I N V O I C E\n\n";
	billing_address.print();
	std::cout << "\n\nDescription                   Price   Qty   Total\n";
	for (int i = 0; i < items.size(); i++)
	{
		items[i].print();
	}
	
	double amount_due = 0;
	for (int i = 0; i < items.size(); i++)
	{
		amount_due = amount_due + items[i].get_total_price();
	}

	std::cout << "\nAMOUNT DUE: $" << amount_due;
}

// Test Harness
int main()
{
	Address brysonAddress("Bryson's Fake Business", "1234 Middle of Knowwhere", "Rancho Cucamonga", "CA", "90210");
	Invoice brysonInvoice(brysonAddress);
	brysonInvoice.add(Product("Rubiks Cube", 10.05), 21);
	brysonInvoice.add(Product("Stack Matt", 25.08), 34);
	brysonInvoice.add(Product("Table Timer", 40.13), 55);
	brysonInvoice.print();
	return 0;
}