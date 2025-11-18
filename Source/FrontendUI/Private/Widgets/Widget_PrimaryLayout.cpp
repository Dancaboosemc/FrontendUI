// Daniel McPherson All Rights Reserved


#include "Widgets/Widget_PrimaryLayout.h"
#include "FrontendDebug.h"
UCommonActivatableWidgetContainerBase* UWidget_PrimaryLayout::FindWidgetStackByTag(const FGameplayTag& InTag) const
{
	checkf(RegesteredWidgetStackMap.Contains(InTag), TEXT("Cannot find the widget stack by the tag &s"),*InTag.ToString())

	return RegesteredWidgetStackMap.FindRef(InTag);
}

void UWidget_PrimaryLayout::RegisterWidgetStack(UPARAM(meta = (Categories = "Frontend.WidgetStack"))FGameplayTag InStackTag, UCommonActivatableWidgetContainerBase* InStack)
{
	if (!IsDesignTime())
	{
		if (!RegesteredWidgetStackMap.Contains(InStackTag))
		{
			RegesteredWidgetStackMap.Add(InStackTag, InStack);
		}
	}
}
