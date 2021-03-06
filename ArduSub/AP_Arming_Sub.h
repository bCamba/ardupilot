#pragma once

#include <AP_Arming/AP_Arming.h>

class AP_Arming_Sub : public AP_Arming {
public:
    AP_Arming_Sub(const AP_AHRS &ahrs_ref, Compass &compass,
                  const AP_BattMonitor &battery)
        : AP_Arming(ahrs_ref, compass, battery)
    {
    }

    /* Do not allow copies */
    AP_Arming_Sub(const AP_Arming_Sub &other) = delete;
    AP_Arming_Sub &operator=(const AP_Arming_Sub&) = delete;

    bool rc_calibration_checks(bool report) override;
    bool pre_arm_checks(bool report) override;

protected:
    bool ins_checks(bool report) override;
};
