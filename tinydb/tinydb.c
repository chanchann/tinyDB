//
//  tinydb.c
//  tinydb
//
//  Created by Frank on 2019/5/31.
//  Copyright © 2019 Frank. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define Bool DEBUG true
// A small wrapper to input command line
struct InputBuffer_t{
    char* buffer;
    size_t buffer_length;  // size_t used in standart library for                             //  representing sizes.
    ssize_t input_length;  // ssize_t is used for functions whose return                      // value could either be a valid size, or a                        // negative value to indicate an error
};

typedef struct InputBuffer_t InputBuffer;   // Why not just declare
                                            // InputBuffer

// Just like the constructor to init
InputBuffer* new_input_buffer(){
    InputBuffer* input_buffer = malloc(sizeof(InputBuffer));
    input_buffer -> buffer = NULL;
    input_buffer -> buffer_length = 0;
    input_buffer -> input_length = 0;
    
    return input_buffer;
}

void print_prompt() { printf("db >");}

void read_input(InputBuffer* input_buffer){
    /*
     ssize_t getline(char **lineptr, size_t *n, FILE *stream);
     
     - lineptr: a pointer to the variable we use to point the buffer
     containing the read line.
     - n: a pointer to the variable we use to save the size of allocated buffer
     - stream the input stream to read from. We'll be reading from standard input
     - return value: the number of bytes read, which may be less than the size
     of the buffer.
    */
    
    ssize_t bytes_read = getline(&(input_buffer -> buffer), &(input_buffer -> buffer_length), stdin);
    /*
     We store the read line in input_buffer -> buffer,
     size of the allocated buffer in input_buffer -> buffer_length,
     store the return value in input_buffer -> input_length.
     
     buffer starts as NULL, so getline allocates enough memory to hold the
     line of input and makes buffer point to it
     */
    
    // To check success reading or not
    if(bytes_read <= 0){
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }
    //Ignore trailing newline
    // Here I've got some questions~~~
    if(DEBUG){
        printf("Before : input_length %zd\n", input_buffer -> input_length);
        printf("Before : input_buffer %s\n", input_buffer -> buffer);
    
        printf("bytes : %zd\n", bytes_read);
        printf("buffer[bytes]: %c\n", input_buffer -> buffer[bytes_read-1]);
    }

    input_buffer -> input_length = bytes_read - 1;
    input_buffer -> buffer[bytes_read - 1] = 0;
    if(DEBUG){
        printf("After : input_length %zd\n", input_buffer -> input_length);
        printf("After : input_buffer %s\n", input_buffer -> buffer);
    }
}

// free the memory allocated for an instance of InputBuffer*
// and the element of respective structure(getline allocate memory)
void close_input_buffer(InputBuffer *input_buffer){
    free(input_buffer -> buffer);
    free(input_buffer);
}

int main(int argc, const char * argv[]) {
    
    InputBuffer* input_buffer = new_input_buffer();
    
    while(true){
        print_prompt(); // print the informaiton as a start
        read_input(input_buffer);   // read the command in the                                         // buffer
        
        if (strcmp(input_buffer -> buffer, ".exit") == 0){
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        }else{
            printf("Unrecognized command '%s'.\n", input_buffer -> buffer);
        }
    }
    
    return 0;
}
