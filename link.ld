ENTRY(reset_handler)

MEMORY
{
    /* Boot from main Flash memory. */
    /* STM32F103C8T6 provides 64 KB of Flash. */
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