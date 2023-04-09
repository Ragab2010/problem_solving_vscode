#include<iostream>


using namespace std;

void toggle_bit(int * a , int  b){
    *a ^=(1<<b-1);
}


int main(){
    int number= 0xf0;
    cout<<"---------------------before toggle-----------------"<<endl;
    cout<<std::hex<<"number="<<number<<endl;
    toggle_bit(&number , 2);
    cout<<"---------------------after swap-----------------"<<endl;
    cout<<std::hex<<"number="<<number<<endl;


    return 0;
}