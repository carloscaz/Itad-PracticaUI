// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHealthBar.h"
#include "Kismet/GameplayStatics.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "Components/ProgressBar.h"
#include "Math/Color.h"
#include "Styling/SlateColor.h"

#define BLINK_ANIMATION_TIME 1.f
#define BLINK_THRESHOLD 0.25f

void UPlayerHealthBar::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	LowHealthBlink();
}

void UPlayerHealthBar::NativeConstruct()
{
	Super::NativeConstruct();
	AUTAD_UI_FPSCharacter* Character = Cast<AUTAD_UI_FPSCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Character)
	{
		Character->OnHealthChanged.BindUObject(this, &UPlayerHealthBar::UpdatePlayerHealthBar);
	}
}


void UPlayerHealthBar::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);
	
}

void UPlayerHealthBar::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UPlayerHealthBar::UpdatePlayerHealthBar(int NewHealth, int MaxHealth)
{
	float healthPercentage = (float)NewHealth / (float)MaxHealth;
	playerHealthBar->SetPercent(healthPercentage);
	if (healthPercentage <= BLINK_THRESHOLD)
	{
		m_isLowHealth = true;
	}
	else
	{
		m_isLowHealth = false;
	}
}

void UPlayerHealthBar::LowHealthBlink()
{
	FProgressBarStyle HealthBarStyle = playerHealthBar->GetWidgetStyle();
	if (m_isLowHealth)
	{
		m_blinkTimer += GetWorld()->GetDeltaSeconds();
		if (m_blinkTimer >= BLINK_ANIMATION_TIME)
		{
			m_blinkTimer = 0.0f;
			m_blinkTurningRed = !m_blinkTurningRed;
		}
		if (m_blinkTurningRed)
		{
			HealthBarStyle.FillImage.TintColor = FSlateColor(FLinearColor(1.f, 0.f, 0.f, 1.f));
		}
		else
		{
			HealthBarStyle.FillImage.TintColor = FSlateColor(FLinearColor(0.f, 1.f, 0.f, 1.f));
		}
	}
	else
	{
		HealthBarStyle.FillImage.TintColor = FSlateColor(FLinearColor(0.f, 1.f, 0.f, 1.f));
	}
	playerHealthBar->SetWidgetStyle(HealthBarStyle);
}
