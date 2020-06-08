#include "bst.h"


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
