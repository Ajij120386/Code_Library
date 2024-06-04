#include<bits/stdc++.h>
using namespace std;
struct Node
{

public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1)
    {
        data=data1;
        next=next1;
    }


public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};

Node* convertArr2LL(vector<int>&arr)
{
    Node* head= new Node(arr[0]);
    Node* mover=head;

    for(int i=1;i<arr.size();i++)
    {
        Node* tmp= new Node(arr[i]);
        mover->next=tmp;
        mover=tmp;
    }
    return head;
}
int lengthofLL(Node* head)
{
    int cnt=0;
    Node* tmp=head;

    while(tmp)
    {
        cnt++;

       tmp=tmp->next;
    }

    return cnt;
}
int checkIfPresent(Node* head,int val)
{

    Node* tmp=head;

    while(tmp)
    {
        if(tmp->data==val) return 1;

       tmp = tmp->next;
    }

    return 0;
}

void print(Node* head)
{

    while(head!=NULL)
    {
        cout<<head->data<<" ";
         head=head->next;
    }
    cout<<endl;
}
Node* removeHead(Node* head)
{
    if(head==NULL) return head;
    Node* tmp=head;
    head=head->next;
    delete tmp;
    return head;

}
Node* removeTail(Node* head)
{
    if(head==NULL || head->next==NULL) return NULL;  //linked list is empty || it has one element
    Node* tmp=head;

    while(tmp->next->next!=NULL)
    {
        tmp=tmp->next;
    }

    delete tmp->next;
    tmp->next=nullptr;
    return head;

}
Node* removeK(Node* head,int k)
{
    if(head==NULL ) return head;
    if(k==1)
    {
        Node* tmp=head;
       head=head->next;
       delete tmp;
        return head;

    }
    int cnt=0;
    Node* tmp=head;
    Node* prev=NULL;

    while(tmp!=NULL)
    {
        cnt++;
        if(cnt==k)
        {

            prev->next=prev->next->next;
            free(tmp);
            break;
        }
        prev=tmp;
        tmp=tmp->next;

    }
    return head;

}
Node* removeEl(Node* head,int el)
{
    if(head==NULL ) return head;
    if(head->data==el)
    {
        Node* tmp=head;
       head=head->next;
       delete tmp;
        return head;

    }

    Node* tmp=head;
    Node* prev=NULL;

    while(tmp!=NULL)
    {

        if(tmp->data==el)
        {

            prev->next=prev->next->next;
            free(tmp);
            break;
        }
        prev=tmp;
        tmp=tmp->next;

    }
    return head;

}
Node* insertHead(Node* head,int val)
{

    /*
    Node* tmp=new Node(val,head);
    return tmp;

    */
    return new Node(val,head);

}
Node* insertTail(Node* head,int val)
{

    if(head==NULL)
        return new Node(val);

    Node* tmp =head;
    while(tmp->next!=NULL)
    {

        tmp=tmp->next;
    }
    Node* newNode= new Node(val);
    tmp->next=newNode;
    return head;

}

Node* insertPosition(Node* head,int el,int k)
{

    if(head==NULL)
    {

        if(k==1)
             return new Node(el);
        else
            return head;
    }

    if(k==1)
    {
        return new Node(el,head);
    }

    int cnt=0;

    Node* tmp =head;
    while(tmp!=NULL)
    {
        cnt++;
        if(cnt==k-1)
        {
            Node* x=new Node(el,tmp->next);
            tmp->next=x;
            break;
        }
        tmp=tmp->next;
    }

    return head;

}
Node* insertBeforeValue(Node* head,int el,int val)
{

    if(head==NULL)
    {

         return NULL;
    }

    if(head->data==val)
    {
        return new Node(el,head);
    }



    Node* tmp =head;
    while(tmp->next!=NULL)
    {

        if(tmp->next->data==val)
        {
            Node* x=new Node(el,tmp->next);
            tmp->next=x;
            break;
        }
        tmp=tmp->next;
    }

    return head;

}
int main()
{



 /*
     vector<int>arr={2,5,8,7};
    Node y=  Node(arr[1],nullptr);
    cout<<y.data<<" "<<y.next<<endl;


     Node* y=  new Node(arr[1],nullptr);
     cout<<y->data<<" "<<y->next<<endl;

  */

/*
      vector<int>arr={2,5,8,7};
    Node* head=  convertArr2LL(arr);

    Node* tmp =  head;

    while(tmp)
    {
            cout<<tmp->data<<" ";
            tmp=tmp->next;
    }
*/


/*
       vector<int>arr={2,5,8,7};
       Node* head=  convertArr2LL(arr);
         cout<<lengthofLL(head);

*/

/*
         vector<int>arr={2,5,8,7};
       Node* head=  convertArr2LL(arr);
         cout<<checkIfPresent(head,15);
*/

/*
          vector<int>arr={2,5,8,7};
       Node* head=  convertArr2LL(arr);
         head= removeHead(head);
         print(head);

 */
 /*

         vector<int>arr={2,5,8,7};
       Node* head=  convertArr2LL(arr);
         head= removeTail(head);
         print(head);

  */
  /*
            vector<int>arr={2,5,8,7};
       Node* head=  convertArr2LL(arr);
         head= removeK(head,3);
         print(head);
*/

/*
        vector<int>arr={2,5,8,7};
        Node* head=  convertArr2LL(arr);
         head= removeEl(head,8);
         print(head);

  */
  /*
        vector<int>arr={2,5,8,7};
        Node* head=  convertArr2LL(arr);
         head= insertHead(head,100);
         print(head);

 */

 /*
        vector<int>arr={2,5,8,7};
        Node* head=  convertArr2LL(arr);
         head= insertTail(head,100);
         print(head);
*/

/*
       vector<int>arr={2,5,8,7};
        Node* head=  convertArr2LL(arr);
         head= insertPosition(head,100,4);
         print(head);
*/

 /*
  vector<int>arr={2,5,8,7};
        Node* head=  convertArr2LL(arr);
         head= insertBeforeValue(head,100,7);
         print(head);
*/

          vector<int>arr={2,5,8,7};
        Node* head=  convertArr2LL(arr);
         head= insertBeforeValue(head,100,7);
         print(head);
}

