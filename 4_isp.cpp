#include <iostream>
#include <fstream>

using namespace std;

class Log {
public:
    virtual void log(string txt) = 0;
};
class Conection{
public:
    virtual void connect() = 0;

    virtual void disconnect() = 0;
};

class FileLog : public Log, public Conection {
    ofstream salida;
public:
    void connect() override {
        salida.open("log.txt");
    }

    void disconnect() override {
        salida.close();
    }

    void log(string txt) override {
        salida << "LogArchivo: " << txt << endl;
    }
};

class ConsoleLog: public Log{
public:
    void log(string txt) override {
        cout << "Log: " << txt << endl;
    }
};

int main() {
    ConsoleLog cl;

    cl.log("prueba1");
    cl.log("prueba2");

    return 0;
}
