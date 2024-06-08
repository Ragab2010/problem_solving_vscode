#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;
bool is_prime(int number){
    if(number <=1)
        return  false;
    for (int i = 2; i < number/2; i++)
    {
        if(number%i == 0 )
            return false;
    }
    return true;
}

bool isPrime(int number){
    if(number <=1)return false;
    for(int i =2 ; i*i <=number ; i++){
        if(number%i == 0) return false;
    }
    return true;

}

int main(){

    cout<<"---------------------is_prime C , Cpp -----------------"<<endl;
    bool stauts  = isPrime(6);
    if(stauts == true)
        cout<<"the number is prime"<<endl;
    else
        cout<<"the number isn't prime"<<endl;

    return 0;
}