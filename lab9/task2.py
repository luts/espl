#!/usr/bin/python
import sys
import csv
lines = open( sys.argv[1], "r" ).readlines()
#create a dictionary
d = {}
d2 = {}
# skip the header line (start at 1 rather than 0)
for i in range( 1, len(lines) ):
    line = lines[i].rstrip()
    words = line.split(",")
    try:
      d[words[2]] += 1
    except KeyError:
      d[words[2]] = 1
    try:
      d2[words[2]] += ", "+str(words[0])
    except KeyError:    
      d2[words[2]] = str(words[0])
      
for grade,num in d.iteritems():
    print "Grade: " + str(grade) + " Number of students: " + str(num)
for grade,students in d2.iteritems():
    print "Grade: " + str(grade) + " Students: " + str(students)    