//Book.h
#pragma once
#include "ehglobal.h"
class Book
{
    const int bnum;
    string title;
public:
    Book(int bnum, string title);
    int GetBNum()const;
    string GetTitle()const;
    void View()const;
};

//Book.cpp
#include "Book.h"

Book::Book(int bnum, string title) :bnum(bnum)
{
    this->title = title;
}
int Book::GetBNum()const
{
    return bnum;
}
string Book::GetTitle()const
{
    return title;
}
void Book::View()const
{
    cout << bnum << ", " << title << endl;
}

//BinSearchTree.h
#pragma once
#include "Book.h"
struct Node
{
    Book* book;
    Node* left;
    Node* right;
    Node* parent;
    Node(Book* book)
    {
        this->book = book;
        left = right = parent = 0;
    }
};

class BinSearchTree
{
    Node* root;
public:
    BinSearchTree(void);
    ~BinSearchTree(void);
    bool AddBook(int bnum, string title);
    bool FindBook(int bnum)const;
    bool RemoveBook(int bnum);
    void ListAll()const;
private:
    Node* Find(Node* sr, int bnum)const;
    void HangNode(Node* parent, Node* now);
    void DeHang(Node* now);
    void PreOrder(Node* sr)const;
    void InOrder(Node* sr)const;
    void PostOrder(Node* sr)const;
    void Clear(Node* sr);
};

//BinSearchTree.cpp
#include "BinSearchTree.h"
BinSearchTree::BinSearchTree(void)
{
    root = 0;
}
BinSearchTree::~BinSearchTree(void)
{
}
bool BinSearchTree::AddBook(int bnum, string title)
{
    return false;
}
bool BinSearchTree::FindBook(int bnum)const
{
    return false;
}
bool BinSearchTree::RemoveBook(int bnum)
{
    return false;
}
void BinSearchTree::ListAll()const
{
}

//App.h
#pragma once
#include "ehglobal.h"
#include "BinSearchTree.h"
class App
{
    BinSearchTree bstree;
public:
    void Run();
private:
    int SelectMenu();
    void AddBook(); //도서 추가
    void RemoveBook();//도서 삭제
    void FindBook()const; //도서 검색    
    void ListAll()const; //전체 보기
};

//App.cpp
#include "App.h"

void App::Run()
{
    int key = NO_DEFINED;
    while ((key = SelectMenu()) != ESC)
    {
        switch (key)
        {
        case F1: AddBook(); break;
        case F2: RemoveBook(); break;
        case F3: FindBook(); break;
        case F4: ListAll(); break;
        default: cout << "잘못 선택하셨습니다." << endl; break;
        }
        cout << "아무 키나 누르세요." << endl;
        ehglobal::getkey();
    }
}

int App::SelectMenu()
{
    ehglobal::clrscr();//콘솔 화면을 지우기
    cout << "도서 관리 프로그램 [ESC]: 종료" << endl;
    cout << "F1: 도서 추가 F2: 도서 삭제 F3: 도서 검색 F4: 전체 보기" << endl;

    return ehglobal::getkey();//사용자가 입력한 기능 키 반환
}
void App::AddBook() //도서 추가
{
    cout << "추가할 도서 번호:";
    int num = ehglobal::getnum();
    if (bstree.FindBook(num))
    {
        cout << "이미 존재합니다." << endl;
        return;
    }
    cout << "도서명:";
    string title = ehglobal::getstr();
    bstree.AddBook(num, title);
}

void App::RemoveBook()//도서 삭제
{
    cout << "삭제할 도서 번호:";
    int num = ehglobal::getnum();

    if (bstree.RemoveBook(num))
    {
        cout << "삭제하였습니다." << endl;
    }
    else
    {
        cout << "존재하지 않는 도서입니다." << endl;
    }
}

void App::FindBook()const //도서 검색    
{
    cout << "검색할 도서 번호:";
    int num = ehglobal::getnum();

    if (bstree.FindBook(num) == 0)
    {
        cout << "존재하지 않는 도서입니다." << endl;
    }
}

void App::ListAll()const //전체 보기
{
    bstree.ListAll();
}


//Program.cpp
#include "App.h"
int main()
{
    App* app = new App();
    app->Run();
    delete app;
    return 0;
}




//
//class Book
//{
//    //도서는 상수화 멤버로 도서 번호와 도서명을 멤버 필드로 추가하세요.
//    const int bnum;
//    string title;
//public:
//    //생성자에서 도서 번호와 도서명을 입력 인자로 받기로 해요.
//    Book(int bnum, string title);
//    //도서 번호와 도서명에 관한 접근자와 정보를 출력하는 메서드를 제공하세요.
//    int GetBNum()const;
//    string GetTitle()const;
//    void View()const;
//};
//
//class Book
//{
//    //도서는 상수화 멤버로 도서 번호와 도서명을 멤버 필드로 추가하세요.
//    const int bnum;
//    string title;
//public:
//    //생성자에서 도서 번호와 도서명을 입력 인자로 받기로 해요.
//    Book(int bnum, string title);
//    //도서 번호와 도서명에 관한 접근자와 정보를 출력하는 메서드를 제공하세요.
//    int GetBNum()const;
//    string GetTitle()const;
//    void View()const;
//};
//
//
//
//
//#include "Book.h"
//Book::Book(int bnum, string title) :bnum(bnum)
//{
//    this->title = title;
//}
//int Book::GetBNum()const
//{
//    return bnum;
//}
//string Book::GetTitle()const
//{
//    return title;
//}
//void Book::View()const
//{
//    cout << bnum << ", " << title << endl;
//}
//
//
//
//
//struct Node
//{
//    //멤버 필드로 도서 개체를 기억하는 멤버 필드가 필요하겠죠.
//    Book* book;
//    //왼쪽 자식과 오른쪽 자식을 기억하는 멤버가 필요합니다.
//    Node* left;
//    Node* right;
//    //삭제를 편하게 하기 위해 부모를 기억하는 멤버도 추가하세요.
//    Node* parent;
//    //생성자에는 도서 개체를 입력 인자로 받아 멤버 필드를 설정하게 구현하세요.
//    Node(Book* book)
//    {
//        this->book = book;
//        left = right = parent = 0;
//    }
//};
//
//class BinSearchTree
//{
//    //최상위 노드를 기억할 root 멤버 필드가 필요하겠죠.
//    Node* root;
//public:
//    BinSearchTree(void);
//    ~BinSearchTree(void);
//    //도서를 추가하는 메서드를 제공합시다. 
//    //여기에서는 추가할 도서의 정보를 입력 인자로 받아 
//    //같은 도서 번호를 갖는 개체가 없을 때만 생성해서 보관하기로 해요. 
//    //그리고 생성 여부를 반환하기로 합시다.
//    bool AddBook(int bnum, string title);
//    //도서 번호로 검색하는 기능도 제공합시다. 
//    //간단히 구현하기 위해 내부에서 검색한 도서 정보를 출력하고 
//    //호출한 곳에는 검색 성공 여부만 반환하기로 해요.
//    bool FindBook(int bnum)const;
//    //도서 번호로 삭제하는 기능도 제공합시다. 
//    //호출하는 곳에 삭제 여부를 반환하게 구현합시다.
//    bool RemoveBook(int bnum);
//    //전체 도서 정보를 출력하는 기능도 제공합시다.
//    void ListAll()const;
//};