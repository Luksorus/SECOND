#include <iostream>
#include <string>

using namespace std;

class NotifierBase
{
public:
    virtual void notify(const string &mesage) = 0;
};

void SendBK(const string& id, const string& message) {
    cout << "Send '" << message << "' to BK user " << id << endl;
}

void SendTelegraph(const string& login, const string& message) {
    cout << "Send '" << message << "' to Telegraph user " << login << endl;
}


class BKNotifier : public NotifierBase
{
private:
    string id;

public:
    BKNotifier(string id)
    {
        this->id = id;
    }
    void notify(const string &message)
    {
        SendBK(this->id, message);
    }
};

class TelegraphNotifier : public NotifierBase
{
private:
    string login;

public:
    TelegraphNotifier(string login)
    {
        this->login = login;
    }
    void notify(const string &message)
    {
        SendTelegraph(this->login, message);
    }
}; 
 
#include "main2_2.cpp"
