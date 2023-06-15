#include "linked_list.h"

void linkedlist_test(void)
{
    NODE_ST_PTR p, q, r;

    p = (NODE_ST_PTR)malloc(sizeof(struct ListNode));
    q = (NODE_ST_PTR)malloc(sizeof(struct ListNode));
    p->data = 23;
    p->link = q;
    p->link->data = 45;
    q->link = NULL;
    r = (NODE_ST_PTR)malloc(sizeof(NODE_ST));
    r->data = 34;
    r->link = p->link;
    p->link = r;
    free(p);
    free(q);
    free(r);
}

/// @brief
/// @param arr
/// @param num
/// @return
NODE_ST_PTR linkedlist_create(int *arr, int num)
{
    NODE_ST_PTR head, tail, tmp;
    head = tail = (NODE_ST_PTR)malloc(sizeof(NODE_ST));

    for (int i = 0; i < num; i++)
    {
        tail->link = (NODE_ST_PTR)malloc(sizeof(NODE_ST));
        tail = tail->link;
        tail->data = arr[i];
    }
    tail->link = NULL;
    tmp = head;
    head = head->link;
    free(tmp);
    return head;
}

void linkedlist_release(NODE_ST_PTR head)
{
    int cnt = 0;
    NODE_ST_PTR ptr = (NODE_ST_PTR)malloc(sizeof(NODE_ST));
    while (head != NULL)
    {
        ptr = head;
        head = head->link;
        printf("Release %d-th data = %d\r\n", ++cnt, ptr->data);
        free(ptr);
    }
}

void linkedlist_print(NODE_ST_PTR head)
{
    int cnt = 0;
    NODE_ST_PTR ptr = (NODE_ST_PTR)malloc(sizeof(NODE_ST));
    while (head != NULL)
    {
        ptr = head;
        head = head->link;
        printf("Output %d-th data = %d\r\n", ++cnt, ptr->data);
    }
}

NODE_ST_PTR linkedlist_concat(NODE_ST_PTR head, NODE_ST_PTR body)
{
    NODE_ST_PTR ptr;

    if (head == NULL)
    {
        // Empty head list
        return body;
    }
    else
    {
        ptr = head;
        while (ptr->link != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = body;
    }
    return head;
}

void linkedlist_insert_after(NODE_ST_PTR head, int x, int y)
{
    NODE_ST_PTR ptr, new;
    if (head == NULL)
    {
        // Case I. Empty linked list
        printf("Empty linked list\r\n");
    }
    else
    {
        // Case II. Non-empty linked list
        ptr = head;
        while (ptr->link != NULL && ptr->data != x)
        {
            ptr = ptr->link;
        }
        if (ptr->data == x)
        {
            // Get the value
            new = (NODE_ST_PTR)malloc(sizeof(NODE_ST));
            new->data = y;
            new->link = ptr->link;
            ptr->link = new;
        }
        else
        {
            // No x data exist
            printf("node not found\r\n");
        }
    }
}

NODE_ST_PTR linkedlist_insert_before(NODE_ST_PTR head, int x, int y)
{
    NODE_ST_PTR pre, curr, new;
    pre = NULL;
    curr = head;
    while (curr != NULL && curr->data != x)
    {
        pre = curr;
        curr = curr->link;
    }
    if (curr == NULL)
    {
        printf("Node not found\r\n");
    }
    else
    {
        // Find the x value
        new = (NODE_ST_PTR)malloc(sizeof(NODE_ST));
        new->data = y;
        if (pre == NULL)
        {
            // x is at the first
            head = new;
        }
        else
        {
            pre->link = new;
        }
        new->link = curr;
    }
    return head;
}

NODE_ST_PTR linkedlist_order_insert(NODE_ST_PTR head, int x)
{
    NODE_ST_PTR pre, curr, new;
    new = (NODE_ST_PTR)malloc(sizeof(NODE_ST));
    new->data = x;

    curr = head;
    pre = NULL;
    while (curr != NULL && curr->data <= x)
    {
        pre = curr;
        curr = curr->link;
    }
    if (pre == NULL)
    {
        // x is the minimal
        head = new;
    }
    else
    {
        pre->link = new;
    }
    new->link = curr;

    return head;
}

NODE_ST_PTR linkedlist_reverse(NODE_ST_PTR head)
{
    NODE_ST_PTR pre, curr;
    curr = NULL;
    while (head != NULL)
    {
        pre = curr;
        curr = head;
        head = head->link;
        curr->link = pre;
    }
    head = curr;
    return head;
}

int linkedlist_get_length(NODE_ST_PTR head)
{
    int len = 0;
    NODE_ST_PTR curr = head;
    while (curr != NULL)
    {
        len++;
        curr = curr->link;
    }

    return len;
}
