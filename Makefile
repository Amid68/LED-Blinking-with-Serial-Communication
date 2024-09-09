MCU = atmega328p
F_CPU = 16000000UL

CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os

SRC_DIR = src
DELAY_DIR = $(SRC_DIR)/delay
USART_DIR = $(SRC_DIR)/usart
TIMER_DIR = $(SRC_DIR)/timer

SRCS =  $(SRC_DIR)/main.c \
        $(DELAY_DIR)/delay.c \
        $(USART_DIR)/usart.c \
        $(TIMER_DIR)/timer.c

OBJS = $(SRCS:.c=.o)
TARGET = main.hex

AVRDUDE_PROGRAMMER = arduino
AVRDUDE_PORT = /dev/cu.usbserial-2110   # Update this for your system
AVRDUDE_BAUD = 115200
AVRDUDE_MCU = $(MCU)

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

main.elf: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(TARGET): main.elf
	avr-objcopy -O ihex -R .eeprom $< $@

upload: $(TARGET)
	avrdude -c $(AVRDUDE_PROGRAMMER) -p $(AVRDUDE_MCU) -P $(AVRDUDE_PORT) -b $(AVRDUDE_BAUD) -U flash:w:$(TARGET)

clean:
	rm -f $(OBJS) main.elf $(TARGET)
