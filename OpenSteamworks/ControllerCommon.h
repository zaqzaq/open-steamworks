//==========================  Open Steamworks  ================================
//
// This file is part of the Open Steamworks project. All individuals associated
// with this project do not claim ownership of the contents
// 
// The code, comments, and all related files, projects, resources,
// redistributables included with this project are Copyright Valve Corporation.
// Additionally, Valve, the Valve logo, Half-Life, the Half-Life logo, the
// Lambda logo, Steam, the Steam logo, Team Fortress, the Team Fortress logo,
// Opposing Force, Day of Defeat, the Day of Defeat logo, Counter-Strike, the
// Counter-Strike logo, Source, the Source logo, and Counter-Strike Condition
// Zero are trademarks and or registered trademarks of Valve Corporation.
// All other trademarks are property of their respective owners.
//
//=============================================================================

#ifndef CONTROLLERCOMMON_H
#define CONTROLLERCOMMON_H
#ifdef _WIN32
#pragma once
#endif

#define CLIENTSTEAMCONTROLLER_INTERFACE_VERSION "CLIENTSTEAMCONTROLLER_INTERFACE_VERSION_000"

#define STEAMCONTROLLER_INTERFACE_VERSION_003 "SteamController003"
#define STEAMCONTROLLER_INTERFACE_VERSION_004 "SteamController004"

#define STEAM_RIGHT_TRIGGER_MASK			0x0000000000000001l
#define STEAM_LEFT_TRIGGER_MASK				0x0000000000000002l
#define STEAM_RIGHT_BUMPER_MASK			 	0x0000000000000004l
#define STEAM_LEFT_BUMPER_MASK			  	0x0000000000000008l
#define STEAM_BUTTON_0_MASK				 	0x0000000000000010l
#define STEAM_BUTTON_1_MASK				 	0x0000000000000020l
#define STEAM_BUTTON_2_MASK				 	0x0000000000000040l
#define STEAM_BUTTON_3_MASK				 	0x0000000000000080l
#define STEAM_TOUCH_0_MASK				  	0x0000000000000100l
#define STEAM_TOUCH_1_MASK				  	0x0000000000000200l
#define STEAM_TOUCH_2_MASK				  	0x0000000000000400l
#define STEAM_TOUCH_3_MASK				  	0x0000000000000800l
#define STEAM_BUTTON_MENU_MASK			  	0x0000000000001000l
#define STEAM_BUTTON_STEAM_MASK			 	0x0000000000002000l
#define STEAM_BUTTON_ESCAPE_MASK			0x0000000000004000l
#define STEAM_BUTTON_BACK_LEFT_MASK		 	0x0000000000008000l
#define STEAM_BUTTON_BACK_RIGHT_MASK		0x0000000000010000l
#define STEAM_BUTTON_LEFTPAD_CLICKED_MASK   0x0000000000020000l
#define STEAM_BUTTON_RIGHTPAD_CLICKED_MASK  0x0000000000040000l
#define STEAM_LEFTPAD_FINGERDOWN_MASK	   	0x0000000000080000l
#define STEAM_RIGHTPAD_FINGERDOWN_MASK	  	0x0000000000100000l

struct SteamControllerState_t
{
	// If packet num matches that on your prior call, then the controller state hasn't been changed since 
	// your last call and there is no need to process it
	uint32 unPacketNum;

	// bit flags for each of the buttons
	uint64 ulButtons;

	// Left pad coordinates
	short sLeftPadX;
	short sLeftPadY;

	// Right pad coordinates
	short sRightPadX;
	short sRightPadY;

};

enum ESteamControllerPad
{
	k_ESteamControllerPad_Left,
	k_ESteamControllerPad_Right
};

enum EControllerActionOrigin
{
	// no idea
};

enum EControllerType
{
	k_EControllerTypeController_none = -1,
	k_EControllerTypeController_unknown,
	k_EControllerTypeController_steamcontroller_unknown,
	k_EControllerTypeController_steamcontroller_gordon,
	k_EControllerTypeController_steamcontroller_headcrab,
	k_EControllerTypeController_generic = 30,
	k_EControllerTypeController_xbox360,
	k_EControllerTypeController_xboxone,
	k_EControllerTypeController_ps3,
	k_EControllerTypeController_ps4,
	k_EControllerTypeController_wii,
	k_EControllerTypeController_apple,
};

enum EControllerActivationType
{
	k_EControllerActivationTypeNone = 0,
	k_EControllerActivationTypeFull_press,
	k_EControllerActivationTypeSoft_press,
	k_EControllerActivationTypeStart_press,
	k_EControllerActivationTypeRelease,
	k_EControllerActivationTypeLong_press,
	k_EControllerActivationTypeDouble_press,
	k_EControllerActivationTypeAnalog,
};

