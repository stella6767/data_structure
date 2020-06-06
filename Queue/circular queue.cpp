#include <iostream>
using namespace std;
#define MAXQ 100

class Queue {
 public:
	Queue();
	bool IsEmpty() { return (rear_ == front_); }
	bool IsFull() { return ((rear_ + 1) % MAXQ == front_); } //(arr[99])->100 % 100 ==0(나머지) 0다음에 99
	bool InsertQ(int el);
	int DeleteQ();
 private:
	int arr_[MAXQ];
	int front_;
	int rear_;
	
};


 Queue::Queue() {
	front_ = 0;
	rear_ = 0;
	
}

bool Queue::InsertQ(int el) {
	 if (IsFull()) return false;    
	 arr_[rear_] = el; //arr_[rear_++] = el;  
	 rear_ = (rear_ + 1) % MAXQ; //rear_ = rear_ % MAXQ;
	 return true;
 }

int Queue::DeleteQ() {
	if (IsEmpty()) return -1;
	int el = arr_[front_++]; //	int el =arr_[front];
	front_ = front_ % MAXQ; //front = (front+1)%100
	return el;
}

int main() {
    Queue * q = new Queue();
    q-> InsertQ(2);
    q-> InsertQ(5);
    q-> InsertQ(3);
    while (!q->IsEmpty()) cout << q->DeleteQ() << " ";

    return 0;
   }
