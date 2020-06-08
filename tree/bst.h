#pragma once
#include "node.h"

#include <iostream>  //���� ������Ͽ��� Ŭ������ ���� �־�ߵǰ� �Լ��� ����ߵ�����
using namespace std; // �����ϱ� �������� �ϴ� cout ���� �� �ִ� iosteram std ����־��  

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
	node* root_;//  "_" <- �̰� �ɹ�������� �����϶�� �ǹ̰���
};