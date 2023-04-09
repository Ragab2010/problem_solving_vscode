#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>


using namespace std;

int count_most_repeated_bruteforce_c(int * a , int size ){
    if(size <=1)
        return -1;
    int max=0;
    for (int i = 0; i < size; i++)
    {
        int count=0;
        for (int j = 0; j < size; j++)
        {
            if((a[i] == a[j]) ) {
                count++;
            }
        }
        if(count >= max){
            max = count;
            count=0;
        }
        
    }
    
    return max;
}

int count_most_repeated_map_cpp(vector<int> & v){
    std::unordered_map<int, int> frequency_map;
    int max_frequency = 0;
    int most_repeated_element = 0;
    
    // Count frequency of each element
    for (int i = 0; i < v.size(); i++) {
        frequency_map[v[i]]++;
        if (frequency_map[v[i]] > max_frequency) {
            max_frequency = frequency_map[v[i]];
            //most_repeated_element = v[i];
        }
    }
    
    return max_frequency;
    
}


int count_most_repeated_search_cpp(vector<int> & v){
    int max_frequency = 0;
    int most_repeated_element = 0;
    
    // Count frequency of each element
    for (auto& element : v) {
        int count = std::count(v.begin() , v.end() , element);
        if (count > max_frequency) {
            max_frequency = count;
            //most_repeated_element = element;
        }
    }
    
    return max_frequency;
    
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
    int max_element=count_most_repeated_bruteforce_c(arr , sizeof(arr)/sizeof(*arr) ) ;
    cout<<"the max count   :"<<max_element<<endl;
    cout<<"---------------------remove_duplicatein C++ map-----------------"<<endl;
    std::vector<int> v{1,1,1,1,3,3,3,6,6,6,6,3,3,3,9,9,8,2,1,4,7,7,7,7,7};
    cout<<"the origin:";
    for (auto & it  : v)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    int max_element_cpp_map = count_most_repeated_search_cpp(v);
    cout<<"the max count   :"<<max_element_cpp_map<<endl;
    cout<<"---------------------remove_duplicatein C++ search(bruteforce)-----------------"<<endl;
    cout<<"the origin:";
    for (auto & it  : v)
    {
        cout<<it<<" ";
    }
    cout<<endl;//search
    int max_element_cpp_search = count_most_repeated_search_cpp(v);
    cout<<"the max count   :"<<max_element_cpp_search<<endl;
    cout<<"---------------------remove_duplicatein C++ lambda-----------------"<<endl;
    auto most_repeated_element = *std::max_element(v.begin(), v.end(),
        [&](int a, int b) { return std::count(v.begin(), v.end(), a) < std::count(v.begin(), v.end(), b); });
    std::cout << "Most repeated element: " << most_repeated_element << std::endl;

    return 0;
}