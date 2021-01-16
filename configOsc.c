
#include <pic16f1459.h>
#include "config.h"
void configOsc(void)
{
    OSCCONbits.IRCF3 = HI;  // 16MHz internal clock selected
    OSCCONbits.IRCF2 = HI;
    OSCCONbits.IRCF1 = LO;
    OSCCONbits.IRCF0 = LO;
    OSCCONbits.SCS1 = HI;   // internal oscillator block is selected
    OSCCONbits.SCS0 = LO;
}

