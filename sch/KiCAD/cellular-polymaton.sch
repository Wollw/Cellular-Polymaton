EESchema Schematic File Version 2  date Wed 29 Feb 2012 04:03:13 PM PST
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:myparts
EELAYER 43  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "1 mar 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
NoConn ~ 2700 1200
Connection ~ 1800 1100
Wire Wire Line
	1300 1200 1800 1200
Wire Wire Line
	1800 1200 1800 1100
Wire Wire Line
	1800 1100 1800 1100
Wire Wire Line
	1800 1100 1800 800 
Wire Wire Line
	4400 2300 4400 2400
Wire Wire Line
	4400 2400 3350 2400
Wire Wire Line
	4000 1800 4000 1900
Wire Wire Line
	2700 1400 2950 1400
Connection ~ 4000 1400
Wire Wire Line
	2700 1800 2700 1900
Wire Wire Line
	2700 1900 3350 1900
Wire Wire Line
	3350 1900 4000 1900
Connection ~ 3350 1900
Wire Wire Line
	3350 2600 3350 2400
Wire Wire Line
	3350 2400 3350 1900
Connection ~ 3350 2400
Wire Wire Line
	1300 1100 1800 1100
Connection ~ 1800 1100
Wire Wire Line
	3750 1400 4000 1400
Wire Wire Line
	4000 1400 4400 1400
Wire Wire Line
	4400 1400 4800 1400
Connection ~ 4400 1400
Text Notes 10650 7650 0    60   ~ 0
A
Text Notes 7350 7550 0    60   ~ 0
Cellular Polymaton
Text Label 4800 1400 2    60   ~ 0
5V
$Comp
L GND #PWR?
U 1 1 4F4EB853
P 1800 800
F 0 "#PWR?" H 1800 800 30  0001 C CNN
F 1 "GND" H 1800 730 30  0001 C CNN
	1    1800 800 
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 4F4EB6FA
P 3350 2600
F 0 "#PWR?" H 3350 2600 30  0001 C CNN
F 1 "GND" H 3350 2530 30  0001 C CNN
	1    3350 2600
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P?
U 1 1 4F4EB608
P 4500 7250
F 0 "P?" V 4450 7250 40  0000 C CNN
F 1 "CONN_2" V 4550 7250 40  0000 C CNN
	1    4500 7250
	1    0    0    -1  
$EndComp
$Comp
L SWITCH_INV SW?
U 1 1 4F4EB5A2
P 2200 1300
F 0 "SW?" H 2000 1450 50  0000 C CNN
F 1 "SWITCH_INV" H 2050 1150 50  0000 C CNN
	1    2200 1300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 4F4EB56D
P 4400 1650
F 0 "R?" V 4480 1650 50  0000 C CNN
F 1 "R" V 4400 1650 50  0000 C CNN
	1    4400 1650
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 4F4EB521
P 5800 4000
F 0 "R?" V 5880 4000 50  0000 C CNN
F 1 "R" V 5800 4000 50  0000 C CNN
	1    5800 4000
	1    0    0    -1  
$EndComp
$Comp
L CONN_3 K?
U 1 1 4F4EB513
P 950 1200
F 0 "K?" V 900 1200 50  0000 C CNN
F 1 "CONN_3" V 1000 1200 40  0000 C CNN
	1    950  1200
	-1   0    0    1   
$EndComp
$Comp
L LED D?
U 1 1 4F4EB4F5
P 4400 2100
F 0 "D?" H 4400 2200 50  0000 C CNN
F 1 "LED" H 4400 2000 50  0000 C CNN
	1    4400 2100
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 4F4EB4EF
P 2000 7300
F 0 "C?" H 2050 7400 50  0000 L CNN
F 1 "C" H 2050 7200 50  0000 L CNN
	1    2000 7300
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F4EB4ED
P 1400 7250
F 0 "C?" H 1450 7350 50  0000 L CNN
F 1 "C" H 1450 7150 50  0000 L CNN
	1    1400 7250
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F4EB4EB
P 950 7250
F 0 "C?" H 1000 7350 50  0000 L CNN
F 1 "C" H 1000 7150 50  0000 L CNN
	1    950  7250
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F4EB4E9
P 1900 6600
F 0 "C?" H 1950 6700 50  0000 L CNN
F 1 "C" H 1950 6500 50  0000 L CNN
	1    1900 6600
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F4EB4E7
P 1350 6700
F 0 "C?" H 1400 6800 50  0000 L CNN
F 1 "C" H 1400 6600 50  0000 L CNN
	1    1350 6700
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4F4EB4DE
P 900 6700
F 0 "C?" H 950 6800 50  0000 L CNN
F 1 "C" H 950 6600 50  0000 L CNN
	1    900  6700
	1    0    0    -1  
