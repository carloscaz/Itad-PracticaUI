// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ReloadBar.generated.h"

class UProgressBar;
UCLASS()
class UTAD_UI_FPS_API UReloadBar : public UUserWidget
{
	GENERATED_BODY()

private:

	void UpdateReloadBarValue(float NewValue);
	
public:
	
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* ReloadBar;


};
