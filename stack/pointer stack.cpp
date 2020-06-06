#include <iostream>
using namespace std;
#pragma once

#define ERROR -1; //양의 정수만을 다루는 것을 가정한다.
class node {
public:
    node(int d, node* n = 0) {
        next = n;
        data = d;
    }
    // private: 코딩상의 편의를 위하여 모두 public으로 한다.
    node* next;
    int data;
};


class Stack {
public:
    Stack();
    bool IsEmpty();
    bool IsFull();
    bool Push(int el);
    int Pop();
    int Top();
private:
    node* top;
};


Stack::Stack() {
    top = 0;
}

bool Stack::IsEmpty() {
    return (top == 0);
}

bool Stack::IsFull() {
    return false;
}

bool Stack::Push(int el) {
    if (IsFull()) return false; //제일 처음 들어온 데이터가 마지막으로 밀려나가는 구조
    top = new node(el, top);  //node* ptr = new node()
    return true;             //ptr->data= el;
                             //ptr->next = top;
                             //top=ptr;
}

int Stack::Pop() {
    if (IsEmpty()) return 0;
    node* ptr = top;
    top = top->next;
    int el = ptr->data;
    delete ptr;
    return el;
}

int Stack::Top() {
    if (IsEmpty()) return 0;
    return top->data;
}

int main() { //후입선출
    Stack a;
    a.Push(5);
    a.Push(6);
    a.Push(8);

    a.Pop();

    cout << a.Top() << endl;

    return 0;
}