/*
 * Selected implementation excerpt
 * from the ESP32 RGBW LED Controller.
 *
 * Demonstrates the command-dispatch architecture
 * used to process Bluetooth commands from the Android app.
 */

void handleCommand(String command) {

    if (command.startsWith("POWER:")) {

        String state = command.substring(6);

        if (state == "ON") {
            startFadeIn();
        }
        else if (state == "OFF") {
            startFadeOut();
        }
    }

    else if (command.startsWith("COLOR:")) {

        String newColor = command.substring(6);

        setSolidColor(newColor);
        saveState();

        SerialBT.println("COLOR:" + newColor);
    }

    else if (command.startsWith("BRIGHTNESS:")) {

        currentBrightness =
            command.substring(11).toInt();

        strip.setBrightness(
            map(currentBrightness, 0, 100, 0, 255)
        );

        saveState();

        SerialBT.println(
            "BRIGHTNESS:" + String(currentBrightness)
        );
    }

    else if (command.startsWith("SPEED:")) {

        currentSpeed =
            command.substring(6).toInt();

        saveState();

        SerialBT.println(
            "SPEED:" + String(currentSpeed)
        );
    }

    else if (command.startsWith("EFFECT:")) {

        currentEffect =
            command.substring(7);

        saveState();

        SerialBT.println(
            "EFFECT:" + currentEffect
        );
    }

    else if (command.startsWith("PALETTE:")) {

        String palette =
            command.substring(8);

        applyPalette(palette);
        saveState();

        SerialBT.println(
            "PALETTE:" + palette
        );
    }

    else if (command.startsWith("REQUEST:STATE")) {

        sendCurrentState();
    }

    else {

        SerialBT.println(
            "ERROR:Unknown command"
        );
    }
}
