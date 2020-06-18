#include "queue.h"
#include "graph.h"
#include <iostream>
using namespace std;    //���� ��� �׷��� - �׷����� ���� ���踦 ������ �迭�� ��Ÿ���� ��� https://sarah950716.tistory.com/12


graph::graph(int n) {  //���� ���� ���
    size_ = n; //size�� ����
    am_ = new int* [n]; // ������ �迭�� ���� �����Ͱ� �迭�̹Ƿ� ** 2���� �迭 ����
    for (int i = 0; i < n; i++) {
        am_[i] = new int[n];  //��Ȯ�� �� ������ �𸣰ڴ�. �׳� 2���� �迭�� ���� ǥ���̶�� ��������
        for (int j = 0; j < n; j++) am_[i][j] = 0; //�̷� ������ 2���� �迭 ǥ�������ϴ�.
    }
}

graph::graph(int n, int* m) {
    int i, j;
    size_ = n;
    am_ = new int* [n];
    for (i = 0; i < n; i++) {
        am_[i] = new int[n];
        for (j = 0; j < n; j++) am_[i][j] = m[i * n + j];
    }
}

graph::~graph() {
    for (int i = 0; i < size_; i++) delete am_[i]; //������ �迭�� �ϳ��ϳ� ����
    delete am_;
}

void
graph::AddEdge(int x, int y, int weight = 1) { //������ �ϳ� �߰�
    am_[x][y] = weight; //�� 2���� �迭�� 1�� �ִ´ٰ� ��������. weight ���� �� �ϸ� 1
}

void
graph::DeleteEdge(int x, int y) {
    am_[x][y] = 0;
}

void
graph::Visit(int v) {
    cout << "node " << v << " is visited" << endl;
}

void
graph::bfs(int v) {
    int i;
    queue q;
    bool* visited = new bool[size_];
    for (i = 0; i < size_; i++) visited[i] = false;

    visited[v] = true; // call visit(v)
    Visit(v);
    q.InsertQ(v);
    while (!q.IsEmpty()) {
        int w = q.DeleteQ();
        for (i = 0; i < size_; i++) {
            if (!visited[i] && am_[w][i] > 0) {
                visited[i] = true;
                Visit(i);
                q.InsertQ(i);
            }
        }
    }
}

void
graph::dfs(int v) {
    bool* visited = new bool[size_];
    for (int i = 0; i < size_; i++) visited[i] = false;
    visited[v] = true;
    Visit(v);
    dfs(visited, v);
}

void
graph::dfs(bool visited[], int v) {
    for (int i = 0; i < size_; i++) {
        if (!visited[i] && am_[v][i] > 0) {
            visited[i] = true;
            Visit(i);
            dfs(visited, i);
        }
    }
}

int main() {
    int gd[16] = { 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1 }; //2���� �迭�� 1���� �迭 ǥ��, 4*4
    graph g(4, gd); // graph * g = new graph(4, gd);   //������ 4���� ���������� �̷��� ����
    g.dfs(0); // g->dfs(0); //�������� �ƹ��ų� �� �� ����, Ʈ���� ��Ʈ���� Ʈ���� �ƴ� �׷����� ��Ʈ�� �����Ƿ�
    g.bfs(0); // g->bfs(0);
}
