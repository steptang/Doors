For information on installing libraries, see: http://www.arduino.cc/en/Guide/Libraries

Here's what we learned from FemmeHacks and installing libraries:
1. Do not follow the instructions on the RedBear website for libraries (only follow it for non-library steps)
2. For libraries, remove pre-existing RedBear libraries from C:Arduino/, and go to Sketch > Include Library > Manage Library. Search "ble_sdk" and install the two libraries that pop up.
3. Check that the example programs are all there now for the two newly added libraries. Also, check the project directory to see a libraries folder. This folder should contain the two new libraries.