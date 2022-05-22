#include <iostream>
#include <vector>
using namespace std;

int main(){
    int total_node=3, total_edge=2;
    //cin>> total_node>> total_edge;
    vector<int> edges[total_node]; // total noder soman vector create hobe
    int a,b;
    for(int i=0; i<total_edge; i++){
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
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
        for(int j=0; j<edges[i].size(); j++){
            count++;
        }
    cout<< count;
    cout<< endl;
    }

}
