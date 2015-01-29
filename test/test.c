#include <stdio.h>
#include "bs_tree.h"

int main(int argc, char **argv)
{
    node_t *root = NULL;
    node_t *search_result = NULL;
    
    unsigned int tableau[] = {5,7,2,39,46,32,14, 38, 36, 6};
    unsigned int i=0;
   
    for(i=0;i<sizeof(tableau)/sizeof(unsigned int);i++)
    {
       
        bs_insert(&root, tableau[i], NULL);
    }
    
    bs_tree_delete(root,7);
    print_tree(root, 0);
    search_result = bs_search(root,39);
    
    bs_free_tree(&root);
    return 0;
}