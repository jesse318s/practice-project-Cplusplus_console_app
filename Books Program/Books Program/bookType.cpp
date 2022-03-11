#include "bookType.h"
#include <iostream>
#include <string>
#include <iomanip>

// constructors
bookType::bookType()
{

	title = "";
	authors[0] = "";
	authors[1] = "";
	authors[2] = "";
	authors[3] = "";
	publisher = "";
	ISBN = "";
	price = 0;
	copies = 0;
	numAuthors = 0;

}
bookType::bookType(string newTitle, string newAuthors[4], string newPublisher, string newISBN, double newPrice, int newCopies, int newNumAuthors)
{

	title = newTitle;
	authors[0] = newAuthors[0];
	authors[1] = newAuthors[1];
	authors[2] = newAuthors[2];
	authors[3] = newAuthors[3];
	publisher = newPublisher;
	ISBN = newISBN;
	price = newPrice;
	copies = newCopies;
	numAuthors = newNumAuthors;

}

// methods
void bookType::setTitle(string newTitle)
{

	title = newTitle;

}
void bookType::setAuthors(string newAuthors[4])
{

	authors[0] = newAuthors[0];
	authors[1] = newAuthors[1];
	authors[2] = newAuthors[2];
	authors[3] = newAuthors[3];

}
void bookType::setPublisher(string newPublisher)
{

	publisher = newPublisher;

}
void bookType::setISBN(string newISBN)
{

	ISBN = newISBN;

}
void bookType::setPrice(double newPrice)
{

	price = newPrice;

}
void bookType::setCopies(int newCopies)
{

	copies = newCopies;

}
void bookType::setNumAuthors(int newNumAuthors)
{

	numAuthors = newNumAuthors;

}

string bookType::getTitle()
{

	return title;

}
void bookType::getAuthors()
{

	for (int i = 0; i < numAuthors; i++)
	{

		cout << "Author #" << i + 1 << ": " << authors[i] << endl;

	}

}
string bookType::getPublisher()
{

	return publisher;

}
string bookType::getISBN()
{

	return ISBN;

}
double bookType::getPrice()
{

	return price;

}
int bookType::getCopies()
{

	return copies;

}
int bookType::getNumAuthors()
{

	return numAuthors;

}

void bookType::printInfo()
{

	cout << "\nBook details -\nTitle: " << getTitle() << endl;
	getAuthors();
	cout << "Publisher: " << getPublisher() << "\nISBN: " << getISBN() << "\nPrice: $" << fixed << showpoint << setprecision(2) << getPrice()
		<< scientific << noshowpoint << setprecision(6) << "\nCopies: " << getCopies() << "\nNumber of authors: " << getNumAuthors() << endl;

}