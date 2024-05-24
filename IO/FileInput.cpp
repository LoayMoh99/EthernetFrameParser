#include "FileInput.h";

FileInput::FileInput()
{
}

vector<string> FileInput::GetUserInput() const
{
	vector<string> frames;
	string filename = "";
	string frame = "";
	cout << "Get the Ethernet Frame(s) from file,\nA frame shouldNOT contains any spaces/new-lines (i.e. spaces/new lines indicates a new frame to be parsed)\n";
	cout << "Enter the file name without (.txt): \n";
	cin >> filename;
	ifstream file(filename+".txt");
	if (file.is_open()) {
		while (file >> frame) {
			if(frame != "")
				frames.push_back(frame);
		}
	}
	else {
		cout << "Couldn't open your file please try again after checking the name or close it if opened..";
	}

	return frames;
}

FileInput::~FileInput()
{
}
