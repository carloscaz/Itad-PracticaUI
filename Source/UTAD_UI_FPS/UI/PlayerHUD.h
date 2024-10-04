// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHUD.generated.h"

class UAmmoCounter;
class UCrosshair;
class UPlayerHealthBar;
class UReloadBar;

UCLASS()
class UTAD_UI_FPS_API UPlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UAmmoCounter* AmmoCounterWidget;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UCrosshair* CrosshairWidget;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UPlayerHealthBar* PlayerHealthBarWidget;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UReloadBar* ReloadBarWidget;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UUserWidget* MinimapWidget;
	/** Show the Minimap and the PlayerHealthBar */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void ShowNoWeapon();

	/** Show all the widgets */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void ShowAll();

	/** Hide all the widgets */
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

};
