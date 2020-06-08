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
	~binaryTree(); //�Ҹ���
	binaryTree* Search(binaryTree* ptr, int el);
	bool AddLeftChild(int parent, int child,binaryTree* root_);
	//bool AddRightChild(int parent, int child);

	virtual void visit(binaryTree* ptr) { //�����Լ�? ��� Ŭ�������� ��ӹ��� Ŭ������ �θ�Ŭ������ �Լ����� �ߺ��ɶ� ���
		cout << "node " << ptr->node_ << " is visited" << endl;
	};

	void PreOrderTraversal(binaryTree* root);

private:
    int node_;
	binaryTree* lc; //leftsubtree_; 
	binaryTree* rc; //rightsubtree_; 
};

binaryTree* binaryTree::Search(binaryTree* ptr, int el) { //bt�� �޾�����(root)
	if (ptr == 0) return 0; // ��忡 �� ������ 0 return   ���� ���� �ߺ��Ǵ� �� �ִٸ� ��ұ�?
	if (ptr->node_ == el) return ptr; //�ʱ⿡ ����Ų ����� ����Ŀ�� ã�� ���� ��ġ�ϸ� �� ��带 ����Ű�� ������(�� ���������Ե� ���)�� �ǵ�����
	binaryTree* tptr = Search(ptr->lc, el); //���� ��� Ž���� ���� ������� tptr �����Ͱ� ����Ŵ
	if (tptr) return tptr; //if(tptr!=0) return tptr
	tptr = Search(ptr->rc, el);
	return tptr;
};


bool binaryTree::AddLeftChild(int parent, int child, binaryTree* root_) {
	binaryTree* ptr = Search(root_, parent); //parent ��� ��ġ Ž��
	if (ptr == 0) return false; //��尡 ������ false
	if (ptr->lc != 0) return false; //ã�� ����� �����ڽĳ�尡 �ִٸ� false
	ptr->lc = new binaryTree(child); //�װ� �ƴ϶�� ���ʿ� �ڽĳ�� ����
	return true;
};

//bool binaryTree::AddRightChild(int parent, int child) {
//	node* ptr = Search(root_, parent);
//	if (ptr == 0) return false;
//	if (ptr->rc_ != 0) return false;
//	ptr->rc_ = new node(child);
//	return true;
//};


void binaryTree::PreOrderTraversal(binaryTree* ptr) {//������ȸ
	if (ptr == 0) return;
	visit(ptr);
	PreOrderTraversal(ptr->lc);
	PreOrderTraversal(ptr->rc);
};

int main() {
    binaryTree* bt = new binaryTree(1); //bt�� root

	binaryTree* ptr = bt->getlc(); //�����̺� ���ٹ�� �̰͹ۿ� �����ȳ�
	ptr = new binaryTree(3);
	
	bt->AddLeftChild(1, 2, bt);
    bt->PreOrderTraversal(bt);
}
