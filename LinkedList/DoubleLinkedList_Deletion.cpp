#include <bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    public:
    Node(int data){
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }

    public:
    Node(int data,Node* next,Node* prev){
        this->data = data;
        this->next = next;
        this->prev= prev;
    }

};

Node* ConvertArr2LL(vector<int> arr){
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
    Node* prev = head;
    head = head->next;
    head-> prev = nullptr;
    prev->next = nullptr;
    delete prev;
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
    tail->prev = nullptr;
    secondLast->next = nullptr;
    delete tail;
    return head;
}
Node* removeKthElement(Node* head,int k)
{
    if(head==NULL ) return NULL;
    int cnt=0;

    Node* kNode=head;

    while(kNode!= NULL)
    {

        cnt++;
        if(cnt==k) break;
        kNode=kNode->next;
    }
    Node* prev= kNode->prev;
    Node* front= kNode->next;

    if(prev==NULL && front==NULL)
          return NULL;

    else if(prev==NULL)
         return DeleteHead(head);

    else if(front==NULL)
         return deleteLastNode(head);

    prev->next= front;
    front->prev=prev;

    kNode->next=nullptr;
    kNode->prev=nullptr;
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
              front->prev = nullptr;
              free(temp);
              return;

            }

              back -> next= front;
              front->prev = back;

            temp ->next = nullptr;
            temp ->prev = nullptr;
             free(temp);
    }



int main()
{
    vector<int> arr = {12, 5, 8, 7};
    int n = arr.size();
    Node* head = ConvertArr2LL(arr);
   // head= deleteElement(head,5);

  // head= removeKthElement(head,1);
   // head= deleteLastNode(head);
   deleteNode(head->next->next);
    print(head);
    return 0;
}
