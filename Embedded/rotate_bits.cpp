#include<iostream>
#include <cinttypes>


using namespace std;
#define INT_BITS (sizeof(uint32_t) * 8)

#define ROTATE_LEFT(pos, data) ( (data << pos) | (data >> (INT_BITS - pos)))
#define ROTATE_RIGHT(pos, data) ( (data >> pos) | (data << (INT_BITS - pos)))

int main(){
    uint32_t pos = 2; // Number of rotation
    uint32_t data = 32; //data which will be rotate
    cout<<"---------------------ROTATE_LEFT-----------------"<<endl;
    printf("%u Rotate Left by %u is ", data, pos);
    printf("%u \n", ROTATE_LEFT(pos, data));
    cout<<"---------------------ROTATE_RIGHT-----------------"<<endl;
    printf("%u Rotate Right by %u is ",data, pos);
    printf("%u \n", ROTATE_RIGHT(pos, data));


    return 0;
}