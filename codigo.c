/* C program to print a sentence. */
int r;
int h[2];
int printf();
int i;
float myfunc(int a, int b)
{
	return a*b;
}
int main()
{
	double x = 0.1;
	float y = 1.5/3;
	int z = 3+2;
	r = x-3*4/2;
	y *= 2.5;
	if(r>3)
		printf("C Programing // %d\n", 5); /* printf() prints the content inside quotation */
	else
		printf("C Programing // %d\n", 5);
	
	for(i=0; i<5; i++)
	{
		printf("%d\n",i);
	}
	z= myfunc(h[1], 5);
	return 0;
}