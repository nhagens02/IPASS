#ifndef LOGGING_HPP
#define LOGGING_HPP

class Logging {
public:
	static bool isLoggingEnabled;
	static void writeToLog(char[]);
};

#endif // LOGGING_HPP