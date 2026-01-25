/* clock_conf.h                                           */
/********************************************************/
/* object    | クロック周波数定義                       */
/* abstract  | rp24専用クロック周波数定義               */
/* edit his  | 2026/01/25 新規作成                      */
/*           |                                          */
/********************************************************/
#ifndef CLOCK_CONF_H
#define CLOCK_CONF_H

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

#endif  /* CLOCK_CONF_H */
/********************************************************/
/* EOF                                                  */
/********************************************************/
