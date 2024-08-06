//content.h
//Program 1
//Cassandra Deatherage

#include <fstream>
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;


//This is the class that controls
//the LLL of rooms
class Content
{
    public:
        Content();
        Content(const Content & to_copy);        
        Content(char * temp_date, char * temp_title);
        virtual ~Content();
        
        void set_next(Content * to_add);
        Content *& get_next();
        
        int compare(char * to_compare);
        //int compare_title(char * to_compare);
        virtual void display() const;

    protected:
        //ptr to LLL of rooms
        Content * next;
        char * date;
        char * title;
};


//content type: message
class Message: public Content
{
    public:
        Message();
        Message(char * date, char * title, char * message);
        ~Message();
        void display() const;

    protected:
        char * message;     
};


//content type: video
class Video: public Content
{
    public:
        Video();
        Video(char * date, char * title, char * genre);
        ~Video();
        void display() const;
    
    protected:
        char * genre;
};


//content type: notes
class Notes: public Content
{
    public:
        Notes();
        Notes(char * date, char * title, char * notes);
        ~Notes();
        void display() const; 
    
    protected:
        char * notes;
};




