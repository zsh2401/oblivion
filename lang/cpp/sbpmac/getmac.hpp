#ifndef __GET_MAC
#define __GET_MAC
#include <vector>
#include <string>

/**
 * @brief 表示地址内容
 *
 */
typedef struct _AddressInfo
{
    std::string interfaceName;
    std::string address;
} AddressInfo;

typedef std::vector<AddressInfo> Addresses_t;

Addresses_t *getAddresses();

#define GETMAC_IMPL_SIGNATURE void getMacImpl(Addresses_t* resultList)

#endif