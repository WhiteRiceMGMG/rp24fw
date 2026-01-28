/* knl_port.h                                           */
/********************************************************/
/* object    | MCU依存部分離                            */
/* abstract  | MCU依存部分                              */
/* edit his  | 2026/01/26 新規作成                      */
/*           | scheduler vector_tblで使用               */
/*           |                                          */
/********************************************************/
#ifndef KNL_PORT_H
#define KNL_PORT_H

/********************************************************/
/* インクルード                                        */
/********************************************************/


/********************************************************/
/* 外部公開定義                                         */
/********************************************************/
#define SCB_ICSR    0xE000ED04 /* 割り込み制御レジスタ */
#define ICSR_PENDSVSET (1 << 28) /* PendSV pedingヒット */

static inline void dispatch( void )
{
    out_w( SCB_ICSR, ICSR_PENDSVSET ); /* pendSV発生 */
}

/* タスクコンテキスト生成 */
extern void *make_context( u4 *sp, UINT ssize, void (*fp)()); 

extern void dispatch_entry( void );   /*ディスパッチャ*/
extern void systimer_handler( void ); /*割り込みハンドラ*/

#endif
/********************************************************/
/* EOF                                                  */
/********************************************************/
