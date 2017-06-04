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
        
        inFile=open(file_i, 'r')
        station=inFile.readline()[0:7]
        outFile=open(station+".tmp", 'w')
        #outFile=open(file_i+".dat", 'w')
        inFile.close()

        inFile=open(file_i, 'r')




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
        inFile=open(station+".tmp", 'r')
        outFile=open(station+".dat", 'w')


#method 1

        first_line = inFile.readline()
        tokens=first_line.split()
        start=int(tokens[0])

        last_line = inFile.readlines()[-1]
        tokens=last_line.split()
        end=int(tokens[0])

        print (start)
        print (end)


        inFile.close()
        inFile=open(station+".tmp", 'r')

        year=start
        month=1
        day=1

        found=0
        
        while year < end+1:
            while month < 13:
                while day < 32:
                    key = str(year)+' '+str(month)+' '+str(day)
                    default = str(year)+' '+str(month)+' '+str(day)+' -999.0\n'
                    for line in inFile:
                            if key in line:
                                found=1
                                break

                    if found == 0:
                        outFile.write(default)
                    else:
                        outFile.write(line)

                    found=0
                                
                    inFile.close()
                    inFile=open(station+".tmp", 'r')
                    day+=1
                month+=1
                day=1
            year+=1
            month=1
                                
                                




        inFile.close()
        outFile.close()

            
            
            
                


        

        

    
