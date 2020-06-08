#include <iostream>
using namespace std;


class binaryTree {
public:
	binaryTree* getlc() {
		return lc;
	}

	binaryTree(int n=0, binaryTree* l = 0, binaryTree* r = 0) {
		node_ = n;
		lc = l;
		rc = r;
	}
	~binaryTree(); //소멸자
	binaryTree* Search(binaryTree* ptr, int el);
	bool AddLeftChild(int parent, int child,binaryTree* root_);
	//bool AddRightChild(int parent, int child);

	virtual void visit(binaryTree* ptr) { //가상함수? 상속 클래스에서 상속받은 클래스가 부모클래스와 함수명이 중복될때 사용
		cout << "node " << ptr->node_ << " is visited" << endl;
	};

	void PreOrderTraversal(binaryTree* root);

private:
    int node_;
	binaryTree* lc; //leftsubtree_; 
	binaryTree* rc; //rightsubtree_; 
};

binaryTree* binaryTree::Search(binaryTree* ptr, int el) { //bt로 받아주자(root)
	if (ptr == 0) return 0; // 노드에 값 없으면 0 return   만약 값이 중복되는 게 있다면 어떠할까?
	if (ptr->node_ == el) return ptr; //초기에 가리킨 노드의 데이커가 찾는 값과 일치하면 그 노드를 가리키는 포인터(즉 데이터포함된 노드)를 되돌려줌
	binaryTree* tptr = Search(ptr->lc, el); //왼쪽 노드 탐색한 후의 결과값을 tptr 포인터가 가리킴
	if (tptr) return tptr; //if(tptr!=0) return tptr
	tptr = Search(ptr->rc, el);
	return tptr;
};


bool binaryTree::AddLeftChild(int parent, int child, binaryTree* root_) {
	binaryTree* ptr = Search(root_, parent); //parent 노드 위치 탐색
	if (ptr == 0) return false; //노드가 없으면 false
	if (ptr->lc != 0) return false; //찾은 노드의 왼쪽자식노드가 있다면 false
	ptr->lc = new binaryTree(child); //그게 아니라면 왼쪽에 자식노드 생성
	return true;
};

//bool binaryTree::AddRightChild(int parent, int child) {
//	node* ptr = Search(root_, parent);
//	if (ptr == 0) return false;
//	if (ptr->rc_ != 0) return false;
//	ptr->rc_ = new node(child);
//	return true;
//};


void binaryTree::PreOrderTraversal(binaryTree* ptr) {//전위순회
	if (ptr == 0) return;
	visit(ptr);
	PreOrderTraversal(ptr->lc);
	PreOrderTraversal(ptr->rc);
};

int main() {
    binaryTree* bt = new binaryTree(1); //bt가 root

	binaryTree* ptr = bt->getlc(); //프라이빗 접근방법 이것밖에 생각안남
	ptr = new binaryTree(3);
	
	bt->AddLeftChild(1, 2, bt);
    bt->PreOrderTraversal(bt);
}
