/***********软件延时************/
#include "Delayms_lib.h"


void delayms(uint time)
{
    uint i, j;
    for (i = time; i > 0; i--)
        for (j = 845; j > 0; j--);
}