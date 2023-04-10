#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void reverse_word_c(char * cstring , int start , int end){
    int len = strlen(cstring);
    if(len <= 1)
        return ;
    while(start <=end){
        char temp = cstring[start];
        cstring[start]= cstring[end];
        cstring[end] = temp ;
        start++;
        end--;
    }

}
void reverse_string_v2_c(char * cstring){
    int len = strlen(cstring);
    if(len <= 1)
        return ;
    int start = 0  , end = len -1;
    reverse_word_c(cstring , start , end);
    while(start <len){
        int end_word = start + strcspn(cstring + start , " ");
        reverse_word_c(cstring, start, end_word - 1);
        start = end_word + 1;
    }
}
void reverse_string_c(char * cstring){
    int len = strlen(cstring);
    if(len <= 1)
        return ;
    int start = 0  , end = len -1;
    reverse_word_c(cstring , start , end);
    while(start <len){
        int end_word = start;
        while(cstring[end_word] != ' ' && end_word <len){
            end_word++;
        }
        reverse_word_c(cstring, start, end_word - 1);
        start = end_word + 1;
    }
}

void reverse_string_cpp(string & cppstring){
    int len = cppstring.size();
    if(len <= 1)
        return ;
    //std::reverse(cppstring.begin() , cppstring.end()); 
    int start = 0 , end = len -1;
    reverse_word_c(&cppstring[0] , start , end);
    while (start < len) {
        int end_word = cppstring.find(" ", start);
        if (end_word == string::npos) {
            end_word = len;
        }
        reverse_word_c(&cppstring[0], start, end_word - 1);
        start = end_word + 1;
    }
}
void reverse_string_v2_cpp(string & cppstring){
    int len = cppstring.size();
    if(len <= 1)
        return ;
    std::reverse(cppstring.begin() , cppstring.end()); 
    int start = 0;
    while (start < len) {
        int end_word = cppstring.find(" ", start);
        if (end_word == string::npos) {
            end_word = len;
        }
        std::reverse(cppstring.begin() , cppstring.begin()+ end_word ); 

        start = end_word + 1;
    }
}


int main(){
    cout<<"---------------------reverse_string_c-----------------"<<endl;
    char cstring []="welcome in Egypt";
    cout<<"the origin:"<<cstring<<endl;
    reverse_string_c(cstring);
    cout<<"new_string:"<<cstring<<endl;

    cout<<"---------------------reverse_string_v2_c-----------------"<<endl;
    char cstringv2 []="hello world!!";
    cout<<"the origin:"<<cstringv2<<endl;
    reverse_string_v2_c(cstringv2);
    cout<<"new_string:"<<cstringv2<<endl;

    cout<<"---------------------reverse_string_cpp-----------------"<<endl;
    string cppstring="welcome in Egypt";//"to be cpp or not to be";
    cout<<"the origin:"<<cppstring<<endl;
    reverse_string_cpp(cppstring);
    cout<<"new_string:"<<cppstring<<endl;

    cout<<"---------------------reverse_string_v2_cpp-----------------"<<endl;
    string cppstringcppv2="to be cpp or not to be";
    cout<<"the origin:"<<cppstringcppv2<<endl;
    reverse_string_v2_cpp(cppstringcppv2);
    cout<<"new_string:"<<cppstringcppv2<<endl;



    return 0;
}