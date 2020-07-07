int intersectPoint(Node* head1, Node* head2){
    Node* a=head1,*b=head2;
    while(a->next!=NULL && b->next!=NULL){
        if(a==b)return a->data;
        a=a->next;b=b->next;
        
    }
    Node* sec;
    
    if(a->next==NULL){
        sec=head2;
        while(b->next!=NULL){
            b=b->next;sec=sec->next;
        }
        a=head1;
        while(sec!=NULL && a!=NULL){
            if(sec==a)return sec->data;
            else {
                sec=sec->next;a=a->next;
            }
        }
    }else {
        sec=head1;
        while(a->next!=NULL){
            a=a->next;sec=sec->next;
        }
        b=head2;
        while(sec!=NULL && b!=NULL){
            if(sec==b)return sec->data;
            else {
                sec=sec->next;b=b->next;
            }
        }
    }
    return -1;
    
}
