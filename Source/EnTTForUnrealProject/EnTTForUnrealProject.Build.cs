// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class EnTTForUnrealProject : ModuleRules
{
	public EnTTForUnrealProject(ReadOnlyTargetRules Target) : base(Target)
	{
		// These settings are needed for EnTT as it uses C++17
		CppStandard = CppStandardVersion.Cpp17;
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"InputCore",
				"EnTTForUnreal"
			});

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
