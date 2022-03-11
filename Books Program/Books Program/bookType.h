#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class bookType
{

	// member variables
private:
	string title;
	string authors[4];
	string publisher;
	string ISBN;

	double price;

	int copies;
	int numAuthors;

	// methods
public:
	bookType();
	bookType(string newTitle, string newAuthors[4], string newPublisher, string newISBN, double newPrice, int newCopies, int newNumAuthors);

	void setTitle(string newTitle);
	void setAuthors(string newAuthors[4]);
	void setPublisher(string newPublisher);
	void setISBN(string newISBN);
	void setPrice(double newPrice);
	void setCopies(int newCopies);
	void setNumAuthors(int newNumAuthors);

	string getTitle();
	void getAuthors();
	string getPublisher();
	string getISBN();
	double getPrice();
	int getCopies();
	int getNumAuthors();

	void printInfo();

};
