
#include <iostream>
using namespace std;

class arrInt3 {  //3차원 배열
public:
	arrInt3(int d1, int d2, int d3);
	int GetAt(int p1, int p2, int p3);
	void SetAt(int p1, int p2, int p3, int v);
private:
	int* arr_;
	int d1_, d2_, d3_;
};

arrInt3::arrInt3(int d1, int d2, int d3) {
	d1_ = d1;
	d2_ = d2;
	d3_ = d3;
	arr_ = new int[d1 * d2 * d3];
	for (int i = 0; i < d1 * d2 * d3; i++) arr_[i] = 0;
}

int arrInt3::GetAt(int p1, int p2, int p3) {
	if (p1 < 0 || d1_ <= p1) return -1;
	if (p2 < 0 || d2_ <= p2) return -1;
	if (p3 < 0 || d3_ <= p3) return -1;
	return arr_[p1 * d2_ * d3_ + p2 * d3_ + p3];
}

void arrInt3::SetAt(int p1, int p2, int p3, int v) {
	if (p1 < 0 || d1_ <= p1) return;
	if (p2 < 0 || d2_ <= p2) return;
	if (p3 < 0 || d3_ <= p3) return;
	if (v <= 0) return;
	arr_[p1 * d2_ * d3_ + p2 * d3_ + p3] = v;
}

int main() {
	int d1, d2, d3;
	int x, y, z, v;

	cin >> d1 >> d2 >> d3;
	arrInt3 cube(d1, d2, d3);

	for (int i = 0; i < 3; i++) {
		cin >> x >> y >> z >> v;
		cube.SetAt(x, y, z, v);
	}

	cin >> x >> y >> z;
	cout << cube.GetAt(x, y, z) << endl;
}









#include <iostream>
using namespace std;

class arrInt3 {   //3차원 희소배열
public:
	arrInt3();
	int GetAt(int p1, int p2, int p3);
	void SetAt(int p1, int p2, int p3, int v);
private:
	int arr_[100];
	int size_;
	int data_;
};

arrInt3::arrInt3() {
	size_ = 0;
}

int arrInt3::GetAt(int p1, int p2, int p3) {
	if (p1 >= 100 || p2 >= 100 || p3 >= 100) // 오류조건 수정필요 p1<=0 등 포함
		return -1;
	else {
		for (int i = 0; i < size_; i++) {
			if (arr_[i * 4] == p1 && arr_[i * 4 + 1] == p2 && arr_[i * 4 + 2] == p3) return arr_[i * 4 + 3];
		}
		return 0;
	}
}

void arrInt3::SetAt(int p1, int p2, int p3, int v) {
	if (p1 >= 100 || p2 >= 100 || p3 >= 100 || v <= 0) // 오류조건 수정필요 p1<=0 등 포함
		return;
	else {
		arr_[size_ * 4] = p1;
		arr_[size_ * 4 + 1] = p2;
		arr_[size_ * 4 + 2] = p3;
		arr_[size_ * 4 + 3] = v;
		size_++;
	}
}

int main() {
	arrInt3 cube;
	int x, y, z, v;

	for (int i = 0; i < 3; i++) {
		cin >> x >> y >> z >> v;
		cube.SetAt(x, y, z, v);
	}

	cin >> x >> y >> z;
	cout << cube.GetAt(x, y, z);
}











#include <iostream>
using namespace std;

class dlnode {   //이중연결리스트
public:
	dlnode(int d, dlnode* p = 0, dlnode* n = 0) {
		prev_ = p;
		next_ = n;
		data_ = d;
	}
	dlnode* prev_;
	dlnode* next_;
	int data_;
};

class dllist {
public:
	dllist() { head_ = 0; tail_ = 0; }
	int GetSize();
	void Insert(int item);
	void Delete(int value);
	int GetAt(int position);
	int Index(int value);
	void Print();
	void PrintReverse();
private:
	dlnode* head_;
	dlnode* tail_;
};

void
dllist::Insert(int item) {
	if (head_ == 0) {
		head_ = new dlnode(item);
		tail_ = head_;
		return;
	}
	if (item < head_->data_) {
		dlnode* ptr = new dlnode(item, 0, head_);
		head_->prev_ = ptr;
		head_ = ptr;
		return;
	}
	if (tail_->data_ < item) {
		dlnode* ptr = new dlnode(item, tail_, 0);
		tail_->next_ = ptr;
		tail_ = ptr;
		return;
	}
	dlnode* ptr = head_;
	while (ptr->data_ < item) ptr = ptr->next_;
	dlnode* nptr = new dlnode(item, ptr->prev_, ptr);
	ptr->prev_->next_ = nptr;
	ptr->prev_ = nptr;
}

void
dllist::Delete(int value) {
	if (head_ == 0) return;
	if (value < head_->data_) return;
	if (tail_->data_ < value) return;
	if (value == head_->data_) {
		dlnode* ptr = head_;
		head_ = head_->next_;
		if (head_ == 0) tail_ = 0;
		else head_->prev_ = 0;
		delete ptr;
	}
	if (value == tail_->data_) {
		dlnode* ptr = tail_;
		tail_ = tail_->prev_;
		if (tail_ == 0) head_ = 0; // 필요없음
		else tail_->next_ = 0;
		delete ptr;
	}
	dlnode* ptr = head_;
	while (ptr != 0 && ptr->data_ != value) ptr = ptr->next_;
	if (ptr == 0) return;
	ptr->next_->prev_ = ptr->prev_;
	ptr->prev_->next_ = ptr->next_;
	delete ptr;
}

