/* task_mange.c                                         */
/********************************************************/
/* object    | タスク管理                               */
/* abstract  | タスク管理定義                           */
/* edit his  | 2025/12/23 テンプレート作成              */
/*           |                                          */
/********************************************************/
/********************************************************/
/* ヘッダーインクルード                                 */
/********************************************************/
#include <rp24knl.h>
#include <knldef.h> 

/********************************************************/
/* 内部公開マクロ                                       */
/********************************************************/
/* #define  u1g_SAMPLE_VAL                              */

/********************************************************/
/* 外部公開変数                                         */
/********************************************************/
/* u1 u1g_sample_val                                    */

/********************************************************/
/* 内部公開変数                                         */
/********************************************************/
TCB tcb_tbl[CNF_MAX_TSKID];

/********************************************************/
/* 外部公開関数定義                                     */
/********************************************************/

/********************************************************/
/* 関数   | ID tk_cre_tsk( const T_CTSK *pk_ctsk )      */
/* 説明   | タスク生成API                               */
/* 引数   | T_CTSK *pk_ctsk                             */
/* 戻り値 | tskid                                       */
/********************************************************/
ID tk_cre_tsk( const T_CTSK *pk_ctsk )
{
    UINT intsts; /* 割り込み状態保存用 */
    ID   tskid;  /* 戻り値 */
    INT  i;      /* TCB探索用 */

    /* 未許可属性が混ざっていないか確認．TA_RNG3でリング属性をマスク */
    /* 保護レベルはどれでも可能だが，それ以外はHLNGとUSERBUFのみ */
    if((pk_ctsk -> tskatr & ~TA_RNG3) != (TA_HLNG|TA_USERBUF))
    {
        return E_RSATR;
    }

    /* 優先度チェック */
    if(pk_ctsk -> itskpri <= 0 || pk_ctsk -> itskpri > CNF_MAX_TSKPRI)
    {
        return E_PAR;
    }

    /* スタックサイズチェック */
    if(pk_ctsk -> stksz == 0)
    {
        return E_PAR;
    }

    DI(intsts);

    /* 空きTCB探索．TS_NONEXISTは未使用スロット */
    for(i = 0; i < CNF_MAX_TSKID; i++)
    {
        if(tcb_tbl[i].state == TS_NONEXIST)
        {
            break;
        }
    }

    /* TCBの空き探索で該当した場合 */
    if(i < CNF_MAX_TSKID)
    {
        tcb_tbl[i].state   = TS_DORMANT;
        tcb_tbl[i].pre     = NULL;
        tcb_tbl[i].next    = NULL;

        /* タスク情報をコピー */
        tcb_tbl[i].tskadr  = pk_ctsk -> task;    /*  エントリ関数 */
        tcb_tbl[i].itskpri = pk_ctsk -> itskpri; /* 優先度 */
        tcb_tbl[i].stksz   = pk_ctsk -> stksz;   /* 提供スタック */
        tcb_tbl[i].stkadr  = pk_ctsk -> bufptr;

        tskid = i+1; /* タスクID決定 */
    } 
    else  /* 空きがなかった場合 */
    {
        tskid = (ID)E_LIMIT; /* タスク数上限オーバー */
    }
    EI(intsts);
    return tskid;
}

/********************************************************/
/* 関数   | ER tk_sta_tsk( ID tskid, INT stacd )        */
/* 説明   | タスク実行API                               */
/* 引数   | ID tskid, INT stacd                         */
/* 戻り値 | err                                         */
/********************************************************/
ER tk_sta_tsk( ID tskid, INT stacd )
{
    TCB  *tcb;
    UINT intsts;
    ER err = E_OK;
    
    /* IDチェック．範囲外はエラー返す */
    if(tskid <= 0 || tskid > CNF_MAX_TSKID)
    {
        return E_ID;
    }
    DI(intsts);

    /* TCB取得 */
    tcb = &tcb_tbl[tskid - 1];

    /* 状態チェック．休眠時のみ起動可 */
    if(tcb -> state == TS_DORMANT)
    {
        tcb -> state = TS_READY; /* READYへ遷移 */
        /* コンテキスト生成  */
        tcb -> context = make_context
        (
            tcb -> stkadr, 
            tcb -> stksz, 
            tcb -> tskadr
        );

        /* レディーキューに追加．高優先度ほど先に実行 */
        tqueue_add_entry(&ready_queue[tcb -> itskpri], tcb);
        scheduler(); /* スケジューラ起動 */
    }
    else /* DORMANT以外で起動時 */
    {
        err = E_OBJ;
    }

    EI(intsts);
    return err;
}


/********************************************************/
/* 関数   | void tk_ext_tsk( void )                     */
/* 説明   | タスクの動作終了API                         */
/* 引数   | なし                                        */
/* 戻り値 | なし                                        */
/********************************************************/
void tk_ext_tsk( void )
{
    UINT	intsts;

    DI(intsts); 

    /* 状態を休眠へ */
    cur_task->state	= TS_DORMANT; 

    /* レディーキューから削除  */
    tqueue_remove_top(&ready_queue[cur_task->itskpri]);

    /* 再スケジューリング */
    scheduler(); 
    EI(intsts);
}

/********************************************************/
/* EOF                                                  */
/********************************************************/
