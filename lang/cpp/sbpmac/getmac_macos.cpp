#include "getmac.hpp"
#include <iostream>
#include <CoreFoundation/CoreFoundation.h>
#include <SystemConfiguration/SystemConfiguration.h>

GETMAC_IMPL_SIGNATURE
{
     CFArrayRef interfaces = SCNetworkInterfaceCopyAll();
    CFIndex count = CFArrayGetCount(interfaces);

    for (CFIndex i = 0; i < count; ++i) {
        SCNetworkInterfaceRef interface = (SCNetworkInterfaceRef)CFArrayGetValueAtIndex(interfaces, i);
        CFDataRef macData = SCNetworkInterfaceGetHardwareAddress(interface);
        
        if (macData != nullptr) {
            const UInt8* macBytes = CFDataGetBytePtr(macData);
            char macAddress[18];
            snprintf(macAddress, sizeof(macAddress), "%02X:%02X:%02X:%02X:%02X:%02X",
                     macBytes[0], macBytes[1], macBytes[2], macBytes[3], macBytes[4], macBytes[5]);

            CFStringRef interfaceName = SCNetworkInterfaceGetBSDName(interface);
            char interfaceNameBuffer[256];
            CFStringGetCString(interfaceName, interfaceNameBuffer, sizeof(interfaceNameBuffer), kCFStringEncodingUTF8);

            std::cout << "Interface: " << interfaceNameBuffer << std::endl;
            std::cout << "MAC Address: " << macAddress << std::endl;
        }
    }

    CFRelease(interfaces);
}