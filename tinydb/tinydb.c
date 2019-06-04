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
#define DEBUG false
// A small wrapper to input command line
struct InputBuffer_t{
    char* buffer;
    size_t buffer_length;  // size_t used in standart library for representing sizes.
    ssize_t input_length;  // ssize_t is used for functions whose return value could either be a valid size                                  // or a negative value to indicate an error
};

typedef struct InputBuffer_t InputBuffer;   // Why not just declare
                                            // InputBuffer

enum MetaCommandResult_t{
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
};

// Need to test no typedef here !!!
typedef enum MetaCommandResult_t MetaCommandResult;

enum PrepareResult_t{
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT    // It seems like an exeption
    // But exeptions are bad(and C dosen't  support them)
    // So here use enum result codes wherever practical
    // The C compiler will complain if my switch statement doesn't handle a member of the enum
    // So we can feel a little more confident we handle every result of a function
    // Expect more result codes to be added in the future
};

typedef enum PrepareResult_t PrepareResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer){
    if(strcmp(input_buffer -> buffer, ".exit") == 0){
        exit(EXIT_SUCCESS);
    }else{
        return META_COMMAND_UNRECOGNIZED_COMMAND;
    }
}

enum StatementType_t{
    STATEMENT_INSERT,
    STATEMENT_SELECT
};

typedef enum StatementType_t StatementType;

struct Statement_t{
    StatementType type;
};

typedef struct Statement_t Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement){
    if(strncmp(input_buffer->buffer, "insert", 6) == 0){
        statement -> type = STATEMENT_INSERT;
        // implement parse args : insert 1 chanchan xxx@xx.com
        // int sscanf(const char *str, const char *format, ...) reads formatted input from a string.
        int args_assigned = sscanf(
                                   input_buffer -> buffer, "insert %d %s %s", &(statement -> row_to_insert.id),
                                   statement -> row_to_insert.username, statement -> row_to_insert.email);
        if(args_assigned <3){
            return PREPARE_SYNTAX_ERROR;
        }
        return PREPARE_SUCCESS;
    }
    if(strncmp(input_buffer -> buffer, "select", 6) == 0){   // Should I just use strcmp here?
        statement -> type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    return PREPARE_UNRECOGNIZED_STATEMENT;
}

void execute_statement(Statement* statement){
    switch(statement -> type){
        case(STATEMENT_INSERT):
            printf("This is where we would do an insert.\n");
            break;
        case(STATEMENT_SELECT):
            printf("This is where we would do an select.\n");
            break;
        }
}


// Just like the constructor to init
InputBuffer* new_input_buffer(){
    InputBuffer* input_buffer = malloc(sizeof(InputBuffer));  // Free? Yes!
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
    input_buffer -> buffer[bytes_read - 1] = 0;  // Here 0 is equal to '\0'
    
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
        
//        if (strcmp(input_buffer -> buffer, ".exit") == 0){
//            close_input_buffer(input_buffer);
//            exit(EXIT_SUCCESS);
//        }else{
//            printf("Unrecognized command '%s'.\n", input_buffer -> buffer);
//        }
        
        //Non-sql statements like '.exit' are 'meta-commands'
        // They all start with a dot
        //So we check for them and handle them in a separate function
        if(input_buffer -> buffer[0] == '.'){
            switch(do_meta_command(input_buffer)){
                case(META_COMMAND_SUCCESS):
                    continue;
                case(META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Unrecognized command '%s'\n",input_buffer -> buffer);
                    continue;
            }
        }
        
        
        // convert the line of input into our internel representation of a statement
        Statement statement;
        
        switch(prepare_statement(input_buffer, &statement)){
            case(PREPARE_SUCCESS):
                break;
            case(PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keyword at start of '%s'.\n", input_buffer -> buffer);
                continue;
        }
        
        // We passs the prepared statement to execute_statement.
        // This function will eventually become our virtual machine
        execute_statement(&statement);
        printf("Executed.\n");
        
    }
    return 0;
}
