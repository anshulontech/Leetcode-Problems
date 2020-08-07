// Approach 1:-(DFS)

class Solution {
private:
    map<int, map<int, set<int>>> store;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        traverse(root, 0, 0);
        vector<vector<int>> res;

        for (auto p:store) {
            vector<int> col;
            for (auto q:p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());

            res.push_back(col);
        }

        return res;
    }

    void traverse(TreeNode* root, int x, int y) {
        if (root) {
            store[x][y].insert(root->val);
            traverse(root->left, x-1, y+1);
            traverse(root->right, x+1, y+1);
        }
    }
};

// Approach 2:-(BFS)

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, set<int>>> store;
        queue<pair<TreeNode*, pair<int, int>>> todo;

        todo.push({ root, { 0, 0 } });

        while (!todo.empty()) {
            auto p=todo.front();
            todo.pop();
            TreeNode* node=p.first;
            int x=p.second.first, y=p.second.second;
            store[x][y].insert(node->val);
            if (node->left)
                todo.push({ node->left, { x-1, y+1 } });
            if (node->right)
                todo.push({ node->right, { x+1, y+1 } });
        }


        vector<vector<int>> res;

        for (auto p:store) {
            vector<int> col;
            for (auto q:p.second)
                col.insert(col.end(), q.second.begin(), q.second.end());

            res.push_back(col);
        }

        return res;
    }
};