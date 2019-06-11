### Inside firmware/code

avr-gcc -mmcu=atmega644 01_blinky.cxx -o 01_blinky.o

avr-objcopy -j .text -j .data -O ihex 01_blinky.o 01_blinky.ihx

sudo avrdude -p m644 -P /dev/ttyUSB0 -c stk500v2 -b 19200 -U flash:w:01_blinky.ihx