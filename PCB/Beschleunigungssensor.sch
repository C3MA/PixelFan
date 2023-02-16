EESchema Schematic File Version 4
LIBS:PixelFan-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 6400 3500 2    50   Output ~ 0
COMP_OUT
$Comp
L Device:R R16
U 1 1 5D721665
P 6200 3200
F 0 "R16" H 6270 3246 50  0000 L CNN
F 1 "10k" H 6270 3155 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6130 3200 50  0001 C CNN
F 3 "~" H 6200 3200 50  0001 C CNN
	1    6200 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3350 6200 3500
Connection ~ 6200 3500
Wire Wire Line
	6200 3500 6400 3500
$Comp
L power:+3.3V #PWR046
U 1 1 5D721DB9
P 6200 2900
F 0 "#PWR046" H 6200 2750 50  0001 C CNN
F 1 "+3.3V" H 6215 3073 50  0000 C CNN
F 2 "" H 6200 2900 50  0001 C CNN
F 3 "" H 6200 2900 50  0001 C CNN
	1    6200 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 2900 6200 3050
$Comp
L LM397:LM397 U11
U 2 1 5D714D57
P 5500 2000
F 0 "U11" H 5500 2367 50  0000 C CNN
F 1 "LM397" H 5500 2276 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 5500 2000 50  0001 C CNN
F 3 "" H 5500 2000 50  0001 C CNN
	2    5500 2000
	1    0    0    -1  
$EndComp
$Comp
L LM397:LM397 U11
U 1 1 5D715340
P 5650 3500
F 0 "U11" H 5708 3546 50  0000 L CNN
F 1 "LM397" H 5708 3455 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 5650 3500 50  0001 C CNN
F 3 "" H 5650 3500 50  0001 C CNN
	1    5650 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR041
U 1 1 5D717105
P 3250 3000
F 0 "#PWR041" H 3250 2750 50  0001 C CNN
F 1 "GND" H 3255 2827 50  0000 C CNN
F 2 "" H 3250 3000 50  0001 C CNN
F 3 "" H 3250 3000 50  0001 C CNN
	1    3250 3000
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR045
U 1 1 5D7177B8
P 5500 2450
F 0 "#PWR045" H 5500 2200 50  0001 C CNN
F 1 "GND" H 5505 2277 50  0000 C CNN
F 2 "" H 5500 2450 50  0001 C CNN
F 3 "" H 5500 2450 50  0001 C CNN
	1    5500 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR044
U 1 1 5D7184DE
P 5500 1550
F 0 "#PWR044" H 5500 1400 50  0001 C CNN
F 1 "+5V" H 5515 1723 50  0000 C CNN
F 2 "" H 5500 1550 50  0001 C CNN
F 3 "" H 5500 1550 50  0001 C CNN
	1    5500 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5500 2350 5500 2400
$Comp
L Device:R R14
U 1 1 5D7190CC
P 4400 3150
F 0 "R14" H 4470 3196 50  0000 L CNN
F 1 "10k" H 4470 3105 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4330 3150 50  0001 C CNN
F 3 "~" H 4400 3150 50  0001 C CNN
	1    4400 3150
	1    0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 5D7198C6
P 4400 3900
F 0 "R15" H 4470 3946 50  0000 L CNN
F 1 "6k2" H 4470 3855 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4330 3900 50  0001 C CNN
F 3 "~" H 4400 3900 50  0001 C CNN
	1    4400 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 3300 4400 3600
Connection ~ 4400 3600
Wire Wire Line
	4400 3600 4400 3750
$Comp
L power:GND #PWR043
U 1 1 5D71A2E3
P 4400 4150
F 0 "#PWR043" H 4400 3900 50  0001 C CNN
F 1 "GND" H 4405 3977 50  0000 C CNN
F 2 "" H 4400 4150 50  0001 C CNN
F 3 "" H 4400 4150 50  0001 C CNN
	1    4400 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 2900 4400 3000
Wire Wire Line
	4400 4050 4400 4100
$Comp
L Device:C C32
U 1 1 5D71B3DA
P 3000 3000
F 0 "C32" H 3115 3046 50  0000 L CNN
F 1 "100n" H 3115 2955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3038 2850 50  0001 C CNN
F 3 "~" H 3000 3000 50  0001 C CNN
	1    3000 3000
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C33
U 1 1 5D71C492
P 5150 2000
F 0 "C33" H 5265 2046 50  0000 L CNN
F 1 "100n" H 5265 1955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5188 1850 50  0001 C CNN
F 3 "~" H 5150 2000 50  0001 C CNN
	1    5150 2000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 1850 5150 1600
Wire Wire Line
	5150 1600 5500 1600
Wire Wire Line
	5500 1550 5500 1600
Connection ~ 5500 1600
Wire Wire Line
	5500 1600 5500 1650
Wire Wire Line
	5150 2150 5150 2400
Wire Wire Line
	5150 2400 5500 2400
Connection ~ 5500 2400
Wire Wire Line
	5500 2400 5500 2450
$Comp
L Connector:TestPoint TP10
U 1 1 5D7E0016
P 3750 3300
F 0 "TP10" H 3808 3418 50  0000 L CNN
F 1 "TestPoint" H 3808 3327 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_D1.5mm" H 3950 3300 50  0001 C CNN
F 3 "~" H 3950 3300 50  0001 C CNN
	1    3750 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 3300 3750 3400
