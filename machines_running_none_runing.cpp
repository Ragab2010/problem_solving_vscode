#include <iostream>
#include <vector>
#include <algorithm>

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
int getMinimumOperations0(string machines){
    int start =0;
    int end = machines.length();
    while (machines[start]=='0' && start < end) start++;
    while (machines[end  ]=='1' && start < end) end--;
    int zeroCount=0;
    int oneCount=0;
    for(int i=start; i <end; i++){
        if(machines[i]=='0'){
            zeroCount++;
        }
        if(machines[i]=='1'){
            oneCount++;
        }
    }
    cout<<"zeroCount:"<<zeroCount<<endl;
    cout<<"oneCount:"<<oneCount<<endl;
    return std::min(zeroCount, oneCount);
}

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
                        machines[indexZero] ='1';
                        indexZero++;
                        countZeroAfter--;
                        count++;
                        cout<<"count front "<<endl;
                    }               
            }else{
                while(indexOne >=0 && machines[indexOne] =='1'){
                    machines[indexOne] ='0';
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
int getMinimumOperations2(string machines) {
    int len = machines.length();
    int count = 0;

    for (int i = 0; i < len - 1; i++) {
        if (machines[i] == '1' && machines[i + 1] == '0') {
            int countOneBefore = 0;
            int countZeroAfter = 0;
            int indexOne = i - 1;
            int indexZero = i + 1;

            while (indexOne >= 0 && machines[indexOne] == '1') {
                countOneBefore++;
                indexOne--;
            }

            while (indexZero < len && machines[indexZero] == '0') {
                countZeroAfter++;
                indexZero++;
            }

            indexOne = i;
            indexZero = i;

            if (countOneBefore > countZeroAfter) {
                while (indexZero < len && machines[indexZero] == '0') {
                    machines[indexZero] = '1';  // Update machine state
                    indexZero++;
                    countZeroAfter--;
                    count++;
                }
            } else {
                while (indexOne >= 0 && machines[indexOne] == '1') {
                    machines[indexOne] = '0';  // Update machine state
                    indexOne--;
                    countOneBefore--;
                    count++;
                }
            }
        }
    }

    return count;
}

int getMinimumOperations3(std::string machines) {
    int n = machines.length();
    std::vector<int> leftOnes(n, 0);
    std::vector<int> rightOnes(n, 0);

    // Count the number of '1's to the left of each machine
    for (int i = 1; i < n; ++i) {
        leftOnes[i] = leftOnes[i - 1] + (machines[i - 1] == '1');
    }

    // Count the number of '1's to the right of each machine
    for (int i = n - 2; i >= 0; --i) {
        rightOnes[i] = rightOnes[i + 1] + (machines[i + 1] == '1');
    }

    int minOperations = n; // Initialize with a large value

    for (int i = 0; i < n; ++i) {
        int flipsNeeded = leftOnes[i] + rightOnes[i];
        minOperations = std::min(minOperations, flipsNeeded);
        cout<< flipsNeeded << " "<<minOperations<<endl;
    }

    return minOperations;
}

int getMinimumOperations4(std::string machines) {
    int n = machines.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));

    // Initialize dp table
    dp[0][0] = 0; // No operations for the first 0 elements
    dp[0][1] = 0; // No operations for the first 0 elements

    for (int i = 1; i <= n; ++i) {
        if (machines[i - 1] == '0') {
            // If the current machine is '0', we can choose to flip it ('1') or not ('0')
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
            // If the current machine is '1', we can only choose not to flip it ('1')
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    // Return the minimum of operations needed at the end
    return std::min(dp[n][0], dp[n][1]);
}
int main() {
    // string machines = "0010101100";
    // int operations = getMinimumOperations(machines);
    string machines2 = "01110010010110001";
    int operations2 = getMinimumOperations(machines2);
    int operations3 = getMinimumOperations0(machines2);
    cout << operations2 << endl;
    cout << operations3<< endl;


}