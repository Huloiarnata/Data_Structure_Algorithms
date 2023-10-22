#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Blueprint of Tree Node.
class Node{
    public:
        int data;
        Node* right;
        Node* left;
    public:
        Node(int key){
            data = key;
            left = nullptr;
            right = nullptr;
        }
};

//Insertion according to BSt rules.
class BST{
    public:
        Node* root;
    public:
        BST(){
            root = nullptr;
        }
        void insert(int key){
            root = InsertBST(root, key);
        }
        Node* InsertBST(Node* current, int key){
            if(current==nullptr){
                return new Node(key);
            }
            if(key<current->data){
                current->left = InsertBST(current->left, key);
            }
            else if(key>current->data){
                current->right = InsertBST(current->right, key);
            }
            return current;
        }
};

//Level Order Traversal.
vector< vector<int> > LevelOrderTraversal(Node* current){
    vector< vector<int> > res;
    if(current==nullptr){
        return res;
    }

    queue<Node*> ElementQueue;
    ElementQueue.push(current);

    while(!ElementQueue.empty()){
        int size = ElementQueue.size();
        vector<int> levelElement;
        for(int i=0; i<size; i++){

            Node* tmp = ElementQueue.front();
            ElementQueue.pop();
            
            if(tmp->left!=NULL){
                ElementQueue.push(tmp->left);
            }
            if(tmp->right!=NULL){
                ElementQueue.push(tmp->right);
            }
            levelElement.push_back(tmp->data);
        }
        res.push_back(levelElement);
    }
    return res;
}

//Main.
int main(){
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(10);
    cout<<"Level Order Traversal gives: "<<endl;
    vector< vector<int> > levelOrderResult = LevelOrderTraversal(tree.root);
    for(size_t i=0; i<levelOrderResult.size(); i++){
        for(size_t j=0; j<levelOrderResult[i].size(); j++){
            cout<<levelOrderResult[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

