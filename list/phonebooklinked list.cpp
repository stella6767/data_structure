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
//	phoneNode* ptr = lst_; //�����͸� �����ϰ� lst_�� �ּҰ��� �����Ѵ�.  lst�� �Բ� ���� ���� ��带 ����Ű�� �ּҰ��� ������ �ȴ�. 
//	while (ptr->next_ != 0 && ptr->next_->data_ < item) { //�� �����Ͱ� ����Ű�� ���������� �ּҰ��� 0�� �ƴϰ� ���������� ���������ּҰ� �� 
//		//��ü�� ����Ű�� item ������ ������ �۴ٸ� 
//		ptr = ptr->next_; //ptr�� ��带 �̵��ϸ鼭 ptr�� ����Ű�� next�� �ּҰ����� ��� �ٲ��. 
//	}
//
//	ptr->next_= new phoneNode(item, ptr->next_); //phonedata ��ü�� ����Ű�� �ּҰ��� ���� ������ ���� phonedata ��ü ����Ű�� �ּҰ�����
//	//�۴ٸ�  ���ο� ��带 ����� �ű⿡ ��ü �������ּҰ��� next_ ���� ptr�� ����Ű�� next�� �ּҰ��� �ִ´�. 
//	//�׷� ���� ���Ӱ� ������� ����� �� �ּҸ� ���� ptr�� ����Ű�� next�� ���� �����Ѵ�.
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
//	while (ptr->next_ != 0 && ptr->next_->data_->name_ != key) {  //��带 ������ ���鼭 ������ �̸��� ���� ���� ã�´�.
//		ptr = ptr->next_;  //���� ������ 
//	}
//
//	if (ptr->next_ == 0) return 0;
//	phoneNode* dptr = ptr->next_;//
//	ptr->next_ = ptr->next_->next_;
//	delete dptr; //�ʿ���� �޸� ����(��Ȯ���� ������ �ƴ϶� �ü������ �̰� ��������ϱ� �ᵵ �ȴٰ� �˷��ִ� ����) dptr�� ����Ű�� ��ü 
//
//}
//
//
//
//int main() {
//	phoneBook* pb = new phoneBook();
//	phoneData* pd = new phoneData("������", "010-2345-6789", "���Ǵ��б�");
//	pb->Insert(pd);
//	pd = new phoneData("�ƹ���", "010-9876-5432", "���Ǵ��б�");
//	pb->Insert(pd);
//
//	pd = pb->Find("������");
//	if (pd) pd->printPD();
//
//	pd = pb->Find("�ƹ���");
//	if (pd) pd->printPD();
//
//	pb->Delete("�ƹ���");
//
//	pd = pb->Find("������");
//	if (pd) pd->printPD();
//	pd = pb->Find("�ƹ���");
//	if (pd) pd->printPD();
//}