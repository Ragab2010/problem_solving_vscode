#include<iostream>




using namespace std;
// Function to calculate factorial using iteration
int calc_factorial_iterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate factorial using recursion
int calc_factorial_recursive(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * calc_factorial_recursive(n-1);
}

int main(){

    cout<<"---------------------calc_factorial_iterative C , Cpp -----------------"<<endl;
    cout<<calc_factorial_iterative(6)<<endl;

    cout<<"---------------------calc_factorial_recursive C , Cpp -----------------"<<endl;
    cout<<calc_factorial_iterative(6)<<endl;


    return 0;
}