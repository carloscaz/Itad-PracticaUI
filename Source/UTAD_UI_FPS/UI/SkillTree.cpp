// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillTree.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "SkillPoint.h"

void USkillTree::NativeConstruct()
{
	Super::NativeConstruct();

	m_cancelButton->OnClicked.AddDynamic(this, &USkillTree::CancelMenu);
	m_acceptButton->OnClicked.AddDynamic(this, &USkillTree::AcceptMenu);
	
	NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));


	TArray<UWidget*> CanvasChildren = CanvasPanel->GetAllChildren();
	for (UWidget* Widget : CanvasChildren)
	{
		if(USkillPoint* SkillTreeNode = Cast<USkillPoint>(Widget))
		{
			m_skillsButtons.Add(SkillTreeNode);
			SkillTreeNode->m_skillTree = this;
		}
		
	}
}

void USkillTree::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
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

	//When menu show create a snapshot of the state of the buttons
	for(USkillPoint* skillButton : m_skillsButtons)
	{
		skillButton->m_previousState = skillButton->m_button->GetIsEnabled();
	}
	
}

void USkillTree::Hide()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	PlayerController->SetInputMode(FInputModeGameOnly());
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetPause(false);

	SetVisibility(ESlateVisibility::Hidden);
}

void USkillTree::CancelMenu() //Reset state of the buttons to the previous state
{
	m_skillPoints = m_previousPoints;

	for(USkillPoint* m_skillButton : m_skillsButtons)
	{
		m_skillButton->ResetState();
	}
	m_ButtonsPressed.Empty();
	
	Hide();
}

void USkillTree::AcceptMenu()
{
	Hide();
	m_ButtonsPressed.Empty();
}

void USkillTree::SubtractPoints()
{
	m_skillPoints--;
	NumberSkillPoints->SetText(FText::FromString(FString::FromInt(m_skillPoints)));

}
