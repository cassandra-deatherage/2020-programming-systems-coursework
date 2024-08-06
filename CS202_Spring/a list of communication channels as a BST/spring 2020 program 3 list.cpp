//list.cpp
//program 3
//Cassandra Deatherage
//Spring 2020
//This is the implementation of the functions for the list class 

//These functions will be called on to interact with the list from
//the main menu
#include "list.h"

//In this program the data is being stored in a BST

Node::Node()
{
    left = NULL;
    right = NULL;
}


//const by reference of the obj type of the item that is being copied to
//every copy constructor follows this format:
// OBJ::OBJ(const OBJ &)
Node::Node(const Node & to_copy)
{
    if(to_copy.content)
    {
        Slack * s = dynamic_cast<Slack*>(to_copy.content);
        if(s)
            content = new Slack(*s);


        Zoom * z = dynamic_cast<Zoom*>(to_copy.content);
        if(z)
            content = new Zoom(*z);


        D2L * d = dynamic_cast<D2L*>(to_copy.content);
        if(d)
            content = new D2L(*d);
    }
    else
        content = NULL;
}



Node::~Node()
{
   left = NULL;
   right = NULL;
   delete content;
}


int Node::insert(Source * to_add)
{
    to_add->display();
    if(!content)
    {
        Slack * s = dynamic_cast<Slack*>(to_add);
        if(s)
        {
            content = new Slack(*s);
            return 1;
        }
        Zoom * z = dynamic_cast<Zoom*>(to_add);
        if(z)
        {
            content = new Zoom(*z);
            return 1;
        }
        D2L * d = dynamic_cast<D2L*>(to_add);
        if(d)
        {
            content = new D2L(*d);
            return 1;
        }
    }
    return 0;
}


int Node::display()
{
    //call contents disp.
    content->display();
    return 1;
}


int Node::search(char * name)
{   
    //compare is a fn of all derived
    int x = content->compare(name);
    if(x == 0) 
    {
        content->display();
        return 1; 
    }
    return 0;
}



int Node::remove(char * name)
{
    if(content)
    {
        if(content->compare(name) == 0)
        {
            delete content;
            content = NULL;
            return 1; 
        }
    }
    return 0;
}

Source * Node::get_content()
{
    return content;
}
/* //not sure which is the right remove for this context
   int Node::remove(char * name)
   {
   if(content)
   delete content;
   return 1;
   }
   */

void Node::set_left(Node * connect)
{
    left = connect;

}


void Node::set_right(Node * connect)
{
    right = connect;
}


Node *& Node::get_left()
{
    return left;
}


Node *& Node::get_right()
{
    return right;
}


//This is the list class implementation
//The job of this class is to mediate between
//the user and the class interface
List::List()
{
    root = NULL;

}


List::~List()
{
    if(!root)
        return;
    //call the remove all fn
    remove_all();
}


