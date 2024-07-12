#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int maxGain(TreeNode* node, int& maxSum) {
    if (node == nullptr) return 0;

    int left = max(maxGain(node->left, maxSum), 0);
    int right = max(maxGain(node->right, maxSum), 0);

    int currentPathSum = node->val + left + right;

    maxSum = max(maxSum, currentPathSum);

    return node->val + max(left, right);
}
int maxPathSum(TreeNode* root) {
    int maxSum = INT_MIN;
    maxGain(root, maxSum);
    return maxSum;
}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    int result = maxPathSum(root);

    cout << "The maximum path sum is: " << result << endl;

    // Cleaning memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}