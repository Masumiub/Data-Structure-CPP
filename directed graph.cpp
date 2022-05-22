#include <iostream>
#include <vector>
using namespace std;

int main(){
    int total_node, total_edge;
    cin>> total_node>> total_edge;
    vector<int> edges[total_node]; // total noder soman vector create hobe
    int a,b;
    for(int i=0; i<total_edge; i++){
        cin>>a>>b;
        edges[a].push_back(b);

    }
    for(int i=0; i<total_node; i++){
        cout<< "Adjacency list of "<< i<< ": ";
        for(int j=0; j<edges[i].size(); j++){
            cout<< edges[i][j]<< " ";
        }
        cout<< endl;
    }

    int count=0;
    for(int i=0; i<total_node; i++){
            cout<< "outdegree of"<< i<< ":"<< edges[i].size()<< endl;
    }
    int indegree[total_node] = {0};
    for(int i=0; i<total_node; i++){
        for(int j=0; j<edges[i].size(); j++){
            int node = edges[i][j];
            indegree[node]++;
        }

    }

    for(int i=0; i<total_node; i++){
            cout<< "indegree of"<< i<< ":"<< indegree[i]<< endl;
    }
}
