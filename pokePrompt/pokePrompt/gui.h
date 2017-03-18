#pragma once
//#include "stdAfx.h"
#include "editor_texto.h"
#include <cstdio>
#include <stdlib.h>
#include <stdio.h> 
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <array>

#include <iostream>
#include "BTree.h"
#include "BTreeNode.h"
#include "BTreePrinter.h"

using std::string;
using std::cout;

namespace pokePrompt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de gui
	/// </summary>
	public ref class gui : public System::Windows::Forms::Form
	{
	public:
		gui(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			
			std::string comando2 = "cd";

			const char * c2 = comando2.c_str();

			string resp = exec(c2);

			System::String^ respuesta2 = gcnew String(resp.c_str());

			label1->Text = respuesta2;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~gui()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	protected:

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
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(10, 29);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(826, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &gui::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(11, 55);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(825, 438);
			this->textBox2->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(824, 13);
			this->label1->TabIndex = 2;
			// 
			// gui
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(850, 505);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"gui";
			this->Text = L"gui";
			this->Load += gcnew System::EventHandler(this, &gui::gui_Load);
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
	private: System::Void gui_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == (char)Keys::Enter) {

			System::String^ comand = textBox1->Text;

			msclr::interop::marshal_context context;
			std::string comando = context.marshal_as<std::string>(comand);

			const char * c = comando.c_str();
			string resp;
			

			if(comando == "la"){
				resp = exec("dir");
			}
			else if (comando.find("touch")!= std::string::npos) {
				int fin = (comando.size() - 1);
				string temp = comando.substr(5, fin);

				editor_texto^ edt = gcnew editor_texto();
				edt->ShowDialog();
			}
			else if (comando.find("rm") != std::string::npos) {
				int fin = (comando.size() - 1);
				string temp= comando.substr(2, fin);
				if (comando.find(".txt") != std::string::npos) {
					resp = exec(c);
				}
				else {
					string temp2 = ("rm -rf" + temp);
					c = temp2.c_str();
					resp = exec(c);
				}
			}
			else if (comando.find("grep") != std::string::npos) {
				System::String^ managedString =textBox1->Text;
				msclr::interop::marshal_context context;
				string standardString = context.marshal_as<string>(managedString);
				string com = "findstr /s /i ";
				com.append(standardString.c_str());
				com.append(" .txt");
				resp = exec(com.c_str());

			}
			else if (comando.find("search") != std::string::npos) {
				int fin = (comando.size() - 1);
				string temp = ("DIR /S /b *")+comando.substr(7, fin)+"*";

				c = temp.c_str();
				resp = exec(c);
			}
			else if (comando.find("tree") != std::string::npos) {
				BTreePrinter printer;
				BTree t(2);

				srand(29324);

				for (unsigned i = 1; i <= 10; ++i)
				{
					/* 
					int p = rand() % 100;
					std::cout << "\ninsertando... " << p << "...\n\n";
					t.insert(p);
					printer.print(t);*/
				}
			}
			else {
				resp = exec(c);
			}
			

			System::String^ respuesta = gcnew String(resp.c_str());

			textBox2->Text = respuesta;
			textBox1->Text = "";

			
			//recargar direccion
			std::string comando2 = "cd";

			const char * c2 = comando2.c_str();

			string resp2 = exec(c2);

			System::String^ respuesta2 = gcnew String(resp2.c_str());

			label1->Text = respuesta2;
		}
		else {

		}
		

	}

};
}
