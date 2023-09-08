#include<iostream>
#include<cstring>
#include<cctype>
#include<algorithm>

#define NUM_CHAR 128U


using namespace std;
int nonrepeating_character_string_c(char *cstring){
    if(cstring== nullptr)
        return -1;
    int len  = strlen(cstring);
    char freq_char[NUM_CHAR]={0};
    for (int i = 0; i < len; i++){
        if( isalpha(cstring[i]) ){
            freq_char[cstring[i]]++;
        }
    }
    for (int i = 0; i < len; i++){
        if( isalpha(cstring[i]) ){
            if(freq_char[cstring[i]]  == 1){
                return i;
            }
        }

    }
    return -1;
}


int main(){

    cout<<"---------------------nonrepeating_character_string_c-----------------"<<endl;
    char cstring[]= "hello world hi hey";
    cout<<"the origin:"<<cstring<<endl;
    int index = nonrepeating_character_string_c(cstring);
    if(index == -1){
        cout<<"there no nonrepeating_character" <<endl;
    }else{
        cout<<"nonrepeating_character is:"<<cstring[index]<<endl;
    }

    return 0;
}