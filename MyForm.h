#pragma once

#include "ApiWrapper.h"

namespace StockPortfolioApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ Stock_Info;
	protected:

	private: System::Windows::Forms::TextBox^ Symbol_Input;
	private: System::Windows::Forms::Button^ Search_Button;

	private: System::Windows::Forms::Label^ label1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Stock_Info = (gcnew System::Windows::Forms::RichTextBox());
			this->Symbol_Input = (gcnew System::Windows::Forms::TextBox());
			this->Search_Button = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// Stock_Info
			// 
			this->Stock_Info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Stock_Info->Location = System::Drawing::Point(28, 166);
			this->Stock_Info->Name = L"Stock_Info";
			this->Stock_Info->Size = System::Drawing::Size(697, 339);
			this->Stock_Info->TabIndex = 0;
			this->Stock_Info->Text = L"";
			// 
			// Symbol_Input
			// 
			this->Symbol_Input->Font = (gcnew System::Drawing::Font(L"Candara Light", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Symbol_Input->Location = System::Drawing::Point(91, 97);
			this->Symbol_Input->MinimumSize = System::Drawing::Size(4, 30);
			this->Symbol_Input->Name = L"Symbol_Input";
			this->Symbol_Input->Size = System::Drawing::Size(454, 33);
			this->Symbol_Input->TabIndex = 1;
			this->Symbol_Input->TextChanged += gcnew System::EventHandler(this, &MyForm::Symbol_Input_TextChanged);
			// 
			// Search_Button
			// 
			this->Search_Button->AccessibleName = L"Search Button";
			this->Search_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Search_Button->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->Search_Button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Search_Button->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Search_Button->Location = System::Drawing::Point(551, 90);
			this->Search_Button->Name = L"Search_Button";
			this->Search_Button->Size = System::Drawing::Size(105, 45);
			this->Search_Button->TabIndex = 2;
			this->Search_Button->Text = L"Search";
			this->Search_Button->UseVisualStyleBackColor = true;
			this->Search_Button->Click += gcnew System::EventHandler(this, &MyForm::Search_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(91, 63);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label1->Size = System::Drawing::Size(209, 30);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter a stock symbol:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(754, 538);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Search_Button);
			this->Controls->Add(this->Symbol_Input);
			this->Controls->Add(this->Stock_Info);
			this->Name = L"MyForm";
			this->Text = L"Portfolio";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//sets up the api
		ApiWrapper^ apiWrapper = gcnew ApiWrapper();

		private: System::Void Symbol_Input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}

		//the search button on click
		private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e) {
		
			//gets the input from the user and clears the input box
			String^ symbol = Symbol_Input->Text;
			Symbol_Input->Clear();

			//retrieves the data and sends it to the text box
			String^ stockData = apiWrapper->FetchStockData(symbol);
			Stock_Info->Text = stockData;

		}
};
}
