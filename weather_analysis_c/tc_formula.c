//Tanzim Mokammel
//July 13, 2009
//mtanzim@hotmail.com
//program to calculate PE with Turc's formula
//short term formula for PE over 10 days

# include <stdio.h>
# include <string.h>
# include <math.h>

int main (){
	
	//variables for calculations
	double P; //precipitation in a 10 day period in mm
	double a; //estimated evaporation in 10 day period from bare soil unaffected by precipitation in mm
	
	double T; //mean air temperature over 10 days in C
	double Qs; //short wave radiation in (cal*cm^-2*day^-1)
	double L; //evaporation capacity (to be calculated from T and Qs)

	double PE; //potential evapotranspiration (final answer)

	//variables for user I/O
	const int MAX_LINE = 256;
	char buffer[MAX_LINE];
	char *temp;

///////////////////////// GET ALL NECESSARY VARIABLES  

	//get P (precipitation in a 10 day period in mm)
	printf ("Please enter P (precipitation in a 10 day period in mm):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &P) == 1 )
	{
		printf("P = %lf\n", P);
	
	}


	//get a (estimated evaporation)
	printf ("Please enter a (estimated evaporation from bare soil in mm):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &a) == 1 )
	{
		printf("a = %lf\n", a);
	
	}


	//get T (estimated evaporation)
	printf ("Please enter T (mean air temperature in C):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &T) == 1 )
	{
		printf("T = %lf\n", T);
	
	}

	//get Qs (short wave radiation)
	printf ("Please enter Qs (short wave radiation in cal*cm^-2*day^-1):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &Qs) == 1 )
	{
		printf("Qs = %lf\n", Qs);
	
	}

	//reassure user with entered values
	//printf ("Values entered respectively were: %lf,%lf,%lf,%lf\n",P,a,T,Qs);

///////////////////// Calculate L

	L = ((T+2)*pow(Qs, 0.5)) / 16;	
	printf ("\nL  = %lf\n",L);

//////////////////// Calculate PE

	PE = (P+a+70) / ( pow ((1 + (pow((2*P+2*a+70)/(2*L), 2))),0.5) );
	
	printf ("PE = %lf\n",PE);
	
	return 0;

}
	
	


	
	

	
