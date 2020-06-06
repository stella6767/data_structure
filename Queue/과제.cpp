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
    bool max = q1.InsertQ(el); //�Լ��� �����ϰ� ��ȯ���� max�� �޴´�. �̰� ������ �ð� �������ɷȳ�

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

���� ������ "��������"�� ������ ���ڰ� 3�� �ۿ� �����ϴ�.���� ����ڰ� 3���� ��� �� ������ ����� ������� ���ϰ� ���ư��� �˴ϴ�.
�� ��Ȳ�� ��ǻ�� ���α׷����� �ùķ��̼� �ϰ��� �Ѵٸ�, queue3�� �̿��Ͽ� �ذ� ? �� �� �ֽ��ϴ�.
���� �� �������� ���� ���� 3���� �߰��ؼ� ��ġ�߽��ϴ�.�̸� �ùķ��̼� �ϰ��� �Ѵٸ�, ���ο� queue6�� �ʿ��ѵ�, 
������ queue3 �ΰ��� �� ������ �ذ��ϰ��� �մϴ�.�Է����� �־����� ���� ������ ���� ������ �����ϴ� ����� �ǹ��ϸ�, 0�� ������ �ǹ��ϸ�, 
���� ������ �Էµ��� �ʽ��ϴ�.ť�� ������ ��� ERROR(-1)�� �����մϴ�.