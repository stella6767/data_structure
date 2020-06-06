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
	front_ = 0;
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
	 front_ = rear_ = new node(el);
		 return;
		
	}
	 rear_->next_ = new node(el);
	 rear_ = rear_->next_;
	
}

 int queue::DeleteQ() {
	if (IsEmpty()) return -1; // ERROR!!
	int el = front_->data_;
	node* ptr = front_;
	front_ = front_->next_;
	if (front_ == 0) rear_ = 0;
	delete ptr;
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

