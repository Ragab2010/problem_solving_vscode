#include<iostream>
#include <cstdlib>
#include <ctime>


using namespace std;
void fill_random(int *int_array , int size , int min , int max){
    for (int i = 0; i < size; i++){
        int rand_number = (  rand() % (max - min + 1)  ) + min ;
        int_array[i] =rand_number;
    }
    
}


#define N 15
int main(){
    srand(time(NULL));
    cout<<"---------------------fill_random-----------------"<<endl;
    int int_array[N];
    cout<<"the Array: ";
    fill_random(int_array , N , 5 , 10);
    for (int i = 0; i < N; i++){
        cout<<int_array[i] <<", ";
    }
    cout<<endl;
    


    return 0;
}