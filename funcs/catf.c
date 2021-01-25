#include <stdio.h>
#include <stdlib.h>

static void print_file_err(char * input) {
    printf("%s does not exist\n", input);
}

int read_file(char * input) {
    FILE* file_ptr = fopen(input, "r");
    if(file_ptr == NULL) {
        print_file_err(input);
        return 0;
    } else {
        char ch = fgetc(file_ptr);
        while(ch != EOF) {
            printf("%c", ch);
            ch = fgetc(file_ptr);
        }
    }
    fclose(file_ptr);
    return 1;
}

