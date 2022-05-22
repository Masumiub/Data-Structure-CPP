#include<iostream>
using namespace std;

int  main(){

double a[100];
double sum=0;
double avg=0;
int n;
cout<< "How many Marks you want to store?"<<endl;
cin>> n;
for(int i=0; i<n; i++){
    cin>>a[i];
    sum+=a[i];
}
int i;
for( i=0; i<n; i++){
    cout<<"Roll="<<(i+1)<<" =" <<a[i]<< endl;
}

for(i=0; i<n; i++){
   if(a[0]<a[i])
        {a[0]=a[i];}
}
double tmp=a[0];
for(i=0; i<n; i++){
   if(tmp>a[i])
        {tmp=a[i];}
}
int delete_roll;
cin>>delete_roll;
for(i=delete_roll; i<n-1; i++){
   a[i]=a[i+1];
}
for(i=0; i<n; i++){
    cout<<"Roll="<<(i+1)<<" =" <<a[i]<< endl;
}

//cout<< "Sum of Marks:"<< sum<< endl;
//cout<< "Average of Marks:"<<sum/n<< endl;;
//cout<< "Highest Mark:"<< a[0]<< endl;
//cout<< "Lowest Mark:"<< tmp;
}
