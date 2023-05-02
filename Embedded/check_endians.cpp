#include<iostream>
#include <cinttypes>


using namespace std;

typedef union
{
    uint32_t u32RawData;  // integer variable
    uint8_t  au8DataBuff[4]; //array of character
} RawData;
void check_endians_v1(){
    RawData uCheckEndianess;
    uCheckEndianess.u32RawData = 0x11223344; //assign the value
    if(uCheckEndianess.au8DataBuff[0]== 0x44){
        cout<<"little-endian\n"<<endl;
    }else{
        cout<<"big-endian\n\n"<<endl;
    }
}

void check_endians_v2(){
    uint32_t u32RawData;
    uint8_t *pu8CheckData;
    u32RawData = 0x11223344; //Assign data
    pu8CheckData = (uint8_t *)&u32RawData; //Type cast
    if (*pu8CheckData == 0x44) //check the value of lower address
    {
        printf("little-endian\n");
    }
    else if (*pu8CheckData == 0x11) //check the value of lower address
    {
        printf("big-endian\n");
    }
}

int main(){
    cout<<"---------------------check_endians_v1-----------------"<<endl;
    check_endians_v1();
    cout<<"---------------------check_endians_v2-----------------"<<endl;
    check_endians_v2();



    return 0;
}