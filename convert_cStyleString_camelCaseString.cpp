#include<iostream>
#include<cstring>
//#include<algorithm>
#include<cctype>

using namespace std;
char * toCamelCase_c(const char * cstyle_string ){
    if(cstyle_string == NULL)
        return  NULL;
    int len = strlen(cstyle_string);
    char * camelCase_string = (char *)malloc(sizeof(int)* (len+1));
    //check if the camelCase_string == NULL , return NULL;
    int index_cstyle =0 , index_cameCase=0;
    while(index_cstyle < len && index_cameCase < len ){
        if(cstyle_string[index_cstyle] == '_' || cstyle_string[index_cstyle] == '-'){
            ++index_cstyle;
            camelCase_string[index_cameCase] = toupper(cstyle_string[index_cstyle]);
            index_cameCase++;
            index_cstyle++;
        }else{
            camelCase_string[index_cameCase] = cstyle_string[index_cstyle];
            index_cameCase++;
            index_cstyle++;
        }
    }
    return camelCase_string;
}
std::string toCamelCase_cpp(std::string& style_string){
    int len = style_string.size();
    string camelCase_string="";
    for (int index_cstyle = 0; index_cstyle < len; index_cstyle++){
        if(style_string[index_cstyle] == '_' || style_string[index_cstyle] == '-'){
            camelCase_string += toupper(style_string[++index_cstyle]);
        }else{
            camelCase_string += style_string[index_cstyle];
        }
    }
    return camelCase_string;
    
}



int main(){

    cout<<"---------------------toCamelCase_c-----------------"<<endl;
    char cStyle_string []="to_came_case";
    char * cameCase_string  = toCamelCase_c(cStyle_string);
    cout<<"the cStyle   is :"<<cStyle_string<<endl;
    cout<<"the cameCase is :"<<cameCase_string<<endl;
        cout<<"---------------------toCamelCase_c-----------------"<<endl;
    std::string cppStyle_string="to_came_case"s;
    std::string cameCase_cppstring  = move(toCamelCase_cpp(cppStyle_string));
    cout<<"the cStyle   is :"<<cppStyle_string<<endl;
    cout<<"the cameCase is :"<<cameCase_cppstring<<endl;

    return 0;
}