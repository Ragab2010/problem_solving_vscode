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

    return 0;
}