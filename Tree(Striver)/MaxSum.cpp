#include<iostream>
using namespace std;

//Blueprint of Node.
class TreeNode{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
    public:
        TreeNode(int key){
            data = key;
        }
};

//binary search tree
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
        TreeNode* InsertIntoBST(TreeNode *current, int key){
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

//traversal
void inorderTraversal(TreeNode* current){
    if(current==nullptr){
        return;
    }
    inorderTraversal(current->left);
    cout<<current->data<<" ";
    inorderTraversal(current->right);
}

//max-sum.
int MaxSum(TreeNode* current, int& maximum){
    if(current==nullptr){
        return 0;
    }
    int leftSum = max(0,MaxSum(current->left, maximum));
    int rightSum = max(0,MaxSum(current->right, maximum));

    maximum = max(maximum, current->data+leftSum+rightSum);

    return max(leftSum,rightSum)+current->data;

}

//main
int main(void){
    BinarySearchTree tree;

    //Inserting in BST.
    tree.insert(100);
    tree.insert(20);
    tree.insert(200);
    tree.insert(10);
    tree.insert(30);
    tree.insert(150);
    tree.insert(300);

    //Printing in inorder fashion.
    cout<<"Inorder Traversal: ";
    inorderTraversal(tree.root);
    cout<<endl;

    //printing max sum.
    int maximum = 0;
    MaxSum(tree.root, maximum);
    cout<<"Max-Sum is :"<<maximum<<endl;
    return 0;
}