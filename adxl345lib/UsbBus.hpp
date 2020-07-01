#ifndef USBBUS_HPP
#define USBBUS_HPP
/// @file
/// \brief
/// Class that handles console communication
/// \details
/// This class handles the communication to the device it is connected to via USB.
/// Using this class, you can send up to 50 characters at once to the host that should be reading the USB TTY connection.
class UsbBus {
public:
/// \brief
/// Pauses the program
/// \details
/// The program will be paused until the Enter key is pressed.
/// After the Enter key is pressed, the program wil continue normally.
/// This function is especially useful for reading loops, where the loop must be paused every round.
	static void waitForInput();
/// \brief
/// Function for sending integers to the host
/// \details
/// This function is for sending regular integer numbers to the device the Arduino is connected to.
/// This function is only to be used by other parts of the library. For sending data to the host from your own code, please use the Logging class.
	static void sendDataToHost(int16_t);
/// \brief
/// Function for sending character arrays to the host
/// \details
/// This function is for sending an array with characters to the device the Arduino is connected to.
/// The maximum size of this array is 50.
/// This function is only to be used by other parts of the library. For sending data to the host from your own code, please use the Logging class.
	static void sendDataToHost(char[50]);
};

#endif // USBBUS_HPP