//Tanzim Mokammel
//June 4, 2009
//mtanzim@hotmail.com
//program to analyze yearly weather data


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

const int MAX_CONFIG_LINE_LEN = 3000;



typedef struct day_data day_data;
typedef struct month_data month_data;
typedef struct year_data year_data;

struct day_data{

	int clear;
	int mclear;
	int cloudy;
	int mcloudy;

	//new parameters
	int fog;
	int haze;
	int ths;
	int rain;
	int rain_sh;
	int dz;
	int snow;
	int snow_sh;
	int fz_rain;
	int fz_dz;
	int ice_p;
 
	//char dom_stat[2000];	

};

struct month_data{
	
	//int month;
	day_data days[31];

	int mon_clear;
	int mon_mclear;
	int mon_cloudy;
	int mon_mcloudy;

	//new parameters
	int mon_fog;
	int mon_haze;
	int mon_ths;
	int mon_rain;
	int mon_rain_sh;
	int mon_dz;
	int mon_snow;
	int mon_snow_sh;
	int mon_fz_rain;
	int mon_fz_dz;
	int mon_ice_p;


};


struct year_data{
	int year;
	month_data months[12];

	int yr_clear;
	int yr_mclear;
	int yr_cloudy;
	int yr_mcloudy;

	//new parameters
	int yr_fog;
	int yr_haze;
	int yr_ths;
	int yr_rain;
	int yr_rain_sh;
	int yr_dz;
	int yr_snow;
	int yr_snow_sh;
	int yr_fz_rain;
	int yr_fz_dz;
	int yr_ice_p;

}; 

//structure to hold all information
year_data years;






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




