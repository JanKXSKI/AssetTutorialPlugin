#include "NormalDistributionEditorToolkit.h"
#include "Widgets/Docking/SDockTab.h"
#include "SNormalDistributionWidget.h"
#include "Modules/ModuleManager.h"

void FNormalDistributionEditorToolkit::InitEditor(const TArray<UObject*>& InObjects)
{
	NormalDistribution = Cast<UNormalDistribution>(InObjects[0]);

	const TSharedRef<FTabManager::FLayout> Layout = FTabManager::NewLayout("NormalDistributionEditorLayout")
	->AddArea
	(
		FTabManager::NewPrimaryArea()->SetOrientation(Orient_Vertical)
		->Split
		(
			FTabManager::NewSplitter()
			->SetSizeCoefficient(0.6f)
			->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.8f)
				->AddTab("NormalDistributionPDFTab", ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.2f)
				->AddTab("NormalDistributionDetailsTab", ETabState::OpenedTab)
			)
		)
		->Split
		(
			FTabManager::NewStack()
			->SetSizeCoefficient(0.4f)
			->AddTab("OutputLog", ETabState::OpenedTab)
		)
	);
	FAssetEditorToolkit::InitAssetEditor(EToolkitMode::Standalone, {}, "NormalDistributionEditor", Layout, true, true, InObjects);
}

void FNormalDistributionEditorToolkit::RegisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

	WorkspaceMenuCategory = InTabManager->AddLocalWorkspaceMenuCategory(INVTEXT("Normal Distribution Editor"));

	InTabManager->RegisterTabSpawner("NormalDistributionPDFTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
	{
		return SNew(SDockTab)
		[
			SNew(SNormalDistributionWidget)
			.Mean(this, &FNormalDistributionEditorToolkit::GetMean)
			.StandardDeviation(this, &FNormalDistributionEditorToolkit::GetStandardDeviation)
			.OnMeanChanged(this, &FNormalDistributionEditorToolkit::SetMean)
			.OnStandardDeviationChanged(this, &FNormalDistributionEditorToolkit::SetStandardDeviation)
		];
	}))
	.SetDisplayName(INVTEXT("PDF"))
	.SetGroup(WorkspaceMenuCategory.ToSharedRef());

	FPropertyEditorModule& PropertyEditorModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs DetailsViewArgs;
	DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
	TSharedRef<IDetailsView> DetailsView = PropertyEditorModule.CreateDetailView(DetailsViewArgs);
	DetailsView->SetObjects(TArray<UObject*>{ NormalDistribution });
	InTabManager->RegisterTabSpawner("NormalDistributionDetailsTab", FOnSpawnTab::CreateLambda([=](const FSpawnTabArgs&)
	{
		return SNew(SDockTab)
		[
			DetailsView
		];
	}))
	.SetDisplayName(INVTEXT("Details"))
	.SetGroup(WorkspaceMenuCategory.ToSharedRef());
}

void FNormalDistributionEditorToolkit::UnregisterTabSpawners(const TSharedRef<class FTabManager>& InTabManager)
{
	FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);
	InTabManager->UnregisterTabSpawner("NormalDistributionPDFTab");
	InTabManager->UnregisterTabSpawner("NormalDistributionDetailsTab");
}

float FNormalDistributionEditorToolkit::GetMean() const
{
	return NormalDistribution->Mean;
}

float FNormalDistributionEditorToolkit::GetStandardDeviation() const
{
	return NormalDistribution->StandardDeviation;
}

void FNormalDistributionEditorToolkit::SetMean(float Mean)
{
	NormalDistribution->Modify();
	NormalDistribution->Mean = Mean;
}

void FNormalDistributionEditorToolkit::SetStandardDeviation(float StandardDeviation)
{
	NormalDistribution->Modify();
	NormalDistribution->StandardDeviation = StandardDeviation;
}
