//Activity.cpp
//Cassandra Deatherage
//Program 2
//This is the implementation file for the base class Activity
//And its derived classes: Local_Culture, Outdoor, and Travel

//#include "item.h"
#include "activity.h"


//constructor for the base class
Activity::Activity()
{
    priority = NULL;
    name = NULL;
    description = NULL;
    date = NULL;
}


//This constructor takes a char * from
//main and creates dynamic memory to copy
//over the data
Activity::Activity(char * temp_priority, char * temp_name, char * temp_description, char * temp_date)
{
    priority = new char[strlen(temp_priority)+1];
    strcpy(priority, temp_priority);

    name = new char[strlen(temp_name)+1];
    strcpy(name, temp_name);

    description = new char[strlen(temp_description)+1];
    strcpy(description, temp_description);

    date = new char[strlen(temp_date)+1];
    strcpy(date, temp_date);
}


//Copy Constructor to take the new memory and pass 
//into the data structure
Activity::Activity(const Activity & to_copy)
{
    //this is one way to call the constructor.. 
    //this = new Item(to_copy.priority, to_copy.name, to_copy.description, to_copy.date);

    priority = new char[strlen(to_copy.priority)+1];
    strcpy(priority , to_copy.priority);

    name = new char[strlen(to_copy.name)+1];
    strcpy(name, to_copy.name);

    description = new char[strlen(to_copy.description)+1];
    strcpy(description, to_copy.description);

    date = new char[strlen(to_copy.date)+1];
    strcpy(date, to_copy.date);
}


//destructor for the Activity Class
Activity::~Activity()
{
    delete priority;
    priority = NULL;

    delete name;
    name = NULL;

    delete description;
    description = NULL;

    delete date;
    date = NULL;
}

//Don't create any of the virtual void classes!
//Don't implement this function in Activity Class
/*
void Activity::display() 
{
    cout << "Item information: " << endl;
    cout<<'\t'<< priority <<endl;
    cout<<'\t'<< name <<endl;
    cout<<'\t'<< description <<endl;
    cout<<'\t'<< date <<endl;
}
*/


//Default Constructor for the Local_Culture Activity Class
Local_Culture::Local_Culture():Activity()
{
    event = NULL; 
}


//Constructor for the Local_Culture Activity Class
Local_Culture::Local_Culture(char * priority, char * name, char * description, char * date, char * event):Activity(priority, name, description, date)
{
    this->event = new char[strlen(event)+1];
    strcpy(this->event, event);
}


Local_Culture::Local_Culture(const Local_Culture & to_copy):Activity(to_copy)//upcasting
{
    priority = to_copy.priority;
    name = to_copy.name;
    description = to_copy.description;
    date = to_copy.date;
    event = to_copy.event;
}


//Destructor for the Local_Culture Class
Local_Culture::~Local_Culture()
{
    delete event;
}


//Display for the Used Item display
void Local_Culture::display()
{
    cout<< "Local Culture Activity information: "<<endl;
    cout<<'\t'<< "Priority : "<< priority <<endl;
    cout<<'\t'<< "Name : "<< name <<endl;
    cout<<'\t'<< "Description : "<< description <<endl;
    cout<<'\t'<< "Date : "<< date <<endl;
    cout<<'\t'<< "The type of cultural event is : "<< event <<endl; 
    return;
}


int Local_Culture::set_date(char * new_date)
{
    if(date)
    {
        date = new_date;
        return 1;
    }
    return 0;
}


bool Local_Culture::compare(char * to_compare)
{
    return strcmp(name, to_compare);
    //a zero return value means they're even!
}




//Outdoor Class
Outdoor::Outdoor():Activity()
{
    distance = NULL;
}


Outdoor::Outdoor(char * priority, char * name, char * description, char * date, char * distance):Activity(priority, name, description, date)
{
    this->distance = new char[strlen(distance) +1];
    strcpy(this->distance, distance);
}


Outdoor::Outdoor(const Outdoor & to_copy):Activity(to_copy)//upcasting
{
    distance = to_copy.distance;
}


Outdoor::~Outdoor()
{
    delete distance;
}


void Outdoor::display()
{
    cout<< "Outdoor Activity information: " <<endl;
    cout<<'\t'<< "Priority : "<< priority <<endl;
    cout<<'\t'<< "Name : "<< name <<endl;
    cout<<'\t'<< "Description : "<< description <<endl;
    cout<<'\t'<< "Date : "<< date <<endl;
    cout<<'\t'<< "The distance to this outdoor activity is : "<< distance <<endl; 
}


int Outdoor::set_date(char * new_date)
{
    if(date)
    {
        date = new_date;
        return 1;
    }
    return 0;
}


bool Outdoor::compare(char * to_compare)
{
    return strcmp(name, to_compare);
    //a zero return value means they're even!
}




//Travel Class
Travel::Travel():Activity()
{
   country = NULL; 
}


//Constructor that takes the users args and creates dynamic memory
Travel::Travel(char * priority, char * name, char * description, char *date, char * country):Activity(priority, name, description, date)
{
    this->country = new char[strlen(country) +1]; 
    strcpy(this->country, country);
}

Travel::Travel(const Travel & to_copy):Activity(to_copy)//upcasting
{
    country = to_copy.country;
}


Travel::~Travel()
{
    delete country;
}


void Travel::display()
{
    cout << "Travel Activity information: " << endl;
    cout<<'\t'<< "Priority : "<< priority<<endl;
    cout<<'\t'<< "Name : "<< name <<endl;
    cout<<'\t'<< "Description : "<< description <<endl;
    cout<<'\t'<< "Date : "<< date <<endl;
    cout<<'\t'<< "Country of travel destination : "<< country <<endl; 
}


int Travel::set_date(char * new_date)
{
    if(date)
    {
        date = new_date;
        return 1;
    }
    return 0;
}


bool Travel::compare(char * to_compare)
{
    return strcmp(name, to_compare);
    //a zero return value means they're even!
}









