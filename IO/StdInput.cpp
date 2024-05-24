#include "StdInput.h";

StdInput::StdInput()
{
}

vector<string> StdInput::GetUserInput() const
{
	vector<string> frames;
	string frame = "";
	cout << "Get the Ethernet Frame(s) from console,\nA frame shouldNOT contains any spaces/new-lines (i.e. spaces/new lines indicates a new frame to be parsed),\n";
	cout <<	"Enter q to finish inputing frames: \n";
	while (true) {
		cin >> frame;
		if (frame == "q") break;
		frames.push_back(frame);
	}

	return frames;
}

StdInput::~StdInput()
{
}
