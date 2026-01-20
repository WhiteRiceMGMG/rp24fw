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
};#ifndef RP24_DRV_H
#define RP24_DEV_H

#include <rp24knl.h>
#include "../btn/btn_drv.h"
#include "../led/led_drv.h"

typedef struct
{
    btnDriver Btn;
    ledDriver Led;
}rp24Driver;

extern rp24Driver Rp24;
#endif