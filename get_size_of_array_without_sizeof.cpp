#include<iostream>


using namespace std;

int main(){
    cout<<"---------------------Method:one-----------------"<<endl;
    int array[] = {10, 20, 30, 40, 50, 60};
    // (&array) is pointer to array
    // (&array+1) here we increment the array by the size of array because array:(*)[6]
    // *(&array+1) here after we get the address after incremention ,
    // we dereference the address to convert it from int (*)[6] to int * , 
    // because:*(&array+1) - array expression has to be the same int *
    int size_of_array = *(&array+1) - array; 
    cout<<"the size of array is :"<<size_of_array<<endl;
    cout<<"---------------------Method:two-----------------"<<endl;
    cout<<"the size of array is :"<<sizeof(array)/sizeof(array[0])<<endl;


    return 0;
}