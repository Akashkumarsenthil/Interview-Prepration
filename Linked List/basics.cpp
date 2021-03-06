#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int d){
        data=d;
        next=NULL;
    }
};

void insertAtHead(node *&head,int n){
    node *newNode=new node(n);
    newNode->next=head;
    head=newNode;
    return;
}

void print(node *head){
    while(head!=NULL){
        cout<<head->data<<" -->";
        head=head->next;
    }
    return;
}

int length(node *head){
    int count=0;
    while (head->next!=NULL)
    {
        count++;
        head=head->next;
    }
    return count;
    
}

void insertAtTail(node *&head,int d){
    if(head==NULL){
        head=new node(d);
        return;
    }

    node *tail=head;
    while (tail->next!=NULL)
    {
        tail=tail->next;
    }
    tail->next=new node(d);
    return;
    
}

void insertAtPositionP(node*&head,int p,int d){
    if(head==NULL|| p==0){
        insertAtHead(head,p);
    }else if(length(head)<p){
        insertAtTail(head,d);
    }else{
        int jumps=1;
        node *temp=head;
        while (jumps<=p-1)
        {
            temp=temp->next;
            jumps++;   
        }

        node *n=new node(d);
        n->next=temp->next;
        temp->next=n;
        
    }
    return;
}


void deleteAtHead(node *&head){
    node *temp=head;
    head=head->next;
    delete temp;
    return;
}

void deleteAtTail(node *&head){
    
    node *prev,*temp;
    temp=head;
    //Temp points to last,prev to last before
    while (temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
        
    }

    delete temp;
    prev->next=NULL;
    return;
    
}

void deleteAtPositionP(node *&head,int p){
    node*temp=head;
    int jumps=1;

    while (jumps<=p-1)
    {
        jumps=jumps+1;
        temp=temp->next;
        /* code */
    }

    node *tobedeleted=temp->next;
    temp->next=temp->next->next;
    delete tobedeleted;
    return;
    
}

bool searchRecursive(node *head,int key){
    if(head==NULL){
        return false;
    }else if(head->data==key){
        return true;
    }else
    {
        searchRecursive(head->next,key);
    }
    
}

bool searchIterative(node *head,int key){
    while (head!=NULL)
    {
        if(head->data==key){
            return true;
        }
        head=head->next;
    }
    return false;
    
}

void buildList(node *&head){
    int data;
    cin>>data;
    while (data!=-1)
    {
        insertAtTail(head,data);
        cin>>data;
    }
    
}

istream& operator>>(istream &is,node *&head){
    buildList(head);
    return is;
}

ostream & operator<<(ostream &os,node *head){
    print(head);
    return os;
}

void reverse(node *&head){
    node *curr,*prev,*n;
    curr=head;
    prev=NULL;
    while (curr!=NULL)
    {
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    
    head=prev;
    
}

node *midPoint(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node *slow=head;
    node *fast=head->next;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
    
}

node *mergesortedlinkedlist(node *a,node*b){
    if(a==NULL){
        return b;
    }else if(b==NULL){
        return a;

    }

    node *c;
    if(a->data<b->data){
        c=a;
        c->next=mergesortedlinkedlist(a->next,b);
    }else{
        c=b;
        c->next=mergesortedlinkedlist(a,b->next);
    }
    return c;
}

node *mergeSort(node *head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node *mid=midPoint(head);
    node *a=head;
    node *b=mid->next;
    mid->next=NULL;

    a=mergeSort(a);
    b=mergeSort(b);

    node *c=mergesortedlinkedlist(a,b);
    return c;

}

bool detectCycle(node *head){
    node*slow=head;
    node*fast=head;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
    
}

int main(){
    node *head=NULL;
    node *head2=NULL;
    // insertAtHead(head,4);
    // insertAtHead(head,2);
    // insertAtHead(head,1);

    // insertAtPositionP(head,2,3);
    //insertAtPositionP(head,6,5);

    // // deleteAtHead(head);
    // // deleteAtTail(head);

    // deleteAtPositionP(head,2);
    // if(searchRecursive(head,4)){
    //     cout<<"Present"<<endl;
    // }else{
    //     cout<<"Not present"<<endl;
    // }

    // if(searchIterative(head,5)){
    //     cout<<"Present"<<endl;
    // }else{
    //     cout<<"Not present"<<endl;
    // }


    // cin>>head;
    // reverse(head);
    cin>>head;
    //cout<<head<<endl;
    //node *mid=midPoint(head);
    // cout<<"mid   "<<mid->data<<endl;
    head=mergeSort(head);
    cout<<head<<endl;
    

    
    
}