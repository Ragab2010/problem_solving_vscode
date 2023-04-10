#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void reverse_string_c(char * cstring){
    int len = strlen(cstring);
    if(len <= 1)
        return ;
    int start = 0  , end = len -1;
    while(start <=end){
        char temp = cstring[start];
        cstring[start]= cstring[end];
        cstring[end] = temp ;
        start++;
        end--;
    }

}
void reverse_string_cpp(string & cppstring){
    int len = cppstring.size();
    if(len <= 1)
        return ;
    std::reverse(cppstring.begin() , cppstring.end());


}


int main(){
    cout<<"---------------------reverse_string_c-----------------"<<endl;
    char cstring []="welcome in Egypt";
    cout<<"the origin:"<<cstring<<endl;
    reverse_string_c(cstring);
    cout<<"new_string:"<<cstring<<endl;

    cout<<"---------------------reverse_string_cpp-----------------"<<endl;
    string cppstring="welcome in Egypt";
    cout<<"the origin:"<<cppstring<<endl;
    reverse_string_cpp(cppstring);
    cout<<"new_string:"<<cppstring<<endl;
    // cout<<"---------------------before toggle-----------------"<<endl;
    // toggle_bit(&number , 2);
    // cout<<"---------------------after swap-----------------"<<endl;
    // cout<<std::hex<<"number="<<number<<endl;


    return 0;
}