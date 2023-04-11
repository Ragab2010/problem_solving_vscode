#include<iostream>


using namespace std;
void insertion_sort(int *a , int size){
    if(size <=1)
        return ;
    for (int i = 1; i < size; i++){
        int j =i;
        while(a[j]<=a[j-1] && j >0){
            int temp = a[j];
            a[j]=a[j-1];
            a[j-1]=temp;
            j--;
        }
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
    insertion_sort(arr , sizeof(arr)/sizeof(*arr));
    cout<<"the sorted array:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}