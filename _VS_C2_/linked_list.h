#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>

// Structure definition and Alias
/// @brief
typedef struct ListNode
{
    /* data */
    int data;
    struct ListNode *link;
} NODE_ST, *NODE_ST_PTR;

// Function prototype
void linkedlist_test(void);

/// @brief
/// @param arr
/// @param num
NODE_ST_PTR linkedlist_create(int *arr, int num);

/// @brief
/// @param head
void linkedlist_release(NODE_ST_PTR head);

/// @brief
/// @param head
void linkedlist_print(NODE_ST_PTR head);

/// @brief
/// @param head
/// @param body
/// @return
NODE_ST_PTR linkedlist_concat(NODE_ST_PTR head, NODE_ST_PTR body);

/// @brief
/// @param head
/// @param x
/// @param y
void linkedlist_insert_after(NODE_ST_PTR head, int x, int y);

/// @brief
/// @param head
/// @param x
/// @param y
NODE_ST_PTR linkedlist_insert_before(NODE_ST_PTR head, int x, int y);

/// @brief
/// @param head
/// @param x
/// @return
NODE_ST_PTR linkedlist_order_insert(NODE_ST_PTR head, int x);

/// @brief
NODE_ST_PTR linkedlist_reverse(NODE_ST_PTR head);

/// @brief
/// @param
/// @return
int linkedlist_get_length(NODE_ST_PTR head);

#endif