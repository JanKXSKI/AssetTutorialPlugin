#include "AssetTutorialPluginEditor.h"

void FAssetTutorialPluginEditorModule::StartupModule()
{
	NormalDistributionAssetTypeActions = MakeShared<FNormalDistributionAssetTypeActions>();
	FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(NormalDistributionAssetTypeActions.ToSharedRef());
}

void FAssetTutorialPluginEditorModule::ShutdownModule()
{
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;
	FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(NormalDistributionAssetTypeActions.ToSharedRef());
}

IMPLEMENT_MODULE(FAssetTutorialPluginEditorModule, AssetTutorialPluginEditor)
