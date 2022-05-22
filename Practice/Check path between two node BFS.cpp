#include<bits/stdc++.h>
using namespace std;

//vector<int>graph[4];
list<int>*graph = new list<int>[4];

bool vis[4];
int dist[4];

bool check_path(int source, int des){
    if(source == des) return true;
    list<int> Q;
    vis[source] =1;
    Q.push_back(source);
    list<int>::iterator i;
    while(!Q.empty()){
        int node = Q.front();
        Q.pop_front();
        for(i=graph[source].begin(); i!=graph[source].end(); i++){
            //int next = graph[source][i];

            if(*i == des) {
                return true;
            }

            if(!vis[*i]){
                vis[*i] =1;
                Q.push_back(*i);
            }
        }
    }

    return false;
}
int main(){
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);
    cout<<check_path(2,0);
    /*if(check_path(1,3)){
        cout<< "True";
    }
    else{
        cout<< "False";
    }*/
    return 0;
}
