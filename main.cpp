#include<iostream>
#include<queue>
#include<stack>

using namespace std;

typedef struct  Node
{
    int data;
    Node* left;
    Node* right;
} Node;


/* 3 Cases
Case 1: The node to be deleted doesnt have a child (leaf Node)
    a) Free the memory
    b) set parent node's pointer to NULL
    
Case 2: The node to be deleted has just one child
    a) set it's parent link to the only child node
    b) free the memory of this node 

Case 3: The node to be deleted has 2 children
    a) replace the node's value either with max in left subtree OR min in right subtree
    b) delete the duplicate node in left of right subtree (deduced to case 1 or case 2)
*/

enum child
{
    left = 0,
    right = 1
};

void DeleteNode(Node* root, int val)
{
    Node* prev = root;
    if(root == NULL)
    {return;}
    Node* temp = root;
    child c;

    
}

void LevelOrder(Node* root)
{
    queue<Node*> q;
    if(root == NULL)
        return;
    q.push(root);

    Node* ptr = NULL;
    while(!q.empty())
    {
        ptr = q.front();
        if(ptr->left)
        {q.push(ptr->left);}
        if(ptr->right)
        {q.push(ptr->right);}
        cout<<ptr->data<<endl;
        q.pop();
        
    }
    
}

bool isBSTUtil(Node* root, int min, int max)
{
    if(root == NULL){return true;}
    if(root->data > min && root->data < max && isBSTUtil(root->left, min, root->data) && 
    isBSTUtil(root->right, root->data, max))
    {return true;}
    else{return false;}
}

bool isBST(Node* root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

void InOrderTraversal(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    InOrderTraversal(root->left);
    cout<<root->data<<" "<<endl;
    InOrderTraversal(root->right);
}

void iterativeInorderTraversal(Node* cur)
{
    stack<Node*> st;
    while(cur != NULL || !st.empty())
    {
        if(cur == NULL)
        {
            cur = st.top();
            st.pop();
            cout<<cur->data<<endl;
            cur = cur->right;
        }
        else{
            st.push(cur);
            cur = cur->left;
        }
    }
}

int main()
{
    Node* temp1 = (Node*)malloc(sizeof(Node));
    temp1->data = 3;
    Node* temp2 = (Node*)malloc(sizeof(Node));
    temp2->data = 1;
    Node* temp3 = (Node*)malloc(sizeof(Node));
    temp3->data = 5;
    Node* temp4 = (Node*)malloc(sizeof(Node));
    temp4->data = 2;
    Node* temp5 = (Node*)malloc(sizeof(Node));
    temp5->data = 4;

    temp1->left = temp2;
    temp1->right = temp3;
    temp2->left = NULL;
    temp2->right = temp4;

    temp3->left = temp5;
    temp3->right = NULL;

    temp4->left = NULL;
    temp4->right = NULL;

    temp5->left = NULL;
    temp5->right = NULL;

    /*
            3
           / \
          1   5
           \ /
           2 4
    */

    cout<<"Level order Traversal: "<<endl;
    LevelOrder(temp1);
    cout<<"In order Traversal: "<<endl;
    InOrderTraversal(temp1);

    cout<<"Iterative inorder traversal: "<<endl;
    iterativeInorderTraversal(temp1);
    cout<< "is this BST ? : "<<(isBST(temp1)?("Yes"):("No"));
    return 0;
}