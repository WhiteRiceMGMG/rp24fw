/* sysdef.h                                             */
/********************************************************/
/* object    | レジスタ定義マクロ                       */
/* abstract  | レジスタ共通定義                         */
/* edit his  | 2025/12/14 新規作成                      */
/*           |                                          */
/********************************************************/
#ifndef SYSDEF_H
#define SYSDEF_H

/********************************************************/
/* レジスタ定義マクロ                                   */
/********************************************************/










/* UART */
#define UART0_BASE              0x40034000
#define UART1_BASE              0x40038000

#define UARTx_DR                (0x000)
#define UARTx_FR                (0x018)
#define UARTx_IBRD              (0x024)
#define UARTx_FBRD              (0x028)
#define UARTx_LCR_H             (0x02C)
#define UARTx_CR                (0x030)

#define UART_CR_RXE             (1<<9)
#define UART_CR_TXE             (1<<8)
#define UART_CR_EN              (1<<0)
#define UART_FR_TXFF            (1<<5)

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

/* SysTick レジスタ */
#define SYST_CSR                (0xE000E010)
#define SYST_RVR                (0xE000E014)
#define SYST_CVR                (0xE000E018)

#define SYST_CSR_COUNTFLAG      (1<<16)
#define SYST_CSR_CLKSOURCE      (1<<2)
#define SYST_CSR_TICKINT        (1<<1)
#define SYST_CSR_ENABLE	        (1<<0)

/* クロック周波数 */
#define	CLOCK_XOSC              (12000000UL)
#define	CLOCK_REF               (CLOCK_XOSC)
#define	CLOCK_PERI              (CLOCK_SYS)

#define	XOSC_MHz                (12)
#define	XOSC_KHz                (XOSC_MHz*1000)

#define	TMCLK_MHz               (125)
#define	TMCLK_KHz               (TMCLK_MHz*1000)
#define	TIMER_PERIOD            (10)

#define	KHz                     (1000)
#define	MHz                     (KHz*1000)

/* NVIC レジスタ */
#define SCB_SHPR3               (0xE000ED20)

#define	INTLEVEL_0              (0x00)
#define	INTLEVEL_1              (0x40)
#define	INTLEVEL_2              (0x80)
#define	INTLEVEL_3              (0xC0)

#endif  /* SYSDEF_H */
/********************************************************/
/* EOF                                                  */
/********************************************************/
