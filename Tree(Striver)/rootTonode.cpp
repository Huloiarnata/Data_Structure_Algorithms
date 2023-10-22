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
// getting path.
bool getPath(Node* curr, vector<int>&ans, int target){
    if(!curr){
        return false;
    }
    ans.push_back(curr->data);

    if(curr->data == target){
        return true;
    }
    
    if((getPath(curr->left, ans, target)) || (curr->right, ans, target)){
        return true;
    }
    ans.pop_back();
    return false;
}
// root to node target.
vector<int> pathFinder(Node* curr, int target){
    vector<int> result;
    if(curr == nullptr){
        return result;
    }
    getPath(curr, result, target);
    return result;
}

//Main.
int main(){
    BST tree;
    tree.insert(100);
    tree.insert(20);
    tree.insert(200);
    tree.insert(10);
    tree.insert(30);
    tree.insert(150);
    tree.insert(300);
    cout<<"Root to Node Path is: "<<endl;
    vector<int> ans = pathFinder(tree.root, 50);
    vector<int> :: iterator i;
    for(i=ans.begin(); i<ans.end(); i++){
        cout<< *i << " ";
    }
    cout<<endl;
    return 0;
}

