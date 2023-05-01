#include<iostream>




using namespace std;
bool is_power_of_two(uint32_t number){
    if(number <=1)
        return  false;
    return (number & (number -1 )) == 0;
    //  return ((x != 0) && (!(x & (x - 1))));
}


int main(){

    cout<<"---------------------is_power_of_two C , Cpp -----------------"<<endl;
    for(int i =0 ; i<20; i++){
        cout<<"number ="<<i << "  is ";
        bool stauts  = is_power_of_two(i);
        if(stauts == true){
            cout<<"is power of 2"<<endl;
        }else{
            cout<<"isn't power of 2"<<endl;
        }

    }


    return 0;
}