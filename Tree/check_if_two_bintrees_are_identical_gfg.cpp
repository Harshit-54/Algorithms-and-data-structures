void getans(Node* r1,Node* r2, bool &check){
    if(r1==NULL && r2==NULL)return ;
    else if((r1==NULL && r2!=NULL) || (r1!=NULL && r2==NULL)){
        check=false;
        return;
    }else {
        if(r1->data==r2->data){
            getans(r1->left,r2->left,check);
            getans(r1->right,r2->right,check);
            
        }else {
            check=false;
            return ;
        }
    }
}   

bool isIdentical(Node *r1, Node *r2)
{
    bool check=true;
    getans(r1,r2,check);
    //Your Code here
    return check;
}