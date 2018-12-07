EESchema Schematic File Version 4
LIBS:eduArdu_Rev_A-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	2100 2900 1750 2900
Wire Wire Line
	2100 2700 1550 2700
Wire Wire Line
	2100 3200 1550 3200
Wire Wire Line
	2000 5900 1450 5900
Text GLabel 1550 2900 0    50   Output ~ 0
LEDMSCK
Text GLabel 1550 2700 0    50   Output ~ 0
LEDMDATA
Text GLabel 1400 3200 0    50   Output ~ 0
LEDMLATCH
Text GLabel 1450 5900 0    50   Output ~ 0
GND
Text GLabel 1550 2100 0    50   Output ~ 0
LEDMVDD
Text Label 2000 2900 2    50   ~ 0
SCK
Text Label 2000 2700 2    50   ~ 0
MOSI
Text Label 2000 3200 2    50   ~ 0
D11
Text Label 2000 2100 2    50   ~ 0
VBAT
Text Label 1900 5900 2    50   ~ 0
GND
$Comp
L eduArdu_Rev_A:74HC595-74xx-eduBoard_Rev_A-rescue U5
U 1 1 5BB329A9
P 2500 3100
F 0 "U5" H 2500 3878 50  0000 C CNN
F 1 "74HC595" H 2500 3787 50  0000 C CNN
F 2 "OLIMEX_IC-FP:SO-16" H 2500 3100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2500 3100 50  0001 C CNN
	1    2500 3100
	1    0    0    -1  
$EndComp
$Comp
L eduArdu_Rev_A:74HC595-74xx-eduBoard_Rev_A-rescue U6
U 1 1 5BB32AA0
P 2500 5100
F 0 "U6" H 2500 5878 50  0000 C CNN
F 1 "74HC595" H 2500 5787 50  0000 C CNN
F 2 "OLIMEX_IC-FP:SO-16" H 2500 5100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74hc595.pdf" H 2500 5100 50  0001 C CNN
	1    2500 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 3000 1650 3000
Wire Wire Line
	2100 5000 1650 5000
Wire Wire Line
	1650 5000 1650 3000
Connection ~ 1650 3000
Wire Wire Line
	1650 3000 1550 3000
Wire Wire Line
	2100 4900 1750 4900
Wire Wire Line
	1750 4900 1750 2900
Connection ~ 1750 2900
Wire Wire Line
	1750 2900 1550 2900
Wire Wire Line
	1550 3200 1550 5200
Wire Wire Line
	1550 5200 2100 5200
Connection ~ 1550 3200
Wire Wire Line
	1550 3200 1400 3200
Wire Wire Line
	2900 3600 3000 3600
Wire Wire Line
	3000 3600 3000 4100
Wire Wire Line
	3000 4100 1950 4100
Wire Wire Line
	1950 4100 1950 4700
Wire Wire Line
	1950 4700 2100 4700
Wire Wire Line
	2100 3300 2000 3300
Wire Wire Line
	2000 3300 2000 3850
Wire Wire Line
	2000 3850 2500 3850
Wire Wire Line
	2500 3850 2500 3800
$Comp
L OLIMEX_Power:GND #PWR031
U 1 1 5BB33398
P 2000 3900
F 0 "#PWR031" H 2000 3650 50  0001 C CNN
F 1 "GND" H 2005 3727 50  0000 C CNN
F 2 "" H 2000 3900 60  0000 C CNN
F 3 "" H 2000 3900 60  0000 C CNN
	1    2000 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 3900 2000 3850
Connection ~ 2000 3850
Wire Wire Line
	2000 5900 2500 5900
$Comp
L OLIMEX_Power:GND #PWR034
U 1 1 5BB33653
P 2000 5950
F 0 "#PWR034" H 2000 5700 50  0001 C CNN
F 1 "GND" H 2005 5777 50  0000 C CNN
F 2 "" H 2000 5950 60  0000 C CNN
F 3 "" H 2000 5950 60  0000 C CNN
	1    2000 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 5950 2000 5900
Connection ~ 2000 5900
Wire Wire Line
	2100 5300 2000 5300
Wire Wire Line
	2000 5300 2000 5900
Wire Wire Line
	2500 5800 2500 5900
Wire Wire Line
	2500 2100 2500 2500
Wire Wire Line
	1550 2100 1700 2100
Wire Wire Line
	2500 2100 3100 2100
Wire Wire Line
	3100 2100 3100 4250
Wire Wire Line
	3100 4250 2500 4250
Wire Wire Line
	2500 4250 2500 4500
Connection ~ 2500 2100
$Comp
L eduArdu_Rev_A-rescue:C-Device-eduBoard_Rev_A-rescue C22
U 1 1 5BB35403
P 1700 2300
F 0 "C22" H 1815 2346 50  0000 L CNN
F 1 "1uF" H 1815 2255 50  0000 L CNN
F 2 "OLIMEX_RLC-FP:C_0603_5MIL_DWS" H 1738 2150 50  0001 C CNN
F 3 "~" H 1700 2300 50  0001 C CNN
	1    1700 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 2150 1700 2100
