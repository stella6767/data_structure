#include <iostream>
using namespace std;
// 36*81의 2차원 배열을 이용하여 6*6*9*9의 4차원 배열 구현


class AI4 {
public:
    AI4();
    int GetAt(int p1, int p2, int p3, int p4);
    void SetAt(int p1, int p2, int p3, int p4, int item);
    int arr[36][81];
};

AI4::AI4() {

}

int
AI4::GetAt(int p1, int p2, int p3, int p4) {
    return arr[p1 * 6 + p2][p3 * 9 + p4];
}

void
AI4::SetAt(int p1, int p2, int p3, int p4, int item) {
    arr[p1 * 6 + p2][p3 * 9 + p4] = item;
}

int main() {
    AI4 ai4;
    ai4.SetAt(1, 2, 3, 4, 5);
    cout << ai4.GetAt(1, 2, 3, 4) << endl;
    cout << ai4.GetAt(1, 2, 3, 5) << endl;
}
