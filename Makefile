CROSS_COMPILE ?= arm-none-eabi-
CC := $(CROSS_COMPILE) gcc
CFLAGS = -fno-common -O0 -mcpu=cortex-m3 -mthumb -T link.ld -nostartfiles

TARGET = main.bin
QEMU ?= docker run --rm -i -v $(CURDIR):/work -w /work qemu_stm32-beckus:local /usr/local/bin/qemu-system-arm
QEMU_MACHINE ?= stm32-f103c8

all : $(TARGET)

$(TARGET): kernel_main.c startup.c
	$(CC) $(CFLAGS) $^ -o main.elf
	$(CROSS_COMPILE)objcopy -Obinary main.elf main.bin
	$(CROSS_COMPILE)objdump -S main.elf > main.list

qemu: $(TARGET)
	@$(QEMU) -M ? | grep $(QEMU_MACHINE) >/dev/null || \
		(echo "$(QEMU) does not provide $(QEMU_MACHINE);" exit 1)
	@echo "Press Ctrl-A and then X to exit QEMU"
	@echo 
	$(QEMU) -M $(QEMU_MACHINE) -nographic -kernel main.bin

clean:
	rm -f *.o *.bin *.elf *.list