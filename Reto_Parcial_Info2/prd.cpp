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
