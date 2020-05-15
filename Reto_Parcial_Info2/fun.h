#include "cmb.h"

string leer_Txt(string arch);
void escribir_txt(string texto,string arch);
string des();
void text2bin(string texto,bool *cod);
string bin2text(bool *cod,unsigned long long int l);
void separacion(unsigned long long int semilla, bool *cod, unsigned long long int tam,bool dec);
unsigned short regla_1(short *seg,bool *data,unsigned short regla, unsigned long long semilla,bool dec);
long int str2int(string a);


void a_productos(map <int,producto> &inv);
void ini_administrador(map <int,producto> &inv,map <int,combo> &com);
void administrador(map <int,producto> &inv,map <int,combo> &com);
void d_inventario(map <int,producto> &inv);
void d_combos(map <int,combo> &com);
void ingresar_usu();
void registrar_usuario();
void g_inventario(map <int,producto> &inv);
void g_combos(map <int,combo> &inv);
void usu();
void c_usuarios(map <string,string> &usu);
void m_inventario(map <int,producto> inv);
void m_combos(map <int,combo> com,map <int,producto> inv);
void c_combo(map <int,combo> &com,map <int,producto> inv);
void m_inventario();
void a_productos();
