#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>

#define NUM_CHAR 256U


using namespace std;
bool distinct_characters_string_c(char *cstring){
    if(cstring== nullptr)
        return -1;
    int len  = strlen(cstring);

    char freq_char[NUM_CHAR]={0};
    int distinct_count=0;
    for (int i = 0; i < len; i++){
        if( !isspace(cstring[i]) ){
            if(freq_char[cstring[i]] == 0){
                distinct_count++;
                freq_char[cstring[i]]++;
            }
        }
        if(distinct_count >= 10)
            return true;
    }

    return false;
}


int main(){

    cout<<"---------------------distinct_characters_string_c-----------------"<<endl;
    char cstring[]= "12334bbmma:=6";
    cout<<"the origin:"<<cstring;
    cout<<" is :"<<std::boolalpha<<distinct_characters_string_c(cstring)<<endl;
    cout<<endl;
    char cstring2[]= "eeeemmmmmmmmm1000";
    cout<<"the origin:"<<cstring;
    cout<<" is :"<<std::boolalpha<<distinct_characters_string_c(cstring2)<<endl;
    cout<<endl;


    return 0;
}