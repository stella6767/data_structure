#include <iostream>
using namespace std;



class node {
public:
    node(int d, node* n = 0) {
        next_ = n;
        data_ = d;
    }
    // private: �ڵ����� ���Ǹ� ���Ͽ� ��� public���� �Ѵ�.
    node* next_;
    int data_;
};

class orderlist {
public:
    orderlist();
    int getsize();
    void insert(int item);
    void Delete(int value);
    int getat(int index);
    int index(int key);
private:
    node* lst_;
};


class priorityQueue { //Ŭ������ �ٸ� Ŭ������ ������ �ɹ������� Ȱ���� �� Ŭ���� �ĺ��� ������ �� ���
    //Ŭ������ ������ ���� �ʾҴٴ� �����̹Ƿ� ����ϴ� �ɹ����� Ŭ���� ������ �̵���Ű�� ������ �ذ��� �� �ִ�
    //�׻� �����ڸ� �Ű澲��. ��ũ ������ ���� ū �ֹ�
public:
    priorityQueue() {
        ol_ = new orderlist();
    }
    bool IsEmpty() {
        ol_->getsize();
        if (ol_->getsize() == 0) return true;
        else
            return false;

    };
    bool IsFull() { // ����Ʈ�� �����ͱ��������� full �� ������ ����
        return false;
    };
    bool InsertQ(int el) {
        ol_->insert(el);
        return true;
    };
    int DeleteQ() { // list�� Delete()�� ����Ÿ���� int�� ��� �� ����
        int item = ol_->getat(0);
        ol_->Delete(item);
        return item;
    }
private:
    orderlist* ol_;
};

orderlist::orderlist() {
    lst_ = 0;
    // size_= 0;
}

int orderlist::getsize() {
    node* ptr = lst_;
    int count = 0;
    while (ptr != 0) {
        ptr = ptr->next_;
        count++;
    }
    return count;
}

void orderlist::insert(int item) {
    if (lst_ == 0) {
        lst_ = new node(item, 0);
        return;
    }
    if (item < lst_->data_) {
        lst_ = new node(item, lst_);
        return;
    }
    node* ptr = lst_;
    while (ptr->next_ != 0 && ptr->next_->data_ < item) {
        ptr = ptr->next_;
    }
    ptr->next_ = new node(item, ptr->next_);
}

void orderlist::Delete(int key) {
    node* ptr = lst_;
    if (lst_ == 0) return;
    if (lst_->data_ == key) {
        lst_ = lst_->next_;
        delete ptr;
        return;
    }
    while (ptr->next_ != 0 && ptr->next_->data_ != key) {
        ptr = ptr->next_;
    }
    if (ptr->next_ == 0) return;
    node* dptr = ptr->next_;
    ptr->next_ = ptr->next_->next_;
    delete dptr;
}

int orderlist::getat(int index) {
    node* ptr = lst_;
    for (int i = 0; i < index; i++) {
        if (ptr == 0) return -1;
        ptr = ptr->next_;
    }
    return ptr->data_;
}

int orderlist::index(int key) {
    node* ptr = lst_;
    int idx = 0;
    while (ptr != 0) {
        if (ptr->data_ == key) return idx;
        ptr = ptr->next_;
        idx++;
    }
    return -1;
}




int main() {
    priorityQueue pq;
    int v;

    for (int i = 0; i < 7; i++) {
        cin >> v;
        pq.InsertQ(v);
    }
    while (!pq.IsEmpty()) {
        cout << pq.DeleteQ() << " ";
    }

    return 0;
}
