/*
Problem 12: Power Fault Isolation (Lowest Common Ancestor)
Scenario: A ventilator device distributes power through a hierarchical tree of controllers. The main battery is the root node. It splits power to sub-controllers, which split power to individual sensors and motors.

If two different components (nodes) report a voltage drop at the exact same time, the firmware needs to find their "Lowest Common Ancestor" (LCA)—the deepest power controller in the tree that feeds both failing components—to identify the root hardware failure.

Requirements:

Write a function findFaultOrigin(TreeNode* root, TreeNode* p, TreeNode* q).

Given a binary tree, find the lowest common ancestor of nodes p and q.

The LCA is defined between two nodes p and q as the lowest node in the tree that has both p and q as descendants (where we allow a node to be a descendant of itself).

All Node.val are unique.

p and q will exist in the tree.
*/

#include <iostream>
#include <stack>

// Standard C++ Binary Tree Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findStack(TreeNode* node, TreeNode* p, std::stack<TreeNode*>&stack)
{
    stack.push(node);
    if (node->val == p->val)
    {
        return;
    }
    if (node->left != nullptr)
    {
        findStack(node->left, p, stack);
    }
    if (node->right != nullptr)
    {
        findStack(node->right, p, stack);
    }
    stack.pop();
}

TreeNode* findFaultOrigin(TreeNode* root, TreeNode* p, TreeNode* q) {
    // TODO: Implement your solution here.
    
    std::stack<TreeNode*> p_stack;
    std::stack<TreeNode*> q_stack;
    findStack(root,p,p_stack);
    findStack(root,q,q_stack);

    std::stack<TreeNode*>& temp_stack = p_stack.size() > q_stack.size() ? p_stack  : q_stack;
    while(p_stack.size()!=q_stack.size())
        temp_stack.pop();

    while(p_stack.top() != q_stack.top())
    {
        p_stack.pop();
        q_stack.pop();
    }

    return p_stack.top();
}

TreeNode* findFaultOrigin2(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 1. Base Cases: If we hit the bottom, or if we find one of the targets, return it.
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    // 2. Search down the left and right branches
    TreeNode* left_result = findFaultOrigin(root->left, p, q);
    TreeNode* right_result = findFaultOrigin(root->right, p, q);

    // 3. If BOTH sides returned a node, this current root MUST be the common ancestor!
    if (left_result != nullptr && right_result != nullptr) {
        return root;
    }

    // 4. Otherwise, pass up whatever we found (either left, right, or nullptr)
    return left_result != nullptr ? left_result : right_result;
}

// --- Helper code for local testing ---
int main() {
    /* Power Tree Visualization:
             (3) -> Root
            /   \
          (5)   (1)
         /  \   /  \
       (6) (2)(0)  (8)
          /  \
        (7)  (4)
    */
    
    // Building the tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p1 = root->left;        // Node 5
    TreeNode* q1 = root->right;       // Node 1
    std::cout << "Test 1 (Expected 3): " << findFaultOrigin(root, p1, q1)->val << std::endl;

    TreeNode* p2 = root->left;        // Node 5
    TreeNode* q2 = root->left->right->right; // Node 4
    std::cout << "Test 2 (Expected 5): " << findFaultOrigin(root, p2, q2)->val << std::endl;

    return 0;
}