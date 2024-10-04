// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AmmoCounter.generated.h"

class UTP_WeaponComponent;
class UTextBlock;

UCLASS()
class UTAD_UI_FPS_API UAmmoCounter : public UUserWidget
{
	GENERATED_BODY()
private:

	void UpdateCurrentAmmo(int NewCurrentAmmo);

	void UpdateTotalAmmo(int NewTotalAmmo);
	UTP_WeaponComponent* m_weaponComponent;
public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CurrentAmmo;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TotalAmmo;

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

};
