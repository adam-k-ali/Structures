/*
 * Author: Adam Ali
 * Date: 3/12/2022
 * 
 * This file contains the implementation of the linked list data structure.
*/

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/*
 * Function: create_linkedlist
 * ----------------------------
 *  Creates a new linked list.
 * 
 * returns: a pointer to the newly created linked list
*/
struct linkedlist *create_linkedlist() {
    struct linkedlist *list = malloc(sizeof(struct linkedlist));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

/*
 * Function: size
 * ----------------------------
 * Get the size of the linked list
 * 
 * list: the linked list
 * 
 * returns: the size of the linked list
*/
size_t size(struct linkedlist *list) {
    size_t size = 0;
    struct node *current = list->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

/*
 * Function: empty
 * ----------------------------
 * Check if the linked list is empty
 * 
 * list: the linked list
 * 
 * returns: true if the linked list is empty, false otherwise
*/
bool empty(struct linkedlist *list) {
    return list->head == NULL;
}

/*
 * Function: value_at
 * ----------------------------
 * Get the value at the given index
 * 
 * list: the linked list
 * i: the index
 * 
 * returns: the value at the given index
*/
void *value_at(struct linkedlist *list, int i) {
    struct node *current = list->head;
    int index = 0;
    while (current != NULL) {
        if (index == i) {
            return current->data;
        }
        index++;
        current = current->next;
    }
    return NULL;
}


/*
 * Function: push_front
 * ----------------------------
 * Add a value to the front of the linked list
 * 
 * list: the linked list
 * value: the value to add
*/
void push_front(struct linkedlist *list, void *value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = list->head;
    list->head = new_node;
}

/*
 * Function: pop_front
 * ----------------------------
 * Remove the first value from the linked list
 * 
 * list: the linked list
 * 
 * returns: 0 if successful, -1 otherwise
*/
int pop_front(struct linkedlist *list) {
    if (list->head == NULL) {
        return -1;
    }
    struct node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    return 0;
}

/*
 * Function: push_back
 * ----------------------------
 * Add a value to the back of the linked list
 * 
 * list: the linked list
 * value: the value to add
*/
void push_back(struct linkedlist *list, void *value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

/*
 * Function: pop_back
 * ----------------------------
 * Remove the last value from the linked list
 * 
 * list: the linked list
 * 
 * returns: 0 if successful, -1 otherwise
*/
int pop_back(struct linkedlist *list) {
    if (list->head == NULL) {
        return -1;
    }
    struct node *current = list->head;
    while (current->next != list->tail) {
        current = current->next;
    }
    free(list->tail);
    list->tail = current;
    list->tail->next = NULL;
    return 0;
}

/*
 * Function: front
 * ----------------------------
 * Get the first value in the linked list
 * 
 * list: the linked list
 * 
 * returns: the first value in the linked list
*/
void *front(struct linkedlist *list) {
    if (list->head == NULL) {
        return NULL;
    }
    return list->head->data;
}

/*
 * Function: back
 * ----------------------------
 * Get the last value in the linked list
 * 
 * list: the linked list
 * 
 * returns: the last value in the linked list
*/
void *back(struct linkedlist *list) {
    if (list->tail == NULL) {
        return NULL;
    }
    return list->tail->data;
}

/*
 * Function: insert
 * ----------------------------
 * Insert a value at the given index
 * 
 * list: the linked list
 * i: the index
 * value: the value to insert
*/
void insert(struct linkedlist *list, int i, void *value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    if (i == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        struct node *current = list->head;
        int index = 0;
        while (current != NULL) {
            if (index == i - 1) {
                new_node->next = current->next;
                current->next = new_node;
                break;
            }
            index++;
            current = current->next;
        }
    }
}

/*
 * Function: erase
 * ----------------------------
 * Remove the value at the given index
 * 
 * list: the linked list
 * i: the index
 * 
 * returns: 0 if successful, -1 otherwise
*/
int erase(struct linkedlist *list, int i) {
    if (list->head == NULL) {
        return -1;
    }
    if (i == 0) {
        struct node *temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else {
        struct node *current = list->head;
        int index = 0;
        while (current != NULL) {
            if (index == i - 1) {
                struct node *temp = current->next;
                current->next = current->next->next;
                free(temp);
                break;
            }
            index++;
            current = current->next;
        }
    }
    return 0;
}

/*
 * Function: value_n_from_end
 * ----------------------------
 * Get the value at the given index from the end
 * 
 * list: the linked list
 * n: the index from the end
 * 
 * returns: the value at the given index from the end, NULL if the index is out of bounds
*/
void *value_n_from_end(struct linkedlist *list, int n) {
    struct node *current = list->head;
    int index = 0;
    while (current != NULL) {
        if (index == size(list) - n - 1) {
            return current->data;
        }
        index++;
        current = current->next;
    }
    return NULL;
}

/*
 * Function: reverse
 * ----------------------------
 * Reverse the linked list
 * 
 * list: the linked list
*/
void reverse(struct linkedlist *list) {
    struct node *current = list->head;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    list->head = prev;
}

/*
 * Function: remove_value
 * ----------------------------
 * Remove the first instance of the given value
 * 
 * list: the linked list
 * value: the value to remove
 * 
 * returns: 0 if successful, -1 otherwise
*/
int remove_value(struct linkedlist *list, void *value) {
    if (empty(list)) {
        return 0;
    }

    struct node *current = list->head;
    struct node *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->data, value) == 0) {
            if (current == list->head) {
                list->head = list->head->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return 0;
}