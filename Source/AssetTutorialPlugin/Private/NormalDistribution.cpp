#include "NormalDistribution.h"

UNormalDistribution::UNormalDistribution()
    : Mean(0.5f)
    , StandardDeviation(0.2f)
{}

float UNormalDistribution::DrawSample()
{
    return std::normal_distribution<>(Mean, StandardDeviation)(RandomNumberGenerator);
}

void UNormalDistribution::LogSample()
{
    UE_LOG(LogTemp, Log, TEXT("%f"), DrawSample())
}
