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
    int arr_[MAXQ]; //100개의 공간 배정 arr[0]~~arr[99]
        // int front=0; 항상 첫번째 원소 굳이 선언할 필요가 없음
    int rear_;

};


 Queue::Queue() {
	 rear_ = 0; //현재 저장된 데이터를 표현
}

 bool Queue::InsertQ(int el) {
	if (IsFull()) return false;
	arr_[rear_++] = el; //들어온 값을 배정하고 배열의 번지를 하나 늘린다.
	
}

 int Queue::DeleteQ() {
	if (IsEmpty()) return -1; //-1은 실행할 게 없다는 일종의 약속(error)
	int el = arr_[0]; //처음에 들어간 데이터 el에 저장
	rear_--; //데이터가 하나 줄어들었다는 걸 표현
	for (int i = 0; i < rear_; i++) arr_[i] = arr_[i + 1]; //0부터 rear번지까지 배치된 값을 하나씩 뒤로 카피
	return el; //처음 배정된 데이터를 뱉어냄
	
}


 int main() {
     Queue * q = new Queue();
     q-> InsertQ(2);
     q-> InsertQ(5);
     q-> InsertQ(3);
     while (!q->IsEmpty()) cout << q->DeleteQ() << " "; //real=0이 아니라면 계속 

     return 0;
 }