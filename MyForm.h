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
	private: 
		//input validation for the quantitiy input 
		String^ CheckInteger(String^ s){

			//hanles empty strings
			if (s->Trim()->Length == 0)
				return "Error: No quantity entered.";

			//checks for operational signs
			if (s[0] == '-' || s[0] == '+'){
				if (s->Length == 1)
					return "Error: Invalid quantity input.";
				s = s->Substring(1);
			}

			//checks to see if all characters are digits
			for each (wchar_t c in s){
				if (!iswdigit(c))
					return "Error: Invalid quantity input.";
			}

			//returns a blank string if valid
			return "";
		}

		//function to find a row with a specific symbol in the portfolioGrid
		DataGridViewRow^ FindRowBySymbol(String^ symbol) {
			for each (DataGridViewRow ^ row in portfolioGrid->Rows) {
				if (row->Cells["Symbol_col"]->Value != nullptr && row->Cells["Symbol_col"]->Value->ToString() == symbol) {
					return row;
				}
			}
			return nullptr;  // Return nullptr if the row is not found
		}


	private: System::Windows::Forms::RichTextBox^ Stock_Info;
	protected:

	private: System::Windows::Forms::TextBox^ Symbol_Input;
	private: System::Windows::Forms::Button^ Search_Button;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Button^ remove_button;
	private: System::Windows::Forms::Label^ quantity_label;
	private: System::Windows::Forms::TextBox^ Quantity_input;

	private: System::Windows::Forms::Label^ Error_Label;
	private: System::Windows::Forms::Label^ portfolio_Label;
	private: System::Windows::Forms::DataGridView^ portfolioGrid;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Symbol_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantity_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ currentPrice_col;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ buyPrice_col;









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
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->remove_button = (gcnew System::Windows::Forms::Button());
			this->quantity_label = (gcnew System::Windows::Forms::Label());
			this->Quantity_input = (gcnew System::Windows::Forms::TextBox());
			this->Error_Label = (gcnew System::Windows::Forms::Label());
			this->portfolio_Label = (gcnew System::Windows::Forms::Label());
			this->portfolioGrid = (gcnew System::Windows::Forms::DataGridView());
			this->Symbol_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantity_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->currentPrice_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->buyPrice_col = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->portfolioGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// Stock_Info
			// 
			this->Stock_Info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Stock_Info->Location = System::Drawing::Point(17, 85);
			this->Stock_Info->Name = L"Stock_Info";
			this->Stock_Info->Size = System::Drawing::Size(273, 339);
			this->Stock_Info->TabIndex = 0;
			this->Stock_Info->Text = L"";
			// 
			// Symbol_Input
			// 
			this->Symbol_Input->Font = (gcnew System::Drawing::Font(L"Candara Light", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Symbol_Input->Location = System::Drawing::Point(17, 46);
			this->Symbol_Input->MinimumSize = System::Drawing::Size(4, 30);
			this->Symbol_Input->Name = L"Symbol_Input";
			this->Symbol_Input->Size = System::Drawing::Size(158, 33);
			this->Symbol_Input->TabIndex = 1;
			this->Symbol_Input->TextChanged += gcnew System::EventHandler(this, &MyForm::Symbol_Input_TextChanged);
			// 
			// Search_Button
			// 
			this->Search_Button->AccessibleName = L"Search Button";
			this->Search_Button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Search_Button->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->Search_Button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Search_Button->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Search_Button->Location = System::Drawing::Point(181, 45);
			this->Search_Button->Name = L"Search_Button";
			this->Search_Button->Size = System::Drawing::Size(109, 33);
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
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label1->Size = System::Drawing::Size(209, 30);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Enter a stock symbol:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// add_button
			// 
			this->add_button->AccessibleName = L"Add Button";
			this->add_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->add_button->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->add_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->add_button->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->add_button->Location = System::Drawing::Point(171, 434);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(109, 34);
			this->add_button->TabIndex = 4;
			this->add_button->Text = L"Add";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &MyForm::add_button_Click);
			// 
			// remove_button
			// 
			this->remove_button->AccessibleName = L"Add Button";
			this->remove_button->Cursor = System::Windows::Forms::Cursors::Hand;
			this->remove_button->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->remove_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->remove_button->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->remove_button->Location = System::Drawing::Point(171, 474);
			this->remove_button->Name = L"remove_button";
			this->remove_button->Size = System::Drawing::Size(109, 34);
			this->remove_button->TabIndex = 5;
			this->remove_button->Text = L"Remove";
			this->remove_button->UseVisualStyleBackColor = true;
			this->remove_button->Click += gcnew System::EventHandler(this, &MyForm::remove_button_Click);
			// 
			// quantity_label
			// 
			this->quantity_label->AutoSize = true;
			this->quantity_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->quantity_label->Location = System::Drawing::Point(12, 456);
			this->quantity_label->Name = L"quantity_label";
			this->quantity_label->Size = System::Drawing::Size(88, 25);
			this->quantity_label->TabIndex = 6;
			this->quantity_label->Text = L"Quantity:";
			// 
			// Quantity_input
			// 
			this->Quantity_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Quantity_input->Location = System::Drawing::Point(107, 455);
			this->Quantity_input->Name = L"Quantity_input";
			this->Quantity_input->Size = System::Drawing::Size(34, 33);
			this->Quantity_input->TabIndex = 7;
			// 
			// Error_Label
			// 
			this->Error_Label->ForeColor = System::Drawing::Color::Crimson;
			this->Error_Label->Location = System::Drawing::Point(17, 511);
			this->Error_Label->Name = L"Error_Label";
			this->Error_Label->Size = System::Drawing::Size(263, 23);
			this->Error_Label->TabIndex = 8;
			this->Error_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// portfolio_Label
			// 
			this->portfolio_Label->AutoSize = true;
			this->portfolio_Label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->portfolio_Label->Location = System::Drawing::Point(431, 13);
			this->portfolio_Label->Name = L"portfolio_Label";
			this->portfolio_Label->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->portfolio_Label->Size = System::Drawing::Size(96, 30);
			this->portfolio_Label->TabIndex = 9;
			this->portfolio_Label->Text = L"Portfolio:";
			this->portfolio_Label->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			// 
			// portfolioGrid
			// 
			this->portfolioGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Symbol_col,
					this->Quantity_col, this->currentPrice_col, this->buyPrice_col
			});
			this->portfolioGrid->EnableHeadersVisualStyles = false;
			this->portfolioGrid->Location = System::Drawing::Point(332, 49);
			this->portfolioGrid->Name = L"portfolioGrid";
			this->portfolioGrid->RowHeadersVisible = false;
			this->portfolioGrid->Size = System::Drawing::Size(294, 458);
			this->portfolioGrid->TabIndex = 10;
			// 
			// Symbol_col
			// 
			this->Symbol_col->HeaderText = L"Symbol";
			this->Symbol_col->Name = L"Symbol_col";
			this->Symbol_col->Width = 50;
			// 
			// Quantity_col
			// 
			this->Quantity_col->HeaderText = L"Qty";
			this->Quantity_col->Name = L"Quantity_col";
			this->Quantity_col->Width = 50;
			// 
			// currentPrice_col
			// 
			this->currentPrice_col->HeaderText = L"Current Price";
			this->currentPrice_col->Name = L"currentPrice_col";
			// 
			// buyPrice_col
			// 
			this->buyPrice_col->HeaderText = L"Buy Price";
			this->buyPrice_col->Name = L"buyPrice_col";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(646, 538);
			this->Controls->Add(this->portfolioGrid);
			this->Controls->Add(this->portfolio_Label);
			this->Controls->Add(this->Error_Label);
			this->Controls->Add(this->Quantity_input);
			this->Controls->Add(this->quantity_label);
			this->Controls->Add(this->remove_button);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Search_Button);
			this->Controls->Add(this->Symbol_Input);
			this->Controls->Add(this->Stock_Info);
			this->Name = L"MyForm";
			this->Text = L"Portfolio";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->portfolioGrid))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//sets up the api
		private: 
			ApiWrapper^ apiWrapper = gcnew ApiWrapper();			//holds the api wrapper
			String^ current_symbol;									//holds the most recent entered symbol
			String^ stock_data;										//holds the data of the most recent symbol

		private: System::Void Symbol_Input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		}

		//the search button on click
		private: System::Void Search_Click(System::Object^ sender, System::EventArgs^ e) {
		
			//gets the input from the user and clears the input box
			current_symbol = Symbol_Input->Text;
			Symbol_Input->Clear();

			//retrieves the data and sends it to the text box
			stock_data = apiWrapper->FetchStockData(current_symbol);
			Stock_Info->Text = stock_data;
			Error_Label->Text = "";
		}

		//the add button on click
		private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {

			//if the quantity is invalid it sends an error message
			if (CheckInteger(Quantity_input->Text) != "") {
				Error_Label->Text = CheckInteger(Quantity_input->Text);
				return;
			}
			//else if there is no symbol/symbol data
			else if (String::IsNullOrEmpty(current_symbol) || String::IsNullOrEmpty(stock_data)){
				Error_Label->Text = "Error: No symbol searched.";
				return;
			}

			//gets data
			int quantity = Int32::Parse(Quantity_input->Text);
			String^ current_price;

			//parses the data the api retrieved and gets the price
			array<String^>^ lines = stock_data->Split(gcnew array<wchar_t>{'\n'}, StringSplitOptions::RemoveEmptyEntries);
			for each (String ^ line in lines) {
				array<String^>^ parts = line->Split(':');
				if (parts->Length == 2) {
					String^ key = parts[0]->Trim();
					String^ value = parts[1]->Trim();

					if (key == "05. price") {
						current_price = value;
					}
				}
			}//end for loop

			//adds the stock to he table, else it adds to an existing stock
			DataGridViewRow^ row = FindRowBySymbol(current_symbol);
			if (row == nullptr){
				array<String^>^ row = { current_symbol, quantity.ToString(), current_price, current_price };
				portfolioGrid->Rows->Add(row);
			}
			else{
				int currentQuantity = (row->Cells["Quantity_col"]->Value != nullptr) ? Int32::Parse(row->Cells["Quantity_col"]->Value->ToString()) : 0;
				int newQuantity = currentQuantity + quantity;
				row->Cells["Quantity_col"]->Value = newQuantity;
			}
				
			Error_Label->Text = "";
		}

		//removes the input stock on click
		private: System::Void remove_button_Click(System::Object^ sender, System::EventArgs^ e) {
			
			//returns an error if the symbol does not appear in the table
			DataGridViewRow^ row = FindRowBySymbol(current_symbol);
			if (row == nullptr) {
				Error_Label->Text = "Error: "+ current_symbol + " not found.";
				return;
			}

			//if the quantity or the symbol info is invalid it sends an error message
			if (CheckInteger(Quantity_input->Text) != "") {
				Error_Label->Text = CheckInteger(Quantity_input->Text);
				return;
			}
			if (String::IsNullOrEmpty(current_symbol) || String::IsNullOrEmpty(stock_data)) {
				Error_Label->Text = "Error: No symbol searched.";
			}
			
			//goes through each row of the table and check for the symbol
			for each (DataGridViewRow ^ row in portfolioGrid->Rows) {

				//if it finds a symbol that matches
				if (row->Cells["Symbol_col"]->Value->ToString() == current_symbol) {
				
					//gets quanitity and the amount to remove
					int currentQuantity = Int32::Parse(row->Cells["Quantity_col"]->Value->ToString());
					int quantityToRemove = Int32::Parse(Quantity_input->Text);

					//checks to see if it can remove that amount
					if (quantityToRemove > currentQuantity) {
						Error_Label->Text = "Error: Quantity to remove exceeds current quantity.";
						return;
					}

					// Update the quantity in the row and removes it if it is 0
					int newQuantity = currentQuantity - quantityToRemove;
					
					if (newQuantity == 0)
						portfolioGrid->Rows->Remove(row);
					else
						row->Cells["Quantity_col"]->Value = newQuantity.ToString();
					
					Error_Label->Text = "";
					return; 
				}
			}
		}
};
}
