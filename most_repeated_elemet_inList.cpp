#include<iostream>
#include<type_traits>

using namespace std;

/*********************************quicksort*********************************/
int partition(int *a , int l , int h){
    int i  ;// i for for
    int pivot = a[h];// make pivot the last element
    int partition_index= l;//the index that start place all the smallest element
    //move all the small element in front of pivot
    for( i = l ; i<h ;i++){
        if(a[i]< pivot){
            int swap = a[i];
            a[i] = a[partition_index];
            a[partition_index] = swap;
            partition_index++;

        }
    }
    //move the pivot at the last position at the end of the small elements
    int swap = a[h];
    a[h] = a[partition_index];
    a[partition_index] = swap;
    return  partition_index;

}
void quick_sort(int *a ,  int start , int  end){
    if( start <= end){
        int pivot = partition(a , start , end);
        quick_sort(a , start , pivot-1);
        quick_sort(a , pivot+1 , end);
    }
}
/*********************************************************************/

//time O(n * n)
int get_repeatedElement_brusefoce(int * a , int  size){
    int count = 0 , max =0 , index = 0;
    if(size<=1)
        return index;
    //two loop , compare every element with all other , compare with max 
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(a[i] == a[j] && (i != j))
                count++;
        }
        if(count >=max){
            max = count;
            index=i;
        }
        count= 0;
        
    }
    return index;    
}
void insertion_Sort(int *a , int size){
    if(size <=1)
        return ;
    for (int i = 1; i < size; i++)
    {
        int j = i; 
        while(a[j]< a[j-1]  && (j > 0)){
            int temp = a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
        }
    }
    // for (int i = 0; i < size; i++)
    // {
    //     cout<<a[i]<<", ";
    // }
    // cout<<endl;
}
//get_repeatedElement_sort ; time=O(n)ofSort  +O(n)ofcount = O(n)  , space O(1)
int get_repeatedElement_sort(int * a , int  size){
    if(size <=1)
        return 0 ;
    insertion_Sort(a , size);
    int p=0 , q=0  , count=0 , index=0  , max = 0;
    while(p < size && q <size){
        if(a[p] == a[q]){
            count++;
            q++;
        }else{
            p++;
            count--;
        }
        if(count > max){
            max = count;
            index = p;
        }
    }
    return index;
}

int main(){
    int a[]={6,0,0,0 ,6,9,3,2,5,8,8,8,8,8,6,6,9,9,1};
    
    int index_brusefoce = get_repeatedElement_brusefoce(a , (sizeof(a)/sizeof(*a)));
    cout<<"the element="<<a[index_brusefoce]<<endl;
    
    int index_sort = get_repeatedElement_sort(a , (sizeof(a)/sizeof(*a)));
    cout<<"the element="<<a[index_sort]<<endl;

    quick_sort(a , 0 , (sizeof(a)/sizeof(*a))-1);
    for (int i = 0; i < (sizeof(a)/sizeof(*a)); i++)
    {
        cout<<a[i]<<", ";
    }
    cout<<endl;
    return 0;
}