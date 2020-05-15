#include "fun.h"

string des(){ //Esta funcion sirve para decodificar la clave del admin. para asi comprobarla con la ingresada (S=4, M=1)
    string texto;
    texto=leer_Txt("password.dat");
    bool *cod= new bool [8*(texto.length())];
    text2bin(texto,cod);
    separacion(4,cod,8*(texto.length()),0);
    texto=bin2text(cod,8*(texto.length()));
    return texto;
}

void text2bin(string texto,bool *cod){ //String a binario y despues a char
    char s;
    for(unsigned long long int i=0;i<(texto.length());i++){
        s=char(texto[i]);
        for(int j=0;j<8;j++) cod[8*i+j]=(((s<<j)&0x80)==0x80);
    }
}
long int str2int(string a){  //String a entero
    int b,l,d=1,c=0;
    l=a.length();
    for(int i=l-1;i>=0;i--){
        b=a[i]-48;
        c+=b*d;
        d*=10;
    }
    return c;
}
string bin2text(bool *cod,unsigned long long int l){ //array binario a string
    string text="";
    string s;
    int sum=0,c=0;
    for(unsigned long long int i=0;i<l;i+=8){
        c=0;
        sum=0;
        for(int j=7;j>=0;j--){
            sum+=cod[i+j]*pow(2,c);
            c++;
        }
        s=sum;
        text.append(s);
    }
    return text;
}
void separacion(unsigned long long int semilla, bool *cod, unsigned long long int tam,bool dec){ //Corta el array en segmentos dependiendo la semilla para asi convertirlos despues
    short *seg = new short[semilla];
    long long int j=0;
    unsigned short tp=0;
    for(unsigned long long int i=0;i<semilla;i++) seg[i]=-1;
    for(unsigned long long int i=0,l=0; i<tam; i++,j++){
        seg[j]=cod[i];
        if((i+1)%semilla==0 || i==(tam-1)){
            tp=regla_1(seg,&cod[semilla*l],tp,semilla,dec);
            for(unsigned long long int k=0;k<semilla;k++) seg[k]=-1;
            l++;
            j=-1;
        }
    }
}

unsigned short regla_1(short *seg, bool *data, unsigned short regla, unsigned long long int semilla,bool dec){ //Metodo 1 de decodificacion
    int contador[2]={0,0};
    unsigned short reg=0;
    for(unsigned long long int i=0; i<semilla; i++){
        if(seg[i]!=-1){
            switch (regla){
                case 0: data[i]=1-seg[i];

                break;

                case 1: if(i%2!=0) data[i]=1-seg[i];

                break;

                default: if((i+1)%3==0) data[i]=1-seg[i];
            }
          if(dec) contador[seg[i]]++;
          else contador[data[i]]++;
        }
    }
    if(contador[0]>contador[1]) reg=1;
    else if(contador[0]<contador[1]) reg=2;
    return reg;
}
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
void d_inventario(map <int,producto> &inv){
// Extraer datos del inventario e incluir en un mapa
    string temp="",name,datos=leer_Txt("inventario.txt");
    int id,j;
    int long long temp_int[4];
    producto a;
    for(unsigned long int i=0;i<datos.length();i++){
        j=0;
        while(i<datos.length()){
            if(datos[i]==';' || datos[i]=='\n' || i+1==datos.length()){
                if(i+1==datos.length()) temp.push_back(datos[i]);
                if(j==0){
                    inv.insert(pair<int,producto>(str2int(temp),a));
                    id=str2int(temp);}
                else if(j==1)
                    name=temp;
                else if(j==2)
                    temp_int[0]=str2int(temp);
                else if(j==3)
                    temp_int[1]=str2int(temp);
                else if(j==4)
                    temp_int[2]=str2int(temp);
                else if(j==5)
                    temp_int[3]=str2int(temp);
                temp="";
                if(datos[i]=='\n') break;
                j++;
            }
            else
                temp.push_back(datos[i]);
            i++;
        }
        inv[id].create(name,temp_int[0],temp_int[1],temp_int[2],temp_int[3]);
    }
}

