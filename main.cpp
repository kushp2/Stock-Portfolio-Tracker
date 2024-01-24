#include "MyForm.h"
#include "LoginForm.h"
#include <sqlite3.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Runtime::InteropServices;


[STAThread]
int main(array<System::String^>^ args)
{

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    int userKey;

    //starts the login form
    StockPortfolioApp::UsersDB* usersDB = new StockPortfolioApp::UsersDB();
    StockPortfolioApp::LoginForm^ loginForm = gcnew StockPortfolioApp::LoginForm(usersDB);
    Application::Run(loginForm);
    userKey = loginForm->getUserID();


    //if the user is logged in it starts the portfolio form
    if (loginForm->getUserID() != -1) {
        StockPortfolioApp::MyForm^ mainForm = gcnew StockPortfolioApp::MyForm(usersDB, userKey);
        Application::Run(mainForm);
    }
    

    return 0;
}