/*========================================================================================
===========================   - DC_Motor_program.c		     =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/


/*===========_MCAL_INCLUDES  ===========*/
#include "DcMotor.h"
#include "DcMotorCfg.h"
/*======================================*/
// Initiate the selected motor pins
void H_DcMotorInit(u8 MotorNum)
{
	switch(MotorNum)
	{
		case MOTOR_1:
					MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_PIN_1, MODE_OUTPUT);
					MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_PIN_2, MODE_OUTPUT);
					MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_PIN_EN, MODE_OUTPUT);
					H_DcMotorStop(MOTOR_1);
	    break;
		case MOTOR_2:
				    MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_PIN_1_B, MODE_OUTPUT);
				    MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_PIN_2_B, MODE_OUTPUT);
				    MGPIO_vSetPinMode(DC_MOTOR_PORT, DC_MOTOR_PIN_EN_B, MODE_OUTPUT);
				    H_DcMotorStop(MOTOR_2);
		break;
		default:
		break;
	}
}

// Activate motor in the selected direction
void H_DcMotorMove(u8 MotorNum, u8 Direction)
{
	switch(MotorNum)
	{
		case MOTOR_1:
		switch(Direction)
		{
			case DIRECTION_1:
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_1, HIGH);
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_2, LOW);
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN, HIGH);
			break;
			case DIRECTION_2:
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_1, LOW);
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_2, HIGH);
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN, HIGH);
			break;
			default:
			break;
		}
		break;
		case MOTOR_2:
		switch(Direction)
		{
			case DIRECTION_1:
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_1_B, HIGH);
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_2_B, LOW);
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN_B, HIGH);
			break;
			case DIRECTION_2:
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_1_B, LOW);
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_2_B, HIGH);
							MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN_B, HIGH);
			break;
			default:
			break;
		}
		break;
		default:
		break;
	}
}

// Stop motor
void H_DcMotorStop(u8 MotorNum)
{
	switch(MotorNum)
	{
		case MOTOR_1:
					MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_1,LOW);
					MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_2, LOW);
					MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN, LOW);
					Stop_PWM();
		break;
		case MOTOR_2:
					MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_1_B,LOW);
					MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_2_B, LOW);
					MGPIO_vWriteData(DC_MOTOR_PORT, DC_MOTOR_PIN_EN_B, LOW);
					Stop_PWM();
		break;
		default:
		break;
	}
}

// generating PWM signal of GPIO_PIN_0 according to speed
void H_DcMotorSpeed(u8 MotorSpeed, u8 MotorNum)
{
	switch(MotorNum)
	{
		case MOTOR_1: Generate_PWM(MotorSpeed, PWM_PERIOD_MS, DC_MOTOR_PIN_EN);     break;
		case MOTOR_2: Generate_PWM(MotorSpeed, PWM_PERIOD_MS, DC_MOTOR_PIN_EN_B);   break;
		default:                                                                    break;
	}
}