void
dllist::Print() {
	dlnode* ptr = head_;
	while (ptr) {
		cout << ptr->data_ << " ";
		ptr = ptr->next_;
	}
}

void
dllist::PrintReverse() {
	dlnode* ptr = tail_;
	while (ptr) {
		cout << ptr->data_ << " ";
		ptr = ptr->prev_;
	}
}

int main() {
	dllist lst;
	int v;

	for (int i = 0; i < 7; i++) {
		cin >> v;
		lst.Insert(v);
	}
	for (int i = 0; i < 3; i++) {
		cin >> v;
		lst.Delete(v);
	}
	lst.Print();
	lst.PrintReverse();
}













#include <iostream>
#include <string>
using namespace std;

class phoneData {  //전화번호부 연결리스트
public:
	phoneData(string name, string phoneNumber, string address);
	void printPD();
	// private:
	string name_;
	string phoneNumber_;
	string address_;
};

class phoneNode {
public:
	phoneNode(phoneData* data, phoneNode* next);
	phoneNode* next_;
	phoneData* data_;
};

class phoneBook {
public:
	phoneBook();
	bool Insert(phoneData* data);
	phoneData* Delete(string name);
	phoneData* Find(string name);
private:
	phoneNode* lst_;
};


phoneData::phoneData(string name, string phoneNumber, string address) {
	name_ = name;
	phoneNumber_ = phoneNumber;
	address_ = address;
}

void phoneData::printPD() {
	cout << "name : " << name_ << endl;
	cout << "phone number : " << phoneNumber_ << endl;
	cout << "address : " << address_ << endl;
}

phoneNode::phoneNode(phoneData* data, phoneNode* next = 0) {
	data_ = data;
	next_ = next;
}

phoneBook::phoneBook() {
	lst_ = 0;
}

bool
phoneBook::Insert(phoneData* data) {
	lst_ = new phoneNode(data, lst_);
	return true;
}

phoneData*
phoneBook::Delete(string name) {
	if (lst_ == 0) return 0;

	phoneNode* ptr = lst_;
	phoneData* data;
	if (name == lst_->data_->name_) {
		lst_ = lst_->next_;
		data = ptr->data_;
		delete ptr;
		return data;
	}
	while (ptr->next_ != 0 && ptr->next_->data_->name_ != name) {
		ptr = ptr->next_;
	}
	if (ptr->next_ == 0) return 0;

	phoneNode* nptr = ptr->next_;
	ptr->next_ = ptr->next_->next_;
	data = nptr->data_;
	delete nptr;
	return data;
}

phoneData*
phoneBook::Find(string name) {
	phoneNode* ptr = lst_;
	while (ptr != 0) {
		if (name == ptr->data_->name_) return ptr->data_;
		ptr = ptr->next_;
	}
	return 0;
}

int main() {
	phoneBook* pb = new phoneBook();
	phoneData* pd = new phoneData("누구나", "010-2345-6789", "동의대학교");
	pb->Insert(pd);
	pd = new phoneData("아무개", "010-9876-5432", "동의대학교");
	pb->Insert(pd);

	pd = pb->Find("누구나");
	if (pd) pd->printPD();

	pd = pb->Find("아무개");
	if (pd) pd->printPD();

	pb->Delete("아무개");

	pd = pb->Find("누구나");
	if (pd) pd->printPD();
	pd = pb->Find("아무개");
	if (pd) pd->printPD();
}
















#include <iostream>
using namespace std;

class queue3 {  //고객 대기열 관리 큐
public:
	queue3() {
		rear = 0;
	}
	bool IsEmpty() { return (rear == 0); };
	bool IsFull() { return (rear == 3); };
	bool InsertQ(int el) {
		if (rear == 3) return false;
		arr[rear++] = el;
		return true;
	}
	int DeleteQ() {
		if (rear == 0) return -1;
		int el = arr[0];
		rear--;
		for (int i = 0; i < rear; i++) arr[i] = arr[i + 1];
		return el;
	}
private:
	int arr[3];
	int rear;
};

class queue6 {
public:
	queue6();
	bool IsEmpty();
	bool IsFull();
	bool InsertQ(int el);
	int DeleteQ();
private:
	queue3 q1;
	queue3* q2;
};

queue6::queue6() {
	q2 = new queue3();
};

bool queue6::IsEmpty() {
	return q1.IsEmpty();
};

bool queue6::IsFull() {
	return q2->IsFull();
};

bool queue6::InsertQ(int el) {
	if (q1.IsFull()) return q2->InsertQ(el);
	return q1.InsertQ(el);
}

int queue6::DeleteQ() {
	if (q2->IsEmpty()) return q1.DeleteQ();
	int el = q1.DeleteQ();
	q1.InsertQ(q2->DeleteQ());
	return el;
}

int main() {
	int n, i, a;
	queue6* q = new queue6();

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		if (a == 0) cout << q->DeleteQ() << " ";
		else q->InsertQ(a);
	}
	return 0;
};
