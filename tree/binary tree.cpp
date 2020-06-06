#include<iostream>
#include<queue>
using namespace std;

class node { //���߿� ���Ϻ��� �������� �귣ġ�� �õ�
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

class binaryTree { //����Ʈ��
public: //�ܺ� Ŭ���������� public �Լ��� ��밡��
	//void set(int s) {
	//    salary = s;
	//}
	node* get() {
		return root_;
	}
	// binaryTree ();
	binaryTree(int root); //������
	~binaryTree(); //�Ҹ���
	// bool AddRoot (int root);
	bool Search(int el); //public���� �����ϸ� �ٸ� ��ü������ ��밡�� �ܼ��� protected ������ ������ �Լ��� ȣ���ϴ� ��ɸ� ������ �ִ�.
	bool AddLeftChild(int parent, int child);
	bool AddRightChild(int parent, int child);
	int Height() { return Height(root_); };
	int NumberOfNodes() { return NumberOfNodes(root_); };
	void BFS(); //ť�� �̿��Ѵܴ�.
	virtual void visit(node* ptr) { //�����Լ�?
		cout << "node " << ptr->data_ << " is visited" << endl;
	};
	// void DFS () { DFS(root_); };
	void PreOrderTraversal() { PreOrderTraversal(root_); };
	void InOrderTraversal() { InOrderTraversal(root_); };
	void PostOrderTraversal() { PostOrderTraversal(root_); };
protected:  //public or protected ��ӹ���  �Ļ�Ŭ������ �� �Լ��� ����� �� �ִµ�? �װ� �����ϸ�  private�̶� ���� ���? ���߿� ���������
	void DeleteTree(node* ptr);
	node* Search(node* ptr, int el);
	int  Height(node* ptr);
	int  NumberOfNodes(node* ptr);
	void DFS(node* ptr);
	void PreOrderTraversal(node* ptr);
	void InOrderTraversal(node* ptr);
	void PostOrderTraversal(node* ptr);
private: //�ش� ��ü�� public ��� �Լ��� ���ؼ��� ���ٰ��� �� �ش� ��ü ���� ������ �Լ��� ���ؼ���?
	node* root_; //��Ʈ�� ����Ű�� ���
};

binaryTree::binaryTree(int root) {
	root_ = new node(root); //�� ��带 ����� �����Ͱ��� root���� ���� �������� �������ʱ�ȭ��� 0 0 ��� �������� ��Ʈ�� �� root�� ��带 ����Ŵ
};

binaryTree::~binaryTree() {
	DeleteTree(root_); //deletetree �Լ�ȣ��
	root_ = 0; //��� �� �ʿ�� ����
};

void binaryTree::DeleteTree(node* ptr) { //����Լ��� Ȱ���� ��Ʈ ��尡 ������ ��� �ڽĳ����� ����
	if (ptr == 0) return; //��带 ����Ű�� �����ͷ� �Ű������� �ް� ���� �ڼճ�尡 ������ �׳� ����
	DeleteTree(ptr->lc_); //��Ʈ �Ʒ��� ��尡 �ִٸ� �ٽ� delete �Լ��� ȣ���� ��Ʈ �ڼ��� �ڼ� ��带 Ž��
	DeleteTree(ptr->rc_); //�̷� ������ ����Լ��� ���������� ����
	delete ptr; //�ű⼭���� ���� ���� �ö󰡼� �� ���� ����
};

bool binaryTree::Search(int el) { //ã�� ���� �Ű������� ����
	// return Search(root_, el);</font>
	if (Search(root_, el) == 0) return false; //��Ʈ �����Ϳ� ã�� ���� search �Լ��� ���� ������ false
	return true; //���� true
};

node* binaryTree::Search(node* ptr, int el) { //ptr���� �޴´�.(�׷��� ����Լ��� �� �۵�����)
	if (ptr == 0) return 0; // ��忡 �� ������ 0 return   ���� ���� �ߺ��Ǵ� �� �ִٸ� ��ұ�?
	if (ptr->data_ == el) return ptr; //�ʱ⿡ ����Ų ����� ����Ŀ�� ã�� ���� ��ġ�ϸ� �� ��带 ����Ű�� ������(�� ���������Ե� ���)�� �ǵ�����
	node* tptr = Search(ptr->lc_, el); //���� ��� Ž���� ���� ������� tptr �����Ͱ� ����Ŵ
	if (tptr) return tptr; //if(tptr!=0) return tptr
	tptr = Search(ptr->rc_, el);
	return tptr;
};

bool binaryTree::AddLeftChild(int parent, int child) {
	node* ptr = Search(root_, parent); //parent ��� ��ġ Ž��
	if (ptr == 0) return false; //��尡 ������ false
	if (ptr->lc_ != 0) return false; //ã�� ����� �����ڽĳ�尡 �ִٸ� false
	ptr->lc_ = new node(child); //�װ� �ƴ϶�� ���ʿ� �ڽĳ�� ����
	return true;
};

bool binaryTree::AddRightChild(int parent, int child) {
	node* ptr = Search(root_, parent);
	if (ptr == 0) return false;
	if (ptr->rc_ != 0) return false;
	ptr->rc_ = new node(child);
	return true;
};

int binaryTree::Height(node* ptr) { //����� ���� ��� �ʱ� root ������ ����
	if (ptr == 0) return 0; //��尡 ������ ���̵� 0
	int hl = Height(ptr->lc_); //���� ��带 Ž�� ������ ������ ���κп� �����ϸ� 0�� ����
	int hr = Height(ptr->rc_);
	if (hl > hr) return hl + 1; //��带 �������� ����, ������ ��带 �� Ž���� �Ŀ� ���ƿ� ���ϰ� �� ū ���ϰ��� +1
	else return hr + 1;
};

int binaryTree::NumberOfNodes(node* ptr) { //����� �� ���
	if (ptr == 0) return 0; //��Ʈ�� ����Ű�� ���� ��尡 ���ٸ� 0��
	int nl = NumberOfNodes(ptr->lc_);
	int nr = NumberOfNodes(ptr->rc_);
	return nl + nr + 1; //���� ������ �� Ž���ؼ� ������ �����ش�.
};

void binaryTree::BFS() { //�ʺ�켱Ž��
	queue <node*> q;
	q.push(root_);
	while (!q.empty()) {
		node* ptr = q.front(); //pop�� ���� ���� �����Ƿ� front�� ����ؼ� ������ �����Ͱ�(��带 ����Ű��)�� ������ �� ���� ptr�� �����ϰ�
		q.pop(); //�� ���� ���� (���� ã�µ� 2�ð� �ҿ�)
		visit(ptr);
		if (ptr->lc_ != 0) q.push(ptr->lc_);
		if (ptr->rc_ != 0) q.push(ptr->rc_);
	}
};

void binaryTree::DFS(node* ptr) { //���̿켱Ž�� ������ �������� ���� ������ Ž��
	if (ptr == 0) return;
	DFS(ptr->lc_);
	DFS(ptr->rc_);
};

void binaryTree::PreOrderTraversal(node* ptr) {//������ȸ
	if (ptr == 0) return;
	visit(ptr);
	PreOrderTraversal(ptr->lc_);
	PreOrderTraversal(ptr->rc_);
};

void binaryTree::InOrderTraversal(node* ptr) {//������ȸ
	if (ptr == 0) return;
	InOrderTraversal(ptr->lc_);
	visit(ptr);
	InOrderTraversal(ptr->rc_);
};

void binaryTree::PostOrderTraversal(node* ptr) { //������ȸ
	if (ptr == 0) return;
	PostOrderTraversal(ptr->lc_);
	PostOrderTraversal(ptr->rc_);
	visit(ptr);
};

int main() { //main�� �ܺ� ����ڶ�� �� �� ���� �ǰ�? �ܺ��� extern �ǹ� ��Ȯ��?
	binaryTree* bt = new binaryTree(3);

	int i, a;
	//for (i = 0; i < 5; i++) {
	//    cin >> a;
	//    bt->AddLeftChild(3,a);
	//}

	bt->AddLeftChild(3, 5);//3 ������ ���� �ִ� ��� �������� 5��� �����Ͱ��� ���� �ڽĳ�带 ����.

	node* ptr = bt->get();
	bt->visit(ptr); //ptr�� ��Ʈ�� ����Ű�� ��Ʈ�� ����Ű�Ƿ� ó�� ��带 �Ȱ��� ����Ű�µ�

	bt->InOrderTraversal();//�� �� ����? protected�� �ȵǳ� ����û�߳� �̹� public���� ����Ǿ�����

	//���߿� private �����ε� �غ��� ������� ���� �Լ� ���� �˾ƿ��� ���Ϻ��ҵ� �غ��� ���� �ҰŸ��� ���������� �ϻ�
	//binary tree�� ���߿� �����ϰ� private���� 
}

//
//
//int main() {
//    node* root_ = new node(11); //���ο� ��带 ����� �� ��带 ����Ű�� �����Ͱ��� root�� �����Ѵ�.
//    root_->lc_ = new node(22);
//    root_->lc_->lc_ = new node(33);
//    root_->rc_ = new node(45);
//    root_->rc_->lc_ = new node(7);
//    root_->rc_->rc_ = new node(29);
//};

//void main() {
//    node* lc_ = new node(33);
//    node* tmp1 = new node(22, lc_);
//    lc_ = new node(7);
//    node* rc_ = new node(29);
//    node* tmp2 = new node(45, lc_, rc_);
//    node* root_ = new node(11, tmp1, tmp2);
//};