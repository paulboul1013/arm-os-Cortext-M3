#include <stdint.h>

extern void main(void);
extern uint32_t _stack_top;

void reset_handler(void) {
    //jump to c entry point
    main();
}

__attribute((section(".isr_vector")))
uint32_t *isr_vectors[] = {
    &_stack_top,
    (uint32_t *) reset_handler, //code entry point
}