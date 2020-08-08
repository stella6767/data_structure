#include <iostream>
using namespace std;

//queue 10 30개 활용하여 queue 300
class queue10 {
public:
    queue10() { front = 0; rear = 0; };
    bool IsFull() { return rear == 10; };
    bool IsEmpty() { return front == rear; };
    bool InsertQ(int el) {
        if (IsFull()) return false;
        arr[rear++] = el;
        return true;
    }
    int DeleteQ() {
        if (IsEmpty()) return 0;
        return arr[front++];
    }
private:
    int front, rear;
    int arr[10];
};

class queue300 {
public:
    queue300();
    bool IsFull();
    bool IsEmpty();
    bool InsertQ(int el); // 성공 true, 실패 false
    int DeleteQ(); // 오류 시 0 리턴
private:
    queue10* q[30]; // 필요시 변수추가 가능.
    int front, rear;
};


queue300::queue300() {
    for (int i = 0; i < 30; i++) q[i] = new queue10();
    front = 0; rear = 0;
}

bool
queue300::IsFull() {
    return (rear == 30);
}

bool
queue300::IsEmpty() {
    if (front < rear) return false;
    if (front == 30) return true;
    return (q[front]->IsEmpty());
}

bool
queue300::InsertQ(int el) { // 성공 true, 실패 false
    if (IsFull()) return false;
    q[rear]->InsertQ(el);
    if (q[rear]->IsFull()) rear++;
    return true;
}

int
queue300::DeleteQ() { // 오류 시 0 리턴
    if (IsEmpty()) return 0;
    int el = q[front]->DeleteQ();
    if (q[front]->IsEmpty() && q[front]->IsFull()) front++;
    return el;
}

int main() {
    queue300 q;
    for (int i = 1; i < 201; i++) {
        q.InsertQ(i);
        //        cout << i;
    }
    cout << endl;
    for (int i = 1; i < 300; i++) cout << q.DeleteQ() << " ";
    for (int i = 201; i < 401; i++) {
        q.InsertQ(i);
        //        cout << i;
    }
    cout << endl;
    for (int i = 1; i < 300; i++) cout << q.DeleteQ() << " ";

}
