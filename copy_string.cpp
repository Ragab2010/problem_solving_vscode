#include<iostream>
#include<cstring>

using namespace std;
//note:strlen count characters only didn't include NULL  in count , start count from one
char *  copy_string(char * string){
    char * new_String = (char*) malloc(sizeof(char) * strlen(string)+1);
    if(new_String == nullptr)
        return nullptr;
    strncpy(new_String , string ,strlen(string)+1);
    //strcpy(new_String , string );
    return new_String;
}


int main(){
    char string []="welcome in Egypt";
    char* new_string= copy_string(string);
    cout<<"new_string="<<new_string<<endl;
    // cout<<"---------------------before toggle-----------------"<<endl;
    // toggle_bit(&number , 2);
    // cout<<"---------------------after swap-----------------"<<endl;
    // cout<<std::hex<<"number="<<number<<endl;


    return 0;
}