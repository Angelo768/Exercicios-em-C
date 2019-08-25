#include <stdlib.h>
#include <stdio.h>

typedef struct fifo_element{
    int value;
    struct fifo_element *next;
} fifo_e;

typedef struct{
    fifo_e *head;
    fifo_e *tail;
} fifo_top_bottom;

fifo_top_bottom *fifo_create(){
    fifo_top_bottom *fifo = (fifo_top_bottom*) malloc (sizeof(fifo_top_bottom));
    if (fifo == NULL){
        printf("Memory Error");
        exit(1);
    }
    fifo->head = NULL;
    fifo->tail = NULL;
    return fifo;
}

void fifo_insert(fifo_top_bottom *fifo, int value){
    fifo_e *element = (fifo_e*) malloc (sizeof(fifo_e*));
    if (element == NULL){
        printf("Memory Error");
        exit(1);
    }
    element->value = value;
    element->next = NULL;
    if (fifo->head == NULL){
        fifo->head == element;
        fifo->tail == element;
    } else {
        fifo->tail->next = element;
        fifo->tail = element;
    }
}

int fifo_remove(fifo_top_bottom *fifo){
    fifo_e *toFree;
    int toReturn;
    if (fifo != NULL){
        toReturn = fifo->head->value;
        toFree = fifo->head;
        fifo->head = fifo->head->next;
        free(toFree);
    }else{
        printf("The Fifo is empty\n");
        exit(1);
    }
    return toReturn;
}

int fifo_is_empty(fifo_top_bottom *fifo){
    if (fifo->head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void fifo_destroy(fifo_top_bottom *fifo){
    while(fifo_is_empty(fifo) == 1){
        fifo_remove(fifo);
    }
    free(fifo);
}
