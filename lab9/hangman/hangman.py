#!/usr/bin/python
import sys
import csv
import random
lines = open( sys.argv[1], "r" ).readlines()
number_of_games = 0
letter_guess = ""
while ( letter_guess != "quit" ):
  print ""
  print "*** New Game ***"
  number_of_games = number_of_games + 1
  new_word = random.choice(lines)
  user_guess = ['_'] * len(new_word)
  number_of_guess = 5
  counter = len(new_word)
  while ( number_of_guess > 0 ):
    
    print ""
    letter_guess = raw_input("Enter Letter: ")
  
    while ( len(letter_guess) != 1 and letter_guess != "quit"):
      print "Uh oh: You can only guess a single letter at a time"
      letter_guess = raw_input("Enter Letter: ")
    
    
    if ( letter_guess == "quit" ):
      break
    print "Your Guess is: ", letter_guess
    success = 0
    for i in range( 0, len(new_word) ):
      if new_word[i] == letter_guess:
	user_guess[i] = letter_guess
	success = 1
	counter = counter - 1
    
    # Check the letter we guess
    if success == 0:
      # If we guess a rong letter
      number_of_guess = number_of_guess - 1
      print "Nope " + letter_guess + "does not appear in the word!"
    else:
      # If we guess letter that does appear
      print "Great! The letter " + letter_guess + " appears in the word!"

      
    print "Steps from gallows: " + str(number_of_guess) + " , Word so far: ",
    for i in range( 0, len(new_word) ):
      print user_guess[i],
    
    # If we finish guessing the word, move on to the next one
    if (counter == 0):
      print ""
      print "************************************"
      print "************************************"
      print "************************************"
      print "****** Mazal Tov! You got it *******"
      print "************************************"
      print "************************************"
      print "************************************"
      break
      
    # If we run out of guess
    if (number_of_guess == 0):
      print ""
      print "** Uh oh: you've run out of steps. You're on the platform.. and <SNAP!>"
      print "** The word you were trying to guess was: " + new_word
      break    
