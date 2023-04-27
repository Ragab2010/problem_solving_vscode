#include<iostream>


using namespace std;

int get_fibonacci_number_iter(int n){
    //if there n less than 2 number of series return 
    if(n <2)
        return 0;

    // here we  make the base of the fiboacci  item1 =0 , item2 =1 
    //the next element in series is 0+1 =1 new 
    //the next element in series is 1 old+1 new =2 newer 
    //the next element in series is 1 new +2 newer =3 newest  and ect
    int item1 =0 , item2 =1 ,next_item ;

    for(int i = 2; i<=n ;i++){
        next_item = item1 +item2;
        item1 = item2;
        item2 = next_item;
    }
    return item2;
}
int get_fibonacci_number_recu(int item){
    if(item ==0)
        return 0;
    else if(item == 1)
        return 1;
    return get_fibonacci_number_recu(item -1) + get_fibonacci_number_recu(item -2);
}


int main(){
    int number= 5;
    cout<<"the Number is:"<<number<<endl;
    cout<<"-------------------is_fiboacci_number_iter----------------"<<endl;
    int return_number_iter= get_fibonacci_number_iter(20);
    cout<<"the return Number is:"<<return_number_iter<<endl;
    cout<<"-------------------isfiboacci_numbe_recu----------------"<<endl;
    int return_number_rec= get_fibonacci_number_recu(20);
    cout<<"the return Number is:"<<return_number_rec<<endl;
    return 0;
}