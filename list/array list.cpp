#include <iostream>
using namespace std;

class list {
public:
    list(int lsize = 100);//Ư���� ���� ���� ������ ������� 100
    int GetSize();
    void Insert(int item);
    void Delete(int value);
    int GetAt(int position);
    int Index(int value);    // index Rank(key item);
private:
    int LMAX;    // index LMAX;
    int* arr_;    // element * arr_;
    int size_;    // index size_
};

list::list(int lsize) {
    //���𿡸� ����Ʈ �Ű������� ���ְ� ���ǿ��� ���� �ʾƾ� �Ѵ�...
    LMAX = lsize;
    arr_ = new int[lsize];
    size_ = 0;
}

int
list::GetSize() {
    return size_;
}

void
list::Insert(int item) {
    int i;
    if (size_ == LMAX) return;
    for (i = size_; 0 < i; i--) {
        if (item < arr_[i - 1]) arr_[i] = arr_[i - 1];
        else break;
    }
    arr_[i] = item;
    size_++;
}

void
list::Delete(int value) {
    int i;
    for (i = 0; i < size_; i++) if (value == arr_[i]) break; //������ �� ã�� i
    if (i == size_) return;
    size_--;
    for (; i < size_; i++) arr_[i] = arr_[i + 1]; // �ʱ�ȭ ���� ã�� i�� ����° ���� ���ڸ� ��� ��ĭ��
}

int
list::GetAt(int position) {
    if (size_ <= position) return -1;
    return arr_[position];
}

int
list::Index(int value) {
    int i;
    for (i = 0; i < size_; i++) if (value == arr_[i]) return i;
    return -1;
}

int main() {
    list a;
    a.Insert(3);
}