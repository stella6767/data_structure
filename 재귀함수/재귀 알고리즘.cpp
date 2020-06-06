#include <iostream>

using namespace std;



int bridge(int n) { //징검다리 건너기: n개의 돌로 구성된 징검다리를 건너려고 한다. 
	//이때, 바로 다음 돌을 밟을 수도 있고, 하나를 건너 뛸 수도 있다. 건널 수 있는 방법은 모두 몇 가지인가?

	if (n == 0) return 1;
	if (n == 1) return 2;

	return bridge(n - 1) + bridge(n - 2);

	int sum = 0;
	sum += bridge(n);

}


//"가능한 경로의 수"를 구하기 : n * m의 격자로 구성된 길이 있다.이중 어떤 길의 일부분들이 막힌 경우 총 가능한 경로의 수는 얼마인가 ?
//하노이(Hanoi) 타워 : 3개의 기둥 중 첫 번째 기둥에 n개의 디스크가 크기순으로(위쪽으로 갈수록 작은 디스크) 놓여있다.
//이 디스크를 한 번에 하나씩 3번째 기둥으로 옮기고자 한다.
//단, 전체 과정에서 위에 있는 디스크는 항상 아래 있는 디스크보다 작아야 한다.최소 몇 번을 이동하여야 모든 디스크를
//3번째 기둥으로 옮길 수 있는가 ? 또, 이때 이동의 순서는 어떻게 되는가 ?












int main() {

	cout << bridge(2);

	return 0;
}