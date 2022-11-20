#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "linkedlist.h"

void gen_list(struct node **head, int n) {
    if (n == 0) {
        *head = NULL;
        return;
    }
    
    // Create the first node
    struct node *tmp = malloc(sizeof(struct node));
    tmp->data = 0;
    tmp->next = NULL;
    *head = tmp;

    // Create the rest of the nodes
    for (int i = 1; i < n; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = i;
        new_node->next = NULL;
        tmp->next = new_node;
        tmp = new_node;
    }
}

int fail(int testId, char* msg) {
    printf("\033[1;31m");
    printf("[x] ");
    printf("\033[0m");
    printf("(%d) %s\n", testId, msg);
    return 1;
}

int pass(char* msg) {
    printf("\033[1;32m");
    printf("[/] ");
    printf("\033[0m");
    printf("%s\n", msg);
    return 0;
}

int test_size() {
    struct node *head = NULL;
    int i = size(head);
    if (i != 0) {
        return fail(1, "test_size failed: size != 0");
    }

    gen_list(&head, 1);
    i = size(head);
    if (i != 1) {
        return fail(2, "test_size failed: size != 1");
    }

    return pass("test_size passed");
}

int test_empty() {
    struct node *head = NULL;
    bool f = empty(head);
    if (!f) {
        return fail(1, "test_empty failed: empty != true");
    }

    gen_list(&head, 1);
    f = empty(head);
    if (f) {
        return fail(2, "test_empty failed: empty != false");
    }
    return pass("test_empty passed");
}

int test_value_at() {
    // Test empty list
    struct node *head = NULL;
    int result;
    int i = value_at(head, 0, &result);
    if (i != -1) {
        return fail(1, "test_value_at failed: i != -1");
    }

    // Test list with one element
    head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    i = value_at(head, 0, &result);
    if (i != 0) {
        return fail(2, "test_value_at failed: i != 0");
    }
    if (result != 1) {
        return fail(3, "test_value_at failed: result != 1");
    }

    // Test i > size(head)
    i = value_at(head, 1, &result);
    if (i != -1) {
        return fail(4, "test_value_at failed: i != -1");
    }
    // Test i < 0
    i = value_at(head, -1, &result);
    if (i != -1) {
        return fail(5, "test_value_at failed: i != -1");
    }
    return pass("test_value_at passed");
}

int test_push_front() {
    // Test empty list
    struct node *head = NULL;
    push_front(&head, 1);
    if (empty(head)) {
        return fail(1, "test_push_front failed: empty != false");
    }
    if (head->data != 1) {
        return fail(2, "test_push_front failed: head->data != 1");
    }
    if (head->next != NULL) {
        return fail(3, "test_push_front failed: head->next != NULL");
    }

    // Test list with one element
    push_front(&head, 2);
    if (head->data != 2) {
        return fail(4, "test_push_front failed: head->data != 2");
    }
    if (head->next->data != 1) {
        return fail(5, "test_push_front failed: head->next->data != 1");
    }
    if (head->next->next != NULL) {
        return fail(6, "test_push_front failed: head->next->next != NULL");
    }
    return pass("test_push_front passed");
}

int test_pop_front() {
    // Test empty list
    struct node *head = NULL;
    int result;
    int i = pop_front(&head, &result);
    if (i != -1) {
        return fail(1, "test_pop_front failed: i != -1");
    }
    free(head);

    // Test list with one element
    head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    i = pop_front(&head, &result);
    if (i != 0) {
        return fail(2, "test_pop_front failed: i != 0");
    }
    if (result != 1) {
        return fail(3, "test_pop_front failed: result != 1");
    }
    if (head != NULL) {
        return fail(4, "test_pop_front failed: head != NULL");
    }

    // Test list with two elements
    head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = malloc(sizeof(struct node));
    head->next->data = 2;
    head->next->next = NULL;
    i = pop_front(&head, &result);
    if (i != 0) {
        return fail(5, "test_pop_front failed: i != 0");
    }
    if (result != 1) {
        return fail(6, "test_pop_front failed: result != 1");
    }
    if (head->data != 2) {
        return fail(7, "test_pop_front failed: head->data != 2");
    }
    if (head->next != NULL) {
        return fail(8, "test_pop_front failed: head->next != NULL");
    }
    return pass("test_pop_front passed");
}

