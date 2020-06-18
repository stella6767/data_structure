#pragma once
#define MAXQ 100

class queue {
public:
    queue();
    bool IsEmpty() { return (rear_ == front_); }
    bool IsFull() { return ((rear_ + 1) % MAXQ == front_); }
    bool InsertQ(int el);
    int DeleteQ();
private:
    int arr_[MAXQ];
    int front_;
    int rear_;
};

queue::queue() {
    front_ = 0;
    rear_ = 0;
}

bool queue::InsertQ(int el) {
    if (IsFull()) return false;
    arr_[rear_++] = el;
    rear_ = rear_ % MAXQ;
    return true;
}


int queue::DeleteQ() {
    if (IsEmpty()) return -1;
    int el = arr_[front_++];
    front_ = front_ % MAXQ;
    return el;
}