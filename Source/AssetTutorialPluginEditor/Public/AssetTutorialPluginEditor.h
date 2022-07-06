#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "NormalDistributionActions.h"

class FAssetTutorialPluginEditorModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
private:
	TSharedPtr<FNormalDistributionAssetTypeActions> NormalDistributionAssetTypeActions;
};
