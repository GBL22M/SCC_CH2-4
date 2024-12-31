#include <iostream>
#include "../public/BorrowManager.h"
using namespace std;

void BorrowManager::InitializeStock(Book book, int quantity)
{
	stock.insert({ book.GetTitle(), quantity});
}

void BorrowManager::BorrowBook(string title)
{
	if (stock[title] > 0)
	{
		stock[title]--;
		cout << "Borrow Book: " << title << "\n";
	}
	else
	{
		cout << "already booked\n";
	}
}

void BorrowManager::ReturnBook(string title)
{
	if (0 <= stock[title] && stock[title] < 3)
	{
		stock[title]++;
		cout << "Return book: " << title << "\n";
	}
	else
	{
		cout << "system error\n";
	}
}

void BorrowManager::DisplayStock()
{
	for (const auto& s : stock)
	{
		cout << "Title: " << s.first << " Quantity: " << s.second << "\n";
	}
}