#include "getmac.hpp"

#ifdef _WIN32
#include "getmac_win32.cpp"
#elif __linux__
#include "getmac_linux.cpp"
#elif __APPLE__
#include "getmac_macos.cpp"
#endif

/**
 * @brief Get the Addresses object, Please free it after usage.
 *
 * @return Addresses_t*
 */
Addresses_t *getAddresses()
{
    Addresses_t *resultList = new std::vector<AddressInfo>();
    getMacImpl(resultList);
    return resultList;
}