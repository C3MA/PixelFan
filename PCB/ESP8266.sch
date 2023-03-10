EESchema Schematic File Version 4
LIBS:PixelFan-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L RF_Module:ESP-12F U9
U 1 1 5E21110D
P 5750 3900
F 0 "U9" H 5750 4881 50  0000 C CNN
F 1 "ESP-12F" H 5750 4790 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 5750 3900 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 5400 4000 50  0001 C CNN
	1    5750 3900
	1    0    0    -1  
$EndComp
Text HLabel 4850 4200 0    50   BiDi ~ 0
ESP_IO1
Text HLabel 4850 4100 0    50   BiDi ~ 0
ESP_IO2
$Comp
L power:GND #PWR036
U 1 1 5E213770
P 5750 4800
F 0 "#PWR036" H 5750 4550 50  0001 C CNN
F 1 "GND" H 5755 4627 50  0000 C CNN
F 2 "" H 5750 4800 50  0001 C CNN
F 3 "" H 5750 4800 50  0001 C CNN
	1    5750 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 4800 5750 4600
Wire Wire Line
	5750 2750 5750 2800
$Comp
L Device:R R8
U 1 1 5E213FF7
P 3100 3300
F 0 "R8" V 2893 3300 50  0000 C CNN
F 1 "10k" V 2984 3300 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 3030 3300 50  0001 C CNN
F 3 "~" H 3100 3300 50  0001 C CNN
	1    3100 3300
	0    1    1    0   
$EndComp
$Comp
L power:+3.3V #PWR035
U 1 1 5E214903
P 5750 2750
F 0 "#PWR035" H 5750 2600 50  0001 C CNN
F 1 "+3.3V" H 5765 2923 50  0000 C CNN
F 2 "" H 5750 2750 50  0001 C CNN
F 3 "" H 5750 2750 50  0001 C CNN
	1    5750 2750
	1    0    0    -1  
$EndComp
$Comp
L power:+3.3V #PWR033
U 1 1 5E22D48A
P 2800 3300
F 0 "#PWR033" H 2800 3150 50  0001 C CNN
F 1 "+3.3V" H 2815 3473 50  0000 C CNN
F 2 "" H 2800 3300 50  0001 C CNN
F 3 "" H 2800 3300 50  0001 C CNN
	1    2800 3300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2950 3300 2900 3300
Wire Wire Line
	2900 3500 2900 3300
Connection ~ 2900 3300
Wire Wire Line
	2900 3300 2800 3300
Wire Wire Line
	3250 3300 3450 3300
Wire Wire Line
	6350 3300 6500 3300
$Comp
L Device:R R10
U 1 1 5E266E43
P 6500 3050
F 0 "R10" H 6430 3004 50  0000 R CNN
F 1 "10k" H 6430 3095 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6430 3050 50  0001 C CNN
F 3 "~" H 6500 3050 50  0001 C CNN
	1    6500 3050
	-1   0    0    1   
$EndComp
Wire Wire Line
	6500 3300 6500 3200
$Comp
L Device:R R9
U 1 1 5E269A14
P 6150 2800
F 0 "R9" V 6357 2800 50  0000 C CNN
F 1 "1k" V 6266 2800 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6080 2800 50  0001 C CNN
F 3 "~" H 6150 2800 50  0001 C CNN
	1    6150 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6300 2800 6500 2800
Wire Wire Line
	6500 2800 6500 2900
Wire Wire Line
	6000 2800 5750 2800
Connection ~ 5750 2800
Wire Wire Line
	5750 2800 5750 3100
Wire Wire Line
	7250 2800 6500 2800
Connection ~ 6500 2800
$Comp
L power:GND #PWR038
U 1 1 5E274177
P 7800 2800
F 0 "#PWR038" H 7800 2550 50  0001 C CNN
F 1 "GND" V 7805 2672 50  0000 R CNN
F 2 "" H 7800 2800 50  0001 C CNN
F 3 "" H 7800 2800 50  0001 C CNN
	1    7800 2800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7650 2800 7800 2800
$Comp
L Switch:SW_Push SW2
U 1 1 5E2664D4
P 7450 2800
F 0 "SW2" H 7450 3085 50  0000 C CNN
F 1 "Flash" H 7450 2994 50  0000 C CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1000" H 7450 3000 50  0001 C CNN
F 3 "~" H 7450 3000 50  0001 C CNN
	1    7450 2800
	1    0    0    -1  
$EndComp
Connection ~ 3450 3300
$Comp
L power:GND #PWR034
U 1 1 5E27DD3C
P 3450 4050
F 0 "#PWR034" H 3450 3800 50  0001 C CNN
F 1 "GND" H 3455 3877 50  0000 C CNN
F 2 "" H 3450 4050 50  0001 C CNN
F 3 "" H 3450 4050 50  0001 C CNN
	1    3450 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R11
