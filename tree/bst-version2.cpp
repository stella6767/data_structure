#include<iostream>
using namespace std;

class Node {
private:
	int data;

	Node* left;

	Node* right;

public:

	Node(int data) {
		this->data = data;

		left = NULL;

		right = NULL;
	}

	void SetData(int data) {
		this->data = data;
	}

	void SetLeft(Node* left) {
		this->left = left;
	}

	void SetRight(Node* right) {
		this->right = right;
	}

	int GetData() {
		return data;
	}

	Node* GetLeft() {
		return left;
	}

	Node* GetRight() {
		return right;
	}
};

class BST {
private:

	Node* root;

public:

	~BST() {
		delete root;
	}

	bool Insert(int data) {
		if (root == NULL) {
			root = new Node(data);

			return true;
		}

		else return bSearchInsert(root, data);
	}

	bool bSearchInsert(Node* p, int data) {
		if (p->GetData() > data) {
			if (p->GetLeft() == NULL) {
				p->SetLeft(new Node(data));

				return true;
			}

			else return bSearchInsert(p->GetLeft(), data);
		}

		else {
			if (p->GetRight() == NULL) {
				p->SetRight(new Node(data));

				return true;
			}

			else return bSearchInsert(p->GetRight(), data);
		}
	}

	Node* Search(int data) {
		return bSearch(this->root, data);
	}

	Node* bSearch(Node* p, int data) {
		if (p == NULL) return NULL;

		if (p->GetData() == data) return p;

		if (p->GetData() > data) return bSearch(p->GetLeft(), data);

		else return bSearch(p->GetRight(), data);
	}

	Node* Min() {
		return MinNode(root);
	}

	Node* MinNode(Node* p) {
		if (p == NULL) return NULL;

		if (p->GetLeft() == NULL) return p;

		return MinNode(p->GetLeft());
	}

	Node* Max() {
		return MaxNode(root);
	}

	Node* MaxNode(Node* p) {
		if (p == NULL) return NULL;

		if (p->GetRight() == NULL) return p;

		return MaxNode(p->GetRight());
	}

	Node* ParentNode(Node* p, Node* dest) {
		Node* left, * right;

		if (p == NULL) return NULL;

		if (p->GetLeft() != NULL) { if (p->GetLeft() == dest) return p; }

		if (p->GetRight() != NULL) { if (p->GetRight() == dest) return p; }

		if (p->GetLeft() == NULL && p->GetRight() == NULL) return NULL;

		left = ParentNode(p->GetLeft(), dest);

		right = ParentNode(p->GetRight(), dest);

		if (left != NULL) return left;

		else if (right != NULL) return right;

		else return NULL;
	}

	bool Delete(int data) {
		Node* max, * p_max, * tmp;

		if (root == NULL) return false;

		if (root->GetData() == data) {
			if (root->GetLeft() != NULL) {
				tmp = root;

				max = MaxNode(root->GetLeft());

				p_max = ParentNode(root, max);

				if (p_max->GetLeft() == max) p_max->SetLeft(max->GetLeft());

				else p_max->SetRight(max->GetLeft());

				max->SetLeft(tmp->GetLeft());

				max->SetRight(tmp->GetRight());

				root = max;

				free(tmp);

				return true;
			}

			else if (root->GetRight() != NULL) {
				tmp = root;

				root = tmp->GetRight();

				free(tmp);

				return true;
			}

			else {
				free(root);

				root = NULL;

				return true;
			}
		}

		else return DeleteNode(root, data);
	}

	bool DeleteNode(Node* p, int data) {
		Node* tmp, * p_tmp, * max, * p_max;

		if ((tmp = bSearch(p, data)) == NULL) return false;

		p_tmp = ParentNode(p, tmp);

		if (tmp->GetLeft() != NULL) {
			max = MaxNode(tmp->GetLeft());

			p_max = ParentNode(p, max);

			if (p_max->GetLeft() == max) p_max->SetLeft(max->GetLeft());

			else p_max->SetRight(max->GetLeft());

			max->SetLeft(tmp->GetLeft());

			max->SetRight(tmp->GetRight());

			if (p_tmp->GetLeft() == tmp) p_tmp->SetLeft(max);

			else p_tmp->SetRight(max);

			free(tmp);

			return true;
		}

		else if (tmp->GetRight() != NULL) {
			if (p_tmp->GetLeft() == tmp) p_tmp->SetLeft(tmp->GetRight());

			else p_tmp->SetRight(tmp->GetRight());

			free(tmp);

			return true;
		}

		else {
			if (p_tmp->GetLeft() == tmp) p_tmp->SetLeft(NULL);

			else p_tmp->SetRight(NULL);

			free(tmp);

			return true;
		}
	}

	bool Change(int data, int dest) {
		if (Search(data) == NULL) return false;

		Insert(dest);

		Delete(data);

		return true;
	}
};

int main() {
	return 0;
}