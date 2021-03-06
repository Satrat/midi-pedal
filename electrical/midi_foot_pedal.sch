EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title "Teensy 3.2 MIDI Foot Pedal"
Date "2020-09-21"
Rev "1"
Comp "Sara Adkins"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L teensy:Teensy3.2 U1
U 1 1 5F6A1817
P 7550 3550
F 0 "U1" H 7550 5187 60  0000 C CNN
F 1 "Teensy3.2" H 7550 5081 60  0000 C CNN
F 2 "" H 7550 2800 60  0001 C CNN
F 3 "" H 7550 2800 60  0000 C CNN
	1    7550 3550
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0109
U 1 1 5F6D5D97
P 6550 2200
F 0 "#PWR0109" H 6550 1950 50  0001 C CNN
F 1 "Earth" H 6550 2050 50  0001 C CNN
F 2 "" H 6550 2200 50  0001 C CNN
F 3 "~" H 6550 2200 50  0001 C CNN
	1    6550 2200
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R4
U 1 1 5F6C53B1
P 6200 3750
F 0 "R4" H 6268 3796 50  0000 L CNN
F 1 "220" H 6268 3705 50  0000 L CNN
F 2 "" V 6240 3740 50  0001 C CNN
F 3 "~" H 6200 3750 50  0001 C CNN
	1    6200 3750
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0104
U 1 1 5F6CC5B3
P 6200 4600
F 0 "#PWR0104" H 6200 4350 50  0001 C CNN
F 1 "Earth" H 6200 4450 50  0001 C CNN
F 2 "" H 6200 4600 50  0001 C CNN
F 3 "~" H 6200 4600 50  0001 C CNN
	1    6200 4600
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0103
U 1 1 5F6CBEEE
P 5800 4600
F 0 "#PWR0103" H 5800 4350 50  0001 C CNN
F 1 "Earth" H 5800 4450 50  0001 C CNN
F 2 "" H 5800 4600 50  0001 C CNN
F 3 "~" H 5800 4600 50  0001 C CNN
	1    5800 4600
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0102
U 1 1 5F6CB6CB
P 5400 4600
F 0 "#PWR0102" H 5400 4350 50  0001 C CNN
F 1 "Earth" H 5400 4450 50  0001 C CNN
F 2 "" H 5400 4600 50  0001 C CNN
F 3 "~" H 5400 4600 50  0001 C CNN
	1    5400 4600
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR0101
U 1 1 5F6CAE02
P 5000 4600
F 0 "#PWR0101" H 5000 4350 50  0001 C CNN
F 1 "Earth" H 5000 4450 50  0001 C CNN
F 2 "" H 5000 4600 50  0001 C CNN
F 3 "~" H 5000 4600 50  0001 C CNN
	1    5000 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 4400 6200 4600
Wire Wire Line
	5800 4400 5800 4600
Wire Wire Line
	5400 4400 5400 4600
Wire Wire Line
	5000 4400 5000 4600
$Comp
L Device:LED D4
U 1 1 5F6C92B1
P 6200 4250
F 0 "D4" V 6239 4132 50  0000 R CNN
F 1 "LED" V 6148 4132 50  0000 R CNN
F 2 "" H 6200 4250 50  0001 C CNN
F 3 "~" H 6200 4250 50  0001 C CNN
	1    6200 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D3
U 1 1 5F6C866F
P 5800 4250
F 0 "D3" V 5839 4132 50  0000 R CNN
F 1 "LED" V 5748 4132 50  0000 R CNN
F 2 "" H 5800 4250 50  0001 C CNN
F 3 "~" H 5800 4250 50  0001 C CNN
	1    5800 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D2
U 1 1 5F6C78AF
P 5400 4250
F 0 "D2" V 5439 4132 50  0000 R CNN
F 1 "LED" V 5348 4132 50  0000 R CNN
F 2 "" H 5400 4250 50  0001 C CNN
F 3 "~" H 5400 4250 50  0001 C CNN
	1    5400 4250
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D1
U 1 1 5F6C66CF
P 5000 4250
F 0 "D1" V 5039 4132 50  0000 R CNN
F 1 "LED" V 4948 4132 50  0000 R CNN
F 2 "" H 5000 4250 50  0001 C CNN
F 3 "~" H 5000 4250 50  0001 C CNN
	1    5000 4250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6200 3900 6200 4100
Wire Wire Line
	5800 3900 5800 4100
Wire Wire Line
	5400 3900 5400 4100
Wire Wire Line
	5000 3900 5000 4100
$Comp
L Device:R_US R3
U 1 1 5F6C4CDB
P 5800 3750
F 0 "R3" H 5868 3796 50  0000 L CNN
F 1 "220" H 5868 3705 50  0000 L CNN
F 2 "" V 5840 3740 50  0001 C CNN
F 3 "~" H 5800 3750 50  0001 C CNN
	1    5800 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R2
