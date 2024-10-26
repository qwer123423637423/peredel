#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User {
public:
    User(string name, string password);
    string UserName;
    string UserPassword;
};

class Message {
public:
    Message(string from, string to, string text);
    string From;
    string To;
    string Text;
};

class Server {
public:
    Server();
    void RegisterUser(const string& username, const string& password);
    bool AuthenticateUser(const string& username, const string& password);
    void GetUserInfo(const string& name);
    void WriteMessage(const string& from, const string& to, const string& text);
    void GetMessagesForUser(const string& name);
    void GetGeneral();

private:
    vector<User> users;
    vector<Message> messages;
};