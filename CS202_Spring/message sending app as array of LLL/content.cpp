//content.cpp
//Program 1
//Cassandra Deatherage
#include "content.h"


//The Content Class holds onto the date of the 
//entry and has 3 derived classes 
Content::Content()
{
    next = NULL;
    date = NULL;
    title = NULL;
}

Content::Content(const Content & to_copy)
{
    next = NULL;
    date = new char[strlen(to_copy.date)+1];
    strcpy(date, to_copy.date);
    title = new char[strlen(to_copy.title)+1];
    strcpy(title, to_copy.title);
}


Content::Content(char * temp_date, char * temp_title)
{
    next = NULL;
    date = new char[strlen(temp_date)+1];
    strcpy(date, temp_date);
    title = new char[strlen(temp_title)+1];
    strcpy(title, temp_title);
}

Content::~Content()
{
    delete date;
    date = NULL;
    delete title;
    title = NULL;
}


void Content::set_next(Content * my_content)
{
    next = my_content;
}


Content *& Content::get_next()
{
    return next;
}

int Content::compare(char * to_compare)
{
    return strcmp(title, to_compare);
}
/*
int Content::compare_title(char * to_compare)
{
    return strcmp(title, to_compare);
}
*/
void Content::display() const
{
    cout << "Date content was entered: " << '\n'<<endl;
    cout<<'\t'<< date <<endl;
    cout << " Title : " << '\n'<<endl;
    cout<<'\t'<< title <<endl;
}

//MESSAGE CLASS FUNCTIONS
Message::Message():Content()
{
    message = NULL; 
}

Message::Message(char * date, char * title, char * new_message):Content(date, title)
{
    message = new char[strlen(new_message)+1];
    strcpy(message, new_message);
}

Message::~Message()
{
    message = NULL;
}
void Message::display() const
{
    cout<< '\t' <<" Date entered: "<< date <<endl;
    cout<< '\t' <<" Title: "<< title <<endl;
    cout<<'\t'<<" Message : "<< message <<'\n'<<endl; 
}


//VIDEO CLASS FUNCTIONS
Video::Video():Content()
{
    genre = NULL;
}

Video::Video(char * date, char * title, char * new_genre):Content(date, title)
{
    //dynamically allocate
    genre = new char[strlen(new_genre)+1];
    strcpy(genre, new_genre);
}

Video::~Video()
{
    genre = NULL;
}

void Video::display() const
{
    cout<< '\t' <<" Date entered: "<< date <<endl;
    cout<< '\t' <<" Title: "<< title <<endl;
    cout<<'\t'<<" This Video is in the "<< genre <<" genre "<<'\n'<<endl; 
}


//NOTES CLASS FUNCTIONS
Notes::Notes():Content()
{
   notes = NULL; 
}

Notes::Notes(char * date, char * title, char * new_notes):Content(date, title)
{
    notes = new char[strlen(new_notes)+1];
    strcpy(notes, new_notes);
}

Notes::~Notes()
{
    notes = NULL;
}

void Notes::display() const
{
    cout<< '\t' <<" Date entered: "<< date <<endl;
    cout<< '\t' <<" Title: "<< title <<endl;
    cout<<'\t'<<" Notes: "<< notes <<'\n'<<endl;
}


