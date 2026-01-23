/*hal/gpio/rp24_gpio.h*/

#define FIRST_LED_GPIO   (18)
#define SECOND_LED_GPIO  (19)
#define THIRD_LED_GPIO   (20)
#define FOURTH_LED_GPIO  (21)

#define FIRST_BTN_GPIO  (18)
#define SECOND_BTN_GPIO (19) 
#define THIRD_BTN_GPIO  (20)
#define FOURTH_BTN_GPIO (21)

#define GPIO_BIT(n)   (1U << (n))

#define BTN_READ(gpio)   ((in_w(GPIO_IN) & GPIO_BIT(gpio)) != 0U)

#define LED_ON(gpio)     out_w(GPIO_OUT_SET, GPIO_BIT(gpio))
#define LED_OFF(gpio)    out_w(GPIO_OUT_CLR, GPIO_BIT(gpio))