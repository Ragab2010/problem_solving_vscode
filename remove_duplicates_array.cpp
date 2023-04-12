#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;

vector<int>  remove_duplicate_cpp(vector<int> & v){
    unordered_map<int , int > seen ;
    vector<int> result;
    /*
    for(auto& element: v){
        if(seen[element] != element){
            result.push_back(element);
            seen[element] = element;
        }
    }
    */
    for(auto& element: v){
        if(seen.find(element) ==seen.end()){
            result.push_back(element);
            seen[element] = element;
        }
    }

    return std::move(result);

}

int remove_duplicate_c(int * a , int  size , int **new_array , int *new_size){
    //create new_array with a'size
    *new_array = (int *)malloc(sizeof(int) * size);
    if((*new_array) ==nullptr)
        return -1;
    
    //move only the unique element 
    int newSize=0  , new_index=0;
    for(int index_array = 0; index_array<size ; index_array++){
        bool is_unquie = true;
        for(int index_new_array = 0; index_new_array<newSize ; index_new_array++){
            if(a[index_array] == (*new_array)[index_new_array]){
                    is_unquie=false;
                    break;
            }
        }
        if(is_unquie==true){
            (*new_array)[new_index] =a[index_array];
            new_index++;
            newSize++;
        }
    }
    //resize the new_aray 
    *new_array =(int *)realloc(*new_array  , newSize*sizeof(int));
    *new_size=newSize;
    return 1;
}

int main(){

    cout<<"---------------------remove_duplicatein C-----------------"<<endl;
    int arr[]= {1,3,6,3,3,3,9,9,8,2,1,4,7};
    cout<<"the origin:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int *new_array= nullptr;
    int new_size= 0;
    int status = remove_duplicate_c(arr , sizeof(arr)/sizeof(*arr) , &new_array , &new_size) ;
    cout<<"the new   :";
    for (int i = 0; i < new_size; i++)
    {
        cout<<new_array[i]<<" ";
    }
    cout<<endl;
    free(new_array);
    cout<<"---------------------remove_duplicatein C++-----------------"<<endl;
    std::vector<int> v{1,3,6,3,3,3,9,9,8,2,1,4,7};
    cout<<"the origin:";
    for (auto & it  : v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    std::vector<int> new_V = remove_duplicate_cpp(v);
    cout<<"the new   :";
    for (auto & it  : new_V)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}