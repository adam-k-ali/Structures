/*
 * Author: Adam Ali
 * Date: 3/12/2022
 *
 * This file contains tests for the linked list data structure.
 */
#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>
#include "single_list.h"

single_list *gen_list(size_t n) {
    single_list *list = create_single_list();
    if (n == 0) {
        return list;
    }

    for (size_t i = 0; i < n; i++) {
        void *data = malloc(sizeof(int));
        *(int *)data = i;
        push_back(list, data);
    }
    return list;
}

TEST(LinkedListTests, test_size) {
    single_list *list = gen_list(0);
    size_t i = size(list);
    EXPECT_EQ(i, 0);

    list = gen_list(1);
    i = size(list);
    EXPECT_EQ(i, 1);

    list = gen_list(10);
    i = size(list);
    EXPECT_EQ(i, 10);
}

TEST(LinkedListTests, test_empty) {
    single_list *list = gen_list(0);
    EXPECT_EQ(empty(list), 1);

    list = gen_list(1);
    EXPECT_EQ(empty(list), 0);
}

TEST(LinkedListTests, test_value_at) {
    single_list *list = gen_list(10);
    for (size_t i = 0; i < 10; i++) {
        EXPECT_EQ(*(int *)value_at(list, i), i);
    }
}

TEST(LinkedListTests, test_push_front) {
    single_list *list = gen_list(0);
    void *data = malloc(sizeof(int));
    *(int *)data = 0;
    push_front(list, data);
    EXPECT_EQ(*(int *)value_at(list, 0), 0);
    EXPECT_EQ(size(list), 1);

    list = gen_list(10);
    data = malloc(sizeof(int));
    *(int *)data = 10;
    push_front(list, data);
    EXPECT_EQ(*(int *)value_at(list, 0), 10);
    EXPECT_EQ(size(list), 11);
}

TEST(LinkedListTests, test_pop_front) {
    single_list *list = gen_list(10);
    pop_front(list);
    EXPECT_EQ(*(int *)value_at(list, 0), 1);
    EXPECT_EQ(size(list), 9);
}

TEST(LinkedListTests, test_push_back) {
    single_list *list = gen_list(0);
    void *data = malloc(sizeof(int));
    *(int *)data = 0;
    push_back(list, data);
    EXPECT_EQ(*(int *)value_at(list, 0), 0);
    EXPECT_EQ(size(list), 1);

    list = gen_list(10);
    data = malloc(sizeof(int));
    *(int *)data = 10;
    push_back(list, data);
    EXPECT_EQ(*(int *)value_at(list, 10), 10);
    EXPECT_EQ(size(list), 11);
}

TEST(LinkedListTests, test_pop_back) {
    single_list *list = gen_list(10);
    pop_back(list);
    EXPECT_EQ(*(int *)value_at(list, 8), 8);
    EXPECT_EQ(size(list), 9);
}

TEST(LinkedListTests, test_front) {
    single_list *list = gen_list(10);
    EXPECT_EQ(*(int *)front(list), 0);
}

TEST(LinkedListTests, test_back) {
    single_list *list = gen_list(10);
    EXPECT_EQ(*(int *)back(list), 9);
}

TEST(LinkedListTests, test_insert) {
    single_list *list = gen_list(10);
    void *data = malloc(sizeof(int));
    *(int *)data = 10;
    insert(list, 5, data);
    EXPECT_EQ(*(int *)value_at(list, 5), 10);
    EXPECT_EQ(size(list), 11);
}

TEST(LinkedListTests, test_erase) {
    single_list *list = gen_list(10);
    erase(list, 5);
    EXPECT_EQ(*(int *)value_at(list, 5), 6);
    EXPECT_EQ(size(list), 9);
}

TEST(LinkedListTests, test_value_n_from_end) {
    single_list *list = gen_list(10);
    EXPECT_EQ(*(int *)value_n_from_end(list, 5), 4);
}

TEST(LinkedListTests, test_reverse) {
    single_list *list = gen_list(10);
    reverse(list);
    EXPECT_EQ(*(int *)value_at(list, 0), 9);
    EXPECT_EQ(*(int *)value_at(list, 9), 0);
}

TEST(LinkedListTests, test_remove_value) {
    // [0, 1, 2, 3, 4, 6, 7, 8, 9]
    single_list *list = gen_list(10);

    void *data = malloc(sizeof(int));
    *(int *)data = 5;
    int result = remove_value(list, data);
    EXPECT_NE(result, 0);
    EXPECT_EQ(*(int *)value_at(list, 5), 6);
    EXPECT_EQ(size(list), 9);
}