#pragma once

class graph {
public:
    graph(int n); // 0~n-1의 노드
    graph(int n, int* m); // 0~n-1의 노드
    ~graph();
    void Visit(int v);
    void AddEdge(int x, int y, int weight);
    void DeleteEdge(int x, int y);
    // void AddNode(); // 노드 n을 추가
    // void DeleteNode(); // 노드 n을 삭제
    // bool adjacent(int x, int y);
    // list neighbors(int x);
    // int get_node_value(int x);
    // void set_node_value(int x, int v);
    // int get_edge_value(int x, int y);
    // void set_edge_value(int x, int y, int v);
    void bfs(int v);
    void dfs(int v);
protected:
    void dfs(bool visited[], int v);
private:
    int** am_; //2차원 배열 선언방법
    int size_;
};
