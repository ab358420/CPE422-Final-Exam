# errors when averaging

#!/usr/bin/python 

import sys
FILE_PATH = "/home/debian/Final/Problem2/"

def readFILE ( filename, value, path=FILE_PATH ):
   fo = open( path + filename,"r")  
   fo.read(value)
   fo.close()
   return

print "Starting the Temperature Reading Python Script"
f = open(sys.argv[1]);
filename = sys.argv[1];
print " "
print "CPE 422 Final Exam"
print " "
print "File name of sensor temperatures: ",filename
temp = f.readlines();
i=int();
y=int();
y=sys.argv[2];
for y in temp:
  if y < sys.argv[2]:
    i=i+1;
print " "
print "Number of temperatures below 20 degrees C: ",i
data = [int(line) for line in temp]

#x=len(temp);
#n=sum(temp);
#avg = n/x

avg=sum(data)/len(data);

print " "
print "Average temperature: ",avg
print " "
print "End of Python Script"
