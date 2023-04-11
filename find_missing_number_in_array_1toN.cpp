#include<iostream>


using namespace std;
uint32_t get_missing_number(uint32_t *a , uint32_t size ,uint32_t from , uint32_t to ){
    uint32_t missing_number=0; 
    for (uint32_t i = from; i <= to; i++){
        missing_number ^=i;
    }
    for (uint32_t i = 0; i < size; i++){
        missing_number ^=a[i];
    }
    return missing_number;
}

int main(){

    cout<<"---------------------missing_number C , Cpp -----------------"<<endl;
    uint32_t a[] ={1,2,3,4,5,7,8,9,10}; //missing is 6
    uint32_t mising_number  = get_missing_number(a , sizeof(a)/sizeof(*a) , 1 , 10);
    cout<<"the missing number is:"<<mising_number<<endl;

    return 0;
}