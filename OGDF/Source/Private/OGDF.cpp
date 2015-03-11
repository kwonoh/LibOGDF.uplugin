#include "OGDFPrivatePCH.h"

class FOGDF : public IOGDF
{
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FOGDF, OGDF)

void FOGDF::StartupModule()
{
}


void FOGDF::ShutdownModule()
{
}
