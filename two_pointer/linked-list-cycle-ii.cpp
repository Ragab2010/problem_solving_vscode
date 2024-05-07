#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    bool hasCycle = false;
    ListNode *fastPointer = head, *slowPointer = head;
    while (slowPointer != nullptr && fastPointer != nullptr && fastPointer->next != nullptr) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next->next;
        if (slowPointer == fastPointer) {
            hasCycle = true;
            break;
        }
    }
    if (!hasCycle) {
        return nullptr;
    }

    slowPointer = head;
    while (slowPointer != fastPointer) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
    }
    return slowPointer;
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
    if (detectCycle(head1)) {
        cout << "Cycle detected!" << endl;
    } else {
        cout << "No cycle detected!" << endl;
    }

    cout << "Test Case 2: ";
    if (detectCycle(head2)) {
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
