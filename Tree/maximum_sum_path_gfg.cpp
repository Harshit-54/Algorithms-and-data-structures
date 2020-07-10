int getans(Node* node, int &maxval){
    if(node==NULL)return 0;
    else {
        int l = getans(node->left,maxval);
        int r = getans(node->right,maxval);
        if(node->left==NULL&& node->right==NULL)return node->data;
        if(node->left!=NULL && node->right==NULL)return node->data+l;
        if(node->left==NULL && node->right!=NULL)return node->data+r;
        if(maxval<node->data+l+r)maxval=node->data+r+l;
        return max(node->data+l,node->data+r);
       
    }
}

int maxPathSum(Node* root)
{ 
    int maxval=INT_MIN;
    int ret= getans(root,maxval);
    // code here   
    return maxval;
}