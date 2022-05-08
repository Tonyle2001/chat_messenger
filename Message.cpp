//
// Created by Tonyl on 4/11/2022.
//

#include "Message.h"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

using namespace std;


Message::Message(string mes, string to_user, string from_user)
    :mail{mes}, receiver{to_user}, User_Message(from_user)
{}

Message::Message(string friend_user, string viewer_user)
        :receiver{friend_user}, User_Message(viewer_user)
{}


//getters
string Message::get_mail(){
    return this-> mail;
}
string Message::get_receiver(){
    return this->receiver;
}
string Message::get_sender() {
    return User_Message.get_username();
}

//functions
void Message::out_go(){

    //
    ofstream send_file1(get_sender() + ".txt",ios::app);
    send_file1 << get_sender() << ":" << get_mail() << ":" << endl;
    send_file1.close();

    //
    ofstream send_file2(get_receiver() + ".txt", ios::app);
    send_file2 << get_sender() <<":" << get_mail() << ":" << endl;
    send_file2.close();

}

void Message::print_history(){

    ifstream view_file;

    view_file.open(get_sender() + ".txt");

    string sentence;

    while(getline(view_file, sentence)){
        cout << sentence << endl;
    }
}
