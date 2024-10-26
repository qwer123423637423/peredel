#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    Server server;
    string username, userpassword;

    while (true) {
        int answer = 0;
        cout << "1. Войти" << endl;
        cout << "2. Зарегестрироваться" << endl;
        cin >> answer;

        if (answer == 1) {
            while (true) {
                cout << "Введите логин и пароль" << endl;
                cin >> username >> userpassword;

                if (server.AuthenticateUser(username, userpassword)) {
                    break;
                }
                else {
                    cout << "Неверный логин или пароль!" << endl;
                }
            }
        }
        else if (answer == 2) {
            while (true) {
                cout << "Введите логин и пароль" << endl;
                cin >> username >> userpassword;

                // Проверка на существование пользователя
                if (server.AuthenticateUser(username, userpassword)) {
                    cout << "Пользователь с таким ником уже существует" << endl;
                }
                else {
                    server.RegisterUser(username, userpassword);
                    break;
                }
            }
        }
        else {
            break;
        }

        while (true) {
            cout << "1. Написать сообщение" << endl;
            cout << "2. Информация об аккаунте" << endl;
            cout << "3. Выйти из аккаунта" << endl;
            cout << "4. Показать входящие сообщения" << endl;
            cout << "5. Показать общий чат" << endl;
            cout << "6. Написать в общий чат" << endl;

            int action;
            cin >> action;

            if (action == 1) {
                string recipient, text;
                cout << "Кому отправить?" << endl;
                cin >> recipient;
                cout << "Введите сообщение" << endl;
                cin.ignore(); // Игнорируем остаток строки
                getline(cin, text);
                server.WriteMessage(username, recipient, text);
            }
            else if (action == 2) {
                server.GetUserInfo(username);
            }
            else if (action == 3) {
                break;
            }
            else if (action == 4) {
                server.GetMessagesForUser(username);
            }
            else if (action == 5) {
                server.GetGeneral();
            }
            else if (action == 6) {
                string text;
                cout << "Введите сообщение" << endl;
                cin.ignore(); // Игнорируем остаток строки
                getline(cin, text);
                server.WriteMessage(username, "general", text);
            }
            else {
                cout << "Такого выбора нет" << endl;
                break;
            }
        }
    }

    return 0;
}