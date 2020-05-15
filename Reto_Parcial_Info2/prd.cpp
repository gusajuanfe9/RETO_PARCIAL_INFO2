#include "prd.h"

void producto::create(string name,int uni_p,int uni_a,int canti,int long long costo){
    nombre=name;
    u_producto=uni_p;
    u_paquete=uni_a;
    cant=canti;
    cost=costo;
    disponible=((uni_p-1)*cant)+uni_a;
}
void producto::v_produc(){
    cout<<'|'<<nombre;
    for(unsigned int i=0;i<(50-nombre.length());i++)
        cout<<' ';
    cout<<'|';
    if(cant<100 && cant>10)
        cout<<" ";
    else
        cout<<"  ";
    cout<<cant<<'|';
    if(cost>=1000 && cost<10000)
        cout<<"  ";
    else if(cost>=10000 && cost<100000)
        cout<<" ";
    cout<<cost<<'|';
}
string producto::guardado(){
    //facilita la funcion de guardado retornando en un string los datos privados a guardar
    string datos;
    datos=nombre+';'+int2str(u_producto)+';'+int2str(u_paquete)+';'+int2str(cant)+';'+int2str(cost);
    return datos;
}
string producto::int2str(int long a){
    //esta funncion se usa para convertir las caracteristicas int a string y poder manejarlas mejor
    int c=0,i=1;
    char e;
    string b;
    for(;(a/i);i=i*10)
        c++;
    for(int j=0;j<c;j++){
        i/=10;
        e=(a/i)+48;
        b.push_back(e);
        a-=(a/i)*i;
    }
    return b;
}
void producto::anadir_cant(int can){
    cant+=can;
}
