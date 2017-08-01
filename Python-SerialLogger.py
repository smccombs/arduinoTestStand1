'''
	Python-SerialLogger V1.1
	This program was built for the arduinoTestStand to display the information from the teststand and save it to a file.

	1.1 - created 7-31-17 - By Shawn McCombs
	
	1.2 - created 8-1-17 - By Shawn McCombs
		*The program would not always write the data on close.
		Changed filename to current day to cut down on files every execute of program.
		Added threading to take user input and exit program with user input of 'exit'.
		Added serial write on all other inputs than CMD 'exit'.
		Added check to see if file exists before overwriting.

	1.3 - created 8-1-17 - By Shawn McCombs
		Fixed-Forgot to close the write during the header output
'''

import sys
import os
import threading
import time
import datetime
import serial
from time import sleep

def background():
	while True:
		DataLog = open(FileName, "a")
		now = datetime.datetime.now()
		now = now.strftime('%b %m %H:%M:%S')
		
		line = ser.readline().decode("utf-8").replace("\r\n", "")
		print (now+"\t\t "+line)
		sleep(.1)
		
		DataLog.write(now+"\t\t "+line+'\n')
		DataLog.close()

def UserExit():
	print ('Exiting..')
	sys.exit()

ser = serial.Serial('COM10', 9600)

now = datetime.datetime.now()
now = now.strftime('%b %m %Y')

FileName = "TestStand "+now+".txt"

if os.path.exists(FileName):
	append_write = 'a'
else:
	append_write = 'w'

DataLog = open(FileName, append_write)
print ("DateTime:\t\tUnit:\tStatus:\tCount:\tSensor:\t")
DataLog.write("DateTime:\t\tUnit:\tStatus:\tCount:\tSensor:\t\r\n")
DataLog.close()

threading1 = threading.Thread(target=background)
threading1.daemon = True
threading1.start()

while True:
	userInput = input()
	if userInput == 'exit':
		UserExit()
	else:
		ser.write(userInput.encode())
