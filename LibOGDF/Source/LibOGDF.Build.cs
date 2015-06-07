using System;
using System.IO;

namespace UnrealBuildTool.Rules
{
    public class LibOGDF : ModuleRules
    {
        private string ModulePath
        {
            get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
        }

        private string ThirdPartyPath
        {
            get { return Path.GetFullPath(Path.Combine(ModulePath, "../ThirdParty/")); }
        }

        public LibOGDF(TargetInfo Target)
        {
            PublicIncludePaths.AddRange(new string[] {
                Path.Combine(ThirdPartyPath, "OGDF", "Include")
                });

            PrivateIncludePaths.AddRange(new string[] {
                    "LibOGDF/Private",
                });

            PublicDependencyModuleNames.AddRange(new string[] {
                    "Core",
                });

            PrivateDependencyModuleNames.AddRange(new string[] {
                });

            DynamicallyLoadedModuleNames.AddRange(new string[] {
                });

            string ConfigurationName;
            switch (Target.Configuration)
            {
                case UnrealTargetConfiguration.Debug:
                case UnrealTargetConfiguration.DebugGame:
                    ConfigurationName = "Debug";
                    break;
                default:
                    ConfigurationName = "Release";
                    break;
            }

            string LibPath = Path.Combine(ThirdPartyPath, "OGDF", "Lib", Target.Platform.ToString());
            switch (Target.Platform)
            {
                case UnrealTargetPlatform.Win32:
                case UnrealTargetPlatform.Win64:
                    PublicAdditionalLibraries.Add("psapi.lib");
                    PublicAdditionalLibraries.Add(Path.Combine(LibPath, ConfigurationName, "ogdf.lib"));
                    break;
                case UnrealTargetPlatform.Mac:
                    PublicAdditionalLibraries.Add(Path.Combine(LibPath, "libOGDF.a"));
                    break;
                default:
                    break;
            }
        }
    }
}
