#include<iostream>

//print series 1 , 1 , 2 , 4 , 7 , 13 , 24 , 44 , 81 , 149 , ...

using namespace std;
#define N 10
void print_series(){
    int a[N]={0};
    a[0]=1;
    a[1]=1;
    a[2]=2;
    cout<< a[0] << " , "<<  a[1]<<  " , " << a[2] <<" , ";
    for (int i =3; i < N; i++){
        a[i] =a[i-1] + a[i-2] + a[i-3];
        cout<<a[i] <<" , ";

    }
    cout<<endl;
}


int main(){

    cout<<"---------------------print_series C , Cpp -----------------"<<endl;
    print_series();


    return 0;
}