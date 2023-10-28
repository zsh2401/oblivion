#include "getmac.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    auto ad = getAddresses();
    size_t size = ad->size();
    std::printf("Retrieved %d mac address(es)\n", ad->size());
    for (std::vector<AddressInfo>::iterator it = ad->begin(); it != ad->end(); it++)
    {
        std::printf("Interface name: %s\n", it->interfaceName.c_str());
        std::printf("Mac address: %s\n\n", it->address.c_str());
    }
    delete ad;
    return 0;
}