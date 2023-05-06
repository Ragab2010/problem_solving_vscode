#include<iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>


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
void fill_random_cpp(double *double_array , int size , double min , double max){
    std::random_device rd;
    std::uniform_real_distribution<double> dist( min , max);
    for (int i = 0; i < size; i++){
        
        double_array[i] =dist(rd);
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
    cout<<"---------------------fill_random_fmod-----------------"<<endl;
    double  double_array_cpp[N];
    cout<<"the Array: ";
    fill_random_cpp(double_array_cpp , N , 0.12, 0.75);
    for (int i = 0; i < N; i++){
        cout<<double_array_cpp[i] <<", ";
    }
    cout<<endl;


    return 0;
}