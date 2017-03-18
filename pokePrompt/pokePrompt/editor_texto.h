#pragma once
#include "gui.h"
#include <cstdio>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <array>

using std::string;
using std::cout;
namespace pokePrompt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	string s;
	/// <summary>
	/// Resumen de editor_texto
	/// </summary>
	public ref class editor_texto : public System::Windows::Forms::Form
	{
	public:
		editor_texto(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~editor_texto()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(13, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(718, 496);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(736, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"SAVE";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &editor_texto::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(737, 42);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(146, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"CANCEL";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &editor_texto::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(13, 6);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(362, 20);
			this->textBox2->TabIndex = 3;
			// 
			// editor_texto
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(895, 530);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"editor_texto";
			this->Text = L"editor_texto";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		std::string exec(const char* cmd) {
			std::array<char, 128> buffer;
			std::string result;
			std::string salto = "       ";
			std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
			if (!pipe) throw std::runtime_error("popen() failed!");
			while (!feof(pipe.get())) {
				if (fgets(buffer.data(), 128, pipe.get()) != NULL)
					result += buffer.data();
				result += salto;
			}
			return result;
		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
		//texto nuevo
		System::String^ texto = textBox1->Text;
		msclr::interop::marshal_context context;
		std::string nuevo_texto = context.marshal_as<std::string>(texto);

		string temp = ("echo ") + nuevo_texto+">"+p;

		const char * c = temp.c_str();
		string resp;
		resp = exec(c);
		
		this->Hide();
		textBox1->Text="";
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		textBox1->Text = "";
	}
	};
}
