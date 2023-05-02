#include<iostream>
#include <cinttypes>


using namespace std;
#define CONVERTENDIAN32BITS(X) ( ( (X & 0XFF) << 24 ) | ( (X & 0XFF00) << 8 ) | ( (X & 0XFF0000) >> 8 ) |( (X & 0XFF000000) >> 24 )   )
#define CONVERTENDIA16BITS(X)  ( ( (X & 0XFF) << 8 ) | ( (X & 0XFF00) >> 8 ))

uint32_t convertEndian32Bits(uint32_t x ){
		union convertendian{
			uint32_t endian32bits ;
			uint8_t endianArr[4];
		}convertEndian;

	convertEndian.endian32bits=x;
	for (int i = 0 , j=3; i < 2; ++i , --j) {
		uint8_t temp  =convertEndian.endianArr[i];
		convertEndian.endianArr[i] = convertEndian.endianArr[j];
		convertEndian.endianArr[j]= temp;
	}
	return convertEndian.endian32bits;


}



int main(){
    cout<<"---------------------CONVERTENDIAN32BITS-----------------"<<endl;
    uint32_t u32CheckData  = 0x11223344;
    uint32_t u32ResultData =0;
    u32ResultData = CONVERTENDIAN32BITS(u32CheckData);
    printf("0x%x\n",u32ResultData);
    u32CheckData = u32ResultData;
    cout<<"---------------------convertEndian32Bits-----------------"<<endl;      
    u32ResultData = convertEndian32Bits(u32CheckData);
    printf("0x%x\n",u32ResultData);



    return 0;
}