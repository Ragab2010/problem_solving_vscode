
#include <iostream>
#include <algorithm> // for std::swap and std::copy
using namespace std;

using namespace std;
void insertion_sort(int *a, int size) {
    if (size <= 1) {
        return;
    }
    for (int endIndex = 1; endIndex < size; endIndex++) {
        int backIndex = endIndex;
        while (backIndex > 0 && a[backIndex] < a[backIndex - 1]) {
            std::swap(a[backIndex], a[backIndex - 1]);
            backIndex--;
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