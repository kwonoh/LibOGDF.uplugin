using System.IO;

namespace UnrealBuildTool.Rules
{
	public class OGDF : ModuleRules
	{
		private string ModulePath
		{
			get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
		}

		private string ThirdPartyPath
		{
			get { return Path.GetFullPath(Path.Combine(ModulePath, "../ThirdParty/")); }
		}

		public OGDF(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(new string[] {
				Path.Combine(ThirdPartyPath, "OGDF", "Include")
				});

			PrivateIncludePaths.AddRange(new string[] {
				"OGDF/Private",
				});

			PublicDependencyModuleNames.AddRange(new string[] {
				"Core",
				});

			PrivateDependencyModuleNames.AddRange(new string[] {
				});

			DynamicallyLoadedModuleNames.AddRange(new string[] {
				});

			string LibPath = Path.Combine(ThirdPartyPath, "OGDF", "Lib");

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

			switch (Target.Platform)
			{
				case UnrealTargetPlatform.Win32:
				case UnrealTargetPlatform.Win64:
					PublicAdditionalLibraries.Add("psapi.lib");
					PublicAdditionalLibraries.Add(Path.Combine(LibPath, Target.Platform.ToString(), ConfigurationName, "ogdf.lib"));
					break;
				case UnrealTargetPlatform.Mac:
					PublicAdditionalLibraries.Add(Path.Combine(LibPath, Target.Platform.ToString(), "libOGDF.a"));
					break;
				default:
					break;
			}
		}
	}
}
