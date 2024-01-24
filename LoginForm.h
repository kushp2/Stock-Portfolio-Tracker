#pragma once

#include <sqlite3.h>
#include <msclr/marshal_cppstd.h>
#include "UsersDB.h"
#include <iostream>
#include <msclr/marshal_cppstd.h>

class UsersDB;

namespace StockPortfolioApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		//holds the user' ID
		property int userID;
		

		LoginForm(void* db) : usersDB(static_cast<UsersDB*>(db)){
			userID = -1;
			InitializeComponent();
		}

		int getUserID(){
			return userID;
		}
		void setUserID(int id) {
			userID = id;
		}

	protected:
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ userPromptLabel;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::RadioButton^ loginRButton;
	private: System::Windows::Forms::RadioButton^ deleteRButton;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::RadioButton^ createRButton;
	private: System::Windows::Forms::Button^ nextButton;
	private: System::Windows::Forms::Label^ Error_Label;

	private:
		System::ComponentModel::Container ^components;
		System::Windows::Forms::RadioButton^ selectedRadioButton;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->userPromptLabel = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->loginRButton = (gcnew System::Windows::Forms::RadioButton());
			this->deleteRButton = (gcnew System::Windows::Forms::RadioButton());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->createRButton = (gcnew System::Windows::Forms::RadioButton());
			this->nextButton = (gcnew System::Windows::Forms::Button());
			this->Error_Label = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// userPromptLabel
			// 
			this->userPromptLabel->AutoSize = true;
			this->userPromptLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userPromptLabel->Location = System::Drawing::Point(61, 24);
			this->userPromptLabel->Name = L"userPromptLabel";
			this->userPromptLabel->Size = System::Drawing::Size(150, 25);
			this->userPromptLabel->TabIndex = 0;
			this->userPromptLabel->Text = L"Enter Username:";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(39, 52);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(199, 24);
			this->textBox1->TabIndex = 1;
			// 
			// loginRButton
			// 
			this->loginRButton->AutoSize = true;
			this->loginRButton->Location = System::Drawing::Point(75, 82);
			this->loginRButton->Name = L"loginRButton";
			this->loginRButton->Size = System::Drawing::Size(51, 17);
			this->loginRButton->TabIndex = 2;
			this->loginRButton->TabStop = true;
			this->loginRButton->Text = L"Login";
			this->loginRButton->UseVisualStyleBackColor = true;
			this->loginRButton->CheckedChanged += gcnew System::EventHandler(this, &LoginForm::loginRButton_CheckedChanged);
			// 
			// deleteRButton
			// 
			this->deleteRButton->AutoSize = true;
			this->deleteRButton->Location = System::Drawing::Point(143, 82);
			this->deleteRButton->Name = L"deleteRButton";
			this->deleteRButton->Size = System::Drawing::Size(56, 17);
			this->deleteRButton->TabIndex = 3;
			this->deleteRButton->TabStop = true;
			this->deleteRButton->Text = L"Delete";
			this->deleteRButton->UseVisualStyleBackColor = true;
			this->deleteRButton->CheckedChanged += gcnew System::EventHandler(this, &LoginForm::deleteRButton_CheckedChanged);
			// 
			// createRButton
			// 
			this->createRButton->AutoSize = true;
			this->createRButton->Location = System::Drawing::Point(75, 105);
			this->createRButton->Name = L"createRButton";
			this->createRButton->Size = System::Drawing::Size(124, 17);
			this->createRButton->TabIndex = 4;
			this->createRButton->TabStop = true;
			this->createRButton->Text = L"Create New Account";
			this->createRButton->UseVisualStyleBackColor = true;
			this->createRButton->CheckedChanged += gcnew System::EventHandler(this, &LoginForm::createRButton_CheckedChanged);
			// 
			// nextButton
			// 
			this->nextButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nextButton->Location = System::Drawing::Point(75, 128);
			this->nextButton->Name = L"nextButton";
			this->nextButton->Size = System::Drawing::Size(124, 30);
			this->nextButton->TabIndex = 5;
			this->nextButton->Text = L"Next";
			this->nextButton->UseVisualStyleBackColor = true;
			this->nextButton->Click += gcnew System::EventHandler(this, &LoginForm::nextButton_Click);
			// 
			// Error_Label
			// 
			this->Error_Label->ForeColor = System::Drawing::Color::Crimson;
			this->Error_Label->Location = System::Drawing::Point(12, 161);
			this->Error_Label->Name = L"Error_Label";
			this->Error_Label->Size = System::Drawing::Size(263, 23);
			this->Error_Label->TabIndex = 9;
			this->Error_Label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 188);
			this->Controls->Add(this->Error_Label);
			this->Controls->Add(this->nextButton);
			this->Controls->Add(this->createRButton);
			this->Controls->Add(this->deleteRButton);
			this->Controls->Add(this->loginRButton);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->userPromptLabel);
			this->Name = L"LoginForm";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

			private:
				//variables
				String^ userName;					//holds the username from the textbox
				int primaryKey = -1;				//holds the users' primary key
				UsersDB* usersDB;
				msclr::interop::marshal_context context;


			//saves which radio button is picked
			private: System::Void loginRButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
				selectedRadioButton = loginRButton;
			}
			private: System::Void deleteRButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
				selectedRadioButton = deleteRButton;
			}
			private: System::Void createRButton_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
				selectedRadioButton = createRButton;
			}


			//on next button click
			private: System::Void nextButton_Click(System::Object^ sender, System::EventArgs^ e) {
			
				//gets the username and from the text box, gets the primary key from the username
				userName = textBox1->Text;
				std::string unmanagedUserName = context.marshal_as<const char*>(userName);
				setUserID(usersDB->getPrimaryKey(unmanagedUserName));

				//if the text box or radiobuttons are empty
				if (String::IsNullOrWhiteSpace(userName) || selectedRadioButton == nullptr) {
					Error_Label->Text = "Error: No username entered or no action selected.";
					return;
				}
				//else if the user is not in the database
				else if (userID == -1 && selectedRadioButton != createRButton){
					Error_Label->Text = "Error: Username does not exist.";
					return;

				}else{
					//else (all input feilds are correctly filled and the user is in the db)
					//if the login button was selected it opens the portfolio
					if (selectedRadioButton == loginRButton) {
						this->Close();
					}
					//if the delete button was selected it deletes the user
					else if (selectedRadioButton == deleteRButton) {
						if (usersDB->deletePortfolio(unmanagedUserName) && usersDB->removeUser(unmanagedUserName))
							Error_Label->Text = "Account Successfully Deleted.";
						else
							Error_Label->Text = "Error deleting account.";
						
						setUserID(-1);
						return;
					}
					//if the create button was selected
					else if (selectedRadioButton == createRButton) {
						
						//if the user already exists
						if (userID != -1){
							Error_Label->Text = "Error: Username already exists.";
							return;
						}

						//adds the user to the users database and make a portfolio table and gets the ID
						if (usersDB->insertUser(unmanagedUserName) && usersDB->createPortfolio(unmanagedUserName)){
							setUserID(usersDB->getPrimaryKey(unmanagedUserName));
							this->Close();
						}else
							Error_Label->Text = "Error: Could not create account.";

					}


				}//end of input validation else
			}//end of nextButton_Click

};
}
