#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <sstream>

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
const int MOD = 1000000007;


int countDistinctColorings(vector<string> domino) {
    int n = domino[0].size();
    long long count = 0;
    unordered_set<string> set;
    stringstream ss;
    string rgb {"RGB"};
    sort(rgb.begin(), rgb.end());
    int index_domino ; 
    do{
        //cout<<rgb<<endl;
        ss<<"{";
        for(string d : domino){
            for(char c : d){
                ss<<rgb[(c%rgb.length())];
            }
            ss<<" , ";
        }
        ss<<"}";
        // cout<<ss.str()<<endl;
        set.insert(ss.str());
    }while(next_permutation(rgb.begin() , rgb.end()));


return set.size()%MOD;
}

int main() {
    vector<string> domino = {"baa", "bcc"};
    int result = countDistinctColorings(domino);
    cout << "Total number of distinct valid colorings: " << result << endl;
    return 0;
}
