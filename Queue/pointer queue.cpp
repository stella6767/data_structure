#include<iostream>
#define ERROR - 1;

using namespace std;


class node {
 public:
	node(int d, node* n = 0) {
		next_ = n;
		data_ = d;
		
	}
	   // private:
	node* next_;
	int data_;
	
};


class queue {
public:
	queue();
	bool IsEmpty();
	bool IsFull();
	void InsertQ(int el);
	int DeleteQ();
private:
	node* front_;
	node* rear_;
	
};

queue::queue() {
	front_ = 0; //아무것도 안 가리키고 있다는 걸 의미
	rear_ = 0;
	
}

bool queue::IsEmpty() {
	if (front_ == 0) return true;
	return false;
	
}

bool queue::IsFull() {
	 return false;
	
}

 void queue::InsertQ(int el) {
	        // if (IsFull()) return false;
	 if (IsEmpty()) {
	 front_ = rear_ = new node(el); //둘 다 같은 노드를 가리킴
		 return;
		
	} //비어있지 않는다면 front는 처음 노드를 가리키고
	 rear_->next_ = new node(el);  
	 rear_ = rear_->next_; //rear는 맨 마지막에 들어온 노드를 가리킴
	
}

 int queue::DeleteQ() {
	if (IsEmpty()) return -1; // ERROR!!
	int el = front_->data_; //el에 처음 들어온 노드를 저장
	node* ptr = front_; 
	front_ = front_->next_; //front는 이제 처음 들어온 노드의 다음 노드를 가리킴
	if (front_ == 0) rear_ = 0; //노드가 하나일경우
	delete ptr; //원래 첫번째였던 노드 삭제
	return el; 
	
}

 int main() {

	 queue* q = new queue();
	  q-> InsertQ(2);
	  q-> InsertQ(5);
	  q-> InsertQ(3);
	  while (!q->IsEmpty()) cout << q->DeleteQ() << " ";


    return 0;
   }