void analyze_status (char *status,int num_month, int num_day){


		if (strcmp(status,"Clear")==0){
			years.months[num_month].days[num_day].clear ++;
			years.months[num_month].mon_clear ++;
			years.yr_clear ++;
		}
		else if (strcmp(status,"Mainly Clear")==0){
	
			years.months[num_month].days[num_day].mclear ++;
			years.months[num_month].mon_mclear ++;
			years.yr_mclear ++;
		}
		else if (strcmp(status,"Cloudy")==0){
	
			years.months[num_month].days[num_day].cloudy ++;
			years.months[num_month].mon_cloudy ++;
			years.yr_cloudy ++;
		}
		else if (strcmp(status,"Mostly Cloudy")==0){
	
			years.months[num_month].days[num_day].mcloudy ++;
			years.months[num_month].mon_mcloudy ++;
			years.yr_mcloudy ++;
		}

	
		//new conditions
		else if (strcmp(status,"Fog")==0){
	
			years.months[num_month].days[num_day].fog ++;
			years.months[num_month].mon_fog ++;
			years.yr_fog ++;
		}
		else if (strcmp(status,"Haze")==0){
	
			years.months[num_month].days[num_day].haze ++;
			years.months[num_month].mon_haze ++;
			years.yr_haze ++;
		}
		else if (strcmp(status,"Thunderstorms")==0){
	
			years.months[num_month].days[num_day].ths ++;
			years.months[num_month].mon_ths ++;
			years.yr_ths ++;
		}


		else if (strcmp(status,"Rain")==0){
	
			years.months[num_month].days[num_day].rain ++;
			years.months[num_month].mon_rain ++;
			years.yr_rain ++;
		}

		//check if these are wanted
		else if (strcmp(status,"Moderate Rain")==0){
	
			years.months[num_month].days[num_day].rain ++;
			years.months[num_month].mon_rain ++;
			years.yr_rain ++;
		}
		else if (strcmp(status,"Heavy Rain")==0){
	
			years.months[num_month].days[num_day].rain ++;
			years.months[num_month].mon_rain ++;
			years.yr_rain ++;
		}
		////////////////////////////////////////////////////////////////////////////


		else if (strcmp(status,"Rain Showers")==0){
	
			years.months[num_month].days[num_day].rain_sh ++;
			years.months[num_month].mon_rain_sh ++;
			years.yr_rain_sh ++;
		}
		//wanted?
		else if (strcmp(status,"Moderate Rain Showers")==0){
	
			years.months[num_month].days[num_day].rain_sh ++;
			years.months[num_month].mon_rain_sh ++;
			years.yr_rain_sh ++;
			
		}
		else if (strcmp(status,"Heavy Rain Showers")==0){
	
			years.months[num_month].days[num_day].rain_sh ++;
			years.months[num_month].mon_rain_sh ++;
			years.yr_rain_sh ++;
		}
		///////////////////////////////////////////////////////////////////

		else if (strcmp(status,"Drizzle")==0){
	
			years.months[num_month].days[num_day].dz ++;
			years.months[num_month].mon_dz ++;
			years.yr_dz ++;
		}
		//wanted?
		else if (strcmp(status,"Moderate Drizzle")==0){
	
			years.months[num_month].days[num_day].dz ++;
			years.months[num_month].mon_dz ++;
			years.yr_dz ++;
		}
		else if (strcmp(status,"Heavy Drizzle")==0){
	
			years.months[num_month].days[num_day].dz ++;
			years.months[num_month].mon_dz ++;
			years.yr_dz ++;
		}
		//////////////////////////////////////////////////////////////////



		else if (strcmp(status,"Snow")==0){
	
			years.months[num_month].days[num_day].snow ++;
			years.months[num_month].mon_snow ++;
			years.yr_snow ++;
		}
		//wanted?
		else if (strcmp(status,"Moderate Snow")==0){
	
			years.months[num_month].days[num_day].snow ++;
			years.months[num_month].mon_snow ++;
			years.yr_snow ++;
		}
		else if (strcmp(status,"Heavy Snow")==0){
	
			years.months[num_month].days[num_day].snow ++;
			years.months[num_month].mon_snow ++;
			years.yr_snow ++;
		}
		//////////////////////////////////////////////////////////////////

		else if (strcmp(status,"Snow Showers")==0){
	
			years.months[num_month].days[num_day].snow_sh ++;
			years.months[num_month].mon_snow_sh ++;
			years.yr_snow_sh ++;
		}
		//wanted?
		else if (strcmp(status,"Moderate Snow Showers")==0){
	
			years.months[num_month].days[num_day].snow_sh ++;
			years.months[num_month].mon_snow_sh ++;
			years.yr_snow_sh ++;
		}
		else if (strcmp(status,"Heavy Snow Showers")==0){
	
			years.months[num_month].days[num_day].snow_sh ++;
			years.months[num_month].mon_snow_sh ++;
			years.yr_snow_sh ++;
		}
		///////////////////////////////////////////////////////////////////


		
		else if (strcmp(status,"Freezing Rain")==0){
	
			years.months[num_month].days[num_day].fz_rain ++;
			years.months[num_month].mon_fz_rain ++;
			years.yr_fz_rain ++;
		}

		//check if these are wanted
		else if (strcmp(status,"Moderate Freezing Rain")==0){
	
			years.months[num_month].days[num_day].fz_rain ++;
			years.months[num_month].mon_fz_rain ++;
			years.yr_fz_rain ++;
		}
		else if (strcmp(status,"Heavy Freezing Rain")==0){
	
			years.months[num_month].days[num_day].fz_rain ++;
			years.months[num_month].mon_fz_rain ++;
			years.yr_fz_rain ++;
		}
		///////////////////////////////////////////////////////////////////////////



		else if (strcmp(status,"Freezing Drizzle")==0){
	
			years.months[num_month].days[num_day].fz_dz ++;
			years.months[num_month].mon_fz_dz ++;
			years.yr_fz_dz ++;
		}
		//wanted?
		else if (strcmp(status,"Moderate Freezing Drizzle")==0){
	
			years.months[num_month].days[num_day].fz_dz ++;
			years.months[num_month].mon_fz_dz ++;
			years.yr_fz_dz ++;
			
		}
		else if (strcmp(status,"Heavy Freezing Drizzle")==0){
	
			years.months[num_month].days[num_day].fz_dz ++;
			years.months[num_month].mon_fz_dz ++;
			years.yr_fz_dz ++;
		}
		//////////////////////////////////////////////////////////////////


		else if (strcmp(status,"Ice Pellets")==0){
	
			years.months[num_month].days[num_day].ice_p ++;
			years.months[num_month].mon_ice_p ++;
			years.yr_ice_p ++;
		}
		//wanted?
		else if (strcmp(status,"Moderate Ice Pellets")==0){
	
			years.months[num_month].days[num_day].ice_p ++;
			years.months[num_month].mon_ice_p ++;
			years.yr_ice_p ++;
		}
		else if (strcmp(status,"Heavy Ice Pellets")==0){
	
			years.months[num_month].days[num_day].ice_p ++;
			years.months[num_month].mon_ice_p ++;
			years.yr_ice_p ++;
		}
		//////////////////////////////////////////////////////////////////


		else{
			//printf ("Blank/Invalid/Unwanted Data found.\n");
		}
	//}

	//printf ("The year is: %d\n", num_year);
	//printf ("The month is: %d\n", num_month);
	//printf ("The day is: %d\n", num_day);
	//printf ("|%s|\n", status);


		return;


}





