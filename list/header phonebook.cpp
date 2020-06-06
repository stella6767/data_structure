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
	
	delete ptr; //필요없는 메모리 삭제(정확히는 삭제가 아니라 운영체제에게 이거 쓸모없으니까 써도 된다고 알려주는 과정) dptr이 가리키는 객체 

}



int main() {
	phoneBook* pb = new phoneBook();
	pb->Insert("누구나", "010-2345-6789", "동의대학교");
	pb->printall();
	pb->Insert("아무개", "010-9876-5432", "동의대학교");
	pb->printall();
	pb->Insert("나랑개", "010-9876-5432", "동의대학교");
	pb->printall();
	pb->Insert("마지막", "010-9876-5432", "동의대학교");
	pb->printall();

	pb->Delete("마지막");
	pb->printall();

}













