#ifndef	TEST_H
#define	TEST_H

#include "push_swap.h"
#include <criterion/criterion.h>
#include <stdlib.h>

void expect_stack(t_stack *stack, int expected[], int size);
void expect_arr(int arr[], int expected[], int size);
#endif