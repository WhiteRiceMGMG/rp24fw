/* rp24_drv.h                                           */
/********************************************************/
/* object    | ハードウェア構造体定義                   */
/* abstract  | rp24_driver定義                          */
/* edit his  | 2025/12/07 テンプレート作成 ver1.0       */
/*           |                                          */
/********************************************************/
#ifndef RP24_DRV_H
#define RP24_DEV_H

/********************************************************/
/* ヘッダーインクルード                                 */
/********************************************************/
#include <rp24knl.h>
#include "../btn/btn_drv.h"
#include "../led/led_drv.h"

/********************************************************/
/* 外部公開変数                                         */
/********************************************************/
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