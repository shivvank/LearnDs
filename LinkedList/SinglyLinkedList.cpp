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

// Find length of LinkedList 
//Recursive 
int SinglyLengthRecursive(node * head)
{
    if(head!=NULL)
    {
        return 1+SinglyLengthRecursive(head->next);
    }
    else
    {
        return 0;
    }
}
//Iterative
int SinglyLengthIterative(node *head)
{
    int count=0;
    while(head!=NULL)
    {
        head=head->next;
        count++;
    }
    return count;
}

//Search Element of Linked List
//Recursive
bool SearchSinglyRecursive(node * head,int k)
{
    if(head==NULL)
    {
        cout<<"element not found !"<<endl;
        return false;
    }
    if(head->data==k)
    {
        return true;
    }
    return false || SearchSinglyRecursive(head->next,k);
}
//Iterative
bool SearchSinglyIterative(node * head,int k)
{
    if(head==NULL)
    {
        cout<<"Linked List Empty"<<endl;
        return false;
    }
    while(head!=NULL)
    {
        if(head->data==k)
            return true;
        head=head->next;
    }
    return false;
}
void SinglyNthNode(node * head,int n)
{
    int m=n;
    while(n--)
    {
        head=head->next;
        if(head==NULL)   // -- here checking after moving to next element
        {
            cout<<m<<"th element doesn't exist"<<endl; 
            return;
        }
    }
    cout<<m<<"th element is : "<<head->data<<endl;
}
//Detect loop ????
//Only to find between first and last 
bool SinglyFindLoop(node * head)
{
    node * temp = head;
    int flag=0;
    temp=temp->next;
    while(temp!=NULL)
    {
        if(temp==head)
        {
            flag=1;
        }
        temp=temp->next;
    }
    if(flag)
        return true;
    else
        return false;
}
//two pointer method
bool SinglyFindLoopTP(node * head)
{
    node *temp1=head;
    node *temp2=head;
    int flag=0;
    while(temp1!=NULL&&temp2!=NULL)
    {
        temp1=temp1->next;
        temp2=temp2->next->next;
        if(temp1==temp2)
        {
            flag=1;
            break;
        }
    }
    if(flag)
        return true;
    else
        return false;
}
node * SinglyReverse(node * head)
{
    node * temp1=NULL;
    node * temp2=head;
    node * temp3 =NULL;
    while(temp2!=NULL)
    {
        temp3=temp2->next;
        temp2->next=temp1;
        temp1=temp2;
        temp2=temp3;
    }
    return temp1;
}

//Floyd cycle detection algorithm
node * CycleDetectCommonPoint(node * head)
{
    node * fast_ptr=head;
    node * slow_ptr=head->next;
    int flag=0;
    while(fast_ptr!=slow_ptr & fast_ptr!=NULL)
    {
        if(fast_ptr==slow_ptr)
        {
            flag=1;
        }
        fast_ptr=fast_ptr->next->next;
        slow_ptr=slow_ptr->next;
    }
    if(flag==0)
    {
        return NULL;
    }
    else
    {
        return slow_ptr;
    }
}
int DetectAndCountLoopNode(node * head)
{
    node * ptr=CycleDetectCommonPoint(head);
    node * temp=head;
    int count =0;
    while(temp!=ptr)
    {
        temp=temp->next;
        count++;
    }
    return count;
}
//
long long FindDataString(node * head)
{
    long long data=0;
    while(head!=NULL)
    {
        data=head->data+(data*10);
        head=head->next;
    }
    cout<<data<<endl;
    return data;
}
// node * ReverseLL(node * head)
// {
//     node * temp1=NULL;
//     node * temp2=head;
//     node * temp3=NULL;
//     while(temp2!=NULL)
//     {
//         temp3=temp2->next;
//         temp2->next=temp1;
//         temp1=temp2;
//         temp2=temp3;
//     }
//     return temp1;
// }
// Singly List is Palindrome 
bool IsSinglyPalindrome(node * head)
{
    long long x=FindDataString(head);
    head=SinglyReverse(head);
    long long y=FindDataString(head);
    if(x==y)
    {
        return true;
    }
    else
    {
        return false;
    }
}
//Remove Duplicates from Sorted Linked List
void RemoveDuplicatesSorted(node * head)
{
    while(head->next!=NULL)
    {
        int flag=0;
        if(head->data==head->next->data)
        {
            node * temp2=head->next;
            node * temp1=head;
            temp1->next=temp2->next;
            delete temp2;
            flag=1;
        }
        if(flag==0)
        {
            head=head->next;
        }
    }
}
void RemoveDuplicatesUnsorted(node * head)
{
    unordered_set<int> s;
    s.insert(head->data);
    while(head->next!=NULL)
    {
        if(s.find(head->next->data)!=s.end())
        {
            if(head->next->next==NULL)
            {
                head->next=NULL;
            }
            else
            {
                node * temp1=head;
                node *temp2=head->next;
                node * temp3=head->next->next;
                temp1->next=temp3;
                temp2->next=NULL;
                delete temp2;
            }
        }
        else
        {
            s.insert(head->next->data);
            head=head->next;
        }
    }
}

