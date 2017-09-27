//Tanzim Mokammel
//June 15, 2009
//mtanzim@hotmail.com
//program to analyze yearly wind data


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

const int MAX_CONFIG_LINE_LEN = 3000;



//declaration of needed structures
typedef struct hour_data hour_data;
typedef struct day_data day_data;
typedef struct month_data month_data;
typedef struct year_data year_data;



struct hour_data{
	int wind_dir;
	int wind_speed;
};

struct day_data{
	hour_data hours[24];
};

struct month_data{
	day_data days[31];
};


struct year_data{
	month_data months[12];}; 

//structure to hold all information
year_data years[30];



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


int process_config_line(char *line)
{

	int c_year;
	int c_month;
	int c_day;
	char full_time[5];
	int c_time;
	char c_dir[10];
	char c_speed[10];

	char *token;
	char *sub_token;
	
	token = strtok(line, ",");
	c_year = atoi(token);

	token = strtok(NULL, ",");
	c_month = atoi(token);

	token = strtok(NULL, ",");
	c_day = atoi(token);

	token = strtok(NULL, ",");
	strcpy (full_time, token);


	token = strtok(NULL, ",");


	//check for blank direction data
	if (token[0] == 13){
		strcpy (c_dir,"-1");
	}
	else{
		strcpy (c_dir,token);
	}
/*
		
	if (token == NULL){
		strcpy (c_dir,"-1");
	}
	else{
		int tc = 0;
		while (token[tc] != 0){
		
			printf ("%d\n",token[tc]);
			tc++;
		}

		strcpy (c_dir,token);
	}
*/


	
	token = strtok(NULL, "\n");
	
	//check for blank speed data	
	if (token == NULL){
		strcpy (c_speed,"-1");
		
	}
	else{
		int tc = 0;
		while (token[tc] != 0){
		
			//printf ("%d\n",token[tc]);
			tc++;
		}
	
		token[tc] = 0;
		token[tc-1] = 0;

		strcpy (c_speed,token);
	}



	c_time = atoi(strtok(full_time,":"));


/*

	printf ("The year is: %d\n", c_year);
	printf ("The month is: %d\n", c_month);
	printf ("The day is: %d\n", c_day);
	printf ("The time is %d\n", c_time);
	printf ("The direction  is: %s\n", c_dir);
	printf ("The speed is: %d\n", atoi(c_speed));
*/



	years[c_year-1971].months[c_month-1].days[c_day-1].hours[c_time].wind_dir = atoi(c_dir)*10;
	years[c_year-1971].months[c_month-1].days[c_day-1].hours[c_time].wind_speed = atoi(c_speed);

	//printf("data recorded\n");
	//printf ("Wind Direction: %d\n", years[c_year-1971].months[c_month-1].days[c_day-1].hours[c_time].wind_dir);
	//printf ("Wind Speed: %d\n\n", years[c_year-1971].months[c_month-1].days[c_day-1].hours[c_time].wind_speed);

	return;
}
	