U 1 1 5F6C44C1
P 5400 3750
F 0 "R2" H 5468 3796 50  0000 L CNN
F 1 "220" H 5468 3705 50  0000 L CNN
F 2 "" V 5440 3740 50  0001 C CNN
F 3 "~" H 5400 3750 50  0001 C CNN
	1    5400 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R1
U 1 1 5F6C3EC9
P 5000 3750
F 0 "R1" H 5068 3796 50  0000 L CNN
F 1 "220" H 5068 3705 50  0000 L CNN
F 2 "" V 5040 3740 50  0001 C CNN
F 3 "~" H 5000 3750 50  0001 C CNN
	1    5000 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3300 6200 3600
Wire Wire Line
	6550 3300 6200 3300
Wire Wire Line
	6550 3100 5800 3100
Wire Wire Line
	5800 3100 5800 3600
Wire Wire Line
	6550 2900 5400 2900
Wire Wire Line
	5400 2900 5400 3600
Wire Wire Line
	6550 2700 5000 2700
Wire Wire Line
	5000 2700 5000 3600
$Comp
L Switch:SW_SPST SW4
U 1 1 5F73FA71
P 4450 4100
F 0 "SW4" V 4404 4198 50  0000 L CNN
F 1 "SW_SPST" V 4495 4198 50  0000 L CNN
F 2 "" H 4450 4100 50  0001 C CNN
F 3 "~" H 4450 4100 50  0001 C CNN
	1    4450 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 4300 4450 4600
$Comp
L power:Earth #PWR?
U 1 1 5F741FD5
P 4450 4600
F 0 "#PWR?" H 4450 4350 50  0001 C CNN
F 1 "Earth" H 4450 4450 50  0001 C CNN
F 2 "" H 4450 4600 50  0001 C CNN
F 3 "~" H 4450 4600 50  0001 C CNN
	1    4450 4600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW3
U 1 1 5F742671
P 3950 4100
F 0 "SW3" V 3904 4198 50  0000 L CNN
F 1 "SW_SPST" V 3995 4198 50  0000 L CNN
F 2 "" H 3950 4100 50  0001 C CNN
F 3 "~" H 3950 4100 50  0001 C CNN
	1    3950 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	3950 4300 3950 4600
$Comp
L power:Earth #PWR?
U 1 1 5F74390B
P 3950 4600
F 0 "#PWR?" H 3950 4350 50  0001 C CNN
F 1 "Earth" H 3950 4450 50  0001 C CNN
F 2 "" H 3950 4600 50  0001 C CNN
F 3 "~" H 3950 4600 50  0001 C CNN
	1    3950 4600
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_SPST SW2
U 1 1 5F7440CA
P 3450 4100
F 0 "SW2" V 3404 4198 50  0000 L CNN
F 1 "SW_SPST" V 3495 4198 50  0000 L CNN
F 2 "" H 3450 4100 50  0001 C CNN
F 3 "~" H 3450 4100 50  0001 C CNN
	1    3450 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 4300 3450 4600
$Comp
L Switch:SW_SPST SW1
U 1 1 5F74525C
P 2950 4100
F 0 "SW1" V 2904 4198 50  0000 L CNN
F 1 "SW_SPST" V 2995 4198 50  0000 L CNN
F 2 "" H 2950 4100 50  0001 C CNN
F 3 "~" H 2950 4100 50  0001 C CNN
	1    2950 4100
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 4300 2950 4600
$Comp
L power:Earth #PWR?
U 1 1 5F7464FE
P 3450 4600
F 0 "#PWR?" H 3450 4350 50  0001 C CNN
F 1 "Earth" H 3450 4450 50  0001 C CNN
F 2 "" H 3450 4600 50  0001 C CNN
F 3 "~" H 3450 4600 50  0001 C CNN
	1    3450 4600
	1    0    0    -1  
$EndComp
$Comp
L power:Earth #PWR?
U 1 1 5F746D53
P 2950 4600
F 0 "#PWR?" H 2950 4350 50  0001 C CNN
F 1 "Earth" H 2950 4450 50  0001 C CNN
F 2 "" H 2950 4600 50  0001 C CNN
F 3 "~" H 2950 4600 50  0001 C CNN
	1    2950 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2600 4450 2600
Wire Wire Line
	4450 2600 4450 3900
Wire Wire Line
	6550 2500 3950 2500
Wire Wire Line
	3950 2500 3950 3900
Wire Wire Line
	6550 2400 3450 2400
Wire Wire Line
	3450 2400 3450 3900
Wire Wire Line
	6550 2300 2950 2300
Wire Wire Line
	2950 2300 2950 3900
$EndSCHEMATC
