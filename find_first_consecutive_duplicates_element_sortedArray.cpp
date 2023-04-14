#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>



using namespace std;
int find_first_consecutive_duplicates_element_sortedArray(int *a  , int low , int high , int element ){
	int mid ;
	while(low <= high){
		mid = low +(high - low)/2;
		if((low == high && a[mid]==element) || (a[mid] == element && a[mid - 1] <element))
			return mid;
		else if (a[mid]>= element)
			return find_first_consecutive_duplicates_element_sortedArray(a , low , mid-1 , element );
		else
			return find_first_consecutive_duplicates_element_sortedArray(a , mid+1 , high , element);
	}

	return -1;
}

int find_first_consecutive_duplicates_element_sortedArray_v2(int *a  , int size){
    int left = 0;
    int right = size - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (a[mid] == a[mid + 1]) {
            return mid;
        } else if (a[mid] < a[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return -1;

	return -1;
}



int main(){

    cout<<"---------------------find_first_consecutive_duplicates_element_sortedArray-----------------"<<endl;
    int arr[]= {1,2,3,4,5,5,5,6,7};
    cout<<"the origin:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"the index :"<<find_first_consecutive_duplicates_element_sortedArray(arr , 0 , sizeof(arr)/sizeof(*arr)-1  , 5)<<endl;
    cout<<"---------------------find_first_consecutive_duplicates_element_sortedArray_v2-----------------"<<endl;
	int index_of_element =find_first_consecutive_duplicates_element_sortedArray_v2(arr , sizeof(arr)/sizeof(*arr));
    cout<<"the element is :"<<arr[index_of_element]<<endl;


    return 0;
}