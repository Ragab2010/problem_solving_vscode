#include<iostream>
#include<cstdio>


using namespace std;

#define CHAR_BITS  8  // size of character
#define INT_BITS  ( sizeof(int) * CHAR_BITS) //bits in integer

void swap_v1(int *a, int *b)
{
    // algo to swap 'a' and 'b'
    *a = *a + *b;  // a becomes 15
    *b = *a - *b;  // b becomes 10
    *a = *a - *b;  // fonally a becomes 5
}

void swap_v2(int *a, int *b)
{
    // algo to swap 'a' and 'b'
    *a = *a ^ *b;  // a becomes (a ^ b)
    *b = *a ^ *b;  // b = (a ^ b ^ b), b becomes a
    *a = *a ^ *b;  // a = (a ^ b ^ a), a becomes b
}


int main(){

    int a = 10 , b= 5;
    cout<<"---------------------swap_v1-----------------"<<endl;
    cout<<"the origin: a ="<<a<<" b="<<b<<endl;
    swap_v1(&a , &b);
    cout<<"after swap_v1: a ="<<a<<" b="<<b<<endl;
    cout<<"---------------------swap_v2-----------------"<<endl;
    swap_v2(&a , &b);
    cout<<"after swap_v2: a ="<<a<<" b="<<b<<endl;
    
    return 0;
}
