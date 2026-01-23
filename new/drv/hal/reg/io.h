/* io.h */
/*
#define GPIO_BIT(n)     (1U << (n))

static inline u1 gpio_read(u32 gpio)
{
    return (in_w(GPIO_IN) & GPIO_BIT(gpio)) != 0U;
}

static inline void gpio_set(u32 gpio)
{
    out_w(GPIO_OUT_SET, GPIO_BIT(gpio));
}

static inline void gpio_clr(u32 gpio)
{
    out_w(GPIO_OUT_CLR, GPIO_BIT(gpio));
}
*/


/*などを定義予定*/

/* btn_drv.cなどで以下のように使えるように．
u1 u1g_firstbtn_get(void)
{
    return gpio_read(FIRST_BTN_GPIO);
}
*/