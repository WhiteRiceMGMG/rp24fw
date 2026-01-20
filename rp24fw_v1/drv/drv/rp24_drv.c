#include "./rp24_drv.h"

rp24Driver rp24 =
{
    .firstbtn =
    {
        .On = u1g_firstbtn_conf
    },

    .secondbtn =
    {
        .On = u1g_secondbtn_conf
    },

    .thirdbtn =
    {
        .On = u1g_thirdbtn_conf
    },

    .fourthbtn =
    {
        .On = u1g_fourthbtn_conf
    },

    .firstled =
    {
        .On = Led_On,
        .Off = Led_Off
    }
};