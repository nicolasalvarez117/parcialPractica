int buscarPrimerOcurrencia(ePersonas arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(arrayPersonas[i].estado == valor)
        {
            return i;
            break;
        }
    }
    return -1;
}

void inicializarArrayPersonas(ePersonas arrayPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        arrayPersonas[i].estado = valor;
    }
}

void cargarPersona(ePersonas arrayPersonas[],int cantidadPersonas,int valorOcupado,int maxCaracter)
{
    int i;
    char auxLegajo[20];

    i = buscarPrimerOcurrencia(arrayPersonas,cantidadPersonas,valorOcupado);
    if(i!=-1)
    {
        getName("Ingrese Nombre: ","\ncaracter incorrecto\n",1,maxCaracter,3,arrayPersonas[i].nombre);
        getName("Ingrese Apellido: ","\ncaracter incorrecto\n",1,maxCaracter,3,arrayPersonas[i].apellido);
        getNumber("ingrese legajo","caracter incorrecto",1,5,1,10,3,auxLegajo);
        //printf("ingrese legajo: ");
        //scanf("%s",auxLegajo);
        arrayPersonas[i].legajo = atoi(auxLegajo);
        arrayPersonas[i].estado = OCUPADO;
        //ingresas mas datos a guardar

    }
    else
    {
        printf("\nNo hay espacio\n");
    }
}
/*void mostrarPersona(ePersonas arrayPersonas,int posicion)
{
    printf("%s %s",arrayPersonas[posicion].nombre,arrayPersonas[posicion].apellido);
    //agregar mas datos
}*/

void mostrarListaPersonas(ePersonas arrayPersonas[], int cantidadElementos,int valorOcupado)
{
    int i;
    for(i=0; i<cantidadElementos; i++)
    {
        if(arrayPersonas[i].estado!=valorOcupado)
        {
            //mostrarPersona(arrayPersonas,i);
        }

    }
}


void hardcodearDatosPersonas(ePersonas arrayPersonas[], int cantidadElementos)
{
    int i;
    int legajos[]={1,2,3,4,5};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo"};
    char sexo[]={'F','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000};

    for(i=0; i<cantidadElementos; i++)
    {
        //cargar los datos en la estructura

    }
}

void borrarPersona(ePersonas arrayPersonas[], int cantidadElementos,int maxCaracter)
{

    int i;
    int loEncontro = FALSE;
    char auxLegajo[maxCaracter];
    int legajo;
    getNumber("Ingrese el legajo a dar de baja: ","caracter incorrecto",1,cantidadElementos,1,maxCaracter,3,auxLegajo);
    legajo = atoi(auxLegajo);
    for(i=0; i<cantidadElementos; i++)
    {
        if(legajo == arrayPersonas[i].legajo)
        {

            arrayPersonas[i].estado = LIBRE;
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
