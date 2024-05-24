#include "FileOutput.h"


FileOutput::FileOutput() : Output() {
	filename = "";
}

void FileOutput::UpdateOutput(string outstring) {
	ofstream outfile;
	if (filename == "") {
		cout << "Enter the output file name: \n";
		cin >> filename;
		outfile.open(filename+".txt", ios::trunc); // to clear file content     
		outfile.close();// Close the file after truncating it
	}
	outfile.open(filename+".txt", ios::app); 
	outfile << outstring << endl;
	outfile.close();
}

//////////////////////////////////////////////////////////////////////////////////////////
FileOutput::~FileOutput()
{}

