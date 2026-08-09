/*
 * Selected implementation excerpt
 * from the ESP32 RGBW LED Controller.
 *
 * Demonstrates persistent controller state
 * using ESP32 Preferences.
 */

preferences.begin("led-state", false);

preferences.putBool(
    "power",
    isPoweredOn
);

preferences.putString(
    "color",
    currentColor.c_str()
);

preferences.putString(
    "palette",
    currentPalette.c_str()
);

preferences.putString(
    "effect",
    currentEffect.c_str()
);

preferences.putInt(
    "brightness",
    currentBrightness
);

preferences.putInt(
    "speed",
    currentSpeed
);

preferences.end();
