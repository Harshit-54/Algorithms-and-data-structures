#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode* next;

         SinglyLinkedListNode (int data) {
            this->data = data;
            this->next=nullptr;

        }
};


class SinglyLinkedList {
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;

    }

    void insertnode(int data) {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(data);

        if (!this->head)
            this->head = node;
        else {
            this->tail->next = node;
        }
        this->tail = node;
    }
};
void printlist(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode* node;
    node=head;
    while(node){
        cout<<node->data<<"\t";
        node=node->next;
    }
    cout<<endl;

}
void removeduplicates(SinglyLinkedListNode* head)
{
    unordered_set <int > s;
    SinglyLinkedListNode* node;
    SinglyLinkedListNode* remnode;
    node= head;
    int count=0;
    cout<<endl;
    while(node)
    {

        count++;

        if(s.find(node->data)!=s.end())
        {

            remnode=head;
            for (int i = 0; i < count - 2; ++i) {
                remnode=remnode->next;
            }

            remnode->next= remnode->next->next;
            count--;
            node=remnode->next;
        }
        else{
            s.insert(node->data);
            node=node->next;
        }



    }
}


int main(){

 SinglyLinkedList* list1= new SinglyLinkedList();
    int n;
    cin>>n;
    int data;
    for (int i = 0; i < n; ++i) {
        cin>>data;
        list1->insertnode(data);
    }

    SinglyLinkedListNode* node;
    SinglyLinkedListNode* head;
    head=list1->head;
    node=head;
    for (int j = 0; j < n; ++j){
        cout<<node->data<<"\t";
        node=node->next;
    }

    removeduplicates(head);
    printlist(head);

//    vector <int > v;
//    for (int i  = 0; i <5 ; ++i) {
//
//        v.push_back(i);
//    }
//    while(!v.empty()) {
//        cout<<v.at(v.size()-1);
//       v.pop_back();
//
//    }
//     return 0;


//    list <int > lista;
//    list <int >:: iterator it;
//    for (int i = 0; i < 11; ++i) {
//        lista.push_back(i*4);
//
//    }
//    for (it =lista.begin(); it!=lista.end(); it++) {
//            cout<<*it<<"\t";
//    }
//    cout<<endl;
//    cout<<endl;
//    cout<<*lista.end();
//    while(!lista.empty())
//    {
//        cout<<lista.back()<<"\t";
//        lista.pop_back();
//    }



//    set <int> gquiz1;
//    gquiz1.insert(40);
//    gquiz1.insert(30);
//    gquiz1.insert(60);
//    gquiz1.insert(20);
//
//
//    set<int> :: iterator itr;
//    for (itr = gquiz1.begin();  itr!= gquiz1.end() ; itr++) {
//        cout<<*itr<<"\t";
//
//    }
//
//    set <int,greater<int>> gquiz2(gquiz1.begin(), gquiz1.end());
//
//    // print all elements of the set gquiz2
//    cout << "\nThe set gquiz2 after assign from gquiz1 is : ";
//    for (itr = --gquiz2.end(); itr != --gquiz2.begin(); --itr)
//    {
//        cout << '\t' << *itr;
//    }
//    cout << endl;
//    cout<<endl<<*gquiz2.begin()<<endl;
//    gquiz2.erase(gquiz2.begin(), gquiz2.find(30));
//    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr)
//    {
//        cout << '\t' << *itr;
//    }

//    map<int,int > map1;
//    map<int,int> :: iterator itr;
//
//    for (int i = 1; i < 6; ++i) {
//        map1.insert(pair <int,int> (i,10+i*10));
//    }
//    for(itr=map1.begin(); itr!=map1.end(); itr++)
//    {
//        cout<<"\t"<<itr->first<<"\t"<<itr->second<<endl;
//
//    }


//    struct add_x {
//        add_x(int x) : x(x){};
//        int operator()(int y) const {return x+y;}
//
//    private: int x;
//    };
//    add_x add50(50);
//    int i = add50(8);
//    cout<<i;
//


return 1;
}
