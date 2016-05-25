/*
 Usage: ./send <systemCode> <unitCode> <command>
 Command is 0 for OFF and 1 for ON
 */

#include "RCSwitch.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int PIN = 6; // this is a wiringPi pin number! Check the wiringPi documentation for the number mapping.
    char* code = argv[1];

    if (wiringPiSetup () == -1) return 1;

    printf("sending code [%s] via pin %i", code, PIN);

    RCSwitch mySwitch = RCSwitch();
    mySwitch.enableTransmit(PIN);

    mySwitch.sendTriState(code);

    return 0;
}
