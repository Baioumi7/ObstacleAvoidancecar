/*
 * Timer_config.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Kimo Store
 */

#ifndef MCAL_TIMER_DRIVER_TIMER_CONFIG_H_
#define MCAL_TIMER_DRIVER_TIMER_CONFIG_H_

#include "Timer_interface.h"

/* PreScaller Options
 * 1)    (Timer stopped )
 * 2)    1 no Prescaller  (Fcpu)
 * 3)    8     Prescaler  (Fcpu / 8)
 * 4)    64    Prescaller (Fcpu / 64)
 * 5)    256   Preescaller  (Fcpu / 256)
 * 6)    1024  Prescaller  (Fcpu / 1024)
 * 6)   */

#define Timer0_Prescaler 1

#define Timer1_Prescaler   8

#define Timer2_Prescaler  64


/* For Timer 1 Input Capture Unit*/
typedef enum
{
	ICU_Falling,
	ICU_Rising
}ICU_Edge;

/* For Out Compare without PWM  .. OC0 Toggle , Clear , Set */

/* Options
 * 1) toggleOC0
 * 2) clearOC0
 * 3) setOC0
 * 4) OC0_Disconnected

 */
#define OCO_Response toggleOC0

/* Options
 * 1) toggleOC2
 * 2) clearOC2
 * 3) setOC2
 * 4) OC2_Disconnected

 */
#define OC2_Response toggleOC2

/* Options
 * 1) toggleOC1A
 * 2) clearOC1A
 * 3) setOC1A
 * 4) OC1A_Disconnected

 */
#define OC1A_Response toggleOC1A

/* Options
 * 1) toggleOC1B
 * 2) clearOC1B
 * 3) setOC1B
 * 4) OC1B_Disconnected

 */
#define OC1B_Response toggleOC1B

/* Options
 * 0 --> OUTCOMPARE  OFF
 * 1 --> OUTCOMPARE  ON
*/

#define Timer1OutCompareA 1
#define Timer1OutCompareB 1

/*Options
 * 1) T0_Inverting
 * 2) T0_Noninverting
 */
#define FastPwmModeTimer0 T0_Noninverting

/*Options
 * 1) T2_Inverting
 * 2) T2_Noninverting
 */

#define FastPwmModeTimer2 T2_Noninverting

#endif /* MCAL_TIMER_DRIVER_TIMER_CONFIG_H_ */
