//
// Created by Tonyl on 4/11/2022.
//

#include "User.h"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
//#include <iosfwd>



using namespace std;

//constructors

User::User(){}

//This is used to validate existing users

User::User(string name, string pass)
        :username{name}, user_password{pass}
{}


//This is to validate if username has been taken

User::User(string name)
        :username{name}
{}


string User::get_username(){
    return this-> username;
}
string User::get_user_password(){
    return this-> user_password;
}


//setters
void User::set_username(string name){
    this->username = name;
}
void User::set_password(string password){
    this->user_password = password;
}


//functions
bool User::authenticate(){

    ifstream check_file;

    check_file.open(get_username() + ".txt");

    string check_pass;

    if(check_file.is_open()) {

        while(getline(check_file, check_pass, ':')) {
            getline(check_file, check_pass, ':');
            if (check_pass.compare(get_user_password()) == 0) {
                check_file.close();
                return true;
            } else {
                check_file.close();
                return false;
            }
        }
    }
    else
        cout << "\n This user does not exist or you have entered an invalid password.\n" << endl;

}

bool User::check_unique(){

    ifstream check_file;

    check_file.open(get_username() + ".txt");

    if(check_file)
        return true;
    else
        return false;

}

void User::get_user_status(){


    ofstream make_file(get_username() + ".txt");

    make_file << ':' << get_user_password() + ":\n" << endl;

    if(make_file){

        cout << "Welcome " << get_username() << endl;
        cout << "Your profile has been made!\n" << endl;
    }


    make_file.close();

}