#pragma once
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#if _DEBUG
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

namespace Leopard
{
	namespace Utilities
	{
	std::string read_file(const char* filepath);

		struct File
		{
		public:
			File();

			~File();
		};
	}
}