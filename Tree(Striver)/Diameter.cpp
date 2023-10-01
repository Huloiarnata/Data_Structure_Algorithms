#include<iostream>
using namespace std;
// Structure of Tree Node.
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode(int key){
            data = key;
            left = nullptr;
            right = nullptr;
        }
};

// Operation for inserting and forming binary search tree.
class BinarySearchTree{
    public:
        TreeNode* root;
    public:
        BinarySearchTree(){
            root = nullptr;
        }
        void insert(int key){
            root = InsertIntoBST(root, key);
        }
    private:
        TreeNode* InsertIntoBST(TreeNode* current, int key){
            if(current == nullptr){
                return new TreeNode(key);
            }
            if(key<current->data){
                current->left = InsertIntoBST(current->left, key);
            }else if(key>current->data){
                current->right = InsertIntoBST(current->right, key);
            }
            return current;
        }
};

//traversing the tree.
void inorderTraversal(TreeNode* root){
    if(root==nullptr){
        return ;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

// Diameter(longest path between two leaf nodes) function.
int DiameterOfTree(TreeNode* current, int& diameter){
    if(current == nullptr){
        return 0;
    }
    int lh = DiameterOfTree(current->left, diameter);
    int rh = DiameterOfTree(current->right, diameter);
    diameter = max(diameter, 1+lh+rh);
    return 1+max(lh,rh);
}

//main function.
int main(){
    BinarySearchTree tree;
    tree.insert(100);
    tree.insert(20);
    tree.insert(200);
    tree.insert(10);
    tree.insert(30);
    tree.insert(150);
    tree.insert(300);

    cout<<"Inorder Traversal: ";
    inorderTraversal(tree.root);
    cout<<endl;
    int diameter = 0;
    DiameterOfTree(tree.root, diameter);
    cout<<"Diameter of tree is: "<<diameter<<endl;
    return 0;
}