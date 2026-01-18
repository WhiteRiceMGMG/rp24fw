/* task_sync.c                                          */
/********************************************************/
/* object    | タスク付属同期機能                       */
/* abstract  | タスク付属同期機能定義                   */
/* edit his  | 2026/1/2 新規作成                        */
/*           |                                          */
/********************************************************/
/********************************************************/
/* ヘッダーインクルード                                 */
/********************************************************/
#include <rp24knl.h>
#include <knldef.h> 

/********************************************************/
/* 外部公開関数定義                                     */
/********************************************************/

/********************************************************/
/* 関数   | ER tk_dly_tsk( RELTIM dlytim )              */
/* 説明   | タスクの実行遅延API                         */
/* 引数   | RELTIM dlytim                               */
/* 戻り値 | semid                                       */
/********************************************************/
ER tk_dly_tsk( RELTIM dlytim )
{
    UINT    intsts;
    ER      err = E_OK;

    DI(intsts);     
    if(dlytim > 0) /* 遅延時間チェック */
    {
        /* レディーキューから自分を外す */
        tqueue_remove_top
        (&ready_queue[cur_task->itskpri]); 

        /* タスク状態をWAITに遷移 */
        cur_task -> state   = TS_WAIT;
        
        /* 待ち要因を遅延に設定 */
        cur_task -> waifct  = TWFCT_DLY;  
        
        /* 待ち時間設定 */
        cur_task -> waitim  = dlytim + TIMER_PERIOD;  

        /* エラー返却先を登録 */
        cur_task -> waierr  = &err;                   

        /* ウェイトキューに追加 */
        tqueue_add_entry(&wait_queue, cur_task);   

        /* スケジューラを起動する */
        scheduler();                               
    }
    EI(intsts);     
    return err;
}

/********************************************************/
/* 関数   | ER tk_slp_tsk( TMO tmout )                  */
/* 説明   | タスク起床待ちAPI                           */
/* 引数   | TMO tmout                                   */
/* 戻り値 | なし                                        */
/********************************************************/
ER tk_slp_tsk( TMO tmout )
{
    UINT    intsts;
    ER      err = E_OK;

    DI(intsts);     

    /* 既に起床要求があったかどうかをチェック */
    if ( cur_task -> wupcnt > 0 ) 
    {
        /* 起床要求を消費して即復帰する */
        cur_task -> wupcnt--;
	}
    else
    {
        /* レディーキューから外す */
        tqueue_remove_top
        (&ready_queue[cur_task->itskpri]);

        /* 状態をWAITに設定 */
        cur_task -> state   = TS_WAIT;
        
        /* 待ち要因をSLPに設定する */
        cur_task -> waifct  = TWFCT_SLP;      
        
        /* 待ち時間を設定する */
        cur_task -> waitim  = (tmout==TMO_FEVR)?tmout:(tmout+TIMER_PERIOD); 

        /* エラー返却先登録 */
        cur_task -> waierr = &err;

        /* ウェイトキュー */
        tqueue_add_entry(&wait_queue, cur_task);

        /* スケジューラ起動 */
        scheduler();
    }
    EI(intsts);
    return err;
}


/********************************************************/
/* 関数   | ER tk_wup_tsk( ID tskid )                   */
/* 説明   | タスクの起床API                             */
/* 引数   | ID tskid                                    */
/* 戻り値 | なし                                        */
/********************************************************/
ER tk_wup_tsk( ID tskid )
{
    TCB	    *tcb;
    UINT    intsts;
    ER      err = E_OK;

    /* IDをチェックする */
    if(tskid <= 0 || tskid > CNF_MAX_TSKID) 
    {
        return E_ID;
    }

    DI(intsts);

    /* 対象TCB取得 */
    tcb = &tcb_tbl[tskid-1];

    /* 寝ているタスクを直接起こす場合 */
    if((tcb->state == TS_WAIT) && (tcb->waifct == TWFCT_SLP)) {

        /* ウェイトキューから削除 */
        tqueue_remove_entry(&wait_queue, tcb);

        /* 状態をREADYに設定する */
        tcb->state	= TS_READY;

        /* 待ち要因を解除する */
        tcb->waifct	= TWFCT_NON;

        /* レディーキューへ追加 */
        tqueue_add_entry(&ready_queue[tcb->itskpri], tcb);
        
        /* スケジューラを起動する */
        scheduler();
    } 
    /* タスクが寝ていない場合起床要求を貯める． */
    else if(tcb->state == TS_READY 
            ||tcb->state == TS_WAIT) 
    {
        tcb->wupcnt++;
    } else 
    {
        err = E_OBJ;
    }

    EI(intsts);
    return err;
}

/********************************************************/
/* EOF                                                  */
/********************************************************/
