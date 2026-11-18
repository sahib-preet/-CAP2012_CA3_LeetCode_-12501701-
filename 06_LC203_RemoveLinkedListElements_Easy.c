struct ListNode* removeElements(struct ListNode* head, int val)
{
    struct ListNode *temp;

    while(head != NULL && head->val == val)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    temp = head;

    while(temp != NULL && temp->next != NULL)
    {
        if(temp->next->val == val)
        {
            struct ListNode *del = temp->next;
            temp->next = temp->next->next;
            free(del);
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}
