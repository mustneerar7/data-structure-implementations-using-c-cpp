#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define MAX 100

struct node {
    int data;
    node* next;
};

void bfs(node* adj[], int v, int s) {
    std::queue<int> q;
    bool* visited = new bool[v]();

    visited[s] = true;
    q.push(s);

    std::cout << "BFS traversal starting from node " << s << ": ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " ";
        std::vector<int> neighbors;
        for (node* temp = adj[current]; temp != nullptr; temp = temp->next) {
            neighbors.push_back(temp->data);
        }
        std::sort(neighbors.begin(), neighbors.end());

        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << std::endl;

    delete[] visited;
}

void addEdge(node* adj[], int u, int v) {
    node* p = new node{v, adj[u]};
    adj[u] = p;

    node* q = new node{u, adj[v]};
    adj[v] = q;
}

void cleanup(node* adj[], int v) {
    for (int i = 0; i < v; i++) {
        node* temp = adj[i];
        while (temp != nullptr) {
            node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
}

int main() {
    int V = 6;
    node* adj[V] = {nullptr};

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);

    bfs(adj, V, 0);

    cleanup(adj, V);

    return 0;
}
