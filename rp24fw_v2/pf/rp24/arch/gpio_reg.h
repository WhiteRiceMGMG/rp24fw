/* gpio_reg.h                                           */
/********************************************************/
/* object    | GPIOレジスタアドレス                     */
/* abstract  | rp24専用GPIOアドレス                     */
/* edit his  | 2026/01/24 新規作成                      */
/*           |                                          */
/********************************************************/
#ifndef GPIO_REG_H
#define GPIO_REG_H

/********************************************************/
/* インクルード                                         */
/********************************************************/
#include "./base_adr.h"

/********************************************************/
/* レジスタ定義マクロ                                   */
/********************************************************/
/* GPIO */
#define IO_BANK0_BASE           0x40014000
#define	GPIO_CTRL(n)            (IO_BANK0_BASE+0x04+(n*8))

#define	GPIO_CTRL_FUNCSEL_I2C   3
#define	GPIO_CTRL_FUNCSEL_NULL  31

#define PADS_BANK0_BASE         0x4001c000
#define	GPIO(n)                 (PADS_BANK0_BASE+0x4+(n*4))

#define	GPIO_OD                 (1<<7)
#define	GPIO_IE                 (1<<6)
#define	GPIO_DRIVE_2MA          (0<<4)
#define	GPIO_DRIVE_4MA          (1<<4)
#define	GPIO_DRIVE_8MA          (2<<4)
#define	GPIO_DRIVE_12MA         (3<<4)
#define	GPIO_PUE                (1<<3)
#define	GPIO_PDE                (1<<2)
#define	GPIO_SHEMITT            (1<<1)
#define	GPIO_SLEWDAST           (1<<0)


#endif  /* GPIO_REG_H */
/********************************************************/
/* EOF                                                  */
/********************************************************/
