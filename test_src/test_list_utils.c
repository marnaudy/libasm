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
