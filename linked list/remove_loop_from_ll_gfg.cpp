void removeLoop(Node* head)
{
    // code here
    // just remove the loop without losing any nodes
    Node* slow= head, *fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            break;
        }
    }
    if(fast==NULL || fast->next==NULL)return;
    Node* prev=fast;
    fast=head;
    if(fast==slow){
        while(fast->next!=head){
            fast=fast->next;
        }
        fast->next=NULL;
        return ;
    }
    while(fast!=slow){
        prev=slow;
        fast=fast->next;
        slow=slow->next;
    }
    prev->next=NULL;
}