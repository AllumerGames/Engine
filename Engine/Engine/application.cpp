#include "application.hpp"

namespace Engine
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		std::cout << "Hello World" << std::endl;
		std::vector<int> testVector;
		testVector.push_back(10);
		testVector.push_back(11);
		testVector.push_back(13);

		for (const auto& item : testVector)
		{
			std::cout << item << std::endl;
		}
	}

}

