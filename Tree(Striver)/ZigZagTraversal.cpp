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

//Zig-Zag Traversal.
vector< vector<int> > ZigZagTraversal(Node* current){
    vector< vector<int> >res;
    if(current==nullptr){
        return res;
    }
    queue<Node*> NodesQueue;
    NodesQueue.push(current);

    //Flag for ZigZag
    bool flag = true;
    while(!NodesQueue.empty()){
        int size = NodesQueue.size();
        vector<int> level(size);
        for(size_t i = 0; i<size; i++){
            Node* temp = NodesQueue.front();
            NodesQueue.pop();
            int index = flag?i:(size-1-i);
            level[index] = temp->data;
            if(temp->left){
                NodesQueue.push(temp->left);
            }
            if(temp->right){
                NodesQueue.push(temp->right);
            }
        }
        flag = !flag;
        res.push_back(level);
    }
    return res;

}
void pre(Node* root){
    if(root==nullptr){
        return;
    }
    cout<<(root->data)<< " ";
    pre(root->left);
    pre(root->right);
}

int main(){
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(10);
    cout<<"Level Order Traversal gives: "<<endl;
    vector< vector<int> > levelOrderResult = ZigZagTraversal(tree.root);
    for(size_t i=0; i<levelOrderResult.size(); i++){
        for(size_t j=0; j<levelOrderResult[i].size(); j++){
            cout<<levelOrderResult[i][j]<<" ";
        }
        cout<<endl;
    }
    pre(tree.root);
    return 0;
}