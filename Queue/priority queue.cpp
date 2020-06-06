#include <iostream>
using namespace std;



class node {
public:
    node(int d, node* n = 0) {
        next_ = n;
        data_ = d;
    }
    // private: 코딩상의 편의를 위하여 모두 public으로 한다.
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


class priorityQueue { //클래스가 다른 클래스를 포인터 맴버변수로 활용할 때 클래스 식별자 오류가 날 경우
    //클래스가 선언이 되지 않았다는 이유이므로 사용하는 맴버변수 클래스 밑으로 이동시키면 오류를 해결할 수 있다
    //항상 생성자를 신경쓰자. 링크 오류의 가장 큰 주범
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
    bool IsFull() { // 리스트의 포인터구현에서는 full 이 없음을 가정
        return false;
    };
    bool InsertQ(int el) {
        ol_->insert(el);
        return true;
    };
    int DeleteQ() { // list의 Delete()의 리턴타입이 int인 경우 더 간단
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
