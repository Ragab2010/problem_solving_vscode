#include<iostream>
#include<cstring>
#include<algorithm>
#include<sstream>




using namespace std;
int count_number_of_words_in_string_c(char * cstring){
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int count=0;
    char nonwords[] = " .,;\n\t";

    for (int i = 0; i < len; i++)
    {
        //example: ., welcome;. in Egypt
        //skip all nonwords " .,;\n\t" character from string and stop when see reach any alphabet ( ., |welcome;. in Egypt)
        while((strchr(nonwords , cstring[i]) !=NULL) && i <len){
            i++;
        }
        //now we at start of word (welcome)  as(|welcome;. in Egypt)
        //so we count the word
        if(i <len)
            count++;

        //skip all alphbet character from word and stop when see nonwords " .,;\n\t" ( ., welcome|;. in Egypt)
        while((strchr(nonwords , cstring[i]) ==NULL) && i <len){
            i++;
        }

    }
    
    return count;
}

int count_number_of_words_in_string_v1_c(char * cstring){
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int count=0;
    char nonwords[] = " .,;\n\t";

    for (int i = 0; i < len; i++)
    {
        //example: ., welcome;. in Egypt
        //skip all nonwords " .,;\n\t" character from string and stop when see reach any alphabet ( ., |welcome;. in Egypt)
        while(!isalpha(cstring[i]) && i <len){
            i++;
        }
        //now we at start of word (welcome)  as(|welcome;. in Egypt)
        //so we count the word
        if(i <len)
            count++;

        //skip all alphbet character from word and stop when see nonwords " .,;\n\t" ( ., welcome|;. in Egypt)
        while(isalpha(cstring[i]) && i <len){
            i++;
        }

    }
    
    return count;
}


int count_number_of_words_in_string_cpp(string cppstring){
    int word_count = 0;
    char nonwords[] = " .,;\n\t";
    stringstream ss(cppstring);
    string word;
    while (ss >> word) {
        size_t pos = word.find_first_of(nonwords);
        while (pos != string::npos) {  // Skip any non-word characters
            word.erase(pos, 1);
            pos = word.find_first_of(nonwords);
        }
        if (!word.empty()) {  // Only count non-empty words
            word_count++;
        }
    }
    return word_count;
}

int main(){

    cout<<"---------------------count_number_of_words_in_string_c-----------------"<<endl;
    char c_string[]= " .; welcome;. in Egypt , this is the first one to visit Egypt ..";
    cout<<"the origin:"<<c_string<<endl;
    cout<<"the number of words:"<<count_number_of_words_in_string_c(c_string)<<endl;

    cout<<"---------------------count_number_of_words_in_string_c-----------------"<<endl;
    cout<<"the number of words:"<<count_number_of_words_in_string_v1_c(c_string)<<endl;
    cout<<"---------------------count_number_of_words_in_string_cpp-----------------"<<endl;
    cout<<"the number of words:"<<count_number_of_words_in_string_cpp(c_string)<<endl;





    return 0;
}