#include<iostream>
#include <string>
using namespace std;

class phoneNode {
public:
    phoneNode(string name, string phonrNumber, string address, phoneNode* next);
    phoneNode* next_;
    string name_;
    string phoneNumber_;
    string address_;
};

class phoneBook {
public:
    phoneBook();
    bool Insert(string name, string phonrNumber, string address);
    phoneNode* Delete(string name);
    phoneNode* Find(string name);
	void printall();
private:
    phoneNode* lst_;
};


phoneNode::phoneNode(string name, string phonrNumber, string address, phoneNode* next) {
	name_ = name;
	phoneNumber_ = phonrNumber;
	address_ = address;
	next_ = next;
}

phoneBook::phoneBook() {
	lst_ = 0;
}

void phoneBook::printall() {
	
	phoneNode* h = lst_;

	while (h != NULL) {
		cout << h->name_ << " ->";
		h = h->next_;
	}
	cout << "\n";
}


bool phoneBook::Insert(string name, string phonrNumber, string address) {
	if (lst_ == 0) {
		lst_ = new phoneNode(name,phonrNumber,address, 0); return true;
	}

	if (lst_->next_ == 0) {
		lst_->next_ = new phoneNode(name, phonrNumber, address, 0); return true;

	}

	phoneNode* ptr = lst_;
	while (ptr->next_!=0)
	{
		ptr = ptr->next_;
	}

	ptr->next_ = new phoneNode(name, phonrNumber, address, 0);
	return true;

}


phoneNode* phoneBook::Delete(string name) {

	phoneNode* ptr = lst_;
	phoneNode* pre = NULL;

	if (lst_ == 0) {
		return 0;
	}

	while (ptr->name_ != name) {
		pre = ptr;	
		ptr = ptr->next_;
	}

	if (ptr == 0) return 0;
	pre->next_ = ptr->next_;
	
	delete ptr; //�ʿ���� �޸� ����(��Ȯ���� ������ �ƴ϶� �ü������ �̰� ��������ϱ� �ᵵ �ȴٰ� �˷��ִ� ����) dptr�� ����Ű�� ��ü 

}



int main() {
	phoneBook* pb = new phoneBook();
	pb->Insert("������", "010-2345-6789", "���Ǵ��б�");
	pb->printall();
	pb->Insert("�ƹ���", "010-9876-5432", "���Ǵ��б�");
	pb->printall();
	pb->Insert("������", "010-9876-5432", "���Ǵ��б�");
	pb->printall();
	pb->Insert("������", "010-9876-5432", "���Ǵ��б�");
	pb->printall();

	pb->Delete("������");
	pb->printall();

}













