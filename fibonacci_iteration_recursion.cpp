#include<iostream>


using namespace std;

void fiboacci_iter(int n){
    //if there n less than 2 number of series return 
    if(n <2)
        return ;

    // here we  make the base of the fiboacci  item1 =0 , item2 =1 
    //the next element in series is 0+1 =1 new 
    //the next element in series is 1 old+1 new =2 newer 
    //the next element in series is 1 new +2 newer =3 newest  and ect
    int item1 =0 , item2 =1 ,next_item ;
    cout<< item1 <<" "<<item2;

    for(int i = 2; i<n ;i++){
        next_item = item1 +item2;
        cout<<" "<<next_item;
        item1 = item2;
        item2 = next_item;
    }
    cout<<endl;

}
int fiboacci_recu(int item){
    if(item ==0)
        return 0;
    else if(item == 1)
        return 1;
    return fiboacci_recu(item -1) + fiboacci_recu(item -2);
}


int main(){
    int number= 0xf0;
    cout<<"-------------------fibonacci series iteration----------------"<<endl;
    fiboacci_iter(20);
    cout<<"-------------------fibonacci series recursion ----------------"<<endl;
    for(int i = 0 ; i<20;i++){
        cout<<fiboacci_recu(i)<<" ";
    }
    cout<<endl;

    return 0;
}