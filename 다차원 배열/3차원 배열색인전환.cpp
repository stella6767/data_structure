//#include <iostream>
//using namespace std;
//
//class arrInt3 {
//public:
//	arrInt3(int d1, int d2, int d3); //생성자
//	int GetAt(int p1, int p2, int p3); 
//	void SetAt(int p1, int p2, int p3, int v);
//private: 
//	int* arr_;  //1차원 배열을 생성할 포인터
//	int d1_, d2_, d3_; 
//};
//
//
//
//
//arrInt3::arrInt3(int d1, int d2, int d3) { //생성자 함수..?
//
//	arr_ = new int[d1 * d2 * d3 ]; // 면 행 열? 사이즈 동적할당
//	d1_ = d1;  //7  //함수가 끝나면 사라지기 때문에 이 값을 클래스 private 지역변수에 저장
//	d2_ = d2;  //6 
//	d3_ = d3;  //5
//
//	fill(arr_, arr_ + (d1 * d2 * d3),0); //입력되지 않은 셀에 대해서는 0을 출력한다.
//	//배열안의 값들을 0으로 초기화- 이 방법밖에는 못 찾겠음. 다른 하나는 전역변수로 설정하거나, 다른 방안 못 찾겠음
// 
//	
//};
//
//
//void arrInt3::SetAt(int p1, int p2, int p3, int v) {
//	
//
//	if (p1 > d1_ || p2 > d2_ || p3 > d3_ || v<1) //입력의 색인(index)이 배열의 범위를 벗어나거나, 입력값이 0보다 작거나 같으면, 배열에 저장하지 않는다.
//	{          //배열에 저장하지 않는다는 게 무슨 말인지 모르겠고 어떻게 하는지 모르겠음. 그냥 0으로 초기화
//		arr_[p1 * (d2_ * d3_) + p2 * d3_ + p3] = 0;
//	}
//
//	else
//	arr_[p1 * (d2_ * d3_) + p2 * d3_ + p3 ]= v; // x,y,z 번지에 v를 집어넣는 함수
//	//평면=d2*d3 //모든 배열은 사실 1차원 배열
//	// 7*6*5의 삼차원 배열이라 가정 했을시 1면 1행 1열의 위치는 1부터 시작했을시 37번째(arr_[36=v) 0번째 면의 총 개수는 30개이고 0행의 총 개수 6개 0행 다 넘어가면 바로 다음이 
//	//1행 1열, 계산해보니 뭔 말인지는 알겠음.
//
//	
//};
//
//
//int arrInt3::GetAt(int p1, int p2, int p3) { 
//
//	
//
//	if (p1 > d1_ || p2 > d2_ || p3 > d3_) //출력시 범위를 벗어나는 입력에 대해서는 -1출력
//	{
//		return -1;
//	}
//
//
//	else {
//		return arr_[p1 * (d2_ * d3_) + p2 * d3_ + p3];
//	} //p1*(d2*d3)+p2*d3+p3   
//
//};
//
//
//
//
//int main() {
//	int d1, d2, d3;
//	int x, y, z, v;
//
//	cin >> d1 >> d2 >> d3;
//	arrInt3 cube(d1, d2, d3); //cube라는 객체 생성하고 변수 넘기기
//
//	for (int i = 0; i < 3; i++) {
//		cin >> x >> y >> z >> v; //x,y,z 번지에 v를 집어넣어라.....
//		cube.SetAt(x, y, z, v);
//	}
//
//	cin >> x >> y >> z;
//	cout << cube.GetAt(x, y, z) << endl; 
//}
