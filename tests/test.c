#include <stdio.h>
#include <stdlib.h>
#include "../ll/ll.h" 
#include <string.h>

int main(void) {

    ll_t* new_l = init_ll();

    char* copy = strdup("This is                         a string to read");
    const char delim[2] = " ";
    char* tokenize = strtok(copy, delim);


    while(tokenize != NULL) {
        push_back(new_l, tokenize);
        tokenize = strtok(NULL, delim);
    }

    print_list(new_l, print_string);

    free(copy);
    clear_mem(new_l);

    return 1;
}
