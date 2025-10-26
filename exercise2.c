/*
 * Exercise 2: Stack Implementation using Linked List
 * Assignment 7 - IPFCE 2025
 * 
 * Implement all the stack functions declared in include/stack.h
 * The stack should be implemented using a linked list structure.
 * 
 * Functions to implement:
 * - initialize: Create an empty stack
 * - push: Insert an item at the top of the stack
 * - pop: Remove and return the top item
 * - full: Check if stack is full (always false for linked list)
 * - empty: Check if stack is empty
 * - print: Print all items in the stack
 */

#include "stack.h"

/* Create an empty stack */
void initialize(stack *s)
{
    s->head = NULL;
}

/* Insert item x at the top of stack s */
void push(int x, stack *s)
{
    if(s->head == NULL){
        // WE GOT EMPTY LIST
        node * p = malloc(sizeof(node));
        p->next = NULL;
        p->data = x;
        s->head = p;
        
        return;
    }

    node * p = s->head;
    while(p->next != NULL){
        p = p->next;
    }
    node * new = malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    p->next = new;
    /* pre-condition: true (linked list can always accept more items) */
    /* post-condition: x is added to top of stack */

}

/* Return (and remove) the top item of stack s */
int pop(stack *s)
{
  /* pre-condition: stack must not be empty */
  /* post-condition: top item is removed and returned */
    int data;
    node * p= s->head;
    if(p->next == NULL){
        data = p->data;
        free(p);
        s->head = NULL;
    }
    else{
    while(1){
        if(p->next->next == NULL){
            data = p->next->data;
            free(p->next);
            p->next = NULL;
            break;
        }
        p = p->next;
    }
}
    return data;

}

/* Test whether a stack can accept more pushes */
bool full(stack *s)
{
    /* pre-condition: true */
    /* post-condition: Returns true if stack is full, false otherwise */
    return false;
}

/* Test whether a stack can accept more pops */
bool empty(stack *s)
{
    /* pre-condition: true */
    /* post-condition: returns true if stack is empty, false otherwise */

    return (s->head == NULL); // placeholder - replace with actual implementation
}

/* Print the contents of the stack */
void print(stack *s)
{
    node * p= s->head;
    while(p != NULL){
        p = p->next;
        printf("%d",p->data);
    }
    /* pre-condition: true */
    /* post-condition: prints all items in the stack */
}
