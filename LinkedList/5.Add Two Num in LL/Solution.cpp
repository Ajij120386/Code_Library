// given two number as linkedlist form  and construct one liskedlist for the sum of two number;
// https://leetcode.com/problems/add-two-numbers/solutions/5298475/easy-to-understand-o-n-solution-add-two-number/
// Time complexity = O(n)

Node *addTwoNumbers(Node *num1, Node *num2)
{
   Node *dummyHead = new ListNode(-1);
   Node *curr = dummyHead ;
   Node *temp1 = num1;
   Node *temp2 = num2;

    int sum = 0, carry = 0;

    while (temp1 != NULL || temp2 != NULL)
    {
        sum = carry;
        if (temp1)
            sum += temp1->data;
        if (temp2)
            sum += temp2->data;

        ListNode *newNode = new Node(sum % 10);

        carry = sum / 10;

        curr->next = newNode;

        curr = curr->next;

        if (temp1)
            temp1 = temp1->next;
        if (temp2)
            temp2 = temp2->next;
    }
    if (carry)
    {
        ListNode newNode = new Node(carry);
        curr->next =newNode;
    }
    return dummyHead->next;
}
