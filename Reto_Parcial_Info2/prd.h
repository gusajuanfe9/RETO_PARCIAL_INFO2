#include <iostream>

using namespace std;
#include <fstream>
#include <math.h>
#include <map>
#include <list>
#include <ctime>

class producto
{
private:
    string nombre;
    int u_producto; //Unidades de cada producto
    int u_paquete; //Unidades paquete ya abierto
    int cant;
    int long long cost;
    string int2str(int long a);
public:
    void create(string name,int uni_p,int uni_a,int canti,int long long costo);
    void s_produc(int num);
    void v_produc();
    void anadir_cant(int can);
    string guardado();
    unsigned int disponible;//Variable que determina la disponibilidad del producto
};
