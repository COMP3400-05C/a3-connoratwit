#include <stdio.h>
#include <stdlib.h>
#include "parta.h"

struct ll_node *ll_head(struct ll_node *head) {
    return head;
}

struct ll_node *ll_tail(struct ll_node *head) {
    if (head == NULL) return NULL;
    struct ll_node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    return curr;
}

int ll_size(struct ll_node *head) {
    int count = 0;
    struct ll_node *curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

struct ll_node *ll_find(struct ll_node *head, int value) {
    struct ll_node *curr = head;
    while (curr != NULL) {
        if (curr->data == value)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

int *ll_toarray(struct ll_node *head) {
    int size = ll_size(head);
    if (size == 0) return NULL;

    int *arr = malloc(sizeof(int) * size);
    if (arr == NULL) return NULL;

    struct ll_node *curr = head;
    for (int i = 0; i < size; i++) {
        arr[i] = curr->data;
        curr = curr->next;
    }
    return arr;
}

struct ll_node *ll_create(int data) {
    struct ll_node *node = malloc(sizeof(struct ll_node));
    if (node == NULL) return NULL;
    node->data = data;
    node->next = NULL;
    return node;
}

void ll_destroy(struct ll_node *head) {
    struct ll_node *curr = head;
    while (curr != NULL) {
        struct ll_node *temp = curr;
        curr = curr->next;
        free(temp);
    }
}

void ll_append(struct ll_node *head, int data) {
    if (head == NULL) return;
    struct ll_node *tail = ll_tail(head);
    struct ll_node *new_node = ll_create(data);
    if (new_node == NULL) return;
    tail->next = new_node;
}

struct ll_node *ll_fromarray(int *data, int len) {
    if (data == NULL || len <= 0) return NULL;

    struct ll_node *head = ll_create(data[0]);
    if (head == NULL) return NULL;

    struct ll_node *curr = head;
    for (int i = 1; i < len; i++) {
        struct ll_node *node = ll_create(data[i]);
        if (node == NULL) {
            ll_destroy(head);
            return NULL;
        }
        curr->next = node;
        curr = node;
    }
    return head;
}

struct ll_node *ll_remove(struct ll_node *head, int value) {
    if (head == NULL) return NULL;

    struct ll_node *curr = head;
    struct ll_node *prev = NULL;

    while (curr != NULL) {
        if (curr->data == value) {
            if (prev == NULL) {
                struct ll_node *new_head = curr->next;
                free(curr);
                return new_head;
            } else {
                prev->next = curr->next;
                free(curr);
                return head;
            }
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}
