#pragma once

#include <unordered_map>
#include "Book.h"
using namespace std;

class BorrowManager
{
public:
	void InitializeStock(Book book, int quantity = 3);
	void BorrowBook(string title);
	void ReturnBook(string title);
	void DisplayStock();

private:
	unordered_map<string, int> stock;
};