enum EControllerSource
{
	k_EControllerSourceNone = 0,
	k_EControllerSourceLeft_trackpad,
	k_EControllerSourceRight_trackpad,
	k_EControllerSourceJoystick,
	k_EControllerSourceButton_diamond,
	k_EControllerSourceSwitch,
	k_EControllerSourceLeft_trigger,
	k_EControllerSourceRight_trigger,
	k_EControllerSourceGyro,
	k_EControllerSourceCenter_trackpad,
	k_EControllerSourceRight_joystick,
	k_EControllerSourceDpad,
};

enum EControllerSourceMode
{
	k_EControllerSourceModeNone = 0,
	k_EControllerSourceModeDpad,
	k_EControllerSourceModeButtons,
	k_EControllerSourceModeFour_buttons,
	k_EControllerSourceModeAbsolute_mouse,
	k_EControllerSourceModeRelative_mouse,
	k_EControllerSourceModeJoystick_move,
	k_EControllerSourceModeJoystick_mouse,
	k_EControllerSourceModeJoystick_camera,
	k_EControllerSourceModeScrollwheel,
	k_EControllerSourceModeTrigger,
	k_EControllerSourceModeTouch_menu,
	k_EControllerSourceModeMouse_joystick,
	k_EControllerSourceModeMouse_region,
	k_EControllerSourceModeRadial_menu,
	k_EControllerSourceModeSingle_button,
	k_EControllerSourceModeSwitches,
};

enum EControllerModeInput
{
	k_EControllerModeInputNone = 0,
	k_EControllerModeInputDpad_north,
	k_EControllerModeInputDpad_northeast,
	k_EControllerModeInputDpad_east,
	k_EControllerModeInputDpad_southeast,
	k_EControllerModeInputDpad_south,
	k_EControllerModeInputDpad_southwest,
	k_EControllerModeInputDpad_west,
	k_EControllerModeInputDpad_northwest,
	k_EControllerModeInputButton_y,
	k_EControllerModeInputButton_b,
	k_EControllerModeInputButton_x,
	k_EControllerModeInputButton_a,
	k_EControllerModeInputClick,
	k_EControllerModeInputDoubletap,
	k_EControllerModeInputEdge,
	k_EControllerModeInputScroll_clockwise,
	k_EControllerModeInputScroll_counterclockwise,
	k_EControllerModeInputTrigger_analog,
	k_EControllerModeInputScroll_wheel_list_0,
	k_EControllerModeInputScroll_wheel_list_1,
	k_EControllerModeInputScroll_wheel_list_2,
	k_EControllerModeInputScroll_wheel_list_3,
	k_EControllerModeInputScroll_wheel_list_4,
	k_EControllerModeInputScroll_wheel_list_5,
	k_EControllerModeInputScroll_wheel_list_6,
	k_EControllerModeInputScroll_wheel_list_7,
	k_EControllerModeInputScroll_wheel_list_8,
	k_EControllerModeInputScroll_wheel_list_9,
	k_EControllerModeInputTouch_menu_button_0,
	k_EControllerModeInputTouch_menu_button_1,
	k_EControllerModeInputTouch_menu_button_2,
	k_EControllerModeInputTouch_menu_button_3,
	k_EControllerModeInputTouch_menu_button_4,
	k_EControllerModeInputTouch_menu_button_5,
	k_EControllerModeInputTouch_menu_button_6,
	k_EControllerModeInputTouch_menu_button_7,
	k_EControllerModeInputTouch_menu_button_8,
	k_EControllerModeInputTouch_menu_button_9,
	k_EControllerModeInputTouch_menu_button_10,
	k_EControllerModeInputTouch_menu_button_11,
	k_EControllerModeInputTouch_menu_button_12,
	k_EControllerModeInputTouch_menu_button_13,
	k_EControllerModeInputTouch_menu_button_14,
	k_EControllerModeInputTouch_menu_button_15,
	k_EControllerModeInputTouch_menu_button_16,
	k_EControllerModeInputTouch_menu_button_17,
	k_EControllerModeInputTouch_menu_button_18,
	k_EControllerModeInputTouch_menu_button_19,
	k_EControllerModeInputTouch_menu_button_20,
	k_EControllerModeInputTouch,
	k_EControllerModeInputButton_menu,
	k_EControllerModeInputButton_escape,
	k_EControllerModeInputLeft_bumper,
	k_EControllerModeInputRight_bumper,
	k_EControllerModeInputButton_back_left,
	k_EControllerModeInputButton_back_right,
	k_EControllerModeInputButton_lpad,
	k_EControllerModeInputButton_rpad,
	k_EControllerModeInputButton_ltrigger,
	k_EControllerModeInputButton_rtrigger,
	k_EControllerModeInputButton_ltrigger_threshold,
	k_EControllerModeInputButton_rtrigger_threshold,
	k_EControllerModeInputButton_joystick,
	k_EControllerModeInputButton_steam,
};

