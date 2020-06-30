#ifndef USBBUS_HPP
#define USBBUS_HPP

class UsbBus {
private:
	static bool isFirstOutput;
public:
	static void waitForInput();
	static void sendDataToHost(int);
	static void sendDataToHost(char[50]);
};

#endif // USBBUS_HPP