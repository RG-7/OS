/*
	Write a program using C/C++/Java to simulate the first fit, best fit and worst fit memory
	allocation strategy. Assume memory chunk and initial requirement for memory block from
	your side.
*/

#include<stdio.h>

struct memory_block {
    int size;
    int id;
    int allocated;
    struct memory_block *next;
};

void add_block_to_list(struct memory_block *new_block, struct memory_block *start) {
    if(start == NULL) {
        start = new_block;
    } else {
        struct memory_block *current = start;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_block;
    }
}

struct memory_block *find_best_fit(struct memory_block *start, int size) {
    struct memory_block *current = start;
    struct memory_block *best_fit = NULL;
    int best_fit_size = 999999;
    while(current != NULL) {
        if(current->allocated == 0 && current->size >= size) {
            if(current->size < best_fit_size) {
                best_fit_size = current->size;
                best_fit = current;
            }
        }
        current = current->next;
    }
    return best_fit;
}

struct memory_block *find_worst_fit(struct memory_block *start, int size) {
    struct memory_block *current = start;
    struct memory_block *worst_fit = NULL;
    int worst_fit_size = -1;
    while(current != NULL) {
        if(current->allocated == 0 && current->size >= size) {
            if(current->size > worst_fit_size) {
                worst_fit_size = current->size;
                worst_fit = current;
            }
        }
        current = current->next;
    }
    return worst_fit;
}

struct memory_block *find_first_fit(struct memory_block *start, int size) {
    struct memory_block *current = start;
    while(current != NULL) {
        if(current->allocated == 0 && current->size >= size) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int allocate_memory(struct memory_block *start, int size, int allocation_strategy) {
    struct memory_block *allocated_block = NULL;
    switch(allocation_strategy) {
        case 1:
            allocated_block = find_first_fit(start, size);
            break;
        case 2:
            allocated_block = find_best_fit(start, size);
            break;
        case 3:
            allocated_block = find_worst_fit(start, size);
            break;
    }
    if(allocated_block != NULL) {
        allocated_block->allocated = 1;
        return allocated_block->id;
    } else {
        return -1;
    }
}

void deallocate_memory(struct memory_block *start, int id) {
    struct memory_block *current = start;
    while(current != NULL) {
        if(current->id == id) {
            current->allocated = 0;
            return;
        }
        current = current->next;
    }
}

int main() {
    struct memory_block *start = NULL;
    struct memory_block *new_block = NULL;

    int memory_chunks[] = {100, 200, 300};
    int num_memory_chunks = sizeof(memory_chunks) / sizeof(memory_chunks[0]);

    for(int i = 0; i < num_memory_chunks; i++) {
        new_block = (struct memory_block *)malloc(sizeof(struct memory_block));
        new_block->size = memory_chunks[i];
        new_block->id = i + 1;
        new_block->allocated = 0;
        new_block->next = NULL;
        add_block_to_list(new_block, start);
    }

    int initial_memory_blocks[] = {50, 150, 250};
    int num_initial_memory_blocks = sizeof(initial_memory_blocks) / sizeof(initial_memory_blocks[0]);

    for(int i = 0; i < num_initial_memory_blocks; i++) {
        int block_id = allocate_memory(start, initial_memory_blocks[i], 1);
        printf("Allocated memory block with id %d\n", block_id);
    }

    deallocate_memory(start, 1);
    printf("Deallocated memory block with id 1\n");

    return 0;
}
