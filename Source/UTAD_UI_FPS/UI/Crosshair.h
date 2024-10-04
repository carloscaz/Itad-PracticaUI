// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Crosshair.generated.h"

class AUTAD_UI_FPSCharacter;
class UImage;

UCLASS()
class UTAD_UI_FPS_API UCrosshair : public UUserWidget
{
	GENERATED_BODY()
private:

	float m_animationTimer = 0;
	AUTAD_UI_FPSCharacter* m_character;
	virtual void NativeConstruct() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	float AnimationTime = 0.2f;
	
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Show();

	UFUNCTION(BlueprintCallable, Category = Visibility)
	void Hide();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* Crosshair;

	void SetCrosshairColor(bool EnemyDetected);

	void ShotAnimation();

	void MoveAnimation(bool Moving);

	UFUNCTION()
	void PrintSizeImage();
};
