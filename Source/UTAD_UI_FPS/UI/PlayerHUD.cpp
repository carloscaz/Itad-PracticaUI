// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerHUD.h"
#include "Crosshair.h"
#include "AmmoCounter.h"
#include "PlayerHealthBar.h"
#include "ReloadBar.h"

void UPlayerHUD::ShowNoWeapon()
{
	PlayerHealthBarWidget->Show();
	CrosshairWidget->Hide();
	AmmoCounterWidget->Hide();
	ReloadBarWidget->Hide();
	MinimapWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHUD::ShowAll()
{
	PlayerHealthBarWidget->Show();
	CrosshairWidget->Show();
	AmmoCounterWidget->Show();
	ReloadBarWidget->Show();
	MinimapWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
}

void UPlayerHUD::Hide()
{
	PlayerHealthBarWidget->Hide();
	CrosshairWidget->Hide();
	AmmoCounterWidget->Hide();
	ReloadBarWidget->Hide();
	MinimapWidget->SetVisibility(ESlateVisibility::Collapsed);
}

