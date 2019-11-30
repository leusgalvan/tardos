#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void _assert(int cond, char *msg);
void test_create_empty_list();
void test_create_empty_list_size();
void test_push_1_non_empty();
void test_push_1_size_1();
void test_append_1_non_empty();
void test_append_1_size_1();
void test_pop_empty_list();
void test_push_1_pop();
void test_append_1_pop();
void test_push_1_pop_empty();
void test_append_1_pop_empty();
void test_push_2_pop();
void test_append_2_pop();
void test_push_2_pop_size();
void test_append_2_pop_size();
void test_remove_found();
void test_remove_not_found();
void test_print();
void test_free();

int main() {
    test_create_empty_list();
    test_create_empty_list_size();
	test_push_1_non_empty();
	test_push_1_size_1();
	test_append_1_non_empty();
	test_append_1_size_1();
	test_pop_empty_list();
	test_push_1_pop();
	test_append_1_pop();
	test_push_1_pop_empty();
	test_append_1_pop_empty();
	test_push_2_pop();
	test_append_2_pop();
	test_push_2_pop_size();
	test_append_2_pop_size();
	test_remove_found();
    test_remove_not_found();
    test_print();
    test_free();

    return 0;
}

int cmp_ints(void *v1, void *v2) {
    int x = *((int*) v1);
    int y = *((int*) v2);
    return x < y? -1: x > y? 1: 0;
}

char *intToStr(void *elem) {
    char *s = malloc(sizeof(char) * 16);
    int i = *((int*)elem);
    return itoa(i, s, 10);
}

void test_create_empty_list() {
    doubly_linked_list *l = dll_create(cmp_ints);
    _assert(dll_is_empty(l), "Create empty list");
}

void test_create_empty_list_size() {
    doubly_linked_list *l = dll_create(cmp_ints);
    _assert(dll_size(l) == 0, "Create empty list yields size 0");
}

void test_push_1_non_empty() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    dll_push(l, &x);
    _assert(!dll_is_empty(l), "Pushing an element makes list non empty");
}

void test_push_1_size_1() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    dll_push(l, &x);
    _assert(dll_size(l) == 1, "Pushing an element makes list have size 1");
}

void test_append_1_non_empty() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    dll_append(l, &x);
    _assert(!dll_is_empty(l), "Appending an element makes list non empty");
}

void test_append_1_size_1() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    dll_append(l, &x);
    _assert(dll_size(l) == 1, "Appending an element makes list have size 1");
}

void test_pop_empty_list() {
    doubly_linked_list *l = dll_create(cmp_ints);
    _assert(dll_pop(l) == NULL, 
            "Popping from empty list yields NULL");
}

void test_push_1_pop() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    dll_push(l, &x);
    _assert(*((int*)dll_pop(l)) == 5, 
            "Pushing an element leaves it as the head of the list");
}

void test_append_1_pop() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    dll_append(l, &x);
    _assert(*((int*)dll_pop(l)) == 5, 
            "Appending an element to an empty list leaves it as the head");
}

void test_push_1_pop_empty() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    dll_push(l, &x);
    dll_pop(l);
    _assert(dll_is_empty(l), 
            "Popping from one element list leaves the list empty (push)");
}

void test_append_1_pop_empty() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    dll_append(l, &x);
    dll_pop(l);
    _assert(dll_is_empty(l), 
            "Popping from one element list leaves the list empty (append)");
}

void test_push_2_pop() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    int y = 6;
    dll_push(l, &x);
    dll_push(l, &y);
    _assert(*((int*)dll_pop(l)) == 6, 
            "Pushing twice leaves second element as head");
}

void test_append_2_pop() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    int y = 6;
    dll_append(l, &x);
    dll_append(l, &y);
    _assert(*((int*)dll_pop(l)) == 5, 
            "Appending twice leaves first element as head");
}

void test_push_2_pop_size() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    int y = 6;
    dll_push(l, &x);
    dll_push(l, &y);
    int prev_size = dll_size(l);
    dll_pop(l);
    _assert(dll_size(l) == prev_size - 1,
            "Pop reduces size by 1 (push)");
}

void test_append_2_pop_size() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int x = 5;
    int y = 6;
    dll_append(l, &x);
    dll_append(l, &y);
    int prev_size = dll_size(l);
    dll_pop(l);
    _assert(dll_size(l) == prev_size - 1,
            "Pop reduces size by 1 (append)");
}

void test_remove_found() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int vals[] = {6, 4, 10};
    int elem = 4;
    for(int i = 0; i < 3; i++) dll_append(l, &vals[i]);
    int found = dll_remove(l, &elem);
    _assert(found, "Removing an existing element yields true");
    int size = dll_size(l);
    int first = *((int*)dll_pop(l));
    int second = *((int*)dll_pop(l));
    _assert(size == 2, "Removing an existing element reduces size by 1");
    _assert(first == 6 && second == 10, 
            "Removing the element leaves the list without the element");
}

void test_remove_not_found() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int vals[] = {6, 4};
    int elem = 5;
    for(int i = 0; i < 2; i++) dll_append(l, &vals[i]);
    int found = dll_remove(l, &elem);
    _assert(!found, "Removing a non existing element yields false");
    int size = dll_size(l);
    int first = *((int*)dll_pop(l));
    int second = *((int*)dll_pop(l));
    _assert(size == 2, "Removing a non existing does not alter size");
    _assert(first == 6 && second == 4, 
            "Removing non existing element does not alter list");
}

void test_print() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int values[] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++) dll_push(l, &values[i]);
    dll_println(l, intToStr);
    dll_remove(l, &values[2]);
    dll_println(l, intToStr);
    _assert(1, "Printing the list should work");
}

void test_free() {
    doubly_linked_list *l = dll_create(cmp_ints);
    int values[] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++) dll_push(l, &values[i]);
    dll_free(l);
    _assert(1, "Freeing the list should work");
}

void _assert(int cond, char *msg) {
    printf("%s: %s\n", msg, cond? "PASSED": "FAILED");
}

