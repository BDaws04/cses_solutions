#include <iostream>
#include <algorithm>

struct TreeNode {
    int digit;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        digit = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* build_tree() {
    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(3);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);

    root->left->left->right = new TreeNode(2);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(9);

    root->right->left->right->left = new TreeNode(0);

    return root;
}


void build_paths(TreeNode* current, int current_path, int depth, int& max_val) {
    if (!current) return;

    current_path = current_path * 10 + current->digit;
    depth++;

    if (depth == 3) {
        max_val = std::max(max_val, current_path);
        return;
    }

    build_paths(current->left, current_path, depth, max_val);
    build_paths(current->right, current_path, depth, max_val);
}

int solve(TreeNode* root) {
    int max_val = 0;
    build_paths(root, 0, 0, max_val);
    return max_val;
}

int main() {
    TreeNode* root = build_tree();
    std::cout << solve(root) << std::endl;
    return 0;
}
