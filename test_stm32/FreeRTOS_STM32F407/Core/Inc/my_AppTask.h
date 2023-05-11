/*
 * my_AppTask.h
 *
 *  Created on: Feb 7, 2023
 *      Author: arge12
 */

#ifndef INC_MY_APPTASK_H_
#define INC_MY_APPTASK_H_

#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

extern TaskHandle_t task1;
extern TaskHandle_t task2;



// Idle Hook
void vApplicationIdleHook(void);

// task prototypes
void task_100ms(void *param);
void task_200ms(void *param);
void vTaskFunction(void *pvParameters);
void vPrintString(const char *pcString);


#endif /* INC_MY_APPTASK_H_ */
