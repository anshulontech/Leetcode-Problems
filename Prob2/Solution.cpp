#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *formList();

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(0);

        ListNode *p = l1, *q = l2, *curr = dummy;

        int carry = 0;

        while (p != nullptr || q != nullptr)
        {
            int x = p != nullptr ? p->val : 0;
            int y = q != nullptr ? q->val : 0;

            int sum = carry + x + y;

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;

            p != nullptr ? p = p->next : p;
            q != nullptr ? q = q->next : q;
        }

        if (carry > 0)
            curr->next = new ListNode(carry);

        return dummy->next;
    }
};

int main() {
    ListNode* head1=formList();
    ListNode* head2=formList();

    Solution result;

    ListNode* ans = result.addTwoNumbers(head1,head2);

    cout<<"The Sum of the Given Numbers is :-"<<endl;

    while(ans!=nullptr) {
        cout<<ans->val;
        ans=ans->next;
    }

    return 0;
}

ListNode* formList() {
    cout<<"Enter NUmber of Elements in the list :";
    int n;
    cin>>n;

    ListNode* dummy=new ListNode();
    ListNode* temp=dummy;

    cout<<"Enter the Values of the list:"<<endl;

    while(n) {
        int value ;
        cin>>value ;

        temp->next=new ListNode(value);
        temp=temp->next;
        n--;
    }

    return dummy->next;
}