#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// Structure of node.
typedef struct Node{
    int data;
    Node *left;
    Node *right;
};
// Insertion to binary search tree.
Node* InsertTOBinarySearchTree(Node *root, int data){
    if(root==nullptr){
        root = (Node *)malloc(sizeof(Node));
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
    }
    if(data < root->data){
        root->left = InsertTOBinarySearchTree(root->left, data);
    }
    else if(data > root->data){
        root->right = InsertTOBinarySearchTree(root->right, data);
    }
    return root;
}

// Traversal of binary search tree in INORDER fashion.
void InorderTraversal(Node *root){
    if(root==nullptr){
        return;
    }
    InorderTraversal(root->left);   

    printf("%d ", root->data);
    
    InorderTraversal(root->right);
}
// Traversal of binary search tree in INORDER fashion.
void preorderTraversal(Node *root){
    if(root==nullptr){
        return;
    }
    printf("%d ", root->data);

    preorderTraversal(root->left);   
    
    preorderTraversal(root->right);
}
// Traversal of binary search tree in INORDER fashion.
void postorderTraversal(Node *root){
    if(root==nullptr){
        return;
    }
    postorderTraversal(root->left);   
    
    postorderTraversal(root->right);

    printf("%d ", root->data);
}

// Level Order traversal.
vector<vector<int> > levelOrderTraversal(Node *root){
    vector<vector<int> > res;
    if(root ==NULL){
        return res;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i =0; i<size; i++){
            Node* tmp = q.front();
            q.pop();
            if(tmp->left!=NULL){
                q.push(tmp->left);
            }
            if(tmp->right!=NULL){
                q.push(tmp->right);
            }
            level.push_back(tmp->data);
        }
        res.push_back(level);
    }
    return res;

}
// Main function
int main(){
    Node* root = NULL;
    root = InsertTOBinarySearchTree(root, 100);
    InsertTOBinarySearchTree(root, 20);
    InsertTOBinarySearchTree(root, 200);
    InsertTOBinarySearchTree(root, 10);
    InsertTOBinarySearchTree(root, 30);
    InsertTOBinarySearchTree(root, 150);
    InsertTOBinarySearchTree(root, 300);

    cout<<"Printing in Inorder fashion: ";
    InorderTraversal(root);
    cout<<endl;
    cout<<"Printing in preorder fashion: ";
    preorderTraversal(root);
    cout<<endl;
    cout<<"Printing in postorder fashion: ";
    postorderTraversal(root);
    cout<<endl;
    cout<<"Printing in levels order fashion: ";
    vector<vector<int> > ans = levelOrderTraversal(root);

    for(size_t i = 0; i<ans.size(); ++i){
        for(size_t j = 0; j<ans[i].size();++j){
            cout<<ans[i][j]<<" ";
        }
    }
    cout<<endl;
    return 0;
}