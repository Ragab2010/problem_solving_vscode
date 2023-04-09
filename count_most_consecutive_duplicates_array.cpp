#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>



using namespace std;
int count_most_consecutive_duplicates_bruteforce_c(int *a  , int size ){
    if(size  <=1)
        return -1;
    int max=0;
    for (int i = 0; i < size ; i++)
    {
        int count=0;
        bool is_cons= true;
        for (int j = i;(j < size ) && is_cons; j++)
        {
            if((a[i] == a[j]) && is_cons ) {
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

int count_most_consecutive_duplicates_slidingwindow_c(int *a  , int size ){

    if(size  <=1)
        return -1;
    int l= 0 , h = 0 , count = 0  , max =0;
    while(l < size  && h <size ){
        if(a[l] == a[h]){
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

int count_most_consecutive_duplicates_slidingwindow_v2_c(int *a  , int size ){

    if(size  <=2)
        return -1;
    int max = 0 , count=1;
    for (int i = 1; i < size ; i++){
        if(a[i] == a[i-1]){
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
int count_most_consecutive_duplicates_slidingwindow_ragabVersion_c(int *a  , int size ){
    if(size  <=2)
        return -1;
    int max = 0 , count=1;
    //loop on all  array
    for(int i = 0 ; i<size -1; i++){
        if(a[i] == a[i+1]){
            int j = i ; 
            int count = 0;
            while(a[i] == a[j] && j<size  ){
                count++;
                j++;
            }
            if(count > max)
                max = count;
        }
            
    }
    return max;
}

int count_most_repeated_map_c(int *a  , int size ){
    if(size  <=1)
        return -1;
    int max=0;
    char seen[256]={0};
    for (int i = 0; i < size ; i++){
        seen[a[i]]++;
        if(seen[a[i]] > max){
            max=seen[a[i]];
        }
    }
    
    
    return max;
}
int count_most_consecutive_duplicates_slidingwindow_cpp(vector<int>& v) {
    if(v.size() <=1)
        return -1;
    int max_count = 0;
    int count = 1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1]) {
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
    int arr[]= {1,1,1,1,3,3,3,6,6,6,6,3,3,3,9,9,8,2,1,4,7,7,7,7,7};
    cout<<"the origin:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"the max count   :"<<count_most_consecutive_duplicates_bruteforce_c(arr , sizeof(arr)/sizeof(*arr))<<endl;

    cout<<"---------------------count_most_consecutive_duplicates_slidingwindow_c-----------------"<<endl;
    cout<<"the max count   :"<<count_most_consecutive_duplicates_slidingwindow_c(arr , sizeof(arr)/sizeof(*arr))<<endl;

    cout<<"---------------------count_most_consecutive_duplicates_slidingwindow_v2_c-----------------"<<endl;
    cout<<"the max count   :"<<count_most_consecutive_duplicates_slidingwindow_v2_c(arr , sizeof(arr)/sizeof(*arr))<<endl;

    cout<<"---------------------count_most_consecutive_duplicates_slidingwindow_ragabVersion_c-----------------"<<endl;
    cout<<"the max count   :"<<count_most_consecutive_duplicates_slidingwindow_ragabVersion_c(arr , sizeof(arr)/sizeof(*arr))<<endl;
    
    cout<<"---------------------count_most_repeated_search_cpp-----------------"<<endl;
    vector<int> v= {1,1,1,1,3,3,3,6,6,6,6,3,3,3,9,9,8,2,1,4,7,7,7,7,7};
    cout<<"the origin:";
    for (int i = 0; i <v.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"the max count   :"<<count_most_consecutive_duplicates_slidingwindow_cpp(v)<<endl;


    return 0;
}