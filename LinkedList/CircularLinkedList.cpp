#include "node.cpp"
using namespace std;
void DisplayCircular(node * head)
{
    node * temp=head;
    cout<<temp->data<<"->";
    temp=temp->next;
    while(temp!=head)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"....."<<endl;
}
node * InsertBeginCircular(node * head,int x)
{
    node * tempNode=new node(x);
    if(head==NULL)
    {
        head=tempNode;
        tempNode->next=head;
        return head;
    }
    tempNode->next=head;
    head=tempNode;
    return head;
}
int CountNodes(node * head)
{
    int count=0;
    node * temp=head;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
node * InsertMiddleCircular(node * head,int x)
{
    node * tempNode=new node(x);
    if(head==NULL)
    {
        head=tempNode;
        tempNode->next=head;
        return head;
    }
    node * temp=head;
    int n=CountNodes(head);
    n=n/2;
    while(n--)
    {
        temp=temp->next;
    }
    tempNode->next=temp->next;
    temp->next=tempNode;
    return head;
}
node * InsertLastCircular(node * head,int x)
{
    node * tempNode=new node(x);
    if(head==NULL)
    {
        head=tempNode;
        tempNode->next=tempNode;
        return head;
    }
    node * temp = head; 
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    tempNode->next=head;
    temp->next=tempNode;
    return head;
}
void DeleteLastCircular(node * head)
{
    node * temp=head;
    node * prev=temp;
    while(temp->next!=head)
    {
        prev=temp;
        temp=temp->next;
    }
    node * deleteNode=temp;
    prev->next=head;
    deleteNode->next=NULL;
    delete deleteNode;
}
void DeleteBeginCircular(node * head)
{
    node * temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=head->next;
    head=temp->next;
}
void DeleteMiddleCircular(node * head)
{
    int n=CountNodes(head);
    node * prev=head;
    n=n/2;
    while(n--)
    {
        prev=prev->next;
    }
    node * temp=prev->next;
    prev->next=temp->next;
    temp->next=NULL;
    delete temp;
}
node * SplitInTwo(node * head)
{
    int n=CountNodes(head);
    if(n%2==0)
    {
        n=(n/2)-1;
    }
    else
    {
        n=(n/2)+1;
    }
    cout<<n+1<<" in first rest in second"<<endl;
    node * first=head;
    node * second=NULL;
    node * temp=head;
    while(n!=0)
    {
        temp=temp->next;
        --n;
    }
    second=temp->next;
    temp->next=first;
    temp=second;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=second;
    return second;
}
