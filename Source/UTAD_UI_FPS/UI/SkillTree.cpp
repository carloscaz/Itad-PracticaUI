// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTree.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"

void USkillTree::NativeConstruct()
{
	Super::NativeConstruct();
	
	m_velocityButtonLv1->OnClicked.AddDynamic(this, &USkillTree::OnVelocityButtonLv1Clicked);
	m_velocityButtonLv2->OnClicked.AddDynamic(this, &USkillTree::OnVelocityButtonLv2Clicked);
	m_velocityButtonLv3->OnClicked.AddDynamic(this, &USkillTree::OnVelocityButtonLv3Clicked);
	m_velocityButtonLv2->SetIsEnabled(false);
	m_velocityButtonLv3->SetIsEnabled(false);

	m_healthButtonLv1->OnClicked.AddDynamic(this, &USkillTree::OnHealthButtonLv1Clicked);
	m_healthButtonLv2->OnClicked.AddDynamic(this, &USkillTree::OnHealthButtonLv2Clicked);
	m_healthButtonLv3->OnClicked.AddDynamic(this, &USkillTree::OnHealthButtonLv3Clicked);
	m_healthButtonLv2->SetIsEnabled(false);
	m_healthButtonLv3->SetIsEnabled(false);

	m_damageButtonLv1->OnClicked.AddDynamic(this, &USkillTree::OnDamageButtonLv1Clicked);
	m_damageButtonLv2->OnClicked.AddDynamic(this, &USkillTree::OnDamageButtonLv2Clicked);
	m_damageButtonLv3->OnClicked.AddDynamic(this, &USkillTree::OnDamageButtonLv3Clicked);
	m_damageButtonLv2->SetIsEnabled(false);
	m_damageButtonLv3->SetIsEnabled(false);

	m_cancelButton->OnClicked.AddDynamic(this, &USkillTree::CancelMenu);
	m_acceptButton->OnClicked.AddDynamic(this, &USkillTree::AcceptMenu);
	
	NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
	
}

void USkillTree::OnVelocityButtonLv1Clicked()
{
	IncreaseVelocity("velocityButtonLv1");
}

void USkillTree::OnVelocityButtonLv2Clicked()
{
	IncreaseVelocity("velocityButtonLv2");
}

void USkillTree::OnVelocityButtonLv3Clicked()
{
	IncreaseVelocity("velocityButtonLv3");
}

void USkillTree::OnHealthButtonLv1Clicked()
{
	IncreaseHealth("healthButtonLv1");
}

void USkillTree::OnHealthButtonLv2Clicked()
{
	IncreaseHealth("healthButtonLv2");
}

void USkillTree::OnHealthButtonLv3Clicked()
{
	IncreaseHealth("healthButtonLv3");
}

void USkillTree::OnDamageButtonLv1Clicked()
{
	IncreaseDamage("damageButtonLv1");
}

void USkillTree::OnDamageButtonLv2Clicked()
{
	IncreaseDamage("damageButtonLv2");
}

void USkillTree::OnDamageButtonLv3Clicked()
{
	IncreaseDamage("damageButtonLv3");
}

void USkillTree::Show()
{
	m_previousPoints = m_skillPoints;
	NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetInputMode(FInputModeGameAndUI());
	PlayerController->bShowMouseCursor = true;
	PlayerController->Pause();

	SetVisibility(ESlateVisibility::Visible);
	
}

void USkillTree::Hide()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetPause(false);

	SetVisibility(ESlateVisibility::Hidden);
}

void USkillTree::IncreaseVelocity(FString _buttonName)
{
	if(m_skillPoints > 0)
	{
		if(_buttonName == "velocityButtonLv1" && !m_velocityButtonLv2->GetIsEnabled())
		{
			m_skillPoints--;
			NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
			m_velocityButtonLv2->SetIsEnabled(true);
			return;
		}

		if(_buttonName == "velocityButtonLv2" && !m_velocityButtonLv3->GetIsEnabled())
		{
			m_skillPoints--;
			NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
			m_velocityButtonLv3->SetIsEnabled(true);
			return;
		}

		if(_buttonName == "velocityButtonLv3")
		{
			m_skillPoints--;
			NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
		}
	}
}



void USkillTree::IncreaseHealth(FString _buttonName)
{
	{
		if(m_skillPoints > 0)
		{
			if(_buttonName == "healthButtonLv1" && !m_healthButtonLv2->GetIsEnabled())
			{
				m_skillPoints--;
				NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
				m_healthButtonLv2->SetIsEnabled(true);
				return;
			}

			if(_buttonName == "healthButtonLv2" && !m_healthButtonLv3->GetIsEnabled())
			{
				m_skillPoints--;
				NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
				m_healthButtonLv3->SetIsEnabled(true);
				return;
			}

			if(_buttonName == "healthButtonLv3")
			{
				m_skillPoints--;
				NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
			}
		}
	}
}



void USkillTree::IncreaseDamage(FString _buttonName)
{
	{
		if(m_skillPoints > 0)
		{
			if(_buttonName == "damageButtonLv1" && !m_damageButtonLv2->GetIsEnabled())
			{
				m_skillPoints--;
				NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
				m_damageButtonLv2->SetIsEnabled(true);
				return;
			}

			if(_buttonName == "damageButtonLv2" && !m_damageButtonLv3->GetIsEnabled())
			{
				m_skillPoints--;
				NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
				m_damageButtonLv3->SetIsEnabled(true);
				return;
			}

			if(_buttonName == "damageButtonLv3")
			{
				m_skillPoints--;
				NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));
			}
		}
	}
}

void USkillTree::CancelMenu()
{
	m_skillPoints = m_previousPoints;
	if(!m_velocityLv2Unlock)
	m_velocityButtonLv2->SetIsEnabled(false);

	if(!m_velocityLv3Unlock)
	m_velocityButtonLv3->SetIsEnabled(false);

	if(!m_healthLv2Unlock)
	m_healthButtonLv2->SetIsEnabled(false);
	if(!m_healthLv3Unlock)
	m_healthButtonLv3->SetIsEnabled(false);

	if(!m_damageLv2Unlock)
	m_damageButtonLv2->SetIsEnabled(false);
	if(!m_damageLv3Unlock)
	m_damageButtonLv3->SetIsEnabled(false);
	
	Hide();
}

void USkillTree::AcceptMenu()
{
	m_velocityLv2Unlock = m_velocityButtonLv2->GetIsEnabled();
	m_velocityLv3Unlock = m_velocityButtonLv3->GetIsEnabled();

	m_damageLv2Unlock = m_damageButtonLv2->GetIsEnabled();
	m_damageLv3Unlock = m_damageButtonLv3->GetIsEnabled();

	m_healthLv2Unlock = m_healthButtonLv2->GetIsEnabled();
	m_healthLv3Unlock = m_healthButtonLv3->GetIsEnabled();
	Hide();
}
