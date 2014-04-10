# Makefile for ATmegaBOOT
# E.Lins, 2004-10-14

# program name should not be changed...
PROGRAM    = ATmegaBOOT

MCU        = atmega8

ISPTOOL	   = avrispmkii
ISPPORT	   = usb
ISPSPEED   = -b 115200

DIRAVR = ../../tools/avr/
#DIRAVR = /usr/local/avrtod
#DIRAVR = /usr/local/AVRMacPack
DIRAVRBIN = $(DIRAVR)/bin
DIRAVRUTILS = $(DIRAVR)/utils/bin
DIRINC = $(DIRAVR)/include
DIRLIB = $(DIRAVR)/avr/lib


MCU_TARGET = atmega8
LDSECTION  = --section-start=.text=0x1c00

FUSE_L     = 0xd4
FUSE_H     = 0xca

ISPFUSES    = avrdude -c $(ISPTOOL) -p $(MCU) -P $(ISPPORT) $(ISPSPEED) -e -u -U hfuse:w:$(FUSE_H):m -U lfuse:w:$(FUSE_L):m
ISPFLASH    = avrdude -c $(ISPTOOL) -p $(MCU) -P $(ISPPORT) $(ISPSPEED) -U flash:w:$(PROGRAM).hex 


OBJ        = $(PROGRAM).o
#OPTIMIZE   = -Os
OPTIMIZE   = -Os -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -fno-split-wide-types -Wl,--relax -fno-inline-small-functions -mcall-prologues
#OPTIMIZE   = -Os -fdata-sections -fpack-struct -Wl,--relax  -fno-inline-small-functions -mcall-prologues

DEFS       = -DF_CPU=8000000 -DBAUD_RATE=38400
LIBS       =

CC         = $(DIRAVRBIN)/avr-gcc


# Override is only needed by avr-lib build system.

override CFLAGS        = -g -Wall $(OPTIMIZE) -mmcu=$(MCU_TARGET) -D$(MCU) $(DEFS) -I$(DIRINC)
override LDFLAGS       = -Wl,-Map,$(PROGRAM).map,$(LDSECTION)

OBJCOPY        = $(DIRAVRBIN)/avr-objcopy
OBJDUMP        = $(DIRAVRBIN)/avr-objdump
SIZE           = $(DIRAVRBIN)/avr-size

all: $(PROGRAM).elf lst text asm size

isp: $(PROGRAM).hex
	$(ISPFUSES)
	$(ISPFLASH)

fuse: $(PROGRAM).hex
	$(ISPFUSES)
flash: $(PROGRAM).hex
	$(ISPFLASH)

$(PROGRAM).elf: $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -rf *.s
	rm -rf *.o *.elf
	rm -rf *.lst *.map

asm: $(PROGRAM).s

%.s: %.c
	$(CC) -S $(CFLAGS) -g1 $^

lst:  $(PROGRAM).lst

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

size: $(PROGRAM).hex
	$(SIZE) $^

# Rules for building the .text rom images

text: hex bin srec

hex:  $(PROGRAM).hex
bin:  $(PROGRAM).bin
srec: $(PROGRAM).srec

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.srec: %.elf
	$(OBJCOPY) -j .text -j .data -O srec $< $@

%.bin: %.elf
	$(OBJCOPY) -j .text -j .data -O binary $< $@
