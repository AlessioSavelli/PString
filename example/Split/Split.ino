/*
  Author: Alessio Savelli
  Purpose: Demonstration of PString class with two split methods: split (copy-based) and splitPtr (pointer-based).

  Description:
  This example showcases two methods for splitting a string:
  1. split() - Returns an array of PString objects (creates copies of the tokens).
  2. splitPtr() - Returns an array of pointers to the original string tokens without creating copies.

  Pros and Cons:
  1. split():
     + Creates independent copies of tokens.
     + Useful if the original string may change.
     - Higher memory usage due to copies.
     - Requires additional cleanup (delete[]).

  2. splitPtr():
     + Very memory efficient (no copies).
     + Faster, as it directly operates on the original string.
     - Tokens are dependent on the original string.
     - Original string must remain unmodified while pointers are in use.
*/

#include "PString.h"

void setup() {
    Serial.begin(115200);

    // Original string to split
    PString str = "Ciao:Mondo:Arduino:OPTA";

    // --- Split using copies ---
    int tokenCount = 0; // Holds the number of tokens found
    PString* tokens = str.split(':', tokenCount); // Call split to create copies

    Serial.println("Split using copies:");
    for (int i = 0; i < tokenCount; i++) { // Iterate through the tokens
        Serial.print("Token ");
        Serial.print(i);
        Serial.print(": ");
        tokens[i].print(); // Print each token (copies of the substrings)
        Serial.println();
    }
    delete[] tokens; // Free dynamically allocated memory for tokens

    // --- Split using pointers ---
    int ptrCount = 0; // Holds the number of tokens found
    const char** tokensPtr = str.splitPtr(':', ptrCount); // Call splitPtr to use pointers

    Serial.println("\nSplit using pointers:");
    for (int i = 0; i < ptrCount; i++) { // Iterate through the pointers
        Serial.print("Token ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(tokensPtr[i]); // Directly print the substring pointers
    }
    delete[] tokensPtr; // Free dynamically allocated memory for pointers
}

void loop() {
    // Empty loop
}
