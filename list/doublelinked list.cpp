//#include <iostream>
//using namespace std;
//
//class dlnode {
//public:
//	dlnode(int d, dlnode* p = 0, dlnode* n = 0) {
//		prev_ = p;
//		next_ = n;
//		data_ = d;
//	}
//	dlnode* prev_;
//	dlnode* next_;
//	int data_;
//};
//
//class dllist {
//public:
//	dllist() { head_ = 0; tail_ = 0; }
//	int GetSize();
//	void Insert(int item);
//	void Delete(int value);
//	int GetAt(int position);
//	int Index(int value);
//	void Print();
//	void PrintReverse();
//private:
//	dlnode* head_;
//	dlnode* tail_;
//};
//
//void dllist::Insert(int item) {
//	if (head_ == 0) {
//		head_ = new dlnode(item);
//		tail_ = head_;
//		return;
//
//	}
//	if (item < head_->data_) {
//		dlnode* ptr = new dlnode(item, 0, head_);
//		head_->prev_ = ptr;
//		head_ = ptr;
//		return;
//
//	}
//	if (tail_->data_ < item) {
//		dlnode* ptr = new dlnode(item, tail_, 0);
//		tail_->next_ = ptr;
//		tail_ = ptr;
//		return;
//
//	}
//	dlnode* ptr = head_;
//	while (ptr->data_ < item) ptr = ptr->next_;
//	dlnode* nptr = new dlnode(item, ptr->prev_, ptr);
//	ptr->prev_->next_ = nptr;//
//	ptr->prev_ = nptr;
//
//}
//
//void dllist::Delete(int value) {
//
//	if (head_ == 0) { //노드가 없는 경우
//		return;
//	}
//	dlnode* ptr = head_;
//	dlnode* nptr = tail_;
//
//	if (head_->next_ == 0 && head_->prev_ == 0 && tail_->prev_ == 0 && tail_->next_ == 0 && head_->data_ == value) { //하나만 있는 노드더미를 삭제하는 경우
//		dlnode* cptr = ptr->next_;
//		head_ = head_->next_;
//		tail_ = tail_->prev_;
//		delete cptr;
//		cout << "노드를 다 삭제하였습니다. 더 이상 삭제할 노드가 없습니다" << endl;
//		return;
//	}
//
//	//첫번째 노드가 삭제되는 경우
//	if (head_->data_ == value) {
//		head_ = head_->next_;
//		head_->prev_ = 0;
//		delete ptr;  //list->head = list->head->next;
//		return;
//	}
//
//	//마지막 노드가 삭제되는 경우  
//	if (tail_->data_ == value) {
//		tail_ = tail_->prev_;
//		tail_->next_ = 0; //마지막에 다음 노드가 없으니 넥스트값 주소를 널값으로 초기화
//		delete nptr;
//		return;
//	}
//
//	while (ptr->next_ != 0 && ptr->next_->data_ != value) {  //노드를 끝까지 돌면서 전달한 이름과 같은 값을 찾는다.
//		ptr = ptr->next_;  //값이 없으면
//	}
//
//	if (ptr->next_ == 0) return;
//	dlnode* dptr = ptr->next_;//fine
//	ptr->next_ = dptr->next_;
//	dptr->next_->prev_ = ptr; //이 부분 중요
//	delete dptr; //
//
//}
//
//
//
//
//void dllist::Print() {
//
//	dlnode* h = head_;
//
//	while (h != NULL) {
//		cout << h->data_ << " ";
//		h = h->next_;
//	}
//	cout << "\n";
//
//}
//
//
//void dllist::PrintReverse() {
//
//	dlnode* t = tail_;
//
//	while (t != NULL) {
//		cout << t->data_ << " ";
//		t = t->prev_;
//	}
//	cout << "\n";
//}
//
//
//int main() {
//	dllist lst;
//	int v;
//
//	for (int i = 0; i < 7; i++) {
//		cin >> v;
//		lst.Insert(v);
//	}
//	for (int i = 0; i < 3; i++) {
//		cin >> v;
//		lst.Delete(v);
//	}
//	lst.Print();
//	lst.PrintReverse();
//}