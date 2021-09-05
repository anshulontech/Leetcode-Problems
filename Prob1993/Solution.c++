// Link To Problem:-
// https://leetcode.com/problems/operations-on-tree/

// Solution:-

class tree
{
public:
    int val;
    vector<tree *> child;
    bool isLocked;
    int lockedByUser;

    tree(int x)
    {
        val = x;
        isLocked = false;
        lockedByUser = -1;
    }
};

class LockingTree
{
private:
    tree *node = new tree(0);
    unordered_map<int, tree *> m;

public:
    LockingTree(vector<int> &parent)
    {
        int n = parent.size();
        m.insert({0, node});
        for (int i = 1; i < n; i++)
        {
            tree *child, *par;
            if (m.find(parent[i]) != m.end())
                par = m[parent[i]];
            else
            {
                par = new tree(parent[i]);
                m.insert({parent[i], par});
            }
            if (m.find(i) != m.end())
                child = m[i];
            else
            {
                child = new tree(i);
                m.insert({i, child});
            }

            par->child.push_back(child);
        }
    }

    bool lock(int num, int user)
    {
        tree *currNode = m[num];

        if (currNode->isLocked)
            return false;

        currNode->isLocked = true;
        currNode->lockedByUser = user;

        return true;
    }

    bool unlock(int num, int user)
    {
        tree *currNode = m[num];

        if (currNode->isLocked == false || currNode->lockedByUser != user)
            return false;
        currNode->isLocked = false;
        currNode->lockedByUser = -1;

        return true;
    }

    bool upgrade(int num, int user)
    {
        tree *currNode = m[num];

        if (currNode->isLocked)
            return false;
        bool isLocChild = false;
        for (auto x : currNode->child)
            if (isLockedChild(x))
            {
                isLocChild = true;
                break;
            }

        if (!isLocChild)
            return false;

        vector<tree *> ans;

        ans.push_back(node);

        for (auto x : node->child)
        {
            ans.push_back(x);
            if (getAns(x, num, ans))
                break;
            ans.pop_back();
        }

        for (auto x : ans)
            if (x->isLocked == true)
                return false;

        for (auto x : currNode->child)
            unlockChild(x);

        currNode->isLocked = true;
        currNode->lockedByUser = user;

        return true;
    }

    void unlockChild(tree *currNode)
    {
        currNode->isLocked = false;
        for (auto x : currNode->child)
            unlockChild(x);
    }

    bool isLockedChild(tree *currNode)
    {
        if (currNode->isLocked)
            return true;

        for (auto x : currNode->child)
            if (isLockedChild(x))
                return true;

        return false;
    }

    bool getAns(tree *currNode, int num, vector<tree *> &ans)
    {
        if (currNode->val == num)
            return true;

        for (auto x : currNode->child)
        {
            ans.push_back(x);
            if (getAns(x, num, ans))
                return true;
            ans.pop_back();
        }

        return false;
    }
};
