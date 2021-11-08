/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"
#include <assert.h>

stack* topp;

void DFT (node * root)
{
  if(!root->visited){ //If the root hasn't been visited, it will be printed and put on the stack
    node* element = root;
    topp = push(topp, element);
    print_node(root);
    root->visited = true;
  } else { //Otherwise it will be researched for children
    if(root->lchild != NULL || root->rchild != NULL){ //If it has any children it will go on
      if(!root->lchild->visited){ //If the left child hasn't been visited the program will run for it
        DFT(root->lchild);
      } else if (!root->rchild->visited){
        DFT(root->rchild);
      }
    } else //Otherwise it has been printed and hasn't got children, so it shall be popped from the stack
      {
        pop(topp);
      } 
  }
}

node *make_node (int num, node * left, node * right)
{
  node* element = (node*) malloc(sizeof(node));
  element->num = num;
  element->lchild = left;
  element->rchild = right;  
  element->visited = false;
	return element;
}

void free_node (node * p)
{
  assert(p->lchild == NULL && p->rchild == NULL);
	free(p);
}


void print_node (node * p)
{
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  int i = 0;
  for (i; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
  stack* element = (stack*) malloc(sizeof(stack)); //We allocate memory to the stack element

  if(topp == NULL) { //If the stack is empty the first element will point to nowhere
    element->next = NULL;
    element->node = node;
  }
  else {
    element->next = topp; //otherwise the element will point to the previous top element 
    element->node = node;
  }
  //the new top will become the inserted element
  topp = element;
	return topp;
}

bool isEmpty (stack * topp)
{
  if(topp == NULL)
    return true;
  else return false;
}

node *top (stack * topp)
{
	return topp->node;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  stack* temp = topp;
  temp = topp->next;
  free(topp);
	return temp;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
