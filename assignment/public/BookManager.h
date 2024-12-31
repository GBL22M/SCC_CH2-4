#pragma once

#include <vector>
#include "Book.h"
using namespace std;

class BookManager
{
public:
	~BookManager();
	void AddBook(string title, string author);
	void DisplayAllBooks();
	void SearchByTitle(string title);
	void SearchByAuthor(string author);
	
	// new method
	Book* GetBookByTitle(string title);
	Book* GetBookByAuthor(string author);

protected:
	Book* FindBookByTitle(string title);
	Book* FindBookByAuthor(string author);	

private:
	vector<Book*> books;
};