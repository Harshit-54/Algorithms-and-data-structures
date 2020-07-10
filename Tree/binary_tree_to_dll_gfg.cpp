
void getlist(Node* root, Node* &node){
    if(root==NULL)return ;
    getlist(root->left,node);
    node->right=root;
    node=node->right;
    getlist(root->right,node);
}

Node * bToDLL(Node *root)
{
    if(root==NULL)return NULL;
    Node* head= new Node();
    head->data = 0;
    Node* node=head;
    getlist(root,node);
    head=head->right;
    head->left=NULL;
    node=head;
    Node* prev=NULL;
    while(node!=NULL){
        node->left=prev;
        prev=node;
        node=node->right;
    }
    return head;
    // your code here
}
