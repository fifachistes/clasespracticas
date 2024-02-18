#include <iostream>// KEI U ARE THE GOAT U HEAR ME?? UR THE FUCKING GOATTTTTTTTTTTTT
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_EMPLEADOS = 100;
typedef enum {
    ESO, Bachillerato, FP_Medio, FP_Superior, Grado, Master, Doctor
} tEstudios;
typedef enum {
    Fijo, Practicas, Eventual, Becario
} tTipoContrato;
typedef struct {
    string nombre;
    int edad;
    tEstudios estudios;
    tTipoContrato contrato;
} tEmpleado;
typedef struct {
    int numEmpleados;
    tEmpleado empleados[MAX_EMPLEADOS];
} tPlantilla;

//prototipos
void cargar(tPlantilla& plantilla);
void mostrar(tPlantilla plantilla);
int menu();
void insertar(tPlantilla& plantilla);
void eliminar(tPlantilla& plantilla);

int main() {
    tPlantilla plantilla;
    int aux;
    do {
        aux = menu();
        switch (aux) {
        case 1:cargar(plantilla);
            break;
        case 2:insertar(plantilla);
            break;
        case 3:eliminar(plantilla);
            break;
        case 4:mostrar(plantilla);
            break;
        default:
            cout << " mal hecho" << endl;
            break;
        }

    } while (aux != 5);

    return 0;
}
   /* 
    int eleccion = 1;
    while (eleccion != 5) {
        eleccion = menu(plantilla);
        cout << endl << endl;
    }
    if (plantilla.numEmpleados > 1) {
        cout << endl << "<<<<< " << plantilla.numEmpleados << " EMPLEADOS RESTANTES >>>>>" << endl;
    }
    else {
        cout << endl << "<<<<< " << plantilla.numEmpleados << " EMPLEADO RESTANTE >>>>>" << endl;
    }
    mostrar(plantilla);  */
   
int menu() {
    int op;
    cout << "OPCION 1: Cargar lista de empleados" << endl
        << "OPCION 2: Insertar un empleado en una posicion deseada" << endl
        << "OPCION 3: Eliminar un empleado de la posicion deseada" << endl
        << "OPCION 4: Mostrar lista de empleados" << endl
        << "OPCION 5: SALIR" << endl
        << ">>>> ";
    cin >> op;
    return op;
}
void eliminar(tPlantilla& plantilla) {
    int posEli;
    int tipo;
    for (int i = 0;i < plantilla.numEmpleados;i++) {
        cout << "Posicion " << i << " " << plantilla.empleados[i].nombre << endl;
    }
    cout << endl << "En que posicion desea eliminar el empleado?(Hay " << plantilla.numEmpleados << " empleados atualmente): ";
    cin >> posEli;
    for (int i = posEli;i < plantilla.numEmpleados-1;i++) {
        plantilla.empleados[i].nombre = plantilla.empleados[i + 1].nombre;
        plantilla.empleados[i].edad = plantilla.empleados[i + 1].edad;
        plantilla.empleados[i].contrato = plantilla.empleados[i + 1].contrato;
        plantilla.empleados[i].estudios = plantilla.empleados[i + 1].estudios;
    }
    plantilla.numEmpleados--;
}
void insertar(tPlantilla& plantilla) {
    if (plantilla.numEmpleados < MAX_EMPLEADOS) {
        int posIn;
        int tipo;
        if (plantilla.numEmpleados < MAX_EMPLEADOS) {
            for (int i = 0;i < plantilla.numEmpleados;i++) {
                cout << "Posicion " << i << " " << plantilla.empleados[i].nombre << endl;
            }
            cout << endl << "En que posicion desea introducir el nuevo empleado?(Hay " << plantilla.numEmpleados << " empleados atualmente): ";
            cin >> posIn;
            for (int i = plantilla.numEmpleados;i > posIn;i--) {
                plantilla.empleados[i].nombre = plantilla.empleados[i - 1].nombre;
                plantilla.empleados[i].edad = plantilla.empleados[i - 1].edad;
                plantilla.empleados[i].contrato = plantilla.empleados[i - 1].contrato;
                plantilla.empleados[i].estudios = plantilla.empleados[i - 1].estudios;
            }
            cout << "Nombre del empleado: ";
            cin >> plantilla.empleados[posIn].nombre;
            cout << "Edad del empleado: ";
            cin >> plantilla.empleados[posIn].edad;
            cout << "Tipo de contrato del empleado: " << endl
                << "0 para Fijo" << endl
                << "1 para Practicas" << endl
                << "2 para Eventual" << endl
                << "3 para Becario" << endl
                << ">>> ";
            cin >> tipo;
            if (tipo == 0) {
                plantilla.empleados[posIn].contrato = Fijo;
            }
            else if (tipo == 1) {
                plantilla.empleados[posIn].contrato = Practicas;
            }
            else if (tipo == 2) {
                plantilla.empleados[posIn].contrato = Eventual;
            }
            else if (tipo == 3) {
                plantilla.empleados[posIn].contrato = Becario;
            }
            cout << "Estudios del empleado: " << endl
                << "0 para ESO" << endl
                << "1 para Bachillerato" << endl
                << "2 para FP_Medio" << endl
                << "3 para FP_Superior" << endl
                << "4 para Grado" << endl
                << "5 para Master" << endl
                << "6 para Doctor" << endl
                << ">>> ";
            cin >> tipo;
            if (tipo == 0) {
                plantilla.empleados[posIn].estudios = ESO;
            }
            else if (tipo == 1) {
                plantilla.empleados[posIn].estudios = Bachillerato;
            }
            else if (tipo == 2) {
                plantilla.empleados[posIn].estudios = FP_Medio;
            }
            else if (tipo == 3) {
                plantilla.empleados[posIn].estudios = FP_Superior;
            }
            else if (tipo == 4) {
                plantilla.empleados[posIn].estudios = Grado;
            }
            else if (tipo == 5) {
                plantilla.empleados[posIn].estudios = Master;
            }
            else if (tipo == 6) {
                plantilla.empleados[posIn].estudios = Doctor;
            }
            plantilla.numEmpleados++;
        }
    }
    else {
        cout << "La lista esta llena, no se puede insertar mas empleados" << endl;
    }
}
void mostrar(tPlantilla plantilla) {
    if (plantilla.numEmpleados > 0) {
        for (int i = 0;i < plantilla.numEmpleados;i++) {
            cout << left << setw(10) << plantilla.empleados[i].nombre
                << left << setw(4) << plantilla.empleados[i].edad;
            if (plantilla.empleados[i].contrato == Fijo) {
                cout << left << setw(11) << "Fijo";
            }
            else if (plantilla.empleados[i].contrato == Practicas) {
                cout << left << setw(11) << "Practicas";
            }
            else if (plantilla.empleados[i].contrato == Eventual) {
                cout << left << setw(11) << "Eventual";
            }
            else if (plantilla.empleados[i].contrato == Becario) {
                cout << left << setw(11) << "Becario";
            }

            if (plantilla.empleados[i].estudios == 0) {
                cout << left << setw(15) << "ESO";
            }
            else if (plantilla.empleados[i].estudios == 1) {
                cout << left << setw(15) << "Bachillerato";
            }
            else if (plantilla.empleados[i].estudios == 2) {
                cout << left << setw(15) << "FP_Medio";
            }
            else if (plantilla.empleados[i].estudios == 3) {
                cout << left << setw(15) << "FP_Superior";
            }
            else if (plantilla.empleados[i].estudios == 4) {
                cout << left << setw(15) << "Grado";
            }
            else if (plantilla.empleados[i].estudios == 5) {
                cout << left << setw(15) << "Master";
            }
            else if (plantilla.empleados[i].estudios == 6) {
                cout << left << setw(15) << "Doctor";
            }
            cout << endl;
        }
    }
    else {
        cout << "Lista vacia" << endl;
    }
}

