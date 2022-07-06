#include "NormalDistributionFactory.h"
#include "NormalDistribution.h"

UNormalDistributionFactory::UNormalDistributionFactory()
{
    SupportedClass = UNormalDistribution::StaticClass();
    bCreateNew = true;
}

UObject* UNormalDistributionFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    return NewObject<UNormalDistribution>(InParent, Class, Name, Flags, Context);
}
