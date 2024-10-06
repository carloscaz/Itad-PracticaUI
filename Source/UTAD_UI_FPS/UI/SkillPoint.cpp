// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillPoint.h"

#include "SkillTree.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

void USkillPoint::NativeConstruct()
{
	Super::NativeConstruct();
	m_previousState = GetIsEnabled();
	if(m_isInitButton)
	{
		EnableButton(true);
	}

	else
	{
		EnableButton(false);

	}
	
	m_button->OnClicked.AddDynamic(this, &USkillPoint::ButtonClicked);
	m_text->SetText(m_buttonText);
}

void USkillPoint::ButtonClicked() //Disable the clicked button
{
	//m_previousState = GetIsEnabled();
	if(m_skillTree->m_skillPoints > 0 && GetIsEnabled())
	{
		m_skillTree->SubtractPoints();
		m_skillTree->m_ButtonsPressed.Add(this);
		EnableButton(false);
		UnlockNextButton();
	}
}

void USkillPoint::UnlockNextButton()//unlock the next skill button
{
	if(m_nextSkillPoint)
	{
		//m_nextSkillPoint->m_previousState = m_nextSkillPoint->m_button->GetIsEnabled();
		m_nextSkillPoint->EnableButton(true);
	}
}

void USkillPoint::EnableButton(bool _value)
{
	m_button->SetIsEnabled(_value);
}

void USkillPoint::ResetState()//Reset the state of the button
{
	EnableButton(m_previousState);
	//m_nextSkillPoint->EnableButton(m_nextSkillPoint->m_previousState);
}
