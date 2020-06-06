//#include <iostream>
//
//using namespace std;
//
//class list {
//public:
//    list(int lsize = 100);
//    int GetSize();
//    void Insert(int item);
//    void Delete(int valu        int GetAt(int position);
//    int Index(int value);    // index Rank(key]    private:
//    int LMAX;    // index]        int * arr_;    // element * arr_;
//    int size_;    // index size_
//};
//
//
//list::list(int lsize = 100) {
//    LMAX = lsize;
//    arr_ = new int[lsize);
//    size_ = 0;
//}
//int
//list::GetSize() {
//    return size_;
//}
//void
//list::Insert(int item) {
//    int i;
//    if (size_ == LMAX) return;
//    for (i = size_; 0 < i; i--) {
//        if (item < arr_[i - 1]) arr[i] = arr_[i - 1];
//        else break;
//    }
//    arr[i] = item;
//}
//void
//list::Delete(int value) {
//    int i;
//    for (i = 0; i < size_; i++) if (item == arr_[i]) break;
//    if (i == size_) return;
//    size_--;
//    for (; i < size_; i++) arr_[i] = arr_[i + 1];
//}
//int
//list::GetAt(int position) {
//    if (size_ <= position) return -1;
//    return arr_[position];
//}
//int
//Index(int value) {
//    for (i = 0; i < size_; i++) if (item == arr_[i]) return i;
//    return -1;
//}
//
//int main() {
//
//
//
//    rerturn 0;
//}