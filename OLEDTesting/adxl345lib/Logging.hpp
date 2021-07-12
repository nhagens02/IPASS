#ifndef LOGGING_HPP
#define LOGGING_HPP
/// @file
/// \brief
/// Simple logging class
/// \details
/// This simple class can send log lines to the host device.
/// Also, logging can be enabled and disabled easily using the isLoggingEnabled boolean.
class Logging {
public:
/// \brief
/// Defines if logging should be enabled
/// \details
/// This boolean defines if text sent to writeToLog should be written to the host device.
/// The default value is true.
	static bool isLoggingEnabled;
/// \brief
/// Function for writing text to the log
/// \details
/// This function writes text to the host if isLoggingEnabled is not manually set to false.
/// This function is also used by the different classes to let you know they are working.
	static void writeToLog(const char[50]);
/// \brief
/// Function for writing int16_t integers to the log
/// \details
/// This function writes a number to the host if isLoggingEnabled is not manually set to false.
/// This function is also used by the different classes to let you know they are working.
	static void writeToLog(int16_t);
/// \brief
/// Function for writing a newline to the log
/// \details
/// This function allows the user to send a newline to the host if isLoggingEnabled is not manually set to false.
/// When this function is called, a '\n' will be sent to the host, causing the text to continue on the next line.
	static void writeNewLine();
/// \brief
/// Function for writing a tab to the log
/// \details
/// This function allows the user to send a tab to the host if isLoggingEnabled is not manually set to false.
/// When this function is called, a '\t' will be sent to the host, causing the text to move to the right.
	static void writeTab();
};

#endif // LOGGING_HPP