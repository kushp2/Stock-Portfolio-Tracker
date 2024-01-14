#pragma once

#include "MyForm.h"

namespace StockPortfolioApp {
    public ref class StockPortfolioAppForm : public System::Windows::Forms::Form {
    public:
        StockPortfolioAppForm() {
            InitializeComponent();
        }

    private:
        void InitializeComponent(void) {
            // Initialize the components of your form
            // Add controls, set properties, etc.

            this->Text = L"Stock Portfolio App";
        }
    };
}
