#include <stddef.h>
#include <stdlib.h>
#include "linkedlist.h"

/*
 * Returns the size of the linked list
 *
*/
int size(struct node *head) {
    struct node *tmp = head;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}

/*
* Returns true if the linked list is empty, false otherwise
*/
bool empty(struct node *head) {
    return head == NULL;
}

/*
* Find the value at a given index.
* Returns an error code or 0.
*/
int value_at(struct node *head, int i, int *result) {
    // Check if i > size(head)
    if (i > size(head) - 1) {
        return -1;
    }
    // Check if i < 0
    if (i < 0) {
        return -1;
    }

    // Iterate through the list until i == 0
    struct node *tmp = head;
    while (tmp != NULL && i > 0) {
        i--;
        tmp = tmp->next;
    }
    *result = tmp->data;
    return 0;
}

/*
* Adds a value to the front of the list
*/
void push_front(struct node **head, int value) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

/*
* Removes the value at the front of the list
* Returns an error code or 0.
*/
int pop_front(struct node **head, int *result) {
    if (empty(*head)) {
        return -1;
    }
    struct node *tmp = *head;
    *result = tmp->data;

    if (tmp->next == NULL) {
        *head = NULL;
    } else {
        *head = tmp->next;
    }
    free(tmp);
    return 0;
}

/*
* Adds a value to the end of the list
*/
void push_back(struct node **head, int value) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    if (empty(*head)) {
        *head = new_node;
    } else {
        struct node *tmp = *head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
}

/*
* Removes the value at the end of the list
* Returns an error code or 0.
*/
int pop_back(struct node **head, int *result) {
    if (empty(*head)) {
        return -1;
    }
    struct node *tmp = *head;
    if (tmp->next == NULL) {
        *result = tmp->data;
        *head = NULL;
        free(tmp);
    } else {
        while (tmp->next->next != NULL) {
            tmp = tmp->next;
        }
        *result = tmp->next->data;
        free(tmp->next);
        tmp->next = NULL;
    }
    return 0;
}

/*
* Returns the value of the front element
* Returns an error code or 0.
*/
int front(struct node *head, int *result) {
    if (empty(head)) {
        return -1;
    }
    *result = head->data;
    return 0;
}

int back(struct node *head, int *result) {
    if (empty(head)) {
        return -1;
    }
    // Move to the end of the list
    struct node *tmp = head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    *result = tmp->data;
    return 0;
}

int insert(struct node **head, int i, int value) {
    if (i > size(*head)) {
        return -1;
    }
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = value;
    if (i == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct node *tmp = *head;
        while (i > 1) {
            i--;
            tmp = tmp->next;
        }
        new_node->next = tmp->next;
        tmp->next = new_node;
    }
    return 0;
}

int erase(struct node *head, int i) {
    if (i > size(head)) {
        return -1;
    }
    if (i == 0) {
        // Hold the node to replace in a temporary variable
        struct node *tmp = head;
        // Replace the node with the next node
        head = head->next;
        // Free the memory
        free(tmp);
    } else {
        // Move to the node before the one to be deleted
        struct node *tmp = head;
        while (i > 1) {
            i--;
            tmp = tmp->next;
        }
        // Hold the node to replace in a temporary variable
        struct node *tmp2 = tmp->next;
        // Replace the node
        tmp->next = tmp->next->next;
        // Free the memory
        free(tmp2);
    }
    return 0;
}

int value_n_from_end(struct node *head, int n, int *result) {
    return value_at(head, size(head) - (n + 1), result);
}

void reverse(struct node **head) {
    struct node *prev = NULL;
    struct node *current = *head;
    struct node *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

/*
Removes the first node with the given value
Returns an error code or 0.
Error code -1: The list is empty
Error code -2: The value is not in the list
*/
int remove_value(struct node **head, int value) {
    if (empty(*head)) {
        return -1;
    }
    struct node *tmp = *head;
    if (tmp->data == value) {
        *head = tmp->next;
        free(tmp);
        return 0;
    }
    while (tmp->next != NULL) {
        if (tmp->next->data == value) {
            struct node *tmp2 = tmp->next;
            tmp->next = tmp->next->next;
            free(tmp2);
            return 0;
        }
        tmp = tmp->next;
    }
    return -2;
}