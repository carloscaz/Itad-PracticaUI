
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Splash.generated.h"

class USkillTree;

UCLASS()
class UTAD_UI_FPS_API USplash : public UUserWidget
{
	GENERATED_BODY()
private:
	float m_splashScreenTimer = 0.0f;
	
public:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI)
	float SplashScreenDuration = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UI, DisplayName = "Skill Tree Screen")
	TSubclassOf<USkillTree> m_skillTree;


	

};