int test_push_back() {
    // Test empty list
    struct node *head = NULL;
    push_back(&head, 1);
    if (empty(head)) {
        return fail(1, "test_push_back failed: empty != false");
    }
    if (head->data != 1) {
        return fail(2, "test_push_back failed: head->data != 1");
    }
    if (head->next != NULL) {
        return fail(3, "test_push_back failed: head->next != NULL");
    }

    // Test list with one element
    push_back(&head, 2);
    if (head->data != 1) {
        return fail(4, "test_push_back failed: head->data != 1");
    }
    if (head->next->data != 2) {
        return fail(5, "test_push_back failed: head->next->data != 2");
    }
    if (head->next->next != NULL) {
        return fail(6, "test_push_back failed: head->next->next != NULL");
    }
    return pass("test_push_back passed");
}

int test_pop_back() {
    // Test empty list
    struct node *head = NULL;
    int result;
    int i = pop_back(&head, &result);
    if (i != -1) {
        return fail(1, "test_pop_back failed: i != -1");
    }
    free(head);

    // Test list with one element
    head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    i = pop_back(&head, &result);
    if (i != 0) {
        return fail(2, "test_pop_back failed: i != 0");
    }
    if (result != 1) {
        return fail(3, "test_pop_back failed: result != 1");
    }
    if (head != NULL) {
        return fail(4, "test_pop_back failed: head != NULL");
    }

    // Test list with two elements
    head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = malloc(sizeof(struct node));
    head->next->data = 2;
    head->next->next = NULL;
    i = pop_back(&head, &result);
    if (i != 0) {
        return fail(5, "test_pop_back failed: i != 0");
    }
    if (result != 2) {
        return fail(6, "test_pop_back failed: result != 2");
    }
    if (head->data != 1) {
        return fail(7, "test_pop_back failed: head->data != 1");
    }
    if (head->next != NULL) {
        return fail(8, "test_pop_back failed: head->next != NULL");
    }
    return pass("test_pop_back passed");
}

int test_front() {
    // Test empty list
    struct node *head = NULL;
    int result;
    int i = front(head, &result);
    if (i != -1) {
        return fail(1, "test_front failed: i != -1");
    }

    // Test list with one element
    gen_list(&head, 1);
    i = front(head, &result);
    if (i != 0) {
        return fail(2, "test_front failed: i != 0");
    }
    if (result != 0) {
        return fail(3, "test_front failed: result != 0");
    }

    // Test list with two elements
    gen_list(&head, 2);
    i = front(head, &result);
    if (i != 0) {
        return fail(4, "test_front failed: i != 0");
    }
    if (result != 0) {
        return fail(5, "test_front failed: result != 0");
    }
    return pass("test_front passed");
}

int test_back() {
    // Test empty list
    struct node *head = NULL;
    int result;
    int i = back(head, &result);
    if (i != -1) {
        return fail(1, "test_back failed: i != -1");
    }

    // Test list with one element
    gen_list(&head, 1);
    i = back(head, &result);
    if (i != 0) {
        return fail(2, "test_back failed: i != 0");
    }
    if (result != 0) {
        return fail(3, "test_back failed: result != 0");
    }

    // Test list with two elements
    gen_list(&head, 2);
    i = back(head, &result);
    if (i != 0) {
        return fail(4, "test_back failed: i != 0");
    }
    if (result != 1) {
        return fail(5, "test_back failed: result != 1");
    }
    return pass("test_back passed");
}

int test_insert() {
    // Test empty list
    struct node *head = NULL;
    insert(&head, 0, 1);
    if (empty(head)) {
        return fail(1, "test_insert failed: empty != false");
    }
    if (head->data != 1) {
        return fail(2, "test_insert failed: head->data != 1");
    }
    if (head->next != NULL) {
        return fail(3, "test_insert failed: head->next != NULL");
    }

    // Test list with one element
    insert(&head, 1, 2);
    if (head->data != 1) {
        return fail(4, "test_insert failed: head->data != 1");
    }
    if (head->next->data != 2) {
        return fail(5, "test_insert failed: head->next->data != 2");
    }
    if (head->next->next != NULL) {
        return fail(6, "test_insert failed: head->next->next != NULL");
    }

    // Test list with two elements
    insert(&head, 1, 3);
    if (head->data != 1) {
        return fail(7, "test_insert failed: head->data != 1");
    }
    if (head->next->data != 3) {
        return fail(8, "test_insert failed: head->next->data != 3");
    }
    if (head->next->next->data != 2) {
        return fail(9, "test_insert failed: head->next->next->data != 2");
    }
    if (head->next->next->next != NULL) {
        return fail(10, "test_insert failed: head->next->next->next != NULL");
    }
    return pass("test_insert passed");
}

