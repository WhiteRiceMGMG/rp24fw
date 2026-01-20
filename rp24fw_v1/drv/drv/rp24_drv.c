#include "./rp24_drv.h"

rp24Driver Rp24 =
{
    .Btn =
    {
        .On = Button_On
    },
    .Led =
    {
        .On = Led_On,
        .Off = Led_Off
    }
};