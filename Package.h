#include <iostream>
#include <string>
#include<cassert>
using namespace std;

//By: Gianluca Venditti
//Date: November 22nd 2021
//Specification file that defines all the classes

class Package
{
public:
	Package();
	Package(string /*source*/, string /*destination*/);
	virtual ~Package();
	virtual double computeShipCost() const { return 0.0; }
	string getSource() const { return *source; }
	string getDestination() const { return *destination; }

protected:
	string* source;
	string* destination;
};

class Letter : public Package
{
public:
	Letter();
	Letter(int /*number of pages*/, string /*source*/, string /*destination*/);
	double computeShipCost() const;
	int getNoPages()const { return noPages; }

private:
	int noPages;
};

class Box : public Package
{
public:
	Box();
	Box(int /*weight*/, string /*source*/, string /*destination*/);
	double computeShipCost() const;
	int getWeight() const { return weight; }

private:
	int weight;
};