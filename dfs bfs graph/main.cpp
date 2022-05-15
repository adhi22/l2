#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> visited(100, false);
vector<vector<int>> edges(100); 

void addEdge(int a, int b) {
    edges[a].push_back(b);
    edges[b].push_back(a);
}

void DFS(int index) {
    if(visited[index]) return;
    
    visited[index] = true;
    cout << index << " ";
    for(auto i : edges[index]) {
        if(!visited[i]) DFS(i);
    }
}

void BFS(int index) {
    vector<bool> visited(100, false);
    
    queue<int> q;
    q.push(index);
    visited[index] = true;

    while (!q.empty()) {
        int el = q.front();
        q.pop();
        cout << el << " ";
        for(auto i : edges[el]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        } 
    }
    
}

int main() {
    cout << "Helo";
    
    addEdge(12, 5);
    addEdge(5, 13);
    addEdge(13, 25);
    addEdge(12, 23);
    addEdge(23, 25);
    addEdge(12, 3);
    addEdge(3, 15);
    addEdge(15, 25);

    cout << "\nDFS : \n";
    DFS(12);

    cout << "\nBFS : \n";
    BFS(12);

    return 0;
}




// #include <iostream>
// #include <vector>
// #include <queue>

// using namespace std;
// vector<vector<int>> g(100);
// vector<bool> vis(100,0);
// void dfs(int cur)
// {
//     if(vis[cur]==1)
//         return;
//     vis[cur] = 1;
//     cout << cur << " ";
//     for (auto i : g[cur])
//     {
//         if(!vis[i]){
//             dfs(i);
//         }
//     }
// }

// void bfs(int cur){
//     queue<int> q;
//     q.push(cur);
//     vis[cur] = 1;
//     while(!q.empty()){
//         int ele = q.front();
//         q.pop();
//         cout << ele << " ";
//         for(auto i :g[ele]){
//             if(!vis[i]){
//                 q.push(i);
//                 vis[i] = 1;
//             }
//         }
//     }
// }

// signed main()
// {
//     cout << "______________________________________________________\n";
//     cout << "Enter the number of nodes:- ";
//     int nodes;
//     cin >> nodes;
//     cout << "Enter the number of edges:- ";
//     int edges;
//     cin >> edges;
    
//     cout << "Enter " << edges << " edges:- \n";
//     for (int i = 1; i <= edges;i++){
//         int u, v;
//         cout << "Enter the " << i << " edge:- \n";
//         cout << "u:- ";
//         cin >> u;
//         cout << "v:- ";
//         cin >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     int start,c;
//     cout << "Enter the starting node:- ";
//     cin >> start;
//     cout << "______________________________________________________\n";
//     while(1){
//         for (int i = 0; i < 100;i++)
//             vis[i] = 0;
//         cout << "MENU :-\n";
//         cout << "1- DFS \n";
//         cout << "2- BFS\n";
//         cout << "0- EXIT\n";
//         cin >> c;
//         if (c == 1)
//         {
//             cout << "DFS Traversal:- \n";
//             dfs(start);
//         }
//         else if(c==2){
//             cout << "BFS Traversal:- \n";
//             bfs(start);
//         }
//         else if(c==0){
//             cout << "Exit Successfully :) \n";
//             break;
//         }
//         else{
//             cout << "Please Enter correct choise\n";
//         }
//         cout << "\n______________________________________________________\n";
//     }
//     return 0;
// }