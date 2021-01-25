#ifndef LL_H
#define LL_H

typedef struct node_t {
    void * data;
    struct node_t* next;
    struct node_t*  prev;
} node_t;

typedef struct ll_t {
    int size;
    struct node_t* head;
    struct node_t* tail;
} ll_t;

/* Initialize list and return pointer to head of list */
ll_t* init_ll(); 

/* Append methods for list */
int push_front(struct ll_t*, void *);
int push_back(struct ll_t*, void *);

/* Remove methods for list */

void * pop_front(struct ll_t*);
void * pop_back(struct ll_t*);

/* Print method for list */
void print_list(struct ll_t* , void(*ptr)(void *));
void print_int(void *);
void print_string(void *);


/* Methods for memory management*/
void clear_mem(struct ll_t*);

#endif
