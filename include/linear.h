#ifndef LINEAR_H
#define LINEAR_H

#define DEFINE_STACK(NAME, SIZE) struct NAME { int arr[SIZE]; int top; };
#define DEFINE_QUEUE(NAME, SIZE) struct NAME { int arr[SIZE]; int start; int end; };

#define PUSH_FUNCTION(STRUCT_NAME) \
static inline void push_##STRUCT_NAME(struct STRUCT_NAME *s, int value) { \
    if (s->top < sizeof(s->arr)/sizeof(s->arr[0]) - 1) { \
        s->arr[++s->top] = value; \
    } \
}

#define POP_FUNCTION(STRUCT_NAME) \
static inline int pop_##STRUCT_NAME(struct STRUCT_NAME *s) { \
    if (s->top >= 0) { \
        return s->arr[s->top--]; \
    } \
    return -1; /* Error value */ \
}

#define ENQUEUE_FUNCTION(STRUCT_NAME) \
static inline void enqueue_##STRUCT_NAME(struct STRUCT_NAME *q, int value) { \
    int queue_size = sizeof(q->arr)/sizeof(q->arr[0]); \
    if ((q->end + 1) % queue_size != q->start) { \
        q->arr[q->end] = value; \
        q->end = (q->end + 1) % queue_size; \
    } \
}

#define DEQUEUE_FUNCTION(STRUCT_NAME) \
static inline int dequeue_##STRUCT_NAME(struct STRUCT_NAME *q) { \
    if (q->start != q->end) { \
        int value = q->arr[q->start]; \
        q->start = (q->start + 1) % (sizeof(q->arr)/sizeof(q->arr[0])); \
        return value; \
    } \
    return -1; /* Error value for empty queue */ \
}

#endif