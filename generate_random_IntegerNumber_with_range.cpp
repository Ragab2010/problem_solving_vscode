#include<iostream>
#include <cstdlib>
#include <ctime>
#include <random>


using namespace std;
void fill_random_c(int *int_array , int size , int min , int max){
    for (int i = 0; i < size; i++){
        int rand_number = (  rand() % (max - min + 1)  ) + min ;
        int_array[i] =rand_number;
    }
    
}
void fill_random_cpp(int *int_array , int size , int min , int max){
    std::random_device rd;
    std::uniform_int_distribution<int> dist( min , max);
    for (int i = 0; i < size; i++){
        
        int_array[i] =dist(rd);
    }
    
}


#define N 15
int main(){
    srand(time(NULL));
    cout<<"---------------------fill_random_c-----------------"<<endl;
    int int_array_c[N];
    cout<<"the Array: ";
    fill_random_c(int_array_c , N , 5 , 10);
    for (int i = 0; i < N; i++){
        cout<<int_array_c[i] <<", ";
    }
    cout<<endl;
    cout<<"---------------------fill_random_cpp-----------------"<<endl;
    int int_array_cpp[N];
    cout<<"the Array: ";
    fill_random_cpp(int_array_cpp , N , 5 , 10);
    for (int i = 0; i < N; i++){
        cout<<int_array_cpp[i] <<", ";
    }
    cout<<endl;
    


    return 0;
}