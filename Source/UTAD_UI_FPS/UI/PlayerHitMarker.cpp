// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHitMarker.h"

#define HITMARKER_TIME 0.4f

void UPlayerHitMarker::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (GetVisibility() == ESlateVisibility::HitTestInvisible)
	{
		m_hitMarkerTime += InDeltaTime;
		if (m_hitMarkerTime >= HITMARKER_TIME)
		{
			SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void UPlayerHitMarker::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
	m_hitMarkerTime = 0.f;
}

void UPlayerHitMarker::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}
