#include<iostream>
#include<cstring>


using namespace std;

void remove_duplicate_c(char * cstring){
    int len = strlen(cstring);
    int seen[256]={0};
    int current_pos=0;
    for (int i = 0; i < len; i++)
    {
        if(seen[cstring[i]] ==0){
            seen[cstring[i]]++;
            cstring[current_pos] = cstring[i];
            current_pos++;
        }
    }
    cstring[current_pos]='\0';
    
}

void remove_duplicate_cpp_v1_mapping(string &cppstring){
    int len = cppstring.size();
    int seen[256]={0};
    int current_pos=0;
    for (int i = 0; i < len; i++)
    {
        if(seen[cppstring[i]] ==0){
            seen[cppstring[i]]++;
            cppstring[current_pos] = cppstring[i];
            current_pos++;
        }
    }
    cppstring.erase(current_pos);
    cppstring[current_pos]='\0';
    cppstring.shrink_to_fit();
    
}

void remove_duplicate_cpp_v2_search(string &cppstring){
    string newString="";
    for(auto& ch :cppstring){
        if(newString.find(ch) == std::string::npos)
            newString +=ch;
    }
    cppstring.erase();
    cppstring =std::move(newString);
    cppstring.shrink_to_fit();
    
}



int main(){

    cout<<"---------------------remove_duplicate_C-----------------"<<endl;
    char c_string[]= "wwleecccommmeee";
    cout<<"the origin:"<<c_string<<endl;
    remove_duplicate_c(c_string) ;
    cout<<"the new   :"<<c_string<<endl;
    cout<<"---------------------remove_duplicate_Cpp-----------------"<<endl;
    string cpp_string= "wwleecccommmeee"s;
    cout<<"the origin:"<<cpp_string<<endl;
    remove_duplicate_cpp_v2_search(cpp_string) ;
    cout<<"the new   :"<<cpp_string<<endl;

    
    return 0;
}