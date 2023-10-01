#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
class Node{
    public:
        int val;
        Node* left;
        Node* right;
    public:
        Node(int key){
            val = key;
            left = nullptr;
            right = nullptr;
        }
};

class BST{
    public:
        Node *root;
    public:
        BST(){
            root = nullptr;
        }
        void insert(int key){
            root = INST_BST(root, key);
        }
        Node* INST_BST(Node* curr, int key){
            if(curr==nullptr){
                return new Node(key);
            }
            if(key<curr->val){
                curr->left = INST_BST(curr->left, key);
            }else if(key>curr->val){
                curr->right = INST_BST(curr->right, key);
            }
            return curr;
        }
};

bool isLeaf(Node* curr){
    if(!curr->left && !curr->right){
        return true;
    }
    return false;
}

void addLeftBoundry(Node* curr, vector<int>& res){
    Node* tmp = curr->left;
    if(!isLeaf(tmp)){
        res.push_back(tmp->val);
    }
    if(tmp->left){
        tmp = tmp->left;
    }
    tmp = tmp->right;

}
void addRightBoundry(Node* curr, vector<int>& res){
    Node* tmp = curr->right;
    stack<int> Stack;
    while(tmp){
        if(!isLeaf(tmp)){
            Stack.push(tmp->val);
        }
        if(tmp->right){
            tmp = tmp->right;
        }else{
            tmp = tmp->left;
        }
    }
    while(!Stack.empty()){
        res.push_back(Stack.top());
        Stack.pop();
    }

}
void addleaf(Node* curr, vector<int>& res){
    if(isLeaf(curr)){
        res.push_back(curr->val);
        return;
    }
    if(curr->left){
        addleaf(curr->left, res);
    }
    if(curr->right){
        addleaf(curr->right, res);
    }
}
vector<int> BoundryTraversal(Node* root){
    vector<int> result;
    if(!root){
        return result;
    }
    if(!isLeaf(root)){
        result.push_back(root->val);
    }
    addLeftBoundry(root, result);
    addleaf(root, result);
    addRightBoundry(root, result);
    return result;
}

int main(void){
    BST tree;
    tree.insert(100);
    tree.insert(20);
    tree.insert(200);
    tree.insert(10);
    tree.insert(30);
    tree.insert(150);
    tree.insert(300);
    vector<int> boundryElements = BoundryTraversal(tree.root);
    vector<int>::iterator i;
    for(i = boundryElements.begin(); i!=boundryElements.end(); i++){
        cout<<*i<<" ";
    }
    return 0;
}
