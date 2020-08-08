#include <iostream>
using namespace std;
//걍 또다른 이진탐색트리 문제
class node {
public:
    node() {
        data_ = 0; lc_ = 0; rc_ = 0;
    }
    node(int data, node* lc = 0, node* rc = 0) {
        data_ = data;
        lc_ = lc;
        rc_ = rc;
    }
public:
    int data_;
    node* lc_;
    node* rc_;
};

class binaryTree {
public:
    binaryTree(int root);
    ~binaryTree();
    bool Search(int el);
    bool AddLeftChild(int parent, int child);
    bool AddRightChild(int parent, int child);
    int NumberOfOddNumbers() { return Noon(root_); };
    int MaxNumber() { return Maxn(root_); };
    int MinNumber() { return Minn(root_); };
    int Diff(); // (최댓값 – 최솟값) 계산
    void Transpose() { Transpose(root_); };
    void InOrder() { InOrder(root_); cout << endl; };
protected:
    void DeleteTree(node* ptr);
    node* Search(node* ptr, int el);
    int  Maxn(node* ptr);
    int  Minn(node* ptr);
    int  Noon(node* ptr);
    void Transpose(node* ptr);
    void InOrder(node* ptr);
private:
    node* root_;
};

int
binaryTree::Diff() {
    if (!root_) return 0;
    node* ptr = root_;
    while (ptr->rc_) ptr = ptr->rc_;
    int max = ptr->data_;
    ptr = root_;
    while (ptr->lc_) ptr = ptr->lc_;
    int min = ptr->data_;
    return (max - min);
}

void
binaryTree::Transpose(node* ptr) {
    if (!ptr) return;
    node* tmp = ptr->lc_;
    ptr->lc_ = ptr->rc_;
    ptr->rc_ = tmp;
    Transpose(ptr->lc_);
    Transpose(ptr->rc_);
}

void
binaryTree::InOrder(node* ptr) {
    if (!ptr) return;
    InOrder(ptr->lc_);
    cout << ptr->data_ << " ";
    InOrder(ptr->rc_);
}

binaryTree::binaryTree(int root) {
    root_ = new node(root);
};

binaryTree::~binaryTree() {
    root_ = 0;
    DeleteTree(root_);
};

void binaryTree::DeleteTree(node* ptr) {
    if (ptr == 0) return;
    DeleteTree(ptr->lc_);
    DeleteTree(ptr->rc_);
    delete ptr;
};

bool binaryTree::Search(int el) {
    // return Search(root_, el);
    if (Search(root_, el) == 0) return false;
    return true;
};

node* binaryTree::Search(node* ptr, int el) {
    if (ptr == 0) return 0;
    if (ptr->data_ == el) return ptr;
    node* tptr = Search(ptr->lc_, el);
    if (tptr) return tptr;
    tptr = Search(ptr->rc_, el);
    return tptr;
};

bool binaryTree::AddLeftChild(int parent, int child) {
    node* ptr = Search(root_, parent);
    if (ptr == 0) return false;
    if (ptr->lc_ != 0) return false;
    ptr->lc_ = new node(child);
    return true;
};

bool binaryTree::AddRightChild(int parent, int child) {
    node* ptr = Search(root_, parent);
    if (ptr == 0) return false;
    if (ptr->rc_ != 0) return false;
    ptr->rc_ = new node(child);
    return true;
};

int binaryTree::Noon(node* ptr) {
    if (ptr == 0) return 0;
    int nl = Noon(ptr->lc_);
    int nr = Noon(ptr->rc_);
    if (ptr->data_ % 2 != 0) return nl + nr + 1;
    else return nl + nr;
};

int binaryTree::Maxn(node* ptr) {
    int tmp = ptr->data_;
    if (ptr->lc_ != 0) {
        int nl = Maxn(ptr->lc_);
        if (tmp < nl) tmp = nl;
    }
    if (ptr->rc_ != 0) {
        int nr = Maxn(ptr->rc_);
        if (tmp < nr) tmp = nr;
    }
    return tmp;
};

int binaryTree::Minn(node* ptr) {
    int tmp = ptr->data_;
    if (ptr->lc_ != 0) {
        int nl = Maxn(ptr->lc_);
        if (nl < tmp) tmp = nl;
    }
    if (ptr->rc_ != 0) {
        int nr = Maxn(ptr->rc_);
        if (nr < tmp) tmp = nr;
    }
    return tmp;
};

int main() {
    int n, p, f, c;

    cin >> n;
    cin >> p;
    binaryTree* bt = new binaryTree(p);
    for (int i = 1; i < n; i++) {
        cin >> p >> f >> c;
        if (f == 0) bt->AddLeftChild(p, c);
        else bt->AddRightChild(p, c);
    }

    cout << bt->MaxNumber() << " ";
    cout << bt->MinNumber() << " ";
    cout << bt->NumberOfOddNumbers() << " ";
    cout << bt->Diff() << " ";
    bt->InOrder();
    bt->Transpose();
    bt->InOrder();
    return 0;
};
