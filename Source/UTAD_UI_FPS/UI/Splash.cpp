// Fill out your copyright notice in the Description page of Project Settings.


#include "Splash.h"

void USplash::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{	
	m_splashScreenTimer += InDeltaTime;
	if (m_splashScreenTimer >= SplashScreenDuration)
	{
		RemoveFromParent();
	}
	
}