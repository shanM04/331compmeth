#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
	if (argc !=2) {
		std::cerr << "usage: "<< argv[0] << "<number" << std::endl;
		return 1;
	}

	int number = std::atoi(argv[1]);
	std::cout <<"Hello world " << number << std::endl;

	return 0;
}
