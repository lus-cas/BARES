#ifndef FILE_H
#define FILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class File{
	private:
		std::ifstream input_file;
		std::ofstream output_file;

	public:
		//constructors and destructors
		File(void) = delete;
		File(std::string, std::string);
        ~File(void);

        //support methods
        bool is_eof(void);
        void clean_output

		//input and output methodos
		std::string read_line(void);
		void write_line(std::string);
};

#endif