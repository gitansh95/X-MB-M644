### Build process


01_blinky.c
------

1. Compile :
	`avr-gcc -mmcu=atmega644 01_blinky.c -o 01_blinky.o`

2. Generate executable :
	`avr-objcopy -j .text -j .data -O ihex 01_blinky.o 01_blinky.ihx`

3. Flash :
	`sudo avrdude -p m644 -P /dev/ttyUSB0 -c stk500v2 -b 19200 -U flash:w:01_blinky.ihx`

02_blinky_w_input.c
------

1. Compile :
	`avr-gcc -mmcu=atmega644 02_blinky_w_input.c -o 02_blinky_w_input.o`

2. Generate executable :
	`avr-objcopy -j .text -j .data -O ihex 02_blinky_w_input.o 02_blinky_w_input.ihx`

3. Flash :
	`sudo avrdude -p m644 -P /dev/ttyUSB0 -c stk500v2 -b 19200 -U flash:w:02_blinky_w_input.ihx`




