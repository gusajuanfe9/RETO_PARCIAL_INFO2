#include "prd.h"

class combo

{
private:

    string contenido;
    map <int,int> ff; //Map donde se almacenan los productos del combo, clave = N del producto y  Contenido = unidades de producto necesarias
    string int2str(int long long a);

public:

    long long int costo;
    void create(map <int,producto> inv);
    void ini(string cont, long long int cost, map <int,int> ff);
    string v_combo();
    bool disp(map <int,producto> inv);
    void comprar_com(map <int,producto> &inv);
    string guardado();

};

