#include<iostream>
#include<vector>

using namespace std;

vector<int>graph[10];
bool visited[10];
vector<int> starting_time(1);
vector<int> finishing_time(1);

void DFS(int current_node){
    static int timer =0;

    cout<<current_node<<endl;
    for(int i=0; i<graph[current_node].size(); i++){
        int next = graph[current_node][i];
        if(visited[next]==0){
            visited[next]=1;
            timer++;
            starting_time[next] = timer;
            DFS(next);
        }
    }
    timer++;
    finishing_time[current_node] = timer;
}

int main(){
   /*graph[0].push_back(1);
   graph[1].push_back(3);
   graph[1].push_back(4);
   graph[4].push_back(5);
   graph[2].push_back(3);*/

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

//   int starting_node = 0;
//   visited[starting_node] = 1;
//   starting_time[starting_node] = 0;
//   DFS(starting_node);

   for(int i=0;i<9;i++)
    {
        if(visited[i]==0) {
            int starting_node = i;
            visited[starting_node] = 1;
            DFS(starting_node);
        }
    }


   for(int i=0;i<9; i++)
    {
        cout<<i << "->"<<starting_time[i]<< "->"<<finishing_time[i]<<endl;
    }

    return 0;
}