Connection ~ 1700 2100
Wire Wire Line
	1700 2100 2500 2100
Wire Wire Line
	1700 2450 1700 2500
$Comp
L OLIMEX_Power:GND #PWR030
U 1 1 5BB36E5E
P 1700 2500
F 0 "#PWR030" H 1700 2250 50  0001 C CNN
F 1 "GND" H 1600 2500 50  0000 C CNN
F 2 "" H 1700 2500 60  0000 C CNN
F 3 "" H 1700 2500 60  0000 C CNN
	1    1700 2500
	1    0    0    -1  
$EndComp
$Comp
L eduArdu_Rev_A:ULN2003AD U7
U 1 1 5BB36EDB
P 4200 2950
F 0 "U7" H 4200 3525 50  0000 C CNN
F 1 "ULN2003AD" H 4200 3434 50  0000 C CNN
F 2 "OLIMEX_IC-FP:SO-16" H 4200 2950 50  0001 C CNN
F 3 "" H 4200 2950 50  0001 C CNN
	1    4200 2950
	1    0    0    1   
$EndComp
Wire Wire Line
	2900 2700 3900 2700
Wire Wire Line
	2900 2800 3900 2800
Wire Wire Line
	2900 2900 3900 2900
Wire Wire Line
	2900 3000 3900 3000
Wire Wire Line
	2900 3100 3900 3100
Wire Wire Line
	2900 3200 3900 3200
Wire Wire Line
	2900 3300 3900 3300
$Comp
L OLIMEX_Power:GND #PWR035
U 1 1 5BB3A58E
P 3800 4450
F 0 "#PWR035" H 3800 4200 50  0001 C CNN
F 1 "GND" H 3805 4277 50  0000 C CNN
F 2 "" H 3800 4450 60  0000 C CNN
F 3 "" H 3800 4450 60  0000 C CNN
	1    3800 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 2100 3100 2100
Connection ~ 3100 2100
Wire Wire Line
	3650 3400 2900 3400
Text GLabel 1550 3000 0    50   Input ~ 0
RESET
$Comp
L eduArdu_Rev_A:RA1206_(4x0603)_4B8_XXX RM1
U 1 1 5BB631D5
P 3400 4850
F 0 "RM1" H 3400 5150 60  0000 C CNN
F 1 "RA1206_(4x0603)_4B8_22R" H 3600 3900 60  0000 C CNN
F 2 "OLIMEX_RLC-FP:RA1206_(4X0603)_4B8_mine" H 3450 4750 60  0001 C CNN
F 3 "" H 3450 4750 60  0000 C CNN
	1    3400 4850
	1    0    0    1   
$EndComp
Wire Wire Line
	2900 4700 3200 4700
Wire Wire Line
	2900 4800 3200 4800
Wire Wire Line
	2900 4900 3200 4900
Wire Wire Line
	2900 5000 3200 5000
$Comp
L eduArdu_Rev_A:RA1206_(4x0603)_4B8_XXX RM2
U 1 1 5BB68FC7
P 3400 5250
F 0 "RM2" H 3400 4950 60  0000 C CNN
F 1 "RA1206_(4x0603)_4B8_22R" H 3600 4850 60  0000 C CNN
F 2 "OLIMEX_RLC-FP:RA1206_(4X0603)_4B8_mine" H 3450 5150 60  0001 C CNN
F 3 "" H 3450 5150 60  0000 C CNN
	1    3400 5250
	1    0    0    1   
$EndComp
Wire Wire Line
	2900 5100 3200 5100
Wire Wire Line
	2900 5200 3200 5200
Wire Wire Line
	2900 5300 3200 5300
Wire Wire Line
	2900 5400 3200 5400
Wire Wire Line
	3600 4700 4150 4700
Wire Wire Line
	3600 4800 4150 4800
Wire Wire Line
	3600 4900 4150 4900
Wire Wire Line
	3600 5000 4150 5000
Wire Wire Line
	3600 5100 4150 5100
Wire Wire Line
	3600 5200 4150 5200
Wire Wire Line
	3600 5300 4150 5300
Wire Wire Line
	3600 5400 4150 5400
Text Label 3950 4700 0    50   ~ 0
R1
Text Label 3950 4800 0    50   ~ 0
R2
Text Label 3950 4900 0    50   ~ 0
R3
Text Label 3950 5000 0    50   ~ 0
R4
Text Label 3950 5100 0    50   ~ 0
R5
Text Label 3950 5200 0    50   ~ 0
R6
Text Label 3950 5300 0    50   ~ 0
R7
Text Label 3950 5400 0    50   ~ 0
R8
$Comp
L eduArdu_Rev_A:ULN2003AD U8
U 1 1 5BB746B8
P 4200 4050
F 0 "U8" H 4200 4625 50  0000 C CNN
F 1 "ULN2003AD" H 4200 4534 50  0000 C CNN
F 2 "OLIMEX_IC-FP:SO-16" H 4200 4050 50  0001 C CNN
F 3 "" H 4200 4050 50  0001 C CNN
	1    4200 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3400 3650 3700
