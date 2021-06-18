// Link To Problem:-
// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

// METHOD 1:-

class Solution
{
public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> store;
        ListNode *temp = head;
        while (temp)
        {
            store.push_back(temp->val);
            temp = temp->next;
        }

        return ConvertToBST(store, 0, store.size() - 1);
    }

    TreeNode *ConvertToBST(vector<int> &store, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode *root = new TreeNode(store[mid]);

        root->left = ConvertToBST(store, start, mid - 1);
        root->right = ConvertToBST(store, mid + 1, end);

        return root;
    }
};

// METHOD 2:-

class Solution
{
private:
    ListNode *root;

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        int size = 0;
        root = head;
        ListNode *temp = head;
        while (temp)
        {
            size++;
            temp = temp->next;
        }

        return convertListToBST(0, size - 1);
    }

    TreeNode *convertListToBST(int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;

        TreeNode *left = convertListToBST(start, mid - 1);
        TreeNode *node = new TreeNode(root->val);
        node->left = left;

        root = root->next;

        node->right = convertListToBST(mid + 1, end);

        return node;
    }
};