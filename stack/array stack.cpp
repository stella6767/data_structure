#include <iostream>
using namespace std;

class Stack {
public:
    Stack(int s = 100) {
        size = s;
        storage = new int[size]; //100개의 변수 저장고
        top = 0; //현재까지 저장된 값의 수
    }
    bool IsEmpty() { return top == 0; };
    bool IsFull() { return top == size; };
    bool Push(int el);
    int Pop();
    int Top();
private:
    int* storage;
    int top;
    int size;
};

bool Stack::Push(int el) {
    if (IsFull()) return false;
    storage[top++] = el; //후위연산자
    return true;
}

int Stack::Pop() {
    if (IsEmpty()) return 0;
    return storage[--top]; //전위연산자 활용하여 코드를 작성!
}

int Stack::Top() {
    if (IsEmpty()) return 0;
    return storage[top - 1];
}

int main() {
    Stack* q = new Stack();
    q->Push(2);
    q->Push(5);
    q->Push(3);

    if (!q->IsEmpty())
        q->Pop();

    cout << q->Top() << endl; //마지막 값을 돌려줌

    return 0;
}