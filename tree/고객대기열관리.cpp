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

binaryTree::binaryTree(int root) {
	root_ = new node(root);
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
	if (Search(root_, el) == 0) return false; //��Ʈ �����Ϳ� ã�� ���� search �Լ��� ���� ������ false
	return true; //���� true
};

node* binaryTree::Search(node* ptr, int el) { //ptr���� �޴´�.(�׷��� ����Լ��� �� �۵�����)
	if (ptr == 0) return 0; // ��忡 �� ������ 0 return   ���� ���� �ߺ��Ǵ� �� �ִٸ� ��ұ�?
	if (ptr->data_ == el) return ptr; //�ʱ⿡ ����Ų ����� �����Ͱ� ã�� ���� ��ġ�ϸ� �� ��带 ����Ű�� ������(�� ���������Ե� ���)�� �ǵ�����
	node* tptr = Search(ptr->lc_, el); //���� ��� Ž���� ���� ������� tptr �����Ͱ� ����Ŵ
	if (tptr) return tptr; //if(tptr!=0) return tptr
	tptr = Search(ptr->rc_, el);
	return tptr;
};

bool binaryTree::AddLeftChild(int parent, int child) {
	node* ptr = Search(root_, parent); //parent ��� ��ġ Ž��
	if (ptr == 0) return false; //��尡 ������ false
	while (ptr->lc_ != 0) {
		ptr = ptr->lc_;
	}
	ptr->lc_ = new node(child); //�װ� �ƴ϶�� ���ʿ� �ڽĳ�� ����
	return true;
};

bool binaryTree::AddRightChild(int parent, int child) {
	node* ptr = Search(root_, parent);
	if (ptr == 0) return false;
	while (ptr->rc_ != 0) {
		ptr = ptr->rc_;
	}
	ptr->rc_ = new node(child);
	return true;
};

int binaryTree::Maxn(node* ptr) {
	int left, right, max;
	if (ptr == NULL) return NULL;

	max = ptr->data_;
	left = Maxn(ptr->lc_);
	right = Maxn(ptr->rc_);

	if (left > max)
		max = left;
	if (right > max)
		max = right;
	return max;
};

int binaryTree::Minn(node* ptr) {
	int min = ptr->data_;
	int tmp;
	if (ptr->lc_ != NULL)
	{
		tmp = Minn(ptr->lc_);
		min = (min < tmp) ? min : tmp;
	}
	if (ptr->rc_ != NULL)
	{
		tmp = Minn(ptr->rc_);
		min = (min < tmp) ? min : tmp;
	}
	return min;
};

int binaryTree::Noon(node* ptr) { //Ȧ���� ���
	int count = 0;

	if (ptr == NULL)
		return 0;

	count = Noon(ptr->lc_); //���� ����Ʈ���� Ȧ�� ���
	count += Noon(ptr->rc_); //������ Ʈ�������� Ȧ�� ����

	if (ptr->data_ % 2 == 1) //��Ʈ ��尡 Ȧ���� �� ���� Ȯ��
		count += 1;

	return count;
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

//int FindMax(node* root, int max)
//{
//	if (root->x > max) max = root->x;
//	if (root->left != NULL)
//		max = FindMax(root->left, max);
//	if (root->right != NULL)
//		max = FindMax(root->right, max);
//	return max;
//}