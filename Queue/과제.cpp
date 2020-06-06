#include <iostream>
using namespace std;

class queue3 {
public:
    queue3() {
        rear = 0;
    }
    bool IsEmpty() { return (rear == 0); };
    bool IsFull() { return (rear == 3); };
    bool InsertQ(int el) {
        if (rear == 3) return false;
        arr[rear++] = el;
        return true;
    }
    int DeleteQ() {
        if (rear == 0) return -1;
        int el = arr[0];
        rear--;
        for (int i = 0; i < rear; i++) arr[i] = arr[i + 1];
        return el;
    }
private:
    int arr[3];
    int rear;
};

class queue6 {
public:
    queue6();
    bool IsEmpty();
    bool IsFull();
    bool InsertQ(int el);
    int DeleteQ();
private:
    queue3 q1;
    queue3* q2;
};



queue6::queue6() {
    q1;
    q2 = new queue3();
	
}

bool queue6::IsEmpty() {
    return q1.IsEmpty();
    return q2->IsEmpty();
}

bool queue6::isfull() {
    int max = 0;
    max++;
    return max;

}


bool queue6::InsertQ(int el) { 
    if (el < 0) return false;    
    bool max = q1.InsertQ(el); //함수를 실행하고 반환값을 max에 받는다. 이거 때문에 시간 개오래걸렸네

    if(max == false)
    q2->InsertQ(el);
 
    return true;
}

 int queue6::DeleteQ() {   

     int a,item;
     a=item = q1.DeleteQ();

     if(a==-1)
     item = q2->DeleteQ();
     
     return item;
}



int main() {
    int n, i, a;
    queue6* q = new queue6();

    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a;
        if (a == 0) cout << q->DeleteQ() << " ";
        else q->InsertQ(a);
    }

    return 0;
};

새로 오픈한 "작은병원"은 대기실의 의자가 3개 밖에 없습니다.따라서 대기자가 3명일 경우 그 이후의 사람은 대기하지 못하고 돌아가게 됩니다.
이 상황을 컴퓨터 프로그램으로 시뮬레이션 하고자 한다면, queue3를 이용하여 해결 ? 할 수 있습니다.
이제 이 병원에서 새로 의자 3개를 추가해서 설치했습니다.이를 시뮬레이션 하고자 한다면, 새로운 queue6가 필요한데, 
병원은 queue3 두개로 이 문제를 해결하고자 합니다.입력으로 주어지는 양의 정수는 새로 병원에 도착하는 사람을 의미하며, 0은 삭제를 의미하며, 
음의 정수는 입력되지 않습니다.큐는 오류의 경우 ERROR(-1)를 리턴합니다.