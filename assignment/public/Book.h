#pragma once

#include <iostream>
#include <string>
using namespace std;

class Book
{
public:
	Book(string title, string author)
		:mTitle(title)
		, mAuthor(author)
	{		
	}

	const string GetTitle() const
	{
		return mTitle;
	}

	const string GetAuthor() const
	{
		return mAuthor;
	}

private:
	string mTitle;
	string mAuthor;
};