#include "ApplicationManager.h"

int main()
{

	ActionType actType = EXIT;
	//Create an object of ApplicationManager
	ApplicationManager appManager;

	do
	{		
		//Read user action
		actType = appManager.GetUserAction();

		//Exexute the action
		appManager.ExecuteAction();

		//Update the interface
		appManager.UpdateInterface();	

	} while(actType != EXIT);
	

	
	return 0;
}

