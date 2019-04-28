#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "empleados.h"
#include "ordenamiento.h"
void ordenarEmpleadosApellido(eEmpleados arrayEmpleados[],int cantidadElementos,eEmpleados auxiliarEmpleados)
{
    int i,j;

    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(arrayEmpleados[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(arrayEmpleados[j].legajo == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayEmpleados[i].apellido,arrayEmpleados[j].apellido) > 0)
                        {
                            auxiliarEmpleados = arrayEmpleados[j];
                            arrayEmpleados[j] = arrayEmpleados[i];
                            arrayEmpleados[i] = auxiliarEmpleados;
                        }
                    }
                }
}
