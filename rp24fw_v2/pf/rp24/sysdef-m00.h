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
