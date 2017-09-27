//Tanzim Mokammel
//July 13, 2009
//mtanzim@hotmail.com
//program to calculate PE with Blaney-Criddle formula

# include <stdio.h>
# include <string.h>
# include <math.h>
#include <stdlib.h>
#include <unistd.h>

const int MAX_CONFIG_LINE_LEN = 3000;
//const int MAX_LINES = 50;



typedef struct lat_data lat_data;

struct lat_data {
	
	int latitude;
	double p_values [12];
};

lat_data line_data[50];


int process_config_line (char *line,int line_count) {

	char *all_col;
	int temp_count = 0;
	int temp_lat;
	double temp_p;

	all_col = strtok (line, ",");
	temp_lat = atoi (all_col);



	line_data[line_count-2].latitude = temp_lat;


	while (temp_count < 12){
		all_col = strtok (NULL, ",");
		sscanf(all_col, "%lf", &temp_p);

		line_data[line_count-2].p_values[temp_count] = temp_p;


		temp_count ++;
	}

	return;
}

	
		
	
	

	

	

int main (){

	double PE; //potential evapotranspiration in mm/day
	double T; //mean daily temeperature over a month in C
	double p; //mean daily percentage of total annual daytime

	//variables for user I/O
	const int MAX_LINE = 256;
	char buffer[MAX_LINE];
	char *temp;

/*

///////////////////////////////////////////////////File I/0 for future use\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

	char op_file [1000];

	strcpy (op_file, "p_values_north.csv");	
	FILE *file = fopen(op_file, "r");

	if (file == NULL){
		printf ("File error!\n");
		return 0;
	}

	// Process the file.

	int count = 1;
	int error_occurred = 0;
	while (!error_occurred && !feof(file)) {

		/// Read a line from the file.
		char line[MAX_CONFIG_LINE_LEN];
		char *l = fgets(line, sizeof line, file);

		// Process the line.
		
		if (l == line)
		{

			
			if (count >= 2)
			{
				//printf ("\nline %d from records: %s\n", count, line);
				process_config_line(line,count);
			}

		}			
			
		else if (!feof(file))
		{
			//error_occurred = 1;
			printf ("Error reading file.\n");
			return 0;
		}
		else
		{
			//printf ("Completed reading current file.\n");
		}

		count ++;
	}


	//print out struct data
	int back_count = 0;
	int month_count = 0;

	while (back_count < count -3)
	{
		printf ("Monthly p values for latitude %d are: ", line_data[back_count].latitude);

		while (month_count < 12){
			printf ("\n%lf for month %d", line_data[back_count].p_values[month_count],month_count+1);
			month_count ++;
		}
		printf ("\n\n");
		month_count = 0;
		back_count ++;
	}
	count = 0;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
*/
	

	//get T
	printf ("Please enter T (mean daily temeperature over a month in C):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &T) == 1 )
	{
		printf("T = %lf\n", T);
	
	}


	//get p
	printf ("Please enter p (mean daily percentage of total annual daytime):");
	temp = fgets(buffer,MAX_LINE, stdin);
	if ( sscanf(buffer, "%lf", &p) == 1 )
	{
		printf("p = %lf\n", p);
	
	}

	//calculate PE
	PE = p*(0.46*T+8);

	printf ("PE = %lf mm/day\n",PE);

	return 0;
}


