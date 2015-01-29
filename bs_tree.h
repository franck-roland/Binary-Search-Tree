//
//  bs_tree.h
//  
//
//  Created by Franck Roland on 28/01/2015.
//
//

#ifndef _bs_tree_h
#define _bs_tree_h

typedef struct Node
{
    unsigned int value;
    struct Node *father;
    struct Node *left;
    struct Node *right;
    
}node_t;


void bs_free_tree(node_t **node);
node_t *bs_init_Node(node_t *node, unsigned int value, node_t *father);
node_t *bs_search(node_t *node, unsigned int value);
node_t * bs_insert(node_t **node, unsigned int value, node_t *father);
node_t *bs_find_min(node_t *node);
void bs_replace_node_in_parent(node_t *node, node_t *new_node);
void bs_tree_delete(node_t *node, unsigned int value);
void print_tree(node_t *node, unsigned int depth);

#endif
