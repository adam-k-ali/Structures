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
typedef struct single_list {
    struct node *head;
    struct node *tail;
} single_list;

single_list *create_single_list();

size_t size(single_list *list);
bool empty(single_list *list);

void *value_at(single_list *list, int i);

void push_front(single_list *list, void *value);
int pop_front(single_list *list);

void push_back(single_list *list, void *value);
int pop_back(single_list *list);

void *front(single_list *list);
void *back(single_list *list);

void insert(single_list *list, int i, void *value);
int erase(single_list *list, int i);

void *value_n_from_end(single_list *list, int n);

void reverse(single_list *list);
int remove_value(single_list *list, void *value);

#ifdef __cplusplus
}
#endif
#endif