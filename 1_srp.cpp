#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Blog {
public:
    string titulo;
    vector<string> entradas;

    void add_entry(string txt) {
        entradas.push_back(txt);
    }
};

class PersisteceManager {
public:
    void save(Blog b, string file) {
        ofstream ofs(file);
        for (auto e: b.entradas) {
            ofs << "Entrada: " << e << '\n';
        }
    }
};

int main() {
    Blog miBlog;
    miBlog.titulo = "Personal";

    miBlog.add_entry("Hoy esta soleado");
    miBlog.add_entry("Con Netflix no me aburro en la cuarentena.");

    for (auto d: miBlog.entradas) {
        cout << "Blog: " << d << '\n';
    }
    PersisteceManager pm;
    pm.save(miBlog, "salida.txt");
    return 0;
}
