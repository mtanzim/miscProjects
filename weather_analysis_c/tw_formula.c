//Tanzim Mokammel
//June 9, 2009
//mtanzim@hotmail.com
//program to calculate PE

# include <stdio.h>
# include <string.h>
# include <math.h>





/**
 * @brief Reverses string
 *
 * @param begin Specifies the start of the string to be reversed.
 * @param end Specifies the end of the string to be reversed.
 * 
 * @return Void function; reverses string
 *
 * Code copied from online resource found at:
 *
 * reference
 * [2]	"Stuart's Useful C/C++ Pages," [Online document],[cited 2009 Mar 1],
 *	Available HTTP: http://www.jb.man.ac.uk/~slowe/cpp/itoa.html
 */
void strreverse(char* begin, char* end) {
	char aux;
	while(end>begin)
		aux=*end, *end--=*begin, *begin++=aux;
	
}


/**
 * @brief Converts integers to strings
 *
 * @param value The integer to be converted
 * @param base Integer base (ie. decimal, binary, hexadecimal)
 * 
 * @return Void function; reverses string
 *
 * Code copied from online resource found at:
 *
 * reference
 * [2]	"Stuart's Useful C/C++ Pages," [Online document],[cited 2009 Mar 1],
 *	Available HTTP: http://www.jb.man.ac.uk/~slowe/cpp/itoa.html
 */	
void itoa(int value, char* str, int base) {
	
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* wstr=str;
	int sign;
	
	// Validate base
	if (base<2 || base>35){ *wstr='\0'; return; }
	
	// Take care of sign
	if ((sign=value) < 0) value = -value;
	
	// Conversion. Number is reversed.
	do *wstr++ = num[value%base]; while(value/=base);
	if(sign<0) *wstr++='-';
	*wstr='\0';
	
	// Reverse string
	strreverse(str,wstr-1);
}










