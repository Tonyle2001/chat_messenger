//
// Created by Tonyl on 4/11/2022.
//

#ifndef MESSENGER_APP_USER_H
#define MESSENGER_APP_USER_H

#include <string>

using namespace std;

class User {
public:

    User();
    //This is used to validate existing users
    User(string, string);
    //This is to validate if username has been taken
    User(string);

    //getters
    string get_username();
    string get_user_password();

    bool authenticate();
    bool check_unique();
    void get_user_status();
    void set_username(string);
    void set_password(string);

    string username;
protected:
    //string username;






private:
    string user_password;



};


#endif //MESSENGER_APP_USER_H
