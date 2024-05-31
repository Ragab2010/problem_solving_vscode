#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices) {
    int ans = 0;
    for (int i = 1; i < prices.size(); ++i) 
        ans += max(0, prices[i] - prices[i - 1]);    
    return ans;
}

int main() {
    // Test case 1
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Test Case 1:" << endl;
    cout << "Prices: ";
    for (int price : prices1) cout << price << " ";
    cout << endl;
    int result1 = maxProfit(prices1);
    cout << "Maximum Profit: " << result1 << endl << endl;

    // Test case 2
    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Test Case 2:" << endl;
    cout << "Prices: ";
    for (int price : prices2) cout << price << " ";
    cout << endl;
    int result2 = maxProfit(prices2);
    cout << "Maximum Profit: " << result2 << endl << endl;

    // Test case 3
    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Test Case 3:" << endl;
    cout << "Prices: ";
    for (int price : prices3) cout << price << " ";
    cout << endl;
    int result3 = maxProfit(prices3);
    cout << "Maximum Profit: " << result3 << endl << endl;

    // Additional test case 4
    vector<int> prices4 = {1, 2, 3, 1, 5, 6};
    cout << "Test Case 4:" << endl;
    cout << "Prices: ";
    for (int price : prices4) cout << price << " ";
    cout << endl;
    int result4 = maxProfit(prices4);
    cout << "Maximum Profit: " << result4 << endl << endl;

    // Additional test case 5
    vector<int> prices5 = {2, 1, 2, 0, 1};
    cout << "Test Case 5:" << endl;
    cout << "Prices: ";
    for (int price : prices5) cout << price << " ";
    cout << endl;
    int result5 = maxProfit(prices5);
    cout << "Maximum Profit: " << result5 << endl << endl;

    return 0;
}
