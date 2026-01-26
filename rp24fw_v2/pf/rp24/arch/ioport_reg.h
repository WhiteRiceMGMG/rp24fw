/* ioport_reg.h                                         */
/********************************************************/
/* object    | IOPORTレジスタアドレス                   */
/* abstract  | rp24専用IOPORTアドレス                   */
/* edit his  | 2026/01/25 新規作成                      */
/*           |                                          */
/********************************************************/
#ifndef IOPORT_REG_H
#define IOPORT_REG_H

/********************************************************/
/* インクルード                                         */
/********************************************************/
#include "./base_adr.h"

/********************************************************/
/* レジスタ定義マクロ                                   */
/********************************************************/
/* IOPORT レジスタ */
#define SIO_BASE                0xD0000000
#define	GPIO_IN                 (SIO_BASE+0x04)
#define GPIO_OUT                (SIO_BASE+0x10)
#define GPIO_OUT_SET            (SIO_BASE+0x14)
#define GPIO_OUT_CLR            (SIO_BASE+0x18)
#define GPIO_OUT_XOR            (SIO_BASE+0x1C)
#define GPIO_OE_SET             (SIO_BASE+0x24)
#define GPIO_OE_CLR             (SIO_BASE+0x28)
#define GPIO_OE_XOR             (SIO_BASE+0x2C)


#endif  /* IOPORT_REG_H */
/********************************************************/
/* EOF                                                  */
/********************************************************/
