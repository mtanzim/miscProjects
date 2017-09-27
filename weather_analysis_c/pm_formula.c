//Tanzim Mokammel
//June 9, 2009
//mtanzim@hotmail.com
//program to calculate PE with Penman equation

# include <stdio.h>
# include <string.h>
# include <math.h>

int main (){

	//variables for calculations
	double big_delta; //slope of saturation vapur in mb/C
	const double GAMMA = 0.65; // hygrometric constant in mb/C
	double Ql; //long wave radiation
	const double R = 0.25; //coefficient relating to vegetation (for short grass)
	double Ta; //air temp in C
	double nbyN; //actual/possible sunshine hours
	double rho; //density of water in kg/m^3
	double lambda; //latent heat of vaporization
	const double SIGMA = 5.7 * pow (10,-8); //Bolzman's constant
	double u2; //wind velocity in m/s
	double ea; //saturation vapour pressure in mb
	double ed; //actual vapour pressure in mb
	double Qet = 0;
	double Qs = 0;
	double Eat = 0;
	
	//variable for final answer
	double PE = 0;


	//variables for user I/O
	const int MAX_LINE = 256;
	char buffer[MAX_LINE];
	char *temp;


//////////////////////////////////////////////////////// GET ALL NECESSARY VARIABLES /////////////////////////////////////////////////////////////////// 

	//get rho(water density)
	printf ("Please enter rho (water density in kg/m^3):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &rho) == 1 )
	{
		printf("rho = %lf\n", rho);
	
	}
	
	//get lambda(latent heat of vaporization)
	printf ("Please enter lambda (latent heat of vaporization in J/Kg):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &lambda) == 1 )
	{
		printf("lambda = %lf\n", lambda);
	
	}		

	//get Ta(air temperature)
	printf ("Please enter Ta (air temperature in C):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &Ta) == 1 )
	{
		printf("Ta = %lf\n", Ta);
	
	}

	//get ed(actual vapour pressure)
	printf ("Please enter ed (actual vapour pressure in mb):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &ed) == 1 )
	{
		printf("ed = %lf\n", ed);
	
	}

	//get ea (saturation vapour pressure)
	printf ("Please enter ea (saturation vapour pressure in mb):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &ea) == 1 )
	{
		printf("ea = %lf\n", ea);
	
	}

	//get nbyN (ratio of actual/possinle sunshine hours)
	printf ("Please enter n/N (ratio of actual/possinle sunshine hours):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &nbyN) == 1 )
	{
		printf("nbyN = %lf\n", nbyN);
	
	}
	
	//get u2 (wind velocity)
	printf ("Please enter u2 (wind velocity in m/s):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &u2) == 1 )
	{
		printf("u2 = %lf\n", u2);
	
	}

	//get Qs
	printf ("Please enter Qs:");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &Qs) == 1 )
	{
		printf("Qs = %lf\n", Qs);
	
	}

	//get delta (slope of saturation vapour curve
	printf ("Please enter delta (slope of saturation vapour curve):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &big_delta) == 1 )
	{
		printf("big_delta = %lf\n", big_delta);
	
	}


/////////////////////////////////////////////////////////////// Calculate ///////////////////////////////////////////////////////////////////////////////

	//printf ("Values entered respectively were: %lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n", rho,lambda, Ta, ed, nbyN, ea, u2, Qs);
	
	//calculate Ql
	printf ("\n\nCalculating Ql\n");
	Ql = 0.95* ((8.64*pow(10,7)/(rho*lambda)) * SIGMA * pow((273.16+Ta),4) * (0.53+0.065* pow((ed-1),0.5)) * (0.1+0.9*nbyN))  ;  
	printf ("Ql = %lf\n",Ql);

	//calculating Qet
	printf ("Calculating Qet\n");
	Qet = Qs * (1-R) - Ql;
	printf ("Qet = %lf\n",Qet);


	//calculating Eat
	printf ("Calculating Eat\n");
	Eat = 0.3 * (1+0.5 * u2) * (ea-ed);
	printf ("Eat = %lf\n",Eat);

	//calculating PE
	printf ("\n\nCalculating Potential Evapotranspiration (PE)\n");
	PE = (big_delta/(big_delta+GAMMA)) * Qet + (GAMMA/(big_delta+GAMMA)) * Eat ;
	printf ("The Potential Evapotranspiration is %lf\n\n",PE);


	return 0;
}
	
	
	
	
	
