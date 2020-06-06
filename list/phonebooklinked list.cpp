//#include <iostream>
//#include <string>
//using namespace std;
//
//class phoneData {
//public:
//	phoneData(string name, string phoneNumber, string address);
//	void printPD();
//	// private:
//	string name_;
//	string phoneNumber_;
//	string address_;
//};
//
//class phoneNode {
//public:
//	phoneNode(phoneData* data, phoneNode* next);
//	phoneNode* next_;
//	phoneData* data_;
//};
//
//class phoneBook {
//public:
//	phoneBook();
//	bool Insert(phoneData* data);
//	phoneData* Delete(string name);
//	phoneData* Find(string name);
//private:
//	phoneNode* lst_;
//};
//
//phoneData::phoneData(string name, string phoneNumber, string address) {
//	name_ = name;
//	phoneNumber_ = phoneNumber;
//	address_ = address;
//}
//
//phoneNode::phoneNode(phoneData* data, phoneNode* next) {
//	next_ = next;
//	data_ = data;
//}
//
//phoneBook::phoneBook() {
//	lst_ = 0;
//}
//
//void phoneData::printPD() {
//	cout << " name : " << name_ << " phone number : " << phoneNumber_ << " address : " << address_;
//}
//
//
//bool phoneBook::Insert(phoneData* item) {
//	if (lst_ == 0) {
//		lst_ = new phoneNode(item, 0); return true;
//	}
//
//	if (item < lst_->data_) {
//	lst_ = new phoneNode(item, lst_); return true;
//	}
//
//	phoneNode* ptr = lst_; //포인터를 생성하고 lst_의 주소값을 대입한다.  lst와 함께 같은 다음 노드를 가리키는 주소값을 가지게 된다. 
//	while (ptr->next_ != 0 && ptr->next_->data_ < item) { //이 포인터가 가리키는 다음번지의 주소값이 0이 아니고 다음번지의 다음번지주소가 들어갈 
//		//객체를 가리키는 item 포인터 값보다 작다면 
//		ptr = ptr->next_; //ptr은 노드를 이동하면서 ptr이 가리키는 next의 주소값으로 계속 바뀐다. 
//	}
//
//	ptr->next_= new phoneNode(item, ptr->next_); //phonedata 객체를 가리키는 주소값이 다음 번지의 역시 phonedata 객체 가리키는 주소값보다
//	//작다면  새로운 노드를 만들고 거기에 객체 포인터주소값과 next_ 에는 ptr이 가리키던 next의 주소값을 넣는다. 
//	//그런 다음 새롭게 만들어진 노드의 새 주소를 기존 ptr이 가리키던 next의 값에 대입한다.
//	return true;
//
//}
//
//
//phoneData* phoneBook::Find(string index) {
//	phoneNode* ptr = lst_;
//	if (ptr == 0)
//		return 0;
//
//	while (ptr->data_->name_ != index) {
//		ptr = ptr->next_;
//	}
//
//	return ptr->data_;
//}
//
//
//phoneData* phoneBook::Delete(string key) {
//
//	phoneNode* ptr = lst_;
//	if (lst_ == 0) {
//		return 0;
//	}
//
//	if (lst_->data_->name_ == key) {
//		lst_ = lst_->next_;
//		delete ptr;
//		return 0;
//	}
//
//	while (ptr->next_ != 0 && ptr->next_->data_->name_ != key) {  //노드를 끝까지 돌면서 전달한 이름과 같은 값을 찾는다.
//		ptr = ptr->next_;  //값이 없으면 
//	}
//
//	if (ptr->next_ == 0) return 0;
//	phoneNode* dptr = ptr->next_;//
//	ptr->next_ = ptr->next_->next_;
//	delete dptr; //필요없는 메모리 삭제(정확히는 삭제가 아니라 운영체제에게 이거 쓸모없으니까 써도 된다고 알려주는 과정) dptr이 가리키는 객체 
//
//}
//
//
//
//int main() {
//	phoneBook* pb = new phoneBook();
//	phoneData* pd = new phoneData("누구나", "010-2345-6789", "동의대학교");
//	pb->Insert(pd);
//	pd = new phoneData("아무개", "010-9876-5432", "동의대학교");
//	pb->Insert(pd);
//
//	pd = pb->Find("누구나");
//	if (pd) pd->printPD();
//
//	pd = pb->Find("아무개");
//	if (pd) pd->printPD();
//
//	pb->Delete("아무개");
//
//	pd = pb->Find("누구나");
//	if (pd) pd->printPD();
//	pd = pb->Find("아무개");
//	if (pd) pd->printPD();
//}