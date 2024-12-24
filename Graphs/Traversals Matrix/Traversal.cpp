#include <iostream>
#define MAX 100
#include <stack>

void bfs(int adj[MAX][MAX], int v, int s){

    int q[MAX], rear=0, front=0;
    bool visited[MAX]= {false};

    visited[s] = true;
    q[++rear] = s;

    while(front < rear){
        int current = q[front++];
        std::cout << current << " ";

        for(int i=0; i<v; ++i){
            if(adj[current][i] == 1 && !visited[i]){
                visited[i] = true;
                q[rear++] = i;
            }
        }
    }
}

void dfs(int adj[MAX][MAX], int v, int u){
    std::stack<int> s;
    bool visited[MAX] = {false};

    s.push(u);

    while(!s.empty()){
        int current = s.top();
        s.pop();

        if(visited[current]){
            visited[current] = true;
            std::cout << current << " ";
        }

        for(int i=v; i>0; --i){
            if(adj[current][i] == 1 && !visited[i]){
                s.push(i);
                visited[i] = true;
            }
        }
    }
}

void addEdge(int adj[MAX][MAX], int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}


int main()
{
    int adj[MAX][MAX] = {0};
    int V = 5;

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    dfs(adj, V, 0);

    return 0;
}
