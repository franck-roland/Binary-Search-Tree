#include <stdlib.h>
#include <stdio.h>

#include "bs_tree.h"


void bs_free_tree(node_t **node)
{
	if(!*node)
		return;
	bs_free_tree(&(*node)->left);
	bs_free_tree(&(*node)->right);
	free(*node);
	*node = NULL;
	
}

node_t *bs_init_Node(node_t *node, unsigned int value, node_t *father)
{
	if(!node)
	{
		node = (node_t *)malloc(sizeof(node_t));
        if(!node){
            fprintf(stderr,"MALLOC ERROR\n");
			return node;
        }
	}
	node->value = value;
	node->father = father;
	node->right = NULL;
	node->left = NULL;
	return node;
	
}

	
	
node_t *bs_search(node_t *node, unsigned int value)
{
	while(1)
	{
		if(node == NULL)
			return NULL;
		else if(value == node->value)
			return node;
		else if(value < node->value)
			node = node -> left;
		else
			node = node -> right;
	}
	
}

node_t *bs_insert(node_t **node, unsigned int value, node_t *father)
{
	if(*node == NULL)
	{
		*node = bs_init_Node(*node, value, father);
        return *node;
	}
	else if(value < (*node)->value)
		return bs_insert(&((*node)->left), value, *node);
	else if(value > (*node)->value)
		return bs_insert(&((*node)->right), value, *node);
	else
        return *node;
}

node_t *bs_find_min(node_t *node)
{
	if(!node)
		return node;
	
	while(node->left)
		node = node->left;
	return node;
	
}

void bs_replace_node_in_parent(node_t *node, node_t *new_node)
{
	if(node->father)
	{
		if(node == node->father->left)
			node->father->left = new_node;
		else
			node->father->right = new_node;
	}
	if(new_node)
		new_node->father = node->father;
}

void bs_tree_delete(node_t *node, unsigned int value)
{
	node_t *successor = NULL;
	
	if(!node)
		return;
	
	if(value < node->value)
		bs_tree_delete(node->left, value);
	else if(value > node->value)
		bs_tree_delete(node->right, value);
	else
	{
		if(node->left && node->right)
		{
			successor = bs_find_min(node->right);
			node->value = successor -> value;
			bs_tree_delete(successor, successor->value);
		}
		else if(node->left)
		{
			bs_replace_node_in_parent(node, node->left);
			free(node);
			
		}
		else if(node->right)
		{
			bs_replace_node_in_parent(node, node->right);
			free(node);
			}
		else
		{
			bs_replace_node_in_parent(node, NULL);
			free(node);
		}
	}
}


void print_tree(node_t *node, unsigned int depth)
{
	if(!node)
		return;
	
	printf("%d<ul><li class='right'>",node->value);
	if(node->right)
	{
		print_tree(node->right, depth + 1);
	}
    else{
        printf("None");
    }
    printf("</li><li class='left'>");
	if(node->left)
	{
		print_tree(node->left, depth + 1);
        
	}
    else{
        printf("None\n");
    }
    printf("</li></ul>");

	if(!depth)
		printf("\n");
}





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




