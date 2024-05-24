#include "ApplicationManager.h"
#include "IO/StdInput.h"
#include "IO/FileInput.h"
#include "IO/StdOutput.h"
#include "IO/FileOutput.h"
#include "Parser/Parser.h"
// GUI I/O
#include "mainwindow.h"

// Constructor and Getters/Setters if any
ApplicationManager::ApplicationManager(ActionType actType)
{
	// Create input and output classes
	pIn = new Input;
	pOut = new Output;
	SetExitFlag(false);
	actionType = actType;
    mainwindow = nullptr;
}

void ApplicationManager::SetExitFlag(bool flag)
{
	exitFlag = flag;
}

void ApplicationManager::SetMainwindowUI(MainWindow* mui)
{
    mainwindow = mui;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction()
{
	int actionChoice;
	if (actionType != EMPTY)
		actionChoice = actionType;
	else
	{
		cout << "\t\t**********      IP/ARP Packet Parser   ***************" << endl
			 << endl;
		cout << "\t\t[1] Get the input/output from the console" << endl;
		cout << "\t\t[2] Get the input/output from files" << endl;
		cout << "\t\t[*] Anything else to Exit" << endl
			 << endl;
		cout << "\t\t******************************************************" << endl;
		cout << "Select an action:";
		cin >> actionChoice;
	}

	switch (actionChoice)
	{
	case STD_IO:
		pIn = new StdInput();
		pOut = new StdOutput();
		return STD_IO;
	case FILE_IO:
		pIn = new FileInput();
		pOut = new FileOutput();
		return FILE_IO;
    case GUI_IO:
        pIn = mainwindow;
        pOut = mainwindow;
        return GUI_IO;
		/* Add more i/o handling here */
	}

	SetExitFlag(true);
	return EXIT;
}
////////////////////////////////////////////////////////////////////////////////////
// Get the input data from user and try to parse it
void ApplicationManager::ExecuteAction()
{
	// skip if exit flag
	if (exitFlag)
		return;

	// initialize our parser
	Parser *pParser = new Parser(this);

	vector<string> frames = pIn->GetUserInput();
    for (auto frame : frames)
	{
		if (!pParser->ParseFrame(frame))
            pOut->UpdateOutput("Couldn't parse this frame :" + frame);
	}

	delete pParser;
}
//==================================================================================//
//							Packet Management Functions								//
//==================================================================================//

// Add a packet to the list of packets
void ApplicationManager::AddPacket(Packet *pPacket)
{
	packetQueue.push(pPacket);
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

// Update the interface(console,file, UI, ..) with the output info
void ApplicationManager::UpdateInterface()
{
	// skip if exit flag
	if (exitFlag)
		return;

	while (!packetQueue.empty())
	{
		Packet *currPacket = packetQueue.front();
		pOut->UpdateOutput(currPacket->GetPacketInfo());
		packetQueue.pop();
		delete currPacket;
	}
}
////////////////////////////////////////////////////////////////////////////////////
// Destructor
ApplicationManager::~ApplicationManager()
{
	while (!packetQueue.empty())
	{
		Packet *currPacket = packetQueue.front();
		packetQueue.pop();
		delete currPacket;
	}
    if(actionType == GUI_IO) return;
	delete pIn;
	delete pOut;
}