int List::add_Slack()
{
    cout<<'\t'<<"Please enter the details for the source you would like to add : "<<endl;
    cout<<'\n'<<endl;

    char temp_priority[15];
    cout<<'\t'<<" Please enter the priority of the source you would like to add: "<<endl;
    cout<<'\t'<<" Please enter 1 through 10 : "<<endl;
    cin.get(temp_priority, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    char temp_name[20];
    cout<<'\t'<<" Please enter the name of the source you would like to add: "<<endl;
    cin.get(temp_name, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    char temp_subject[20];
    cout<<'\t'<<" Please enter the subject related to this content (personal, school, work) : "<<endl;
    cin.get(temp_subject, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    //add the data for the specific derived class
    char temp_channel[50];
    cout<<'\t'<<" Please enter a description of the new slack channel : "<<endl;
    cin.get(temp_channel, 100, '\n');
    cin.ignore(100, '\n');

    Source * temp_slack = new Slack(temp_priority, temp_name, temp_subject, temp_channel);

    insert(temp_slack);

    //cout<<'\t'<<"These are the details of the item you just added : "<<endl;
    //display();

    return 1;
}



int List::add_Zoom()
{

    cout<<'\t'<<"Please enter the details for the source you would like to add : "<<endl;
    cout<<'\n'<<endl;

    char temp_priority[15];
    cout<<'\t'<<" Please enter the priority of the source you would like to add: "<<endl;
    cout<<'\t'<<" Please enter 1 through 10 : "<<endl;
    cin.get(temp_priority, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    char temp_name[20];
    cout<<'\t'<<" Please enter the name of the source you would like to add: "<<endl;
    cin.get(temp_name, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    char temp_subject[20];
    cout<<'\t'<<" Please enter the subject related to this content (personal, school, work) : "<<endl;
    cin.get(temp_subject, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    //add the data for the specific derived class
    char temp_zoom_id[20];
    cout<<'\t'<<" Please enter the new id for this Zoom source : "<<endl;
    cin.get(temp_zoom_id, 100, '\n');
    cin.ignore(100, '\n');

    Source * temp_zoom = new Zoom(temp_priority, temp_name, temp_subject, temp_zoom_id);

    insert(temp_zoom);

    //cout<<'\t'<<"These are the details of the item you just added : "<<endl;
    //display();

    return 1;
}


int List::add_D2L()
{
    cout<<'\t'<<"Please enter the details for the source you would like to add : "<<endl;
    cout<<'\n'<<endl;

    char temp_priority[15];
    cout<<'\t'<<" Please enter the priority of the source you would like to add: "<<endl;
    cout<<'\t'<<" Please enter 1 through 10 : "<<endl;
    cin.get(temp_priority, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    char temp_name[20];
    cout<<'\t'<<" Please enter the name of the source you would like to add: "<<endl;
    cin.get(temp_name, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    char temp_subject[20];
    cout<<'\t'<<" Please enter the subject related to this content (personal, school, work) : "<<endl;
    cin.get(temp_subject, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl;

    //add the data for the specific derived class
    char temp_course[20];
    cout<<'\t'<<" Please enter the course number for this class on D2L : "<<endl;
    cin.get(temp_course, 100, '\n');
    cin.ignore(100, '\n');

    Source * temp_d2l = new D2L(temp_priority, temp_name, temp_subject, temp_course);

    insert(temp_d2l);

    //cout<<'\t'<<"These are the details of the item you just added : "<<endl;
    //display();

    return 1;
}


int List::display()
{
    if(!root)
        return 0;
    return display(root);
}

int List::display(Node * root)//in order display
{
    if(!root)
        return 0;
    display(root->get_left());
    root->display();
    display(root->get_right());
    return 1;;
}


int List::copy_entry(Source * copy_to, Source * original)
{
    copy_to->set_name(original->get_name()); 
    
    copy_to->set_priority(original->get_priority());
    
    copy_to->set_subject(original->get_subject()); 
    
    return 1;
}



int List::insert(Source * to_add)
{
    return insert(root, to_add);    
}
int List::insert(Node *& root, Source * to_add)
{
    if(!root)//no list - create a new list//or go to end and insert
    {
        root = new Node;
        root->insert(to_add);
        return 1;
    }//otherwise compare the data by the name and insert
    else if(strcmp(root->get_content()->get_name(), to_add->get_name())>0)
        insert(root->get_left(), to_add);
    else insert(root->get_right(), to_add);

    return 1;
}


int List::remove(char * to_remove)//BST Removal Algorithm
{
    //empty tree
    if(!root)
        return 0;
    return remove(root);
}
int List::remove(Node *& root)
{
    //write algorithm for each case in this fn
    //then call on this fn in each removal fn
    if(!root)
        return 0;
    //leaf
    if(root->get_left() == NULL && root->get_right() == NULL)
    {
        delete root;//double check to make sure that the 
        //destructor for source is called here
        root = NULL;
    }
    //internal node w/ 1 child (left)
    else if(root->get_left() && !root->get_right())
    {
        Node * temp = root->get_left();
        delete root;
        root = temp;
    }
    //Internal node w/ 2 children
    //right child has no children
    else if(root->get_right()->get_left() == NULL)
    {
        //if it is null then root->get_right() 
        // is the successor
        Node * hold = root->get_right();
        delete root;
        root = hold;
    }
    //internal node w/ 2 children
    //find the inorder successor
    else if(root->get_right()->get_left() != NULL)
    {
        Node * previous = root;
        Node * current = root->get_right();

        while(current->get_left() != NULL)
        {
            previous = current;
            current = current->get_left();
        }
        //delete the current values in the node 
        delete []root->get_content()->get_name();
        delete []root->get_content()->get_priority();
        delete []root->get_content()->get_subject();
        //copy over the new values into the node
        copy_entry(root->get_content(), current->get_content());//i don't know if this is correct
        previous->get_left() = current->get_right();
        delete current;
    }
    return 1;
}

int List::remove_source(char * to_remove)
{
    if(!root)
        return 0;
    return remove_source(root, to_remove);
}

//remove all by name
int List::remove_source(Node *& root, char * to_remove)
{
    if(!root)
        return 0;
    int x= remove_source(root->get_left(), to_remove) + remove_source(root->get_right(), to_remove);
    if(strcmp(to_remove, root->get_content()->get_name()) == 0)//is this correct access? 
    {
        remove(to_remove);
    }
    return x;
}



bool List::find(char * name)
{
    if(!root)
        return 0;
    return find(root, name);
}

bool List::find(Node * root, char * name)
{
    if(!root)
        return 0;

    if(root)
    {
        //if found the search fn will display
        //go to the node class and use it's search
        //funtion to compare it's data
        int x = root->search(name);
        //a zero value means its a match
        //otherwise return 1
        if(x == 1)
            return 1;
    }
    int x = find(root->get_left(), name);
    x = find(root->get_right(), name);
    if(x == 1)
        return 1;
    else
        return 0;
}


int List::remove_all()
{
    return remove_all(root);
}

int List::remove_all(Node *& root)
{
    if(!root)
        return 0;
    int x = remove_all(root->get_left());
    x = remove_all(root->get_right());
    delete root;
    root = NULL;
    return x;
}






