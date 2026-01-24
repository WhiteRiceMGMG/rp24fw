/* xocs_reg.h                                           */
/********************************************************/
/* object    | XOCSレジスタアドレス                     */
/* abstract  | rp24専用XOCSアドレス                     */
/* edit his  | 2026/01/24 新規作成                      */
/*           |                                          */
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
/* Crystal Oscillator(XOSC) */
#define XOSC_BASE               0x40024000
#define XOSC_CTRL               (XOSC_BASE+0x00)
#define XOSC_STATUS             (XOSC_BASE+0x04)
#define XOSC_STARTUP            (XOSC_BASE+0x0C)

#define	XOSC_CTRL_ENABLE        (0x00FAB000)
#define	XOSC_CTRL_DISABLE       (0x00D1E000)
#define	XOSC_CTRL_FRANG_1_15MHZ (0x00000AA0)

#define	XOSC_STATUS_STABLE      (0x80000000)

#endif  /* XOCS_REG_H */
/********************************************************/
/* EOF                                                  */
/********************************************************/
