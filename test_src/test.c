#include "test.h"
#include <stdio.h>
#include <unistd.h>

int main() {
    //Set malloc to always use mmap rather than the heap with sbrk
    //memory freed will not be placed on the free list
    //this allows us to make malloc fail reliably
    mallopt(M_MMAP_THRESHOLD, 0);
    test_strlen();
    test_strcpy();
    test_strcmp();
    test_strdup();
}
