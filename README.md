OGDF (Open Graph Drawing Framework) Plugin for Unreal Engine 4
=============
This plugin helps you to link [OGDF](http://www.ogdf.net/) with your UE projects.


Information
----------------------

This plugin is based on OGDF 2015.05 (Baobab).
I added `#pragma clang diagnostic ignored "-Woverloaded-virtual"` in `FMMMLayout.h` and `ClusterGraphAttributes.h` to avoid compile error on clang (OS X).

Also, I built binaries with `_ITERATOR_DEBUG_LEVEL=0` and changed `Runtime Library` to `/MD`. It is required to make same code generation configurations with UE4's binaries on Windows.


Supported Platform
----------------------

OS X, Windows


Installation
----------------------

1. Copy `LibOGDF` folder to `Plugins` folder under your project directory.
2. [Download precompiled binaries](https://www.dropbox.com/s/du8u5eivs0tvlvj/OGDF-Lib-2015.05.zip?dl=0) and extract it to `LibOGDF/ThirdParty/LibOGDF/Lib`.
Check your `Lib` directory, it should looks like `LibOGDF/ThirdParty/OGDF/Lib/Mac`, `LibOGDF/ThirdParty/OGDF/Lib/Win32` and `LibOGDF/ThirdParty/OGDF/Lib/Win64`.
3. Add `LibOGDF` under `PublicDependencyModuleNames` in your `*.Build.cs` file to include header files from your project.
4. Add following code in `*.Target.cs` (not `*Editor.Target.cs`) of your project. It is required to package your project.
```cs
public override void SetupGlobalEnvironment(
    TargetInfo Target,
    ref LinkEnvironmentConfiguration OutLinkEnvironmentConfiguration,
    ref CPPEnvironmentConfiguration OutCPPEnvironmentConfiguration
    )
{
    UEBuildConfiguration.bForceEnableExceptions = true;
}
```

License
----------------------

Unreal® is a trademark or registered trademark of Epic Games, Inc. in the United States of America and elsewhere. Unreal® Engine, Copyright 1998 – 2014, Epic Games, Inc. All rights reserved.

OGDF is available under the terms of the GNU General Public License version 2 or version 3.

Plugin is completely free and available under [MIT open-source license](LICENSE).
