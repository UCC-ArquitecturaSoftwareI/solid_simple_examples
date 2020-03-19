#include <iostream>
#include <vector>

using namespace std;

class Empleado{

};


class Desarrollador: public Empleado{
public:
    Desarrollador(){
        cout << "Nuevo Desarrollador" << endl;
    }
};
class Programador: public Empleado{
public:
    Programador(){
        cout << "Nuevo Programador" << endl;
    }
};
class Tester: public Empleado{
public:
    Tester(){
        cout << "Nuevo Tester" << endl;
    }
};

class Manager{
    vector<Empleado> empl;

public:
    void addEmpleado(Empleado d){
        empl.push_back(d);
    }
};



int main() {
    Manager m;

    m.addEmpleado(Tester());
    m.addEmpleado(Desarrollador());
    m.addEmpleado(Programador());
    m.addEmpleado(Desarrollador());
    m.addEmpleado(Desarrollador());

    return 0;
}
