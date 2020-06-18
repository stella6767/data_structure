#pragma once

class graph {
public:
    graph(int n); // 0~n-1�� ���
    graph(int n, int* m); // 0~n-1�� ���
    ~graph();
    void Visit(int v);
    void AddEdge(int x, int y, int weight);
    void DeleteEdge(int x, int y);
    // void AddNode(); // ��� n�� �߰�
    // void DeleteNode(); // ��� n�� ����
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
    int** am_; //2���� �迭 ������
    int size_;
};
