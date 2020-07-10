int getans(Node* root,int n1,int n2,Node* &ans){
    if(root==NULL)return 0;
    else {
        int l= getans(root->left,n1,n2,ans);
        int r= getans(root->right,n1,n2,ans);
        int m= (root->data==n1 || root->data==n2)?1:0;
        if(l+m+r==2)ans=root;
        if(l==1||m==1||r==1)return 1;
        else return 0;
    }
}

Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   Node* ans=root;
   int x= getans(root, n1,n2,ans);
   return ans;
}
