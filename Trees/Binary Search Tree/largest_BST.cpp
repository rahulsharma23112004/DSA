#include<iostream>
#include<queue>
#include<climits>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class info{
    public:
    int maxi ;
    int mini;
    bool isBST;
    int size;
};

info solve(Node* root , int &ans)
{
    if(root==NULL){
        return {INT_MIN , INT_MAX , true , 0};
    }

    info left = solve(root->left , ans);
    info right = solve(root->right , ans);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data ,right.maxi);
    currNode.mini = min(root->data , left.mini);

    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)){
        currNode.isBST = true;
    }
    else{
        currNode.isBST = false;
    }

    if(currNode.isBST){
        ans =  max(ans , currNode.size);
    }
    return currNode ;
}

int largestBST(Node* root){
    int maxSize = 0;
    info temp = solve(root , maxSize);
    return maxSize;
}


Node* buildTree(Node* root){
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    
    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout<<"Enter data to insert in left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data to insert in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}


Node* levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}



int main()
{
    Node* root = NULL;
    root = buildTree(root);

    cout<<"Printing BST: "<<endl;
    levelOrderTraversal(root);

    cout<<endl;
    int size = largestBST(root);
    cout<<"Size of largest BST is: "<<size<<endl;
    return 0;
}
