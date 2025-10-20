/* """
* 
* Submission for the OSTEP Projects
* Category: Initial Projects/Unix Utilities
* Project: wcat
* Author: Dlite/Prosper
* 
* Usage: wcat [file1, file2, file3...]
* Link to Projects page: aHR0cHM6Ly9naXRodWIuY29tL3JlbXppLWFycGFjaWR1c3NlYXUvb3N0ZXAtcHJvamVjdHM=

""" */

#include <iostream>
#include <fstream>
#include <string>

enum STATUS {
	FAILED_TO_OPEN_FILE = -1,
	NO_ARGUMENTS_PASSED = -2,
	OPERATIONS_SUCCEEDED = 0,
	ERROR_READING_FILE = -3
};

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::string help_message = R"(Usage: wcat "file1", ["file2", "file3", ...])";
		std::cout << help_message;
		return STATUS::NO_ARGUMENTS_PASSED;
	}

	/*Assuming we passed files to the command, 
	we can then loop through the arguments array, printing each file content
	*/

	for (int i = 1; i < argc; i++) {
		std::cout << "File: " << argv[i] << std::endl;
		std::string line;
		std::ifstream file;
		file.open(argv[i], std::ios_base::in);
		if (!file.is_open()) {
			std::cout << "Error opening file: " << argv[i];
			return STATUS::FAILED_TO_OPEN_FILE;
		}

		while (file.good()) {
			std::getline(file, line);

			//Assuming an error prevented the file from being read!
			if (file.bad()) {
				std::cout << "Error reading file: " << argv[i] << std::endl;
				return STATUS::ERROR_READING_FILE;
			}
			std::cout << line << "\n";
			if (file.eof()){
				std::cout << "\n\n\n";
				file.close();
				break;
			}
			
		}

		
	}
	std::cout << "\nFinished...";
	return STATUS::OPERATIONS_SUCCEEDED;
	

	
	return 0;
}