U 1 1 5E28136F
P 7100 4450
F 0 "R11" H 7030 4404 50  0000 R CNN
F 1 "2k2" H 7030 4495 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 7030 4450 50  0001 C CNN
F 3 "~" H 7100 4450 50  0001 C CNN
	1    7100 4450
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR037
U 1 1 5E281C31
P 7100 4700
F 0 "#PWR037" H 7100 4450 50  0001 C CNN
F 1 "GND" H 7105 4527 50  0000 C CNN
F 2 "" H 7100 4700 50  0001 C CNN
F 3 "" H 7100 4700 50  0001 C CNN
	1    7100 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 4700 7100 4600
Wire Wire Line
	7100 4300 7100 4200
$Comp
L Connector:Conn_01x05_Male J4
U 1 1 5D72E53C
P 9650 3100
F 0 "J4" H 9950 2650 50  0000 R CNN
F 1 "Conn_01x05_Male" H 9950 2750 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x05_P2.54mm_Vertical" H 9650 3100 50  0001 C CNN
F 3 "~" H 9650 3100 50  0001 C CNN
	1    9650 3100
	-1   0    0    1   
$EndComp
Text Notes 9750 3300 0    50   ~ 0
5V\nRX\nTX\nGND\nRES
Wire Wire Line
	9450 3000 7000 3000
Wire Wire Line
	7000 3000 7000 3400
Wire Wire Line
	9450 3100 7100 3100
Wire Wire Line
	7100 3100 7100 3600
$Comp
L power:GND #PWR039
U 1 1 5D737A05
P 9350 3450
F 0 "#PWR039" H 9350 3200 50  0001 C CNN
F 1 "GND" V 9355 3322 50  0000 R CNN
F 2 "" H 9350 3450 50  0001 C CNN
F 3 "" H 9350 3450 50  0001 C CNN
	1    9350 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 3200 9350 3200
Wire Wire Line
	9350 3200 9350 3450
Text HLabel 7300 4000 2    50   Output ~ 0
MOSI
Wire Wire Line
	3450 3550 3450 3300
$Comp
L Switch:SW_Push SW1
U 1 1 5E279D19
P 3450 3750
F 0 "SW1" V 3404 3898 50  0000 L CNN
F 1 "Reset" V 3495 3898 50  0000 L CNN
F 2 "Button_Switch_SMD:SW_SPST_B3S-1000" H 3450 3950 50  0001 C CNN
F 3 "~" H 3450 3950 50  0001 C CNN
	1    3450 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	3450 4050 3450 3950
Text HLabel 7300 3900 2    50   Input ~ 0
MISO
Text HLabel 7300 4100 2    50   Output ~ 0
SCLK
Wire Wire Line
	3450 3300 5150 3300
Wire Wire Line
	6350 4100 7300 4100
Wire Wire Line
	6350 3900 7300 3900
Wire Wire Line
	6350 4000 7300 4000
Wire Wire Line
	2900 3500 5150 3500
Wire Wire Line
	6350 4200 7100 4200
Wire Wire Line
	6350 3600 7100 3600
Wire Wire Line
	6350 3400 7000 3400
$Comp
L Device:C C53
U 1 1 5FD2E1A1
P 5500 2800
F 0 "C53" V 5248 2800 50  0000 C CNN
F 1 "470n" V 5339 2800 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5538 2650 50  0001 C CNN
F 3 "~" H 5500 2800 50  0001 C CNN
	1    5500 2800
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5FD2E948
P 5250 2800
F 0 "#PWR0101" H 5250 2550 50  0001 C CNN
F 1 "GND" H 5255 2627 50  0000 C CNN
F 2 "" H 5250 2800 50  0001 C CNN
F 3 "" H 5250 2800 50  0001 C CNN
	1    5250 2800
	0    1    1    0   
$EndComp
Wire Wire Line
	5750 2800 5650 2800
Wire Wire Line
	5350 2800 5250 2800
$Comp
L Device:C C52
U 1 1 5FD306AB
P 5500 2450
F 0 "C52" V 5248 2450 50  0000 C CNN
F 1 "10n" V 5339 2450 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5538 2300 50  0001 C CNN
F 3 "~" H 5500 2450 50  0001 C CNN
	1    5500 2450
	0    1    1    0   
$EndComp
Wire Wire Line
	5650 2450 5650 2800
Connection ~ 5650 2800
Wire Wire Line
	5350 2450 5350 2800
Connection ~ 5350 2800
Wire Wire Line
	5150 4100 4850 4100
Wire Wire Line
	5150 4200 4850 4200
$EndSCHEMATC
