#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "IO\input.h"
#include "IO\output.h"
#include "Packets\Packet.h"
#include <queue>

class MainWindow;	//forward class declaration to prevent circuar dependency

// Main class that manages everything in the application.
class ApplicationManager
{
private:
	queue<Packet *> packetQueue; // to FIFO (first come first serve/output)

	Input *pIn;
	Output *pOut;
	bool exitFlag;
	void SetExitFlag(bool);

	ActionType actionType;
    MainWindow* mainwindow;

public:
    ApplicationManager(ActionType actType = EMPTY);
    ~ApplicationManager();


	// -- Packet Management Functions
	void AddPacket(Packet *pPacket);

	// -- Action-Related Functions
	ActionType GetUserAction();
	void ExecuteAction();

	// -- Interface Management Functions
	void UpdateInterface(); // Update the interface (console, UI, ..) with the output info
    void SetMainwindowUI(MainWindow*); // in case of GUI (QT)
};

#endif
