#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    ListNode* current = head;

    while (current && current->next) {
        if (current->val == current->next->val) {
            ListNode* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;
        }
        else {
            current = current->next;
        }
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(1);
    head1->next->next = new ListNode(2);

    std::cout << "Example 1 Before: ";
    printList(head1);

    head1 = deleteDuplicates(head1);

    std::cout << "Example 1 After: ";
    printList(head1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(1);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(3);
    head2->next->next->next->next = new ListNode(3);

    std::cout << "Example 2 Before: ";
    printList(head2);

    head2 = deleteDuplicates(head2);

    std::cout << "Example 2 After: ";
    printList(head2);

    return 0;
}
