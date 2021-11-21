#include "Package.h"

//By: Gianluca Venditti
//Date: November 22nd 2021
//Implementation file

//Package 
Package::Package()
{
	source = new string; 
	assert(source); 
	destination = new string; 
	assert(destination);

	cout << "Please enter source: " << endl; 
	getline(cin, *source);

	while (source->length() == 0)
	{
		cout << "Error! Please enter a valid source: ";
		getline(cin, *source);
	}

	cout << "Please enter destination: " << endl;
	getline(cin, *destination);

	while (destination->length() == 0)
	{
		cout << "Error! Please enter a valid destination: ";
		getline(cin, *destination);
	}
}

Package::Package(string newSource, string newDestination)
{
	source = new string(newSource.length() == 0 ? "NO NAME" : newSource);
	assert(source);

	destination = new string(newDestination.length() == 0 ? "NO NAME" : newDestination);
	assert(destination);
}

Package::~Package()
{
	delete source;
	delete destination;
}

//Box
Box::Box() : Package()
{
	cout << "Please enter weight: " << endl; 
	cin >> weight; 

	while (cin.fail() || weight <= 0 || weight >=200)
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Error! Please enter a range between 0 and 200: " << endl;
		cin >> weight; 
	}
	cin.ignore(80, '\n');
}

Box::Box(int newWeight, string newSource, string newDestination) :Package(newSource, newDestination)
{
	weight = newWeight < 0 || newWeight > 100 ? 0 : newWeight;
}

double Box::computeShipCost() const
{
	double cost;
	if (weight < 5)
	{
		cost = .79;
	}
	else if (weight >= 5 && weight <= 15)
	{
		cost = 2.75;
	}
	else
	{
		cost = 4.75;
	}

	return cost;
}

//Letter
Letter::Letter() : Package()
{
	cout << "Please enter number of pages: " << endl;
	cin >> noPages;

	while (cin.fail() || noPages < 0 || noPages > 50)
	{
		cin.clear();
		cin.ignore(80, '\n');
		cout << "Error! Please enter a range between 0 and 50: " << endl;
		cin >> noPages;
	}
	cin.ignore(80, '\n');
}

Letter::Letter(int newNoPages, string newSource, string newDestination) : Package(newSource, newDestination)
{
	noPages = newNoPages > 0 && newNoPages < 50 ? newNoPages : 0;
}

double Letter::computeShipCost() const
{
	double cost;
	if (noPages >= 1 && noPages <= 5)
	{
		cost = .45;
	}
	else if (noPages >= 6 && noPages <= 20)
	{
		cost = .70;
	}
	else if (noPages >= 21 && noPages <= 85)
	{
		cost = 1.35;
	}
	else
	{
		cost = 2.89;
	}

	return cost;
}