#include<iostream>
#include<cstdio>


using namespace std;

#define CHAR_BITS  8  // size of character
#define INT_BITS  ( sizeof(int) * CHAR_BITS) //bits in integer
void print_in_binary(unsigned n)
{
    char Pos = (INT_BITS -1);
    for (; Pos >= 0 ; --Pos)
    {
        (n & (1ul << Pos))? printf("1"): printf("0");
    }
    printf("\n");
}



int main(){

    cout<<"---------------------print_in_binary-----------------"<<endl;
    print_in_binary(255);
    return 0;
}
