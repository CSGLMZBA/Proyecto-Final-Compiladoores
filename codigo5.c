int printf();
int main()
{
    char seleccion;
    do{
        printf("1.- Comenzar\n");
        printf("2.- Abrir\n");
        printf("3.- Grabar\n");
        printf("4.- Salir\n");
        printf("Escoge una opción: ");
        seleccion=4;
        switch(seleccion){
        case '1':printf("Opción 1");
        break;
        case '2':printf("Opción 2");
        break;
        case '3':printf("Opción 3");
        }
    }while(seleccion!='4');
    return 0;
}