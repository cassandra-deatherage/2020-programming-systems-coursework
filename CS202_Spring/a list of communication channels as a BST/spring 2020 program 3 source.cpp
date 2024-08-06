//source.cpp
//Program 3
//Cassandra Deatherage
//Spring 2020

//This file is to implement the functions for the base class Source,
//as well as the derived classes, Slack, Zoom, and D2L

#include "source.h"


//constructor for the base class
Source::Source()
{
    priority = NULL;
    name = NULL;
    subject = NULL;
}


//This constructor takes a char * from
//main and creates dynamic memory to copy
//over the data
Source::Source(char * temp_priority, char * temp_name, char * temp_subject)
{
    priority = new char[strlen(temp_priority)+1];
    strcpy(priority, temp_priority);

    name = new char[strlen(temp_name)+1];
    strcpy(name, temp_name);

    subject = new char[strlen(temp_subject)+1];
    strcpy(subject, temp_subject);
}

//If you have time touch base with a tutor about the next fn's copy method

//Copy Constructor to take the new memory and pass
//into the data structure
Source::Source(const Source & to_copy)
{
    //this is one way to call the constructor..
    //this = new Item(to_copy.priority, to_copy.name, to_copy.subject, to_copy.priority);

    priority = new char[strlen(to_copy.priority)+1];
    strcpy(priority , to_copy.priority);

    name = new char[strlen(to_copy.name)+1];
    strcpy(name, to_copy.name);

    subject = new char[strlen(to_copy.subject)+1];
    strcpy(subject, to_copy.subject);
}


//destructor for the Source Class
Source::~Source()
{
    delete priority;
    priority = NULL;

    delete name;
    name = NULL;

    delete subject;
    subject = NULL;
}



bool Source::operator < (const Source & l, const char * lit)
{
    return (strcmp(l.name, lit)<0);
}
bool Source::operator < (char * lit, const Source &r)
{
    return (strcmp(lit, r.name)<0);
}
bool Source::operator < (const Source &l, const Source &r)
{
    return l.compare_sources(r.name)<0;
}



bool Source::operator > (const Source & l, char * lit); 
{
    return (strcmp(l.name, lit)>0);
}
bool Source::operator > (char * lit, const Source &r); 
{
    return (strcmp(lit, r.name)>0);
}
bool Source::operator > (const Source &, const Source &);
{
    return l.compare_sources(r.name)>0;
}



bool Source::operator >= (const Source &l, char * lit)
{
    return (strcmp(l.name, lit) >= 0);
}
bool Source::operator >= (char * lit, const Source &r); 
{
    return (strcmp(lit, l.name) >= 0);
}
bool Source::operator >= (const Source &,const Source &r);
{
    return (strcmp(lit, r.name) >= 0);
}


bool Source::operator <= (const Source &l, char * lit); 
{
    return (strcmp(l.name, lit) <= 0);
}
bool Source::operator <= (char * lit, const Source &r); 
{
    return (strcmp(lit, r.name) <= 0);
}
bool Source::operator <= (const Source &l,const Source &r);
{
    return (strcmp(l.name, r.name) <= 0);
}
       

bool Source::operator != (const Source &l, char * lit); 
{
    return l.compare_sources(to_compare);
}
bool Source::operator != (char * lit, const Source &r); 
{
    return r.compare_sources(to_compare);
}
bool Source::operator != (const Source &l,const Source &r);
{
    return r.compare_sources(l.to_compare);
}


bool Source::operator == (const Source &, char *); 
{
    return compare_sources(original, to_compare);
}
bool Source::operator == (char *, const Source &); 
{
    return compare_sources(original, to_compare);
}
bool Source::operator == (const Source &,const Source &);
{
    return compare_sources(original, to_compare);
}

//this fn compares two derived sources to see if they are 
//the same based on the information saved in them from the base
//class
bool Source::compare_sources(Source & to_compare)
{
    return strcmp(name, to_compare.name) && strcmp(priority, to_compare.priority) && strcmp(subject, to_compare.subject);

}
//Don't create any of the virtual void classes!
//Don't implement this function in Source Class
/*
void Source::display()
{
    cout << "Source information: " << endl;
    cout<<'\t'<< priority <<endl;
    cout<<'\t'<< name <<endl;
    cout<<'\t'<< subject <<endl;
}
*/


char * Source::get_priority()
{
    return priority;
}
int Source::set_priority(char * temp_priority)
{
    if(priority)
        delete priority;
    priority = new char[strlen(temp_priority)+1];
    strcpy(priority, temp_priority);
    return 1;    
}



char * Source::get_name()
{
    return name;
}
int Source::set_name(char * temp_name)
{
    if(name)
        delete name;
    name = new char[strlen(temp_name)+1];
    strcpy(name, temp_name);
    return 1;    
}



char * Source::get_subject()
{
    return subject;
}
int Source::set_subject(char * temp_subject)
{
    if(subject)
        delete subject;
    subject = new char[strlen(temp_subject)+1];
    strcpy(subject, temp_subject);
    return 1;    
}



//  Derived class functions

//Default Constructor for the Slack Source Class
Slack::Slack():Source()
{
   channel  = NULL;
}


//Constructor for the Slack Source Class
Slack::Slack(char * priority, char * name, char * subject, char * channel):Source(priority, name, subject)
{
    this->channel = new char[strlen(channel)+1];
    strcpy(this->channel, channel);
}


