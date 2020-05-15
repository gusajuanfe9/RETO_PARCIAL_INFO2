#include "fun.h"

//En el main de mi programa simplemente se declaran los maps y otras variables, aca se puede observar el primer menu del usuario

int main(){
    int opcion;
    bool ban=1;

    map <int,producto> inv; //Map que almacena el inventario de productos (Clave = N del producto y Contenido=objeto de la clase producto, CONTIENE LAS CARAC. DE CADA PRODUCTO).
    map <int,combo> com; //Mao que almacena los combos disponibles, (Clave = N del combo y Contenido=objeto de la clase combo, CONTIENE LAS CARAC. DE CADA COMBO).
    d_inventario(inv);
    d_combos(com);
    cout<<endl<<endl<<"BIENVENIDO AL SISTEMA DE ALIMENTOS DE NUESTRO CINE"<<endl<<endl;
    while(ban){
        cout<<endl<<"Seleccione:"<<endl<<"1)Entrar como usuario para comprar"<<endl<<"2)Registrarse como nuevo usuario"<<endl<<"3)Entrar como administrador"<<endl<<"0)Cerrar"<<endl;
        cin>>opcion;
        switch(opcion){

        case 1: //Ingresar como usuario
            system("cls");
            ingresar_usu(inv,com);

            break;

        case 2: //Registrarse como usuario
            system("cls");
            registrar_usuario();

            break;
        case 3: //Ingresar como administrador
            system("cls");
            ini_administrador(inv,com);
            break;
        case 0:
            ban=0;
            break;
        default:
            break;
        }
        if(opcion!=0){
            system("pause");
            system("cls");
        }
    }
    g_combos(com);
    g_inventario(inv);
    return 0;
}

