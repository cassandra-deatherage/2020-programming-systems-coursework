//app.h
//Program 1
//Cassandra Deatherage

//this file holds the prototypes for the User and the App classes


//Program 1
#include "content.h"

#include <iostream>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;


class User//User is the class that manages the list
{
    public:
        User();
        User(char * temp_name);
        ~User();
        int size;
        
        //User name stored in the array
        void display_name();

        //LLL functions
        int compare(char * to_compare);
        //int add_content(char * date, char * title);
        int add_content(Content * to_add);
        int remove_content(char * title);
        void display_content();//wrapper for display  
        //int display_by_date(char * date); 

    protected:
        
        //pointer to the LLL
        Content * head;
        char * name;
        //recursive fn for the display name
        void r_display_name();
        //recursive fns for LLL
        int remove_content(Content *& current, char * title); 
        void display_content(Content * current);
        //int display_by_date(Content * current, char * date);
};

//This class manages all of the other class fns
class Application
{
    public:
        Application();
        ~Application();
        
        //add a user to the array 
        int add_user(char * temp_name);
        //display all of the users 
        void display_all_users(); 
        
        //Content Node functions (LLL Fns)
        int add_content(char * name, char * date, char * title);
        int add_content(Content * to_add, char * name);

        void display_content_by_user(char * name);
        //void display_content_by_date(char * date); 
        void display_all_content();
        int remove_content(char * name, char * title);
        //int remove_content(Content *& current, char * title); 
    protected:
        User ** array;
        int array_size = 10;
};



