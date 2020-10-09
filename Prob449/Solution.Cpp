// Approach 1:-

class Codec
{
public:
    string serialize(TreeNode *root)
    {
        if (root == NULL)
            return "-1";

        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    TreeNode *deserialize(string data)
    {
        queue<int> q;
        buildQueue(data, q);

        return helper_deserialize(q);
    }

    void buildQueue(string &s, queue<int> &q)
    {
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < s.size() && s[j] != ',')
                j++;

            q.push(stoi(s.substr(i, j - i)));
            i = j;
        }
        return;
    }

    TreeNode *helper_deserialize(queue<int> &q)
    {
        if (q.front() == (-1))
        {
            q.pop();
            return nullptr;
        }

        TreeNode *node = new TreeNode(q.front());
        q.pop();
        node->left = helper_deserialize(q);
        node->right = helper_deserialize(q);

        return node;
    }
};