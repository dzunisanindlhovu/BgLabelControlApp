#pragma once
#include "BgLabelControl.g.h"
#include <BgLabelControlAutomationPeer.h>

namespace winrt::BgLabelControlApp::implementation
{
    struct BgLabelControl : BgLabelControlT<BgLabelControl>
    {
        BgLabelControl() {
            DefaultStyleKey(winrt::box_value(L"BgLabelControlApp.BgLabelControl"));

            Visibility(winrt::Windows::UI::Xaml::Visibility::Visible);
            IsEnabled(true);
            IsTabStop(true);
            UseSystemFocusVisuals(true);
            AllowFocusOnInteraction(true);
            //Windows::UI::Xaml::Automation::AutomationProperties::SetHelpText(*this, L"Game");
            //Windows::UI::Xaml::Automation::AutomationProperties::SetName(*this, L"Game");
            //Windows::UI::Xaml::Automation::AutomationProperties::SetFullDescription(*this, L"Game is good");
        };

        winrt::hstring Label()
        {
            return winrt::unbox_value<winrt::hstring>(GetValue(m_labelProperty));
        }

        void GotFocus() {
            OutputDebugString(L"BgLabelControl got focus");
        }

        void Label(winrt::hstring const& value)
        {
            SetValue(m_labelProperty, winrt::box_value(value));
        }

        static Windows::UI::Xaml::DependencyProperty LabelProperty() { return m_labelProperty; }
        
        static void OnLabelChanged(Windows::UI::Xaml::DependencyObject const&, Windows::UI::Xaml::DependencyPropertyChangedEventArgs const&);

        Windows::UI::Xaml::Automation::Peers::AutomationPeer OnCreateAutomationPeer()
        {
            return winrt::make<BgLabelControlApp::implementation::BgLabelControlAutomationPeer>(*this, Label());
        }
    private:
        static Windows::UI::Xaml::DependencyProperty m_labelProperty;
    };
}
namespace winrt::BgLabelControlApp::factory_implementation
{
    struct BgLabelControl : BgLabelControlT<BgLabelControl, implementation::BgLabelControl>
    {
    };
}
