#include <iostream>
#include "public/BookManager.h"
using namespace std;

int main() 
{
    BookManager manager;


    while (true) 
    {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책이름으로 책 검색" << endl; 
        cout << "4. 작가 이름으로 책 검색" << endl; 
        cout << "5. 종료" << endl; // 프로그램 종료

        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) 
        {           
            string title, author;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            manager.AddBook(title, author);
        }
        else if (choice == 2) 
        {        
            manager.DisplayAllBooks();
        }
        else if (choice == 3)
        {
            string title;
            cout << "책 제목: ";
            cin.ignore();
            getline(cin, title);

            manager.SearchByTitle(title);
        }
        else if (choice == 4)
        {
            string author;
            cout << "작가 이름: ";
            cin.ignore();
            getline(cin, author);

            manager.SearchByAuthor(author);
        }
        else if (choice == 5) 
        {        
            cout << "프로그램을 종료합니다." << endl;
            break; 
        }
        else 
        {        
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0;
}