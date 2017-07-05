import string
import re
import numbers
import itertools
import os
import sys


files = []
costs_arr=[]
files = os.listdir(os.getcwd())

MONTH_REQ='06'
outFile=open(MONTH_REQ+".csv", 'w')
    

class cost:
    def __init__(self, file_name, date, desc, credit, debit):
        self.file_name=file_name
        self.date=date
        self.month=date.split('/')[0]
        self.desc=desc
        self.debit=debit
        self.credit=credit
        self.delta=credit-debit

    

for file_i in files:
    if ('.csv' in file_i):
        #print (file_i)
        inFile=open(file_i, 'r')
        for line in inFile:
            #print (line)
            tokens = line.split(',')
            #print (tokens[0:4])
            if (tokens[2] == ''): tokens[2]='0'
            if (tokens[3] == ''): tokens[3]='0'
            #print (float(tokens[2]))
            temp_cost_obj = cost(file_i,tokens[0],tokens[1],float(tokens[2]),float(tokens[3]))
            costs_arr.append(temp_cost_obj)
        inFile.close()

costs_arr.sort(key=lambda x:x.date)

for i in costs_arr:
    if (i.month==MONTH_REQ):
        outFile.write (i.date+','+str(i.desc)+','+str(i.delta)+'\n')

outFile.close()
