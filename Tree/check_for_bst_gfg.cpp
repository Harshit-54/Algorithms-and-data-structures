pair<int,int> checkbst(Node* root,bool &check){
    if(root!=NULL){
        pair<int,int> p1= checkbst(root->left,check);
        pair<int,int> p2= checkbst(root->right,check);
        if(p1.second>=root->data || p2.first<=root->data){
            check=false;
        }
        int one= min(p1.first,root->data);
        int two=max(p2.second,root->data);
        return make_pair(one,two);
    }else return make_pair(INT_MAX,INT_MIN);
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    bool check=true;
    pair<int,int> p= checkbst(root,check);
    return check;
    // Your code here
}
