#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "empleados.h"
#include "ordenamiento.h"

#define QTY_EMPLEADOS 10
#define QTY_MENUES 5
#define QTY_SECTORES 5

int main()
{

    eEmpleados arrayEmpleados[QTY_EMPLEADOS];
    eEmpleados auxEmpleados;
    eMenues arrayMenues[QTY_MENUES];
    eSector arraySector[QTY_SECTORES];
    int i;
    char auxLegajoModificar[10];
    int opcion = 0;
    int auxLegajo = 6;
    char arrayAuxiliar[10];
    inicializarArrayEmpleados(arrayEmpleados,QTY_EMPLEADOS);

    hardcodearDatosMenues(arrayMenues,QTY_MENUES);
    hardcodearDatosSector(arraySector,QTY_SECTORES);
    hardcodearDatosEmpleados(arrayEmpleados);

    do
    {
        printf("----------------------ingrese la opcion-----------------------\n\n");
        opcion = menu("1:ALTA\n2:BAJA\n3:MODIFICAR\n4:LISTA ORDENADA\n5:MENUES\n6:SALIR: ","caracter incorrecto",1,6,1,2);

        switch(opcion)
        {
        case 1:
            cargarEmpleado(arrayEmpleados,arraySector,arrayMenues,QTY_EMPLEADOS,-1,51,auxLegajo);
            break;
        case 2:
            mostrarListaEmpleados(arrayEmpleados,arraySector,QTY_EMPLEADOS,-1);
            borrarEmpleado(arrayEmpleados,QTY_EMPLEADOS);
            break;
        case 3:
            mostrarListaEmpleados(arrayEmpleados,arraySector,QTY_EMPLEADOS,-1);
            //getNumber("ingrese legajo a modificar: ","caracter incorrecto",1,QTY_EMPLEADOS,1,5,3,auxLegajoModificar);
            //i = buscarPrimerOcurrencia(arrayEmpleados,QTY_EMPLEADOS,atoi(auxLegajoModificar));
            //if(i == -1)
            //{
                //printf("legajo no existe");
                //break;
            //}
            do
            {
                opcion = menu("Modificar:\n1:Nombre\n2:Apellido\n3:Salario\n4:Sector\n5:Salir\n","caracter incorrecto",1,5,1,2);
                switch(opcion)
                    {
                    case 1:
                        modificarEmpleado(arrayEmpleados,arraySector,QTY_EMPLEADOS,opcion);
                        break;
                    case 2:
                        getName("ingrese el nuevo apellido: ","caracter incorrecto",1,52,3,arrayEmpleados[i].apellido);
                        break;
                    case 3:
                        getNumber("ingrese el nuevo salario: ","caracter incorrecto",1,100000,1,7,3,auxLegajoModificar);
                        arrayEmpleados[i].sueldoBruto = atof(auxLegajoModificar);
                        break;
                    case 4:
                        getNumber("ingrese el nuevo sector: ","caracter incorrecto",1,QTY_SECTORES,1,QTY_SECTORES,3,auxLegajoModificar);
                        arrayEmpleados[i].idSector = atof(auxLegajoModificar);
                        break;
                    }
            }while(opcion != 5);




        }
    }while(opcion != 6);





}
