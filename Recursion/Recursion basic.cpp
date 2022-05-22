#include<iostream>

using namespace std;

/*void hi(int i){
    if(i==3){
    return;
    }
    i++;
    cout<< "hi"<< endl;
    hi(i);

}*/

void hi(int i){
/*if(i<0){
    return;
    }
    i--;
    cout<< "hi"<< endl;
    hi(i);*/

    if(i==0){
    return;
    }
    cout<< "hi"<< endl;
    i--;
    hi(i);


}

int main(){
int i =3;
hi(i);

return 0;
}
