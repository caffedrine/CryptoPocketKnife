#include "DsaSecp.h"
#include <memory>
#include "vSecPrim/ESLib.h"

namespace Base::CryptoPrimitives
{
    class DsaSecp::impl
    {
    public:
        eslt_WorkSpaceEcP workspace;
    };

    DsaSecp::DsaSecp(dsa_secp_curve_t secpCurve): pimpl{std::make_unique<Base::CryptoPrimitives::DsaSecp::impl>()}
    {

    }

    // You MUST define the destructor in the cpp file where impl is complete
    DsaSecp::~DsaSecp() = default;

    std::vector<std::byte> DsaSecp::CalcPubKey(const std::vector<std::byte> &privKey)
    {
        return std::vector<std::byte>();
    }
}