enum EControllerSetting
{
	k_EControllerSettingLeft_trackpad_mode = 0,
	k_EControllerSettingRight_trackpad_mode,
	k_EControllerSettingTrackpad_trigger_data,
	k_EControllerSettingHaptic_intensity,
	k_EControllerSettingRumble_type,
	k_EControllerSettingRumble_intensity,
	k_EControllerSettingEdge_binding_radius,
	k_EControllerSettingOutput_joystick,
	k_EControllerSettingCurve_exponent,
	k_EControllerSettingCustom_curve_exponent,
	k_EControllerSettingSwipe_duration,
	k_EControllerSettingDeadzone_inner_radius,
	k_EControllerSettingDeadzone_outer_radius,
	k_EControllerSettingDeadzone_shape,
	k_EControllerSettingAdaptive_centering,
	k_EControllerSettingVirtual_cap_size,
	k_EControllerSettingVirtual_stick_throw,
	k_EControllerSettingAnti_deadzone,
	k_EControllerSettingAnti_deadzone_buffer,
	k_EControllerSettingEdge_binding_invert,
	k_EControllerSettingOutput_axis,
	k_EControllerSettingRequires_click,
	k_EControllerSettingDeadzone,
	k_EControllerSettingLayout,
	k_EControllerSettingHold_repeats,
	k_EControllerSettingHold_repeat_inverval,
	k_EControllerSettingAnalog_emulation_duty_cycle_pct,
	k_EControllerSettingAnalog_emulation_period,
	k_EControllerSettingSensitivity,
	k_EControllerSettingSensitivity_vert_scale,
	k_EControllerSettingSensitivity_horiz_scale,
	k_EControllerSettingTrackball,
	k_EControllerSettingFriction,
	k_EControllerSettingFriction_vert_scale,
	k_EControllerSettingAcceleration,
	k_EControllerSettingDoubletap,
	k_EControllerSettingDoubletap_beep,
	k_EControllerSettingEdge_spin_radius,
	k_EControllerSettingEdge_spin_velocity,
	k_EControllerSettingInvert_x,
	k_EControllerSettingInvert_y,
	k_EControllerSettingMouse_smoothing,
	k_EControllerSettingMouse_move_threshold,
	k_EControllerSettingRotation,
	k_EControllerSettingDoubetap_max_dist,
	k_EControllerSettingDoubetap_min_duration,
	k_EControllerSettingDoubetap_max_duration,
	k_EControllerSettingMousejoystick_deadzone_x = 48,
	k_EControllerSettingMousejoystick_deadzone_y,
	k_EControllerSettingScroll_angle,
	k_EControllerSettingScroll_wrap,
	k_EControllerSettingScroll_type,
	k_EControllerSettingScroll_invert,
	k_EControllerSettingScroll_friction,
	k_EControllerSettingOutput_trigger,
	k_EControllerSettingAdaptive_threshold,
	k_EControllerSettingButton_size,
	k_EControllerSettingButton_dist,
	k_EControllerSettingGyro_mode,
	k_EControllerSettingJoystick_smoothing,
	k_EControllerSettingGyro_axis,
	k_EControllerSettingGyro_button,
	k_EControllerSettingGyro_neutral,
	k_EControllerSettingGyro_pointer_mode,
	k_EControllerSettingGyro_button_invert,
	k_EControllerSettingVirtual_mode,
	k_EControllerSettingTouch_menu_button_count,
	k_EControllerSettingTouch_menu_opacity,
	k_EControllerSettingTouch_menu_position_x,
	k_EControllerSettingTouch_menu_position_y,
	k_EControllerSettingTouch_menu_scale,
	k_EControllerSettingMouse_dampening_trigger,
	k_EControllerSettingMouse_trigger_clamp_amount,
	k_EControllerSettingTouch_menu_show_labels,
	k_EControllerSettingGyro_sensitivity_scale,
	k_EControllerSettingScale,
	k_EControllerSettingPosition_x,
	k_EControllerSettingPosition_y,
	k_EControllerSettingTeleport_start,
	k_EControllerSettingTeleport_stop,
	k_EControllerSettingTouchmenu_button_fire_type,
	k_EControllerSettingTest_param_0,
	k_EControllerSettingTest_param_1,
	k_EControllerSettingTest_param_2,
	k_EControllerSettingTest_param_3,
	k_EControllerSettingTest_param_4,
	k_EControllerSettingTest_param_5,
	k_EControllerSettingTest_param_6,
	k_EControllerSettingTest_param_7,
	k_EControllerSettingTest_param_8,
	k_EControllerSettingTest_param_9,
	k_EControllerSettingAction_set_trigger_cursor_show,
	k_EControllerSettingAction_set_trigger_cursor_hide,
	k_EControllerSettingDelay_start,
	k_EControllerSettingDelay_end,
	k_EControllerSettingCycle,
	k_EControllerSettingToggle,
	k_EControllerSettingRepeat_rate,
	k_EControllerSettingDouble_tap_time,
	k_EControllerSettingLong_press_time,
	k_EControllerSettingActivation_threshold,
	k_EControllerSettingMouse_warp_x,
	k_EControllerSettingMouse_warp_y,
	k_EControllerSettingAnalog_value,
	k_EControllerSettingInterruptable,
	k_EControllerSettingSoft_press_sytle,
	k_EControllerSettingActivator_output_axis,
};

#endif