$EndComp
$Comp
L CONN_5X2 P1
U 1 1 4F4EB4CF
P 2200 3850
F 0 "P1" H 2200 4150 60  0000 C CNN
F 1 "CONN_5X2" V 2200 3850 50  0000 C CNN
	1    2200 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_5X2 P2
U 1 1 4F4EB4CE
P 2100 5050
F 0 "P2" H 2100 5350 60  0000 C CNN
F 1 "CONN_5X2" V 2100 5050 50  0000 C CNN
	1    2100 5050
	1    0    0    -1  
$EndComp
$Comp
L CONN_5X2 P3
U 1 1 4F4EB4CD
P 3350 5200
F 0 "P3" H 3350 5500 60  0000 C CNN
F 1 "CONN_5X2" V 3350 5200 50  0000 C CNN
	1    3350 5200
	1    0    0    -1  
$EndComp
$Comp
L CONN_5X2 P4
U 1 1 4F4EB4CA
P 3450 4500
F 0 "P4" H 3450 4800 60  0000 C CNN
F 1 "CONN_5X2" V 3450 4500 50  0000 C CNN
	1    3450 4500
	1    0    0    -1  
$EndComp
$Comp
L CONN_5X2 P5
U 1 1 4F4EB4C7
P 3400 3750
F 0 "P5" H 3400 4050 60  0000 C CNN
F 1 "CONN_5X2" V 3400 3750 50  0000 C CNN
	1    3400 3750
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U1
U 1 1 4F4EB4AE
P 6850 4050
F 0 "U1" H 7000 4650 70  0000 C CNN
F 1 "74HC595" H 6850 3450 70  0000 C CNN
	1    6850 4050
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U2
U 1 1 4F4EB4AC
P 6000 6800
F 0 "U2" H 6150 7400 70  0000 C CNN
F 1 "74HC595" H 6000 6200 70  0000 C CNN
	1    6000 6800
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U3
U 1 1 4F4EB4AA
P 9150 5600
F 0 "U3" H 9300 6200 70  0000 C CNN
F 1 "74HC595" H 9150 5000 70  0000 C CNN
	1    9150 5600
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U5
U 1 1 4F4EB4A9
P 9150 1750
F 0 "U5" H 9300 2350 70  0000 C CNN
F 1 "74HC595" H 9150 1150 70  0000 C CNN
	1    9150 1750
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U4
U 1 1 4F4EB4A6
P 9050 3750
F 0 "U4" H 9200 4350 70  0000 C CNN
F 1 "74HC595" H 9050 3150 70  0000 C CNN
	1    9050 3750
	1    0    0    -1  
$EndComp
$Comp
L DIODE D?
U 1 1 4F4EB43E
P 1500 1300
F 0 "D?" H 1500 1400 40  0000 C CNN
F 1 "DIODE" H 1500 1200 40  0000 C CNN
	1    1500 1300
	1    0    0    -1  
$EndComp
$Comp
L CP1 C?
U 1 1 4F4EB43A
P 4000 1600
F 0 "C?" H 4050 1700 50  0000 L CNN
F 1 "CP1" H 4050 1500 50  0000 L CNN
	1    4000 1600
	1    0    0    -1  
$EndComp
$Comp
L CP1 C?
U 1 1 4F4EB437
P 2700 1600
F 0 "C?" H 2750 1700 50  0000 L CNN
F 1 "CP1" H 2750 1500 50  0000 L CNN
	1    2700 1600
	1    0    0    -1  
$EndComp
$Comp
L LM317 U6
U 1 1 4F4EB432
P 3350 1550
F 0 "U6" H 3350 1850 60  0000 C CNN
F 1 "LM323T" H 3400 1300 60  0000 L CNN
	1    3350 1550
	1    0    0    -1  
$EndComp
$EndSCHEMATC
