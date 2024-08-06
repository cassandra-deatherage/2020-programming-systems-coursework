//list.h 
//Cassandra Deatherage
//Program 2
//the list class manages the DLL
//this file also contains the node class that manages the array

#include "activity.h"

//This class manages the DLL
class List
{
    public:
        List();
        ~List();
        int add_Local_Culture();
        int add_Outdoor();
        int add_Travel();
        int insert(Activity * to_add);
        int remove_activity(char * to_remove);//check fn
        int display();//check fn
        bool find(char * name);// check fn
        int remove_all();// build fn

    protected:
        
        class Node * head;
        int display(Node * head);
        bool find(Node * head, char * name); 
        int remove_activity(Node * head, char * to_remove);
        int remove_all(Node * &head);
};

class Node//This class manages the array
{
    public:
        Node();
        Node(const Node & to_copy);
        ~Node();
        int is_full();//check to see if the array is full before insert
        int insert(Activity * to_add);//insert an activity to the array
        int display();//display array
        int search(char * name);//search the array for an activity
        int remove(char * name);//remove an activity from the array 
        void set_next(Node *& connect);
        void set_prev(Node *& connect); 
        Node *& get_next();
        Node *& get_prev();

    protected:
        Node * next;
        Node * prev;
        int size;
        int top;
        Activity ** array;
};


