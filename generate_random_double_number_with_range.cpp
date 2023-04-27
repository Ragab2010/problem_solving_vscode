#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>


using namespace std;
void fill_random(double *double_array , int size , double min , double max){
    for (int i = 0; i < size; i++){
        double rand_number =  ((double) rand()) / RAND_MAX;
        rand_number =rand_number  * (max - min )  ;
        double_array[i] =rand_number;
    }
    
}
void fill_random_fmod(double *double_array , int size , double min , double max){
    for (int i = 0; i < size; i++){
        double rand_number =  fmod( rand() ,( max - min ) ) ;
        double_array[i] =rand_number;
    }
    
}


#define N 15
int main(){
    srand(time(NULL));
    cout<<"---------------------fill_random-----------------"<<endl;
    double  double_array[N];
    cout<<"the Array: ";
    fill_random(double_array , N , 0.12, 0.75);
    for (int i = 0; i < N; i++){
        cout<<double_array[i] <<", ";
    }
    cout<<endl;
    cout<<"---------------------fill_random_fmod-----------------"<<endl;
    double  double_array_fmod[N];
    cout<<"the Array: ";
    fill_random(double_array_fmod , N , 0.12, 0.75);
    for (int i = 0; i < N; i++){
        cout<<double_array[i] <<", ";
    }
    cout<<endl;
    


    return 0;
}