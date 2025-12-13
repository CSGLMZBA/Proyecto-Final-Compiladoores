int printf();
int main()
{
    char palabra[50];
    int f;
    int vocales=0;
    int consonantes=0;
    printf("Palabra:");
    for(f=0;f<50;f++)
    {
        switch (palabra[f]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':vocales++;
                     break;
            default: consonantes++;
        }
    }
    printf("La cantidad de vocales que tiene la palabra son:%i\n",vocales);
    printf("La cantidad de consonantes que tiene la palabra son:%i",consonantes);
    return 0;
}