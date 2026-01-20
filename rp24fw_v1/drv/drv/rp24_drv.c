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
        .On  = u1g_firstled_on,
        .Off = u1g_firstled_off
    },

    .secondled =
    {
        .On  = u1g_secondled_on,
        .Off = u1g_secondled_off
    },

    .thirdled =
    {
        .On  = u1g_thirdled_on,
        .Off = u1g_thirdled_off
    },

    .fourthled =
    {
        .On  = u1g_fourthled_on,
        .Off = u1g_fourthled_off
    }
};