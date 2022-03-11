// Books Program.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "bookType.h"

using namespace std;

// function prototypes
void searchBooks(bookType[100]);
void addBook(bookType[100]);
void updateBookCopies(bookType[100]);
void updateBookPrice(bookType[100]);

int main()
{

	// variables
	int* menuChoicePointer;
	int menuChoice = 0;

	bookType* booksPointer;
	bookType books[100];

	// assign pointer values
	menuChoicePointer = &menuChoice;
	booksPointer = books;

	// check for "Exit Program" input
	while (*menuChoicePointer != 5)
	{

		// outputs menu and inputs choice
		cout << "\n1. Search for book by title or ISBN.\n2. Add a new book to inventory.\n3. Update the number of copies on hand.\n4. Update the price of book.\n5. Exit Program.\n";

		cin >> *menuChoicePointer;

		// processes menu choice
		switch (*menuChoicePointer)
		{

		case 1:
			searchBooks(booksPointer);
			break;
		case 2:
			addBook(booksPointer);
			break;
		case 3:
			updateBookCopies(booksPointer);
			break;
		case 4:
			updateBookPrice(booksPointer);
			break;

		}

	}

}

// function definitions
void searchBooks(bookType books[100])
{

	// local variables
	int searchChoice = 0;

	string searchBook = "";

	bool bookFound = false;

	// outputs search menu and inputs choice
	cout << "\n1. Search for book by title.\n2. Search for book by ISBN.\n";

	cin >> searchChoice;

	// processes search menu choice
	if (searchChoice == 1)
	{

		// inputs search title
		cout << "\nPlease enter the book title you wish to search for:\n";

		cin.ignore();
		getline(cin, searchBook);

		cout << endl;

		// begins title search
		for (int i = 0; i < 100; i++)
		{

			// displays book details if found
			if (books[i].getTitle() == searchBook)
			{

				bookFound = true;

				books[i].printInfo();



			}

			// alerts user if book is not found
			if (i == 99 && bookFound == false)
			{

				cout << "\nBook by title is not in inventory.\n";

			}

		}

	}
	else if (searchChoice == 2)
	{

		// inputs search ISBN
		cout << "\nPlease enter the book ISBN you wish to search for:\n";

		cin.ignore();
		getline(cin, searchBook);

		cout << endl;

		// begins ISBN search
		for (int i = 0; i < 100; i++)
		{

			// displays book details if found
			if (books[i].getISBN() == searchBook)
			{

				bookFound = true;

				books[i].printInfo();

				i = 100;

			}

			// alerts user if book is not found
			if (i == 99 && bookFound == false)
			{

				cout << "\nBook by ISBN is not in inventory.\n";

			}

		}

	}

}

void addBook(bookType books[100])
{

	// local variables
	bool bookFound = false;

	string newBookTitle = "";
	string newBookPublisher = "";
	string newBookISBN = "";
	string newBookAuthors[4] = {};

	double newBookPrice;

	int addCopies = 0;
	int newNumAuthors;

	// inputs search title
	cout << "\nPlease enter the title of the book you wish to add:\n";

	cin.ignore();
	getline(cin, newBookTitle);

	cout << endl;

	// begins title search
	for (int i = 0; i < 100; i++)
	{

		// alerts user if book exists, gets copies input, and then updates copies
		if (books[i].getTitle() == newBookTitle)
		{

			bookFound = true;

			cout << "\nBook already exists.\nPlease enter how many copies you'd like to add:\n";

			cin >> addCopies;

			books[i].setCopies(books[i].getCopies() + addCopies);

			i = 100;

		}

	}

	// inputs new book variables
	if (bookFound == false)
	{

		for (int j = 0; j < 4; j++)
		{

			cout << "\nPlease enter author #" << j + 1 << " or \"ZZZ\" to stop entering authors.\n";

			getline(cin, newBookAuthors[j]);

			if (newBookAuthors[j] == "ZZZ")
			{

				newBookAuthors[j] = "";
				newNumAuthors = j;
				j = 4;

			}

		}

		cout << "\nPlease enter publisher:\n";

		getline(cin, newBookPublisher);

		cout << "\nPlease enter ISBN:\n";

		getline(cin, newBookISBN);

		cout << "\nPlease enter price:\n";

		cin >> newBookPrice;

		cout << "\nPlease enter how many copies you'd like to add:\n";

		cin >> addCopies;

		// sets new book variables in an empty book array element
		for (int i = 0; i < 100; i++)
		{

			if (books[i].getTitle() == "")
			{

				bookType newBook(newBookTitle, newBookAuthors, newBookPublisher, newBookISBN, newBookPrice, addCopies, newNumAuthors);
				books[i] = newBook;

				i = 100;

			}

		}

	}

}

void updateBookCopies(bookType books[100])
{

	// declare variables
	string searchBook = "";

	bool bookFound = false;

	int newCopies = 0;

	// inputs search title
	cout << "\nPlease enter the title of the book you wish to update the copies for:\n";

	cin.ignore();
	getline(cin, searchBook);

	cout << endl;

	// begins title search
	for (int i = 0; i < 100; i++)
	{

		// gets copies input and updates book copies if found
		if (books[i].getTitle() == searchBook)
		{

			bookFound = true;

			cout << "\nPlease enter the amount of copies in inventory for this book:\n";

			cin >> newCopies;

			books[i].setCopies(newCopies);

			i = 100;

		}

	}

	// alerts user if book is not found
	if (bookFound == false)
	{

		cout << "\nBook is not in inventory.\n";

	}

}

void updateBookPrice(bookType books[100])
{

	// declare variables
	string searchBook = "";

	bool bookFound = false;

	double newPrice = 0;

	// inputs search title
	cout << "\nPlease enter the title of the book you wish to update the price for:\n";

	cin.ignore();
	getline(cin, searchBook);

	cout << endl;

	// begins title search
	for (int i = 0; i < 100; i++)
	{

		// gets copies input and updates book price if found
		if (books[i].getTitle() == searchBook)
		{

			bookFound = true;

			cout << "\nPlease enter the new price of this book:\n";

			cin >> newPrice;

			books[i].setPrice(newPrice);

			i = 100;

		}

	}

	// alerts user if book is not found
	if (bookFound == false)
	{

		cout << "\nBook is not in inventory.\n";

	}

}
