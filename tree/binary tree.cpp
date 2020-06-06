#include<iostream>
#include<queue>
using namespace std;

class node { //나중에 파일분할 버전으로 브랜치로 시도
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

class binaryTree { //이진트리
public: //외부 클래스에서는 public 함수만 사용가능
	//void set(int s) {
	//    salary = s;
	//}
	node* get() {
		return root_;
	}
	// binaryTree ();
	binaryTree(int root); //생성자
	~binaryTree(); //소멸자
	// bool AddRoot (int root);
	bool Search(int el); //public으로 선언하면 다른 객체에서도 사용가능 단순히 protected 내에서 구현된 함수를 호출하는 기능만 가지고 있다.
	bool AddLeftChild(int parent, int child);
	bool AddRightChild(int parent, int child);
	int Height() { return Height(root_); };
	int NumberOfNodes() { return NumberOfNodes(root_); };
	void BFS(); //큐를 이용한단다.
	virtual void visit(node* ptr) { //가상함수?
		cout << "node " << ptr->data_ << " is visited" << endl;
	};
	// void DFS () { DFS(root_); };
	void PreOrderTraversal() { PreOrderTraversal(root_); };
	void InOrderTraversal() { InOrderTraversal(root_); };
	void PostOrderTraversal() { PostOrderTraversal(root_); };
protected:  //public or protected 상속받은  파생클래스는 이 함수를 사용할 수 있는듯? 그거 제외하면  private이랑 같은 기능? 나중에 물어봐야지
	void DeleteTree(node* ptr);
	node* Search(node* ptr, int el);
	int  Height(node* ptr);
	int  NumberOfNodes(node* ptr);
	void DFS(node* ptr);
	void PreOrderTraversal(node* ptr);
	void InOrderTraversal(node* ptr);
	void PostOrderTraversal(node* ptr);
private: //해당 객체의 public 멤버 함수를 통해서만 접근가능 또 해당 객체 내의 프렌드 함수를 통해서도?
	node* root_; //루트를 가리키는 노드
};

binaryTree::binaryTree(int root) {
	root_ = new node(root); //새 노드를 만들고 데이터값에 root값을 대입 나머지는 생성자초기화대로 0 0 노드 포인터인 루트는 이 root값 노드를 가리킴
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
	// return Search(root_, el);</font>
	if (Search(root_, el) == 0) return false; //루트 포인터와 찾는 값을 search 함수에 전달 없으면 false
	return true; //있음 true
};

node* binaryTree::Search(node* ptr, int el) { //ptr으로 받는다.(그래서 재귀함수가 잘 작동가능)
	if (ptr == 0) return 0; // 노드에 값 없으면 0 return   만약 값이 중복되는 게 있다면 어떠할까?
	if (ptr->data_ == el) return ptr; //초기에 가리킨 노드의 데이커가 찾는 값과 일치하면 그 노드를 가리키는 포인터(즉 데이터포함된 노드)를 되돌려줌
	node* tptr = Search(ptr->lc_, el); //왼쪽 노드 탐색한 후의 결과값을 tptr 포인터가 가리킴
	if (tptr) return tptr; //if(tptr!=0) return tptr
	tptr = Search(ptr->rc_, el);
	return tptr;
};

bool binaryTree::AddLeftChild(int parent, int child) {
	node* ptr = Search(root_, parent); //parent 노드 위치 탐색
	if (ptr == 0) return false; //노드가 없으면 false
	if (ptr->lc_ != 0) return false; //찾은 노드의 왼쪽자식노드가 있다면 false
	ptr->lc_ = new node(child); //그게 아니라면 왼쪽에 자식노드 생성
	return true;
};

bool binaryTree::AddRightChild(int parent, int child) {
	node* ptr = Search(root_, parent);
	if (ptr == 0) return false;
	if (ptr->rc_ != 0) return false;
	ptr->rc_ = new node(child);
	return true;
};

int binaryTree::Height(node* ptr) { //노드의 높이 계산 초기 root 포인터 전달
	if (ptr == 0) return 0; //노드가 없으면 높이도 0
	int hl = Height(ptr->lc_); //왼쪽 노드를 탐색 끝까지 마지막 노드부분에 도달하면 0을 리턴
	int hr = Height(ptr->rc_);
	if (hl > hr) return hl + 1; //노드를 기점으로 왼쪽, 오른쪽 노드를 다 탐험한 후에 돌아온 리턴값 중 큰 리턴값에 +1
	else return hr + 1;
};

int binaryTree::NumberOfNodes(node* ptr) { //노드의 수 계산
	if (ptr == 0) return 0; //루트가 가리키는 곳에 노드가 없다면 0개
	int nl = NumberOfNodes(ptr->lc_);
	int nr = NumberOfNodes(ptr->rc_);
	return nl + nr + 1; //왼쪽 오른쪽 다 탐험해서 값들을 더해준다.
};

void binaryTree::BFS() { //너비우선탐색
	queue <node*> q;
	q.push(root_);
	while (!q.empty()) {
		node* ptr = q.front(); //pop은 리턴 값이 없으므로 front를 사용해서 삭제할 포인터값(노드를 가리키는)을 끄집어 낸 다음 ptr에 저장하고
		q.pop(); //그 다음 삭제 (이유 찾는데 2시간 소요)
		visit(ptr);
		if (ptr->lc_ != 0) q.push(ptr->lc_);
		if (ptr->rc_ != 0) q.push(ptr->rc_);
	}
};

void binaryTree::DFS(node* ptr) { //깊이우선탐색 왼쪽을 기준으로 쭉쭉 밑으로 탐색
	if (ptr == 0) return;
	DFS(ptr->lc_);
	DFS(ptr->rc_);
};

void binaryTree::PreOrderTraversal(node* ptr) {//전위순회
	if (ptr == 0) return;
	visit(ptr);
	PreOrderTraversal(ptr->lc_);
	PreOrderTraversal(ptr->rc_);
};

void binaryTree::InOrderTraversal(node* ptr) {//중위순회
	if (ptr == 0) return;
	InOrderTraversal(ptr->lc_);
	visit(ptr);
	InOrderTraversal(ptr->rc_);
};

void binaryTree::PostOrderTraversal(node* ptr) { //후위순회
	if (ptr == 0) return;
	PostOrderTraversal(ptr->lc_);
	PostOrderTraversal(ptr->rc_);
	visit(ptr);
};

int main() { //main은 외부 사용자라고 볼 수 없는 건가? 외부의 extern 의미 정확히?
	binaryTree* bt = new binaryTree(3);

	int i, a;
	//for (i = 0; i < 5; i++) {
	//    cin >> a;
	//    bt->AddLeftChild(3,a);
	//}

	bt->AddLeftChild(3, 5);//3 데이터 값이 있는 노드 기준으로 5라는 데이터값의 왼쪽 자식노드를 생성.

	node* ptr = bt->get();
	bt->visit(ptr); //ptr도 루트를 가리키고 루트를 가리키므로 처음 노드를 똑같이 가리키는데

	bt->InOrderTraversal();//왜 안 되지? protected라서 안되나 개멍청했네 이미 public에서 선언되었구나

	//나중에 private 변수로도 해보고 프렌드랑 가상 함수 정의 알아오삼 파일분할도 해보고 존나 할거많네 토익증빙도 하삼
	//binary tree는 나중에 통합하고 private으로 
}

//
//
//int main() {
//    node* root_ = new node(11); //새로운 노드를 만들고 그 노드를 가리키는 포인터값인 root를 생성한다.
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