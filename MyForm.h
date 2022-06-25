#pragma once

#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <urlmon.h>
#include <stdexcept>
#include <stdio.h>
#include <string>
#pragma comment(lib, "urlmon.lib")

std::string solana_Addr;
std::string solana_Bal;
char cmddeb[49] = "/c solana transfer --from my_solana_wallet.json ";
char solana_ammount;
char send_solana_addr;
LPCSTR space = " ";
LPCSTR cmdfin = " --allow-unfunded-recipient --url https://api.devnet.solana.com --fee-payer my_solana_wallet.json";
LPCSTR command_send;

namespace WWC {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			panel1->Hide();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2;




















	protected:
	private:
		/// <summary>
		std::string exec(const char* cmd)
		{
			char buffer[128];
			std::string result = "";
			FILE* pipe = _popen(cmd, "r");
			if (!pipe) throw std::runtime_error("popen() failed!");
			try {
				while (fgets(buffer, sizeof buffer, pipe) != 0) {
					result += buffer;
				}
			}
			catch (...) {
				_pclose(pipe);
				throw;
			}
			_pclose(pipe);
			return result;
		}
		std::string GetClipboardTexte()
		{
			OpenClipboard(nullptr);
			HANDLE hData = GetClipboardData(CF_TEXT);

			char* pszText = static_cast<char*>(GlobalLock(hData));
			std::string text(pszText);

			GlobalUnlock(hData);
			CloseClipboard();

			return text;
		}

		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>


		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(578, 65);
			this->label1->TabIndex = 0;
			this->label1->Text = L"WINDOWS SOLANA WALLET";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button1->ForeColor = System::Drawing::Color::SeaGreen;
			this->button1->Location = System::Drawing::Point(470, 443);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(168, 46);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ACCEPT";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label2->Location = System::Drawing::Point(93, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(415, 37);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Welcome to Windows Solana Wallet";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label3->Location = System::Drawing::Point(151, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(605, 37);
			this->label3->TabIndex = 3;
			this->label3->Text = L"with our product, you can create a Solana address";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label4->Location = System::Drawing::Point(16, 151);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(740, 37);
			this->label4->TabIndex = 4;
			this->label4->Text = L"and you can send and receive your solana quickly and easily !";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(50, 189);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(321, 323);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label5->Location = System::Drawing::Point(393, 420);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(245, 20);
			this->label5->TabIndex = 6;
			this->label5->Text = L"I agree to the Terms and Conditions";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->button2->ForeColor = System::Drawing::Color::Firebrick;
			this->button2->Location = System::Drawing::Point(644, 443);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(143, 46);
			this->button2->TabIndex = 7;
			this->button2->Text = L"EXIT";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::MediumTurquoise;
			this->label6->Location = System::Drawing::Point(1, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(578, 65);
			this->label6->TabIndex = 1;
			this->label6->Text = L"WINDOWS SOLANA WALLET";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label7->Location = System::Drawing::Point(18, 88);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(172, 30);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Solana Address : ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label8->Location = System::Drawing::Point(107, 136);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(128, 37);
			this->label8->TabIndex = 3;
			this->label8->Text = L"Balance : ";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label9->Location = System::Drawing::Point(184, 92);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(51, 25);
			this->label9->TabIndex = 4;
			solana_Addr = exec("solana-keygen pubkey C:/Windows/INF/WindowsSolanaWallet/my-solana-wallet/my-keypair.json").c_str();
			this->label9->Text = gcnew System::String(solana_Addr.c_str());
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label10->Location = System::Drawing::Point(250, 136);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 37);
			this->label10->TabIndex = 5;
			solana_Bal = exec("solana balance C:/Windows/INF/WindowsSolanaWallet/my-solana-wallet/my-keypair.json").c_str();
			this->label10->Text = gcnew System::String(solana_Bal.c_str());
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(714, 88);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(90, 31);
			this->button3->TabIndex = 6;
			this->button3->Text = L"PASTE";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button4->ForeColor = System::Drawing::Color::Red;
			this->button4->Location = System::Drawing::Point(551, 458);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(87, 42);
			this->button4->TabIndex = 7;
			this->button4->Text = L"EXIT";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe Print", 15.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::LimeGreen;
			this->label11->Location = System::Drawing::Point(3, 476);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(229, 36);
			this->label11->TabIndex = 8;
			this->label11->Text = L"SOLANA NETWORK";
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button6->Location = System::Drawing::Point(707, 327);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(97, 38);
			this->button6->TabIndex = 10;
			this->button6->Text = L"SEND";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label12->Location = System::Drawing::Point(43, 296);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(66, 30);
			this->label12->TabIndex = 13;
			this->label12->Text = L"SEND";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::LightSkyBlue;
			this->label13->Location = System::Drawing::Point(220, 296);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(133, 30);
			this->label13->TabIndex = 14;
			this->label13->Text = L"SOLANA TO ";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(114, 296);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 25);
			this->textBox1->TabIndex = 15;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(355, 296);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(449, 25);
			this->textBox2->TabIndex = 16;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button7->Location = System::Drawing::Point(427, 458);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(118, 42);
			this->button7->TabIndex = 17;
			this->button7->Text = L"WEBSITE";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// panel1
			// 
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(821, 512);
			this->panel1->TabIndex = 8;
			this->panel1->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(821, 512);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"Windows Solana Wallet";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Windows Solana Wallet";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		system("exit cmd.exe");
		system("exit conhost.exe");
		system("exit solana-install-init.exe");
		Application::Exit();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		system("exit cmd.exe");
		system("exit conhost.exe");
		system("exit solana-install-init.exe");
		panel1->Show();
	};
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		Clipboard::SetText(this->label9->Text);
	}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
{
	system("exit cmd.exe");
	system("exit conhost.exe");
	system("exit solana-install-init.exe");
	Application::Exit();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) 
{
	command_send = cmddeb + send_solana_addr + *space + solana_ammount + *cmdfin;
	ShellExecuteA(NULL, "open", "cmd", command_send, NULL, SW_HIDE);
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) 
{

}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) 
{
	system("start https://www.wsolanawallet.com");
}
};
}