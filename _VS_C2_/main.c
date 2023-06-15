#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int values1[5] = {47, 21, 52, 19, 63};
    int values2[5] = {147, 221, 352, 419, 563};
    NODE_ST_PTR ll_head0, ll_head1, ll_head2;

    printf("Main start\n");
    ll_head0 = linkedlist_create(values1, 0U);
    ll_head1 = linkedlist_create(values1, sizeof(values1) / sizeof(values1[0]));
    ll_head2 = linkedlist_create(values2, sizeof(values2) / sizeof(values2[0]));

    linkedlist_insert_after(ll_head0, 52, 99);
    ll_head0 = linkedlist_insert_before(ll_head0, 52, 99);

    linkedlist_insert_after(ll_head1, 52, 99);
    ll_head1 = linkedlist_insert_before(ll_head1, 47, 99);

    ll_head2 = linkedlist_order_insert(ll_head2, 399);
    ll_head2 = linkedlist_order_insert(ll_head2, 56);

    // linkedlist_print(ll_head0);
    // linkedlist_print(ll_head1);
    // linkedlist_print(ll_head2);

    ll_head1 = linkedlist_concat(ll_head0, ll_head1);
    ll_head2 = linkedlist_concat(ll_head1, ll_head2);

    ll_head2 = linkedlist_reverse(ll_head2);
    printf("len of ll_head2 = %d\r\n", linkedlist_get_length(ll_head2));

    linkedlist_print(ll_head0);
    linkedlist_print(ll_head1);
    linkedlist_print(ll_head2);

    linkedlist_release(ll_head0);
    linkedlist_release(ll_head1);
    linkedlist_release(ll_head2);

    printf("Main finished\r\n");
    return 0;
}