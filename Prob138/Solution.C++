// Link To Problem:-
// https://leetcode.com/problems/copy-list-with-random-pointer/

// METHOD 1:-

// Time Complexity:-O(N).
// Space Complexity:-O(N).

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> relate;

        Node *temp = head;

        while (temp != NULL)
        {
            Node *temp2 = new Node(temp->val);
            relate[temp] = temp2;
            temp = temp->next;
        }

        temp = head;
        Node *res = relate[head];

        while (temp != NULL)
        {
            relate[temp]->next = relate[temp->next];
            relate[temp]->random = relate[temp->random];

            temp = temp->next;
        }

        return res;
    }
};

// METHOD 2:-

// Time Complexity:-O(N).
// Space Complexity:-O(1).

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *head_cp = nullptr, *curr = head, *curr_cp = nullptr;

        while (curr != nullptr)
        {
            curr_cp = new Node(curr->val, curr->next, nullptr);
            curr->next = curr_cp;
            curr = curr_cp->next;
        }

        curr = head;
        while (curr != nullptr)
        {
            curr_cp = curr->next;
            if (curr->random)
                curr_cp->random = curr->random->next;

            curr = curr_cp->next;
        }

        curr = head;
        head_cp = head->next;

        while (curr != nullptr)
        {
            curr_cp = curr->next;
            curr->next = curr_cp->next;
            curr = curr->next;
            if (curr)
                curr_cp->next = curr->next;
        }

        return head_cp;
    }
};