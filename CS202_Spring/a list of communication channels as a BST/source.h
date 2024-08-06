//source.h
//Program 3
//Cassandra Deatherage
//Spring 2020
//This file is to declare the prototypes for 
//the base class source
//and derived classes; Slack, Zoom, and D2L

using namespace std;
#include <fstream>
#include <cstring>
#include <iostream>

// The Source class is an abstract base class!
// Therefore you cannot create an instance of it

// Each source item has a name, a priortity, and a subject it is related to (school, work, recreation etc.)
// The Source is the base class, and there are 3 classes derived from it. Slack, Zoom, and D2L. 
// Slack has a field for channel
// Zoom has a field for zoom_id
// D2L has a field for course

class Source
{
    public:
        Source(); 
        Source(char * temp_priority, char * temp_name, char * temp_subject);
        Source(const Source & to_copy);
        virtual ~Source();//dynamic dispatch (at runtime holds until it finds method
        
        //Do not implement any of these functions in the base class
        virtual void display() = 0; //PURE VIRTUAL 
        int set_priority(char * temp_priority); 
        virtual bool compare(char * to_compare) = 0;//PURE VIRTUAL
        bool compare_sources(Source & to_compare);//this fn compares two sources to see if they are the same
        friend bool operator < (const Source & l, char * lit);
        friend bool operator < (const char * lit, Source &r);
        friend bool operator < (const Source &l, const Source &r);
        
        friend bool operator > (const Source & l, char * lit); 
        friend bool operator > (char * lit, const Source &r); 
        friend bool operator > (const Source &l, const Source &r);
       
        friend bool operator >= (const Source &, char *); 
        friend bool operator >= (char *, const Source &); 
        friend bool operator >= (const Source &,const Source &);
        
        friend bool operator <= (const Source &, char *); 
        friend bool operator <= (char *, const Source &); 
        friend bool operator <= (const Source &,const Source &);
        
        friend bool operator != (const Source &, char *); 
        friend bool operator != (char *, const Source &); 
        friend bool operator != (const Source &,const Source &);
       
        friend bool operator == (const Source &, char *); 
        friend bool operator == (char *, const Source &); 
        friend bool operator == (const Source &,const Source &);
         
        char * get_priority();
        //int set_priority(char * temp_priority);//forgot this was virtual
        char * get_name();
        int set_name(char * new_name);
        char * get_subject();
        int set_subject(char * new_subject);

    protected:
        char * priority;        
        char * name;
        char * subject;
};


//this is changing to the Slack class
class Slack: public Source
{
    public:
        Slack();//default constructor        
        Slack(char * priority, char * name, char * subject, char * channel);
        Slack(const Slack & to_copy); //deep copy slack channel data 
        ~Slack();        
        //bool operator<(const Slack &l, const Slack &r);
        void display();
        int set_priority(char * new_priority);
        char * get_channel();
        int set_channel(char * new_channel);
        bool compare(char * to_compare);

    protected:
        char * channel;
};


//this is changing to the Zoom class
class Zoom: public Source
{
    public:
        Zoom();        
        Zoom(char * priority, char * name, char * subject, char * zoom_id);
        Zoom(const Zoom & to_copy);        
        ~Zoom();
        //bool operator<(const Zoom &r);

        void display();
        int set_priority(char * new_priority);
        char * get_zoom_id();
        int set_zoom_id(char * new_zoom_id);
        bool compare(char * to_compare);
    
    protected:
        char * zoom_id;
};


//this is changing to the D2L class
class D2L: public Source
{
    public:
        D2L();
        D2L(char * priority, char * name, char * subject, char * course);
        D2L(const D2L & to_copy);
        ~D2L();
        //bool operator<(const D2L &r);
        
        void display();
        int set_priority(char * new_priority);
        char * get_course();
        int set_course(char * new_course);
        bool compare(char * to_compare);
    
    protected:
        char * course;
};


