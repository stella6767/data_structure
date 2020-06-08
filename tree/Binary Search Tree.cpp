
//모든 노드의 키는 유일하다. 
//// 중복된 데이터를 갖는 노드가 없다는 뜻이다. 여기서 키의 의미는 노드 안에 들어 있는 데이터 값을 의미한다.
//왼쪽 서브 트리의 키들은 루트의  키보다 작다. 
//// 예를 들어 루트노드의 데이터가 5라고 하면, 왼쪽 서브트리에는 무조건 5보다 작은 값들만 존재해야 한다.
//오른쪽 서브 트리의 키들은 루트의 키보다 크다. 
//// 위와 같은 원리로 오른쪽에는 루트의 데이터 값보다 더 큰 값들만 존재한다.
//왼쪽과 오른쪽 서브 트리도 이진 탐색 트리이다. 
//// 순환적으로 정의되었다는 뜻이다. 즉 왼쪽 서브트리로 내려가든, 오른쪽 서브트리로 내려가든 동일한 법칙이 적용된다는 뜻이다.
//출처: https://mattlee.tistory.com/30 [waca's field]


#include "node.h"
#include "bst.h"
#include<iostream>
using namespace std;


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


//비주얼 이진탐색트리 https://www.cs.usfca.edu/~galles/visualization/BST.html
