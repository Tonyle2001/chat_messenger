//Tony Le
// CSCE 306; Spring 2022
//chat app; portfolio project

// Summary code:


#include <iostream>
#include <string>
#include <limits>
#include "Message.h"
#include "User.h"
#include <stdio.h>

using namespace std;

//Function intializing
void first_page();

void login_page();

void new_user_page();

void main_page(string);

void option_1(string);

void option_3(string);


//global variable
int choice = 0;
string name;
string pass;
string pass_2;


int main() {

    //User profile();

    // function calls
    first_page();
    User current(name);
    main_page(current.get_username());

    return 0;
}

//Function implemention
void first_page(){
    //First Page:
    cout << "How may I help you today?";
    //int choice = 0;
    while( choice == 0 || choice > 2){
        cout << "Select which option by entering a number\n";
        cout << "\t1) Login \n\t2) Create new user" << endl;
        cin >> choice;

        if(choice == 1)
            login_page();
        else if(choice == 2)
            new_user_page();
    }
}

void login_page() {

    bool auth = false;

    while (auth != true) {
        cout << "Enter Username: " << endl;
        cin >> name;
        cout << "Enter Password: "  << endl;
        cin >> pass;
        User login(name, pass);
        auth = login.authenticate();

        if(auth == false)
            cout << "\n This user does not exist or you have entered an invalid password.\n" << endl;
    }
}
void new_user_page(){


    bool unique = true;

    while(unique == true) {

        cout << "Enter Username of choice: " << endl;
        cin >> name;
        User create(name);
        unique = create.check_unique();
        if (unique == true)
            cout << "This username is taken." << endl;
    }

        do{
            cout << "Enter password of choice: \n";
            cin >> pass;
            cout << "Re-enter password: " << endl;
            cin >> pass_2;

            if(pass != pass_2)
                cout <<  "The password does not match.\n" << endl;

        }while (pass != pass_2);

        User profile(name, pass);
        //profile.set_username(name);
        //profile.set_password(pass);
        profile.get_user_status(); // this will check if the user was successfully added

}

void main_page(string cur_name){

    int option = 0;
    do{

        cout << "\n\tWelcome to Tony's messenger app!\n\n";
        cout << "What would you like to do? (Enter Number Option)\n";
        cout << "\t1) Send a message to a another user\n";
        cout << "\t2) Send a mass message to multiple user\n";
        cout << "\t3) View chat history between you and specific user\n";
        cout << "\t4) Logout\n" << endl;
        cin >> option;

        if(option == 1) {
            option_1(cur_name);
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            //option = 0;
        }

//
        else if(option == 3) {
            option_3(cur_name);
        }


    }while(option != 4 );

    cout << "\n\tThank you for using my app!" << endl;

}

void option_1(string from){

    string from_person = from;
    string to_person;
    string chat;
    bool see = false;

    do{
        cout << "Who is the user you want to send a message to?\n";
        cin >> to_person;
        User check(to_person);
        see = check.check_unique();

        if(see != true)
            cout << "\n This user does not exist!\n" << endl;

    }while(see != true); //function in User class that will return bool to see if User entered in a valid name.

    cout << "What is the message you would like to send?\n";

    getline(cin >>ws, chat);

    //cout << chat << endl;

    Message send(chat, to_person, from_person);
    send.out_go(); //function in Message class that will write a message to txt file to a specific location under receiver.
    //cout << send.get_mail() << endl;
    cout << "Message was sent!" << endl;


}

void option_3(string viewer){

    string viewer_person = viewer;
    string friend_person;
    string chat;
    bool see = false;

    do{
        cout << "Enter the user of the chat history you want to view.\n";
        cin >> friend_person;
        User check(friend_person);
        see = check.check_unique();

        if(see != true)
            cout << "\n This user does not exist!\n" << endl;

    }while(see != true); //function in User class that will return bool to see if User entered in a valid name.

    Message look(friend_person, viewer_person);
    look.print_history();

}
