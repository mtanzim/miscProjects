//Tanzim Mokammel
//July 16, 2009
//mtanzim@hotmail.com
//program to calculate PE with an alternative version of the Penman equation

# include <stdio.h>
# include <string.h>
# include <math.h>

double findA (double temp_ew, double temp_Ta) {

	//if A is not readily available, use this formula
	return (4.098 * temp_ew) / pow ((temp_Ta+237.3),2);
}
double findew () {

	double t;
	double calc_ew;
	double x1;

	//variables for user I/O
	const int MAX_LINE = 256;
	char buffer[MAX_LINE];
	char *temp;

	printf ("Please enter t: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &t) == 1 )
	{
		printf("t = %lf\n", t);
	
	}

	x1 = (17.27 * t)/ (237.3 + t);
	calc_ew = 4.584 * pow (10, x1); 

	return calc_ew;

}

int main (){

	//variables needed for the equations
	double PET; //daily potential evapotranspiration per day in mm
	
	double A; //slope of saturation vaour pressure vs temperature curve at mean air temperature, in mm of mercury/C
	const double y = 0.49; //psychometric constant in mm of mercury/C

	double Hn; //net radiation in mm of evaporable water per day
	double Ha; //incident solar radiation in mm of evaporable water/day
	double r; //reflection coefficient (found on table on page 62 of Engineering Hydrology by K Subramanya)
	double a; //constant depending of latiture(phi) [a= 0.29 cos (phi)]	
	double const b = 0.52;
	double n; //duration of bright sunshine hours
	double N; //max possible sunshine hours (function of latitude as found on Table 3.5)
	const double o = 0.00000000201; //Stefan - Boltzman constant in mm/day	
	double Ta; //mean air temperature in Kelvin

	double Ea; //wind velocity and saturation deficit	
	double u2; //mean wind speed at 2m above the ground in km/day
	double ew; //saturation vapour pressure at mean air temperature in mm of mercury
	double ea; //actual vapour pressure

	//variables for user I/O
	const int MAX_LINE = 256;
	char buffer[MAX_LINE];
	char *temp;

	

	//Get A
	printf ("Please enter A: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &A) == 1 )
	{
		printf("A = %lf\n", A);
	
	}

	



	//Get ew
	printf ("Please enter ew: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &ew) == 1 )
	{
		printf("ew = %lf\n", ew);
	
	}

	//Get u2
	printf ("Please enter u2: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &u2) == 1 )
	{
		printf("u2 = %lf\n", u2);
	
	}

	//Get Ha
	printf ("Please enter Ha: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &Ha) == 1 )
	{
		printf("Ha = %lf\n", Ha);
	
	}

	

	//Get n
	printf ("Please enter n: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &n) == 1 )
	{
		printf("n = %lf\n", n);
	
	}

	//Get N
	printf ("Please enter N: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &N) == 1 )
	{
		printf("N = %lf\n", N);
	
	}

	//Get ea
	printf ("Please enter ea: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &ea) == 1 )
	{
		printf("ea = %lf\n", ea);
	
	}

	//Get a
	printf ("Please enter a: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &a) == 1 )
	{
		printf("a = %lf\n", a);
	
	}


	//Get Ta
	printf ("Please enter Ta: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &Ta) == 1 )
	{
		printf("Ta = %lf\n", Ta);
	
	}
	
	//Get r
	printf ("Please enter r: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &r) == 1 )
	{
		printf("r = %lf\n", r);
	
	}


/*

	//if A is not readily available, use this formula
	A = (4.098 * ew) / pow ((Ta+237.3),2);

	//if ew is not readily available, use this formula

	double t;
	printf ("Please enter t: ");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &t) == 1 )
	{
		printf("t = %lf\n", t);
	
	}
 
	double x1;
	
	x1 = (17.27 * t)/ (237.3 + t);
	ew = 4.584 * pow (10, x1);

*/

	//equations needed to calculate PET

/*

	double x1;
	double x2;
	double x3;
	double x4;
	double x5;

	printf ("Ha = %lf\n",Ha);
	printf ("r = %lf\n",r);
	
	x1 = Ha* (1-r);
	printf ("x1 = %lf\n",x1);

	x2 = a + b*(n/N);
	printf ("x2 = %lf\n",x2);

	x3 = o * pow(Ta,4);
	printf ("x3 = %lf\n",x3);

	x4 = 0.56 -0.092*pow(ea,0.5);
	printf ("x4 = %lf\n",x4);

	x5 = 0.10 + 0.90 * (n/N); 

	Hn = x1*x2 - x3*x4*x5;
*/

	Hn = Ha*(1-r)*(a+b*(n/N)) - o * pow(Ta,4) * (0.56-0.092 * pow (ea, 0.5)) * (0.1+0.9*(n/N));
	
	printf ("\n\nHn = %lf mm of water/day\n",Hn);

	Ea = 0.35 * (1+ (u2/160))*(ew-ea);
	printf ("Ea = %lf mm/day\n",Ea); 

	PET = (A*Hn+Ea*y)/(A+y);
	printf ("PET = %lf mm/day\n",PET);

	return 0;
}
	
