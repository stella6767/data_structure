#pragma once

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