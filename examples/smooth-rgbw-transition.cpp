/*
 * Selected implementation excerpt
 * from the ESP32 RGBW LED Controller.
 *
 * Demonstrates RGBW interpolation used for
 * smooth color transitions.
 */

float progress =
    (float)transitionProgress / transitionTime;

uint8_t r =
    fromR + (toR - fromR) * progress;

uint8_t g =
    fromG + (toG - fromG) * progress;

uint8_t b =
    fromB + (toB - fromB) * progress;

uint8_t w =
    fromW + (toW - fromW) * progress;

uint32_t blendedColor =
    strip.Color(r, g, b, w);

for (int i = 0; i < strip.numPixels(); i++) {

    strip.setPixelColor(
        i,
        blendedColor
    );
}

strip.show();
