//main.cpp
//Program 1
//Cassandra Deatherage

#include "app.h"
using namespace std;

//User Interface
int main()
{
    Application my_app;

    int choice = -1;
    do
    {

        cout<<'\t'<<" Please enter your choice : "<<endl;
        cout<<'\t'<<" Type 1 to add a user : "<<endl;
        cout<<'\t'<<" Type 2 to display all of the users : "<<endl;
        cout<<'\t'<<" Type 3 to add new content: "<<endl;
        cout<<'\t'<<" Type 4 to display content by User : "<<endl; 
        cout<<'\t'<<" Type 5 to display all users and their content : "<<endl;
        cout<<'\t'<<" Type 6 to remove content by user and title : "<<endl; 
        cout<<'\t'<<" Type 0 to quit: "<<endl;
        cin>>choice;
        cin.ignore(100, '\n');
        if(choice == 1)
        {
            //add a new user 
            char temp_name[100]; 
            cout<<'\t'<<" Please enter the name of the user you would like to add : "<<endl;
            cin.get(temp_name,100, '\n');
            cin.ignore(100, '\n');
            my_app.add_user(temp_name);
        }
        if(choice == 2)
        {
            //display all users in array 
            cout<<'\t'<<" These are all of the Users in the array : "<<endl;
            my_app.display_all_users(); 
        }
        if(choice == 3)
        {
            //add new content to the LLL 
            char name[100];
            char date[100];
            char title[100];           
            cout<<'\t'<<" Please enter the name of the user who would like to add content : "<<endl;
            cin.get(name, 100, '\n');
            cin.ignore(100, '\n');
            
            cout<<'\t'<<" Please enter todays date in the format xx/xx/xxxx : "<<endl;
            cin.get(date, 100, '\n');
            cin.ignore(100, '\n');
            
            cout<<'\t'<<" Please enter the title of the content you would like to add : "<<endl;
            cin.get(title, 100, '\n');
            cin.ignore(100, '\n');

            //my_app.add_content(name, date, title);
            
            //add new content
            int c = -1;
            cout<<'\t'<<" What type of content would you like to send? "<<endl;
            cout<<'\t'<<" Type 1 for a message : "<<endl;
            cout<<'\t'<<" Type 2 for a video : "<<endl;
            cout<<'\t'<<" Type 3 for notes : " <<endl;
            cin>>c;
            cin.ignore(100, '\n');
            if(c == 1)
            {
                //call add message 
                char message[100];           
                cout<<'\t'<<" Please enter your message: "<<endl;
                cin.get(message, 500, '\n');
                cin.ignore(100, '\n');
                Message * temp = new Message(date, title, message);//upcasting message ptr plus more
                my_app.add_content(temp, name);//passing into fn that expects a content ptr
            }
            if(c == 2)
            {
                //call add video fn 
                char genre[100];           
                cout<<'\t'<<" Please enter the genre of video you are adding : "<<endl;
                cin.get(genre, 100, '\n');
                cin.ignore(100, '\n');
                Video * temp = new Video(date, title, genre);
                my_app.add_content(temp, name);
            }
            if(c == 3)
            {
                //call add notes fn 
                char notes[100];           
                cout<<'\t'<<" Please enter your notes : "<<endl;
                cin.get(notes, 100, '\n');
                cin.ignore(100, '\n');
                Notes * temp = new Notes(date, title, notes);
                my_app.add_content(temp, name);
            }

        }
        if(choice == 4)
        {
            //display all content at one users index
            char name[100]; 
            cout<<'\t'<<" Please enter the Name of the user who's content you'd like to see : " <<endl;
            cin.get(name, 100, '\n');
            cin.ignore(100, '\n');
            my_app.display_content_by_user(name);
        }
        if(choice == 5)
        {
            //display all content for every user
            my_app.display_all_content();
        }
        if(choice == 6)
        {
           //remove content by user and title
           char title[100];
           char name[100];
           cout<<'\t'<<"Content is removed by name and title. Please enter the name of the user who's content you would like to remove : "<<endl;
           cin.get(name, 100, '\n');
           cin.ignore(100, '\n');
               
            cout<<"Please enter the title : "<< endl;
            
           cin.get(title, 100, '\n');
           cin.ignore(100, '\n');
           my_app.remove_content(name, title);
        }
    }while(choice != 0);//main menu
    
    return 0;
} 
    


