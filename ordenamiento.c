void ordenarPersonasApellido(ePersonas arrayPersonas[],int cantidadElementos,ePersonas auxiliarPersonas)
{
    int i,j;

    for(i=0; i < cantidadElementos - 1; i++)
                {
                    if(arrayPersonas[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j < cantidadElementos; j++)
                    {
                        if(arrayPersonas[j].legajo == -1)
                        {
                            continue;
                        }
                        if(strcmp(arrayPersonas[i].apellido,arrayPersonas[j].apellido) > 0)
                        {
                            auxiliarPersonas = arrayPersonas[j];
                            arrayPersonas[j] = arrayPersonas[i];
                            arrayPersonas[i] = auxiliarPersonas;
                        }
                    }
                }
}
