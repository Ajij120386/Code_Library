/* *****************************BruteForce**************************************

TC: O(N+N/2)
SC:  O(1)
*/


int getLength(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        temp = temp -> next;
        cnt++;
    }
    return cnt;
}

Node* deleteMiddle(Node* head){
    Node* curr = head;
    if(head == nullptr || head -> next == nullptr){
        return nullptr;
    }
    int N = getLength(head);
    int n = 0;
    while(n < N/2 - 1){
        curr = curr -> next;
        n++;
    }
    Node *middle = curr->next;
    curr->next = curr->next->next;
    delete middle;
    return head;
}

/* *****************************Optimal**************************************

time complexity = O(n/2)
 space complexity = O(1)


*/


ListNode *deleteMiddle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    ListNode *fast = head;

    //slightly change slow and fast pointer concept for this problem

    //skip slow pointer once time ,so we apply  move fast pointer where slow pointer not move
    fast = fast->next->next;
    ListNode *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *middleNode = slow->next;
    slow->next = slow->next->next;
    delete (middleNode);
    return head;
}
