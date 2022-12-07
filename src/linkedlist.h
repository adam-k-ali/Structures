/*
 * Author: Adam Ali
 * Date: 3/12/2022
 * 
 * This file contains the definition of the linked list data structure.
*/

#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Struct: node
 * ----------------------------
 *  A node in the linked list.
 *
 *  data: the data stored in the node
 *  next: a pointer to the next node in the linked list
*/
struct node {
    void *data;
    struct node *next;
};

/*
 * Struct: linkedlist
 * ----------------------------
 * A linked list.
 *
 * head: a pointer to the head of the linked list
 * tail: a pointer to the tail of the linked list
 */
struct linkedlist {
    struct node *head;
    struct node *tail;
};

struct linkedlist *create_linkedlist();

size_t size(struct linkedlist *list);
bool empty(struct linkedlist *list);

void *value_at(struct linkedlist *list, int i);

void push_front(struct linkedlist *list, void *value);
int pop_front(struct linkedlist *list);

void push_back(struct linkedlist *list, void *value);
int pop_back(struct linkedlist *list);

void *front(struct linkedlist *list);
void *back(struct linkedlist *list);

void insert(struct linkedlist *list, int i, void *value);
int erase(struct linkedlist *list, int i);

void *value_n_from_end(struct linkedlist *list, int n);

void reverse(struct linkedlist *list);
int remove_value(struct linkedlist *list, void *value);

#ifdef __cplusplus
}
#endif
#endif