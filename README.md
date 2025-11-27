Macro-Based Data Structure Libraries

A collections of C header files for common data structures using macros for generic programming.    
>> This is type-safe    
>> This is inline-able implementations without external dependencies.


**LINEAR DATA STRUCTURES HEADER MANUAL (#include "include/linear.h")**

PURPOSE: Stack and queue implementation with inline functions

STRUCTURE MACROS:
- DEFINE_STACK(NAME, SIZE)
  Creates stack struct with array[SIZE] and top index

- DEFINE_QUEUE(NAME, SIZE)  
  Creates queue struct with array[SIZE] and start/end indices

STACK FUNCTIONS:
- PUSH_FUNCTION(STRUCT_NAME)
  push_STRUCT_NAME(stack, value): Adds value to stack top

- POP_FUNCTION(STRUCT_NAME)
  pop_STRUCT_NAME(stack): Removes/returns top value
  Returns -1 if empty

QUEUE FUNCTIONS:
- ENQUEUE_FUNCTION(STRUCT_NAME)
  enqueue_STRUCT_NAME(queue, value): Adds value to queue end

- DEQUEUE_FUNCTION(STRUCT_NAME)
  dequeue_STRUCT_NAME(queue): Removes/returns front value
  Returns -1 if empty

USAGE:
DEFINE_STACK(MyStack, 100)
PUSH_FUNCTION(MyStack)
struct MyStack s = {{0}, -1};
push_MyStack(&s, 10);

FEATURES:
- Circular queue implementation
- Bounds checking
- Inline functions for performance
- Automatic function naming

NOTE: Initialize stack.top = -1, queue.start/end = 0



**LINKED LIST HEADER MANUAL (#include "include/list.h")**



PURPOSE: Generic linked list implementation with macros

STRUCTURE MACRO:
- DEFINE_LL_STRUCT(NAME, DATA)
  Creates struct ll_NAME with data field and next pointer

FUNCTION MACROS:
- DEFINE_LL_CREATENODE_FUN(NAME, DATA, ASSIGNMENT)
  NAME_createNode(DATA): Allocates node, assigns data
  Returns: new node pointer or NULL

- DEFINE_LL_NTH_NODE_FUN(NAME)
  NAME_get_nthNode(root, n): Traverses to nth node
  Returns: nth node pointer or NULL

- DEFINE_LL_DELETENODE_FUN(NAME)
  NAME_deleteNode(parent): Recursively frees entire list
  Warning: Frees all nodes from parent to end

USAGE:
DEFINE_LL_STRUCT(IntList, int data)
DEFINE_LL_CREATENODE_FUN(IntList, int val, .data = val)
struct ll_IntList *node = IntList_createNode(5);

PARAMETERS:
NAME: Type identifier for the list
DATA: Data type and parameter for createNode
ASSIGNMENT: Field assignment in createNode

NOTE: createNode uses compound literal initialization
deleteNode frees entire chain from given node




**FILE HANDLING HEADER MANUAL (#include "include/fh.h")**

PURPOSE: Simple file operations with error handling

MACROS:
- FUNCTION_TERMINATOR(FH, ERROR_PROGRAM)
  * Checks if file handle FH is NULL
  * Executes ERROR_PROGRAM on failure
  * Returns 1 automatically

FUNCTIONS:

write_content_to_file(filename, content)
  - Creates/overwrites file with content
  - Returns: 0 success, 1 error
  - Example: write_content_to_file("log.txt", "Hello")

append_content_to_file(filename, content)
  - Appends content to existing file
  - Returns: 0 success, 1 error
  - Example: append_content_to_file("log.txt", "World")

read_content_from_file(filename, str, size)
  - Reads entire file into string buffer
  - Params: filename, target string, buffer size
  - Returns: 0 success, 1 error
  - Example: char buf[1024]; 
             read_content_from_file("file.txt", buf, 1024)

USAGE:
  #include "fh.h"
  write_content_to_file("test.txt", "Data");

ERROR HANDLING:
  Automatic error messages printed to stdout
  Functions return 1 on file operation failures

NOTES:
  - read_content_from_file uses 1024 byte temp buffer
  - Ensure sufficient str buffer size for reading
  - All functions handle their own file closing
  - Undefines IS_FILE_SAFE at end





**STRING HEADER MANUAL (#include "include/sh.h")**

PURPOSE: String operation macros

MACROS:
- IS_NULL(STRING)
  * Copies empty string to STRING
  * Returns: 0 if successful, non-zero on error

- STRCMP(STR1, STR2)
  * Copies STR2 to STR1
  * Returns: 0 if successful, non-zero on error

WARNING:
These macros modify strings destructively.
IS_NULL clears the string, STRCMP overwrites STR1.
Not standard string comparison operations.

USAGE:
#include "sh.h"
char str[20] = "hello";
if (IS_NULL(str)) { /* error */ }
STRCMP(str, "world");
