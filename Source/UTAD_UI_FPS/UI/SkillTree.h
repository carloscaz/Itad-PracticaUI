// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "SkillTree.generated.h"

class USkillPoint;
class UButton;
class UCanvasPanel;
class UTextBlock;
UCLASS()
class UTAD_UI_FPS_API USkillTree : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UCanvasPanel* CanvasPanel;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* NumberSkillPoints;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_cancelButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_acceptButton;;

	UPROPERTY(EditAnywhere, Category = "UILogic", DisplayName = "Skill Points")
	int m_skillPoints = 9;
	int m_previousPoints;
	
	TArray<USkillPoint*> m_skillsButtons;
	TArray<USkillPoint*> m_ButtonsPressed;
	

public:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	void Show();

	void Hide();
	
	
	UFUNCTION()
	void CancelMenu();
	
	UFUNCTION()
	void AcceptMenu();

	UFUNCTION()
	void SubtractPoints();
};
