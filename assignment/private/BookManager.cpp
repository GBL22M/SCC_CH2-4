#include <iostream>
#include "../public/BookManager.h"

BookManager::~BookManager()
{
	for (auto book : books)
	{
		delete book;
	}
}

void BookManager::AddBook(string title, string author)
{
	Book* book = new Book(title, author);
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

	for (const auto& book : books)
	{
		cout << book->GetTitle() << " By " << book->GetAuthor() << "\n";
	}
}

void BookManager::SearchByTitle(string title)
{
	for (const auto& book : books)
	{
		if (book->GetTitle() == title)
		{
			cout << "Find book\n";
			cout << "title: " << title << " " << "author: " << book->GetAuthor() << "\n";
			return;
		}
	}
	cout << "Not exist\n";
}

void BookManager::SearchByAuthor(string author)
{
	for (const auto& book : books)
	{
		if (book->GetAuthor() == author)
		{
			cout << "Find book\n";
			cout << "title: " << book->GetTitle() << " " << "author: " << author << "\n";
			return;
		}
	}
	cout << "Not exist\n";
}

Book* BookManager::GetBookByTitle(string title)
{	
	return FindBookByTitle(title);
}

Book* BookManager::GetBookByAuthor(string author)
{
	return FindBookByAuthor(author);
}

//protected
Book* BookManager::FindBookByTitle(string title)
{
	for (const auto& book : books)
	{
		if (book->GetTitle() == title)
		{
			return book;
		}
	}
	return nullptr;
}

Book* BookManager::FindBookByAuthor(string author)
{
	for (const auto& book : books)
	{
		if (book->GetAuthor() == author)
		{
			return book;
		}
	}
	return nullptr;
}