#include "Header.h"

User::User(string name, string password) : UserName(name), UserPassword(password) {}

Message::Message(string from, string to, string text) : From(from), To(to), Text(text) {}

Server::Server() {}

void Server::RegisterUser(const string& username, const string& password) {
    users.emplace_back(username, password);
}

bool Server::AuthenticateUser(const string& username, const string& password) {
    for (const auto& user : users) {
        if (user.UserName == username && user.UserPassword == password) {
            return true;
        }
    }
    return false;
}

void Server::GetUserInfo(const string& name) {
    for (const auto& user : users) {
        if (user.UserName == name) {
            cout << "��� ��������: " << user.UserName << endl;
            cout << "������ �� ��������: " << user.UserPassword << endl; // � �������� ����������� �� ����������� ������!
            return;
        }
    }
    cout << "������������ �� ������." << endl;
}

void Server::WriteMessage(const string& from, const string& to, const string& text) {
    messages.emplace_back(from, to, text);
}

void Server::GetMessagesForUser(const string& name) {
    bool found = false;
    for (const auto& message : messages) {
        if (message.To == name) {
            cout << "��������� �� " << message.From << ": " << message.Text << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "��������� ���." << endl;
    }
}

void Server::GetGeneral() {
    for (const auto& message : messages) {
        cout << message.From << " �������: " << message.Text << endl;
    }
}