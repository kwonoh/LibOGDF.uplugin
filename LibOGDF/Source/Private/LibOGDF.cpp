#include "LibOGDFPrivatePCH.h"

class FLibOGDF : public ILibOGDF
{
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FLibOGDF, LibOGDF)

void FLibOGDF::StartupModule()
{
}


void FLibOGDF::ShutdownModule()
{
}
