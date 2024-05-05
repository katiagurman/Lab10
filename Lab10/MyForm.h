#pragma once
#include <cmath>

namespace Lab10 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(88, 328);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 46);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Читати з файла дані";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(273, 171);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Обчислити";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(85, 88);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(114, 180);
			this->textBox1->TabIndex = 2;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(289, 328);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 46);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Записати у файл";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(248, 128);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(159, 22);
			this->textBox2->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(245, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(268, 16);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Середнє арифметичне непарних чисел.";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(540, 447);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fname = "numbers.txt";
		if (File::Exists(fname)) {
			StreamReader^ reader = File::OpenText(fname);

			textBox1->Clear();

			String^ fileContent = reader->ReadToEnd();

			array<String^>^ numbers = fileContent->Split(' ');

			for (int i = 0; i < numbers->Length; i++) {
				textBox1->AppendText(numbers[i] + Environment::NewLine);
			}

			reader->Close();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		int sum = 0;
		for (int i = 0; i < textBox1->Lines->Length; i++) {
			int number;
			if (int::TryParse(textBox1->Lines[i], number)) {
				if (number % 2 != 0) {
					sum += number;
				}
			}
		}

		double avarage = sum / textBox1->Lines->Length;

		textBox2->Text = Convert::ToString(avarage);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fileName = "output.txt";
		StreamWriter^ writer = File::CreateText(fileName);

		int sum = 0;

		for (int i = 0; i < textBox1->Lines->Length; i++) {
			int number;
			if (int::TryParse(textBox1->Lines[i], number)) {
				if (number % 2 != 0) {
					sum += number;
					writer->WriteLine(number);
				}
			}
		}

		double avarage = sum / textBox1->Lines->Length;
		writer->WriteLine("Середнє арифметичне: " + Convert::ToString(avarage));
		writer->Close();

		MessageBox::Show("Середнє арифметичне непарних чисел записано у файл: " + fileName);
	}
};
}
