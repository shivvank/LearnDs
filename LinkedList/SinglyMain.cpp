#include "SinglyLinkedList.cpp"
using namespace std;
int main()
{
    node * head=NULL;
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
    DisplayLL(head);
    // cout<<"Length of Linked List : "<<SinglyLengthIterative(head)<<endl;
    // bool flag=SearchSinglyIterative(head,4);
    // if(flag)
    //     cout<<"ELement Found"<<endl;
    
    // DisplayLL(SinglyReverse(head));
    // DisplayLL(head);
    // head=DeleteMiddleLL(head);
    // DisplayLL(head);
    // head=InsertMiddleLL(head,10);
    // DisplayLL(head);
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
    // if(IsSinglyPalindrome(head))
    // {
    //     cout<<"It is Palindrome !"<<endl;
    // }
    // else
    // {
    //     cout<<"No it is not Palindrome"<<endl;
    // }
    RemoveDuplicatesUnsorted(head);
    DisplayLL(head);
    return 0;
}