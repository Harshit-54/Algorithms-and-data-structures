
/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
void connect(Node *p)
{
    Node* node=p;
    Node* root = new Node();
    root->data=0;
    Node* level= root;
    while(node!=NULL){
        level=root;
        while(node!=NULL){
            if(node->left!=NULL){
                level->nextRight=node->left;
                level=level->nextRight;
            }
            if(node->right!=NULL){
                level->nextRight=node->right;
                level=level->nextRight;
            }
            node=node->nextRight;
        }
        level->nextRight=NULL;
        node=root->nextRight;
    }
    
   // Your Code Here
}

