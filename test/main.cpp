#include <iostream>
#include <messagefactory.hpp>

int main()
{
    std::cout << MessageFactory::createFetchMessage(12)->toJSON() << std::endl;
    return 0;
}
