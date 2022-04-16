//
// Created by Tonyl on 4/11/2022.
//

#include "Message.h"
#include <iostream>
#include <string>
#include <fstream>
#include <istream>

using namespace std;


Message::Message(string mes, string from_user, string to_user)
    :mail{mes}, receiver{to_user}
{}


//getters
string get_mail();
string get_receiver();

//functions
void out_go();