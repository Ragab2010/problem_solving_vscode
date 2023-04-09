#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>



using namespace std;
int count_most_consecutive_duplicates_bruteforce_c(char * cstring){
    int len = strlen(cstring);
    if(len <=1)
        return -1;
    int max=0;
    for (int i = 0; i < len; i++)
    {
        int count=0;
        bool is_cons= true;
        for (int j = i;(j < len) && is_cons; j++)
        {
            if((cstring[i] == cstring[j]) && is_cons ) {
                count++;
            }else{
                is_cons=false;
            }
        }
        if(count >= max){
            max = count;
            count=0;
        }
        
    }
    
    return max;
}

int count_most_consecutive_duplicates_slidingwindow_c(char * cstring){
    int len  = strlen(cstring);
    if(len <=1)
        return -1;
    int l= 0 , h = 0 , count = 0  , max =0;
    while(l < len && h <len){
        if(cstring[l] == cstring[h]){
            h++;
            count++;
        }else{
            l++;
            count--;
        }
        if(count > max ){
            max = count;
        }
    }
    return max;
}

int count_most_consecutive_duplicates_slidingwindow_v2_c(char * cstring){
    int len  = strlen(cstring);
    if(len <=2)
        return -1;
    int max = 0 , count=1;
    for (int i = 1; i < len; i++){
        if(cstring[i] == cstring[i-1]){
            count++;
        }else{
            if(count>max){
                max = count;
            }
            count =1;
        }
    }
    if(count>max){
        max = count;
    }
    return max;
}
int count_most_consecutive_duplicates_slidingwindow_ragabVersion_c(char * cstring){
    int len  = strlen(cstring);
    if(len <=2)
        return -1;
    int max = 0 , count=1;
    //loop on all  array
    for(int i = 0 ; i<len-1; i++){
        if(cstring[i] == cstring[i+1]){
            int j = i ; 
            int count = 0;
            while(cstring[i] == cstring[j] && j<len ){
                count++;
                j++;
            }
            if(count > max)
                max = count;
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
int count_most_consecutive_duplicates_slidingwindow_cpp(string& cppstring) {
    if(cppstring.size() <=1)
        return -1;
    int max_count = 0;
    int count = 1;
    for (int i = 1; i < cppstring.size(); i++) {
        if (cppstring[i] == cppstring[i-1]) {
            count++;
        } else {
            if (count > max_count) {
                max_count = count;
            }
            count = 1;
        }
    }
    if (count > max_count) {
        max_count = count;
    }
    return max_count;
}


int main(){

    cout<<"---------------------count_most_consecutive_duplicates_bruteforce_c-----------------"<<endl;
    char c_string[]= "wwleecccommmmmeee";
    cout<<"the origin:"<<c_string<<endl;

    cout<<"the max count   :"<<count_most_consecutive_duplicates_bruteforce_c(c_string)<<endl;

    cout<<"---------------------count_most_consecutive_duplicates_slidingwindow_c-----------------"<<endl;
    char c_string2[]= "wwleeccccommmeee";
    cout<<"the origin:"<<c_string2<<endl;
    cout<<"the max count   :"<<count_most_consecutive_duplicates_slidingwindow_c(c_string2)<<endl;

    cout<<"---------------------count_most_consecutive_duplicates_slidingwindow_v2_c-----------------"<<endl;
    char c_string3[]= "wwwwwwwwleeecccommmeee";
    cout<<"the origin:"<<c_string3<<endl;
    cout<<"the max count   :"<<count_most_consecutive_duplicates_slidingwindow_v2_c(c_string3)<<endl;

    cout<<"---------------------count_most_consecutive_duplicates_slidingwindow_ragabVersion_c-----------------"<<endl;
    char c_string4[]= "wwleeccccccommmeee";
    cout<<"the origin:"<<c_string4<<endl;
    cout<<"the max count   :"<<count_most_consecutive_duplicates_slidingwindow_ragabVersion_c(c_string4)<<endl;
    
    cout<<"---------------------count_most_repeated_search_cpp-----------------"<<endl;
    string cpp_string= "wwleecccommmeee"s;
    cout<<"the origin:"<<cpp_string<<endl;
    cout<<"the max count   :"<<count_most_consecutive_duplicates_slidingwindow_cpp(cpp_string)<<endl;




    return 0;
}