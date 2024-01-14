#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create an instance of your form
    StockPortfolioApp::MyForm^ mainForm = gcnew StockPortfolioApp::MyForm();

    // Run the application
    Application::Run(mainForm);

    return 0;
}
