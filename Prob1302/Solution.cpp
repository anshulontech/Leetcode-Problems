// Approach 1:-

class Solution {
private:
    int max_depth=-1;
    int sum=0;
public:
    int deepestLeavesSum(TreeNode* root) {
        int depth=0;
        traverse(root, depth);

        return sum;
    }

    void traverse(TreeNode* root, int& depth) {
        if (root==NULL)
            return;

        if (root->left==NULL && root->right==NULL)
            if (depth>max_depth) {
                max_depth=depth;
                sum=root->val;
            }
            else
                if (depth==max_depth)
                    sum+=root->val;
        depth++;
        traverse(root->left, depth);
        traverse(root->right, depth);
        depth--;
    }
};