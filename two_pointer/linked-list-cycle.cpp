#include <iostream>
#include <unordered_set>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return false;
    }
    ListNode *fastPointer = head, *slowPointer = head;
    while (slowPointer != nullptr && fastPointer != nullptr && fastPointer->next != nullptr) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer) {
            return true;
        }
    }
    return false;
}

int main() {
    // Test cases
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next; // Cycle exists

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = nullptr; // No cycle

    cout << "Test Case 1: ";
    if (hasCycle(head1)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected!" << endl;
    }

    cout << "Test Case 2: ";
    if (hasCycle(head2)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected!" << endl;
    }

    // Clean up memory
    ListNode* temp;
    while (head1 != nullptr) {
        temp = head1;
        head1 = head1->next;
        delete temp;
    }
    while (head2 != nullptr) {
        temp = head2;
        head2 = head2->next;
        delete temp;
    }

    return 0;
}