void cargar(tPlantilla& plantilla) {
    fstream archivo("emple.txt");

    string aux;
    int opcion;
    plantilla.numEmpleados = 0;
    if (archivo.is_open()) {
        archivo >> plantilla.empleados[plantilla.numEmpleados].nombre;
        while (plantilla.numEmpleados < MAX_EMPLEADOS && plantilla.empleados[plantilla.numEmpleados].nombre != "XXX") {


            archivo >> plantilla.empleados[plantilla.numEmpleados].edad;
            archivo >> aux;
            if (aux == "Fijo") {
                plantilla.empleados[plantilla.numEmpleados].contrato = Fijo;
            }
            else if (aux == "Practicas") {
                plantilla.empleados[plantilla.numEmpleados].contrato = Practicas;
            }
            else if (aux == "Eventual") {
                plantilla.empleados[plantilla.numEmpleados].contrato = Eventual;
            }
            else if (aux == "Becario") {
                plantilla.empleados[plantilla.numEmpleados].contrato = Becario;
            }
            archivo >> aux;

            if (aux == "ESO") {
                plantilla.empleados[plantilla.numEmpleados].estudios = ESO;
            }
            else if (aux == "Bachillerato") {
                plantilla.empleados[plantilla.numEmpleados].estudios = Bachillerato;
            }
            else if (aux == "FP_Medio") {
                plantilla.empleados[plantilla.numEmpleados].estudios = FP_Medio;
            }
            else if (aux == "FP_Superior") {
                plantilla.empleados[plantilla.numEmpleados].estudios = FP_Superior;
            }
            else if (aux == "Grado") {
                plantilla.empleados[plantilla.numEmpleados].estudios = Grado;
            }
            else if (aux == "Master") {
                plantilla.empleados[plantilla.numEmpleados].estudios = Master;
            }
            else if (aux == "Doctor") {
                plantilla.empleados[plantilla.numEmpleados].estudios = Doctor;
            }
            plantilla.numEmpleados++;
            archivo >> plantilla.empleados[plantilla.numEmpleados].nombre;
        }
        cout << endl << "CARGA EXITOSA" << endl;
    }
    else {
        cout << "CARGA FALLIDA" << endl;
    }
}
