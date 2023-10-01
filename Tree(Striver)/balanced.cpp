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
    }
    int leftHeight = maxHeight(root->left);
    if(leftHeight==-1){
        return -1;
    }
    int rightHeight = maxHeight(root->right);
    if(rightHeight==-1){
        return -1;
    }
    if(abs(leftHeight-rightHeight)>1){
        return -1;
    }else{
        return (1+max(leftHeight,rightHeight));
    }
}
bool isBalanced(TreeNode *root){
    return maxHeight(root)!=-1;
    
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
    bool status = isBalanced(tree.root);
    if(status==1){
        cout<<"Tree is balanced"<<endl;
    }else{
        cout<<"Tree isn't balanced"<<endl;
    }
    return 0;
}