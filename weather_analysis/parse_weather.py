import string
import re
import numbers
import itertools
import os
import sys


files = []
files = os.listdir(os.getcwd())

for file_i in files:


    if ".txt" in file_i:
        
        inFile=file(file_i, 'r')
        station=inFile.readline()[0:7]
        outFile=file(station+".tmp", 'w')
        #outFile=file(file_i+".dat", 'w')
        inFile.close()

        inFile=file(file_i, 'r')




        #outFile.write ("Year Month Day Value\n")

        for line in inFile:
            #tag = line [0:7] + ',' + line[7:11]+','+line[11:13] + ',' + line[13:16] + ','
            #station = line [0:7]
            tag = line[7:11]+' '+str(int(line[11:13]))+' '
            #print len (tag)

            i=16
            k=1
            while i + 7 < 234:

                value=line[i:i+7]
                if '-9999' in value:
                    value="-999"
                elif 'H' in value or 'I' in value or 'J' in value:
                    value='0'
                else:
                    value=str(float(value)/10)
                    
                outFile.write (tag+str(k) +' '+str(float(value))+'\n')
                
                i+=7
                k+=1

        inFile.close()
        outFile.close()

        #perform post processing
        inFile=file(station+".tmp", 'r')
        outFile=file(station+".dat", 'w')


#method 1

        first_line = inFile.readline()
        tokens=first_line.split()
        start=tokens[0]

        last_line = inFile.readlines()[-1]
        tokens=last_line.split()
        end=tokens[0]

        


        
#method 2
    
        blank="-999.0"
        month_count=1
        day_count=1
        last_year=0
        last_month=1
        
        #day_count=1
        for line in inFile:
            tokens=line.split()
            current_year=tokens[0]
            current_month=tokens[1]

            if abs(int(current_month)-last_month)>1:
                print "Missing values here:"
                print line

                
                month_count=last_month
                if last_year != 0 and int(current_year)!=last_year:
                    current_month=13
                
                while month_count < int(current_month):
                    while day_count < 32:
                        outFile.write (current_year+' '+str(month_count)+' '+str(day_count)+' '+blank+'\n')
                        day_count+=1
                    month_count+=1
                    day_count=1
                month_count=1

            last_year=int(current_year)
            last_month=int(current_month)
            outFile.write(line)


        inFile.close()
        outFile.close()

            
            
            
                


        

        

    
