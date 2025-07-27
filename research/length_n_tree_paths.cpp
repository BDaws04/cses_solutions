/*
I remember last cyle receieving a tree question like this: (DRW)
- exists a binary tree with * to left + right (could be null) && an int digit(0-9)
- find largest size 3 digit num
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct TreeNode{
    int digit;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
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

void build_paths(int& max, int& current_path, TreeNode* current){

    if (!current) return;

    current_path *= 10;
    current_path += current->digit;

    if (current_path >= 100 && current_path < 1000){
        max = std::max(max, current_path);
    }
    else {
        build_paths(max, current_path, current->left);
        build_paths(max, current_path, current->right);
    }

    current_path /= 10;
}

int solve(TreeNode* root){
    int max = 0;
    std::queue<TreeNode*> q;
    if (!root){
        return -1;
    }
    q.push(root);
    while (!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        int c = 0;
        build_paths(max, c, current);
        if (current->left){
            q.push(current->left);
        }
        if (current->right){
            q.push(current->right);
        }
    }
    return max;
}

int main () {

    TreeNode* root = build_tree();
    std::cout << solve(root) << std::endl;

    return 0;

}