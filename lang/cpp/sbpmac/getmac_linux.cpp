#include "getmac.hpp"
#include <iostream>
#include <ifaddrs.h>
#include <fstream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
// #include <netpacket/packet.h>
#include <net/ethernet.h> /* the L2 protocols */

GETMAC_IMPL_SIGNATURE
{
    // Addresses_t* result = new std::vector<AddressInfo>();
    struct ifaddrs *addrs;
    getifaddrs(&addrs);
    for (struct ifaddrs *addr = addrs; addr != nullptr; addr = addr->ifa_next)
    {
        if (addr->ifa_addr && addr->ifa_addr->sa_family == AF_PACKET)
        {
            std::string interfaceName = addr->ifa_name;
            AddressInfo inf;
            inf.interfaceName = interfaceName;

            // std::cout << "Interface Name: " << interfaceName << std::endl;
            std::string fileName = "/sys/class/net/" + interfaceName + "/address";
            std::ifstream file(fileName);

            if (!file)
            {
                std::cerr << "Failed to open the file: " << fileName << std::endl;
                continue;
            }


            std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
            auto s = content;

            // content.erase(std::remove(content.begin(), content.end(), '\n'), content.cend());
            if (!s.empty() && s[s.length() - 1] == '\n')
            {
                s.erase(s.length() - 1);
            }
            
            inf.address = s;
            resultList->push_back(inf);
        }
    }
}