#include <iostream>

using namespace std;

int findSquareSum(int number) {
    int sum = 0, digit = 0;
    do {
        digit = number % 10;
        sum += digit * digit;
        number = number / 10;
    } while (number);
    return sum;
}

bool isHappy(int num) {
    int slow = num, fast = num;
    do {
        slow = findSquareSum(slow);
        fast = findSquareSum(findSquareSum(fast));
    } while (slow != fast);
    return slow == 1;
}

int main() {
    // Test cases
    int testCases[] = {19, 2, 7, 10, 13};

    cout << "Test Cases:" << endl;
    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); ++i) {
        int num = testCases[i];
        cout << "Test Case " << i + 1 << ": " << num << endl;
        cout << "Output: ";
        if (isHappy(num)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << endl;
    }

    return 0;
}
