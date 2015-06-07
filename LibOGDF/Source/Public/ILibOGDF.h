#pragma once

#include "ModuleManager.h"

class ILibOGDF : public IModuleInterface
{

public:
    static inline ILibOGDF& Get()
    {
        return FModuleManager::LoadModuleChecked<ILibOGDF>("LibOGDF");
    }

    static inline bool IsAvailable()
    {
        return FModuleManager::Get().IsModuleLoaded("LibOGDF");
    }
};
