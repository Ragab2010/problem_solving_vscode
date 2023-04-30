#include<iostream>


using namespace std;

bool check_opposite_sign(int a, int b)
{
    bool bRetValue = 0;
    bRetValue = ((a ^ b) < 0); // true if a and b have opposite signs
    return bRetValue;
}



int main(){

    cout<<"---------------------reverse_bits_c-----------------"<<endl;
    cout<<std::boolalpha << check_opposite_sign(-3 ,3)<<endl;
    cout<<std::boolalpha << check_opposite_sign(3 ,3)<<endl;
    return 0;
}
