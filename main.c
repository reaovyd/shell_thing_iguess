#include <stdio.h>
#include <stdlib.h>
#include "./ll/ll.h"
#include <editline/readline.h>
#include <editline/history.h>
#include "./funcs/catf.h"
#include <string.h>

#define CLEAR_TERMINAL_SCREEN() printf("\e[1;1H\e[2J")

const char INPUT_DELIMITER[2] = " ";

/* using this to parse the input stream */
static char* parse_input(struct ll_t* list, char * input) {
    char* copy = strdup(input);
    if(copy == NULL) {
        return NULL;
    }
    char* tokenized_string = strtok(copy, INPUT_DELIMITER);

    while(tokenized_string != NULL) {
        push_back(list, tokenized_string);
        tokenized_string = strtok(NULL, INPUT_DELIMITER);
    }

    return copy;
}

int main(void) {
    CLEAR_TERMINAL_SCREEN();
    puts("Shell Interpreter");
    puts("Type CTRL+C to Exit");

    int bool_cond = 1;
    while(bool_cond) {
       char* input = readline("sh> "); 
       add_history(input);
       ll_t* input_ll = init_ll(); 
       char* parsed = parse_input(input_ll, input);
       if(input_ll == NULL || parsed == NULL) {
            perror("RAN OUT OF MEMORY");
       }
       void * first_com = input_ll->head->data;
       if(strcmp((char *)first_com, "cat") == 0) {
            char* file_r = readline("File Name: ");
            read_file(file_r);

       }

       free(parsed);
       clear_mem(input_ll);
       free(input);

    }
    return 1;
}

/* TODO */
/*
1. Design a Hash Table. The Hash Table will take in the user's command as the key(e.g. like cat) and the value will be to activate a function correlated to the command? (unsure for now)
2. Finish the functions in funcs and create functiosn for those in main
3. Something to add: check working directory function
*/
