#pragma once
#include "node.h"

#include <iostream>  //원래 헤더파일에는 클래스의 선언만 있어야되고 함수는 없어야되지만
using namespace std; // 수정하기 귀찮으니 일단 cout 만들 수 있는 iosteram std 집어넣어라  

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
	node* root_;//  "_" <- 이게 맴버변수라고 구분하라는 의미같음
};