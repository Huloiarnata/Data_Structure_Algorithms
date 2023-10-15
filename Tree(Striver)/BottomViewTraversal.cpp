#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<set>

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
        Node* INSRT_BST(Node* curr, int key){
            if(curr==nullptr){
                return new Node(key);
            }
            if(key<curr->val){
                curr->left = INSRT_BST(curr->left, key);    
            }else if(key>curr->val){
                 curr->right = INSRT_BST(curr->right, key);
            }
            return curr;
        }
};

vector<int> BottomViewTraversal(Node* current){
    vector<int> res;
    if(current == nullptr){
        return res;
    }
    map<int, int> VisibleNodes;
    queue<pair<Node*, int> > ElementsQueue;

    ElementsQueue.push(make_pair(current,0));
    while(!ElementsQueue.empty()){
        pair<Node*, int> FrontNode = ElementsQueue.front();
        ElementsQueue.pop();

        Node* tempNode = FrontNode.first;
        int x = FrontNode.second;

        VisibleNodes[x] = tempNode->val;

        if(tempNode->left!=NULL){
            ElementsQueue.push(make_pair(tempNode->left, x-1));
        }
        if(tempNode->right!=NULL){
            ElementsQueue.push(make_pair(tempNode->right, x+1));
        }
    }

    map<int, int>:: iterator i;
    for(i=VisibleNodes.begin(); i!=VisibleNodes.end(); i++){
        res.push_back(i->second);
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
  
    cout<<"BottomViewOrder Traversal gives: "<<endl;
    vector<int> bottomViewOrderResult = BottomViewTraversal(tree.root);
    for(size_t i=0; i<bottomViewOrderResult.size(); i++){
            cout<<bottomViewOrderResult[i]<<" ";
    }
    return 0;
}