$Comp
L Device:R R17
U 1 1 5D6F2503
P 2800 3300
F 0 "R17" H 2870 3346 50  0000 L CNN
F 1 "0" H 2870 3255 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2730 3300 50  0001 C CNN
F 3 "~" H 2800 3300 50  0001 C CNN
	1    2800 3300
	0    1    1    0   
$EndComp
$Comp
L Device:R R18
U 1 1 5D6F2D93
P 2800 3400
F 0 "R18" H 2870 3446 50  0000 L CNN
F 1 "0" H 2870 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2730 3400 50  0001 C CNN
F 3 "~" H 2800 3400 50  0001 C CNN
	1    2800 3400
	0    1    1    0   
$EndComp
$Comp
L Device:R R19
U 1 1 5D6F324D
P 2800 3500
F 0 "R19" H 2870 3546 50  0000 L CNN
F 1 "0" H 2870 3455 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 2730 3500 50  0001 C CNN
F 3 "~" H 2800 3500 50  0001 C CNN
	1    2800 3500
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 3300 3050 3300
Wire Wire Line
	3050 3300 3050 3400
Connection ~ 3050 3400
Wire Wire Line
	3050 3400 2950 3400
Wire Wire Line
	2950 3500 3050 3500
Wire Wire Line
	3050 3500 3050 3400
Wire Wire Line
	2550 3300 2650 3300
Wire Wire Line
	2550 3400 2650 3400
Wire Wire Line
	2550 3500 2650 3500
$Comp
L power:+3.3V #PWR040
U 1 1 5D6F5727
P 2700 2900
F 0 "#PWR040" H 2700 2750 50  0001 C CNN
F 1 "+3.3V" H 2715 3073 50  0000 C CNN
F 2 "" H 2700 2900 50  0001 C CNN
F 3 "" H 2700 2900 50  0001 C CNN
	1    2700 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR042
U 1 1 5D6F9789
P 4400 2900
F 0 "#PWR042" H 4400 2750 50  0001 C CNN
F 1 "+3.3V" H 4415 3073 50  0000 C CNN
F 2 "" H 4400 2900 50  0001 C CNN
F 3 "" H 4400 2900 50  0001 C CNN
	1    4400 2900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R20
U 1 1 5D700FA3
P 4800 3400
F 0 "R20" H 4870 3446 50  0000 L CNN
F 1 "1k" H 4870 3355 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4730 3400 50  0001 C CNN
F 3 "~" H 4800 3400 50  0001 C CNN
	1    4800 3400
	0    1    1    0   
$EndComp
Wire Wire Line
	3050 3400 3750 3400
$Comp
L Device:R R21
U 1 1 5D704157
P 5550 3050
F 0 "R21" H 5620 3096 50  0000 L CNN
F 1 "100k" H 5620 3005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5480 3050 50  0001 C CNN
F 3 "~" H 5550 3050 50  0001 C CNN
	1    5550 3050
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 3600 4750 3600
Wire Wire Line
	4950 3400 5200 3400
Wire Wire Line
	5950 3500 6000 3500
Wire Wire Line
	6000 3500 6000 3050
Wire Wire Line
	6000 3050 5700 3050
Connection ~ 6000 3500
Wire Wire Line
	6000 3500 6200 3500
Wire Wire Line
	5400 3050 5200 3050
Wire Wire Line
	5200 3050 5200 3400
Connection ~ 5200 3400
Wire Wire Line
	5200 3400 5350 3400
Connection ~ 3750 3400
Wire Wire Line
	3750 3400 4650 3400
$Comp
L Connector:Conn_01x06_Male J5
U 1 1 5D7767BD
P 2350 3300
F 0 "J5" H 2458 3681 50  0000 C CNN
F 1 "Conn_01x06_Male" H 2458 3590 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 2350 3300 50  0001 C CNN
F 3 "~" H 2350 3300 50  0001 C CNN
	1    2350 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3100 2700 3100
Wire Wire Line
	2700 2900 2700 3000
Wire Wire Line
	2700 3000 2850 3000
Connection ~ 2700 3000
Wire Wire Line
	2700 3000 2700 3100
Wire Wire Line
	3150 3000 3200 3000
Wire Wire Line
	3200 3000 3200 3200
Wire Wire Line
	3200 3200 2550 3200
Connection ~ 3200 3000
Wire Wire Line
	3200 3000 3250 3000
$Comp
L Device:C C42
U 1 1 5D77E792
P 4750 3900
F 0 "C42" H 4865 3946 50  0000 L CNN
F 1 "100n" H 4865 3855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4788 3750 50  0001 C CNN
F 3 "~" H 4750 3900 50  0001 C CNN
	1    4750 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 3750 4750 3600
Connection ~ 4750 3600
Wire Wire Line
	4750 3600 5350 3600
Wire Wire Line
	4750 4050 4750 4100
Wire Wire Line
	4750 4100 4400 4100
Connection ~ 4400 4100
Wire Wire Line
	4400 4100 4400 4150
Text Notes 3100 3500 0    50   ~ 0
Signal: 1V - 1,5V
$EndSCHEMATC
