class minheap {
public:
    minheap() { minheap(100); };
    minheap(int size);
    ~minheap();
    bool IsEmpty();
    bool IsFull();
    void InsertMH(int el);
    int DeleteMH();
protected:
    void UpHeap(int el);
    void DownHeap();
private:
    int hsize_; // 힙의 최대 크기
    int last_; //현재 힙의 크기
    int* storage_;
};

minheap::minheap(int size) {
    hsize_ = size;
    last_ = 0;
    storage_ = new int[100];
};

minheap::~minheap::() {
    delete storage_;
};

bool minheap::IsEmpty() {
    return last_ == 0;
};

bool minheap::IsFull() {
    return last_ == hsize_;
};

void minheap::InsertMH(int el) {
    storage_[last_++] = el;
    UpHeap(last - 1);
};

void minheap::UpHeap(int cur) {
    int par = (cur - 1) / 2;
    while ((cur != 0) && (storage_[cur] < storage_[par])) {
        Swap(cur, par);
        cur = par;
        par = (cur - 1) / 2;
    }
};

int minheap::DeleteMH() {
    int el = storage_[0];
    storage_[0] = storage_[--last_];
    DownHeap(0);
    return el;
};

void minheap::DownHeap(int cur) {
    while ((cur * 2 + 1) < last_) {
        int mc = cur * 2 + 1; // mc=lc;
        if ((cur * 2 + 2 < last_) && (storage_[mc] > storage_[cur * 2 + 2])) mc = cur * 2 + 2; // mc = rc;
        if (storage_[cur] < storage_[mc]) break;
        Swap(cur, mc);
        cur = mc;
    }
};

void minheap::rUpHeap(int cur) {
    if (cur == 0) return;
    if (storage_[cur] > storage_[(cur - 1) / 2]) return;
    Swap(cur, (cur - 1) / 2);
    rUpHeap((cur - 1) / 2);
};

void minheap::rDownHeap(int cur) {
    if ((cur * 2 + 1) >= last_) return; // no left child
    int mc = cur * 2 + 1; // mc=lc;
    if ((cur * 2 + 2 < last_) && (storage_[mc] > storage_[cur * 2 + 2])) mc = cur * 2 + 2; // mc = rc;
    if (storage_[cur] < storage_[mc]) return;
    Swap(cur, mc);
    rDownHeap(mc);
};

void MakeHeap() {
    int i = (hsize_ - 1) / 2;
    for (; i >= 0; i--) rDownHeap(i);
};


//heapsort1
void main() {
    int n;
    cin >> n;
    int data;
    minheap mh(n);
    for (int i = 0; i < n; i++) {
        cin >> data;
        mh.InsertMH(data);
    }
    for (int i = 0; i < n; i++) cout << mh.DeleteMH();
}

//heapsort2
void main() {
    int n;
    cin >> n;
    minheap mh(n);
    for (int i = 0; i < n; i++) cin >> mh.storage_[i];
    mh.last_ = n;
    mh.MakeHeap();
    for (int i = 0; i < n; i++) cout << mh.DeleteMH();
}
