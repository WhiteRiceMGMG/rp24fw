/* rp24_drv,c                                           */
/********************************************************/
/* object    | ハードウェア構造体定義                   */
/* abstract  | rp24構造体定義                           */
/* edit his  | 2026/01/22 新規作成                      */
/*           |                                          */
/********************************************************/
/********************************************************/
/* ヘッダーインクルード                                 */
/********************************************************/
#include "./rp24_drv.h"

/********************************************************/
/* 外部公開変数                                         */
/********************************************************/
rp24_driver rp24 =
{
    .firstbtn =
    {
        .push = u1g_firstbtn_get
    },

    .secondbtn =
    {
        .push = u1g_secondbtn_get
    },

    .thirdbtn =
    {
        .push = u1g_thirdbtn_get
    },

    .fourthbtn =
    {
        .push = u1g_fourthbtn_get
    },

    .firstled =
    {
        .on  = u1g_firstled_on,
        .off = u1g_firstled_off
    },

    .secondled =
    {
        .on  = u1g_secondled_on,
        .off = u1g_secondled_off
    },

    .thirdled =
    {
        .on  = u1g_thirdled_on,
        .off = u1g_thirdled_off
    },

    .fourthled =
    {
        .on  = u1g_fourthled_on,
        .off = u1g_fourthled_off
    }
};
/********************************************************/
/* EOF                                                  */
/********************************************************/