Slack::Slack(const Slack & to_copy):Source(to_copy)//upcasting
{
    this->priority  = new char[strlen(to_copy.priority)+1];
    strcpy(this->priority, to_copy.priority);
    this->name = new char[strlen(to_copy.name)+1];
    strcpy(this->name, to_copy.name);
    this->subject = new char[strlen(to_copy.priority)+1];
    strcpy(this->subject, to_copy.subject);
    this->channel = new char[strlen(to_copy.channel)+1];
    strcpy(this->channel, to_copy.channel);
}


//Destructor for the Slack Class
Slack::~Slack()
{
    delete channel;
}


/*
//< operator 
bool Slack::operator<(const Slack & l, const Slack &r)
{
    //for each element of slack
    return l.compare_sources(r.name)<0;
}
*/


//Display for the Used Item display
void Slack::display()
{
    cout<< "Slack information: "<<endl;
    cout<<'\t'<< "Priority : "<< priority <<endl;
    cout<<'\t'<< "Name : "<< name <<endl;
    cout<<'\t'<< "Subject : "<< subject <<endl;
    cout<<'\t'<< "Channel description : "<< channel <<endl;
    return;
}


char * Slack::get_channel()
{
    return channel;
}
int Slack::set_channel(char * new_channel)
{
    if(channel)
        delete channel;
    channel = new char[strlen(new_channel)+1];
    strcpy(channel, new_channel);
    return 1;    
}


bool Slack::compare(char * to_compare)
{
    return strcmp(name, to_compare);
    //a zero return value means they're even!
}



//Zoom Class
Zoom::Zoom():Source()
{
    zoom_id = NULL;
}


Zoom::Zoom(char * priority, char * name, char * subject, char * zoom_id):Source(priority, name, subject)
{
    this->zoom_id = new char[strlen(zoom_id) +1];
    strcpy(this->zoom_id, zoom_id);
}


Zoom::Zoom(const Zoom & to_copy):Source(to_copy)//upcasting
{
    this->priority  = new char[strlen(to_copy.priority)+1];
    strcpy(this->priority, to_copy.priority);
    this->name = new char[strlen(to_copy.name)+1];
    strcpy(this->name, to_copy.name);
    this->subject = new char[strlen(to_copy.priority)+1];
    strcpy(this->subject, to_copy.subject);
    this->zoom_id = new char[strlen(to_copy.zoom_id)+1];
    strcpy(this->zoom_id, to_copy.zoom_id);
}


Zoom::~Zoom()
{
    delete zoom_id;
}

/*
//< operator 
bool Zoom::operator<(const Zoom &r)
{
    //for each element of zoom
    return l.compare_sources(r.name)<0;
}
*/


void Zoom::display()
{
    cout<< "Zoom information: " <<endl;
    cout<<'\t'<< "Priority : "<< priority <<endl;
    cout<<'\t'<< "Name : "<< name <<endl;
    cout<<'\t'<< "subject : "<< subject <<endl;
    cout<<'\t'<< "The zoom_id for this channel is : "<< zoom_id <<endl;
}


char * Zoom::get_zoom_id()
{
    return zoom_id;
}
int Zoom::set_zoom_id(char * new_zoom_id)
{
    if(zoom_id)
        delete zoom_id;
    zoom_id = new char[strlen(new_zoom_id)+1];
    strcpy(zoom_id, new_zoom_id);
    return 1;    
}


bool Zoom::compare(char * to_compare)
{
    return strcmp(name, to_compare);
    //a zero return value means they're even!
}


//D2L Class
D2L::D2L():Source()
{
   course = NULL;
}


//Constructor that takes the users args and creates dynamic memory
D2L::D2L(char * priority, char * name, char * subject, char * course):Source(priority, name, subject)
{
    this->course = new char[strlen(course) +1];
    strcpy(this->course, course);
}

D2L::D2L(const D2L & to_copy):Source(to_copy)//upcasting
{
    this->priority  = new char[strlen(to_copy.priority)+1];
    strcpy(this->priority, to_copy.priority);
    this->name = new char[strlen(to_copy.name)+1];
    strcpy(this->name, to_copy.name);
    this->subject = new char[strlen(to_copy.priority)+1];
    strcpy(this->subject, to_copy.subject);
    this->course = new char[strlen(to_copy.course)+1];
    strcpy(this->course, to_copy.course);
}


D2L::~D2L()
{
    delete course;
}

/*
//< operator 
bool D2L::operator<(const D2L &r)
{
    //for each element of d2l
    return l.compare_sources(r.name)<0;
}
*/

void D2L::display()
{
    cout << "D2L information: " << endl;
    cout<<'\t'<< "Priority : "<< priority<<endl;
    cout<<'\t'<< "Name : "<< name <<endl;
    cout<<'\t'<< "subject : "<< subject <<endl;
    cout<<'\t'<< "Course number : "<< course <<endl;
}


char * D2L::get_course()
{
    return course;
}
int D2L::set_course(char * new_course)
{
    if(course)
        delete course;
    course = new_course;
    course = new char[strlen(new_course)+1];
    strcpy(course, new_course);
    return 1;    
}


bool D2L::compare(char * to_compare)
{
    return strcmp(name, to_compare);
    //a zero return value means they're even!
}


