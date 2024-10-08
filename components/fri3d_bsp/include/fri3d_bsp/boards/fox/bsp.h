#pragma once

#include "driver/gpio.h"
#include "driver/spi_common.h"
#include "esp_lcd_types.h"
#include "hal/adc_types.h"

// Capabilities
#define BSP_CAPS_ADC           1
#define BSP_CAPS_DISPLAY       1
#define BSP_CAPS_TOUCH         0
#define BSP_CAPS_BUTTONS       1
#define BSP_CAPS_JOYSTICK      1
#define BSP_CAPS_BUZZER        1
#define BSP_CAPS_AUDIO         0
#define BSP_CAPS_AUDIO_SPEAKER 0
#define BSP_CAPS_AUDIO_MIC     0
#define BSP_CAPS_LED           1
#define BSP_CAPS_SDCARD        0
#define BSP_CAPS_IMU           0

// Pinout

// Leds
#define BSP_LED_RGB_GPIO       (GPIO_NUM_12)
#define BSP_LED_NUM            (5)

/* Buttons */
#define BSP_BUTTON_BOOT_IO     (GPIO_NUM_0)
#define BSP_BUTTON_MENU_IO     (GPIO_NUM_45)
#define BSP_BUTTON_A_IO        (GPIO_NUM_39)
#define BSP_BUTTON_B_IO        (GPIO_NUM_40)
#define BSP_BUTTON_X_IO        (GPIO_NUM_38)
#define BSP_BUTTON_Y_IO        (GPIO_NUM_41)

/* Buttons */
typedef enum
{
    BSP_BUTTON_BOOT = 0,
    BSP_BUTTON_MENU,
    BSP_BUTTON_A,
    BSP_BUTTON_B,
    BSP_BUTTON_X,
    BSP_BUTTON_Y,
    BSP_BUTTON_NUM
} bsp_button_t;

/* Button mappings */
#define BSP_KEY_ENTER             BSP_BUTTON_A
#define BSP_KEY_ESC               BSP_BUTTON_B
#define BSP_KEY_NEXT              BSP_BUTTON_X
#define BSP_KEY_PREV              BSP_BUTTON_Y
#define BSP_KEY_HOME              BSP_BUTTON_MENU
#define BSP_KEY_END               BSP_BUTTON_BOOT

/* Joystick */
#define BSP_JOYSTICK_AXIS_X_IO    (GPIO_NUM_1)
#define BSP_JOYSTICK_AXIS_Y_IO    (GPIO_NUM_3)

#define BSP_JOYSTICK_AXIS_X_ATTEN (ADC_ATTEN_DB_12)
#define BSP_JOYSTICK_AXIS_Y_ATTEN (ADC_ATTEN_DB_12)

/* Joystick axis */
typedef enum
{
    BSP_JOYSTICK_AXIS_X = 0,
    BSP_JOYSTICK_AXIS_Y,
    BSP_JOYSTICK_AXIS_NUM
} bsp_joystick_t;

/* ADC */
#define BSP_ADC_UNIT ADC_UNIT_1

typedef enum
{
    BSP_ADC_CHANNEL_JOYSTICK_AXIS_X = 0,
    BSP_ADC_CHANNEL_JOYSTICK_AXIS_Y,
    BSP_ADC_CHANNEL_NUM
} bsp_adc_channel_t;

/* Buzzer */
#define BSP_BUZZER_GPIO    (GPIO_NUM_46)

/* SPI */
#define BSP_SPI_MOSI       (GPIO_NUM_6)
#define BSP_SPI_MISO       (GPIO_NUM_8)
#define BSP_SPI_SCK        (GPIO_NUM_7)

#define BSP_SPI_HOST       (SPI3_HOST)
#define BSP_SPI_BAUDRATE   (20 * 1000 * 1000)

/* Display */
#define BSP_LCD_RST        (GPIO_NUM_48)
#define BSP_LCD_DC         (GPIO_NUM_4)
#define BSP_LCD_CS         (GPIO_NUM_5)

#define BSP_LCD_WIDTH      (296)
#define BSP_LCD_HEIGHT     (240)
#define BSP_LCD_SWAP_XY    (true)
#define BSP_LCD_MIRROR_X   (false)
#define BSP_LCD_MIRROR_Y   (false)
#define BSP_LCD_INVERT     (false)
#define BSP_LCD_RGB_ORDER  (LCD_RGB_ELEMENT_ORDER_BGR)
#define BSP_LCD_BPP        (16)
#define BSP_LCD_CMD_BITS   (8)
#define BSP_LCD_PARAM_BITS (8)
