#pragma once
#include "BgLabelControlAutomationPeer.g.h"

namespace winrt::BgLabelControlApp::implementation
{
    struct BgLabelControlAutomationPeer : BgLabelControlAutomationPeerT<BgLabelControlAutomationPeer>
    {
        BgLabelControlAutomationPeer(BgLabelControlApp::BgLabelControl const& owner, hstring const& label);

        BgLabelControlApp::BgLabelControl owner;
        BgLabelControlApp::BgLabelControl Owner();
        void Owner(BgLabelControlApp::BgLabelControl const& value);

        hstring label;
        hstring Label();
        void Label(hstring const& value);

        winrt::hstring GetClassNameCore() {
            return L"BgLabelControl";
        }

        Windows::UI::Xaml::Automation::Peers::AutomationControlType GetAutomationControlTypeCore()
        {
            return Windows::UI::Xaml::Automation::Peers::AutomationControlType::Button;
        }

        Windows::Foundation::IInspectable GetPatternCore(Windows::UI::Xaml::Automation::Peers::PatternInterface const& patternInterface)
        {
            if (patternInterface == Windows::UI::Xaml::Automation::Peers::PatternInterface::Invoke)
            {
                return *this;
            }
            return nullptr;
        }

        winrt::hstring GetLocalizedControlTypeCore()
        {
            return L"Game";
        }

        void Invoke() {

        }
    };
}
namespace winrt::BgLabelControlApp::factory_implementation
{
    struct BgLabelControlAutomationPeer : BgLabelControlAutomationPeerT<BgLabelControlAutomationPeer, implementation::BgLabelControlAutomationPeer>
    {
    };
}