int test_value_n_from_end() {
    // Test empty list
    struct node *head = NULL;
    int result;
    int i = value_n_from_end(head, 0, &result);
    if (i != -1) {
        return fail(1, "test_value_n_from_end failed: i != -1");
    }

    // Test list with one element
    gen_list(&head, 1);
    i = value_n_from_end(head, 0, &result);
    if (i != 0) {
        return fail(2, "test_value_n_from_end failed: i != 0");
    }
    if (result != 0) {
        return fail(3, "test_value_n_from_end failed: result != 0");
    }

    // Test list with two elements
    gen_list(&head, 2);
    i = value_n_from_end(head, 0, &result);
    if (i != 0) {
        return fail(4, "test_value_n_from_end failed: i != 0");
    }
    if (result != 1) {
        return fail(5, "test_value_n_from_end failed: result != 1");
    }
    i = value_n_from_end(head, 1, &result);
    if (i != 0) {
        return fail(6, "test_value_n_from_end failed: i != 0");
    }
    if (result != 0) {
        return fail(7, "test_value_n_from_end failed: result != 0");
    }
    return pass("test_value_n_from_end passed");
}

int test_reverse() {
    // Test empty list
    struct node *head = NULL;
    reverse(&head);
    if (!empty(head)) {
        return fail(1, "test_reverse failed: empty != true");
    }

    // Test list with one element
    gen_list(&head, 1);
    reverse(&head);
    if (head->data != 0) {
        return fail(2, "test_reverse failed: head->data != 0");
    }
    if (head->next != NULL) {
        return fail(3, "test_reverse failed: head->next != NULL");
    }

    // Test list with two elements
    gen_list(&head, 2);
    reverse(&head);
    if (head->data != 1) {
        return fail(4, "test_reverse failed: head->data != 1");
    }
    if (head->next->data != 0) {
        return fail(5, "test_reverse failed: head->next->data != 0");
    }
    if (head->next->next != NULL) {
        return fail(6, "test_reverse failed: head->next->next != NULL");
    }
    return pass("test_reverse passed");
}

int test_remove_value() {
    // Test empty list
    struct node *head = NULL;
    int i = remove_value(&head, 0);
    if (!empty(head) || i != -1) {
        return fail(1, "test_remove_value failed: empty != true || i != -1");
    }

    // Test list with one element
    gen_list(&head, 1);
    remove_value(&head, 0);
    if (!empty(head)) {
        return fail(2, "test_remove_value failed: empty != true");
    }

    // Test list with two elements
    gen_list(&head, 2);
    remove_value(&head, 0);
    if (head->data != 1) {
        return fail(3, "test_remove_value failed: head->data != 1");
    }
    if (head->next != NULL) {
        return fail(4, "test_remove_value failed: head->next != NULL");
    }
    gen_list(&head, 2);
    remove_value(&head, 1);
    if (head->data != 0) {
        return fail(5, "test_remove_value failed: head->data != 0");
    }
    if (head->next != NULL) {
        return fail(6, "test_remove_value failed: head->next != NULL");
    }

    // Test element not in list
    gen_list(&head, 2);
    i = remove_value(&head, 2);
    if (i != -2) {
        return fail(7, "test_remove_value failed: i != -2");
    }
    return pass("test_remove_value passed");
}

void run_tests() {
    int result = 0;

    // Run linked list tests
    printf("=== Linked List Tests ===\n");
    int ll_tests = 0;
    ll_tests += test_size();
    ll_tests += test_empty();
    ll_tests += test_value_at();
    ll_tests += test_push_front();
    ll_tests += test_pop_front();
    ll_tests += test_push_back();
    ll_tests += test_pop_back();
    ll_tests += test_front();
    ll_tests += test_back();
    ll_tests += test_insert();
    ll_tests += test_value_n_from_end();
    ll_tests += test_reverse();

    if (ll_tests == 0) {
        printf("=== Linked List Tests Passed ===\n");
    } else {
        printf("=== %d Linked List Tests Failed ===\n", ll_tests);
    }
    result += ll_tests;

    // Print final result
    if (result == 0) {
        printf("=== All tests passed ===\n");
    } else {
        printf("=== %d tests failed ===\n", result);
    }
}

/*
 * Runs tests on the implementations 
*/
int main(int argc, char *argv[]) {
    // Check if we should run tests.
    if (argc > 1 && strcmp(argv[1], "test") == 0) {
        printf("Running tests\n");
        run_tests();
        return 0;
    }

    return 0;
}