void d_combos(map <int,combo> &com){
// Extrae la informacion de otro .txt y se pone en un map

    map <int,int> ff;
    map <int,int>::iterator it;
    string temp="",name,datos=leer_Txt("combos.txt");
    combo a;
    int j,num,cont[2];
    long long int costo;
    for(unsigned long int i=0;i<datos.length();i++){
        j=0;
        while(i<datos.length()){
            if(datos[i]==';' || datos[i]=='\n' || i+1==datos.length()){
                if(i+1==datos.length()) temp.push_back(datos[i]);
                if(j==0){
                    com.insert(pair<int,combo>(str2int(temp),a));
                    num=str2int(temp);}
                else if(j==1)
                    name=temp;
                else if(j==2)
                    costo=str2int(temp);
                else{
                    cont[1]=str2int(temp);
                    ff.insert(pair<int,int>(cont[0],cont[1]));
                }
                temp="";
                if(datos[i]=='\n') break;
                j++;
            }
            else if (datos[i]=='-'){
                cont[0]=str2int(temp);
                temp="";
            }
            else
                temp.push_back(datos[i]);
            i++;
        }
        com[num].ini(name,costo,ff);
        while(ff.size()!=0){
            it=ff.begin();
            ff.erase(it->first);}
    }
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
void ini_administrador(map <int,producto> &inv,map <int,combo> &com){
    //Clave y comparacion
    //Parametros: maps que contiene el inventario y  los combos para pasarselos a la funcion administrador
    system("cls");
    string clave;
    cout<<"Ingrese la clave de administrador: "<<endl;
    cin>>clave;
    if(clave!=des()){
        cout<<"CLAVE INCORRECTA"<<endl;
        return;}
    else{
        cout<<"ACCESO CONCEDIDO"<<endl;
        system("pause");
        system("cls");
        administrador(inv,com);}
}
void administrador(map <int,producto> &inv,map <int,combo> &com){
//Funcion que muestra el menu y las funciones del administrador
//Parametros: Maps que contiene el inventario y  los  combos para modificarlos
    short opcion;
    int el, temp;
    cout<<"INVENTARIO ACTUAL"<<endl<<endl;
    m_inventario(inv);
    while(true){
        cout<<"Ingrese la opcion que desee: "<<endl,
        cout<<"1)Mostrar los combos del momento"<<endl<<"2)Crear un nuevo combo"<<endl<<"3)Quitar un combo"<<endl<<"4)Mostrar inventario"<<endl;
        cout<<"5)Ingresar un nuevo producto para el inventario"<<endl<<"6)Quitar un producto del inventario"<<endl<<"7)Abastecer un producto del inventario"<<endl<<"8)Reporte de ventas"<<endl<<"0)SALIR"<<endl;
        cin>>opcion;
        system("cls");
        switch(opcion){
        case 1:
            system("cls");
            m_combos(com,inv);

            break;

        case 2:
            system("cls");
            c_combo(com,inv);


            break;
        case 3:

            system("cls");
            cout<<"Ingrese el N del combo a eliminar: "<<endl;
            cin>>el;
            if(com.find(el)==com.end())
                cout<<"El N que ingreso no existe en los combos actuales"<<endl;
            else com.erase(el);
            break;

        case 4:
            system("cls");
            m_inventario(inv);

            break;
        case 5:

            system("cls");
            m_inventario(inv);

            a_productos(inv);

            system("cls");
            break;




        case 6:
            system("cls");
            cout<<"Ingrese el N del producto del inventario para eliminar: "<<endl;
            cin>>el;
            if(inv.find(el)==inv.end())
                cout<<endl<<"N no disponible en el inventario"<<endl;
            else inv.erase(el);

            break;


        case 7:
            system("cls");
            m_inventario(inv);
            cout<<endl<<"Ingrese el N del producto del inventario para abastecer: "<<endl;
            cin>>el;
            if(inv.find(el)==inv.end())
                cout<<endl<<"El N no se encuentra en el inventario"<<endl;
            else{
                cout<<endl<<"Ingrese la cantidad que llego del producto para abastecerlo"<<endl;
                cin>>temp;
                inv[el].anadir_cant(temp);}


        case 8:
            cout<<leer_Txt("reporte.txt");
            break;
        case 0:
            return;
        default:
            cout<<endl<<"OPCION INVALIDA"<<endl;
            break;
        }
        system("pause");
        system("cls");
    }
}
void a_productos(map <int,producto> &inv){
//Recibe map con inventario para poder añadir productos
    int unid[2],id=(inv.begin())->first;
    producto a;
    string nombre;
    long long int costo;
    while(inv.find(id)!=inv.end()){
        cout<<"Ingrese el N del nuevo producto (No ingrese un N existente): "<<endl;
        cin>>id;
        if(inv.find(id)!=inv.end()) cout<<endl<<"N EXISTENTE"<<endl;}
    cout<<"Ingrese el nombre del producto (De la forma xxx_xx_xx: "<<endl;
    cin>>nombre;
    cout<<"Ingrese la cantidad de unidades que viene en cada producto: "<<endl;
    cin>>unid[0];
    cout<<"Ingrese la cantidad del producto: "<<endl;
    cin>>unid[1];
    cout<<"Ingrese el precio del producto: "<<endl;
    cin>>costo;
    a.create(nombre,unid[0],unid[0],unid[1],costo);
    inv.insert(pair<int,producto>(id,a));
}
void m_inventario(map <int,producto> inv){
//Recibe map con inventario para imprimirlo
    map <int,producto>::iterator ii;
    cout<<"|N |                     Producto                |cantidad|costo |"<<endl;
    for(int i=0;i<65;i++) cout<<' ';
    cout<<endl;
    for(ii=inv.begin();ii!=inv.end();ii++){
        if(ii->first<10)
            cout<<"| "<<ii->first;
        else
            cout<<'|'<<ii->first;
        ii->second.v_produc();
        cout<<endl;
        for(int i=0;i<65;i++) cout<<' ';
        cout<<endl;
    }
}
template <typename t>
string int2str(t a){ //Entero a string
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
void g_inventario(map <int,producto> &inv){
    //Recibe map que contiene el inventario para ponerlo en un .txt
    string datos;
    map <int,producto>::iterator j;
    for(j=inv.begin();j!=inv.end();j++){
        datos= datos + int2str(j->first) + ';' + j->second.guardado() + '\n';
    }
    datos.pop_back();
    escribir_txt(datos,"inventario.txt");
}

void g_combos(map <int,combo> &inv){
    //Recibe map que contiene los combos para ponerlo en un .txt
    string datos;
    map <int,combo>::iterator j;
    for(j=inv.begin();j!=inv.end();j++){
        datos= datos + int2str(j->first) + ';' + j->second.guardado() + '\n';
    }
    datos.pop_back();
    escribir_txt(datos,"combos.txt");
}
void a_productos(){

}
void m_combos(map <int,combo> com,map <int,producto> inv){
//Recibe el map que contiene a los combos y los imprime en una tabla dependiendo si estan o no disponibles

    system("cls");
    map <int,combo>::iterator ic;
    for(int i=0;i<62;i++) cout<<' ';
    cout<<endl;
    for(ic=com.begin();ic!=com.end();ic++){
        if(ic->first<10)
            cout<<"| "<<ic->first;
        else
            cout<<'|'<<ic->first;
        cout<<ic->second.v_combo();
        if(!(ic->second.disp(inv))) cout<<"producto no disponible por el momento";
        cout<<endl;
        for(int i=0;i<62;i++) cout<<' ';
        cout<<endl;
    }
}
void c_combo(map <int,combo> &com,map <int,producto> inv){
// Parametro: map de combos y el map con el inventario,
// Crear combos dependiendo del inventario
    cout<<endl<<"COMBOS ACTUALES"<<endl;
    m_combos(com,inv);
    int num=(com.begin())->first;
    while(com.find(num)!=com.end()){
        cout<<"Ingrese el N del combo: "<<endl;
        cin>>num;
        if(com.find(num)!=com.end()) cout<<"N existente"<<endl;
    }
    combo b;
    cout<<"Inventario actual para abastecer el combo"<<endl;
    m_inventario(inv);
    b.create(inv);
    com.insert(pair<int,combo>(num,b));
}
