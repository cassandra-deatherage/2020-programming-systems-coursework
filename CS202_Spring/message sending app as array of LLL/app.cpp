//app.cpp
//Program 1
//Cassandra Deatherage

#include "app.h"
//This file houses the funtion implementation 
//for the User and the Application classes


//Functions for the User Class
User::User()//constructor
{
    head = NULL;
    name = NULL;
}

User::User(char * temp_name)//copy constructor
{
    name = new char[strlen(temp_name)+ 1];
    strcpy(name, temp_name);
}

User::~User()
{
    //Go through the array of users
    for(int i; i < size; ++i)
    {
        if(name)
            name = NULL;
    }
    //Delete the LLL of rooms at each index
    if(head) 
    {   
        Content * current = head;
        while(current)
        {
            Content * temp = current->get_next();
            delete current;
            current = NULL;
            current = temp; 
        }
    } 
}

// The array has a ptr to a LLL at each index
// The LLL is a list of content a user has added
void User::display_name()
{
    //call the the recursive display
    r_display_name();
}


void User::r_display_name()
{
    cout<<'\t'<<" User Name : "<<endl;
    cout<<'\t'<<'\t'<< name <<endl;
}


int User::add_content(Content * to_add)
{
    to_add->set_next(head);
    head = to_add;
    return 1; 
}


//remove content from a LLL of content
int User::remove_content(char * title)
{
    Content * current = head;
    int r = remove_content(current, title);
    if(r == 1)
    {
        Content * temp = head->get_next();
        delete head;
        head = temp;
    }
    return 0;
}

//remove content recursive
int User::remove_content(Content *& current, char * title)
{
    if(!current) return 0;
    
    int x = current->compare(title);
    if(x == 0)
    {
        return 1;
    }
    int r = remove_content(current->get_next(), title);
    if(r == 1)
    {
        //delete in the list
        Content * temp = current->get_next()->get_next();
        temp = current->get_next()->get_next();
        delete current->get_next();
        current->set_next(temp);
    }
    return 0;
}

//find a user in the array
int User::compare(char * to_compare)
{
    return strcmp(name, to_compare);
}


//display all the content in the LLL
void User::display_content()// Wrapper fn for the LLL
{
    if(!head)
    {
        cout<<'\t'<<" The list of content is empty "<<endl;
        return;
    }
    Content * current = head;
    return display_content(current);
}


//recursive fn display all content in LLL
void User::display_content(Content * current) 
{
    if(!current) 
        return;
    current->display();
    return display_content(current->get_next());
}


//Functions for the Application Class
//This is the class that manages the array
//(calls on fns from the user class)
Application::Application()
{
    array = new User * [10];
    for(int i = 0; i < array_size; ++i)
    {
        array[i] = NULL;
    }
}

Application::~Application()
{
    for(int i = 0; i < array_size; ++i)
    {
        if(array[i])
        {
            delete array[i];
        }
    }
    delete []array;
}


int Application::add_user(char * temp_name)
{
    for(int i = 0; i < array_size; ++i) 
    { 
        if(array[i] == NULL)
        {
            array[i] = new User(temp_name);
            cout<<'\t'<<" The new user has been added "<<endl; 
            //display_all_users(); 
            return 1; 
        }
    }
    return 0;
}

void Application::display_all_users()
{
    int index = 1;
    for(int i = 0; i < array_size; ++i)
    {
        if(array[i])
        {
            cout<<" User # : "<< index <<endl;
            array[i]->display_name();  
            ++index;  
        }
    }
    return;
}


int Application::add_content(Content * to_add, char * name)
{
    for(int i = 0; i < array_size; ++i)
    {
        if(array[i] != NULL)
        {
            //see if the name passed in is the correct name
            if(array[i]->compare(name) == 0)
            {
                //if it is add the content to that users list
                array[i]->add_content(to_add);

                return 1;
            }
        }
    }
    return 0;
    
}

void Application::display_content_by_user(char * name)
{
    for(int i = 0; i < array_size; ++i)
    {
        if(array[i] != NULL)
        {
            if(array[i]->compare(name) == 0)
            {
                array[i]->display_content();
            }
        }
    }
}


void Application::display_all_content()
{
    for(int i = 0; i < array_size; ++i)
    {
        if(array[i])
        {
            array[i]->display_name();
            array[i]->display_content();
        }
    }
    return;
}

int Application::remove_content(char * name, char * title)
{
    
    for(int i = 0; i < array_size; ++i)
    {
        if(array[i] != NULL)
        {
            if(array[i]->compare(name) == 0)
            {
                array[i]->remove_content(title);
                return 1; 
            }
        }
    }
    return 1; 
}



