#pragma once

#include "MyForm.h"
#include "LoginForm.h"

namespace StockPortfolioApp {
    public ref class StockPortfolioAppForm : public System::Windows::Forms::Form {
    public:
       
        StockPortfolioAppForm() {
            InitializeComponent();
        }

    private:
        void InitializeComponent(void) {
            this->Text = L"Stock Portfolio App";
        }
    };
}
