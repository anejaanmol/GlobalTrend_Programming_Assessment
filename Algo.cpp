#include <bits/stdc++.h>
using namespace std;

// Defining BT
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


string serialize(TreeNode* root) {
    if (!root) return "#";
    
    ostringstream out;
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node) {
            out << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            out << "# ";
        }
    }
    
    return out.str();
}

TreeNode* deserialize(const std::string& data) {
    if (data == "#") return nullptr;
    
    std::istringstream in(data);
    std::string val;
    in >> val;
    
    TreeNode* root = new TreeNode(std::stoi(val));
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (!(in >> val)) break;
        if (val != "#") {
            node->left = new TreeNode(std::stoi(val));
            q.push(node->left);
        }
        
        if (!(in >> val)) break;
        if (val != "#") {
            node->right = new TreeNode(std::stoi(val));
            q.push(node->right);
        }
    }
    
    return root;
}

void printTree(TreeNode* root) {
    if (!root) return;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (node) {
            std::cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            std::cout << "# ";
        }
    }
    cout << endl;
}

int main() {
    // Creating Sample tree :- [1, 2, 3, #, #, 4, 5]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serializing
    std::string serialized = serialize(root);
    std::cout << "Serialized tree: " << serialized << std::endl;

    // Deserializing
    TreeNode* deserializedRoot = deserialize(serialized);
    std::cout << "Deserialized tree (level order): ";
    printTree(deserializedRoot);

    // Cleaning memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
