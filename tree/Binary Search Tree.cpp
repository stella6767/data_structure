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
	node* p_; //부모노드와 연결해주는 포인터
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
		cout << "node " << ptr->d_ << " is visited" << endl; // underscore 추가
	};
	void PreOrderTraversal(node* ptr);
	void InOrderTraversal(node* ptr);
	void PostOrderTraversal(node* ptr);
private:
	node* root_;//_이게 맴버변수라고 구분하라는 의미같음
};

bool bst::Search(int el) {
	if (Search(root_, el) != 0) return true;
	else return false; //찾는 값이 없는 경우
}

node* bst::Search(node* ptr, int el) {
	if (ptr == 0) return 0;  //없다는 말
	if (ptr->d_ == el) return ptr; //있으면 바로 돌려주고
	else if (ptr->d_ > el) return Search(ptr->l_, el); //노드의 값이 찾는 값보다 크다면 왼쪽 노드로 이동후 같은 작업
	else return Search(ptr->r_, el);
}

void bst::Insert(int el) { //매개변수가 다르면 다른 함수 취급받는다는 것을 이용
	if (root_ == 0) root_ = new node(el); //값이 없으면 새로운 노드를 만들고 루트포인터가 거기를 가르키게함.
	else Insert(root_, el);
}

void bst::Insert(node* ptr, int el) {
	if (ptr->d_ == el) return; //값이 중복되는 게 있다면 그냥 리턴
	else if (ptr->d_ > el) { //부모노드의 값이 삽입값보다 크다면
		if (ptr->l_ == 0) ptr->l_ = new node(el, ptr);//왼쪽 아래에 노드가 없다면 왼쪽에 노드를 만들어라
		else Insert(ptr->l_, el); //아니면 다시 함수를 실행해서 왼쪽 오른쪽 값 비교 탐색
	}
	else { //삽입값보다 작다면
		if (ptr->r_ == 0) ptr->r_ = new node(el, ptr); //이하동문
		else Insert(ptr->r_, el);
	}
}

bool bst::Delete(int el) {
	node* ptr = Search(root_, el); //삭제할 노드 찾음
	if (ptr->p_ == 0) { //루트노드 삭제시
		root_ = DeleteByMerging(ptr); //기존 시작노드를 가리키던 루트가 새로운 루트노드를 가리키도록
		delete ptr;
		return true;
	}
	if (ptr == 0) return false;
	if (ptr->p_->d_ > ptr->d_) {//삭제할 노드의 부모노드의 값이 삭제노드 값보다 많다면 부모노드의 왼쪽 포인터값(간선) 결정
		ptr->p_->l_ = DeleteByMerging(ptr);
	}

	else {
		ptr->p_->r_ = DeleteByMerging(ptr);//부모노드의 오른쪽 포인터값(간선)을 결정
	}
	delete ptr; //노드 삭제
	return true;
}

node* bst::DeleteByMerging(node* ptr) { //이해가 안 가는게 자식 노드의 parent 포인터값은 이상하게 되는데 질문하자.
	if (ptr->l_ == 0 && ptr->r_ == 0) return 0;// 삭제할 노드의 자식노드가 없다면 0 반환

	if (ptr->l_ == 0) {
		node* tptr = ptr->r_;
		tptr->p_ = ptr->p_;   return ptr->r_;
	} //이 함수에서 부모포인터 변경하고, 반환값은 윗단계에서 변경
	if (ptr->r_ == 0) {
		node* tptr = ptr->l_;
		tptr->p_ = ptr->p_;
		return ptr->l_;
	}
	node* tptr = ptr->l_; //왼쪽으로 한 번 이동
	while (tptr->r_ != 0) { tptr = tptr->r_; }//삭제할 노드의 왼쪽노드의 오른쪽 자식노드가 0이 아니라면 계속 오른쪽으로 깊이탐색
	if (tptr->p_ == 0) { //루트노드를 삭재시 시행되는 함수
		tptr->r_ = ptr->r_;  //그냥 다 싸그리 간선 변경
		tptr->p_ = ptr->p_; 
		tptr->p_->r_ = ptr->r_;  
		tptr->p_->l_ = ptr->l_; 
		tptr->l_ = ptr->l_; 
		return tptr;
	}

	tptr->r_ = ptr->r_; //그래서 만난 리프노드의 오른쪽 포인터가 삭제노드의 오른쪽 자식노드를 가리킴
	tptr->p_ = ptr->p_; //부모가리키는 것도 바꾸자
	return ptr->l_; //삭제노드의 왼쪽자식 노드포인터값 반환
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

	cout << "10,7,6,4, 삭제 후 전위 순회" << endl;
	bt->Delete(10);
	bt->Delete(7);
	bt->Delete(6); //ctrl+d 한줄복사후 아래이동
	bt->Delete(4); 
	bt->PreOrderTraversal();
	cout << "중위순회" << endl;
	bt->InOrderTraversal();
	cout << "후위순회" << endl;
	bt->PosteOrderTraversal();
}