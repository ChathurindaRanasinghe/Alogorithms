#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }
    
            

	void levelOrder(Node * root){
       queue<Node*> traversal;
       if (root == NULL)
            return;

       Node* temp_node = root; 
       traversal.push(root);
        while(traversal.empty()==false){
            temp_node = traversal.front();
            traversal.pop();
            cout<<temp_node->data<<" ";

            if(temp_node->left!=NULL)
                traversal.push(temp_node->left);
            if(temp_node->right!=NULL)
                traversal.push(temp_node->right);   
        }
               
	}

};//End of Solution
int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}