// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/

// Time Complexity:-O(N).
// Space Complexity:-O(N).
    
// Approach:-
//     In this what we are going to do is that we will store the prefix Sum of all the nodes in a unordered_map with 
// the last node they belongs to. Now we will again iterate the List and if we will found any prefix Sum occur in the 
// map we will set the next pointer of that node to the corresponding node and move forward. As we know all prefix Sum 
// exist in the list so if the prefiSum exist to remve the value than we can undersatnd it but what if that node will 
// not be removed frm the sln . So for this case the sln works because for that case it will assign the next of the 
// current node to it's already existing next node and hence no problem will arrise.

class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        int prefixSum = 0;

        unordered_map<int, ListNode *> store;
        ListNode *temp = dummy;
        while (temp != NULL)
        {
            prefixSum += temp->val;
            store[prefixSum] = temp;

            temp = temp->next;
        }

        prefixSum = 0;

        temp = dummy;

        while (temp != NULL)
        {
            prefixSum += temp->val;
            temp->next = store[prefixSum]->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};