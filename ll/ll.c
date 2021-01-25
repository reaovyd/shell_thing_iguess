#include <stdio.h>
#include <stdlib.h>
#include "ll.h"


/* Allocating mem for new node */
static node_t* init_node_t(void * data) {
    node_t* nn = malloc(sizeof(node_t));
    if(nn == NULL) {
        return NULL;
    }
    nn->data = data;
    nn->prev = NULL;
    nn->next = NULL;
    return nn;
}

static node_t* init_node_tnp(void * data, node_t* prev, node_t* next) {
    node_t* nn = malloc(sizeof(node_t));
    if(nn == NULL) {
        return NULL;
    }
    nn->data = data;
    nn->prev = prev;
    nn->next = next;
    return nn;
}

/* Initializing new list */

ll_t* init_ll() {
    ll_t* list = malloc(sizeof(struct ll_t));
    if(list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

/* Adds directly to front of the list  */
int push_front(struct ll_t* list, void* data) {
    node_t* new_node = init_node_t(data);
    if(new_node == NULL) {
        return 0;
    }
    if(list->size == 0) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return 1;
    }
    node_t* tmpNode = list->head;
    new_node->next = tmpNode;
    tmpNode->prev = new_node;

    list->head = new_node;

    list->size++;
    return 1;
}

/* Adds directly to back of the list */
int push_back(struct ll_t* list, void* data) {
    if(list->head == NULL || list->size == 0) {
        int bool_cond = push_front(list, data);
        if(!bool_cond) {
            return 0;
        }
        return 1;
    }
    node_t* new_node = init_node_tnp(data, list->tail, NULL);
    if(new_node == NULL) {
        return 0;
    }
    list->tail->next = new_node;
    list->tail = new_node;
    list->size++;
    return 1;
}


/* Removal methods */

/* Returns the front of the list */
void * pop_front(struct ll_t* list) {
    if(list->head == NULL) {
        return NULL;
    }
    void* nn_d = list->head->data;
    node_t* nn = list->head;

    list->head = list->head->next;
    free(nn);
    list->size--;
    return nn_d;
}

void * pop_back(struct ll_t* list) {
   if(list->size == 0) {
        return NULL;
   }
   // If there's only one node
   if(list->size == 1) {
        pop_front(list);
        return NULL;
   }

   void* nn_dt = list->tail->data; 
   node_t* fr_t = list->tail;
   node_t* nn_d = fr_t->prev;
   nn_d->next = NULL;
   list->tail = nn_d;

   free(fr_t);
   list->size--;
   return nn_dt;
}

/*  Printing methods */
void print_list(struct ll_t* list, void(*ptr)(void *)) {
    if(list->size == 0 || list == NULL) {
        printf("[]\n");
        return;
    }
    node_t* crs = list->head;
    printf("[");
    for(; crs->next != NULL; crs = crs->next) {
        (*ptr)(crs->data);
        printf(", ");
    }
    (*ptr)(crs->data);
    printf("]\n");
}

/* pass this to print integer type */
void print_int(void * data) {
    printf("%d", *(int *) data);
}

/* pass this to print char* type */
void print_string(void * data) {
    for(int i = 0; *((char *)(data + i)) != '\0'; i++) {
        printf("%c", *((char *)(data + i)));
    }
}

/* memory cleaning */
void clear_mem(struct ll_t* list) {
    node_t* crs = list->head;

    while(crs != NULL) {
        node_t* tmp = crs->next;
        free(crs);
        crs = tmp;
    }
    free(list);
}
