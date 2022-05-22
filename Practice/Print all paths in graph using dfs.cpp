#include<iostream>
#include<vector>
using namespace std;

vector<int>G[100];

void DFS(int visited[100], int u, int v, vector<int>path){
    visited[u]=1;
    if(u==v){
        for(int i=0; i<path.size(); i++){
            cout<< path[i] << "->";
        }
        cout<< endl;
    }
    else{
        for(int i=0; i<G[u].size(); i++){
            int y = G[u][i];
            if(visited[y]==0){
                visited[y]=1;
                path.push_back(y);
                DFS(visited,y,v,path);
                path.pop_back();
            }
        }
    }
    visited[u]=0;
}

int main(){
    int edges;
    cin>> edges;

   while(edges--){
        int x,y;
        cin>> x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int visited[100]={0};
    vector<int>path;
    int u, v; // source & destination
    cin>>u>> v;
    //Find all possible simple paths from u to v;
    path.push_back(u);

    DFS(visited, u,v,path);
    return 0;
}
