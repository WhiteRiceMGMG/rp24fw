/* ﾒﾓﾒﾓ:OSAPIとMCU依存を分離すべき */
/* knldef.h                                             */
/********************************************************/
/* object    | カーネル内部共通定義ヘッダ               */
/* abstract  | カーネル内部共通定義                     */
/* edit his  | 2025/12/17 新規作成                      */
/*           |                                          */
/********************************************************/
#ifndef KNLDEF_H
#define KNLDEF_H

/********************************************************/
/* 外部公開定義                                         */
/********************************************************/

 



extern void Reset_Handler( void );    /*リセットハンドラ*/
extern void dispatch_entry( void );   /*ディスパッチャ*/
extern void systimer_handler( void ); /*割り込みハンドラ*/

#define SCB_ICSR    0xE000ED04 /* 割り込み制御レジスタ */
#define ICSR_PENDSVSET (1 << 28) /* PendSV pedingヒット */

static inline void dispatch( void )
{
    out_w( SCB_ICSR, ICSR_PENDSVSET ); /* pendSV発生 */
}


/* タスクコンテキスト生成 */
extern void *make_context( u4 *sp, UINT ssize, void (*fp)()); 





/* イベントフラグ管理情報 */
typedef struct st_flgcb
{
    KSSTAT state;  /* イベントフラグ状態 */
    UINT   flgptn; /* イベントフラグ値 */
} FLGCB;

/* セマフォ管理情報 */
typedef struct semaphore_control_block
{
    KSSTAT state;  /* セマフォ状態 */
    INT    semcnt; /* セマフォ値 */
    INT    maxsem; /* セマフォ最大値 */
} SEMCB;

/* OSメイン関数 */
extern int main( void );

/* ユーザーメイン関数 */
extern int usermain( void );

#endif
/********************************************************/
/* EOF                                                  */
/********************************************************/
