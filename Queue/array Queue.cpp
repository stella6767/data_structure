#include <iostream>
using namespace std;
#define MAXQ 100

class Queue {
 public:
    Queue();
     bool IsEmpty() { return (rear_ == 0); }
     bool IsFull() { return (rear_ == MAXQ); }
     bool InsertQ(int el);
     int DeleteQ();
private:
    int arr_[MAXQ]; //100���� ���� ���� arr[0]~~arr[99]
        // int front=0; �׻� ù��° ���� ���� ������ �ʿ䰡 ����
    int rear_;

};


 Queue::Queue() {
	 rear_ = 0; //���� ����� �����͸� ǥ��
}

 bool Queue::InsertQ(int el) {
	if (IsFull()) return false;
	arr_[rear_++] = el; //���� ���� �����ϰ� �迭�� ������ �ϳ� �ø���.
	
}

 int Queue::DeleteQ() {
	if (IsEmpty()) return -1; //-1�� ������ �� ���ٴ� ������ ���(error)
	int el = arr_[0]; //ó���� �� ������ el�� ����
	rear_--; //�����Ͱ� �ϳ� �پ����ٴ� �� ǥ��
	for (int i = 0; i < rear_; i++) arr_[i] = arr_[i + 1]; //0���� rear�������� ��ġ�� ���� �ϳ��� �ڷ� ī��
	return el; //ó�� ������ �����͸� ��
	
}


 int main() {
     Queue * q = new Queue();
     q-> InsertQ(2);
     q-> InsertQ(5);
     q-> InsertQ(3);
     while (!q->IsEmpty()) cout << q->DeleteQ() << " "; //real=0�� �ƴ϶�� ��� 

     return 0;
 }