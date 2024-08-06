//list.cpp
//Cassandra Deatherage
//Program 2
//This file holds the function implementation 
//for the list class and the node class

#include "list.h"

//In this program the data is being stored in a 
//DLL of Arrays.

Node::Node()
{
    next = NULL;
    prev = NULL;
    size = 5; 
    top = 0;

    array = new Activity * [size]; 
    for(int i; i  < size; ++i)
    {
        array[i] = NULL;
        ++i;
    }
}


//const by reference of the obj type of the item that is being copied to
//every copy constructor follows this format:
// OBJ::OBJ(const OBJ &)
Node::Node(const Node & to_copy)
{
    top = to_copy.top;
    size = to_copy.size;
    array = new Activity * [size];
    for(int i = 0; i < size; ++i)
    {
        if(to_copy.array[i])
        {
            Local_Culture * lc = dynamic_cast<Local_Culture*>(to_copy.array[i]);
            if(lc)
              array[i] = new Local_Culture(*lc);
        
        
            Outdoor * o = dynamic_cast<Outdoor*>(to_copy.array[i]);
            if(o)
                array[i] = new Outdoor(*o);
        
        
            Travel * t = dynamic_cast<Travel*>(to_copy.array[i]);
            if(t)
                array[i] = new Travel(*t);
        }
        else 
            array[i] = NULL;
    }
}



Node::~Node()
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i])
        {
            delete array[i];
            array[i] = NULL; 
        }
    }
}


int Node::insert(Activity * to_add)
{
    //insert an item into the array
        if(top < size)
        {
            Local_Culture * lc = dynamic_cast<Local_Culture*>(to_add);
            if(lc)
            {
                array[top] = new Local_Culture(*lc);
                ++top; 
                return 1;
            }
            Outdoor * o = dynamic_cast<Outdoor*>(to_add);
            if(o)
            {
                array[top] = new Outdoor(*o);
                ++top; 
                return 1; 
            }
            Travel * t = dynamic_cast<Travel*>(to_add);
            if(t)
            {
                array[top] = new Travel(*t);
                ++top; 
                return 1;
            }
        }
    return 0;
}


int Node::display()
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i])
            array[i]->display();
    }
    return 1; 
}


int Node::search(char * name)
{   
    for(int i = 0; i < size; ++i)
    {
        if(array[i])
        {
            //compare is a fn of all derived
            int x = array[i]->compare(name);
            if(x == 0) 
            {
                array[i]->display();
                return 1; 
            }
        }
    }
return 0;
}



int Node::remove(char * name)
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i])
        {
            if(array[i]->compare(name) == 0)
            {
                delete array[i];
                array[i] = NULL;
                return 1; 
            }
        }
    }
    return 0;
}


int Node::is_full()
{
    if(top <= size)
    {
        return 1;
    }
    return 0;
}


void Node::set_next(Node *& connect)
{
    next = connect;
}


void Node::set_prev(Node * & connect)
{
    prev = connect;
}


Node *& Node::get_next()
{
    return next;     
}


Node *& Node::get_prev()
{
    return prev;
}


//This is the list class implementation
//The job of this class is to mediate between
//the user and the class interface
List::List()
{
    head = NULL;    

}


List::~List()
{
    if(!head)
        return; 
    //call the remove all fn
    remove_all();
}



