// Fill out your copyright notice in the Description page of Project Settings.


#include "Crosshair.h"
#include "Components/Image.h"
#include "../UTAD_UI_FPSCharacter.h"

void UCrosshair::NativeConstruct()
{
	Super::NativeConstruct();

	m_character = Cast<AUTAD_UI_FPSCharacter>(GetOwningPlayerPawn());
}

void UCrosshair::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (m_animationTimer > 0)
	{
		m_animationTimer -= InDeltaTime;
		if (m_animationTimer <= 0)
		{
			m_character->AnimationShooting = false;
		}
	}
}

void UCrosshair::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UCrosshair::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UCrosshair::SetCrosshairColor(bool EnemyDetected)
{
	if(EnemyDetected)
	{
		Crosshair->SetBrushTintColor(FLinearColor::Red);
	}

	else
	{
		Crosshair->SetBrushTintColor(FLinearColor::White);
	}
	
}

void UCrosshair::ShotAnimation()
{
	m_character->AnimationShooting = true;
	m_animationTimer = AnimationTime;
	Crosshair->SetDesiredSizeOverride(FVector2D(125, 125));
}

void UCrosshair::MoveAnimation(bool Moving)
{
	if(Crosshair != nullptr)
	{
		if (Moving)
		{
			Crosshair->SetDesiredSizeOverride(FVector2D(75, 75));
			//UE_LOG(LogTemp, Warning, TEXT("%f, %f"),Crosshair->GetDesiredSize().X, Crosshair->GetDesiredSize().Y);
		}
		else
		{
			Crosshair->SetDesiredSizeOverride(FVector2D(100, 100));
			//UE_LOG(LogTemp, Warning, TEXT("%f, %f"),Crosshair->GetDesiredSize().X, Crosshair->GetDesiredSize().Y);

		}	
	}
	
}

void UCrosshair::PrintSizeImage()
{
	UE_LOG(LogTemp, Warning, TEXT("%f, %f"),Crosshair->GetDesiredSize().X, Crosshair->GetDesiredSize().Y);

}
