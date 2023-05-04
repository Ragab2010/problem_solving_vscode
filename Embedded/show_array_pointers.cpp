#include<iostream>
#include<iostream>
#include <cinttypes>


using namespace std;
/*
sizeof int 4byte
int arr[3][3] ;//2D array
-> arr is pointer to int [3]   , so arr+1 increment by 3*sizeof(int)
-&arr is pointer to int [3][3], so &arr+1 increment by 3*3*sizeof(int)
- arr[0] is pointer to int    , so  arr[0]+1 increment by sizeof(int)
->&arr[0] is pointer to int[3] , so &arr[0]+1 increment by 3*sizeof(int)
- arr[0][0] is the [3][3] int element , 
-&arr[0][0] is pointer to [3][3] int element , so &arr[0][0]+1 increment by sizeof(int)
--then arr=&arr[0]  ==>  *arr=arr[0] ==>  **a=*arr[0]=arr[0][0]

int (*ptr_1D)[3];//pointer to 1D array , or pointer to int [3].
--then ptr_1D= arr = &arr[0]

int (*ptr_2D)[3][];//pointer to 2D array , or pointer to int [3][3].
--then ptr_2D= &arr  ==> (*ptr_2D)= arr

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

Assuming the size of the integer is 4 bytes and beginning address of the array is 0.
#include <stdio.h>
int main()
{
  //  Declare 2D array
    int aiData [3][3]= {1};
    printf("%ld\n\n",aiData);
    printf("%ld\n\n",aiData+1);
    return 0;
}
Ans:
0, 12

Q) What is the output of the below program?


Assuming the size of the integer is 4 bytes and beginning address of the array is 0.
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