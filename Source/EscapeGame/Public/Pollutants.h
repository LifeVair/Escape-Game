#pragma once
#include "CoreMinimal.h"
/**
 * 
 */
UENUM(BlueprintType)
enum class E_Pollutants : uint8 {
	VOC UMETA(DisplayName = "VOC"),
	PM UMETA(DisplayName = "PM"),
	NOx UMETA(DisplayName = "NOx")
};