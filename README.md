# **📌 Explanation: Find and Remove Nth Node from End of Linked List**  

## **🔍 Problem Understanding**  
We are given a **singly linked list** and an integer `n`. Our goal is to **remove the `n`th node from the end** of the list and return the modified list.

---

## **📌 Example Walkthrough**  

### **Example 1:**
```
Input: 1 → 2 → 3 → 4 → 5, n = 2  
Output: 1 → 2 → 3 → 5  
Explanation: The 2nd node from the end (4) is removed.
```
👉 The 2nd node from the end (4) is deleted, and the list becomes `1 → 2 → 3 → 5`.

### **Example 2:**
```
Input: 1 → 2, n = 1  
Output: 1  
Explanation: The last node (2) is removed.
```
👉 The last node is deleted, leaving only `1` in the list.

---

## **🚀 Approach: Two-Pointer Technique**  

The **most efficient way** to solve this problem is by using the **two-pointer technique**. Instead of finding the length of the list first, we use two pointers (`fast` and `slow`) to locate the node to be removed **in one pass**.

---

## **🔢 Step-by-Step Breakdown**  

### **🔹 Step 1: Create a Dummy Node**
- A **dummy node** is added before the head (`0 → head`).
- This helps handle edge cases (like removing the first node).

### **🔹 Step 2: Move `fast` Pointer `n+1` Steps Ahead**
- The `fast` pointer moves `n+1` steps forward to create a gap of `n` nodes between `fast` and `slow`.

### **🔹 Step 3: Move Both Pointers Together**
- Now, move both `fast` and `slow` pointers **one step at a time** until `fast` reaches the end.
- At this point, `slow` will be **right before** the node that needs to be deleted.

### **🔹 Step 4: Remove the Node**
- Update `slow->next` to `slow->next->next` to **skip the node** that needs to be deleted.

---

## **💻 Code Implementation**  

```cpp
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
    ListNode* dummy = new ListNode(0);  // Step 1: Create a dummy node
    dummy->next = head;
    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Step 2: Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Step 3: Move both pointers until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Step 4: Remove the nth node
    slow->next = slow->next->next;

    return dummy->next; // Return the new head
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
```

---

## **📌 Dry Run of the Code**  

### **🔹 Initial State:**
```
List: 1 → 2 → 3 → 4 → 5
n = 2
```

### **🔹 Step 1: Create Dummy Node**
```
dummy → 1 → 2 → 3 → 4 → 5
         ^   (head)
```

### **🔹 Step 2: Move `fast` `n+1 = 3` steps ahead**
```
dummy → 1 → 2 → 3 → 4 → 5
               ^   (fast)
         ^   (slow)
```

### **🔹 Step 3: Move `fast` and `slow` Together**
```
dummy → 1 → 2 → 3 → 4 → 5
                        ^   (fast reaches end)
               ^   (slow is right before node to delete)
```

### **🔹 Step 4: Remove Node**
```
dummy → 1 → 2 → 3 → 5
Output: 1 → 2 → 3 → 5
```

---

## **⏳ Time & Space Complexity Analysis**  

| **Operation**  | **Time Complexity**  | **Explanation** |
|---------------|----------------|----------------|
| Finding Nth node | O(N) | Traverses the list once using `fast` pointer |
| Removing node | O(1) | Modifies the links directly |
| Overall Complexity | **O(N)** | The whole process is done in a single pass |

✅ **Optimized Approach**: The solution is **O(N) time & O(1) space** since no extra memory is used except for pointers.

---

## **🔥 Key Takeaways**  
✔ **Two-pointer technique avoids extra space usage**  
✔ **Dummy node helps handle edge cases efficiently**  
✔ **Single pass solution (O(N)) is optimal**  

---

## **📧 Contact & Contribution**  
📩 **surajpratap469@gamil.com**  
⭐ **If you found this project useful, please star the repository on GitHub! 🚀**
