#include "cmb.h"

string leer_Txt(string arch);
void escribir_txt(string texto,string arch);
string des();
void text2bin(string texto,bool *cod);
string bin2text(bool *cod,unsigned long long int l);
void separacion(unsigned long long int semilla, bool *cod, unsigned long long int tam,bool dec);
unsigned short regla_1(short *seg,bool *data,unsigned short regla, unsigned long long semilla,bool dec);


void ini_administrador(map <int,producto> &inv,map <int,combo> &com);
void administrador(map <int,producto> &inv,map <int,combo> &com);
void d_inventario();
void d_combos();
void ingresar_usu();
void registrar_usuario();
void g_inventario();
void g_combos();
void usu();
void c_usuarios(map <string,string> &usu);
void m_inventario();
void m_combos();
void c_combo();
void m_inventario();
void a_productos();
