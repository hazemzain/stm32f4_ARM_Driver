/*========================================================================================
===========================   - DcMotor.h     =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "STD_TYPES.h"
#include "GPIO_Interface.h"
#include "PWM_Interface.h"
#include "DcMotorCfg.h"

void H_DcMotorInit(u8 MotorNum);
void H_DcMotorMove(u8 MotorNum, u8 Direction);
void H_DcMotorStop(u8 MotorNum);
void H_DcMotorSpeed(u8 MotorSpeed, u8 MotorNum);

#endif /* DCMOTOR_H_ */
