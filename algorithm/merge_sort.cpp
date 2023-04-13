#include<iostream>
#include<cmath>


using namespace std;


void merge( int *left_array , int *right_array ,int *orgin_array ,  int size_of_leftArray , int size_of_rightArray ){
    int left_index_array_counter=0;
    int right_index_array_counter=0;
    int orign_index_array_counter=0;
    while (left_index_array_counter < size_of_leftArray && right_index_array_counter < size_of_rightArray){
        if(left_array[left_index_array_counter] < right_array[right_index_array_counter]){
            orgin_array[orign_index_array_counter]=left_array[left_index_array_counter];
            orign_index_array_counter++;
            left_index_array_counter++;
        }else{
            orgin_array[orign_index_array_counter]=right_array[right_index_array_counter];
            orign_index_array_counter++;
            right_index_array_counter++;
        }
    }
    while(left_index_array_counter < size_of_leftArray ){
            orgin_array[orign_index_array_counter]=left_array[left_index_array_counter];
            orign_index_array_counter++;
            left_index_array_counter++;
    }
    while(right_index_array_counter < size_of_rightArray ){
            orgin_array[orign_index_array_counter]=right_array[right_index_array_counter];
            orign_index_array_counter++;
            right_index_array_counter++;
    }
    
}

void merge_sort_recursive(int *array , int size){
    if(size < 2){
        return ;
    }
    int middle , size_of_leftArray , size_of_rightArray;
    middle = size/2;
    size_of_leftArray =middle;
    size_of_rightArray =size - middle;
    int left_array[size_of_leftArray];
    int right_array[size_of_rightArray];
    for (int i = 0; i < middle; i++){
        left_array[i]=array[i];
    }
    for (int i = middle; i < size; i++){
        right_array[i-middle]=array[i];
    }
    merge_sort_recursive(left_array , size_of_leftArray);
    merge_sort_recursive(right_array , size_of_rightArray);
    merge(left_array ,right_array ,array ,  size_of_leftArray , size_of_rightArray );

}

// void merge_sort_iterative(int *array , int size ){
// 	int mid ;
// 	for(mid = 1 ; mid <=size/2 ; mid++){
// 		merge(array ,array ,array ,mid , size-mid);
// }

// function to sort the subsection a[i .. j] of the array a[]
void merge_sort_v2(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return;     // the subsection is empty or a single element
    }
    int mid = (i + j) / 2;

    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    
    merge_sort_v2(i, mid, a, aux);     // sort the left sub-array recursively
    merge_sort_v2(mid + 1, j, a, aux);     // sort the right sub-array recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter

    // we loop from i to j to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
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
    merge_sort_recursive(arr ,  sizeof(arr)/sizeof(*arr) );
    cout<<"the sorted array:";
    for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}