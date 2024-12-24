#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* next;
};

void addEdge(Node* adj[], int u, int v) {

    Node* newNode = new Node{v, adj[u]};
    adj[u] = newNode;

    newNode = new Node{u, adj[v]};
    adj[v] = newNode;
}

void dfs(Node* adj[], int v, int s) {
    std::stack<int> stack;
    bool* visited = new bool[v]();

    stack.push(s);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        if (!visited[current]) {
            visited[current] = true;
            std::cout << current << " ";
        }

        for (Node* temp = adj[current]; temp != nullptr; temp = temp->next) {
            if (!visited[temp->data]) {
                stack.push(temp->data);
            }
        }
    }

    delete[] visited;
}

int main() {
    int V = 5;
    Node* adj[V] = {nullptr};

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    dfs(adj, V, 0);

    for (int i = 0; i < V; ++i) {
        Node* current = adj[i];
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    return 0;
}
