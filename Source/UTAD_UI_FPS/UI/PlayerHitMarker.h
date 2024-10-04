// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHitMarker.generated.h"


UCLASS()
class UTAD_UI_FPS_API UPlayerHitMarker : public UUserWidget
{
	GENERATED_BODY()
private:

	float m_hitMarkerTime = 0.0f;
	

public:

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	void Show();

	void Hide();

	
};
