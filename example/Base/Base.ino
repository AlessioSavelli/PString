#include "PString.h"

PString inputBuffer; // Buffer to accumulate the received data

void setup() {
    Serial.begin(115200);
    Serial.println("Send a string that starts with 'Ciao' and ends with '/*' to validate it.");
}

void loop() {
    // Receive data from the serial monitor and accumulate it in inputBuffer
    while (Serial.available() > 0) {
        char incomingChar = Serial.read(); // Read one character from the serial

        // Add the character to inputBuffer
        inputBuffer = inputBuffer + incomingChar;

        // Print the received character for debugging purposes
        Serial.print(incomingChar);

        // Validate the string:
        // It must start with "Ciao" and end with "/*"
        if (validateString(inputBuffer)) {
            Serial.println("\nValid string received:");
            inputBuffer.print(); // Print the received string
            Serial.println();

            // Reset the buffer to receive a new string
            inputBuffer = "";
        }
    }
}

// Function to validate the string
bool validateString(const PString& str) {
    if (str.startsWith("Ciao") && str.endsWith("/*")) {
        return true;
    }
    return false;
}
