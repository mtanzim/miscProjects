/* DOMINANT DAILY STATUS CALCULATIONS NOT NEEDED ANYMORE/////////////////////////////////////////////////////////////////////////////////////////////////



			//determine dominant status for the day
			int temp_clear = years.months[mcount].days[dcount].clear;
			int temp_mclear = years.months[mcount].days[dcount].mclear;
			int temp_cloudy = years.months[mcount].days[dcount].cloudy;
			int temp_mcloudy = years.months[mcount].days[dcount].mcloudy;

			strcpy (years.months[mcount].days[dcount].dom_stat, "");

			if (temp_clear == 0 && temp_mclear == 0 &&  temp_cloudy == 0 &&  temp_mcloudy == 0){
				strcpy (years.months[mcount].days[dcount].dom_stat, "BLANK OR INVALID DATA");
			}

			else { //NOTE ERROR IN INDENTATION

//----------------------------------------------------------------------------------------------------------------------------
			if (temp_clear >= temp_mclear && temp_clear >= temp_cloudy && temp_clear >= temp_mcloudy){
				strcpy (years.months[mcount].days[dcount].dom_stat, "Clear");
				years.months[mcount].monthly_clear ++;
				
				//check for duplicates of CLEAR
				if (temp_clear != 0){
					if (temp_clear == temp_mclear){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Mostly Clear");
						years.months[mcount].monthly_mclear ++;
					}
					if (temp_clear == temp_cloudy){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Cloudy");
						years.months[mcount].monthly_cloudy ++;
					}
					if (temp_clear == temp_mcloudy){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Mostly Cloudy");
						years.months[mcount].monthly_mcloudy ++;
					}
				}
					


			}

			
			else if (temp_mclear >= temp_clear && temp_mclear >= temp_cloudy && temp_mclear >= temp_mcloudy){

				strcpy (years.months[mcount].days[dcount].dom_stat, "Mainly Clear");
				years.months[mcount].monthly_mclear ++;

				//check for duplicates of CLEAR+
				if (temp_mclear != 0){
					if (temp_mclear == temp_clear){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Clear");
						years.months[mcount].monthly_clear ++;
					}
					if (temp_mclear == temp_cloudy){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Cloudy");
						years.months[mcount].monthly_cloudy ++;
					}
					if (temp_mclear == temp_mcloudy){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Mostly Cloudy");
						years.months[mcount].monthly_mcloudy ++;
					}
				}
			} 


			else if (temp_cloudy >= temp_clear && temp_cloudy >= temp_mclear && temp_cloudy >= temp_mcloudy){
				strcpy (years.months[mcount].days[dcount].dom_stat, "Cloudy");
				years.months[mcount].monthly_cloudy ++;

				//check for duplicates of CLOUDY
				if (temp_cloudy != 0){
					if (temp_cloudy == temp_clear){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Clear");
						years.months[mcount].monthly_clear ++;
					}
					if (temp_cloudy == temp_mclear){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Mainly Clear");
						years.months[mcount].monthly_mclear ++;
					}
					if (temp_cloudy == temp_mcloudy){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Mostly Cloudy");
						years.months[mcount].monthly_mcloudy ++;
					}
				}


			}
			else if (temp_mcloudy > temp_clear && temp_mcloudy > temp_mclear && temp_mcloudy > temp_cloudy){
				strcpy (years.months[mcount].days[dcount].dom_stat, "Mostly Cloudy");
				years.months[mcount].monthly_mcloudy ++;

				//check for duplicates of CLOUDY+
				if (temp_cloudy != 0){
					if (temp_mcloudy == temp_clear){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Clear");
						years.months[mcount].monthly_clear ++;
					}
					if (temp_mcloudy == temp_mclear){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Mainly Clear");
						years.months[mcount].monthly_mclear ++;
					}
					if (temp_mcloudy == temp_cloudy){
						strcat (years.months[mcount].days[dcount].dom_stat, ",Cloudy");
						years.months[mcount].monthly_cloudy ++;
					}
				}

			}

			else
			{
				strcpy (years.months[mcount].days[dcount].dom_stat, "Perform Manual Check");
			}
			}//NOTE ERROR IN INDENTATION

//--------------------------------------------------------------------------------------------------------------------------------------*/
//
///
///
///
/
///
////




