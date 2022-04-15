//
// Created by Tonyl on 4/11/2022.
//

#include "User.h"
#include <iostream>
#include <string>

using namespace std;

//constructors
User::User(string name, string pass)
        :username{name}, user_password{pass}
{}


User::User(string name)
        :username{name}
{}


string User::get_username(){
    return this-> username;
}
string User::get_user_password(){
    return this-> user_password;
}

//functions
bool User::authenticate(){

    return true;// this will be replace later when I learn how to use read and write
}

bool User::check_unique(){

    return true; // this will be replace later when I learn how to use read and write
}

void User::get_user_status(){

    cout << "Your profile has been made!\n" << endl;
}