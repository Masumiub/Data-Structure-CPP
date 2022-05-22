#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>graph[10];
int dist[10];
bool vist[10];

void DFS(int source){
    vist[source]=1;
    cout<< source<< endl;
    for(int i=0; i<graph[source].size(); i++){
        int next = graph[source][i];
        if(vist[next]==0){
            DFS(next);
        }
    }
}

void BFS(int source){
    queue<int>q;
    vist[source] = 1;
    dist[source] = 0;
    q.push(source);

    while(!q.empty()){
        int node = q.front();
        cout<< node<< "->";
        q.pop();
        for(int i =0; i<graph[node].size(); i++){
            int next = graph[node][i];
            if(vist[next] ==0){
                vist[next] = 1;
                dist[next] = dist[node]+1;
                q.push(next);
            }
        }
    }
}

int main(){
    string countries[10] = {"Greenland", "China", "India", "Pakistan", "Iran", "Bangladesh", "Turkey", "USA", "Canada", "Thailand"};
    for(int i=0; i<10; i++){
        //cout<< countries[i]<< "->";
    }

   /* graph[2].push_back(1);
    graph[5].push_back(10);
    graph[3].push_back(2);
    graph[7].push_back(8);
    graph[6].push_back(4);
    graph[3].push_back(4);
    graph[3].push_back(6);
    graph[5].push_back(2);*/

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

    //BFS(0);
    DFS(0);
    cout<< "From node "<< 2 << endl;
    for(int i=0; i<10; i++){
        cout<< "Distance of"<< i<< "is: "<< dist[i]<< endl;
    }
    return 0;
}
