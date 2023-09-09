#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;

void remove_string_consecutive_duplicates_c(char * cstring){
    int len = strlen(cstring);
    int l=0 , h = 0 ,  current_pos=0;
    //arr:wwwweeeellllccccooomeee 
    //loop on array  by two pointer  low (l) , high(h)  with limit to the size of array 
    // every elements consecutive if(cstring[l] == cstring[h])->true  increment as wwwwee
    // l point on w , h point on thrid w 
    //when if(cstring[l] == cstring[h])->false  as l point on w and h point on first e
    //here we current_pos++ , that we want  cstring[0] only 
    //,  and increment l to be like h (l = h)
    //after finish the string ,write null at position current_pos 
    // while(l < len && h <len ){
    //     if(cstring[l] ==  cstring[h]){
    //         h++;
    //     }else{
    //         cstring[current_pos]=cstring[l];
    //         current_pos++;
    //         l = h;
    //     }
    // }    
    while(l < len && h <len ){
        while( (cstring[l] ==  cstring[h]) &&(l < len && h <len)){
            h++;
        }
            cstring[current_pos]=cstring[l];
            current_pos++;
            l = h;
    }
    cstring[current_pos]='\0';

    
}
//prefer
void remove_string_consecutive_duplicates_cpp(string &cppstring){
    int len = cppstring.length();
    int current_pos=0;
    
    int l = 0 , h=0;
    for(int i = 1 ; i<len; i++){
        if(cppstring[i] != cppstring[i-1]){
            cppstring[current_pos]=cppstring[i-1];
            current_pos++;
        }
    }
    cppstring[current_pos]=cppstring[len-1];
    current_pos++;
    cppstring.erase(current_pos);
    cppstring.shrink_to_fit();
    
}

void remove_string_consecutive_duplicates_unique_cpp(string &cppstring){
    //use unique function to  remove_consecutive_duplicates
    auto last_element = std::unique(cppstring.begin(), cppstring.end());
    //resize the vector from cppstring.begin() to last_element
    cppstring.resize(std::distance(cppstring.begin() , last_element));
    cppstring.shrink_to_fit();
}



int main(){

    cout<<"---------------------remove_duplicate_C-----------------"<<endl;
    char c_string[]= "wwleecccommmeee";
    cout<<"the origin:"<<c_string<<endl;
    remove_string_consecutive_duplicates_c(c_string) ;
    cout<<"the new   :"<<c_string<<endl;
    cout<<"---------------------remove_duplicate_Cpp-----------------"<<endl;
    string cpp_string= "wwleecccommmeee"s;
    cout<<"the origin:"<<cpp_string<<endl;
    remove_string_consecutive_duplicates_cpp(cpp_string) ;
    cout<<"the new   :"<<cpp_string<<endl;
    cout<<"---------------------remove_duplicate_unique_Cpp-----------------"<<endl;
    string cpp_string2= "wwleecccommmeee"s;
    cout<<"the origin:"<<cpp_string2<<endl;
    remove_string_consecutive_duplicates_unique_cpp(cpp_string2) ;
    cout<<"the new   :"<<cpp_string2<<endl;

    
    return 0;
}