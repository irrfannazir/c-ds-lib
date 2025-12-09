#ifndef TREE_H
#define TREE_H

#define DEFINE_BTREE(NAME, DATA) struct btree_##NAME{\
    DATA; \
    struct btree_##NAME *right; \
    struct btree_##NAME *left; \
    }; \
    \
    static inline struct btree_##NAME* btree_##NAME##_add_right(struct btree_##NAME *parent, DATA) {\
        if (!parent) return NULL;\
        struct btree_##NAME *node = malloc(sizeof(struct btree_##NAME));\
        if (!node) return NULL;\
        node->right = NULL;\
        node->left = NULL;\
        *(typeof(DATA)*)&node->__data = __data;\
        parent->right = node;\
        return node;\
    }\
    \
    static inline struct btree_##NAME* btree_##NAME##_add_left(struct btree_##NAME *parent, DATA) {\
        if (!parent) return NULL;\
        struct btree_##NAME *node = malloc(sizeof(struct btree_##NAME));\
        if (!node) return NULL;\
        node->right = NULL;\
        node->left = NULL;\
        *(typeof(DATA)*)&node->__data = __data;\
        parent->left = node;\
        return node;\
    }\
    \
    static inline void btree_##NAME##_delete(struct btree_##NAME *node) {\
        if (!root) return;\
        btree_##NAME##_delete(root->left);\
        btree_##NAME##_delete(root->right);\
        free(root);\
    }

#endif