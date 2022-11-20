#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

int size(struct node *head);
bool empty(struct node *head);

int value_at(struct node *head, int i, int *result);

void push_front(struct node **head, int value);
int pop_front(struct node **head, int *result);
void push_back(struct node **head, int value);
int pop_back(struct node **head, int *result);

int front(struct node *head, int *result);
int back(struct node *head, int *result);

int insert(struct node **head, int i, int value);
int erase(struct node *head, int i);

int value_n_from_end(struct node *head, int n, int *result);

void reverse(struct node **head);
int remove_value(struct node **head, int value);

#endif