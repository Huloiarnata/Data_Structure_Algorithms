#include<iostream>
using namespace std;

// Can be done using recursion or level order search.
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val){
            data = val;
            left = nullptr;
            right = nullptr;
        }
};
class BinarySearchTree{
    public:
        TreeNode* root;
        BinarySearchTree(){
            root = nullptr;
        }
        void insert(int key){
            root = insertRecursive(root, key);
        }
        TreeNode* insertRecursive(TreeNode* current, int key){
            if(current == nullptr){
                return new TreeNode(key);
            }
            if(key<current->data){
                current->left = insertRecursive(current->left, key);
            }else if(key>current->data){
                current->right = insertRecursive(current->right, key);
            }
            return current;
        }
};
void inorderTraversal(TreeNode* root){
    if(root==nullptr){
        return ;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}
int maxHeight(TreeNode* root){
    if(root==nullptr){
        return 0;
    }else{
        return (1+max(maxHeight(root->left),maxHeight(root->right)));
    }
}



int main(void){
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
    int height = maxHeight(tree.root);
    cout<<"Maximum height of tree is: "<<height<<endl;
    return 0;
}