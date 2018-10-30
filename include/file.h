#ifndef FILE_H
#define FILE_H

#include <iostream>	//std::cin and std::cout
#include <fstream>	//std::ifstream and std::ofstream
#include <string>	//std::string
#include <sstream>	//std::sstream

/*!
 * This class offers file handling
*/

class File{
	private:
		//==== private members
		std::ifstream input_file;	//!< input file stream variable to load the arithmetic expressions file
		std::ofstream output_file;	//!< output file stream to stores the processing results

	public:
		//==== special methods
        /// default constructor
		File(void) = delete;
		/// ifstream and ofstream constructor
		File(std::string, std::string);
		/// destructor
        ~File(void);

        //==== support methods
        bool is_eof(void); // returns true if the processing reach the end of the input file

		//==== input and output methods
		std::string read_line(void);	// reads a line from the input file and returns it as string
		void write_line(std::string);	// writes a line on the output file
};

#endif