#ifndef LIST_H
#define LIST_H
#include <stdlib.h>

#define DEFINE_LL_STRUCT(NAME, DATA) struct ll_##NAME {\
    DATA; \
    struct ll_##NAME *next;\
};

#define DEFINE_LL_CREATENODE_FUN(NAME, DATA, ASSIGNMENT) static inline struct ll_##NAME* NAME##_createNode(DATA) { \
    struct ll_##NAME *node = (struct ll_##NAME*)malloc(sizeof(struct ll_##NAME)); \
    if (!node) return NULL; \
    *node = (struct ll_##NAME){ ASSIGNMENT , NULL }; \
    return node; \
}

#define DEFINE_LL_NTH_NODE_FUN(NAME) \
static inline struct ll_##NAME* NAME##_get_nthNode(struct ll_##NAME *root, size_t n) { \
    while (root && n--) { \
        root = root->next; \
    } \
    return root; \
}

#define DEFINE_LL_DELETENODE_FUN(NAME) \
static inline void NAME##_deleteNode(struct ll_##NAME *parent) { \
    while (parent) { \
        struct ll_##NAME *next = parent->next; \
        free(parent); \
        parent = next; \
    } \
}



#endif