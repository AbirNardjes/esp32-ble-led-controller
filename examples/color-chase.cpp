/*
 * Selected implementation excerpt
 * from the ESP32 RGBW LED Controller.
 *
 * Demonstrates the moving Color Chase algorithm,
 * including grouped colors and RGBW interpolation.
 */

int effectDelay =
    map(currentSpeed, 0, 100, 150, 30);

int groupSize = 2;
int totalGroups = 8;

for (int i = 0; i < LED_COUNT; i++) {

    int baseGroupIndex =
        ((i / groupSize) + effectPosition)
        % totalGroups;

    int nextGroupIndex =
        (baseGroupIndex + 1)
        % totalGroups;

    float positionInGroup =
        (float)(i % groupSize)
        / (groupSize - 1);

    uint32_t fromColor =
        rainbowColors[baseGroupIndex];

    uint32_t toColor =
        rainbowColors[nextGroupIndex];

    uint8_t fromR =
        (fromColor >> 16) & 0xFF;

    uint8_t fromG =
        (fromColor >> 8) & 0xFF;

    uint8_t fromB =
        fromColor & 0xFF;

    uint8_t fromW =
        (fromColor >> 24) & 0xFF;

    uint8_t toR =
        (toColor >> 16) & 0xFF;

    uint8_t toG =
        (toColor >> 8) & 0xFF;

    uint8_t toB =
        toColor & 0xFF;

    uint8_t toW =
        (toColor >> 24) & 0xFF;

    uint8_t r =
        fromR + (toR - fromR) * positionInGroup;

    uint8_t g =
        fromG + (toG - fromG) * positionInGroup;

    uint8_t b =
        fromB + (toB - fromB) * positionInGroup;

    uint8_t w =
        fromW + (toW - fromW) * positionInGroup;

    strip.setPixelColor(
        i,
        strip.Color(r, g, b, w)
    );
}

strip.show();

effectPosition =
    (effectPosition + 2)
    % totalGroups;
