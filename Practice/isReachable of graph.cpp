#include<bits/stdc++.h>
#include<iostream>
#include<list>
using namespace std;


vector<int>graph[11];
bool vis[11];
int dist[11];


void dfs(int source){
     vis[source]=1;
     for(int i=0; i<graph[source].size(); i++){
        int next = graph[source][i];
        if(vis[next]==0){
            dfs(next);
        }
    }
}

bool bfs_reach(int source, int des){
    if(source == des){
        return true;
    }
    queue<int> Q;
    vis[source] =1;
    dist[source] =0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();

        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(next == des){
                return true;
            }
            if(vis[next] == 0){
                vis[next] =1; //visit
                dist[next] = dist[node]+1; //update
                Q.push(next); //push to queue
            }
        }
    }
    return false;
}

bool is_Reachable(int source, int destination){
    if(source == destination){
        return true;
    }
    queue<int> q;
    vis[source] = 1;
    q.push(source);


    while(!q.empty()){
        int start = q.front();
        q.pop();

        for(int i=0; i<graph[start].size(); i++){
            int next = graph[start][i];
            if(next == destination || vis[i] == 1 ){
                return true;
            }
            if(!vis[i]){
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    return false;
}
int main(){
     graph[0].push_back(1);
     graph[0].push_back(7);
     graph[0].push_back(8);
     graph[1].push_back(8);
     graph[7].push_back(6);
     graph[7].push_back(5);
     graph[6].push_back(5);
     graph[8].push_back(3);
     graph[5].push_back(3);
     graph[5].push_back(4);
     graph[3].push_back(2);
     graph[2].push_back(4);
     graph[2].push_back(8);

     graph[9].push_back(10);
     dfs(0);
    if(is_Reachable(4, 3)){
        cout<< "Reachable"<< endl;
    }
    else{
        cout<< "Not Reachable"<< endl;
    }
     for(int i=0; i<11; i++){
        if(vis[i]==1){
            cout<< "Node "<< i<< " is visited."<< endl;
        }else{
            cout<< "Node "<< i << "is not visited"<< endl;
        }
    }

return 0;
}
