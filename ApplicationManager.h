#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "IO\input.h"
#include "IO\output.h"
#include "Packets\Packet.h"
#include <queue>

//Main class that manages everything in the application.
class ApplicationManager
{
private:
	queue<Packet*> packetQueue; // to FIFO (first come first serve/output)
		
	Input *pIn;
	Output *pOut;
	bool exitFlag;
	void SetExitFlag(bool);
	

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Packet Management Functions
	void AddPacket(Packet* pPacket);

	// -- Action-Related Functions
	ActionType GetUserAction();
	void ExecuteAction(); 
		
	// -- Interface Management Functions
	void UpdateInterface();	//Update the interface (console, UI, ..) with the output info	
};

#endif