/* DOMINANT MonthLY STATUS CALCULATIONS NOT NEEDED ANYMORE//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////calculate and display monthly data//////////////////////////////////////////////////////

			//determine dominant status for the MONTH

			int temp_clear = years.months[mcount].monthly_clear;
			int temp_mclear = years.months[mcount].monthly_mclear;
			int temp_cloudy = years.months[mcount].monthly_cloudy;
			int temp_mcloudy = years.months[mcount].monthly_mcloudy;

			strcpy (years.months[mcount].m_dom_stat, "");

			if (temp_clear == 0 && temp_mclear == 0 &&  temp_cloudy == 0 &&  temp_mcloudy == 0){
				strcpy (years.months[mcount].m_dom_stat, "BLANK OR INVALID DATA");
			}

			else { //NOTE ERROR IN INDENTATION

//----------------------------------------------------------------------------------------------------------------------------
			if (temp_clear >= temp_mclear && temp_clear >= temp_cloudy && temp_clear >= temp_mcloudy){
				strcpy (years.months[mcount].m_dom_stat, "Clear");
				//years.months[mcount].monthly_clear ++;
				
				//check for duplicates of CLEAR
				if (temp_clear != 0){
					if (temp_clear == temp_mclear){
						strcat (years.months[mcount].m_dom_stat, ",Mostly Clear");
						//years.months[mcount].monthly_mclear ++;
					}
					if (temp_clear == temp_cloudy){
						strcat (years.months[mcount].m_dom_stat, ",Cloudy");
						//years.months[mcount].monthly_cloudy ++;
					}
					if (temp_clear == temp_mcloudy){
						strcat (years.months[mcount].m_dom_stat, ",Mostly Cloudy");
						//years.months[mcount].monthly_mcloudy ++;
					}
				}
					


			}

			
			else if (temp_mclear >= temp_clear && temp_mclear >= temp_cloudy && temp_mclear >= temp_mcloudy){

				strcpy (years.months[mcount].m_dom_stat, "Mainly Clear");
				//years.months[mcount].monthly_mclear ++;

				//check for duplicates of CLEAR+
				if (temp_mclear != 0){
					if (temp_mclear == temp_clear){
						strcat (years.months[mcount].m_dom_stat, ",Clear");
						//years.months[mcount].monthly_clear ++;
					}
					if (temp_mclear == temp_cloudy){
						strcat (years.months[mcount].m_dom_stat, ",Cloudy");
						//years.months[mcount].monthly_cloudy ++;
					}
					if (temp_mclear == temp_mcloudy){
						strcat (years.months[mcount].m_dom_stat, ",Mostly Cloudy");
						//years.months[mcount].monthly_mcloudy ++;
					}
				}
			} 


			else if (temp_cloudy >= temp_clear && temp_cloudy >= temp_mclear && temp_cloudy >= temp_mcloudy){
				strcpy (years.months[mcount].m_dom_stat, "Cloudy");
				//years.months[mcount].monthly_cloudy ++;

				//check for duplicates of CLOUDY
				if (temp_cloudy != 0){
					if (temp_cloudy == temp_clear){
						strcat (years.months[mcount].m_dom_stat, ",Clear");
						//years.months[mcount].monthly_clear ++;
					}
					if (temp_cloudy == temp_mclear){
						strcat (years.months[mcount].m_dom_stat, ",Mainly Clear");
						//years.months[mcount].monthly_mclear ++;
					}
					if (temp_cloudy == temp_mcloudy){
						strcat (years.months[mcount].m_dom_stat, ",Mostly Cloudy");
						//years.months[mcount].monthly_mcloudy ++;
					}
				}


			}
			else if (temp_mcloudy > temp_clear && temp_mcloudy > temp_mclear && temp_mcloudy > temp_cloudy){
				strcpy (years.months[mcount].m_dom_stat, "Mostly Cloudy");
				//years.months[mcount].monthly_mcloudy ++;

				//check for duplicates of CLOUDY+
				if (temp_cloudy != 0){
					if (temp_mcloudy == temp_clear){
						strcat (years.months[mcount].m_dom_stat, ",Clear");
						//years.months[mcount].monthly_clear ++;
					}
					if (temp_mcloudy == temp_mclear){
						strcat (years.months[mcount].m_dom_stat, ",Mainly Clear");
						//years.months[mcount].monthly_mclear ++;
					}
					if (temp_mcloudy == temp_cloudy){
						strcat (years.months[mcount].m_dom_stat, ",Cloudy");
						//years.months[mcount].monthly_cloudy ++;
					}
				}

			}

			else
			{
				strcpy (years.months[mcount].m_dom_stat, "Perform Manual Check");
			}
			}//NOTE ERROR IN INDENTATION














		fprintf (w_file,"------------------------------------------------------------------------------------\n");
		fprintf (w_file, "Dominant Status for month %d is: %s\n",mcount+1, years.months[mcount].m_dom_stat);
 		fprintf (w_file,"------------------------------------------------------------------------------------\n\n");

//////////////////////////////////////////////end of monthly analysis/////////////////////////////////////////////////////////////////////////////////*/





























