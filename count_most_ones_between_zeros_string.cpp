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
    int len = cppstring.size();
    if(len <= 1)
        return -1;
    int max = 0;
    for (int i = 0; i < len; i++) {
        if (cppstring[i] == '0') {
            int count = strspn(&cppstring[i] + i, "1");
            //cout<<count<<endl;
            if (count > max) {
                max = count;
            }
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
    // cout<<"---------------------count_most_repeated_search_cpp-----------------"<<endl;
    // string cpp_string= "wwleecccommmeee"s;
    // cout<<"the origin:"<<cpp_string<<endl;
    // cout<<"the max count   :"<<count_most_repeated_search_cpp(cpp_string)<<endl;
    // cout<<"---------------------count_most_repeated_map_cpp-----------------"<<endl;
    // string cpp_string2= "wwleecccommmeee"s;
    // cout<<"the origin:"<<cpp_string2<<endl;
    // cout<<"the max count   :"<<count_most_repeated_map_cpp(cpp_string)<<endl;



    return 0;
}