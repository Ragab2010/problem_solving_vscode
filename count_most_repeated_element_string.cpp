#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>



using namespace std;

int count_most_repeated_bruteforce_c(char * cstring){
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int max=0;
    for (int i = 0; i < len; i++)
    {
        int count=0;
        for (int j = 0; j < len; j++)
        {
            if((cstring[i] == cstring[j]) ) {
                count++;
            }
        }
        if(count >= max){
            max = count;
            count=0;
        }
        
    }
    
    return max;
}
int count_most_repeated_map_c(char * cstring){
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int max=0;
    char seen[256]={0};
    for (int i = 0; i < len; i++){
        seen[cstring[i]]++;
        if(seen[cstring[i]] > max){
            max=seen[cstring[i]];
        }
    }
    
    
    return max;
}

int count_most_repeated_map_cpp(string & cppstring){
    std::unordered_map<int, char> frequency_map;
    int max_frequency = 0;
    int most_repeated_element = 0;
    
    // Count frequency of each element
    for (int i = 0; i < cppstring.size(); i++) {
        frequency_map[cppstring[i]]++;
        if (frequency_map[cppstring[i]] > max_frequency) {
            max_frequency = frequency_map[cppstring[i]];
            //most_repeated_element = v[i];
        }
    }
    
    return max_frequency;
    
}


int count_most_repeated_search_cpp(string & cppstring){
    int max_frequency = 0;
    int most_repeated_element = 0;
    
    // Count frequency of each element
    for (auto& element : cppstring) {
        int count = std::count(cppstring.begin() , cppstring.end() , element);
        if (count > max_frequency) {
            max_frequency = count;
            //most_repeated_element = element;
        }
    }
    
    return max_frequency;
    
}

int main(){

    cout<<"---------------------count_most_repeated_bruteforce_c-----------------"<<endl;
    char c_string[]= "wwleecccommmeee";
    cout<<"the origin:"<<c_string<<endl;

    cout<<"the max count   :"<<count_most_repeated_bruteforce_c(c_string)<<endl;
    cout<<"---------------------count_most_repeated_map_c-----------------"<<endl;
    char c_string2[]= "wwleecccommmeee";
    cout<<"the origin:"<<c_string2<<endl;
    cout<<"the max count   :"<<count_most_repeated_map_c(c_string2)<<endl;
    cout<<"---------------------count_most_repeated_search_cpp-----------------"<<endl;
    string cpp_string= "wwleecccommmeee"s;
    cout<<"the origin:"<<cpp_string<<endl;
    cout<<"the max count   :"<<count_most_repeated_search_cpp(cpp_string)<<endl;
    cout<<"---------------------count_most_repeated_map_cpp-----------------"<<endl;
    string cpp_string2= "wwleecccommmeee"s;
    cout<<"the origin:"<<cpp_string2<<endl;
    cout<<"the max count   :"<<count_most_repeated_map_cpp(cpp_string)<<endl;



    return 0;
}