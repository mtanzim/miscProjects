import string
import re
import numbers
import itertools
import os
import sys



class cost:
    
    EATGOUT = ["banh","spirit","nando","subway","tim horton", "mcdonald","soda-snack","lcbo", "cafe","bar","pho","noodle"];
    FEES=[]
    GROC =["nofrills", "metro","whole foods"]
    HLTH=["honsberger","la fitness"]
    HOUSE=["timbercreek","enercare","sparkle"]
    TRVL=["expedia","air","delta","travel"]
    INTRCOMM=["tsi","fido"]
    TRNSPRT=["shell","presto", "esso","husky","parking"]
    DNT=["mokam"]
    MSC=[]
    PET=[]
    SHP=[]
    HBY=[]

    CATEGORIES = {"Eating/Going Out": EATGOUT,
                    "Fees":FEES,
                    "Groceries":GROC,
                    "Health":HLTH,
                    "Housing": HOUSE,
                    "Travel":TRVL,
                    "Internet/Comm":INTRCOMM,
                    "Transport":TRNSPRT,
                    "Donations":DNT,
                    "Misc":MSC,
                    "Pet": PET,
                    "Shopping":SHP,
                    "Hobbies":HBY}
    
    def __init__(self, file_name, date, desc, credit, debit):
        self.file_name=file_name
        self.date=date
        self.month=date.split('/')[0]
        self.desc=desc
        self.debit=debit
        self.credit=credit
        self.delta=credit-debit
        self.category=''

    def categorize(self):
        #print (self.desc)
        for key in cost.CATEGORIES:
            for items in cost.CATEGORIES[key]:
                #print (items)
                if ( items in self.desc.lower()):
                    self.category=key;
                    break;
                #print (CATEGORIES[key])
        #print (self.desc+':'+self.category)

#MAIN FUNCTION

#files = []
files = os.listdir(os.getcwd())
costs_arr=[]
####MONTH###
MONTH_REQ='06'
####MONTH###
DATE_TOKEN=0
DESC_TOKEN=1
CREDIT_TOKEN=2
DEBIT_TOKEN=3

outFile=open(MONTH_REQ+".csv", 'w')

COST_EXCLUDE = ["TD VISA PREAUTH PYMT", "MONTHLY ACCOUNT FEE ", "QUESTRADE"]

for file_i in files:
    if ('.csv' in file_i and file_i!=str(outFile)):
        #print (file_i)
        inFile=open(file_i, 'r')
        for line in inFile:
            #print (line)
            tokens = line.split(',')
            #print (tokens[0:4])
            if (tokens[CREDIT_TOKEN] == ''): tokens[CREDIT_TOKEN]='0'
            if (tokens[DEBIT_TOKEN] == ''): tokens[DEBIT_TOKEN]='0'
            #print (float(tokens[2]))
            temp_cost_obj = cost(file_i,tokens[DATE_TOKEN],tokens[DESC_TOKEN],float(tokens[CREDIT_TOKEN]),float(tokens[DEBIT_TOKEN]))
            temp_cost_obj.categorize()
            costs_arr.append(temp_cost_obj)
        inFile.close()

costs_arr.sort(key=lambda x:x.date)

#print (CATEGEGORIES)


#printing function
outFile.write ("Date,Activity,Amount,Category\n") 
for i in costs_arr:
    includeCost=True
    for invalid_cost in COST_EXCLUDE:
        if (invalid_cost in i.desc):
            #print (invalid_cost)
            includeCost=False;
    if (i.month==MONTH_REQ and i.delta>0 and includeCost):
        outFile.write (i.date+','+str(i.desc)+','+str(i.delta)+','+i.category+'\n')
        #print(i.date+','+str(i.desc)+','+str(i.delta)+','+i.category+'\n')

outFile.close()
