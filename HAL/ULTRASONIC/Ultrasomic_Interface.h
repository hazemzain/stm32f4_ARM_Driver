/*========================================================================================
===========================   - Ultrasonic_Interface.h    =============================
===========================   - Created: 30/6/2022	     =============================
===========================   - Author: Wave4 G3    =============================
===========================   - Version : _1_		     =============================
===========================   - Note :
========================================================================================*/

#ifndef Ultrasonic_INTERFACE_H_
#define Ultrasonic_INTERFACE_H_
/*US port option*/
#define _PORT_A   (0U)
#define _PORT_B   (1U)
#define _PORT_C   (2U)
#define _PORT_D   (3U)
#define _PORT_E   (4U)
#define _PORT_H   (5U)
/*US_Pin Option*/
#define _PIN_0    (0U)
#define _PIN_1    (1U)
#define _PIN_2    (2U)
#define _PIN_3    (3U)
#define _PIN_4    (4U)
#define _PIN_5    (5U)
#define _PIN_6    (6U)
#define _PIN_7    (7U)
#define _PIN_8    (8U)
#define _PIN_9    (9U)
#define _PIN_10   (10U)
#define _PIN_11   (11U)
#define _PIN_12   (12U)
#define _PIN_13   (13U)
#define _PIN_14   (14U)
#define _PIN_15   (15U)
void H_VUltrasonicInit(void);
u32  H_u16USRead(void);

#endif
