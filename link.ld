ENTRY(reset_handler)

MEMORY
{
    //Boot from main Flash memory
    //64K is from STM32 F103 C8 T6's C8 = 64KB Flash
    FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 64K
    SRAM  (rwx): ORIGIN = 0x20000000, LENGTH = 20K
}

_stack_top = ORIGIN(SRAM) + LENGTH(SRAM);

SECTIONS
{
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text)
        *(.rodata*)
    } > FLASH
}