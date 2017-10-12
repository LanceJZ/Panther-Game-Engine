#include "File.h"


namespace Leopard
{
	namespace Utilities
	{

		File::File()
		{
		}


		File::~File()
		{
		}

		std::string read_file(const char * filepath)
		{
			FILE* file = fopen(filepath, "rt");

			if (file == NULL)
			{
				LOG(filepath << " File Not found.");
				system("PAUSE");
				exit(0);
			}

			fseek(file, 0, SEEK_END);
			unsigned long length = ftell(file);
			char* data = new char[length + 1]();
			fseek(file, 0, SEEK_SET);
			fread(data, 1, length, file);
			fclose(file);

			std::string result(data);
			delete[] data;

			return result;
		}
	}
}