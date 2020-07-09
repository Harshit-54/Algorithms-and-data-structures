
void getwidth(Node* root, int &left, int &right, int l){
    if(root==NULL)return ;
    if(left>l)left=l;
    if(right<l)right=l;
    getwidth(root->left,left,right,l-1);
    getwidth(root->right,left,right,l+1);
}

void getans(Node* root, int l, vector<int> &ans, vector<int> &heights, int h){
    if(root==NULL)return;
    if(heights[l]<=h){
        ans[l]=root->data;
        heights[l]=h;
    }
    getans(root->left,l-1,ans,heights,h+1);
    getans(root->right,l+1,ans,heights,h+1);
}

// Method that returns the bottom view.
vector <int> bottomView(Node *root)
{
    int left=0,right=0;
    getwidth(root,left,right,0);
    left=left*(-1);
    vector<int> ans(left+right+1,0);
    vector<int> heights(left+right+1,0);
    getans(root,left,ans,heights,1);
    return ans;
   // Your Code Here
}

