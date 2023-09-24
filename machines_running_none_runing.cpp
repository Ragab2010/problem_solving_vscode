#include <iostream>
#include <random>

using namespace std;
/*

c++:
there are n machines placed in a line in manufacturing unit. Their arrangment is represented as a binnary srting machines,
of length n, where a machine is running if the charater is '1' and is not running if is '0'. in one operation, the state of a machine can be fllipped,
'1' is changed to '0' or vice versa, and the operation can be applied any number of times.

an arrangment is valid if no running machine has a non-running machine to its immediate right , i.e., the final arrangment doesn't contain "10" as a sub string

find the minimum number of operations required to form a valid arrangment.

example 
initially, machines ="10110". optimally , machines[0] and machines[4] are flipped to obtain "00111" after 2 operations. The answer is 2.

function description :
complete the function getMinimumOperations in the editor below

getMinimumOperations has following parameter: 
string machines: a binary string that denotes the inital arrangment of machines

Returns:
int the minimum number of operations required to make the arrangment valid.


int getMinimumOperations(string machines) 

*/
int getMinimumOperations(string machines){
    int len = machines.length();
    int count = 0;
    for( int i = 0; i < len -1 ; i++){
        if( machines[i] =='1' &&  machines[i+1] == '0'){
            int countOneBefore = 0;
            int countZeroAfter = 0;
            int indexOne = i-1;
            int indexZero = i+1;
            while(indexOne >=0 && machines[indexOne] =='1'){
                countOneBefore++;
                indexOne--;
            }
            while(indexZero <len && machines[indexZero] =='0'){
                countZeroAfter++;
                indexZero++;
            }
            cout<<"i="<<i <<"  countOneBefore="<<countOneBefore<<"  countZeroAfter="<<countZeroAfter<<endl;
            indexOne = i;
            indexZero = i;
            if(countOneBefore > countZeroAfter ){
                while(indexZero <len && machines[indexZero] =='0' ){
                        machines[indexZero] =='1';
                        indexZero++;
                        countZeroAfter--;
                        count++;
                        cout<<"count front "<<endl;
                    }               
            }else{
                while(indexOne >=0 && machines[indexOne] =='1'){
                    machines[indexOne] =='0';
                    indexOne--;
                    countOneBefore--;
                    count++;
                    cout<<"count back "<<endl;
                }
            }
           // count++;
        }
    }
    return count;
}

int main() {
    string machines = "0010101100";
    int operations = getMinimumOperations(machines);
    cout << operations << endl;

}