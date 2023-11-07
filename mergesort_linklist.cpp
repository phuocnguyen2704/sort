#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int _val = 0, ListNode* _next = nullptr) : val(_val), next(_next) { }
};

// Merge two sorted lists
ListNode* mergeLists(ListNode* a, ListNode* b);

// Sort an unsorted list given its head pointer
ListNode* mergeSortList(ListNode* head);

ListNode *mergeLists(ListNode *a, ListNode *b)
{
    ListNode * combine;
    while(a!=nullptr && b!=nullptr)
    {
        if ( a->val<b->val)
        {
            combine->next=a;
            combine=combine->next;
            a=a->next;
        }
        else 
        {
            combine->next=b;
            combine=combine->next;
            b=b->next;
        }
    }
    if (a==nullptr)
    {
        combine->next=b;
        b=nullptr;
    }
    else 
    combine->next=a;
    return combine ->next;
}

ListNode *mergeSortList(ListNode *head)
{
    if (head->next!=nullptr && head!=nullptr)
    {
        ListNode * middle=head;
        ListNode * tail=head;
        while (tail!=nullptr && tail->next!=nullptr)
        {
            middle=middle->next;
            tail=tail->next->next;
        }
        ListNode * middle_next=middle->next;
        middle->next=nullptr;
        ListNode* left=mergeSortList(head);
        ListNode* right=mergeSortList(middle_next);
        return mergeLists(left,right);
    }
    else return head;
    
}
int main()
{


}