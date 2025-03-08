#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
 
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
Node* buildTreeFromInorderPreorder(
    int inStart, int inEnd, int& preIndex, int preorder[],
    unordered_map<int, int>& inorderIndexMap,
    bool& notPossible)
{
    if (inStart > inEnd)
        return NULL;
 
    // build the current Node
    int rootData = preorder[preIndex];
    Node* root = new Node(rootData);
    preIndex++;
 
    // find the node in inorderIndexMap
    if (inorderIndexMap.find(rootData)
        == inorderIndexMap.end()) {
        notPossible = true;
        return root;
    }
 
    int inorderIndex = inorderIndexMap[rootData];
    if (!(inStart <= inorderIndex
          && inorderIndex <= inEnd)) {
        notPossible = true;
        return root;
    }
 
    int leftInorderStart = inStart,
        leftInorderEnd = inorderIndex - 1,
        rightInorderStart = inorderIndex + 1,
        rightInorderEnd = inEnd;
 
    root->left = buildTreeFromInorderPreorder(
        leftInorderStart, leftInorderEnd, preIndex,
        preorder, inorderIndexMap, notPossible);
 
    if (notPossible)
        return root;
 
    root->right = buildTreeFromInorderPreorder(
        rightInorderStart, rightInorderEnd, preIndex,
        preorder, inorderIndexMap, notPossible);
 
    return root;
}
 
bool checkPostorderCorrect(Node* root, int& postIndex,
                           int postorder[])
{
    if (!root)
        return true;
 
    if (!checkPostorderCorrect(root->left, postIndex,
                               postorder))
        return false;
    if (!checkPostorderCorrect(root->right, postIndex,
                               postorder))
        return false;
 
    return (root->data == postorder[postIndex++]);
}
 

 
bool checktree(int preorder[], int inorder[],
               int postorder[], int N)
{
    
    if (N == 0)
        return true;
 
    unordered_map<int, int> inorderIndexMap;
    for (int i = 0; i < N; i++)
        inorderIndexMap[inorder[i]] = i;
 
    int preIndex = 0;
 
    
    bool notPossible = false;
 
    Node* root = buildTreeFromInorderPreorder(
        0, N - 1, preIndex, preorder, inorderIndexMap,
        notPossible);
 
    if (notPossible)
        return false;
 
    int postIndex = 0;
 
    return checkPostorderCorrect(root, postIndex,
                                 postorder);
}
 
// Driver program to test above functions
int main()
{
    int inOrder[] = { 4, 2, 5, 1, 3 };
    int preOrder[] = { 1, 2, 4, 5, 3 };
    int postOrder[] = { 4, 5, 2, 3, 1 };
 
    int len = sizeof(inOrder) / sizeof(inOrder[0]);
 
    // If both postorder traversals are same
    if (checktree(preOrder, inOrder, postOrder, len))
        cout << "Yes";
    else
        cout << "No";
 
    return 0;
}