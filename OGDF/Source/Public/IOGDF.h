#pragma once

#include "ModuleManager.h"

class IOGDF : public IModuleInterface
{

public:
    static inline IOGDF& Get()
    {
        return FModuleManager::LoadModuleChecked<IOGDF>("OGDF");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("OGDF");
    }
};
