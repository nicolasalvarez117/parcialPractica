#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;


typedef struct
{
  int idMenu;
  int legajoEmpleado;
}eEmpleado_Menu;


typedef struct
{
  int idSector;
  int legajoEmpleado;
}eEmpleado_Sector;

typedef struct
{
  int idSector;
  char descripcion[20];
}eSector;

typedef struct
{
    int id;
    int empleadoLegajo;
    int precioMenu;
    char descripcion[50];

}eMenues;

typedef struct
{
    char nombre[50];
    char apellido[50];
    int edad;
    int legajo;
    float sueldoBruto;
    int fechaIngreso;
    int idSector;
    char sexoEmpleado;
    int estado;

    eFecha t_Fecha;

}eEmpleados;



int menu(char *msg,char *msgError,int desde,int hasta,int minCaracter,int maxCaracter);


int buscarPrimerOcurrencia(eEmpleados arrayEmpleados[],int cantidadDeElementos,int valor);
void inicializarArrayEmpleados(eEmpleados arrayEmpleados[],int cantidadDeElementos);
void cargarEmpleado(eEmpleados arrayEmpleados[],eSector arraySector[],eMenues arrayMenues[],int cantidadEmpleados,int valorOcupado,int maxCaracter,int *auxLegajo);
void mostrarListaEmpleados(eEmpleados arrayEmpleados[],eSector arraySector[], int cantidadElementos,int valorOcupado);
void hardcodearDatosEmpleados(eEmpleados arrayEmpleados[]);
void borrarEmpleado(eEmpleados arrayEmpleados[], int cantidadElementos);
void ingresarOpcion(int *x,char *msg,char *msgError,int desde,int hasta,int minCaracter,int maxCaracter);
void hardcodearDatosMenues(eMenues arrayMenues[], int cantidadElementos);
void hardcodearDatosSector(eSector arraySector[], int cantidadElementos);

void mostrarMenues(eMenues arrayMenues[],int cantidad);
void mostrarSectores(eSector arraySector[],int cantidad);

void modificarEmpleado(eEmpleados arrayEmpleados[],eSector arraySector[], int cantidadElementos,int opcion);


