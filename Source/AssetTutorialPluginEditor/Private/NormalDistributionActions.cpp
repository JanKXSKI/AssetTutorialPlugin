#include "NormalDistributionActions.h"
#include "NormalDistribution.h"
#include "NormalDistributionEditorToolkit.h"

UClass* FNormalDistributionAssetTypeActions::GetSupportedClass() const
{
    return UNormalDistribution::StaticClass();
}

FText FNormalDistributionAssetTypeActions::GetName() const
{
    return INVTEXT("Normal Distribution");
}

FColor FNormalDistributionAssetTypeActions::GetTypeColor() const
{
    return FColor::Cyan;
}

uint32 FNormalDistributionAssetTypeActions::GetCategories()
{
    return EAssetTypeCategories::Misc;
}

void FNormalDistributionAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor)
{
    MakeShared<FNormalDistributionEditorToolkit>()->InitEditor(InObjects);
}
