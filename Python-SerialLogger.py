'''
	Python-SerialLogger V1.1
	This program was built for the arduinoTestStand to display the information from the teststand and save it to a file.

	1.1 - created 8-1-17 - By Shawn McCombs
'''

import sys
import os
import time
import datetime
import serial
from time import sleep

now = datetime.datetime.now()
now = now.strftime('%b %m %Y %H-%M-%S')

ser = serial.Serial('COM10', 9600)
DataLog = open("TestStand "+now+".txt", "w")

print ("DateTime:\t\tUnit:\tStatus:\tCount:\tSensor:\t")
DataLog.write("DateTime:\t\tUnit:\tStatus:\tCount:\tSensor:\t\r\n")

while True:
	now = datetime.datetime.now()
	now = now.strftime('%b %m %H:%M:%S')
	
	line = ser.readline().decode("utf-8").replace("b'", "").replace("\r\n", "")
	print (now+"\t\t "+line)
	sleep(.1)
	
	DataLog.write(now+"\t\t "+line+'\n')
DataLog.close()
