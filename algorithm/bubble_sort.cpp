#include<iostream>


using namespace std;
void bubble_sort_v1(int *a , int size){
    bool is_Sorted= false;
    for (int i = size-1  ; i>=0 &&is_Sorted==false; i--){
        for (int j = 0; j <i ; j++) {
            is_Sorted ==true;//let asume that the array is sorted
            if(a[j] >a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                //when we swap mean that the array is not sorted
                is_Sorted= false;
            }
        }
        
    }
    
}
void bublle_Sort_v2(int *a , int size){
	int i,j,temp , isSorted=1;
	for(i =0 ; i < size ;i++){
		for(j=size-1; j > i ;j--){
			if(a[j-1] > a[j]){
				temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                isSorted = 0;
			}
		}
		if(isSorted)
			break;
	}
}


void bubble_sort(int * arr, int n) {
    int  temp;
    bool is_Sorted= false;
    for (int i = 0; i < n-1; i++) {
        for ( int j = 0; j < n-i-1; j++) {
            is_Sorted ==true;//let asume that the array is sorted
            if (arr[j] > arr[j+1]) {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                //when we swap mean that the array is not sorted
                is_Sorted= false;
            }
        }
    }
}


int main(){
    int arr[] = {6,3,0,4,2,1,9,12,8,16,11,5,15};
    cout<<"---------------------bubble_sort C , Cpp -----------------"<<endl;
    cout<<"the origin array:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubble_sort(arr , sizeof(arr)/sizeof(*arr));
    cout<<"the sorted array:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}