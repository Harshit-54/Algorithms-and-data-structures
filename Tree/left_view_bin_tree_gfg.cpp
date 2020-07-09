void getleft(Node* root, int &i, int h){
    if(root!=NULL){
        if(h>i){
            cout<<root->data<<" ";i++;
        }
        getleft(root->left,i,h+1);
        getleft(root->right,i,h+1);
    }
}

// A wrapper over leftViewUtil()
void leftView(Node *root)
{
    int i=0;
    getleft(root,i,1);
   // Your code here
}