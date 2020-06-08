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
    void AddBook(); //���� �߰�
    void RemoveBook();//���� ����
    void FindBook()const; //���� �˻�    
    void ListAll()const; //��ü ����
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
        default: cout << "�߸� �����ϼ̽��ϴ�." << endl; break;
        }
        cout << "�ƹ� Ű�� ��������." << endl;
        ehglobal::getkey();
    }
}

int App::SelectMenu()
{
    ehglobal::clrscr();//�ܼ� ȭ���� �����
    cout << "���� ���� ���α׷� [ESC]: ����" << endl;
    cout << "F1: ���� �߰� F2: ���� ���� F3: ���� �˻� F4: ��ü ����" << endl;

    return ehglobal::getkey();//����ڰ� �Է��� ��� Ű ��ȯ
}
void App::AddBook() //���� �߰�
{
    cout << "�߰��� ���� ��ȣ:";
    int num = ehglobal::getnum();
    if (bstree.FindBook(num))
    {
        cout << "�̹� �����մϴ�." << endl;
        return;
    }
    cout << "������:";
    string title = ehglobal::getstr();
    bstree.AddBook(num, title);
}

void App::RemoveBook()//���� ����
{
    cout << "������ ���� ��ȣ:";
    int num = ehglobal::getnum();

    if (bstree.RemoveBook(num))
    {
        cout << "�����Ͽ����ϴ�." << endl;
    }
    else
    {
        cout << "�������� �ʴ� �����Դϴ�." << endl;
    }
}

void App::FindBook()const //���� �˻�    
{
    cout << "�˻��� ���� ��ȣ:";
    int num = ehglobal::getnum();

    if (bstree.FindBook(num) == 0)
    {
        cout << "�������� �ʴ� �����Դϴ�." << endl;
    }
}

void App::ListAll()const //��ü ����
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
//    //������ ���ȭ ����� ���� ��ȣ�� �������� ��� �ʵ�� �߰��ϼ���.
//    const int bnum;
//    string title;
//public:
//    //�����ڿ��� ���� ��ȣ�� �������� �Է� ���ڷ� �ޱ�� �ؿ�.
//    Book(int bnum, string title);
//    //���� ��ȣ�� ������ ���� �����ڿ� ������ ����ϴ� �޼��带 �����ϼ���.
//    int GetBNum()const;
//    string GetTitle()const;
//    void View()const;
//};
//
//class Book
//{
//    //������ ���ȭ ����� ���� ��ȣ�� �������� ��� �ʵ�� �߰��ϼ���.
//    const int bnum;
//    string title;
//public:
//    //�����ڿ��� ���� ��ȣ�� �������� �Է� ���ڷ� �ޱ�� �ؿ�.
//    Book(int bnum, string title);
//    //���� ��ȣ�� ������ ���� �����ڿ� ������ ����ϴ� �޼��带 �����ϼ���.
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
//    //��� �ʵ�� ���� ��ü�� ����ϴ� ��� �ʵ尡 �ʿ��ϰ���.
//    Book* book;
//    //���� �ڽİ� ������ �ڽ��� ����ϴ� ����� �ʿ��մϴ�.
//    Node* left;
//    Node* right;
//    //������ ���ϰ� �ϱ� ���� �θ� ����ϴ� ����� �߰��ϼ���.
//    Node* parent;
//    //�����ڿ��� ���� ��ü�� �Է� ���ڷ� �޾� ��� �ʵ带 �����ϰ� �����ϼ���.
//    Node(Book* book)
//    {
//        this->book = book;
//        left = right = parent = 0;
//    }
//};
//
//class BinSearchTree
//{
//    //�ֻ��� ��带 ����� root ��� �ʵ尡 �ʿ��ϰ���.
//    Node* root;
//public:
//    BinSearchTree(void);
//    ~BinSearchTree(void);
//    //������ �߰��ϴ� �޼��带 �����սô�. 
//    //���⿡���� �߰��� ������ ������ �Է� ���ڷ� �޾� 
//    //���� ���� ��ȣ�� ���� ��ü�� ���� ���� �����ؼ� �����ϱ�� �ؿ�. 
//    //�׸��� ���� ���θ� ��ȯ�ϱ�� �սô�.
//    bool AddBook(int bnum, string title);
//    //���� ��ȣ�� �˻��ϴ� ��ɵ� �����սô�. 
//    //������ �����ϱ� ���� ���ο��� �˻��� ���� ������ ����ϰ� 
//    //ȣ���� ������ �˻� ���� ���θ� ��ȯ�ϱ�� �ؿ�.
//    bool FindBook(int bnum)const;
//    //���� ��ȣ�� �����ϴ� ��ɵ� �����սô�. 
//    //ȣ���ϴ� ���� ���� ���θ� ��ȯ�ϰ� �����սô�.
//    bool RemoveBook(int bnum);
//    //��ü ���� ������ ����ϴ� ��ɵ� �����սô�.
//    void ListAll()const;
//};