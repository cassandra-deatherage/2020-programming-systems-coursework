//main.cpp
//Cassandra Deatherage
//Program 2
#include "list.h"
//add activities to a list: types: cultural, outdoor, travel

using namespace std;

int main()
{
    // User Interface  
    List  my_list;

    int choice = -1;
    while(choice != 0)//main menu
    {
        cout<<'\t'<<"Please enter your choice : "<<endl;
        cout<<'\t'<<"Type 1 to add an activity : "<<endl;
        cout<<'\t'<<"Type 2 to remove an activity : "<<endl;
        cout<<'\t'<<"Type 3 to display the list of activities: "<<endl;
        cout<<'\t'<<"Type 4 to search for an activity : "<<endl;
        cout<<'\t'<<"Type 0 to quit: "<<endl;

        cin>>choice;
        cin.ignore(100, '\n');
        if(choice == 1)//add an activity
        {
            int type = -1;
            while(type != 0)
            {
                cout<<'\t'<<"Please enter your choice : "<<endl;
                cout<<'\t'<<"Type 1 to add a local cultural activity : "<<endl;
                cout<<'\t'<<"Type 2 to add an outdoor activity : "<<endl;
                cout<<'\t'<<"Type 3 to add a travel activity : "<<endl;
                cout<<'\t'<<"Type 0 to go back to the main menu : "<<endl;

                cin>>type;
                cin.ignore(100, '\n');
                if(type == 1)// Local Culture
                {
                    int x = my_list.add_Local_Culture();
                    if(x == 1)
                    {
                        cout<<'\t'<<'\n'<<" Success "<<'\n'<<endl;
                    }
                    else
                        cout<<'\t'<<'\n'<<" Failure "<<'\n'<<endl;
                }
                if(type == 2)// Outdoor
                {
                    int x = my_list.add_Outdoor();
                    if(x == 1)
                    {
                        cout<<'\t'<<'\n'<<" Success "<<'\n'<<endl;
                    }
                    else
                        cout<<'\t'<<'\n'<<" Failure "<<'\n'<<endl;
                }
                if(type == 3)// Travel
                {
                    int x = my_list.add_Travel();
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
            // remove an activity from the list
            char to_remove[100];
            cout<<'\t'<<" Please enter the name of the activity you would like to remove : "<<endl;
            cin.get(to_remove, 100, '\n');
            cin.ignore(100, '\n');
            int x = my_list.remove_activity(to_remove);
            if(x == 1)
            {
                List my_activity;
                cout<<'\n'<<'\t'<<" The activity was removed successfully"<<'\n'<<endl;
                my_activity.display();
            }
            else
                cout<<'\n'<<" Failure "<<'\n'<<endl;
        }
        if(choice == 3)
        {
            cout<<'\t'<<" Here are all of the activities in the list : "<<'\n'<<endl;
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
            cout<<'\t'<<"Please enter the name of the activity you would like to find : "<<endl;
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



