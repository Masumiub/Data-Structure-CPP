#include<iostream>
#include<string>
using namespace std;

struct bank_user{
string name;
int account_num;
float current_balance;

void enter_name(){
    string str;
    cout<<"Enter User Name: ";
    getline(cin, str);
    name=str;
}
void enter_account(){
    int num;
    cout<<"Enter Account No. " ;
    cin>> num;
    account_num=num;
}

void diposit(){
    float balance;
    cout<<"Enter Diposit Amount: " ;
    cin>> balance;
    current_balance = balance;
}

void withdraw(){
    float withdraw_amount;
    cout<< "Enter a amount to withdraw:";
    cin>>withdraw_amount;
    if(current_balance<withdraw_amount){
        cout<< "withdraw amount is greater than current_balance!! "<< endl;
    }
    else{
        current_balance = current_balance- withdraw_amount;
    }
}

void display_details(){
    cout<< "Name: "<<name<< endl;
    cout<<"Current Balance: " <<current_balance<< endl;
}


};



int main(){

bank_user user;
char n;

cout<< "Welcome to Bank Management System!"<< endl<< endl;

cout<< "Press- 1. To Enter User Name."<<  endl;
cout<< "Press- 2. To Enter Account No."<<  endl;
cout<< "Press- 3. To Diposit Money."<<endl;
cout<< "Press- 4. To Withdraw Money."<<endl;
cout<< "Press- 5. To Display Current Balance."<<endl;
cout<< "Press- 6. To Exit Program."<<endl;

/*user.enter_name();
user.diposit();
user.display_details();*/

do{
cin>> n;
cin.ignore();
switch(n){
    case '1':
        user.enter_name();
        break;
    case '2':
        user.enter_account();
        break;
    case '3':
        user.diposit();
         break;
    case '4':
        user.withdraw();
        break;
    case '5':
        user.display_details();
        break;
    case '6':
        cout<< "Thank you!"<< endl;
        break;

}

}while(n!=6);

return 0;
}
