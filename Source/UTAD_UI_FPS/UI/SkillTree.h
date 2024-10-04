// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "SkillTree.generated.h"

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
	UButton* m_velocityButtonLv1;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_velocityButtonLv2;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_velocityButtonLv3;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_healthButtonLv1;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_healthButtonLv2;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_healthButtonLv3;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_damageButtonLv1;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_damageButtonLv2;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_damageButtonLv3;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_cancelButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* m_acceptButton;;

	
	int m_skillPoints = 10;
	int m_previousPoints;

	bool m_velocityLv2Unlock = false;
	bool m_velocityLv3Unlock = false;
	bool m_healthLv2Unlock = false;
	bool m_healthLv3Unlock = false;
	bool m_damageLv2Unlock = false;
	bool m_damageLv3Unlock = false;
	

public:
	virtual void NativeConstruct() override;

	void Show();

	void Hide();
	
	UFUNCTION()
	void OnVelocityButtonLv1Clicked();

	UFUNCTION()
	void OnVelocityButtonLv2Clicked();
	
	UFUNCTION()
	void OnVelocityButtonLv3Clicked();
	
	void IncreaseVelocity(FString _buttonName);

	UFUNCTION()
	void OnHealthButtonLv1Clicked();

	UFUNCTION()
	void OnHealthButtonLv2Clicked();
	
	UFUNCTION()
	void OnHealthButtonLv3Clicked();

	void IncreaseHealth(FString _buttonName);

	UFUNCTION()
	void OnDamageButtonLv1Clicked();

	UFUNCTION()
	void OnDamageButtonLv2Clicked();
	
	UFUNCTION()
	void OnDamageButtonLv3Clicked();

	void IncreaseDamage(FString _buttonName);

	UFUNCTION()
	void CancelMenu();
	
	UFUNCTION()
	void AcceptMenu();
	
	

};
