#ifndef LINEAR_H
#define LINEAR_H

#define DEFINE_STACK(TYPE, NAME, SIZE) struct NAME { TYPE arr[SIZE]; int top; };
#define DEFINE_QUEUE(TYPE, NAME, SIZE) struct NAME {TYPE arr[SIZE]; int start; int end; };
#define DEFINE_SET(TYPE, NAME, SIZE)   struct NAME { TYPE arr[SIZE]; int size; };

#define PUSH(STRUCT_NAME, STRUCT_PTR, VALUE) do { \
    if ((STRUCT_PTR)->top < sizeof((STRUCT_PTR)->arr)/sizeof((STRUCT_PTR)->arr[0]) - 1) { \
        (STRUCT_PTR)->arr[++(STRUCT_PTR)->top] = (VALUE); \
    } \
} while(0)

#define POP(STRUCT_NAME, STRUCT_PTR) ({ \
    int result = -1; \
    if ((STRUCT_PTR)->top >= 0) { \
        result = (STRUCT_PTR)->arr[(STRUCT_PTR)->top--]; \
    } \
    result; \
})

#define ENQUEUE(STRUCT_NAME, STRUCT_PTR, VALUE) do { \
    int queue_size = sizeof((STRUCT_PTR)->arr)/sizeof((STRUCT_PTR)->arr[0]); \
    if (((STRUCT_PTR)->end + 1) % queue_size != (STRUCT_PTR)->start) { \
        (STRUCT_PTR)->arr[(STRUCT_PTR)->end] = (VALUE); \
        (STRUCT_PTR)->end = ((STRUCT_PTR)->end + 1) % queue_size; \
    } \
} while(0)

#define DEQUEUE(STRUCT_NAME, STRUCT_PTR) ({ \
    int result = -1; \
    if ((STRUCT_PTR)->start != (STRUCT_PTR)->end) { \
        int queue_size = sizeof((STRUCT_PTR)->arr)/sizeof((STRUCT_PTR)->arr[0]); \
        result = (STRUCT_PTR)->arr[(STRUCT_PTR)->start]; \
        (STRUCT_PTR)->start = ((STRUCT_PTR)->start + 1) % queue_size; \
    } \
    result; \
})

#define IS_STACK_EMPTY(STRUCT_NAME, STRUCT_PTR) ((STRUCT_PTR)->top < 0)

#define IS_STACK_FULL(STRUCT_NAME, STRUCT_PTR) \
    ((STRUCT_PTR)->top >= sizeof((STRUCT_PTR)->arr)/sizeof((STRUCT_PTR)->arr[0]) - 1)

#define IS_QUEUE_EMPTY(STRUCT_NAME, STRUCT_PTR) ((STRUCT_PTR)->start == (STRUCT_PTR)->end)

#define IS_QUEUE_FULL(STRUCT_NAME, STRUCT_PTR) ({ \
    int queue_size = sizeof((STRUCT_PTR)->arr)/sizeof((STRUCT_PTR)->arr[0]); \
    (((STRUCT_PTR)->end + 1) % queue_size == (STRUCT_PTR)->start); \
})

#define SET_CONTAINS(SET, ELEMENT) ({ \
    int found = 0; \
    for (int i = 0; i < (SET).size; i++) { \
        if ((SET).arr[i] == (ELEMENT)) { \
            found = 1; \
            break; \
        } \
    } \
    found; \
})

#define SET_ADD(SET, ELEMENT) ({ \
    int result = 0; \
    if ((SET).size < (sizeof((SET).arr) / sizeof((SET).arr[0])) && \
        !SET_CONTAINS(SET, ELEMENT)) { \
        (SET).arr[(SET).size] = (ELEMENT); \
        (SET).size++; \
        result = 1; \
    } \
    result; \
})

#define SET_REMOVE(SET, ELEMENT) ({ \
    int result = 0; \
    for (int i = 0; i < (SET).size; i++) { \
        if ((SET).arr[i] == (ELEMENT)) { \
            /* Shift elements left to fill the gap */ \
            for (int j = i; j < (SET).size - 1; j++) { \
                (SET).arr[j] = (SET).arr[j + 1]; \
            } \
            (SET).size--; \
            result = 1; \
            break; \
        } \
    } \
    result; \
})

#define SET_CLEAR(SET) ((SET).size = 0)
#define SET_IS_EMPTY(SET) ((SET).size == 0)
#define SET_IS_FULL(SET) ((SET).size >= (sizeof((SET).arr) / sizeof((SET).arr[0])))

#endif