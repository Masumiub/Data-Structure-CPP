#include<bits/stdc++.h>
using namespace std;

#define MX 110
vector<int>graph[MX];
bool vis[MX];
int dist[MX];

void getDepth(int source){
    queue<int>Q;
    vis[source] = 1;
    dist[source] = 0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.front();
        cout<< node<< endl; //level wise print
        Q.pop();

        for(int i=0; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(vis[next] == 0){
                vis[next] =1; //visit
                dist[next] = dist[node]+1; //update
                Q.push(next); //push to queue
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

     getDepth(0);

     int depth=0;
     int lagrest = dist[0];
     for(int i=0; i<9; i++){
        if(lagrest<dist[i]){
            lagrest = dist[i];
        }
        //cout<< "Distance of"<< i<< "is: "<< dist[i]<< endl;
     }
    cout<< "Depth of the Graph: "<< lagrest<< endl;
     //cout<< "The depth of the Graph: "<< depth<< endl;
     return 0;
}
