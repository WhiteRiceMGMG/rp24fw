/* base_adr.h                                           */
/********************************************************/
/* object    | ベースレジスタアドレス                   */
/* abstract  | rp24専用ベースアドレス                   */
/* edit his  | 2026/01/24 新規作成                      */
/*           |                                          */
/********************************************************/
#ifndef CLOCL_REG_H
#define CLOCK_REG_H

/********************************************************/
/* インクルード                                         */
/********************************************************/
#include "./base_adr.h"

/********************************************************/
/* レジスタ定義マクロ                                   */
/********************************************************/
/* APB ペリフェラル */
/* Clocks */
#define CLOCKS_BASE             0x40008000
#define CLK_GPOUT0              (CLOCKS_BASE+0x00)
#define CLK_GPOUT1              (CLOCKS_BASE+0x0C)
#define CLK_GPOUT2              (CLOCKS_BASE+0x18)
#define CLK_GPOUT3              (CLOCKS_BASE+0x24)
#define CLK_REF	                (CLOCKS_BASE+0x30)
#define CLK_SYS	                (CLOCKS_BASE+0x3C)
#define CLK_PERI                (CLOCKS_BASE+0x48)
#define CLK_USB	                (CLOCKS_BASE+0x54)
#define CLK_ADC	                (CLOCKS_BASE+0x60)
#define CLK_RTC	                (CLOCKS_BASE+0x6C)
#define CLK_SYS_RESUS_CTRL      (CLOCKS_BASE+0x78)
#define CLK_SYS_RESUS_STATUS    (CLOCKS_BASE+0x7C)

#define	CLK_x_CTRL              (0x00)
#define	CLK_x_DIV               (0x04)
#define	CLK_x_SELECTED          (0x08)

#define CLK_SYS_CTRL_AUXSRC     (0x000000e0)
#define CLK_SYS_CTRL_SRC        (0x00000001)
#define CLK_REF_CTRL_SRC        (0x00000003)
#define CLK_CTRL_ENABLE	        (0x00000800)

#define CLK_SYS_CTRL_SRC_AUX	(0x1)

#define CLK_KIND_GPOUT0         0
#define CLK_KIND_GPOUT1         1
#define CLK_KIND_GPOUT2         2
#define CLK_KIND_GPOUT3         3
#define CLK_KIND_REF            4
#define CLK_KIND_SYS            5
#define CLK_KIND_PERI           6
#define CLK_KIND_USB            7
#define CLK_KIND_ADC            8
#define CLK_KIND_RTC            9

#endif  /* SYSDEF_H */
/********************************************************/
/* EOF                                                  */
/********************************************************/
