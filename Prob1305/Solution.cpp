// Approach 1:-

class Solution
{
private:
    vector<int> res;

public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        traversal(root1);
        traversal(root2);

        sort(res.begin(), res.end());

        return res;
    }

    void traversal(TreeNode *root)
    {
        if (root == NULL)
            return;

        res.push_back(root->val);
        traversal(root->left);
        traversal(root->right);
    }
};

// Approach 2:-

class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> first, second, res;
        inorder(root1, first);
        inorder(root2, second);

        merge_arrays(res, first, second);

        return res;
    }

    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    void merge_arrays(vector<int> &res, vector<int> &first, vector<int> &second)
    {
        int i = 0, j = 0;

        while (i < first.size() && j < second.size())
        {
            if (first[i] <= second[j])
                res.push_back(first[i++]);
            else
                res.push_back(second[j++]);
        }

        while (i < first.size())
            res.push_back(first[i++]);

        while (j < second.size())
            res.push_back(second[j++]);
    }
};

// Approach 3:-

class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        stack<TreeNode *> S1, S2;
        vector<int> res;

        TreeNode *temp = root1;

        while (temp != NULL)
        {
            S1.push(temp);
            temp = temp->left;
        }

        temp = root2;

        while (temp != NULL)
        {
            S2.push(temp);
            temp = temp->left;
        }

        TreeNode *top;

        while (!S1.empty() && !S2.empty())
            if (S1.top()->val <= S2.top()->val)
            {
                top = S1.top();
                S1.pop();
                res.push_back(top->val);
                top = top->right;

                while (top)
                {
                    S1.push(top);
                    top = top->left;
                }
            }
            else
            {
                top = S2.top();
                S2.pop();
                res.push_back(top->val);
                top = top->right;

                while (top)
                {
                    S2.push(top);
                    top = top->left;
                }
            }

        while (!S1.empty())
        {
            top = S1.top();
            S1.pop();
            res.push_back(top->val);
            top = top->right;

            while (top)
            {
                S1.push(top);
                top = top->left;
            }
        }

        while (!S2.empty())
        {
            top = S2.top();
            S2.pop();
            res.push_back(top->val);
            top = top->right;

            while (top)
            {
                S2.push(top);
                top = top->left;
            }
        }

        return res;
    }
};