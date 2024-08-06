//activity.h
//Cassandra Deatherage
//Program 2 
//activity is the base class for three derived activities
//There is a local_culture class, an outdoor class and a travel class

using namespace std;
#include <fstream>
#include <cstring>
#include <iostream>

// Do not create any instance of the Activity class
// it is an abstract base class!
class Activity
{
    public:
        Activity(); 
        Activity(char * temp_priority, char * temp_name, char * temp_description, char * temp_date);
        Activity(const Activity & to_copy);
        virtual ~Activity();//dynamic dispatch (at runtime holds until it finds method)        
    
        //Do not implement any of these functions in the base class
        virtual void display() = 0; //PURE VIRTUAL 
        virtual int set_date(char * new_date) = 0; //PURE VIRTUAL        
        virtual bool compare(char * to_compare) = 0;//PURE VIRTUAL

    protected:
        char * priority;        
        char * name;
        char * description;
        char * date;
};



class Local_Culture: public Activity
{
    public:
        Local_Culture();//default constructor        
        Local_Culture(char * priority, char * name, char * description, char * date, char * event);
        Local_Culture(const Local_Culture & to_copy); //take a Local_culture obj and deep copy the data        
        ~Local_Culture();        
        
        void display();
        int set_date(char * new_date);
        bool compare(char * to_compare);

    protected:
        char * event;
};



class Outdoor: public Activity
{
    public:
        Outdoor();        
        Outdoor(char * priority, char * name, char * description, char * date, char * distance);
        Outdoor(const Outdoor & to_copy);        
        ~Outdoor();

        void display();
        int set_date(char * new_date);
        bool compare(char * to_compare);
    
    protected:
        char * distance;
};



class Travel: public Activity
{
    public:
        Travel();
        Travel(char * priority, char * name, char * description, char * date, char * country);
        Travel(const Travel & to_copy);
        ~Travel();
        
        void display();
        int set_date(char * new_date);
        bool compare(char * to_compare);
    
    protected:
        char * country;
};

