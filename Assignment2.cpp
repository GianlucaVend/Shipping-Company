#include "Package.h"

//By: Gianluca Venditti
//Date: November 22nd 2021
//Client Code
//Purpose: To write a program for a shipping company that delivers boxes and letters to its customers.

void show(const Package* objectOne);

int main()
{
	cout << "Creating objects on the Stack" << endl << endl;

	Package PackageOne("Mail", "Kingston");
	cout << "Source for PackageOne is " << PackageOne.getSource() << endl;
	cout << "Destintion for PackageOne is " << PackageOne.getDestination() << endl << endl;

	Box BoxOne(30, "Mail", "Toronto");
	cout << "Weight of box is " << BoxOne.getWeight() << endl;
	cout << "Source for BoxOne is " << BoxOne.getSource() << endl;
	cout << "Destintion for BoxOne is " << BoxOne.getDestination() << endl << endl;

	Letter LetterOne(40, "Mail", "Ottawa");
	cout << "Number of Pages for letter are " << LetterOne.getNoPages() << endl;
	cout << "Source for PackageOne is " << LetterOne.getSource() << endl;
	cout << "Destintion for PackageOne is " << LetterOne.getDestination() << endl << endl << endl;

	cout << "Creating objects on the Heap" << endl << endl;

	Package* PackageTwo = new Package("Plane", "Kingston");
	assert(PackageTwo);
	cout << "Number of PackageTwo shipping cost is: " << PackageTwo->computeShipCost() << endl << endl;
	cout << "Source for PackageOne is " << PackageTwo->getSource() << endl;
	cout << "Destintion for PackageOne is " << PackageTwo->getDestination() << endl << endl;

	Box* BoxTwo = new Box(20, "Mail", "Toronto");
	assert(BoxTwo);
	cout << "Number of BoxTwo shipping cost is: " << BoxTwo->computeShipCost() << endl << endl;
	cout << "Source for PackageOne is " << BoxTwo->getSource() << endl;
	cout << "Destintion for PackageOne is " << BoxTwo->getDestination() << endl << endl;

	Letter* LetterTwo = new Letter(30, "Mail", "Toronto");
	assert(LetterTwo);
	cout << "Number of LetterTwo shipping cost is: " << LetterTwo->computeShipCost() << endl << endl;
	cout << "Source for PackageOne is " << LetterTwo->getSource() << endl;
	cout << "Destintion for PackageOne is " << LetterTwo->getDestination() << endl << endl;

	cout << "Calling Polymorphic functions" << endl << endl;

	show(&PackageOne);
	show(PackageTwo);
	show(&BoxOne);
	show(BoxTwo);
	show(&LetterOne);
	show(LetterTwo);

	delete PackageTwo;
	delete BoxTwo;
	delete LetterTwo;

	system("pause");
}

void show(const Package* objectOne)
{
	cout << "Shipping Cost: " << objectOne->computeShipCost() << endl << endl;
}

/*
Creating objects on the Stack

Source for PackageOne is Mail
Destintion for PackageOne is Kingston

Weight of box is 30
Source for BoxOne is Mail
Destintion for BoxOne is Toronto

Number of Pages for letter are 40
Source for PackageOne is Mail
Destintion for PackageOne is Ottawa


Creating objects on the Heap

Number of PackageTwo shipping cost is: 0

Source for PackageOne is Plane
Destintion for PackageOne is Kingston

Number of BoxTwo shipping cost is: 4.75

Source for PackageOne is Mail
Destintion for PackageOne is Toronto

Number of LetterTwo shipping cost is: 1.35

Source for PackageOne is Mail
Destintion for PackageOne is Toronto

Calling Polymorphic functions

Shipping Cost: 0

Shipping Cost: 0

Shipping Cost: 4.75

Shipping Cost: 4.75

Shipping Cost: 1.35

Shipping Cost: 1.35

Press any key to continue . . .
*/