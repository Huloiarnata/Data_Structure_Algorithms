#include<iostream>
using namespace std;

//Node Blueprint.
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    public:
        Node(int key){
            data = key;
            left = nullptr;
            right = nullptr;
        }
};

//Binary Search Tree.
class BST{
    public:
        Node *root;
        BST(){
            root = nullptr;
        }
    public:
        void insert(int key){
            root = InsertBST(root, key);
        }
        Node* InsertBST(Node* root, int key){
            if(root == nullptr){
                return new Node(key);
            }
            if(key<root->data){
                root->left = InsertBST(root->left, key);
            }else if(key>root->data){
                root->right = InsertBST(root->right, key);
            }
            return root;
        }
};

bool isIdentical(Node* root1, Node* root2){
    if(root1==nullptr && root2==nullptr){
        return (root1==root2);
    }
    return (root1->data == root2->data)
        &&isIdentical(root1->left,root2->left)
        &&isIdentical(root1->right,root2->right);
}

int main(void){
    BST tree1;
    tree1.insert(100);
    tree1.insert(20);
    tree1.insert(200);
    BST tree2;
    tree2.insert(100);
    tree2.insert(20);
    tree2.insert(210);
    if(isIdentical(tree1.root, tree2.root)){
        cout<<"Identical"<<endl;
    }else{
        cout<<"Not Identical"<<endl;
    }
    return 0;
}

