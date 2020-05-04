#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::BgLabelControlApp::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainPage::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        myButton().Content(box_value(L"Clicked"));
        auto peer = winrt::Windows::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer::FromElement(myButton());// as BgLabelAutomationPeer;
        if (peer != NULL) {
            myButton().Content(box_value(L"It's there man!"));
        }
        else {
            myButton().Content(box_value(L"No where to be seen"));
        }
    }
}
