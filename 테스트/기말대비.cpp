#include <iostream>

using namespace std;

//class stack {
//public:
//	stack(int s = 100) {
//		size = s; storage = new int[s]; top = 0;
//	}
//	bool push(int el);
//	int pop();
//
//private:
//	int* storage;
//	int size;
//	int top;
//};
//
//
//bool stack::push(int el) {
//
//	storage[top++] = el;
//	return true;
//};
//
//
//int stack::pop() {
//
//	return storage[top - 1];
//};
//
//
//
//int main() {
//
//
//
//	return 0;
//}


//
//
//class arrInt2 {
//public:
//	arrInt2(); //1X100
//	int GetAt(int p1, int p2);
//	void SetAt(int p1, int p2, int item);
//private:
//	int arr_[100];
//	// int * arr_;
//};
//
//arrInt2::arrInt2() {
//	// arr_ = (int *) malloc(sizeof(int)* 100);};
//};
//
//int arrInt2::GetAt(int p1, int p2) {
//	return arr_[p1 * 10 + p2];
//	// return *(arr_+(p1*10+p2));
//};
//
//void arrInt2::SetAt(int p1, int p2, int item) {
//	arr_[p1 * 10 + p2] = item;
//	// *(arr_+(p1*10+p2)) = item;
//};
//
//class AI2 { // arrInt2 양의 정수만을 저장함을 가정
//public:
//	AI2();
//	int GetAt(int p1, int p2);
//	void SetAt(int p1, int p2, int item);
//	void PlusTwo(); // 모든 저장된 원소 값에 +2
//	int FindMax();
//	void transpose()
//	{
//		int i, j;
//		for (i = 0; i < 7; i++)
//			for (j = 0; j < 11; j++)
//				SetAt(j, i, i * 100 + j);
//	};
//private:
//	int arr_[77];
//};
//
//AI2::AI2() {
//};
//
//int AI2::GetAt(int p1, int p2) {
//	return arr_[p1 * 11 + p2];
//	// return *(arr_+(p1*10+p2));
//};
//
//void AI2::SetAt(int p1, int p2, int item) {
//	arr_[p1 * 11 + p2] = item;
//	// *(arr_+(p1*10+p2)) = item;
//};
//
//void AI2::PlusTwo() {
//	for (int i = 0; i < 77; i++)
//		arr_[i] = arr_[i] + 2;
//};
//
//int AI2::FindMax() {
//	int max = arr_[0];
//	for (int i = 0; i < 77; i++)
//		if (arr_[i] >= max) max = arr_[i];
//
//	return max;
//};
//
//
//class SAI { //크기선언이 가능한 1차원 배열
//public:
//	SAI(int d1, int max);
//	int GetAt(int p1);
//	void SetAt(int p1, int item);
//	int GetMax();
//private:
//	int* arr_;
//	int d1_, max_, size_;
//};
//
//SAI::SAI(int d1, int max) {
//	arr_ = new int[max * 2]; //하나를 저장할때마다 2칸이 필요
//	d1_ = d1;
//	max_ = max;
//	size_ = 0;
//};
//
//int SAI::GetAt(int p1) {
//	for (int i = 0; i < size_; i++) {
//		if ((arr_[i * 2] == p1)) return arr_[i * 2 + 1];
//	}
//	return 0; // ERROR은 미리 선언된 오류를 나타내는 정수
//};
//
//
//void SAI::SetAt(int p1, int item) {
//	if (size_ == max_) // 오류처리 필요
//	arr_[size_ * 2] = p1;
//	arr_[size_ * 2 + 1] = item;
//	size_++;
//};
//
//int SAI::GetMax() {
//	int max = arr_[0];
//	for (int i = 0; i <= size_*2+1; i++)
//		if (arr_[i] >= max) max = arr_[i];
//
//	return max;
//};
//
//int main() {
//	AI2 arr; // arrInt arr;
//	for (int i = 0; i < 7; i++) for (int j = 0; j < 11; j++) arr.SetAt(i, j, i * 100 + j);        // arr[i][j] = i*100+j;
//	for (int i = 0; i < 7; i++)for (int j = 0; j < 11; j++) cout << arr.GetAt(i, j)<<endl;  // cout << arr[i][j];
//	arr.PlusTwo();
//	for (int i = 0; i < 7; i++)for (int j = 0; j < 11; j++) cout << arr.GetAt(i, j) << endl;  // cout << arr[i][j];
//	
//	cout << "max 값 : "<<arr.FindMax();
//
//	SAI arr2(10,10);
//	arr2.SetAt(1, 3);
//	arr2.SetAt(2, 5);
//	cout<<arr2.GetMax();
//
//
//}
//

class Stack10 {
public:
	Stack10() {
		storage = new int[10];
		top = 0;
	}
	bool IsFull();
	bool IsEmpty();
	bool Push(int el); // 성공 true, 실패 false 리턴
	int Pop(); // 오류 시 0 리턴
private:
	int* storage;
	int top;
	int size;
};

class Stack200 {
public:
	Stack200() {
		s = new Stack10();

	};
	bool push(int el) {
		//if (IsFull()) return false;
		for(int i=0; i<20; i++)
		s[i]->Push(el);
		return true;
	};

	int Pop() { // 오류 시 0 리턴
		if (IsEmpty()) return 0;
		for (int i = 0; i < 20; i++)
			return s[i]->Pop();
	};
private:
	Stack10* s[20];
};