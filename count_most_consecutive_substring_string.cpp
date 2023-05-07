#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>



using namespace std;

int count_most_consecutive_substring_c(char * cstring){
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int max=0;
    int l = 0 , h =1 , count=0;
    while(l<len && h<len){
        if(cstring[l] < cstring[h]){
            l++;
            h++;
            count++;
        }else{
            if(count>max){
                max=count;
            }
            count=0;
            l++;
            h++;
        }
    }
    return max+1;
}

int count_most_consecutive_substring_v2_c(char * cstring){
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int max=0;
    int l = 0 , h =1 , count=0;
    for (int i = 0; i < len;){
        int index = i;
        int count =0;
        while((cstring[index] < cstring[index+1]) && (index<len-1)){
            count++;
            index++;
        }
        if(count > max){
            max = count;
        }
        i = index+1;
    }
    
    return max+1;
}



int main(){

    cout<<"---------------------count_most_consecutive_substring_c-----------------"<<endl;
    char c_string[]= "abcabcdefabc";
    cout<<"the origin:"<<c_string<<endl;

    cout<<"the max count   :"<<count_most_consecutive_substring_c(c_string)<<endl;

    cout<<"---------------------count_most_consecutive_duplicates_slidingwindow_v2_c-----------------"<<endl;
    char c_string2[]= "abcabcdefabc";
    cout<<"the origin:"<<c_string2<<endl;
    cout<<"the max count   :"<<count_most_consecutive_substring_v2_c(c_string2)<<endl;



    return 0;
}