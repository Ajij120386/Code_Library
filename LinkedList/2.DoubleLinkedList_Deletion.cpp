#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;


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

Node* ConvertArr2DLL(vector<int> arr){
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
    while(temp != nullptr){
        cout << temp->data << ' ';
        temp = temp-> next;
    }

}

Node* DeleteHead(Node* head){
    if(head == nullptr || head ->next == nullptr){

        delete head;
        return nullptr;

    }

    Node* back = head;
    head = head->next;
    head-> prev = nullptr; //connection cut
    back->next =  nullptr; //connection cut
    delete back;
    return head;

}

Node * deleteLastNode(Node *head) {
    if(head == nullptr || head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node* tail = head;
    while(tail->next != nullptr){

        tail = tail->next;
    }

    Node* secondLast = tail->prev;
    tail->prev = nullptr;  //connection cut
    secondLast->next = nullptr;
    delete tail;
    return head;
}
Node* removeKthElement(Node* head,int k)
{
    if(head==NULL) return NULL;
    int cnt=0;

    Node* kNode=head;

    while(kNode!= NULL)
    {

        cnt++;
        if(cnt==k) break;
        kNode=kNode->next;
    }
    Node* back= kNode->prev;
    Node* front= kNode->next;

    if(back==NULL && front==NULL)
          return NULL;

    else if(back==NULL)
         return DeleteHead(head);

    else if(front==NULL)
         return deleteLastNode(head);

    back->next= front;
    front->prev=back;

    kNode->next=nullptr;  //connection cut
    kNode->prev=nullptr;   //connection cut
    delete kNode;
    return head;


}

void deleteNode(Node* temp)
{

//not delete head , Except head any node delete

            Node* back = temp->prev;
            Node* front = temp->next;

            if(front == nullptr){


              back -> next= nullptr;
              front->prev = nullptr; //connection cut
              free(temp);
              return;

            }

              back -> next= front;
              front->prev = back;

            temp ->next = nullptr; //connection cut
            temp ->prev = nullptr;  //connection cut
             free(temp);
    }



int main()
{
    vector<int> arr = {12, 5, 8, 7};
    int n = arr.size();
    Node* head = ConvertArr2DLL(arr);
//   head= deleteElement(head,5);

  //head= removeKthElement(head,4);
 //head= deleteLastNode(head);
  // head= DeleteHead(head);
  // deleteNode(head->next->next);
    print(head);
    return 0;
}
