#include<iostream>
using namespace std;

class node { //bst tree
public:
	node() {
		d_ = 0; p_ = 0; l_ = 0; r_ = 0;
	}
	node(int d, node* p = 0, node* l = 0, node* r = 0) {
		d_ = d;
		p_ = p;
		l_ = l;
		r_ = r;
	}
	// private:
	int d_;
	node* p_; //�θ���� �������ִ� ������
	node* l_;
	node* r_;
};

class bst {
public:
	bst() { root_ = 0; };
	bst(node* root) { root_ = root; };
	~bst();
	bool Search(int el);
	void Insert(int el);
	bool Delete(int x);
	void PreOrderTraversal() { PreOrderTraversal(root_); };
	void InOrderTraversal() { InOrderTraversal(root_); };
	void PosteOrderTraversal() { PostOrderTraversal(root_); };
protected:
	node* Search(node* ptr, int el);
	void Insert(node* ptr, int el);
	node* DeleteByMerging(node* ptr);
	//  node * DeleteByCopying(node * ptr);
	virtual void visit(node* ptr) {
		cout << "node " << ptr->d_ << " is visited" << endl; // underscore �߰�
	};
	void PreOrderTraversal(node* ptr);
	void InOrderTraversal(node* ptr);
	void PostOrderTraversal(node* ptr);
private:
	node* root_;//_�̰� �ɹ�������� �����϶�� �ǹ̰���
};

bool bst::Search(int el) {
	if (Search(root_, el) != 0) return true;
	else return false; //ã�� ���� ���� ���
}

node* bst::Search(node* ptr, int el) {
	if (ptr == 0) return 0;  //���ٴ� ��
	if (ptr->d_ == el) return ptr; //������ �ٷ� �����ְ�
	else if (ptr->d_ > el) return Search(ptr->l_, el); //����� ���� ã�� ������ ũ�ٸ� ���� ���� �̵��� ���� �۾�
	else return Search(ptr->r_, el);
}

void bst::Insert(int el) { //�Ű������� �ٸ��� �ٸ� �Լ� ��޹޴´ٴ� ���� �̿�
	if (root_ == 0) root_ = new node(el); //���� ������ ���ο� ��带 ����� ��Ʈ�����Ͱ� �ű⸦ ����Ű����.
	else Insert(root_, el);
}

void bst::Insert(node* ptr, int el) {
	if (ptr->d_ == el) return; //���� �ߺ��Ǵ� �� �ִٸ� �׳� ����
	else if (ptr->d_ > el) { //�θ����� ���� ���԰����� ũ�ٸ�
		if (ptr->l_ == 0) ptr->l_ = new node(el, ptr);//���� �Ʒ��� ��尡 ���ٸ� ���ʿ� ��带 ������
		else Insert(ptr->l_, el); //�ƴϸ� �ٽ� �Լ��� �����ؼ� ���� ������ �� �� Ž��
	}
	else { //���԰����� �۴ٸ�
		if (ptr->r_ == 0) ptr->r_ = new node(el, ptr); //���ϵ���
		else Insert(ptr->r_, el);
	}
}

bool bst::Delete(int el) {
	node* ptr = Search(root_, el); //������ ��� ã��
	if (ptr->p_ == 0) { //��Ʈ��� ������
		root_ = DeleteByMerging(ptr); //���� ���۳�带 ����Ű�� ��Ʈ�� ���ο� ��Ʈ��带 ����Ű����
		delete ptr;
		return true;
	}
	if (ptr == 0) return false;
	if (ptr->p_->d_ > ptr->d_) {//������ ����� �θ����� ���� ������� ������ ���ٸ� �θ����� ���� �����Ͱ�(����) ����
		ptr->p_->l_ = DeleteByMerging(ptr);
	}

	else {
		ptr->p_->r_ = DeleteByMerging(ptr);//�θ����� ������ �����Ͱ�(����)�� ����
	}
	delete ptr; //��� ����
	return true;
}

node* bst::DeleteByMerging(node* ptr) { //���ذ� �� ���°� �ڽ� ����� parent �����Ͱ��� �̻��ϰ� �Ǵµ� ��������.
	if (ptr->l_ == 0 && ptr->r_ == 0) return 0;// ������ ����� �ڽĳ�尡 ���ٸ� 0 ��ȯ

	if (ptr->l_ == 0) {
		node* tptr = ptr->r_;
		tptr->p_ = ptr->p_;   return ptr->r_;
	} //�� �Լ����� �θ������� �����ϰ�, ��ȯ���� ���ܰ迡�� ����
	if (ptr->r_ == 0) {
		node* tptr = ptr->l_;
		tptr->p_ = ptr->p_;
		return ptr->l_;
	}
	node* tptr = ptr->l_; //�������� �� �� �̵�
	while (tptr->r_ != 0) { tptr = tptr->r_; }//������ ����� ���ʳ���� ������ �ڽĳ�尡 0�� �ƴ϶�� ��� ���������� ����Ž��
	if (tptr->p_ == 0) { //��Ʈ��带 ������ ����Ǵ� �Լ�
		tptr->r_ = ptr->r_;  //�׳� �� �α׸� ���� ����
		tptr->p_ = ptr->p_; 
		tptr->p_->r_ = ptr->r_;  
		tptr->p_->l_ = ptr->l_; 
		tptr->l_ = ptr->l_; 
		return tptr;
	}

	tptr->r_ = ptr->r_; //�׷��� ���� ��������� ������ �����Ͱ� ��������� ������ �ڽĳ�带 ����Ŵ
	tptr->p_ = ptr->p_; //�θ𰡸�Ű�� �͵� �ٲ���
	return ptr->l_; //��������� �����ڽ� ��������Ͱ� ��ȯ
}

void bst::PreOrderTraversal(node* ptr) {
	if (ptr == 0) return;
	visit(ptr);
	PreOrderTraversal(ptr->l_);
	PreOrderTraversal(ptr->r_);
};

void bst::InOrderTraversal(node* ptr) {
	if (ptr == 0) return;
	InOrderTraversal(ptr->l_);
	visit(ptr);
	InOrderTraversal(ptr->r_);
};

void bst::PostOrderTraversal(node* ptr) {
	if (ptr == 0) return;
	PostOrderTraversal(ptr->l_);
	PostOrderTraversal(ptr->r_);
	visit(ptr);
};

int main() {
	bst* bt = new bst();

	bt->Insert(4);
	bt->Insert(2);
	bt->Insert(3);
	bt->Insert(1);
	bt->Insert(6);
	bt->Insert(5);
	bt->Insert(7);
	bt->Insert(10);
	bt->Insert(8);
	bt->Insert(9);
	bt->PreOrderTraversal();

	cout << "10,7,6,4, ���� �� ���� ��ȸ" << endl;
	bt->Delete(10);
	bt->Delete(7);
	bt->Delete(6); //ctrl+d ���ٺ����� �Ʒ��̵�
	bt->Delete(4); 
	bt->PreOrderTraversal();
	cout << "������ȸ" << endl;
	bt->InOrderTraversal();
	cout << "������ȸ" << endl;
	bt->PosteOrderTraversal();
}