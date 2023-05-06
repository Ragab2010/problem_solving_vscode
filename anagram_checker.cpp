#include<iostream>
#include<cstring>
#include<cctype>
#include<unordered_map>


#define NUM_CHARACHTER 'z'-'a'+1

using namespace std;
//note:strlen count characters only didn't include NULL  in count , start count from one
bool anagram_checker_c(char * str1 ,char * str2){

    if(str1 == nullptr || str2 == nullptr){
        return false;
    }
    int lenstr1 = strlen(str1);
    int lenstr2 = strlen(str2);
    if(lenstr1 != lenstr2){
        return false;
    }
    char hash_array[NUM_CHARACHTER]={0};
    for(int i = 0 ; i<lenstr1 ; i++){
        //'a'-tolower(str1[i]) /we shift the number to begin from zero ,
        //as 'a' - str1[1]->'a' so it will be 'a'-'a'=0 from index 0 at the hash_array
        hash_array[tolower(str1[i]) - 'a']++;
        hash_array[tolower(str2[i]) - 'a']--;
    }
    for(char i = 0 ; i<NUM_CHARACHTER ; i++){
        if(hash_array[i] >0){
            return false;
        }
    }
    return true;
}

bool anagram_checker_cpp(string str1 ,string str2){

    if(str1.empty()|| str2.empty()){
        return false;
    }
    int lenstr1 = str1.size();
    int lenstr2 = str2.size();
    if(lenstr1 != lenstr2){
        return false;
    }
    std::unordered_map<char , int> freq;
    for(int i = 0 ; i<lenstr1 ; i++){
        //'a'-tolower(str1[i]) /we shift the number to begin from zero ,
        //as 'a' - str1[1]->'a' so it will be 'a'-'a'=0 from index 0 at the hash_array
        freq[tolower(str1[i])]++;
        freq[tolower(str2[i])]--;
    }
    //for (auto& [key, value] : freq) {//for c++17
    for(auto it : freq){
        if(it.second >0)
            return false;
    }
    return true;
}


int main(){
    char w1[] = "Listen";
    char w2[] = "Silent";
    cout<<"---------------------anagram_checker_c-----------------"<<endl;
    cout<<"w1[] = \"Listen\" , w2[] = \"Silent\""<<endl;
    cout<<std::boolalpha<<"return="<<anagram_checker_c(w1 , w2)<<endl;

    string w1cpp = "Listen";
    string w2cpp = "Silent";
    cout<<"---------------------anagram_checker_cpp-----------------"<<endl;
    cout<<"w1cpp = \"Listen\" , w2cpp = \"Silent\""<<endl;
    cout<<std::boolalpha<<"return="<<anagram_checker_cpp(w1cpp , w2cpp)<<endl;



    return 0;
}