int process_config_line(char *line)
{
	

	int num_year;
	int num_month;
	int num_day;
	char status [MAX_CONFIG_LINE_LEN];
	

	char *mul_status[10];
	char *all_col;

	all_col = strtok(line,",");
	num_year = atoi (all_col);
	years.year = num_year;

	all_col = strtok(NULL,",");
	num_month = atoi (all_col)-1;

	all_col = strtok(NULL,",");
	num_day = atoi (all_col)-1;

	all_col = strtok(NULL,"\n");

	int tc = 0;
	while (all_col[tc] != 0){
		//printf ("%d\n",all_col[tc]);
		tc++;
	}
	
	all_col[tc] = 0;
	all_col[tc-1] = 0;	
	//all_col[tc-2] = 0;

	
	//multiple status during one hour
	if (all_col[0] == 34){
		//printf ("More analysis needed.\n");
		//all_col[0] = 8;

		int shift_count = 1;

		while (all_col[shift_count] != 0){
			all_col[shift_count-1] =all_col[shift_count];
			shift_count++;
		}
		all_col[shift_count] = 0;
		all_col[shift_count-1] = 0;
		all_col[shift_count-2] = 44; 		

		//printf ("%s\n",all_col);


		char temp_status[MAX_CONFIG_LINE_LEN];
		char *temp_col;
		int mul_count = 1;

		strcpy (temp_status, all_col);
		temp_col = strtok(temp_status, ",");
		mul_status[0] = temp_col;
		//printf ("First status: |%s|\n",mul_status[0]);
		//printf ("Analyzed |%s|\n",mul_status[0]);


		//analyze first of multiple statuses
		analyze_status(mul_status[0],num_month,num_day);
		//printf ("Analyzed |%s|\n",mul_status[0]);

		do{

			
    			temp_col = strtok(NULL, ",");
    			if(temp_col)
			{	 

				mul_status[mul_count] = temp_col;
				//printf ("Status %d :|%s|\n",mul_count,mul_status[mul_count]);
				analyze_status(mul_status[mul_count],num_month,num_day);
				//printf ("Analyzed |%s|\n",mul_status[mul_count]);

				mul_count ++;
			}


  		} while(temp_col);
		
		//temp_col = strtok(temp_status, ",");
		//mul_status[1] = temp_col;
		//printf ("|%s|\n",mul_status[1]);
		
		
		
	}

	else{

		strcpy(status,all_col);
		analyze_status(status,num_month,num_day);

	}
				

	return;

		
}