int List::add_Local_Culture()
{
    cout<<'\t'<<"Please enter the details for the activity you would like to add : "<<endl;
    cout<<'\n'<<endl; 

    char temp_priority[15]; 
    cout<<'\t'<<" Please enter the priority of the activity you would like to add: "<<endl;
    cout<<'\t'<<" Please enter 1 through 10 : "<<endl;
    cin.get(temp_priority, 100, '\n');
    cin.ignore(100, '\n');
    
    cout<<'\n'<<endl; 
    
    char temp_name[15]; 
    cout<<'\t'<<" Please enter the name of the activity you would like to add: "<<endl;
    cin.get(temp_name, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl; 
    
    char temp_description[50]; 
    cout<<'\t'<<" Please enter a short description of the item you would like to add: "<<endl;
    cin.get(temp_description, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl; 
    
    char temp_date[15]; 
    cout<<'\t'<<" Please enter the date of the activity you would like to add: "<<endl;
    cout<<'\t'<<" Please enter the date in this format : DD/MM/YYYY "<<endl;
    cin.get(temp_date, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl; 

    char temp_event[15];
    cout<<'\t'<<" Please enter the type of event you would like to add. Example; Food, Arts, Music : "<<endl;
    cin.get(temp_event, 100, '\n');
    cin.ignore(100, '\n');

    Activity * temp_local_culture = new Local_Culture(temp_priority, temp_name, temp_description, temp_date, temp_event);
    
    insert(temp_local_culture);

    cout<<'\t'<<"These are the details of the item you just added : "<<endl;
    display(); 

    return 1;
}



int List::add_Outdoor()
{
    cout<<'\t'<<"Please enter the details for the activity you would like to add : "<<endl;
    cout<<'\n'<<endl; 

    char temp_priority[15]; 
    cout<<'\t'<<" Please enter the priority of the activity you would like to add: "<<endl;
    cout<<'\t'<<" Please enter 1 through 10 : "<<endl;
    cin.get(temp_priority, 100, '\n');
    cin.ignore(100, '\n');
    
    cout<<'\n'<<endl; 
    
    char temp_name[15]; 
    cout<<'\t'<<" Please enter the name of the activity you would like to add: "<<endl;
    cin.get(temp_name, 100, '\n');
    cin.ignore(100, '\n');
    
    cout<<'\n'<<endl; 

    char temp_description[50]; 
    cout<<'\t'<<" Please enter a short description of the item you would like to add: "<<endl;
    cin.get(temp_description, 100, '\n');
    cin.ignore(100, '\n');
    
    cout<<'\n'<<endl; 

    char temp_date[15]; 
    cout<<'\t'<<" Please enter the date of the activity you would like to add: "<<endl;
    cout<<'\t'<<" Please enter the date in this format : DD/MM/YYYY "<<endl;
    cin.get(temp_date, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl; 

    char temp_distance[15];
    cout<<'\t'<<" Please enter the travel distance to this outdoor activity : "<<endl;
    cin.get(temp_distance, 100, '\n');
    cin.ignore(100, '\n');

    Activity * temp_outdoor = new Outdoor(temp_priority, temp_name, temp_description, temp_date, temp_distance);
    
    insert(temp_outdoor);

    cout<<'\t'<<"These are the details of the item you just added : "<<endl;
    display(); 

    return 1;
}


int List::add_Travel()
{
    cout<<'\t'<<"Please enter the details for the activity you would like to add : "<<endl;
    
    cout<<'\n'<<endl; 

    char temp_priority[15]; 
    cout<<'\t'<<" Please enter the priority of the activity you would like to add: "<<endl;
    cout<<'\t'<<" Please enter 1 through 10 : "<<endl;
    cin.get(temp_priority, 100, '\n');
    cin.ignore(100, '\n');
    
    cout<<'\n'<<endl; 
    
    char temp_name[15]; 
    cout<<'\t'<<" Please enter the name of the activity you would like to add: "<<endl;
    cin.get(temp_name, 100, '\n');
    cin.ignore(100, '\n');
    
    cout<<'\n'<<endl; 

    char temp_description[50]; 
    cout<<'\t'<<" Please enter a short description of the item you would like to add: "<<endl;
    cin.get(temp_description, 100, '\n');
    cin.ignore(100, '\n');
    
    cout<<'\n'<<endl; 

    char temp_date[15]; 
    cout<<'\t'<<" Please enter the date of the activity you would like to add: "<<endl;
    cout<<'\t'<<" Please enter the date in this format : DD/MM/YYYY "<<endl;
    cin.get(temp_date, 100, '\n');
    cin.ignore(100, '\n');

    cout<<'\n'<<endl; 

    char temp_country[15];
    cout<<'\t'<<" Please enter the country this travel destination is located : "<<endl;
    cin.get(temp_country, 100, '\n');
    cin.ignore(100, '\n');

    Activity * temp_travel = new Travel(temp_priority, temp_name, temp_description, temp_date, temp_country);
    
    insert(temp_travel);

    cout<<'\t'<<"These are the details of the item you just added : "<<endl;
    display(); 

    return 1;
}


int List::display()
{
    if(!head)
        return 0;
    return display(head);
}

int List::display(Node * head)
{
    if(!head)
        return 1;
    if(head)
    {
        head->display();
    }
    display(head->get_next());
    return 1;;
}



int List::insert(Activity * to_add)
{
    if(!head)
    {
        head = new Node;
        head->insert(to_add);
        return 1; 
    }
    if(head->is_full() == 1)
    {
        Node * temp = new Node;
        temp->set_next(head);
        head->set_prev(temp);
        head = temp;
        head->insert(to_add);//add the new item into the array
        return 1;
    }
    head->insert(to_add);
    return 1;
}


int List::remove_activity(char * to_remove)
{
    if(!head)
        return 0;
    return remove_activity(head, to_remove);
}

int List::remove_activity(Node * head, char * to_remove)
{
    if(!head) 
        return 0;
    if(head->search(to_remove) == 1)// match
    {
        head->remove(to_remove); //delete
        return 1; 
    } 
    return remove_activity(head->get_next(), to_remove);
}



bool List::find(char * name)
{
    if(!head)
        return 0;
    return find(head, name); 
}

bool List::find(Node * head, char * name)
{
    if(!head)
        return 0;

    if(head)
    {
        //call on the search (array)  fn 
        //if found the search will display!
        int x = head->search(name);
        if(x == 1)
            return 1;
    }
    int x = find(head->get_next(), name);
    if(x == 1)
        return 1;
    else 
        return 0;
}


int List::remove_all()
{
    return remove_all(head);
}

int List::remove_all(Node *& head)
{
    if(!head)
        return 0;
    int x =remove_all(head->get_next());
    delete head;
    head = NULL;
    return x;
}





