#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"

// Function to configure the system clock to 120 MHz
void ConfigureSystemClock(void) {
    // Set the system clock to 120 MHz
    SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                        SYSCTL_OSC_MAIN |
                        SYSCTL_USE_PLL |
                        SYSCTL_CFG_VCO_480), 120000000);
}

int main(void) {
    // Configure the system clock
    ConfigureSystemClock();
    // Other initializations and configurations will go here
    while (1) {
        // Main loop
    }
}

// Enable and Configure GPIOs

#define LED_RED     GPIO_PIN_1
#define LED_GREEN   GPIO_PIN_3
#define LED_BLUE    GPIO_PIN_2
#define BUTTONS     (GPIO_PIN_4 | GPIO_PIN_0)  // Assuming buttons are connected to these pins

void ConfigureGPIO(void) {
    // Enable the GPIO port for the LEDs and buttons
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)) {}

    // Configure the GPIO pins for the LEDs as outputs
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, LED_RED | LED_GREEN | LED_BLUE);

    // Configure the GPIO pins for the buttons as inputs with pull-up resistors
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, BUTTONS);
    GPIOPadConfigSet(GPIO_PORTF_BASE, BUTTONS, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}

//Enable and Configure SysTick Timer @ 10ms

void SysTickHandler(void) {
    // Increment the tick count or set a flag for the scheduler
}

void ConfigureSysTick(void) {
    // Set the reload value to generate an interrupt every 10ms
    SysTickPeriodSet(120000000 / 100);  // 120 MHz / 100 = 10 ms
    SysTickIntRegister(SysTickHandler);
    SysTickIntEnable();
    SysTickEnable();
}

//Implement the Basic Scheduler with 3 Tasks

volatile uint32_t g_ticks = 0;

void SysTickHandler(void) {
    g_ticks++;
}

void Task_0(void) {
    // Task that runs every 10ms
}

void Task_1(void) {
    // Task that runs every 20ms, reads the buttons
    static uint32_t lastRun = 0;
    if ((g_ticks - lastRun) >= 2) { // 20ms = 2 * 10ms
        lastRun = g_ticks;
        // Read buttons and store their states
        uint8_t buttonStates = GPIOPinRead(GPIO_PORTF_BASE, BUTTONS);
        // Process button states
    }
}

void Task_2(void) {
    // Task that runs every 100ms, controls LEDs based on button values
    static uint32_t lastRun = 0;
    if ((g_ticks - lastRun) >= 10) { // 100ms = 10 * 10ms
        lastRun = g_ticks;
        // Control LEDs based on button values
    }
}

void IdleTask(void) {
    // Idle task, can be used for low-priority operations
}

int main(void) {
    // Configure the system clock
    ConfigureSystemClock();
    // Configure GPIOs
    ConfigureGPIO();
    // Configure SysTick
    ConfigureSysTick();
    // Enable interrupts
    IntMasterEnable();

    while (1) {
        // Scheduler
        Task_0();  // Runs every 10ms
        Task_1();  // Runs every 20ms
        Task_2();  // Runs every 100ms
        IdleTask(); // Runs when no other task is running
    }
}

