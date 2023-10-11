#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <sstream>

using namespace std;
/*

c++:
A valid domino arrangement is given which is represented using two strings in array domino.
all dominoes are unique (of size 1*2 or 2*1) and each domino is represented by an English charater (lowercase or uppercase)

Each domino can be colored using any one of the colors Red,Green,or Blue (RGB).
Find the number of distinct ways to color the dominoes such that no two adjacent dominoes have the same color.
since the answer can be large, return the answer modulo(10^9 +7 ).
Note: Both halves of a domino are one Color.

Example:
consider domino ={"baa", "bcc"};
The valid coloring of dominoes are : {{RGG, RBB} , {RBB, RGG} , {GRR,GBB} , {GBB , GRR} , {BGG, BRR} , {BRR , BGG}}; Thus, the answer is 6;

Function description:
complete the function countDistinctColorings in the editor below.

countDistinctColorings has the following parameter: string domino[2]: two strings of equal length that denote the arrangement of dominoes
int countDistinctColorings(vector<string> domino)

Returns:
int total number of distinct valid colorings, taking modulo(10^9 + 7)
*/
const int MOD = 1000000007;

int countCharOfDomino(vector<string>& domino){
    unordered_set<char> count_char;
        for(string s : domino){
        for(char c: s){
            count_char.insert(c);
        }
    }
    return count_char.size();
}
int countDistinctColoringsTest(vector<string> domino){
    int countChar = countCharOfDomino(domino);
    cout<<"count="<<countChar<<endl;
    string rgb {"RGB"s.substr(0 , countChar)};
    sort(rgb.begin(), rgb.end());
    int index_domino ;
    unordered_set<string> set;
    do{
        //cout<<rgb<<endl;
        stringstream ss;
        for(string s : domino){
            for(char c: s){
                ss<<rgb[c%rgb.size()];
            }
        }
        set.insert(ss.str());
        cout<<ss.str()<<endl;

    }while(next_permutation(rgb.begin() , rgb.end()));
    return set.size()%MOD;
}



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
    // int result = countDistinctColorings(domino);
    // cout << "Total number of distinct valid colorings: " << result << endl;

    cout << countDistinctColoringsTest({"aab", "bcc"})<<endl;
    // cout << countDistinctColoringsTest(domino)<<endl;
    return 0;
}
