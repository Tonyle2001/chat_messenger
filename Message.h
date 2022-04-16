//
// Created by Tonyl on 4/11/2022.
//

#include <iostream>
#include <string>
#include "User.h"

using namespace std;

#ifndef MESSENGER_APP_MESSAGE_H
#define MESSENGER_APP_MESSAGE_H




class Message : public User{
public:

    //constructor
    Message(string, string, string);

    //getters
    string get_mail();
    string get_receiver();

    //functions
    void out_go();

protected:
    string mail;
    string receiver;

};


#endif //MESSENGER_APP_MESSAGE_H
