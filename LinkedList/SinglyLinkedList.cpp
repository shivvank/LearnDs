#include "node.cpp"
using namespace std;
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
node * DeleteAt_i(node * head,int i)
{
    node * temp=head;
    node * tempPrev=NULL;
    while(i--)
    {
        if(temp==NULL)
        {
            cout<<"Cannot delete as ith element doesn't exist"<<endl;
            return NULL;
        }
        tempPrev=temp;
        temp=temp->next;
    }
    tempPrev->next=temp->next;
    delete temp;
    return head;
}