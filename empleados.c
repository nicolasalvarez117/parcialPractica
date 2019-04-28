#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "empleados.h"
#include "ordenamiento.h"

#define OCUPADO 1
#define LIBRE -1

#define FALSE 0
#define TRUE 1

#define QTY_EMPLEADOS 10
#define QTY_MENUES 5
#define QTY_SECTORES 5

int buscarPrimerOcurrencia(eEmpleados arrayEmpleados[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayEmpleados[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

void inicializarArrayEmpleados(eEmpleados arrayEmpleados[],int cantidadDeElementos)
{
    int i;
    for(i=0;i<cantidadDeElementos;i++)
    {
        arrayEmpleados[i].estado = LIBRE;
    }
}

void cargarEmpleado(eEmpleados arrayEmpleados[],eSector arraySector[],eMenues arrayMenues[],int cantidadEmpleados,int valorOcupado,int maxCaracter,int *auxLegajo)
{
    int i,j;
    char auxNacionalidad[10];
    char auxSexo;
    int flag = 0;
    char auxDia[10];
    char auxMes[10];
    char auxAnio[10];
    char auxSalario[20];
    char auxSector[10];
    i = buscarPrimerOcurrencia(arrayEmpleados,cantidadEmpleados,valorOcupado);
    if(i!=-1)
    {
        getName("Ingrese Nombre: ","\ncaracter incorrecto\n",1,maxCaracter,3,arrayEmpleados[i].nombre);
        getName("Ingrese Apellido: ","\ncaracter incorrecto\n",1,maxCaracter,3,arrayEmpleados[i].apellido);
        getSexo("Ingrese el sexo M o F: ","sexo incorrecto\n",&auxSexo);
        getNumber("ingrese el salario: ","caracter incorrecto",1,100000,1,15,3,auxSalario);
        getNumber("fecha de ingreso\nDia: ","caracter incorrecto",1,31,1,3,3,auxDia);
        getNumber("\nMes: ","caracter incorrecto",1,12,1,3,3,auxMes);
        getNumber("\nAño: ","caracter incorrecto",1930,2019,1,5,3,auxAnio);
        mostrarSectores(arraySector,QTY_SECTORES);
        getNumber("sector en el que trabaja: ","caracter incorrecto",1,5,1,2,3,auxSector);

        arrayEmpleados[i].sexoEmpleado = auxSexo;
        arrayEmpleados[i].idSector = atoi(auxSector);
        arrayEmpleados[i].t_Fecha.dia = atoi(auxDia);
        arrayEmpleados[i].t_Fecha.mes = atoi(auxMes);
        arrayEmpleados[i].t_Fecha.anio = atoi(auxAnio);
        arrayEmpleados[i].sueldoBruto = atof(auxSalario);
        arrayEmpleados[i].legajo = auxLegajo;
        auxLegajo = auxLegajo + 1;
        arrayEmpleados[i].estado = OCUPADO;

        system("cls");
        printf("\nAlta exitosa");

    }
    else
    {
        printf("\nNo hay espacio\n");
    }
}
void mostrarMenues(eMenues arrayMenues[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf("%d %s %d",arrayMenues[i].id,arrayMenues[i].descripcion,arrayMenues[i].precioMenu);
    }
}

void mostrarSectores(eSector arraySector[],int cantidad)
{
    int i;
    for(i=0;i<cantidad;i++)
    {
        printf("%d %s \n",arraySector[i].idSector,arraySector[i].descripcion);
    }
}

void mostrarListaEmpleados(eEmpleados arrayEmpleados[],eSector arraySector[], int cantidadElementos,int valorOcupado)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(arrayEmpleados[i].estado == 1)
        {
            printf("legajo: %d %s %s %c",arrayEmpleados[i].legajo,arrayEmpleados[i].nombre,arrayEmpleados[i].apellido,arrayEmpleados[i].sexoEmpleado);
            printf(" %.2f %s\n",arrayEmpleados[i].sueldoBruto,arraySector[arrayEmpleados[i].idSector-1].descripcion);

        }

    }
}


void hardcodearDatosEmpleados(eEmpleados arrayEmpleados[])
{
    int i;
    int legajos[]={1,2,3,4,5};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo"};
    char apellidos[][50] ={"gonzales","alvarez","rodriguez","avila","urti"};
    char sexo[]={'F','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000};
    int estado[5] = {1,1,1,1,1};

    int sector[] = {2,2,1,3,4};

    for(i=0; i<5; i++)
    {
        arrayEmpleados[i].legajo = legajos[i];
        arrayEmpleados[i].sexoEmpleado = sexo[i];
        arrayEmpleados[i].sueldoBruto = sueldosBruto[i];
        arrayEmpleados[i].estado = estado[i];
        arrayEmpleados[i].idSector = sector[i];
        strncpy(arrayEmpleados[i].nombre,nombres[i],50);
        strncpy(arrayEmpleados[i].apellido,apellidos[i],50);
    }
}

void borrarEmpleado(eEmpleados arrayEmpleados[], int cantidadElementos)
{

    int i;
    int loEncontro = FALSE;
    char auxLegajo[20];
    int legajo;
    getNumber("Ingrese el legajo a dar de baja: ","caracter incorrecto",1,cantidadElementos,1,5,3,auxLegajo);
    legajo = atoi(auxLegajo);
    for(i=0; i<cantidadElementos; i++)
    {
        if(legajo == arrayEmpleados[i].legajo)
        {

            arrayEmpleados[i].estado = LIBRE;
            printf("Baja exitosa");

            loEncontro = TRUE;
            break;//modifcar
        }

    }

    if(loEncontro==FALSE)
    {
        printf("El dato no existe");
    }

}

void ingresarOpcion(int *x,char *msg,char *msgError,int desde,int hasta,int minCaracter,int maxCaracter)
{
  char auxOpcion[10];
  printf("----------------------ingrese la opcion-----------------------\n\n");
  getNumber(msg,msgError,desde,hasta,minCaracter,maxCaracter,3,auxOpcion);
  x = atoi(auxOpcion);
}

void hardcodearDatosMenues(eMenues arrayMenues[], int cantidadElementos)
{
    int i;
    int id[]={1,2,3,4,5};
    char nombres[][50]={"Milanesa","Sopa","Pizza","Pescado","Asado"};

    int precio[]={200,90,150,250,300};

    for(i=0; i<cantidadElementos; i++)
    {
        arrayMenues[i].id = id[i];
        strcpy(arrayMenues[i].descripcion,nombres[i]);
        arrayMenues[i].precioMenu = precio[i];

    }
}

void hardcodearDatosSector(eSector arraySector[], int cantidadElementos)
{
    int i;
    int id[]={1,2,3,4,5};
    char nombres[][50]={"Contabilidad","RRHH","Ventas","Administracion","Limpieza"};

    for(i=0; i<cantidadElementos; i++)
    {
        arraySector[i].idSector = id[i];
        strcpy(arraySector[i].descripcion,nombres[i]);
    }
}

int menu(char *msg,char *msgError,int desde,int hasta,int minCaracter,int maxCaracter)
{
    int i;
    char opcion[20];

    getNumber(msg,msgError,desde,hasta,minCaracter,maxCaracter,3,opcion);
    i = atoi(opcion);

    return i;
}

void modificarEmpleado(eEmpleados arrayEmpleados[],eSector arraySector[], int cantidadElementos,int opcion)
{

    int i;
    int loEncontro = FALSE;
    char auxLegajo[20];
    int legajo;
    getNumber("Ingrese el legajo a modificar: ","caracter incorrecto",1,cantidadElementos,1,5,3,auxLegajo);
    legajo = atoi(auxLegajo);
    for(i=0; i<cantidadElementos; i++)
    {
        if(legajo == arrayEmpleados[i].legajo)
        {

            switch(opcion)
            {
            case 1:
                getName("ingrese nuevo nombre: ","caracter incorrecto",1,51,3,arrayEmpleados[i].nombre);
                break;
            }

            loEncontro = TRUE;
            break;//modifcar
        }

    }
}





















