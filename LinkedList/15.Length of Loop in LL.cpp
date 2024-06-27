
/* *****************************BruteForce**************************************

TC: O(N*2*log1)
SC:  O(N)
*/
int findLoopLength(ListNode* head) {

    unordered_map<ListNode*, int> nodeMap; // Map to store node addresses and their corresponding indices
    ListNode* current = head;
    int index = 0;

    while (current != nullptr) {
        // Check if the current node is already in the map
        if (nodeMap.find(current) != nodeMap.end()) {
            // Loop detected, calculate the length
            int loopStartIndex = nodeMap[current];
            return index - loopStartIndex;
        }

        // Add the current node to the map
        nodeMap[current] = index;

        // Move to the next node
        current = current->next;
        index++;
    }

    // No loop found
    return 0;
}


/* *****************************Optimal**************************************

time complexity = O(n)
 space complexity = O(1)


*/


int LengthofLoop(Node *head)
{
    // Code here
    int count = 0;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return findLength(slow,fast);
        }

    }
    return 0;

}

int findLength(Node* slow, Node* fast)
{
    int cnt=1;
    fast=fast->next;
    while(slow!=fast)
    {

        cnt++;
        fast=fast->next;
    }
    return cnt;


}
