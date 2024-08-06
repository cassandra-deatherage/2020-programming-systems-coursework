//list.h
//program 3
//Cassandra Deatherage
//Spring 2020
//This file houses the prototypes for the BST list. The list
//class will be called on by the main menu

//This program is a balanced search tree that holds the data
//for a base class Source and three derived classes 
//Slack, Zoom, and D2L

//This file also holds the prototypes for the Node class 
//The node class will be used to create a bst for the list class

#include "source.h"

//This class manages a single node for a BST
class Node//This class will manage the BST structure
{
    public:
        Node();
        Node(const Node & to_copy);
        ~Node();
        int insert(Source * to_add);//insert an source to the list
        int display();//display items in a node
        int search(char * name);//search for a source
        int remove(char * name);//remove a single source from the list
        void set_left(Node * connect);
        void set_right(Node * connect);
        Source * get_content(); 
        Node *& get_left();
        Node *& get_right();

    protected:
        Node * left;
        Node * right;
        Source * content;//base class ptr
};
//This is the class that should manage a BST
class List
{
    public:
        List();
        ~List();
        int add_Slack();
        int add_Zoom();
        int add_D2L();
        int copy_entry(Source * copy_to, Source* original);  
        int display();
        int insert(Source * to_add);
        int remove(char * to_remove);
        int remove_source(char * to_remove);//check fn
        bool find(char * name);// check fn
        int remove_all();// build fn

    protected:
        Node * root;
        int display(Node * root);
        bool find(Node * root, char * name);
        int insert(Node *& root, Source * to_add);//insert an source to the list
        int remove(Node *& root);
        int remove_source(Node *& root, char * to_remove);//remove by name
        int remove_all(Node *& root);
};




