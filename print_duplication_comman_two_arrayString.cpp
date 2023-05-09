#include <cstdio> 
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

void parse_array(char * string_array ,int string_array_size , int *int_array ,int *int_array_size){
  int index =0;
  int index_int_array=0;
  while(index < string_array_size  && string_array != NULL){
    if(!isdigit(*string_array)){
      string_array++;
    }else{
      int number = strtol(string_array , &string_array , 10);
      int_array[index_int_array] = number;
      index_int_array++;
    }
    index++;
  }
  *int_array_size = index_int_array;
  
}

int find(int *int_array ,int size , int element){
  for(int i = 0 ; i<size ; i++){
    if(int_array[i] == element){
      return i;
    }
  }
  return -1;
}
void FindIntersection(char * strArr[], int arrLength) {
  
  // code goes here  
  int len_one = strlen(strArr[0]);
  int len_two = strlen(strArr[1]);
  int *array_one = (int *) malloc(sizeof(int) * len_one);
  int *array_two = (int *) malloc(sizeof(int) * len_two);

  int size_array_one;
  int size_array_two;

  parse_array(strArr[0] , len_one ,array_one , &size_array_one);
  parse_array(strArr[1] , len_two ,array_two , &size_array_two);
  for(int i = 0;i<size_array_one ; i++){
    printf("%d, " ,array_one[i] );
  }
    printf("\n" );

  for(int i = 0;i<size_array_two ; i++){
    printf("%d, " ,array_two[i] );
  }
    printf("\n" );
  

  for(int i = 0;i<size_array_two ; i++){
    int return_index = find(array_one ,size_array_one , array_two[i] );
    if(return_index != -1){
      printf("%d, " , array_one[return_index]);
    }
  }

}

int main(void) { 
   
  // keep this function call here
  char * A[] = {"1, 2, 3, 4, 5", "6, 7, 8, 9, 10"};
  int arrLength = 2;
  FindIntersection(A, arrLength);
  return 0;
    
}