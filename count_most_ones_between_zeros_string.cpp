#include<iostream>
#include<cstring>
#include<algorithm>




using namespace std;
int count_most_ones_between_zeros_string_c(char * cstring){
    int len= strlen(cstring);
    if(len <=1)
        return -1;
    int max = 0;
    for (int i = 0; i < len; i++){
        if(cstring[i] == '0');
        int count =strspn(cstring +i , "1");
        //cout<<count<<endl;
        if(count > max){
            max = count;
        }
    }
    return max;    
}

int count_most_ones_between_zeros_string_cpp(string cppstring) {
    int count = 0 , max = 0;
    for(char c : cppstring){
        if(c == '1'){
            count++;
        }else{
            if(count > max )
                max = count;
            count=0;
        }
    }
    return max; 
}


int main(){
    cout<<"---------------------count_most_ones_between_zeros_string_c-----------------"<<endl;
    char c_string[]= "01101011111101100000001";
    cout<<"the origin:"<<c_string<<endl;

    cout<<"the max count   :"<<count_most_ones_between_zeros_string_c(c_string)<<endl;
    cout<<"---------------------count_most_ones_between_zeros_string_cpp-----------------"<<endl;
    cout<<"the max count   :"<<count_most_ones_between_zeros_string_cpp(c_string)<<endl;

    return 0;
}