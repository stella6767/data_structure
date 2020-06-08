
// node ����: �θ��带 ����Ű�� parent pointer����
//���յ� ��嵵 ����� �����̺��� ����� �˰��� �����ϰ� ���� ���ҵ� �غ��� �� �غ�����
//gist ����� ���־� ��Ʃ��� �� ���� ���� �� ���� ����� ������ remote 


#include <iostream>
using namespace std;


class node { 
public:
    node() {
        data_ = 0; lc_ = 0; rc_ = 0; //0���� �ʱ�ȭ
    }
    node(int data, node* lc = 0, node* rc = 0) {
        data_ = data;
        lc_ = lc;
        rc_ = rc;
    }
    // private: //���߿� ���� �����غ��� �ҵ�
    int data_;
    node* lc_;
    node* rc_;
};


class bst { //BST�� �������� ����Ʈ���� ������ �ִ� DSW (Colin Day, Quentin F. Stout, Bette L. Warren) �˰���
public:
    bst() { root_ = 0; };
    bst(node* root) { root_ = root; };
    void Balance(int data[], int first, int last);
    int Size(); //�߿�
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