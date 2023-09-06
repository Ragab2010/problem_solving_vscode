#include<iostream>
#include<cstring>
#include<algorithm>
#include<sstream>




using namespace std;
/****************************************************************/
int count_long_number_of_words_in_string_c(char * cstring){
    if(cstring == NULL)
        return -1;
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int  i = 0 , max = 0 , count = 0;
    while(i < len){
        if(!isalpha(cstring[i])){
            //cout<<"->count="<<count<<endl;
            i++;
            if(count >max){
                max = count;
            }
            count=0;
        }else{
           // cout<<cstring[i];
            count++;
            i++;
        }

    }
    return max;
}

/************************************************************************/
int count_long_number_of_words_in_string_v2_c(char * cstring){
    if(cstring == NULL)
        return -1;
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int  i = 0 , max = 0 , count = 0;
    while(i < len){
        while(!isalpha(cstring[i]) && i < len){
            //cout<<"->count="<<count<<endl;
            i++;
        }
        while(isalpha(cstring[i]) && i < len){
            count++;
            //cout<<"->count="<<count<<endl;
            i++;
        }

        if(count >max){
            max = count;
        }
        count=0;

    }
    return max;
}


int count_long_number_of_words_in_string_cpp(string cppstring){
    std::stringstream ss(cppstring);
    std::string word;
    int longest = 0;
    while (ss >> word) {
        word.erase(std::remove_if(word.begin(), word.end(),
                                  [](char c) { return !std::isalpha(c); }), word.end());
        int length = word.length();
        if (length > longest) {
            longest = length;
        }
    }
    return longest;
}

int count_long_number_of_words_in_string_cpp_v1(string cppstring){
    std::istringstream iss(cppstring);
    std::string word;
    std::string maxWord;
    size_t maxWordLength = 0;

    while (iss >> word) {
        // Remove punctuation from the word
        std::string cleanedWord;
        for (char c : word) {
            if (isalnum(c) || c == '-') {
                cleanedWord += c;
            }
        }

        // Check if the cleaned word is longer than the current max word
        if (cleanedWord.length() > maxWordLength) {
            maxWord = cleanedWord;
            maxWordLength = cleanedWord.length();
        }
    }

    return maxWordLength;
}

int main(){

    cout<<"---------------------count_long_number_of_words_in_string_c-----------------"<<endl;
    char c_string[]= " .; welcomeeee;. in Egypt , this is the first one to visit Egypt ..";
    cout<<"the origin:"<<c_string<<endl;
    cout<<"the long words is :"<<count_long_number_of_words_in_string_c(c_string)<<endl;

    cout<<"---------------------count_long_number_of_words_in_string_v2_c-----------------"<<endl;
    cout<<"the long words is :"<<count_long_number_of_words_in_string_v2_c(c_string)<<endl;

    cout<<"---------------------count_long_number_of_words_in_string_cpp-----------------"<<endl;
    cout<<"the long words is :"<<count_long_number_of_words_in_string_cpp(c_string)<<endl;

    cout<<"---------------------count_long_number_of_words_in_string_cpp_v1-----------------"<<endl;
    cout<<"the long words is :"<<count_long_number_of_words_in_string_cpp_v1(c_string)<<endl;





    return 0;
}