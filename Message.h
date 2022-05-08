//
// Created by Tonyl on 4/11/2022.
//

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

#ifndef MESSENGER_APP_MESSAGE_H
#define MESSENGER_APP_MESSAGE_H




class Message : public User, public basic_string<char>{
public:

    //constructor
    Message(string, string, string);
    Message(string, string);

    //getters
    string get_mail();
    //friend
    string get_receiver();
    //viewer
    string get_sender();

    //functions
    void out_go();
    void print_history();

protected:

private:
    string mail;
    string receiver;

    User User_Message;
};


#endif //MESSENGER_APP_MESSAGE_H
