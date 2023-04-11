#include<iostream>


using namespace std;

int partition(int *a , int low , int high){
    int pivot_index = high;
    int last_index=low;
    for (int i = low; i <= high; i++){
        if(a[i]< a[pivot_index]){
            int temp = a[i];
            a[i] =a[last_index];
            a[last_index]=temp;
            last_index++;
        }
    }
    int temp = a[pivot_index];
    a[pivot_index] =a[last_index];
    a[last_index]=temp;

    return last_index;
}
void quick_sort(int *a , int low , int high){

    if(low <= high){
        int pivot =partition(a , low , high);
        quick_sort(a , low , pivot - 1);
        quick_sort(a , pivot + 1 , high);
    }
}


int main(){
    int arr[] = {6,3,0,4,2,1,9,12,8,16,11,5,15};
    cout<<"---------------------selection_sort C , Cpp -----------------"<<endl;
    cout<<"the origin array:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quick_sort(arr , 0 ,  sizeof(arr)/sizeof(*arr) - 1 );
    cout<<"the sorted array:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}