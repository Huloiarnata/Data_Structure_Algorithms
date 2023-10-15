#include<iostream>
#include <queue>
#include<map>
#include<set>
#include<vector>

using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;
    public:
        Node(int key){
            val = key;
        }

};
class BST{
    public:
        Node* root;
    public:
        BST(){
            root = nullptr;
        }
        void insert(int key){
            root = INSRT_BST(root, key);
        }
        Node* INSRT_BST(Node* current, int key){
            if(current==nullptr){
                return new Node(key);
            }
            if(key<current->val){
                current->left = INSRT_BST(current->left, key);
            }else if(key>current->val){
                current->right = INSRT_BST(current->right, key);
            }
            return current;
        }
};

vector<int> TopViewTraversal(Node* current){
    vector<int> res;
    if(current == nullptr){
        return res;
    }
    map<int, int> VisibleNodes;
    queue<pair<Node*, int> > NodesQueue;
    NodesQueue.push(make_pair(current, 0));

    while(!NodesQueue.empty()){
        pair<Node*, int> FrontNode = NodesQueue.front();
        NodesQueue.pop();

        Node* TmpNode = FrontNode.first;
        int x = FrontNode.second;

        if(VisibleNodes.find(x)==VisibleNodes.end()){
            VisibleNodes[x] = TmpNode->val;
        }

        if(TmpNode->left!=nullptr){
            NodesQueue.push(make_pair(TmpNode->left, x-1));
        }if(TmpNode->right!=nullptr){
            NodesQueue.push(make_pair(TmpNode->right, x+1));
        }
    }

    map<int, int> :: iterator it;
    for(it = VisibleNodes.begin(); it!= VisibleNodes.end(); it++){
        res.push_back(it->second);
    }
    return res;
}

int main(){
    BST tree;
    tree.insert(100);
    tree.insert(20);
    tree.insert(200);
    tree.insert(10);
    tree.insert(30);
    tree.insert(150);
    tree.insert(300);
  
    cout<<"TopViewOrder Traversal gives: "<<endl;
    vector<int> topViewOrderResult = TopViewTraversal(tree.root);
    for(size_t i=0; i<topViewOrderResult.size(); i++){
            cout<<topViewOrderResult[i]<<" ";
    }
    return 0;
}