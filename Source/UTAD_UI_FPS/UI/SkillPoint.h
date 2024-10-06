// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkillPoint.generated.h"

class UTextBlock;
class USkillTree;
class UButton;
/**
 * 
 */
UCLASS()
class UTAD_UI_FPS_API USkillPoint : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_button;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* m_text;

	USkillTree* m_skillTree;

	

	UPROPERTY(EditAnywhere, Category = "UILogic", DisplayName = "isInitButton")
	bool m_isInitButton;

	bool m_previousState;

	UPROPERTY(EditAnywhere, Category = "UILogic", DisplayName = "ButtonText")
	FText m_buttonText;

	UPROPERTY(EditAnywhere, Category = "UILogic", DisplayName = "Next Skill Button")
	USkillPoint* m_nextSkillPoint;
	
	virtual void NativeConstruct() override;
	
	void Show();

	void Hide();

	UFUNCTION()
	void ButtonClicked();

	UFUNCTION()
	void UnlockNextButton();

	UFUNCTION()
	void EnableButton(bool _value);

	UFUNCTION()
	void ResetState();
};
