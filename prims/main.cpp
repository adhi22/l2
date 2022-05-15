#include <iostream>
#include <vector>
#include <queue>    // priority queue
#include <utility>  // for pair
#define MAX 100

using namespace std;


int main() {
    int n, m;   // n=nodes, m=edges
    cout << "nodes : "; cin >> n;
    cout << "edges : "; cin >> m;

    vector<pair<int, int>> adj[n];
    
    
    cout << "Enter edgeA, edgeB, weight : \n";
    for(int i=0; i<m; i++) {
        int a, b, wt;
        cin >> a >> b >> wt;
        
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }

    int parent[n];
    int key[n];
    bool mstset[n];

    for(int i = 0; i < n; i++) {
        key[i] = MAX;
        mstset[i] = false;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;

    pq.push({0, 0});

    for(int count=0; count<n-1; count++) {
        int u = pq.top().second;
        pq.pop();

        mstset[u] = true;

        for(auto itr : adj[u]) {
            int v = itr.first;
            int weight = itr.second;

            if(mstset[v] == false && weight < key[v]) {
                parent[v] = u;
                pq.push({key[v], v});
                key[v] = weight;
            }
        }

    }
    
    for(int i=0; i<n; i++) {
        cout << parent[i] << " -> " << i << endl;
    }
   

    return 0;
}