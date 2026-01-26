/* ﾒﾓﾒﾓ:OSAPIとmcu依存が混ざっているため分離するべき．  */
/* apidef.h                                             */
/********************************************************/
/* object    | API定義ヘッダー                          */
/* abstract  | APIに用いる定義                          */
/* edit his  | 2025/12/16 新規作成                      */
/*           |                                          */
/********************************************************/
#ifndef APIDEF_H
#define APIDEF_H

/********************************************************/
/* 外部公開定義                                         */
/********************************************************/






/* タスクの待ち属性 */
#define TA_TFIFO     0x00000000 /* 待機をFIFO管理 */
#define TA_TPRI      0x00000001 /* 待機を優先度管理 */
#define TA_FIRST     0x00000000 /* 待機行列タスク優先 */
#define TA_CNT       0x00000002 /* 要求数少タスク優先 */
#define TA_WSGL      0x00000000 /* 複数タスク待機禁止 */
#define TA_WMUL      0x00000008 /* 複数タスク待機許可 */




/* イベントフラグ生成情報 */
typedef struct t_cflg
{
    ATR    flgatr;  /* イベントフラグ属性 */
    UINT   iflgptn; /* イベントフラグ初期値 */
} T_CFLG;

/* イベントフラグAPI */
ID tk_cre_flg( const T_CFLG *pk_cflg );
ER tk_set_flg( ID flgid, UINT setptn );
ER tk_clr_flg( ID flgid, UINT clrptn );



ER tk_wai_flg( ID flgid, UINT waiptn, UINT wfmode, UINT *p_flgptn, TMO tmout );

/* セマフォ生成情報 */
typedef struct t_csem
{
    ATR    sematr;  /* セマフォ属性 */
    INT    isemcnt; /* セマフォ資源数の初期値 */
    INT    maxsem;  /* セマフォ資源数最大値 */
} T_CSEM;

/* セマフォAPI */
ID tk_cre_sem( const T_CSEM *pk_csem );
ER tk_sig_sem( ID semid, INT cnt );
ER tk_wai_sem( ID semid, INT cnt, TMO tmout );

#endif






/********************************************************/
/* EOF                                                  */
/********************************************************/
