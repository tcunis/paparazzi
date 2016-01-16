/*
 * Copyright (C) Torbjoern Cunis <t.cunis@tudelft.nl>
 *
 * The DelFly Control module provides submodules and functions necessary
 * for control of the DelFly:
 *
 *  -	Guidance h/v submodule implements guidance_module.h in order to
 *    	control vertical and horizontal position and velocity;
 *  - 	Speed/thrust Control submodule controls commanded horizontal and
 *    	vertical acceleration.
 *
 * This file is part of paparazzi:
 *
 * paparazzi is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * paparazzi is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with paparazzi; see the file COPYING.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
/**
 * @file "modules/delfly_control/delfly_control.h"
 * @author Torbjoern Cunis
 * 
 */

#ifndef DELFLY_CONTROL_H
#define DELFLY_CONTROL_H


#include "generated/modules.h"

#include "math/pprz_geodetic_int.h"
#include "std.h"



#define GUIDANCE_H_MODE_MODULE_SETTING 	GUIDANCE_H_MODE_MODULE
#define GUIDANCE_V_MODE_MODULE_SETTING 	GUIDANCE_V_MODE_MODULE


#ifndef DELFLY_MODEL_RUN_PERIOD
#define DELFLY_MODEL_RUN_PERIOD         DELFLY_CONTROL_RUN_PERIOD
#define DELFLY_MODEL_RUN_FREQ           DELFLY_CONTROL_RUN_FREQ
#endif

#ifndef SPEED_CONTROL_RUN_PERIOD
#define SPEED_CONTROL_RUN_PERIOD        DELFLY_CONTROL_RUN_PERIOD
#define SPEED_CONTROL_RUN_FREQ          DELFLY_CONTROL_RUN_FREQ
#endif

#ifndef STATE_ESTIMATION_RUN_PERIOD
#define STATE_ESTIMATION_RUN_PERIOD     DELFLY_CONTROL_RUN_PERIOD
#define STATE_ESTIMATION_RUN_FREQ       DELFLY_CONTROL_RUN_FREQ
#endif



/*    general module functions      */
extern void delfly_control_init(void);
extern void delfly_control_start(void);
extern void delfly_control_stop(void);

/*    delfly control periodic       */
extern void delfly_control_run(void);
extern void delfly_control_module_run(void);


/*    speed/thrust control          */
extern void speed_control_init(void);
extern void speed_control_enter(void);
extern void speed_control_run(bool_t in_flight);


/*	  state filter                  */
extern void ins_module_int_init(void);
extern void ins_module_int_reset_local_origin(void);
extern void ins_module_int_propagate(struct Int32Vect3* acc, float dt);
extern void ins_module_int_update_gps(struct NedCoor_i* pos, struct NedCoor_i* vel, float dt);


/*    guidance control h/v          */
//extern void guidance_control_start(void);
//extern void guidance_control_stop(void);

extern void guidance_h_module_init(void);
extern void guidance_h_module_enter(void);
extern void guidance_h_module_read_rc(void);
extern void guidance_h_module_run(bool_t);

extern void guidance_v_module_init(void);
extern void guidance_v_module_enter(void);
extern void guidance_v_module_run(bool_t);


#endif
