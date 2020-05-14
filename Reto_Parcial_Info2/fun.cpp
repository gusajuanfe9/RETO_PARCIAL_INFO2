#include "fun.h"

string leer_Txt(string arch){ //Abre archivo y retorna su contenido mediante un string
    long long int tam;
    string salida, s2;
    char s;
    fstream k_1(arch, ios::in | ios::ate);
    tam=k_1.tellg();
    k_1.close();
    fstream k(arch.c_str(), ios::in | ios::binary);
    for(long long int i=0;i<tam;i++){
        k.get(s);
        salida.push_back(s);
    }
    k.close();
    return salida;
}

void escribir_txt(string texto,string arch){ //Funcion basica para escribir en un archivo
    ofstream k(arch.c_str(), ios::out | ios::binary);
    k<<texto;
    k.close();
}


void ini_administrador() {

}
void d_inventario(){

}
void d_combos(){

}
void ingresar_usu(){

}
void registrar_usuario(){
// Registrar nuevos usuarios en otro .txt
    map <string,string> users;
    c_usuarios(users);
    string clave,usuario,datos=leer_Txt("users.txt");
    usuario=(users.begin())->first;
    while(users.find(usuario)!=users.end()){
        cout<<"Ingrese su numero de documento: ";
        cin>>usuario;
        if(users.find(usuario)!=users.end())cout<<"DOCUMENTO YA EXISTENTE EN EL SISTEMA"<<endl;}
    cout<<"Ingrese su contrasena: "<<endl;
    cin>>clave;
    system("cls");
    cout<<"Bienvenido a nuestro CINE!! "<<endl<<endl<<endl;
    datos=datos + '\n' + usuario + ';' + clave;
    escribir_txt(datos,"users.txt");
}

void c_usuarios(map <string,string> &usu){
// Extrae los usuarios y claves de otro .txt y los pone en un map
    map <string,string>::iterator is;
    string tempc,temp="",datos=leer_Txt("users.txt");
    for(unsigned int i=0;i<datos.length();i++){
        if(datos[i]==';'){
            tempc=temp;
            temp="";}
        else if(datos[i]=='\n' || i+1==datos.length()){
            if(i+1==datos.length()) temp.push_back(datos[i]);
            if(temp[temp.length()-1]=='\r')
                temp.pop_back();
            usu.insert(pair<string,string>(tempc,temp));
            temp="";
        }
        else
            temp.push_back(datos[i]);
    }
}
void g_inventario(){

}


void g_combos(){

}
