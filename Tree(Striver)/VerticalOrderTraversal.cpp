#include<iostream>
#include<map>
#include<vector>
#include<queue>
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
            left = nullptr;
            right = nullptr;
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
                curr->right= INSRT_BST(curr->right, key);
            }
            return curr;
        }
};
vector< vector<int> > verticalTraversal(Node* current){
    map<int, map<int, multiset<int> > > nodes;
    queue< pair<Node*, pair<int, int> > > NodeQueue;
    NodeQueue.push(make_pair(current, make_pair(0, 0)));
   // NodeQueue.push({current, {0,0}});
    while(!NodeQueue.empty()){

        // storing front element of queue.
        pair<Node*, pair<int, int> > FrontQueueElement = NodeQueue.front(); 
        //auto FrontQueueElement = NodeQueue.front();

        // removing the element out of queue.
        NodeQueue.pop();

        //preparing for map nodes.
        Node* TmpNode = FrontQueueElement.first;
        int x = FrontQueueElement.second.first;
        int y = FrontQueueElement.second.second;

        //pushing into the map nodes.
        //remember y is multiset hence can take same values.
        nodes[x][y].insert(TmpNode->val);
        //inserting Nodes in queue in level order manner managinf the x and y coordinates of the nodes.
        if(TmpNode->left){
            //x-1: as we go left we are moving from root in negative side direction.
            //y+1: as we look for left and right nodes we are moving a level ahead.
            NodeQueue.push(make_pair(TmpNode->left, make_pair(x-1, y+1)));
        }
        if(TmpNode->right){
            //x+1: as we go left we are moving from root in positive side direction.
            //y+1: as we look for left and right nodes we are moving a level ahead.
            NodeQueue.push(make_pair(TmpNode->right, make_pair(x+1,y+1)));
        }
    }

    // final response structure.
    vector< vector<int> > ans;

    map<int, map<int, multiset<int> > >::iterator it;
    for ( it = nodes.begin(); it != nodes.end(); ++it) {
    vector<int> col;
    map<int, multiset<int> >::iterator inner_it;
    for ( inner_it = it->second.begin(); inner_it != it->second.end(); ++inner_it) {

        col.insert(col.end(), inner_it->second.begin(), inner_it->second.end());
    }
    ans.push_back(col);
    }


    return ans;
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
    cout<<"Verticle Order Traversal gives: "<<endl;
    vector< vector<int> > verticalOrderResult = verticalTraversal(tree.root);
    for(size_t i=0; i<verticalOrderResult.size(); i++){
        for(size_t j=0; j<verticalOrderResult[i].size(); j++){
            cout<<verticalOrderResult[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
