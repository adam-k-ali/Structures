/*
 * Author: Adam Ali
 * Date: 7/12/2022
 *
 * This file contains tests for the stack data structure.
 */
#include "gtest/gtest.h"
#include <iostream>
#include <cstdlib>
#include "stack.h"

TEST(StackTests, test_create_stack) {
    stack *s = create_stack(10);
    EXPECT_EQ(s->top, -1);
    EXPECT_EQ(s->capacity, 10);
}

TEST(StackTests, test_is_empty) {
    stack *s = create_stack(10);
    EXPECT_EQ(is_empty(s), 1);
    push(s, (void *)1);
    EXPECT_EQ(is_empty(s), 0);
}

TEST(StackTests, test_is_full) {
    stack *s = create_stack(1);
    EXPECT_EQ(is_full(s), 0);
    push(s, (void *)1);
    EXPECT_EQ(is_full(s), 1);
}


TEST(StackTests, test_push) {
    stack *s = create_stack(10);
    for (int i = 0; i < 10; i++) {
        push(s, (void *)i);
        EXPECT_EQ(s->top, i);
        EXPECT_EQ(s->array[i], (void *)i);
    }
}

TEST(StackTests, test_pop) {
    stack *s = create_stack(10);
    for (int i = 0; i < 10; i++) {
        push(s, (void *)i);
    }
    for (int i = 9; i >= 0; i--) {
        EXPECT_EQ(pop(s), (void *)i);
    }
}

TEST(StackTests, test_peek) {
    stack *s = create_stack(10);
    for (int i = 0; i < 10; i++) {
        push(s, (void *)i);
        EXPECT_EQ(peek(s), (void *)i);
    }
}