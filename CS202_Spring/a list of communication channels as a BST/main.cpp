//main.cpp
//Cassandra Deatherage
//Spring 2020
//This file interfaces with the user and allows 
//They are given options to add new items to 
//their list of sources they can add a new 
//slack channel, a new zoom id, or a new D2L
//course to a balanced search tree data structure
#include "list.h"

using namespace std;

//change all prompts to work with new class types
int main()
{
    // User Interface  
    List  my_list;

    int choice = -1;
    while(choice != 0)//main menu
    {
        cout<<'\t'<<"Please enter your choice : "<<endl;
        cout<<'\t'<<"Type 1 to add a new source : "<<endl;
        cout<<'\t'<<"Type 2 to remove a source : "<<endl;
        cout<<'\t'<<"Type 3 to display the list of sources: "<<endl;
        cout<<'\t'<<"Type 4 to search for a source : "<<endl;
        cout<<'\t'<<"Type 0 to quit: "<<endl;

        cin>>choice;
        cin.ignore(100, '\n');
        if(choice == 1)//add a source
        {
            int type = -1;
            while(type != 0)
            {
                cout<<'\t'<<"Please enter your choice : "<<endl;
                cout<<'\t'<<"Type 1 to add a new slack channel : "<<endl;
                cout<<'\t'<<"Type 2 to add a new zoom id : "<<endl;
                cout<<'\t'<<"Type 3 to add a new D2L course : "<<endl;
                cout<<'\t'<<"Type 0 to go back to the main menu : "<<endl;

                cin>>type;
                cin.ignore(100, '\n');
                if(type == 1)// slack
                {
                    int x = my_list.add_Slack();
                    if(x == 1)
                    {
                        cout<<'\t'<<'\n'<<" Success "<<'\n'<<endl;
                    }
                    else
                        cout<<'\t'<<'\n'<<" Failure "<<'\n'<<endl;
                }
                if(type == 2)// zoom
                {
                    int x = my_list.add_Zoom();
                    if(x == 1)
                    {
                        cout<<'\t'<<'\n'<<" Success "<<'\n'<<endl;
                    }
                    else
                        cout<<'\t'<<'\n'<<" Failure "<<'\n'<<endl;
                }
                if(type == 3)// D2L
                {
                    int x = my_list.add_D2L();
                    if(x == 1)
                    {
                        cout<<'\t'<<'\n'<<" Success "<<'\n'<<endl;
                    }
                    else
                        cout<<'\t'<<'\n'<<" Failure "<<'\n'<<endl;
                }
            }
        }
        if(choice == 2)
        {
            // remove a source from the list
            char to_remove[100];
            cout<<'\t'<<" Please enter the name of the source you would like to remove : "<<endl;
            cin.get(to_remove, 100, '\n');
            cin.ignore(100, '\n');
            int x = my_list.remove_source(to_remove);
            if(x == 1)
            {
                List my_source;
                cout<<'\n'<<'\t'<<" The source was removed successfully"<<'\n'<<endl;
                my_source.display();
            }
            else
                cout<<'\n'<<" Failure "<<'\n'<<endl;
        }
        if(choice == 3)
        {
            cout<<'\t'<<" Here are all of the sources in the list : "<<'\n'<<endl;
            int x = my_list.display();
            if(x == 1)
            {
                cout<<'\n'<<'\t'<<" Success "<<'\n'<<endl;
            }
            else 
            {
                cout<<'\n'<<'\t'<<" Failure "<<'\n'<<endl;
            }
        }
        if(choice == 4)
        {
            // find an item
            cout<<'\t'<<"Please enter the name of the sources you would like to find : "<<endl;
            char to_search[100]; 
            cin.get(to_search, 100, '\n');
            cin.ignore(100, '\n');
            int x = my_list.find(to_search);
            if(x == 1)
            {
                cout<<'\n'<<'\t'<<" Success" <<'\n'<<endl;
            }
            else
                cout<<'\n'<<'\t'<<" Failure" <<'\n'<<endl;
        }
    }
return 0;
} 




