#ifndef RP24_DRV_H
#define RP24_DEV_H

#include <rp24knl.h>
#include "../btn/btn_drv.h"
#include "../led/led_drv.h"

typedef struct
{
    btn_driver firstbtn;
    btn_driver secondbtn;
    btn_driver thirdbtn;
    btn_driver fourthbtn;
    
    led_driver firstled;
    led_driver secondled;
    led_driver thirdled;
    led_driver fourthled;
}rp24_driver;

extern rp24_driver rp24;
#endif