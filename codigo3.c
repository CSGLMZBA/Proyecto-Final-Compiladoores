int printf();
int main() 
{
    int c='';
    printf(" Menu:");
    printf(" A=Añadir a la lista");
    printf(" B=Borrar de la lista");
    printf(" O=Ordenar la lista");
    printf(" I=Imprimir la lista");
    printf(" Escriba su selección y luego <enter>");
    if (c!= '') {
        if (c=='A') printf(" Has seleccionado añadir");
        else if (c=='B') printf(" Has seleccionado borrar");
        else if (c=='O') printf(" Has seleccionado ordenar");
        else if (c=='I') printf(" Has seleccionado imprimir");
    } else printf(" No has seleccionado nada");
        return 0;
}