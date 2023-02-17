#pragma once
#include "MyForm.h"
#include "frmInstrucciones.h"
namespace Game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frmMenu : public System::Windows::Forms::Form
	{
	public:
		frmMenu(void)
		{
			InitializeComponent();
		}

	protected:
		~frmMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnIniciar;
	private: System::Windows::Forms::NumericUpDown^ nudVidas;
	private: System::Windows::Forms::NumericUpDown^ nudTiempo;
	private: System::Windows::Forms::NumericUpDown^ nudEnemigos;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnInstrucciones;



	protected:

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMenu::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnIniciar = (gcnew System::Windows::Forms::Button());
			this->nudVidas = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudTiempo = (gcnew System::Windows::Forms::NumericUpDown());
			this->nudEnemigos = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudVidas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudTiempo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudEnemigos))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1, -6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(519, 294);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Small", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Red;
			this->label1->Location = System::Drawing::Point(85, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(339, 43);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Delibird\'s Adventure";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnIniciar
			// 
			this->btnIniciar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIniciar->Location = System::Drawing::Point(137, 214);
			this->btnIniciar->Name = L"btnIniciar";
			this->btnIniciar->Size = System::Drawing::Size(122, 36);
			this->btnIniciar->TabIndex = 2;
			this->btnIniciar->Text = L"JUGAR";
			this->btnIniciar->UseVisualStyleBackColor = true;
			this->btnIniciar->Click += gcnew System::EventHandler(this, &frmMenu::btnIniciar_Click);
			// 
			// nudVidas
			// 
			this->nudVidas->Location = System::Drawing::Point(69, 117);
			this->nudVidas->Name = L"nudVidas";
			this->nudVidas->Size = System::Drawing::Size(64, 20);
			this->nudVidas->TabIndex = 3;
			this->nudVidas->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// nudTiempo
			// 
			this->nudTiempo->Location = System::Drawing::Point(281, 117);
			this->nudTiempo->Name = L"nudTiempo";
			this->nudTiempo->Size = System::Drawing::Size(64, 20);
			this->nudTiempo->TabIndex = 4;
			this->nudTiempo->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->nudTiempo->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 25, 0, 0, 0 });
			// 
			// nudEnemigos
			// 
			this->nudEnemigos->Location = System::Drawing::Point(173, 117);
			this->nudEnemigos->Name = L"nudEnemigos";
			this->nudEnemigos->Size = System::Drawing::Size(64, 20);
			this->nudEnemigos->TabIndex = 5;
			this->nudEnemigos->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->nudEnemigos->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(75, 83);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 18);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Vidas:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(283, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 18);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Tiempo:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(170, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 18);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Enemigos:";
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnInstrucciones->Location = System::Drawing::Point(93, 164);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(212, 32);
			this->btnInstrucciones->TabIndex = 9;
			this->btnInstrucciones->Text = L"INSTRUCCIONES";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &frmMenu::btnInstrucciones_Click);
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(521, 286);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->nudEnemigos);
			this->Controls->Add(this->nudTiempo);
			this->Controls->Add(this->nudVidas);
			this->Controls->Add(this->btnIniciar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"frmMenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Delibird\'s Adventure";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudVidas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudTiempo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nudEnemigos))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	Void btnIniciar_Click(Object^ sender, EventArgs^ e) {
		MyForm^ frm = gcnew MyForm((int)nudVidas->Value, (int)nudEnemigos->Value, (int)nudTiempo->Value);
		this->Visible = false;
		frm->ShowDialog();
		this->Visible = true;
	}
	Void btnInstrucciones_Click(Object^ sender, EventArgs^ e) {
		frmInstrucciones^ frmInst = gcnew frmInstrucciones();
		frmInst->ShowDialog();
		this->Visible = true;
}
};
}