int main()
{


	
	int grand_count = 1971;
	
//NOTE ERROR IN INDENTATION
//////////////////////////////////////////////////////////////////START FILE LOOP HERE//////////////////////////////////////////////////////////////////
	while(grand_count <= 2000){

		char op_file [1000];
	
		//void itoa(int value, char* str, int base)
		itoa(grand_count, op_file, 10);
		strcat(op_file, ".csv");
		printf ("Reading:%s\n", op_file);


	
		int error_occurred = 0;


	// Open file for reading.
//__________________________________________________________________________________________________________________________________________________
		FILE *file = fopen(op_file, "r");
//__________________________________________________________________________________________________________________________________________________

		if (file == NULL){
			printf ("File error!\n");
			return 0;
		}

		// Process the file.

		int count = 1;
		while (!error_occurred && !feof(file)) {
			/// Read a line from the file.
			char line[MAX_CONFIG_LINE_LEN];
			char *l = fgets(line, sizeof line, file);

			// Process the line.

			
			if (l == line)
			{

			
				if (count >= 2)
				{
					//printf ("\nline %d from records: %s", count, line);
					process_config_line(line);
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
				printf ("Completed reading current file.\n");
			}

			count ++;
		}


		fclose(file);
		grand_count ++;
	
	}



	char wr_file [1000];
	char temp_wr_file [1000];
	char dir_name[1000];
	strcpy (dir_name,"analyzed_wind");
	mkdir(dir_name, 0700);


	
	
	strcpy (wr_file,"");
	strcat (wr_file, dir_name);
	strcat (wr_file, "/");
	//itoa(grand_count,temp_wr_file,10);
	//strcat(wr_file,temp_wr_file);
	strcat (wr_file,"speed_analyzed.txt");
	printf ("Writing to:%s:\n", wr_file); 

	//printf ("Ready to write to %s.\n",wr_file);


//_______________________________________________________________________________________________________________________________________________________
	FILE *w_file = fopen (wr_file, "w");
//_______________________________________________________________________________________________________________________________________________________

	if (w_file == NULL){
		printf ("Error writing to file\n");
		return 0;
	}

	
	fprintf (w_file, "Average Wind Speeds\n");
	fprintf (w_file, "MM,DD,Hr,");


	int yr_count;
	
	for (yr_count = 71;yr_count<100;yr_count++){
		fprintf (w_file, "%d,",yr_count);
	}
	fprintf (w_file,"00,Avg\n");

	int m_count =0;
	int d_count =0;
	int h_count =0;
	int y_count =0;

	double all_speeds=0.0;
	double speed_avg=0.0;
	const double num_of_years = 30.0;
	double subtractor = 0.0;


	while (m_count <12){


		fprintf(w_file, "%d,%d,%d,", m_count+1, d_count+1, h_count);



		while (y_count < 30){
			fprintf (w_file, "%d,", years[y_count].months[m_count].days[d_count].hours[h_count].wind_speed);
			
			if (years[y_count].months[m_count].days[d_count].hours[h_count].wind_speed >= 0){
				all_speeds = all_speeds + years[y_count].months[m_count].days[d_count].hours[h_count].wind_speed;
			}
			else{
				subtractor ++;
			}

			y_count++;
		}
		
		speed_avg = all_speeds/(num_of_years-subtractor);
		fprintf (w_file, "%f\n", speed_avg);
		//fprintf (w_file, "\n");

		all_speeds = 0;
		speed_avg = 0;
		y_count=0;
		subtractor = 0;


		

		h_count ++;
		if (h_count ==24){

			h_count = 0;
			d_count++;
			
			if (d_count == 31){
				d_count = 0;
				h_count = 0;
				m_count++;
				fprintf (w_file, "\n--------------------------------END OF MONTH-------------------------------------\n\n");

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				if (m_count < 12){

					fclose(w_file);

					strcpy (wr_file,"");
					strcat (wr_file, dir_name);
					strcat (wr_file, "/");

					strcat (wr_file,"speed_analyzed_");
					itoa(m_count+1,temp_wr_file,10);
					strcat(wr_file,temp_wr_file);
					strcat (wr_file, ".txt");
					printf ("Writing to:%s:\n", wr_file); 

					//printf ("Ready to write to %s.\n",wr_file);


//_______________________________________________________________________________________________________________________________________________________
					FILE *w_file = fopen (wr_file, "w");
//_______________________________________________________________________________________________________________________________________________________

					if (w_file == NULL){
						printf ("Error writing to file\n");
						return 0;
					}

	
					fprintf (w_file, "Average Wind Speeds for month %d\n\n",m_count+1);
					fprintf (w_file, "MM,DD,Hr,");

					for (yr_count = 71;yr_count<100;yr_count++){
						fprintf (w_file, "%d,",yr_count);
					}
					fprintf (w_file,"00,Avg\n");
				}

*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			}
		}

	}

	
	fclose(w_file);
	printf ("Completed writing speed data. Commencing writing direction data.\n");










//////////////////////////////////////////////////////////WIND DIRECTION/////////////////////////////////////////////////////////////////////

	strcpy (wr_file,"");
	strcat (wr_file, dir_name);
	strcat (wr_file, "/");
	//itoa(grand_count,temp_wr_file,10);
	//strcat(wr_file,temp_wr_file);
	strcat (wr_file,"dir_analyzed.txt");
	printf ("Writing to:%s:\n", wr_file); 

	//printf ("Ready to write to %s.\n",wr_file);


//_______________________________________________________________________________________________________________________________________________________
	w_file = fopen (wr_file, "w");
//_______________________________________________________________________________________________________________________________________________________

	if (w_file == NULL){
		printf ("Error writing to file\n");
		return 0;
	}

	
	fprintf (w_file, "Average Wind Directions\n");
	fprintf (w_file, "MM,DD,Hr,");

	
	for (yr_count = 71;yr_count<100;yr_count++){
		fprintf (w_file, "%d,",yr_count);
	}
	fprintf (w_file,"00,Avg\n");

	m_count =0;
	d_count =0;
	h_count =0;
	y_count =0;

	double all_dir=0.0;
	double dir_avg=0.0;
	//num_of_years = 30.0;


	while (m_count <12){


		fprintf(w_file, "%d,%d,%d,", m_count+1, d_count+1, h_count);



		while (y_count < 30){
			fprintf (w_file, "%d,", years[y_count].months[m_count].days[d_count].hours[h_count].wind_dir);

			if (years[y_count].months[m_count].days[d_count].hours[h_count].wind_dir >= 0){
				all_dir = all_dir + years[y_count].months[m_count].days[d_count].hours[h_count].wind_dir;
			}
			else
			{
				subtractor++;
			}
			y_count++;
		}
		
		dir_avg = all_dir/(num_of_years-subtractor);
		fprintf (w_file, "%f\n", dir_avg);
		//fprintf (w_file, "\n");

		all_dir = 0;
		dir_avg = 0;
		y_count=0;
		subtractor = 0;


		

		h_count ++;
		if (h_count ==24){

			h_count = 0;
			d_count++;
			
			if (d_count == 31){
				d_count = 0;
				h_count = 0;
				m_count++;
				fprintf (w_file, "\n--------------------------------END OF MONTH-------------------------------------\n\n");

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

				if (m_count < 12){

					fclose(w_file);

					strcpy (wr_file,"");
					strcat (wr_file, dir_name);
					strcat (wr_file, "/");

					strcat (wr_file,"dir_analyzed_");
					itoa(m_count+1,temp_wr_file,10);
					strcat(wr_file,temp_wr_file);
					strcat (wr_file, ".txt");
					printf ("Writing to:%s:\n", wr_file); 

					//printf ("Ready to write to %s.\n",wr_file);


//_______________________________________________________________________________________________________________________________________________________
					FILE *w_file = fopen (wr_file, "w");
//_______________________________________________________________________________________________________________________________________________________

					if (w_file == NULL){
						printf ("Error writing to file\n");
						return 0;
					}

	
					fprintf (w_file, "Average wind directions for month %d\n\n",m_count+1);
					fprintf (w_file, "MM,DD,Hr,");

					for (yr_count = 71;yr_count<100;yr_count++){
						fprintf (w_file, "%d,",yr_count);
					}
					fprintf (w_file,"00,Avg\n");
				}

*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


			}
		}

	}

	fclose(w_file);
	printf ("Completed writing direction data.\n");


	return 0;
}
