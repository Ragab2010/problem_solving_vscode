#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    // Test cases
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    cout << "Test Case 1: ";
    ListNode* middle1 = middleNode(head1);
    while (middle1 != nullptr) {
        cout << middle1->val << " ";
        middle1 = middle1->next;
    }
    cout << endl;

    cout << "Test Case 2: ";
    ListNode* middle2 = middleNode(head2);
    while (middle2 != nullptr) {
        cout << middle2->val << " ";
        middle2 = middle2->next;
    }
    cout << endl;

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
