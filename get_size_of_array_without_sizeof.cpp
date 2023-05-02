#include<iostream>


using namespace std;

int main(){
    cout<<"---------------------Method:one-----------------"<<endl;
    int array[] = {10, 20, 30, 40, 50, 60};
    // (&array) is pointer to array 
    //*(&array) is pointer to int , because * with discard &
    // *(&array+1)  with increament by size of array , and dereferance the address of the last element
    int size_of_array = *(&array+1) - array; 
    cout<<"the size of array is :"<<size_of_array<<endl;
    cout<<"---------------------Method:two-----------------"<<endl;
    cout<<"the size of array is :"<<sizeof(array)/sizeof(array[0])<<endl;


    return 0;
}