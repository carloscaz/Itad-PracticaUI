// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHealthBar.generated.h"

class UProgressBar;
UCLASS()
class UTAD_UI_FPS_API UPlayerHealthBar : public UUserWidget
{
	GENERATED_BODY()
	
private:

	float m_blinkTimer = 0.f;
	bool m_isLowHealth = false;
	bool m_blinkTurningRed = true;

	void UpdatePlayerHealthBar(int NewHealth, int MaxHealth);

	void LowHealthBlink();
	
protected:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
public:

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* playerHealthBar;


};
