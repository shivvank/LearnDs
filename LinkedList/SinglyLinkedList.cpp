#include "Node.cpp"
using namespace std;

//Display all the elements of Linked List 
void DisplayLL(node * head)
{
    if(head==NULL)
    {
        cout<<"Linked List is Empty"<<endl;
    }
    while(head->next!=NULL)
    {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<head->data<<endl;
}


//Insertion in a Linked List:
//Insert at Beginning
node * InsertBeginLL(node *head, int x)
{
    node * tempNode=new node(x);
    if(head==NULL)
    {
        head=tempNode;
        return head;
    }
    tempNode->next=head;
    head=tempNode;
    return head;
}
//Insert at Middle
node * InsertMiddleLL(node * head,int x)
{
    node * tempNode=new node(x);
    if(head==NULL)
    {
        head=tempNode;
        return head;
    }
    node * temp1=head;
    int count =0;
    node * temp2=head;
    while(temp2->next!=NULL&&temp2->next->next!=NULL)
    {
        temp1=temp1->next;
        temp2=temp2->next->next;
    }
    temp2=temp1->next;
    temp1->next=tempNode;
    tempNode->next=temp2;
    return head;
}
//Insert at Last
node * InsertEndLL(node * head,int x)
{
    //if no element 
    if(head==NULL)
    {
        head=new node(x);
        return head;
    }
    //if 1 or more elements 
    node *temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    node * tempNode=new node(x);
    temp->next=tempNode;
    return head;
}
//Delete from a linked list :

//Delete Middle Element
/*
whats middle?
for even number of elements : n/2 & (n/2)+1
    cases: if only 2 present -> delete both
for odd number of elements : n/2(int) 
    cases : if only 1 present 
    should count or not ?
how to find middle ? two pointers method : one with speed 1 & other with speed 2
less complexity with doubly LL
*/
node * DeleteMiddleLL(node * head)
{
    int count=0;
    node * temp1=head;
    node * temp2=head;
    node * tempPrev=NULL;
    while(temp2->next!=NULL&&temp2->next->next!=NULL)
    {
        tempPrev=temp1;
        temp1=temp1->next;
        count++;
        temp2=temp2->next->next;
    }
    tempPrev->next=temp1->next;
    delete temp1;
    return head;
}

//Delete First Element
node * DeleteFirstLL(node * head)
{
    //if empty 
    if(head==NULL)
    {
        cout<<"Linked List empty!"<<endl;
        return NULL;
    }
    //if one element
    if(head->next==NULL)
    {
        head=NULL;
        return head;
    }
    //if more than 1 element in Linked List
    node *temp=head;
    head=head->next;
    delete temp;
    return head;
}
//Delete last element
node * DeleteLastLL(node *head)
{
    //Empty Linked List
    if(head==NULL)
    {
        cout<<"No Element there! Aborting!"<<endl;
        return NULL;
    }
    //if one element
    if(head->next==NULL)
    {
        head=NULL;
        return head;
    }
    //if more than 1 element
    node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;

}
int main()
{
    node *head=NULL;
    cout<<"Enter the value : ";
    char ch='y';
    int x;
    cin>>x;
    head=new node(x);
    cout<<"Want to enter more elements? (y/n)"<<endl;
    cin>>ch;
    while(ch=='y')
    {
        cout<<"Enter the value : ";
        cin>>x;
        head=InsertEndLL(head,x);
        cout<<"Want to enter more elements? (y/n)"<<endl;
        cin>>ch;
    }
    // DisplayLL(head);
    // head=DeleteMiddleLL(head);
    DisplayLL(head);
    head=InsertMiddleLL(head,10);
    DisplayLL(head);
    // ch='y';
    // while(ch=='y')
    // {
    //     head=DeleteLastLL(head);
        
    //     if(head!=NULL)
    //     {
    //         DisplayLL(head);
    //         cout<<"Want to delete more elements? (y/n)"<<endl;
    //         cin>>ch;
    //     }
    // }
    return 0;
}