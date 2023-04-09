#include<iostream>


using namespace std;
//time : O(long N) , space : O(1)
int binary_search_iteratively( int * a , int size , int target ){
    if(size <=0)
        return -1;
    int  start = 0  , end = size -1  ;
    while(start <= end){
        //get the middle of array  
        int mid = start +(end -start)/2;
        if (target == a[mid] ){
            return mid;
        }else if(target < a[mid] ){
            end = mid -1;
        }else{
            start = mid +1;
        }

    }
    return -1;
}

//time : O(long N) , space : O(n)
int binary_search_recursively( int * a , int start , int end , int target ){

    while(start <= end){
        //get the middle of array  
        int mid = start +(end -start)/2;

        if (target == a[mid] ){
            return mid;
        }else if(target < a[mid] ){
            return binary_search_recursively( a , start , mid -1 , target);
        }else{
            return binary_search_recursively( a ,  mid +1 , end , target);
        }

    }
    return -1;
}

int main(){
    int number= 0xf0;
    int a[] = {1, 6, 8, 9, 12, 18, 25, 36, 52, 57, 61};

    cout<<"---------------------binary_search_iteratively-----------------"<<endl;
    int index_iter = binary_search_iteratively(a  , (sizeof(a)/sizeof(*a)) , 36);
    if(index_iter == -1)
        cout<<"the binary_search_iteratively= element dosent' exist "<<endl;
    else
        cout<<"the binary_search_iteratively= "<<a[index_iter]<<endl;
    
    cout<<"---------------------binary_search_recursively-----------------"<<endl;
    
    int index_rec = binary_search_recursively(a  , 0, (sizeof(a)/sizeof(*a))-1 , 36);
    if(index_rec == -1)
        cout<<"the binary_search_recursively= element dosent' exist "<<endl;
    else
        cout<<"the binary_search_recursively= "<<a[index_rec]<<endl;
    return 0;
}