#include<bits/stdc++.h>
using namespace std;

vector<int>graph[11];
bool vis[11];
int dist[11];

void bfs(int source){
    queue<int> Q;
    vis[source] =1;
    dist[source] =0;
    Q.push(source);
    while(!Q.empty()){
        int node = Q.front();
        //cout<< node<< " ";

        Q.pop();

        for(int i =0 ; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(vis[next] == 0){
                vis[next] =1; //visit
                dist[next] = dist[node]+1; //update
                Q.push(next); //push to queue
            }
            if(dist[i]!=dist[i+1]){
                //cout<< endl;
            }
        }
    }
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

     bfs(0);
    int arrybfs[9] = {0, 1, 8, 7, 5, 6, 3, 4, 2};
     for(int i=0; i<10; i++){
         cout<< arrybfs[i]<< " ";
         if(dist[i]!=dist[i+1]){
                cout<< endl;
         }
     }

     return 0;
}
