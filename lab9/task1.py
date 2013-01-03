#!/usr/bin/python
import sys
import csv
lines = open( sys.argv[1], "r" ).readlines()
grade_sum = 0
total_grades = 0
print "%s" % (lines[0])
# skip the header line (start at 1 rather than 0)
for i in range( 1, len(lines) ):
    line = lines[i].rstrip()
    words = line.split(",")
    total_grades = total_grades + 1
    grade_sum = grade_sum + float(words[2])
    print "%s" % (line)
    
print "AVERAGE %f" % (grade_sum/total_grades)