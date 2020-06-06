//#include <iostream>
//using namespace std;
//
//
//class node {
//public:
//    node(int d, node* n = 0) {
//        next_ = n;
//        data_ = d;
//    }
//    // private: 코딩상의 편의를 위하여 모두 public으로 한다.
//    node* next_;
//    int data_;
//};
//
//class list {
//public:
//    list();
//    int getsize();
//    void insert(int item);
//    void Delete(int value);
//    int getat(int index);
//    int index(int key);
//private:
//    node* lst_;
//};
//
//list::list() {
//    lst_ = 0;
//    // size_= 0;
//}
//
//int
//list::getsize() {
//    node* ptr = lst_;
//    int count = 0;
//    while (ptr != 0) {
//        ptr = ptr->next_;
//        count++;
//    }
//    return count;
//}
//
//void
//list::insert(int item) {
//    if (lst_ == 0) {
//        lst_ = new node(item, 0);
//        return;
//    }
//    if (item < lst_->data_) {
//        lst_ = new node(item, lst_);
//        return;
//    }
//    node* ptr = lst_;
//    while (ptr->next_ != 0 && ptr->next_->data_ < item) {
//        ptr = ptr->next_;
//    }
//    ptr->next_ = new node(item, ptr->next_);
//}
//
///*
//void
//list::insert(int item) {
//    if (lst_==0) {
//        lst = new node(item, 0);
//        return;
//    }
//    if (item < lst_->data) {
//        lst = new node(item, lst);
//        return;
//    }
//    node * ptr = lst_->next_;
//    node * pptr = lst_;
//    while (ptr!=0 && ptr->data < item) {
//        pptr = ptr;
//        ptr = ptr->next;
//    }
//    pptr->next = new node(item, ptr->next);
//}
//*/
//
//void
//list::Delete(int key) {
//    node* ptr = lst_;
//    if (lst_ == 0) return;
//    if (lst_->data_ == key) {
//        lst_ = lst_->next_;
//        delete ptr;
//        return;
//    }
//    while (ptr->next_ != 0 && ptr->next_->data_ != key) {
//        ptr = ptr->next_;
//    }
//    if (ptr->next_ == 0) return;
//    node* dptr = ptr->next_;
//    ptr->next_ = ptr->next_->next_;
//    delete dptr;
//}
//
///*
//int
//list::delete(int value) {
//    node * ptr = lst_;
//    int item;
//    if (lst_==0) return -1;
//    if (value == lst_->data) {
//        lst_ = lst_->next_;
//        item = ptr->data_;
//        delete ptr;
//        return item;
//    }
//    while (ptr->next_!=0 && ptr->next_->data_ != item) {
//        ptr = ptr->next_;
//    }
//    if (ptr->next_==0) return -1;
//    node * dptr = ptr->next_;
//    ptr->next_ = ptr->next_->next_;
//    item = dptr->data_;
//    delete dptr;
//    return item;
//}
//*/
//
//int
//list::getat(int index) {
//    node* ptr = lst_;
//    for (int i = 0; i < index; i++) {
//        if (ptr == 0) return -1;
//        ptr = ptr->next_;
//    }
//    return ptr->data_;
//}
//
//int
//list::index(int key) {
//    node* ptr = lst_;
//    int idx = 0;
//    while (ptr != 0) {
//        if (ptr->data_ == key) return idx;
//        ptr = ptr->next_;
//        idx++;
//    }
//    return -1;
//}
//
//
//
//int main() {
//    list* lst = new list();
//    lst->insert(2);
//    lst->insert(3);
//    lst->insert(5);
//    lst->insert(7);
//    cout << lst->getsize();
//
//    return 0;
//}
