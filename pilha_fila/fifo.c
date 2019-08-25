#include "fifo.h"

int main(){
    fifo_top_bottom *fifo = fifo_create();

    // for(int i = 0; i < 10; i++){
    //     printf("Insert %d in FIFO\n", i);
    //     fifo_insert(fifo, i);
    // }

    // while(!fifo_is_empty(fifo)){
    //     printf("Remove %d from FIFO\n", fifo_remove(fifo));
    // }

    fifo_destroy(fifo);
    return 0;
}