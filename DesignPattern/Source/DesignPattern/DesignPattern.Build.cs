// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DesignPattern : ModuleRules
{
	public DesignPattern(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
