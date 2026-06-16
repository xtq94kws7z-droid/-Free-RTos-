#ifndef APP_TASKS_H
#define APP_TASKS_H

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include <stdint.h>

/* ===== 数据结构 ===== */
typedef struct {
    float    temp;
    float    humi;
    float    press;
    uint8_t  status;     /* 0=正常  1=传感器故障 */
    uint32_t tick;
} SensorData_t;

typedef struct {
    uint8_t  event;
    uint32_t tick;
} ButtonEvent_t;

/* ===== 系统模式 ===== */
#define MODE_NORMAL   0   /* 温度 + 湿度 */
#define MODE_PRESSURE 1   /* 气压 */
#define MODE_DETAIL   2   /* 系统信息 */
#define MODE_COUNT    3

/* ===== 引脚定义 ===== */
#define BTN_PORT  GPIOA
#define BTN_PIN   GPIO_PIN_1
#define LED_PORT  GPIOB
#define LED_PIN   GPIO_PIN_12

/* ===== 时间参数 ===== */
#define SENSOR_PERIOD_MS  1000
#define DISPLAY_PERIOD_MS 200
#define UART_PERIOD_MS    1000
#define KEY_SCAN_MS       20
#define LED_TOGGLE_MS     500
#define BTN_DEBOUNCE_MS   200

/* ===== 全局变量 ===== */
extern QueueHandle_t xSensorQueue;
extern volatile uint8_t g_system_mode;

#endif /* APP_TASKS_H */