int main (){


	int year = 1988;
	char c_year[5];


	///note error in indentation
	while (year <= 1990) {

	printf ("\nProcessing data for year %d.\n", year);



	double mean_temp [12];
	double N_m[12];
	double a = 0;

	double i_m [12];  //monthly heat index
	double big_I = 0; //heat index for the year

	double PE_m [12]; //potential evapotransiration 

	const int MAX_LINE = 1000;
	char buffer[MAX_LINE];
	char *temp;

	

	char op_file_t [1000];
	char op_file_n [1000];

	int ns;
	char NS[30];


/*
	printf ("Enter 0 for North, and 1 for South:");
	temp = fgets(buffer,MAX_LINE, stdin);
	if (temp != NULL)
	{
		//mean_temp[k] = atoi(buffer);
		sscanf(buffer, "%d", &ns);
		//printf("You entered %d\n", latitude);
	}
	else
	{
		printf ("Error!\n");
	}
*/



	//open file for temperature and N
	strcpy (op_file_t, "mean_temp_pearson_toronto/");
	itoa (year, c_year, 10);
	strcat (op_file_t, c_year);
	strcat (op_file_t, ".csv");

	
	strcpy (op_file_n, "tw_n.csv");
	strcpy (NS, "N (Pearson, Toronto)");

/*

	if (ns == 0) {
		strcpy (op_file_t, "pearson_toronto/temp_1960.csv");	
		strcpy (op_file_n, "tw_n.csv");
		strcpy (NS, "North");
	}
	else if (ns == 1) {
		strcpy (op_file_t, "south_tw_test_t.csv");	
		strcpy (op_file_n, "south_tw_test_n.csv");
		strcpy (NS, "South");
	}
	else {
		printf ("Invalid Input.\n");
		return 0;
	}
*/

	
	FILE *file_t = fopen(op_file_t, "r");
	FILE *file_n = fopen(op_file_n, "r");

	if (file_t == NULL || file_n == NULL){
		printf ("File error!\n");
		return 0;
	}


	
	double temp_T [12];
	double temp_N [12];

	int latitude = 43;


/*

	printf ("Please enter the latitude:");
	temp = fgets(buffer,MAX_LINE, stdin);
	if (temp != NULL)
	{
		//mean_temp[k] = atoi(buffer);
		sscanf(buffer, "%d", &latitude);
		//printf("You entered %d\n", latitude);
	}
	else
	{
		printf ("Error!\n");
	}
*/


	//process the files

	int count_n = 1; //line counter
	int count_t = 1;
	int found_t = 0;
	int found_n = 0;


	while (!found_n && !feof(file_n)) {
		
		char line_n[MAX_LINE];
		char *ln = fgets(line_n, sizeof line_n, file_n);

		if (ln == line_n){

			
			if (count_n >= 0){
				//printf ("\nline %d from records: %s\n", count, line);
				//process_config_line(line,count);
				char *all_col;
				int temp_lat = 0;
				double temp = 0;

				all_col = strtok (line_n, ",");
				temp_lat = atoi (all_col);

				//if the latitude matches, fill the temporary N array
				if  (temp_lat == latitude) {

					//printf("Latitude found. Collecting N Data.\n");
					found_n = 1;
					
					int temp_count = 0;

					while (temp_count < 12){

						all_col = strtok (NULL, ",");
						//printf ("Found %s\n", all_col);
						sscanf(all_col, "%lf", &temp);
						temp_N [temp_count] = temp;
						//line_data[line_count-2].p_values[temp_count] = temp_p;
						//printf ("N for month %d for latitude %d is %lf \n", temp_count+1, latitude, temp_N [temp_count]); 

						temp_count ++;
					}
					temp_count = 0;
				}
				else{
					//printf("Latitude not found yet.\n");
				}
							
			}

		}

		count_n ++;
	}

	



	while (!found_t && !feof(file_t)) {

		/// Read a line from the file.
		char line_t[MAX_LINE];
		
		char *lt = fgets(line_t, sizeof line_t, file_t);
		

		// Process the lines.

		if (lt == line_t){

			
			if (count_t >= 0){
				//printf ("\nline %d from records: %s\n", count, line);
				//process_config_line(line,count);
				char *all_col;
				int temp_lat = 0;
				double temp = 0;

				all_col = strtok (line_t, ",");
				temp_lat = atoi (all_col);

				//if the latitude matches, fill the temporary tempearature array
				if  (temp_lat == latitude) {

					//printf("Latitude found. Collecting T Data.\n\n");
					found_t = 1;
					
					int temp_count = 0;

					while (temp_count < 12){

						all_col = strtok (NULL, ",");
						sscanf(all_col, "%lf", &temp);
						
						//setting negative values to zero
						if (temp <= 0) {temp = 0;}

						temp_T [temp_count] = temp;
						//line_data[line_count-2].p_values[temp_count] = temp_p;
						//printf ("Temperature for month %d for latitude %d is %lf \n", temp_count+1, latitude, temp_T [temp_count]); 

						temp_count ++;
					}
					temp_count = 0;
				}
				else{
					//printf("Latitude not found yet.\n");
				}
							
			}

		}			

		count_t ++;
	}

	fclose (file_t);
	fclose (file_n);

	if (found_t != 1 || found_n != 1) {
		//printf ("Latitude was not found. Exiting.\n");
		return 0;
	}






	int k = 0;
	for (k = 0; k < 12; k++){



		mean_temp[k] = temp_T[k];
		//printf ("Temperature for month %d for latitude %d%s is %lf \n", k+1, latitude,NS, mean_temp[k]); 
		N_m[k] = temp_N[k];
		//printf ("N for month %d for latitude %d%s is %lf \n", k+1, latitude,NS, N_m[k]);

		

/*

		printf ("Please enter mean temperature for month %d:", k+1);


		//cin >> mean_temp[k];
		temp = fgets(buffer,MAX_LINE, stdin);
		if (temp != NULL)
		{
			//mean_temp[k] = atoi(buffer);
			sscanf(buffer, "%lf", &mean_temp[k]);
			printf("You entered = %lf\n", mean_temp[k]);
		}
		else
		{
			printf ("Error!\n");
		}


		//cout << "Please enter the constant N for month "  << k+1 << ": ";
		printf ("Please enter the constant N for month %d:", k+1);


		//cin >> N_m[k];
		temp = fgets(buffer,MAX_LINE, stdin);
		if (temp != NULL)
		{
			//N_m[k] = atoi(buffer);
			sscanf(buffer, "%lf", &N_m[k]);
			printf("You entered = %lf\n", N_m[k]);
		}
		else
		{
			printf ("Error!\n");
		}
*/
	

		//calculate i_m
		i_m[k] = pow((mean_temp[k]/5),1.5);

		//printf ("The i_m is %lf \n",i_m[k]);

		//calculate I
		big_I = big_I + i_m[k];
		//printf ("Current value of I: %lf\n\n\n",big_I); 

	}

	//for testing purposes, set big_I
	//big_I = 31.63;
	//cout << "Current value of I: "  << big_I << endl;


	//calculate a
	a = 6.7 * pow (10,-7) * pow (big_I,3) - 7.7 * pow(10,-5) * pow (big_I,2) + 1.8 * pow (10,-2) * big_I + 0.49 ;

	//cout << "Value of a: "  << a << endl;
	//printf ("Value of a: %lf\n\n\n",a);

	//calculate monthly PE

	int j=0;
	for (j = 0; j < 12 ; j++){
		
		PE_m [j] = (1.6*N_m[j]) * pow ((10* mean_temp[j] / big_I), a);
		


		//PE_m[j] = 1.62 * pow ((10*mean_temp[j]/big_I),a);
		//cout << "Potential evapotransiration for month "  << j+1 << ": " << PE_m[j] << endl;
		printf ("Potential evapotranspiration for month %d,%d:\t %lf\n", j+1,year, PE_m[j]);
	}

	
	year ++;
	}


	return 0;


}

