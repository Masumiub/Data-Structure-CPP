#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>graph[11];
bool visited[11];
int dist[11];
//int parent[11];

bool bfs(int source, int des){
    queue<int> Q;
    visited[source] = 1;
    dist[source] =0;
    Q.push(source);

    while(!Q.empty()){
        int node = Q.front();
        Q.pop();
        for(int i=0; i<graph[node].size(); i++){
            int neighbour = graph[node][i];

            if(visited[neighbour] == 0){
                visited[neighbour] =1;
                dist[neighbour] = dist[node] + 1;
                Q.push(neighbour);

                if(neighbour == des){
                    return true;
                }
            }
        }
    }
    return false;
}

void print_least_dist(int source, int des){
    if(bfs(source,des) == false){
        cout<< "Given source & destination are not connected"<< endl;
        return;
    }
    int parent[11];
    for(int i=0; i<=11; i++){
        parent[i] = -1;
    }
    //vector path stores the shortest path
    vector<int>path;
    int crawl = des;
    path.push_back(crawl);
    while(parent[crawl]!=-1){
        path.push_back(parent[crawl]);
        crawl = parent[crawl];
    }
    // distance from source is in distance array
    cout<< "Shortest path length is: "<< dist[des]<< endl;

    //printing the path
    cout<< "Shortest path is: ";
    for(int i =0 ; i<path.size(); i++){
        cout<< path[i]<< "->";
    }
}
int main ()
{
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

     print_least_dist(0, 5);

     return 0;
}
