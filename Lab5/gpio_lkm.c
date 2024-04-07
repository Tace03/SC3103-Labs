#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/interrupt.h>

static unsigned int ledGreen = 4;
static unsigned int pushButton = 11;
static unsigned int irqNumber;
static bool ledOn = 0;

static irq_handler_t rpi_gpio_isr(unsigned int irq, void *dev_id, struct pt_regs *regs)
{
    // need to fill smth here

    // in lab manual 
    // toggle the LED state
    gpio_set_value(ledGreen, 1);
    usleep(50000);
    gpio_set_value(ledGreen, 0);
    usleep(50000);
    // set LED accordingly
    printk(KERN_ALERT "GPIO Interrupt!\n");
    return (irq_handler_t) IRQ_HANDLED;
}

static void __exit rpi_gpio_exit()
{
    gpio_set_value(ledGreen, 0);
    gpio_free(ledGreen);
    gpio_free(pushButton);
    free_irq(irqNumber, NULL);
    printk(KERN_ALERT "Goodbye from the LKM\n");
}

static int __init rpi_gpio_init()
{
    int result = 0;
    printk(KERN_ALERT "Initializing the GPIO LKM\n");

    if(!gpio_is_valid(ledGreen)){
        printk(KERN_ALERT "Pin LedGreen is not usable\n");
        return -1;
    }
    if(!gpio_is_valid(pushButton)){
        printk(KERN_ALERT "Pin pushButton is not usable\n");
        return -1;
    }

    ledOn = true;
    gpio_request(ledGreen, "sysfs");
    gpio_direction_output(ledGreen, ledOn);
    
    gpio_request(pushButton, "sysfs");
    gpio_direction_input(pushButton);
    gpio_set_debounce(pushButton, 1000);

    irqNumber = gpio_to_irq(pushButton);
    printk(KERN_ALERT "Button mapped to IRQ: %d\n", irqNumber);

    result = request_irq(
        irqNumber,
        (irq_handler_t) rpi_gpio_isr,
        IRQF_TRIGGER_RISING,
        "rpi_gpio_handler",
        NULL
    );
    return result;
}

module_init(rpi_gpio_init);
module_exit(rpi_gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CE3103");
MODULE_DESCRIPTION("GPIO module");
MODULE_VERSION("V1");