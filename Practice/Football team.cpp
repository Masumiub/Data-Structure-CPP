#include<iostream>
#include<string>
using namespace std;

struct Team{
    int team_num;
    int player_id[10];
    int total_goals;


    void goal_player_id(){
        int sum=0;
        for(int i=0; i<10; i++){
            cout<< "Player No. "<< (i+1)<< " scored ";
            cin>>player_id[i];
            sum +=player_id[i];
        }
        total_goals=sum;
    }

    int goals_by_team(){
        cout<< total_goals;
        return total_goals;
    }
};

int main(){

Team **t=new Team*[1];
for(int i=0; i<1; i++){
        t[i] = new Team[2];
}

for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 2; j++) {
            cout<< "Team Number: ";
            cin>> t[i][j].team_num;
            t[i][j].goal_player_id();
        }
    }

int team_one_goals;
int team_two_goals;

cout<<"Total goals of ";
cout<<"Team No."<< t[0][0].team_num<<":";
team_one_goals=t[0][0].goals_by_team();
cout<< endl;

cout<<"Total goals of ";
cout<<"Team No."<< t[0][1].team_num<<":";
team_two_goals=t[0][1].goals_by_team();
cout<< endl;


if(team_one_goals>team_two_goals){
    cout<<"Team-1 is winner!"<< endl;
}else{
    cout<<"Team-2 is winner!"<< endl;
}
return 0;
}
