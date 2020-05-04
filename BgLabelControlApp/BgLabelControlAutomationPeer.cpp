#include "pch.h"
#include "BgLabelControlAutomationPeer.h"
#include "BgLabelControlAutomationPeer.g.cpp"

namespace winrt::BgLabelControlApp::implementation
{
    BgLabelControlAutomationPeer::BgLabelControlAutomationPeer(BgLabelControlApp::BgLabelControl const& owner, hstring const& label)
    {
        Owner(owner);
        Label(label);
    }
    BgLabelControlApp::BgLabelControl BgLabelControlAutomationPeer::Owner()
    {
        return owner;
    }
    void BgLabelControlAutomationPeer::Owner(BgLabelControlApp::BgLabelControl const& value)
    {
        owner = value;
    }
    hstring BgLabelControlAutomationPeer::Label()
    {
        return label;
    }
    void BgLabelControlAutomationPeer::Label(hstring const& value)
    {
        BgLabelControlAutomationPeer::label = value;
    }
}
