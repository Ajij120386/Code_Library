#include <bits/stdc++.h>
// #include <Node.cpp>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;


      public:
    Node(int data1,Node* next1,Node* prev1){
        data = data1;
        next = next1;
        prev= prev1;
    }


    public:
    Node(int data1){

         data = data1;
         next = nullptr;
         prev = nullptr;

    }


};

Node* ConvertArr2DLL(vector<int>&arr){

    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){

        Node* newNode= new Node(arr[i],nullptr,temp);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void print(Node* head){

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << ' ';
        temp = temp-> next;
    }

}
Node* InsertBeforeHead(Node* head,int val){

    if(head == nullptr){
        return new Node(val);
    }

    Node* newNode = new Node(val,head,nullptr);
    head -> prev= newNode;
    return newNode;
}
Node* InsertBeforeTail(Node* head,int val){

    if(head == nullptr){

        return new Node(val);
    }

     if(head->next == nullptr){

        return InsertBeforeHead(head,val);
    }


    Node* tail = head;
    while(tail->next != nullptr){
        tail =tail->next;
    }

    Node* back=tail->prev;
    Node* newNode = new Node(val,tail,back);
     back->next = newNode;  //connection setup
     tail->prev=newNode;  ////connection setup

    return head;

}
Node* InsertBeforeKthElement(Node* head,int k,int val){


    if(head == nullptr){
        return new Node(val);
    }

    if(k == 1){
        return InsertBeforeHead(head,val);
    }

    int cnt = 0;

    Node* temp = head;

    while(temp != nullptr)
    {
        cnt++;
        if(cnt == k) break;
        temp=temp->next;

    }

        Node* back = temp->prev;
        Node* newNode = new Node(val,temp,back);
        back->next = newNode;//connection setup
        temp->prev= newNode; //connection setup
        return head;

}


void InsertBeforeNode(Node* node, int val)
{

//not delete head , Except head any node delete

            Node* back = node->prev;
            Node* newNode =new Node(val,node,back);
            back->next=newNode; //connection setup
            node->prev=newNode; //connection setup


    }


int main()
{
    vector<int> arr = {12, 5, 8, 7};
    int n = arr.size();
    Node* head = ConvertArr2DLL(arr);


     //head = InsertBeforeHead(head,10);
     //head = InsertBeforeTail(head,15);
    //head = InsertBeforeKthElement(head,4,3);
    InsertBeforeNode(head->next,100);
    print(head);
    return 0;
}
