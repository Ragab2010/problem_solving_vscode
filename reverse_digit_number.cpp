#include<iostream>
#include<cstring>
#include<algorithm>
#include <bitset>



using namespace std;

int32_t reverse_digit_number_c(int32_t number){
    uint32_t result = 0;
    while(number != 0){
        result =(result* 10) +(number % 10);
        number =number/10;
    }
    return result;
}

int32_t reverse_digit_negative_number_handel_overflow_c(int32_t num){
    int tmp = 0;
    //If num is negative, then convert it to positive
    tmp = (num < 0)? (-1 * num): num;
    int prev_rev_num = 0, rev_num = 0;
    while (tmp != 0)
    {
        int last_digit = tmp%10;
        prev_rev_num = (rev_num*10) + last_digit;
        // checking if the reverse overflowed or not.
        // The values of (rev_num - last_digit)/10 and
        // prev_rev_num must be same if there was no
        // problem.
        if ((prev_rev_num - last_digit)/10 != rev_num)
        {
            //printf("WARNING OVERFLOWED!!!\n");
            cout<<"WARNING OVERFLOWED!!!\n";
            return 0;
        }
        else
        {
            rev_num = prev_rev_num;
        }
        tmp = tmp/10;
    }
    return (num < 0)? -rev_num : rev_num;
}




int main(){

    unsigned int number = 2576980377 ; //16 zero   , 16 one
    cout<<"---------------------reverse_number_c-----------------"<<endl;
    cout<<"sum_digit_number=" << reverse_digit_number_c(12345)<<endl;
    cout<<"---------------------reverse_digit_negative_number_handel_overflow_c-----------------"<<endl;
    cout<<"sum_digit_number=" << reverse_digit_negative_number_handel_overflow_c(12345)<<endl;



    return 0;
}