#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove Nth node from end
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0);  // Dummy node for edge cases
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++)
        fast = fast->next;

    // Move both pointers together until fast reaches end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the Nth node
    slow->next = slow->next->next;

    return dummy->next;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Main function to test the code
int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int n = 2;
    cout << "Original List: ";
    printList(head);

    head = removeNthFromEnd(head, n);
    
    cout << "Modified List: ";
    printList(head);
    
    return 0;
}
