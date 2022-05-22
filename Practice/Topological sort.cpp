#include<bits/stdc++.h>
using namespace std;

vector<int>graph[105];
bool visited[105];


vector<int>result;

void dfs(int source){
    visited[source]=1;
    for(int i=0; i<graph[source].size(); i++){
        int next = graph[source][i];
        if(visited[next]==0){
            dfs(next);
        }
    }
    result.push_back(source);
}

int main(){
    int nodes, edges; // 5, 4
//    1 2
//    3 2
//    2 4
//    2 5
    cout<< "Enter the Nodes & Edges: ";
    cin>> nodes>> edges;

    for(int i=0; i<edges; i++){
        int u, v;
        cin>> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
//    int source;
//    cout<< "Enter the Start Source: ";
//    cin>> source;

    //dfs(source);

   /* for(int i=0; i<nodes; i++){
        if(visited[i]==1){
            cout<< "Node "<< i<< " is visited."<< endl;
        }else{
            cout<< "Node "<< i << "is not visited"<< endl;
        }
    }*/

    //for left unvisited nodes, again run dfs
    for(int i=1; i<=nodes; i++){
        if(visited[i]==0){
            //visited[i]=1;
            dfs(i);
        }
    }

    //reverse(result.begin(), result.end());
    cout<< "Topological Order: "<< endl;
    for(int i=0; i< result.size(); i++){
        cout<< result[i]<< "->";
    }
    return 0;
}

