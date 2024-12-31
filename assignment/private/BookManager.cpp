#include "../public/BookManager.h"

void BookManager::AddBook(string title, string author)
{
	Book book(title, author);
	books.push_back(book);
}

void BookManager::DisplayAllBooks()
{
	if (books.empty())
	{
		cout << "Empty!\n";
		return;
	}

	cout << "display all books\n";

	for (const Book& book : books)
	{
		cout << book.GetTitle() << " By " << book.GetAuthor() << "\n";
	}
}

void BookManager::SearchByTitle(string title)
{
	for (const Book& book : books)
	{
		if (book.GetTitle() == title)
		{
			cout << "Find book\n";
			cout << "title: " << title << " " << "author: " << book.GetAuthor() << "\n";
			return;
		}
		cout << "Not exist\n";
	}
}

void BookManager::SearchByAuthor(string author)
{
	for (const Book& book : books)
	{
		if (book.GetAuthor() == author)
		{
			cout << "Find book\n";
			cout << "title: " << book.GetTitle() << " " << "author: " << author << "\n";
			return;
		}
		cout << "Not exist\n";
	}
}
