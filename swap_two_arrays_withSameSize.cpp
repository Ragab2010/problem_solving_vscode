#include<iostream>
#include<type_traits>

using namespace std;
//swap two array with same size 

void swap_array(int * a , int * b , int size){
    for (int i = 0; i < size; i++)
    {
        int temp= a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    
}


int main(){
    int a[]={1,2,3,4,5};
    int b[]={6,7,8,9,10};
    cout<<"---------------------before swap-----------------"<<endl;
    cout<<"  a  "<<"   b  "<<endl;
    for(int i = 0;i<(sizeof(a)/sizeof(*a)) ;i++){
    cout<< "  "<< a[i]<<"  " << "  "<< b[i]<<"  "<<endl;
    }
    swap_array(a  , b ,  (sizeof(a)/sizeof(*a)) );
    cout<<"---------------------after swap-----------------"<<endl;
    cout<<"  a  "<<"   b  "<<endl;
    for(int i = 0;i<(sizeof(a)/sizeof(*a)) ;i++){
    cout<< "  "<< a[i]<<"  " << "  "<< b[i]<<"  "<<endl;
    }

    return 0;
}