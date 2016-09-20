#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include "Config.h"
#include "Move.h"
/*Node data...trying to use some generic data:
 *
 * GAME for an instance of a game
 * ALLOC_PTR for an allocation
 * 
 */

 enum N_DATA {GAME = 0 , ALLOC_PTR = 1 ,STRING = 3 , FLOAT = 2 , INT = 4 , LONG = 5 , CHAR = 6};
typedef enum N_DATA N_DATA ; 

struct Node ;
struct List ;
struct Tree ;


/*
 *	Nodes are as such : 
 *		
 *	       	N
 *	       		
 *	    NL01-NL02-NL03-NL04....	
 *	      		
 *	NL11-NL12-NL13-NL14-NL15-NL16-NL17...
 *
 *
 *
 *
 *
 */


typedef struct Node Node;

 struct Node{
    void* value;
    N_DATA data_type;  
    Node *prev ;
    Node *next ;/* pointer to nodes of the same level */
    struct List *prev_level; /*pointer to up level nodes*/
    struct List *next_level ;
};



typedef struct List List; 
struct List {
    int count ;
    Node* begin ;
    Node* end   ;
    N_DATA data_type ; 

};


typedef struct Tree Tree;
 struct Tree{
    Node *root;

};


 void free_tree(Tree* tree);
 void free_node(Node* node);
 void free_list(List* list);





Tree * init_tree(Node* root); // initialize the search tree
/**
 * \Brief  
 *
 * \Param data
 * \Param next
 * \Param previous
 * \Param next_level
 * \Param prev_level
 *
 * \Returns  Node* 
 */
Node * init_node(void* data,Node* next,Node* previous,List * next_level , List * prev_level,N_DATA type) ;



/**
 * \Brief  initialize a list
 *
 * \Param begin
 * \Param end
 *
 * \Returns  List*
 */
List* init_list(Node* begin);
List* init_empty_list(N_DATA data);

void add_node_to_list(List* list , Node* node) ; 
void delete_node(List* list , Node* node);

char* toString(List *list); 

/**
 * \file Engine.h
 * \Brief print the content of the list in terminal 
 *
 * \Param list 
 */
void print_list(List* list);






/**
 * \File Engine.h
 * \Brief Giving a certain board configuration and a piece,returns all moves possible in the form of multiple boards,in a list
 *
 * \Param game The board to generate the next moves from 
 * \Param piece The id of the piece in the array ,we want to move
 *
 * \Returns  List*
 */
List* generate_boards(Node *root , size_t id) ;


/**
 * \Brief  
 *
 * \Param 
 * \Param List
 *
 *  
 */
List* concatenate_list(List* , List*) ;









List* generate_all_boards(Node*,COLOR color);





void print_tree(Tree* tree);




#endif // ENGINE_H_INCLUDED
