#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "public/BookManager.h"
#include "public/BorrowManager.h"

using namespace std;

#ifdef _DEBUG
    #define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main()
{
#ifdef _DEBUG
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	BookManager bookManager;
	BorrowManager borrowManager;

    while (true)
    {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;
        cout << "2. 모든 책 출력" << endl;
        cout << "3. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string title, author;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            bookManager.AddBook(title, author);

            borrowManager.InitializeStock(Book(title, author), 3);
        }
        else if (choice == 2)
        {
            bookManager.DisplayAllBooks();
        }
        else if (choice == 3)
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;                       
        }
    }

    while (1)
    {
        cout << "\n도서관 대여 프로그램" << endl;
        cout << "1. 책 대여(책 이름)" << endl;
        cout << "2. 책 대여(작가 이름)" << endl;
        cout << "3. 책 반납" << endl;
        cout << "4. 대여 상황 출력" << endl;
        cout << "5. 종료" << endl;
        cout << "선택: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string title;
            cout << "대여하려고하는 책 제목을 입력하세요: ";
            cin.ignore();
            getline(cin, title);
           
            Book* book = bookManager.GetBookByTitle(title);
            if (book != nullptr)
            {
                borrowManager.BorrowBook(title);            
            }
            else
            {
                cout << "존재하지 않는 책입니다\n";
            }
        }
        else if (choice == 2)
        {
            string author;
            cout << "대여하려고하는 책의 작가를 입력하세요: ";
            cin.ignore();
            getline(cin, author);

            Book* book = bookManager.GetBookByAuthor(author);
            if (book != nullptr)
            {
                borrowManager.BorrowBook(book->GetTitle());
            }
            else
            {
                cout << "존재하지 않는 책입니다\n";
            }
        }

        else if (choice == 3)
        {
            string title;
            cout << "반납 하려고하는 책 제목을 입력하세요: ";
            cin.ignore();
            getline(cin, title);

            Book* book = bookManager.GetBookByTitle(title);
            if (book != nullptr)
            {
                borrowManager.ReturnBook(book->GetTitle());
            }
            else
            {
                cout << "존재하지 않는 책입니다\n";
            }           
        }
        else if (choice == 4)
        {
            borrowManager.DisplayStock();            
        }
        else if(choice == 5)
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else
        {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }
}