#ifndef _MTREE_H_
#define _MTREE_H_

#ifndef typeof
#define typeof(T) __typeof__(T)
#endif

#ifndef offsetof
#define offsetof(type, member) ((size_t)&(((type*)0)->member))
#endif

#ifndef container_of
#define container_of(ptr, type, member) ({                  \
            const typeof(((type*)0)->member)* mptr = (ptr); \
            (type*)((char*) mptr - offsetof(type,member));})
#endif

typedef struct tree_root {

    struct tree_root* left;
    struct tree_root* right;

} tree_root;

#define TREE_ROOT_INIT(name) { NULL, NULL }

#define TREE_ROOT(name) \
    tree_root name = TREE_ROOT_INIT(name)

#define INIT_TREE_ROOT(ptr) do {                        \
            (ptr)->left = NULL; (ptr)->right = NULL;    \
        } while (0)

#define tree_node(ptr, type, member)    \
    container_of(ptr, type, member)

#define tree_node_left(ptr, type, member)       \
    tree_node((ptr)->left, type, member)

#define tree_node_right(ptr, type, member)      \
    tree_node((ptr)->right, type, member)

static inline int tree_empty_left(tree_root* root) {

    return (root->left == NULL);
}

static inline int tree_empty_right(tree_root* root) {

    return (root->right == NULL);
}

static inline int tree_empty(tree_root* root) {

    return (tree_empty_left(root) && tree_empty_right(root));
}

static inline void tree_add_left(tree_root* new, tree_root* root) {

    root->left  = new;
}

static inline void tree_add_right(tree_root* new, tree_root* root) {

    root->right  = new;
}

static inline void tree_add(tree_root* new, tree_root* root) {

    tree_add_left(new, root); tree_add_right(new, root);
}

static inline void tree_del(tree_root* root) {

    root->left = root->right = NULL;
}

static inline tree_root* tree_node_succ(tree_root* root) {

    root = root->right;

    while (root && root->left)
        root = root->left;

    return root;
}

static inline tree_root* tree_right_rotate(tree_root* root) {

    tree_root* lt = root->left;
    root->left = lt->right;
    lt->right = root;
    return lt;
}

static inline tree_root* tree_left_rotate(tree_root* root) {

    tree_root* rt = root->right;
    root->right = rt->left;
    rt->left = root;
    return rt;
}

#endif //_MTREE_H_
