#include "test.h"

int main(int argc, char **argv) {
    bool skip_mem_check = (argc == 2) && (strcmp(argv[1], "--skip-mem-check") == 0);
    //Set malloc to always use mmap rather than the heap with sbrk
    //memory freed will not be placed on the free list
    //this allows us to make malloc fail reliably
    if (!skip_mem_check) {
        mallopt(M_MMAP_THRESHOLD, 0);
    }
    test_strlen();
    test_strcpy();
    test_strcmp();
    test_strdup(skip_mem_check);
    test_read();
    test_write();
    test_atoi_base();
    test_create_elem(skip_mem_check);
    test_list_push_front(skip_mem_check);
    test_list_size();
    test_list_sort();
    test_list_remove_if();
}
