
#include <iostream>
using namespace std;
#define MAXQ 100
//인접리스트
class queue {
public:
    queue() {
        front_ = 0;
        rear_ = 0;
    };
    bool IsEmpty() { return (rear_ == front_); }
    bool IsFull() { return ((rear_ + 1) % MAXQ == front_); }
    bool InsertQ(int el) {
        if (IsFull()) return false;
        arr_[rear_++] = el;
        rear_ = rear_ % MAXQ;
        return true;
    };
    int DeleteQ() {
        if (IsEmpty()) return -1;
        int el = arr_[front_++];
        front_ = front_ % MAXQ;
        return el;
    };
private:
    int arr_[MAXQ];
    int front_;
    int rear_;
};

class list {
public:
    list(int lsize = 100) {
        LMAX = lsize;
        arr_ = new int[lsize];
        size_ = 0;
    };
    int GetSize() {
        return size_;
    }
    void Insert(int item) {
        int i;
        if (size_ == LMAX) return;
        for (i = size_; 0 < i; i--) {
            if (item < arr_[i - 1]) arr_[i] = arr_[i - 1];
            else break;
        }
        arr_[i] = item;
        size_++;
    };
    void Delete(int value) {
        int i;
        for (i = 0; i < size_; i++) if (value == arr_[i]) break;
        if (i == size_) return;
        size_--;
        for (; i < size_; i++) arr_[i] = arr_[i + 1];
    };
    int GetAt(int position) {
        if (size_ <= position) return -1;
        return arr_[position];
    };
private:
    int LMAX;    // index LMAX;
    int* arr_;    // element * arr_;
    int size_;    // index size_
};

class graph {
public:
    graph(int n);
    graph(int n, int* m);
    ~graph();
    void Visit(int v) {
        cout << "node " << v << " is visited" << endl;
    }
    void AddEdge(int x, int y, int weight);
    void DeleteEdge(int x, int y);
    void Print() {
        for (int i = 0; i < size_; i++) {
            cout << "row " << i << ": ";
            for (int j = 0; j < al_[i]->GetSize(); j++) {
                cout << al_[i]->GetAt(j) << " ";
            }
            cout << endl;
        }
    }
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
    list** al_;
    int size_;
};

// #include "list.h"
// #include "queue.h"
// #include "graph.h"
graph::graph(int n) {
    int i;
    size_ = n;
    al_ = new list * [n];
    for (i = 0; i < n; i++) {
        al_[i] = new list(n);
    }
}

graph::graph(int n, int* m) {
    int i, j, k = 0;
    size_ = n;
    al_ = new list * [n];
    for (i = 0; i < size_; i++) {
        al_[i] = new list(n);
        for (j = 0; j < size_; j++)
            if (m[i * n + j] == 1) al_[i]->Insert(j);
    }
}

graph::~graph() {
    for (int i = 0; i < size_; i++) delete al_[i];
    delete al_;
}

void
graph::AddEdge(int x, int y, int weight = 1) {
    al_[x]->Delete(y);
    al_[x]->Insert(y);
}

void
graph::DeleteEdge(int x, int y) {
    al_[x]->Delete(y);
}

void
graph::bfs(int v) {
    int i, p;
    bool* visited = new bool[size_];
    queue q;
    for (i = 0; i < size_; i++) visited[i] = false;

    visited[v] = true;
    Visit(v);
    q.InsertQ(v);
    while (!q.IsEmpty()) {
        int w = q.DeleteQ();
        for (i = 0; i < al_[w]->GetSize(); i++) {
            p = al_[w]->GetAt(i);
            if (!visited[p]) {
                visited[p] = true;
                Visit(p);
                q.InsertQ(p);
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
    for (int i = 0; i < al_[v]->GetSize(); i++) {
        int p = al_[v]->GetAt(i);
        if (!visited[p]) {
            visited[p] = true;
            Visit(p);
            dfs(visited, p);
        }
    }
}

int main() {
    int gd[16] = { 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1 };
    // graph * g = new graph(4, gd);
    graph g(4, gd);
    g.Print();
    g.bfs(0);
}
