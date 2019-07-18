#include <iostream>
#include <fstream>
#include <stdlib.h>

struct File_Creator {
	public:
		std::string name;
		std::string path = "./genfold/";
		std::ofstream fcreate;
		unsigned int quantity;
		unsigned int rows;
		unsigned int columns;
		int range;
		File_Creator(std::string& name, unsigned int& quantity, 
					 unsigned int& rows, unsigned int& columns, int& range) {
			std::cout << "Enter parameters of the matrix" <<std::endl;
			std::cout << "Name` ";
			std::cin >> name;
			std::cout << "Quantity of matrices = ";
			std::cin >> quantity;
			std::cout << "Range of matrices = ";
			std::cin >> range;
			std::cout << "Rows = ";
			std::cin >> rows;
			std::cout << "Columns = ";
			std::cin >> columns;
			std::string Name = path + name;
			fcreate.open(Name, std::ios::out);
			fcreate << "This " << name << " file contains " << quantity
			        << " matrix " << rows << "x" << columns 
					<< " with the range of " << range << "\n" << std::endl;
			for(int i = 0; i < quantity; ++i) {
				int digit;
				for(int j = 0; j < rows; ++j) {
					for(int k = 0; k < columns; ++k) {
						digit = rand()% range;
						if(!(fcreate << digit << "\t")) {
							std::cout << "Couldn't write into the file !!!\n";
						}
					}
					fcreate << "\n";
				}
				fcreate << "\n";
			}
		}
		~File_Creator() {
			fcreate.close();
		}
};

int main() {
	srand(time(NULL));
	std::string name;
	int end_point;
	std::cout << "How much TXT file you want to create" << std::endl;
	std::cout << "File quantity = ";
	std::cin >> end_point;
	unsigned int quantity, rows, columns;
	int range;
	for(int i = 0; i < end_point; ++i) {
		File_Creator a(name, quantity, rows, columns, range);
	}
	return 0;
}
