#include "queue.h"
#include "graph.h"
#include <iostream>
using namespace std;    //인접 행렬 그래프 - 그래프의 연결 관계를 이차원 배열로 나타내는 방식 https://sarah950716.tistory.com/12


graph::graph(int n) {  //값만 들어올 경우
    size_ = n; //size를 정함
    am_ = new int* [n]; // 포인터 배열을 선언 포인터가 배열이므로 ** 2차원 배열 선언
    for (int i = 0; i < n; i++) {
        am_[i] = new int[n];  //정확히 뭔 말인지 모르겠다. 그냥 2차원 배열의 동적 표현이라고 생각하자
        for (int j = 0; j < n; j++) am_[i][j] = 0; //이런 식으로 2차원 배열 표현가능하다.
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
    for (int i = 0; i < size_; i++) delete am_[i]; //포인터 배열을 하나하나 삭제
    delete am_;
}

void
graph::AddEdge(int x, int y, int weight = 1) { //간선을 하나 추가
    am_[x][y] = weight; //걍 2차원 배열에 1을 넣는다고 생각하자. weight 지정 안 하면 1
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
    int gd[16] = { 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1 }; //2차원 배열의 1차원 배열 표현, 4*4
    graph g(4, gd); // graph * g = new graph(4, gd);   //정점이 4개가 간선정보는 이렇게 생김
    g.dfs(0); // g->dfs(0); //시작점은 아무거나 줄 수 있음, 트리는 루트지만 트리가 아닌 그래프는 루트가 없으므로
    g.bfs(0); // g->bfs(0);
}
