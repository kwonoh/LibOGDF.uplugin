OGDF (Open Graph Drawing Framework) Plugin for Unreal Engine 4
=============
This plugin helps you to link [OGDF](http://www.ogdf.net/) with your UE projects.


Information
----------------------

This plugin is based on OGDF 2012.07.
I added `#pragma clang diagnostic ignored "-Woverloaded-virtual"` in `FMMMLayout.h` and `ClusterGraphAttributes.h` to avoid compile error on clang (OS X).


Supported Platform
----------------------

OS X, Windows


Installation
----------------------

1. Copy `OGDF` folder to `Plugins` folder under your project directory.
2. [Download precompiled binaries](https://www.dropbox.com/s/0by0dt5ryaxwqqc/OGDF-Lib.zip?dl=0) and extract it to `OGDF/ThirdParty/OGDF/Lib`.
Check your `Lib` directory, it should looks like `OGDF/ThirdParty/OGDF/Lib/Mac`, `OGDF/ThirdParty/OGDF/Lib/Win32` and `OGDF/ThirdParty/OGDF/Lib/Win64`.
3. Add `OGDF` under `PublicDependencyModuleNames` in your `*.Build.cs` file to include header files from your project.
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
