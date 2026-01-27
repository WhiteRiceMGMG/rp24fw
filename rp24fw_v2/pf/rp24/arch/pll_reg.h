/* pll_reg.h                                            */
/********************************************************/
/* object    | PLLレジスタアドレス                      */
/* abstract  | rp24専用PLLアドレス                      */
/* edit his  | 2026/01/24 新規作成                      */
/*           | reset_hdrで使用                          */
/********************************************************/
#ifndef XOCS_REG_H
#define XOCS_REG_H

/********************************************************/
/* インクルード                                         */
/********************************************************/
#include "./base_adr.h"

/********************************************************/
/* レジスタ定義マクロ                                   */
/********************************************************/
/* PLL */
#define PLL_SYS_BASE            (0x40028000)
#define PLL_USB_BASE            (0x4002C000)

#define PLL_CS                  (0x00)
#define	PLL_PWR                 (0x04)
#define	PLL_FBDIV_INT           (0x08)
#define	PLL_PRIM                (0x0C)

#define	PLL_CS_LOCK             (1<<31)
#define	PLL_PWR_PD              (1<<0)
#define	PLL_PWR_VCOPD           (1<<5)
#define	PLL_PWR_POSTDIVPD       (1<<3)
#define PLL_PRIM_POSTDIV1_LSB   (16)
#define PLL_PRIM_POSTDIV2_LSB   (12)

#endif  /* PLL_REG_H */
/********************************************************/
/* EOF                                                  */
/********************************************************/
