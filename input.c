int getString(char *msg,
              char *msgError,
              int minimo,
              int maximo,
              int reintentos,
              char *resultado)
{

    int retorno = -1;
    char buffer[4096];
    if(msg != NULL &&
       msgError != NULL &&
       minimo<maximo &&
       reintentos >= 0&&
       resultado != NULL)
        {
            do
            {
                printf("%s",msg);
                fflush(stdin);
                fgets(buffer,sizeof(buffer),stdin);
                buffer[strlen(buffer)-1] = '\0';
                if(strlen(buffer)>= minimo && strlen(buffer) <= maximo)
                {
                    strncpy(resultado,buffer,maximo);
                    retorno = 0;
                    break;
                }
                reintentos--;
                printf("%s",msgError);
            }while(reintentos >= 0);
        }
        return retorno;
}

int getName(char *msg,
            char *msgError,
            int minimo,
            int maximo,
            int reintentos,
            char *resultado)
{
    char buffer[4096];
    int retorno = -1;
    if(msg != NULL &&
       msgError != NULL &&
       minimo<maximo &&
       reintentos >= 0&&
       resultado != NULL)
    {
        do {
            if(!getString(msg,msgError,minimo,maximo,reintentos,buffer))
                {
                    if(isValidName(buffer))
                    {
                        strlwr(buffer);
                        buffer[0] = toupper(buffer[0]);
                        strncpy(resultado,buffer,maximo);
                        retorno = 0;
                    }
                    else
                    {
                        printf(msgError);
                    }
                }
            }while(retorno!=0);
    }
    return retorno;
}

int isValidName(char str[])
{

    int retorno = TRUE;
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] != ' ' && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return FALSE;
        }
        i++;
    }
    return retorno;

}

int getNumber(char *msg,char *msgError,int desde,int hasta,int minimo,int maximo,int reintentos,char *resultado)
{
    int retorno = -1;
    char buffer[4096];
    int bufferInt;
    if(msg != NULL &&
       msgError != NULL &&
       desde < hasta &&
       minimo < maximo &&
       reintentos >= 0 &&
       resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,buffer))
        {
           if(isValidNumber(buffer))
           {
              bufferInt = atoi(buffer);
              if(isValidRange(desde,hasta,bufferInt))
              {
                 strncpy(resultado,buffer,maximo);
                 retorno = 0;
              }

           }
        }
    }
    return retorno;

}

int isValidNumber(char strNumber[])
{
    int retorno = TRUE;
    int i = 0;
    while(strNumber[i] != '\0')
    {
        if(strNumber[i] < '0' || strNumber[i] > '9')
        {
            retorno = FALSE;
        }
        i++;
    }
    return retorno;
}

int isValidRange(int desde,int hasta,int numero)
{
    if(numero >= desde && numero <= hasta)
    {
        return TRUE;
    }
    return FALSE;

}
