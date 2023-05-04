#include<iostream>
#include<iostream>
#include <cinttypes>


using namespace std;
/*

Assuming the size of the integer is 4 bytes and the beginning address of the array is 0.
#include <stdio.h>
int main( void )
{
    //Declare 2D array
    int aiData [3][3]= {1};
    printf("%u\n\n",*aiData);
    printf("%u\n\n",*aiData+1);
    return 0;
}
Ans:
0, 4


Q) What is the output of the below program?

//Assuming the size of the integer is 4 bytes and beginning address of the array is 0.
#include <stdio.h>
int main()
{
    //Declare 2D array
    int aiData [3][3]= {1};
    printf("%ld\n\n",aiData);
    printf("%ld\n\n",aiData+1);
    return 0;
}
Ans:
0, 12

Q) What is the output of the below program?


//Assuming the size of the integer is 4 bytes and beginning address of the array is 0.
#include <stdio.h>
int main()
{
    //Declare 2D array
    int aiData [3][3]= {1};
    printf("%ld\n\n",&aiData);
    printf("%ld\n\n",&aiData+1);
    return 0;
}
Ans:
0, 36


*/
//Assuming the size of the integer is 4 bytes and the beginning address of the array is 0.
int main(){
    //Declare 2D array
    int aiData [3][3]= {1};
    cout<<"---------------------*aiData , *aiData+1----------------"<<endl;
    printf("%p\n\n",*aiData); 
    printf("%p\n\n",*aiData+1);
    //ouput: 0 , 4
    cout<<"---------------------aiData , aiData+1----------------"<<endl;
    printf("%p\n\n",aiData);
    printf("%p\n\n",aiData+1);
    //ouput: 0 , 12
    cout<<"---------------------&aiData , &aiData+1-----------------"<<endl;
    printf("%pn\n",&aiData);
    printf("%p\n\n",&aiData+1);
    //ouput: 0 , 36




    return 0;
}