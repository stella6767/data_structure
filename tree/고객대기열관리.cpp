#include <iostream>
using namespace std;

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
protected:
    void DeleteTree(node* ptr);
    node* Search(node* ptr, int el);
    int  Maxn(node* ptr);
    int  Minn(node* ptr);
    int  Noon(node* ptr);
private:
    node* root_;
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
    return 0;
};