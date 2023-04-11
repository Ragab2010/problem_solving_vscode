#include<iostream>


using namespace std;
void selection_sort(int *a , int size){
    if(size <=1)
        return ;
    for (int i = 0; i < size; i++){
        int min_index =i;
        for (int j = i; j < size; j++){
            if(a[min_index] > a[j]){
                min_index=j;
            }
        }
        int temp = a[min_index];
        a[min_index]= a[i];
        a[i] = temp;
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
    selection_sort(arr , sizeof(arr)/sizeof(*arr));
    cout<<"the sorted array:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}