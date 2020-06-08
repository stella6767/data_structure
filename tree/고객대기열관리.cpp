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
	DeleteTree(root_); //deletetree 함수호출
	root_ = 0; //사실 쓸 필요는 없음
};

void binaryTree::DeleteTree(node* ptr) { //재귀함수를 활용해 루트 노드가 연결한 모든 자식노드들을 삭제
	if (ptr == 0) return; //노드를 가리키는 포인터로 매개변수를 받고 만약 자손노드가 없으면 그냥 리턴
	DeleteTree(ptr->lc_); //루트 아래에 노드가 있다면 다시 delete 함수를 호출해 루트 자손의 자손 노드를 탐색
	DeleteTree(ptr->rc_); //이런 식으로 재귀함수로 리프노드까지 가서
	delete ptr; //거기서부터 삭제 위로 올라가서 또 삭제 삭제
};

bool binaryTree::Search(int el) { //찾는 값을 매개변수로 전달
	if (Search(root_, el) == 0) return false; //루트 포인터와 찾는 값을 search 함수에 전달 없으면 false
	return true; //있음 true
};

node* binaryTree::Search(node* ptr, int el) { //ptr으로 받는다.(그래서 재귀함수가 잘 작동가능)
	if (ptr == 0) return 0; // 노드에 값 없으면 0 return   만약 값이 중복되는 게 있다면 어떠할까?
	if (ptr->data_ == el) return ptr; //초기에 가리킨 노드의 데이터가 찾는 값과 일치하면 그 노드를 가리키는 포인터(즉 데이터포함된 노드)를 되돌려줌
	node* tptr = Search(ptr->lc_, el); //왼쪽 노드 탐색한 후의 결과값을 tptr 포인터가 가리킴
	if (tptr) return tptr; //if(tptr!=0) return tptr
	tptr = Search(ptr->rc_, el);
	return tptr;
};

bool binaryTree::AddLeftChild(int parent, int child) {
	node* ptr = Search(root_, parent); //parent 노드 위치 탐색
	if (ptr == 0) return false; //노드가 없으면 false
	while (ptr->lc_ != 0) {
		ptr = ptr->lc_;
	}
	ptr->lc_ = new node(child); //그게 아니라면 왼쪽에 자식노드 생성
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

int binaryTree::Noon(node* ptr) { //홀수의 계산
	int count = 0;

	if (ptr == NULL)
		return 0;

	count = Noon(ptr->lc_); //왼쪽 서브트리의 홀수 계산
	count += Noon(ptr->rc_); //오른쪽 트리꺼까지 홀수 더함

	if (ptr->data_ % 2 == 1) //루트 노드가 홀수인 것 까지 확인
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