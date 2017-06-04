import string
import re
import numbers
import itertools
import os
import shutil
import sys




def fill_in(year, start, end, value):

    month_count=start
    day_count=1
    while month_count < end:
        while day_count < 32:
            outFile.write (str(year)+' '+str(month_count)+' '+str(day_count)+' '+value+'\n')
            day_count+=1
        month_count+=1
        day_count=1
            

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


        first_line = inFile.readline()
        tokens=first_line.split()
        last_year=int(tokens[0])
        file_length=len(inFile.readlines())

        print file_length
        
        inFile.close()

        inFile=file(station+".tmp", 'r')

        
        outFile=file(station+".dat", 'w')


    
        blank="-999.0"
        last_month=1
        
        #day_count=1
        line_count=0
        for line in inFile:
            tokens=line.split()
            current_year=int(tokens[0])
            current_month=int(tokens[1])

            if current_year == last_year:
                if abs(int(current_month)-last_month)>1:
                    fill_in(current_year, last_month, current_month, blank)
            else:
                if last_month!=12:
                    fill_in(last_year, last_month, 13, blank)

                if current_month!=1:
                    fill_in(current_year, 1, current_month, blank)

            
                
                
            outFile.write(line)
            last_month=current_month
            last_year=current_year

            if line_count == file_length:
                if current_month!=12:
                    print current_month
                    print current_year
                    print line
                    fill_in(current_year, current_month+1, 13, blank)

            line_count+=1

            
        

        inFile.close()
        outFile.close()

        src=os.getcwd()+"\\"+station + ".tmp"
        dst=os.getcwd()+"\\tmp"
        if os.path.isfile(dst+"\\"+station + ".tmp"):
            os.remove(dst+"\\"+station + ".tmp")
        shutil.move(src, dst)
        
        print src
        print dst

        src=os.getcwd()+"\\"+station + ".dat"
        dst=os.getcwd()+"\\dat"
        if os.path.isfile(dst+"\\"+station + ".dat"):
            os.remove(dst+"\\"+station + ".dat")
        
        shutil.move(src, dst)
        print src
        print dst

        
        
        



            
            
            
                


        

        

    
