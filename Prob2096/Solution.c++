// Link To Problem:-
// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

// Solution:-

class Solution
{
public:
    string getDirections(TreeNode *root, int s, int e)
    {
        string res = "";
        stack<char> st;

        bool isS = false;

        dfsPre(root, s, e, st, isS, res);

        if (res != "")
            return res;

        while (!st.empty())
            st.pop();

        isS = false;

        dfsPost(root, s, e, st, isS, res);

        return res;
    }

    void dfsPre(TreeNode *root, int s, int e, stack<char> &st, bool &isS, string &res)
    {
        if (!root)
            return;

        if (root->val == s)
        {
            isS = true;
        }

        if (!isS && root->val == e)
            return;

        if (res.size() == 0 && isS && root->val == e)
        {
            while (!st.empty())
            {
                res += st.top();
                st.pop();
            }

            reverse(res.begin(), res.end());

            for (auto x : res)
                st.push(x);

            return;
        }

        if (isS)
        {
            st.push('L');
            dfsPre(root->left, s, e, st, isS, res);
            while (st.top() != 'L')
                st.pop();
            st.pop();
        }
        else
            dfsPre(root->left, s, e, st, isS, res);

        if (isS)
        {
            st.push('R');
            dfsPre(root->right, s, e, st, isS, res);
            while (st.top() != 'R')
                st.pop();
            st.pop();
        }
        else
            dfsPre(root->right, s, e, st, isS, res);

        if (res.size() == 0 && isS && root->val == e)
        {
            while (!st.empty())
            {
                res += st.top();
                st.pop();
            }

            reverse(res.begin(), res.end());

            for (auto x : res)
                st.push(x);

            return;
        }

        if (isS)
            st.push('U');
    }

    void dfsPost(TreeNode *root, int s, int e, stack<char> &st, bool &isS, string &res)
    {
        if (!root)
            return;

        if (root->val == s)
        {
            isS = true;
        }

        // if(!isS && root->val==e) return;

        if (res.size() == 0 && isS && root->val == e)
        {
            while (!st.empty())
            {
                res += st.top();
                st.pop();
            }

            reverse(res.begin(), res.end());

            for (auto x : res)
                st.push(x);
        }

        if (isS)
        {
            st.push('R');
            dfsPost(root->right, s, e, st, isS, res);
            while (st.top() != 'R')
                st.pop();
            st.pop();
        }
        else
            dfsPost(root->right, s, e, st, isS, res);

        if (isS)
        {
            st.push('L');
            dfsPost(root->left, s, e, st, isS, res);
            while (st.top() != 'L')
                st.pop();
            st.pop();
        }
        else
            dfsPost(root->left, s, e, st, isS, res);

        if (res.size() == 0 && isS && root->val == e)
        {
            while (!st.empty())
            {
                res += st.top();
                st.pop();
            }

            reverse(res.begin(), res.end());

            for (auto x : res)
                st.push(x);
        }

        if (isS)
            st.push('U');
    }
};