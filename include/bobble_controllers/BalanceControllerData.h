//
// Created by mike on 5/11/19.
//

#ifndef SRC_BALANCE_CONTROLLER_DATA_H
#define SRC_BALANCE_CONTROLLER_DATA_H

#include <bobble_controllers/ControlCommands.h>
#include <bobble_controllers/BobbleBotStatus.h>
#include <bobble_controllers/PidControl.h>
#include "bobble_controllers/MadgwickAHRS.h"
#include <bobble_controllers/Filter.h>

namespace bobble_controllers {

    /// Controller real-time data.
    /// HW interface data.
    class BalanceControllerRtData {
    public:
        double AccelX;
        double AccelY;
        double AccelZ;
        double RollDot;
        double TiltDot;
        double TurnDot;
        double LeftMotorVoltage;
        double LeftMotorPosition;
        double LeftMotorVelocity;
        double LeftMotorEffort;
        double RightMotorVoltage;
        double RightMotorPosition;
        double RightMotorVelocity;
        double RightMotorEffort;
    };

    /// Controller configuration parameters.
    /// These are set at init via yml
    class BalanceControllerConfig {
    public:
        double StartingTiltSafetyLimitDegrees;
        double MaxTiltSafetyLimitDegrees;
        double MotorEffortMax;
        double MotorEffortToTorqueSimFactor;
        double WheelVelocityAdjustment;
        double MadgwickFilterGain;
        double MeasuredTiltFilterGain;
        double MeasuredTiltDotFilterGain;
        double MeasuredHeadingFilterGain;
        double MeasuredTurnRateFilterGain;
        double LeftWheelVelocityFilterGain;
        double RightWheelVelocityFilterGain;
        double DesiredForwardVelocityFilterGain;
        double DesiredTurnRateFilterGain;
        double MaxVelocityCmd;
        double MaxTurnRateCmd;
        double WheelRadiusMeters;
        double VelocityCmdScale;
        double TurnCmdScale;
        double VelocityControlKp;
        double VelocityControlKi;
        double VelocityControlAlphaFilter;
        double VelocityControlMaxIntegralOutput;
        double VelocityControlOutputLimitDegrees;
        double TiltControlKp;
        double TiltControlKd;
        double TiltControlAlphaFilter;
        double TiltOffset;
        double TiltDotOffset;
        double RollDotOffset;
        double YawDotOffset;
        double TurningControlKp;
        double TurningControlKi;
        double TurningControlKd;
        double TurningOutputFilter;
    };

    /// Controller commands.
    /// These are sent in via external command.
    class BalanceControllerCommands {
    public:
        bool StartupCmd;
        bool IdleCmd;
        bool DiagnosticCmd;
        double DesiredVelocityRaw;
        double DesiredTurnRateRaw;
        double DesiredVelocity;
        double DesiredTurnRate;
    };

    /// Controller outputs.
    class BalanceControllerOutputs {
    public:
        double TiltEffort;
        double HeadingEffort;
        double LeftMotorEffortCmd;
        double RightMotorEffortCmd;
    };

    /// Controller state parameters.
    /// These are updated continually at run-time
    class BalanceControllerState {
    public:
        int    ActiveControlMode;
        double MeasuredTilt;
        double MeasuredHeading;
        double MeasuredRoll;
        double MeasuredRollDot;
        double MeasuredTiltDot;
        double MeasuredTurnRate;
        double MeasuredRightMotorPosition;
        double MeasuredRightMotorVelocity;
        double MeasuredLeftMotorPosition;
        double MeasuredLeftMotorVelocity;
        double ForwardVelocity;
        double DesiredTilt;
        double Tilt;
        double TiltDot;
        double Heading;
        double TurnRate;
        double LeftWheelVelocity;
        double RightWheelVelocity;
        BalanceControllerCommands Cmds;
    };

    /// Controller modes
    enum ControlModes {
        IDLE,
        STARTUP,
        BALANCE,
        DIAGNOSTIC
    };

    /// Controller filters
    class BalanceControllerFilters {
    public:
        LPFilter MeasuredTiltFilter;
        LPFilter MeasuredTiltDotFilter;
        LPFilter MeasuredHeadingFilter;
        LPFilter MeasuredTurnRateFilter;
        LPFilter LeftWheelVelocityFilter;
        LPFilter RightWheelVelocityFilter;
        LPFilter DesiredForwardVelocityFilter;
        LPFilter DesiredTurnRateFilter;
    };


    /// PID Controllers
    class BalancePIDControllers {
    public:
        BalancePIDControllers() :
          VelocityControlPID(0.0, 0.0, 0.0),
          TiltControlPID(0.0, 0.0, 0.0),
          TurningControlPID(0.0, 0.0, 0.0)
        {}
        PidControl VelocityControlPID;
        PidControl TiltControlPID;
        PidControl TurningControlPID;
    };
}

#endif //SRC_BALANCE_CONTROLLER_DATA_H
