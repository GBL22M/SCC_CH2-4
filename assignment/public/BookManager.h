#pragma once

#include <vector>
#include "Book.h"
using namespace std;

class BookManager
{
public:
	void AddBook(string title, string author);
	void DisplayAllBooks();
	void SearchByTitle(string title);
	void SearchByAuthor(string author);


private:
	vector<Book> books;
};