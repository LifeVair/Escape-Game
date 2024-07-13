#pragma once
#include "CoreMinimal.h"
/**
 * 
 */
UENUM(BlueprintType)
enum class E_Pollutants : uint8 {
	Option1 UMETA(DisplayName = "VOC"),
	Option2 UMETA(DisplayName = "PM"),
	Option3 UMETA(DisplayName = "NOx")
};