#include <iostream>
using namespace std;

class ListNode
{
public:
    int val{0};
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class MiddleOfLinkedList
{
public:
    static ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

int main(int, char **)
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->val << endl;

    head->next->next->next->next->next = new ListNode(6);
    cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->val << endl;

    head->next->next->next->next->next->next = new ListNode(7);
    cout << "Middle Node: " << MiddleOfLinkedList::findMiddle(head)->val << endl;
}
