
#include <iostream>
#include <stack>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void reorderList(ListNode* head) {
    if (head ==nullptr || head->next==nullptr || head->next->next ==nullptr) return; // Check if the list is empty or has only 1 or 2 nodes
    
    std::stack<ListNode*> st;
    ListNode* slow = head ;
    ListNode* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* curr = slow->next;
    slow->next = nullptr; // Split the list into two halves
    //push the last halve into the stack;
    while (curr != nullptr) {
        st.push(curr);
        curr = curr->next;
    }
    
    curr = head;
    while (!st.empty()) {
        ListNode* nextNode = curr->next;
        ListNode* popNode = st.top();
        st.pop();
        
        curr->next = popNode;
        popNode->next = nextNode;
        
        curr = nextNode;
    }
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Test case
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    reorderList(head);

    std::cout << "Reordered list: ";
    printList(head);

    return 0;
}