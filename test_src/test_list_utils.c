#include "test.h"

t_list *create_elem(void *data) {
    t_list *new_elem = malloc(sizeof(t_list));
    if (new_elem == NULL) {
        return NULL;
    }
    new_elem->data = data;
    new_elem->next = NULL;
    return new_elem;
}

void list_push_front(t_list **begin_list, void *data) {
    if (begin_list == NULL) {
        return;
    }
    t_list *new_elem = create_elem(data);
    if (!new_elem) {
        return;
    }
    new_elem->next = *begin_list;
    *begin_list = new_elem;
}

bool list_is_sorted(t_list *begin_list, int (*cmp)()) {
    if (begin_list == NULL) {
        return true;
    }
    while (begin_list->next != NULL) {
        if ((*cmp)(begin_list->data, begin_list->next->data) > 0) {
            return false;
        }
        begin_list = begin_list->next;
    }
    return true;
}

bool is_in_list(t_list *begin_list, void *data_ref, int (*cmp)()) {
    while (begin_list != NULL) {
        if ((*cmp)(begin_list->data, data_ref) == 0) {
            return true;
        }
    }
    return false;
}

t_list *create_list() {
    char *str_list[10];
    for (int i = 0; i < 10; i++) {
        str_list[i] = calloc(10, sizeof(char));
    }
    str_list[0][0] = '5';
    str_list[1][0] = '2';
    str_list[2][0] = '4';
    str_list[3][0] = '9';
    str_list[4][0] = '3';
    str_list[5][0] = '0';
    str_list[6][0] = '8';
    str_list[7][0] = '1';
    str_list[8][0] = '7';
    str_list[9][0] = '6';
    t_list *new_list = NULL;
    for (int i = 0; i < 10; i++) {
        list_push_front(&new_list, str_list[i]);
    }
    return new_list;
}

void free_list(t_list *list_begin) {
    t_list *to_free;
    while (list_begin) {
        to_free = list_begin;
        list_begin = list_begin->next;
        free(to_free->data);
        free(to_free);
    }
}
