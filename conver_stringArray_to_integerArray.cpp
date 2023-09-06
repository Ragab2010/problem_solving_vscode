#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<sstream>
#include<limits>



using namespace std;
int * parse_stringArray_C(char *cstring , int *int_array_size){
    if(cstring == NULL || int_array_size ==  NULL)
        return NULL;
    int len = strlen(cstring);
    int *int_array = (int *)malloc(sizeof(int)*len);
    if(int_array ==NULL)
        return NULL;
    char *next_number = cstring;
    int index_intArray=0;
    int parse_index = 0;
//loop
    while(next_number !=NULL && parse_index <len){
    //discard none numbers 
    if(!isdigit(*next_number)){
        //cout<<*next_number<<endl;
        next_number++;
    }else{
        //parse the number until the none digit 
        int parse_number =strtol(next_number , &next_number , 10);
        //push it at the int array with increment the index_intArray,
        //to know the size of int_array 
        int_array[index_intArray]=parse_number;
        index_intArray++;
        //cout<<parse_number<<endl;
        //next_number++;
    } 
    parse_index++;
    }
    //resize the int_array with the index_intArray
    int* new_int_array =(int *)realloc(int_array , sizeof(int)* index_intArray);
    //write the index_intArray to pointer to tell the caller the size of int_array
    *int_array_size=index_intArray;
    return new_int_array;
}

std::vector<int> parse_stringArray_v1(const std::string& input) {
    std::vector<int> result; // Create a vector to store parsed integers
    std::stringstream ss(input); // Create a string stream from the input string
    int num;

    // Ignore leading '{'
    ss.ignore(std::numeric_limits<std::streamsize>::max(), '{');

    while (ss >> num) {
        result.push_back(num); // Add the integer to the result vector

        // Ignore comma and potential spaces
        ss.ignore(std::numeric_limits<std::streamsize>::max(), ',');
    }

    // Ignore trailing '}'
    ss.ignore(std::numeric_limits<std::streamsize>::max(), '}');

    return result; // Return the vector of parsed integers
}

int main(){

    cout<<"---------------------parse_stringArray_C-----------------"<<endl;
    char arrString[]= "{1, 23,3 ,4,565, 6,  7 ,8 }";
    int int_array_size;
    int *int_array=parse_stringArray_C(arrString , &int_array_size);
    for (int i = 0; i < int_array_size; i++){
        cout<<int_array[i]<<", ";
    }
    cout<<endl;
    free(int_array);

    cout<<"---------------------parse_stringArray_v1-----------------"<<endl;
    std::string arrStringcpp = "{1, 23,3 ,4,565, 6,  7 ,8 }";
    std::vector<int> parsed_array = parse_stringArray_v1(arrStringcpp);

    //Print the parsed integers
    for (int num : parsed_array) {
        std::cout << num << ", ";
    }
    std::cout << "\n";

    return 0;
}