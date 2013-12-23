string sTemp = "";
TFileHandle hFileWriteHandle = NOT_A_HANDLE;
bool bFirstNumberOnLine = true;
TFileIOResult nIoResult = ioRsltSuccess;

bool log_open(const string &sFileName, int nFileSize);

void log_close();

void log_integer(long nNumber);

void log_string(string nString);

void log_writedelimiters();

bool log_open(const string &sFileName, int nFileSize)
{
	//This function opens a file to store data in
	//Not designed to be used as data storage for the robot, only designed to be used as a debugging tool
	bFirstNumberOnLine = true;
	Delete(sFileName, nIoResult);
	OpenWrite(hFileWriteHandle, nIoResult, sFileName, nFileSize);
	return nIoResult == ioRsltSuccess;
}

void log_close()
{
	//Closes whatever file was opened in the previous function
	Close(hFileWriteHandle, nIoResult);
	hFileWriteHandle = NOT_A_HANDLE;
}

void log_newline()
{
	//Adds a newline character, resulting in the writing functions writing on a new line
	WriteText(hFileWriteHandle, nIoResult, "\r\n");
	bFirstNumberOnLine = true;
	return;
}

void log_writedelimiters()
{
	//Only called by other functions, not inteneded to be used except by other functions
	if (bFirstNumberOnLine)
		bFirstNumberOnLine = false;
	else
		WriteText(hFileWriteHandle, nIoResult, ", ");
	return;
}

void log_integer(long nNumber)
{
	//Adds a number to the file
	string sTemp;
	log_writedelimiters();
	StringFormat(sTemp, "%d", (long) nNumber);
	WriteText(hFileWriteHandle, nIoResult, sTemp);
	return;
}

void log_string(string nString)
{
	//Adds some text to the file
	WriteText(hFileWriteHandle, nIoResult, sTemp);
	return;
}
