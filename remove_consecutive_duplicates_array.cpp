#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

/*
    for (int i = 0; i < size; i++)
    {
        bool is_unque = true;
        for(int j = 0; j <new_size ; j++)
        {
            if(a[i] ==  new_array[j]){
                is_unque = false;
                break;
            }
        }
        if(is_unque){
            new_array[new_size++]=a[i];
        }
    }
*/

using namespace std;

//prefer
int * remove_consecutive_duplicates_c_v1(int * a , int size  , int *newSize){
    int * new_array = (int *) malloc(sizeof(int) * size);
    int new_array_index = 0;
    if(new_array ==NULL)
        return NULL;
    //copy unique only  form consecutive 
    int  l = 0 , h = 0 , new_size=0;
    //arr:1 1 1 1 3 3 3 6 6 6 6 3 3 3 9 9 8 2 1 4 7 7 7 7 7 
    //loop on array  by two pointer  low (l) , high(h)  with limit to the size of array 
    // every elements consecutive if(a[l] == a[h])->true  increment as 1 1 1 1 
    // l point on 1 , h point on thrid 1 
    //when if(a[l] == a[h])->false  as l point on 1 and h point on 3
    //here we copy a[l] element 1 ,  and increment l to be like h (l = h)
    //after copy a[l] and (l=h)  , increment(new_size) index of new_array 
    for(int i = 1 ; i<size; i++){
        if(a[i] != a[i-1]){
            new_array[new_array_index]= a[i-1];
            new_array_index++;
        }
    }
    //add the last element
    new_array[new_array_index]= a[size-1];
    new_array_index++;
    //resize the new_array with to fit with the last element (new_size)
    int *temp = (int *) realloc(new_array , sizeof(int)*new_array_index);
    if(new_array == NULL) {
        free(new_array); // free the old block of memory
        return NULL;
    }

    *newSize = new_array_index;
    return temp;
}


int * remove_consecutive_duplicates_c(int * a , int size  , int *newSize){
    int * new_array = (int *) malloc(sizeof(int) * size);
    if(new_array ==NULL)
        return NULL;
    //copy unique only  form consecutive 
    int  l = 0 , h = 0 , new_size=0;
    //arr:1 1 1 1 3 3 3 6 6 6 6 3 3 3 9 9 8 2 1 4 7 7 7 7 7 
    //loop on array  by two pointer  low (l) , high(h)  with limit to the size of array 
    // every elements consecutive if(a[l] == a[h])->true  increment as 1 1 1 1 
    // l point on 1 , h point on thrid 1 
    //when if(a[l] == a[h])->false  as l point on 1 and h point on 3
    //here we copy a[l] element 1 ,  and increment l to be like h (l = h)
    //after copy a[l] and (l=h)  , increment(new_size) index of new_array 
    while(l<size && h < size){
        bool is_unquie = false;
        while( (a[l] ==  a[h]) &&(l < size && h <size)){
            h++;
            is_unquie=true;
        }
        if(is_unquie){
            new_array[new_size]=a[l];
            l=h;
            new_size++;
        }
    }
    //resize the new_array with to fit with the last element (new_size)
    int *temp = (int *) realloc(new_array , sizeof(int)*new_size);
    if(new_array == NULL) {
        free(new_array); // free the old block of memory
        return NULL;
    }
    new_array = temp;

    *newSize = new_size;
    return new_array;

}

//prefer
std::vector<int> remove_consecutive_duplicates_cpp(vector<int> &v){
    std::vector<int> result;
    std::unordered_set<int> seen;
    for(auto number : v){
        if(seen.insert(number).second == true){
            result.push_back(number);
        }
    }
    return move(result);

}

vector<int> remove_consecutive_duplicates_cpp_v(vector<int>  v){
    //insert all the vector element at the unordered_set so there not duplication
    unordered_set<int> seen(v.begin() , v.end());
    vector<int> result;
    for(auto num_element: v){
        //check if there num_element at seen:
        //if it is not point on seen.end() , so there is an element  
        //push it at result and then remove it from seen 
        //c++17 if(auto it  = seen.find(num_element) ; it!= seen.end()){
        auto it  = seen.find(num_element);
        if( it!= seen.end()){
            result.push_back(num_element);
            seen.erase(it);
        }
    }
    return std::move(result);
}



int main(){

    cout<<"---------------------remove_duplicatein C-----------------"<<endl;
    int arr[]= {1,1,1,1,3,3,3,6,6,6,6,3,3,3,9,9,8,2,1,4,7,7,7,7,7};
    cout<<"the origin:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int *new_array= nullptr;
    int new_size= 0;
    new_array =remove_consecutive_duplicates_c(arr , sizeof(arr)/sizeof(*arr) , &new_size) ;
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
    std::vector<int> new_V = remove_consecutive_duplicates_cpp(v);
    cout<<"the new   :";
    for (auto  it  : v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}