Wire Wire Line
	3650 3700 3900 3700
Wire Wire Line
	4500 3700 4800 3700
Wire Wire Line
	4800 3400 4800 3700
Wire Wire Line
	4650 4400 4500 4400
Wire Wire Line
	3900 4400 3800 4400
Wire Wire Line
	3800 4400 3800 4450
Connection ~ 3800 4400
Wire Wire Line
	3900 3800 3450 3800
Wire Wire Line
	3900 3900 3450 3900
Wire Wire Line
	4500 3800 5200 3800
Wire Wire Line
	4500 3900 5200 3900
Text GLabel 5200 3800 2    50   Input ~ 0
IRLED
Text GLabel 5200 3900 2    50   Input ~ 0
BUZZER
Text GLabel 3450 3800 0    50   Input ~ 0
IRTX
Text GLabel 3450 3900 0    50   Input ~ 0
D6
Wire Wire Line
	6650 5300 7200 5300
Wire Wire Line
	6650 4800 7200 4800
Wire Wire Line
	4900 5300 5450 5300
Wire Wire Line
	6650 5000 7200 5000
Wire Wire Line
	4900 4600 5450 4600
Wire Wire Line
	4900 5200 5450 5200
Wire Wire Line
	4900 4700 5450 4700
Wire Wire Line
	4900 5000 5450 5000
Text Label 7000 5300 0    50   ~ 0
R1
Text Label 7000 4800 0    50   ~ 0
R2
Text Label 5250 5300 0    50   ~ 0
R3
Text Label 7000 5000 0    50   ~ 0
R4
Text Label 5250 4600 0    50   ~ 0
R5
Text Label 5250 5200 0    50   ~ 0
R6
Text Label 5250 4700 0    50   ~ 0
R7
Text Label 5250 5000 0    50   ~ 0
R8
$Comp
L eduArdu_Rev_A:GYX1588AB-RESCUE-BADGE-LED8x8_Rev.A U9
U 1 1 5BD0F4CC
P 6050 4950
F 0 "U9" V 5413 4950 60  0000 C CNN
F 1 "GYX1588AB" V 5519 4950 60  0000 C CNN
F 2 "OLIMEX_LEDs-FP:GYX1588AB" H 6050 4950 60  0001 C CNN
F 3 "" H 6050 4950 60  0000 C CNN
	1    6050 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	4500 2700 5500 2700
Wire Wire Line
	4500 2800 5500 2800
Wire Wire Line
	4500 2900 5500 2900
Wire Wire Line
	4500 3000 5500 3000
Wire Wire Line
	4500 3100 5500 3100
Wire Wire Line
	4500 3200 5500 3200
Wire Wire Line
	4500 3300 5500 3300
Text Label 5000 2700 0    50   ~ 0
C1
Text Label 5000 2800 0    50   ~ 0
C2
Text Label 5000 2900 0    50   ~ 0
C3
Text Label 5000 3000 0    50   ~ 0
C4
Text Label 5000 3100 0    50   ~ 0
C5
Text Label 5000 3200 0    50   ~ 0
C6
Text Label 5000 3300 0    50   ~ 0
C7
Text Label 5000 3400 0    50   ~ 0
C8
Wire Wire Line
	4800 3400 5500 3400
Wire Wire Line
	6650 4900 7200 4900
Wire Wire Line
	4900 4800 5450 4800
Wire Wire Line
	4900 4900 5450 4900
Wire Wire Line
	6650 5200 7200 5200
Wire Wire Line
	4900 5100 5450 5100
Wire Wire Line
	6650 5100 7200 5100
Wire Wire Line
	6650 4700 7200 4700
Text Label 6850 4900 0    50   ~ 0
C1
Text Label 5100 4800 0    50   ~ 0
C2
Text Label 5100 4900 0    50   ~ 0
C3
Text Label 6850 5200 0    50   ~ 0
C4
Text Label 5100 5100 0    50   ~ 0
C5
Text Label 6850 5100 0    50   ~ 0
C6
Text Label 6850 4700 0    50   ~ 0
C7
Text Label 6850 4600 0    50   ~ 0
C8
Wire Wire Line
	6650 4600 7200 4600
Wire Wire Line
	4650 2100 4650 2600
Wire Wire Line
	4500 2600 4650 2600
Connection ~ 4650 2600
Wire Wire Line
	4650 2600 4650 4400
Wire Wire Line
	3800 2600 3900 2600
Wire Wire Line
	3800 2600 3800 4400
NoConn ~ 3900 4000
NoConn ~ 3900 4100
NoConn ~ 3900 4200
NoConn ~ 3900 4300
NoConn ~ 4500 4000
NoConn ~ 4500 4100
NoConn ~ 4500 4200
NoConn ~ 4500 4300
NoConn ~ 2900 5600
$EndSCHEMATC
