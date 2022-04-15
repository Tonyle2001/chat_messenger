//
// Created by Tonyl on 4/11/2022.
//

#ifndef MESSENGER_APP_USER_H
#define MESSENGER_APP_USER_H

#include <string>

using namespace std;

class User {
public:
    User(string, string);
    User(string);

    //getters
    string get_username();
    string get_user_password();

    bool authenticate();
    bool check_unique();
    void get_user_status();

protected:
    string username;




private:
    string user_password;



};


#endif //MESSENGER_APP_USER_H