int main()
{


	
	int grand_count = 1971;
	char op_file [1000];
	char wr_file [1000];
	char temp_wr_file [1000];
	mkdir("analyzed", 0700);

//NOTE ERROR IN INDENTATION
//////////////////////////////////////////////////////////////////START FILE LOOP HERE//////////////////////////////////////////////////////////////////
	while(grand_count <= 2000){

	
	//void itoa(int value, char* str, int base)
	itoa(grand_count, op_file, 10);
	strcat(op_file, ".csv");
	printf ("Reading:%s\n", op_file);

	
	
	strcpy (wr_file,"");
	strcat (wr_file, "analyzed/");
	itoa(grand_count,temp_wr_file,10);
	strcat(wr_file,temp_wr_file);
	strcat (wr_file,"_analyzed.txt");
	printf ("Writing to:%s:\n", wr_file); 



	//initializing the structures
	int blank_month = 0;
	int blank_day = 0;

	while (blank_month<12)
	{
		while (blank_day < 31)
		{
			years.months[blank_month].days[blank_day].clear = 0;
			years.months[blank_month].days[blank_day].mclear = 0;
			years.months[blank_month].days[blank_day].cloudy = 0;
			years.months[blank_month].days[blank_day].mcloudy = 0;

			//new parameters
			years.months[blank_month].days[blank_day].fog = 0;
			years.months[blank_month].days[blank_day].haze = 0;
			years.months[blank_month].days[blank_day].ths = 0;
			years.months[blank_month].days[blank_day].rain = 0;
			years.months[blank_month].days[blank_day].rain_sh = 0;
			years.months[blank_month].days[blank_day].dz = 0;
			years.months[blank_month].days[blank_day].snow = 0;
			years.months[blank_month].days[blank_day].snow_sh = 0;
			years.months[blank_month].days[blank_day].fz_rain = 0;
			years.months[blank_month].days[blank_day].fz_dz = 0;
			years.months[blank_month].days[blank_day].ice_p = 0;

			blank_day++;	
		}

		years.months[blank_month].mon_clear = 0;
		years.months[blank_month].mon_mclear = 0;
		years.months[blank_month].mon_cloudy = 0;
		years.months[blank_month].mon_mcloudy = 0;
		//new parameters
		years.months[blank_month].mon_fog = 0;
		years.months[blank_month].mon_haze = 0;
		years.months[blank_month].mon_ths = 0;
		years.months[blank_month].mon_rain = 0;
		years.months[blank_month].mon_rain_sh = 0;
		years.months[blank_month].mon_dz = 0;
		years.months[blank_month].mon_snow = 0;
		years.months[blank_month].mon_snow_sh = 0;
		years.months[blank_month].mon_fz_rain = 0;
		years.months[blank_month].mon_fz_dz = 0;
		years.months[blank_month].mon_ice_p = 0;


		blank_day = 0;
		blank_month ++;
	} 

	years.yr_clear = 0;
	years.yr_mclear = 0;
	years.yr_cloudy = 0;
	years.yr_mcloudy = 0;
	//new parameters
	years.yr_fog = 0;
	years.yr_haze = 0;
	years.yr_ths = 0;
	years.yr_rain = 0;
	years.yr_rain_sh = 0;
	years.yr_dz = 0;
	years.yr_snow = 0;
	years.yr_snow_sh = 0;
	years.yr_fz_rain = 0;
	years.yr_fz_dz = 0;
	years.yr_ice_p = 0;




	
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

			
			//if (count >= 2 && count <= 755)
			//{
				//printf ("\nline %d from records: %s\n", count, line);
				process_config_line(line);
			//}

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


	printf ("Ready to write to %s.\n",wr_file);
//_______________________________________________________________________________________________________________________________________________________
	FILE *w_file = fopen (wr_file, "w");
//_______________________________________________________________________________________________________________________________________________________


	if (w_file == NULL){
		printf ("Error writing to file\n");
		return 0;
	}

	int mcount = 0;
	int dcount = 0;

	//fprintf (w_file, "Prepared by Tanzim Mokammel.\n");

fprintf (w_file, "___________________________________________________________________________________________________________________________________________________\n");
	
	fprintf (w_file, "LEGEND\n");
	//fprintf (w_file, "_______|\n\n");
	fprintf (w_file, "CLR:Clear, CLR+:Mainly Clear, CLD:Cloudy, CLD+:Mostly Cloudy, FG:Fog, HZ:Haze, TS:Thunderstorms, RN:Rain, RNS: Rainshowers, DZ: Drizzle, SNW:Snow, SNS:Snow Showers, FZR:Freezing Rain, FZD:Freezing Drizzle, IP:Ice Pellets\n");

fprintf (w_file, "___________________________________________________________________________________________________________________________________________________\n\n");
  

	fprintf  (w_file, "YYYY\tMM\tDD\t\tCLR\tCLR+\tCLD\tCLD+\tFG\tHZ\tTS\tRN\tRNS\tDZ\tSNW\tSNS\tFZR\tFZD\tIP\n");
	
	while (mcount < 12){
		while (dcount < 31){


			//print out all analyzed information to a text file

			fprintf (w_file,"%d\t%d\t%d\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",years.year,mcount+1,dcount+1,years.months[mcount].days[dcount].clear,years.months[mcount].days[dcount].mclear,years.months[mcount].days[dcount].cloudy,years.months[mcount].days[dcount].mcloudy,years.months[mcount].days[dcount].fog,years.months[mcount].days[dcount].haze,years.months[mcount].days[dcount].ths,years.months[mcount].days[dcount].rain,years.months[mcount].days[dcount].rain_sh,years.months[mcount].days[dcount].dz,years.months[mcount].days[dcount].snow,years.months[mcount].days[dcount].snow_sh,years.months[mcount].days[dcount].fz_rain,years.months[mcount].days[dcount].fz_dz,years.months[mcount].days[dcount].ice_p);

			dcount++;  
		}


		dcount = 0;

		fprintf (w_file, "___________________________________________________________________________________________________________________________________________________\n\n");

		//display monthly sums
		fprintf (w_file, "M_Sum\t\t\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",years.months[mcount].mon_clear,years.months[mcount].mon_mclear,years.months[mcount].mon_cloudy,years.months[mcount].mon_mcloudy,years.months[mcount].mon_fog,years.months[mcount].mon_haze,years.months[mcount].mon_ths,years.months[mcount].mon_rain,years.months[mcount].mon_rain_sh,years.months[mcount].mon_dz,years.months[mcount].mon_snow,years.months[mcount].mon_snow_sh,years.months[mcount].mon_fz_rain,years.months[mcount].mon_fz_dz,years.months[mcount].mon_ice_p);

		fprintf (w_file, "___________________________________________________________________________________________________________________________________________________\n\n");
		fprintf (w_file, "___________________________________________________________________________________________________________________________________________________\n\n");
		mcount ++;
	}


	//display yearly sums
	fprintf (w_file, "Y_sum\t\t\t\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",years.yr_clear,years.yr_mclear,years.yr_cloudy,years.yr_mcloudy,years.yr_fog,years.yr_haze,years.yr_ths,years.yr_rain,years.yr_rain_sh,years.yr_dz,years.yr_snow,years.yr_snow_sh,years.yr_fz_rain,years.yr_fz_dz,years.yr_ice_p);
	


		
	fclose(file);
	fclose(w_file);

	grand_count ++;

	} ///////////////////////////end of FILE LOOP////////////////////////////////////////////////////////////////////////////////////////
	//NOTE ERROR IN INDENTATION

	return 0;
}
