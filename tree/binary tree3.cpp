
// node 수정: 부모노드를 가르키는 parent pointer포함
//통합된 노드도 만들고 프라이빗도 만들고 알고리즘도 적용하고 파일 분할도 해보고 다 해봐야지
//gist 개념과 비주얼 스튜디오 깃 사용법 전부 다 원격 저장소 여러개 remote 


#include <iostream>
using namespace std;


class node { 
public:
    node() {
        data_ = 0; lc_ = 0; rc_ = 0; //0으로 초기화
    }
    node(int data, node* lc = 0, node* rc = 0) {
        data_ = data;
        lc_ = lc;
        rc_ = rc;
    }
    // private: //나중에 따로 구현해봐야 할듯
    int data_;
    node* lc_;
    node* rc_;
};


class bst { //BST를 균형잡힌 이진트리로 변경해 주는 DSW (Colin Day, Quentin F. Stout, Bette L. Warren) 알고리즘
public:
    bst() { root_ = 0; };
    bst(node* root) { root_ = root; };
    void Balance(int data[], int first, int last);
    int Size(); //중요
        void DSW() {
        CreateBackBone(root_);
        CreatePerfectTree(root_, Size());
    }

protected:
    void LeftTurn(node* ptr);
    void RightTurn(node* ptr);
    void CreateBackBone(node* ptr);
    void CreatePerfectTree(node* ptr, int n);

private:
    node* root_;
};

void bst::Balance(int data[], int first, int last) {
    if (first <= last) {
        int middle = (first + last) / 2;
        insert(data[middle]);
        balance(data, first, middle - 1);
        balance(data, middle + 1, last);
    }
}

void bst::LeftTurn(node* ptr) {
    if (ptr->p_->d_ > ptr->d_) ptr->p_->l_ = ptr->r_;
    else ptr->p_->r_ = ptr->r_;
    node* rcptr = ptr->r_;
    ptr->r_ = rcptr->l_;
    rcptr->l_ = ptr;
}

void bst::RightTurn(node* ptr) {
    if (ptr->p_->d_ > ptr->d_) ptr->p_->l_ = ptr->l_;
    else ptr->p_->r_ = ptr->l_;
    node* lcptr = ptr->l_;
    ptr->l_ = lcptr->r_;
    lcptr->r_ = ptr;
}

void bst::CreateBackBone(node* root) {
    ptr = root;
    while (ptr != 0) {
        if (ptr->l_) { RightTrun(ptr); ptr = ptr->p_; }
        else ptr = ptr->r_;
    }
}

void bst::CreatePerfectTree(node* root, int n) {
    int m = Exp((int)Log(n + 1)) - 1;
    node* ptr = root;
    for (int i = 0; i < n - m; i++) {
        LeftTurn(ptr); ptr = ptr->p_->r_;
    }
    while (m > 1) {
        m = m / 2;
        node* ptr = root;
        for (int i = 0; i < m; i++) {
            LeftTurn(ptr); ptr = ptr->p_->r_;
        }
    }
}




int main() {




    return 0;
}