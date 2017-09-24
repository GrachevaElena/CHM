#pragma once

namespace CHM9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для RefForm
	/// </summary>
	public ref class RefForm : public System::Windows::Forms::Form
	{
	public:
		RefForm(int udv, int del, double maxh, double minh, int steps, double maxL)
		{
			InitializeComponent();

			this->labelUdv->Text = L"Число увеличений шага: " + udv.ToString();
			this->labelDel->Text = L"Число уменьшений шага: " + del.ToString();
			this->labelSteps->Text = L"Общее число шагов: " + steps.ToString();
			this->labelMaxL->Text = L"Максимальная лок. погрешность: " + maxL.ToString();
			this->labelMaxh->Text = L"Максимальный шаг: " + maxh.ToString();
			this->labelMinh->Text = L"Минимальный шаг: " + minh.ToString();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RefForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelUdv;
	private: System::Windows::Forms::Label^  labelDel;
	private: System::Windows::Forms::Label^  labelSteps;
	private: System::Windows::Forms::Label^  labelMaxL;
	private: System::Windows::Forms::Label^  labelMaxh;
	private: System::Windows::Forms::Label^  labelMinh;
	protected:

	protected:




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
		void InitializeComponent()
		{
			this->labelUdv = (gcnew System::Windows::Forms::Label());
			this->labelDel = (gcnew System::Windows::Forms::Label());
			this->labelSteps = (gcnew System::Windows::Forms::Label());
			this->labelMaxL = (gcnew System::Windows::Forms::Label());
			this->labelMaxh = (gcnew System::Windows::Forms::Label());
			this->labelMinh = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelUdv
			// 
			this->labelUdv->AutoSize = true;
			this->labelUdv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelUdv->Location = System::Drawing::Point(46, 10);
			this->labelUdv->Name = L"labelUdv";
			this->labelUdv->Size = System::Drawing::Size(175, 17);
			this->labelUdv->TabIndex = 0;
			this->labelUdv->Text = L"Число увеличений шага: ";
			// 
			// labelDel
			// 
			this->labelDel->AutoSize = true;
			this->labelDel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDel->Location = System::Drawing::Point(46, 40);
			this->labelDel->Name = L"labelDel";
			this->labelDel->Size = System::Drawing::Size(179, 17);
			this->labelDel->TabIndex = 0;
			this->labelDel->Text = L"Число уменьшений шага: ";
			// 
			// labelSteps
			// 
			this->labelSteps->AutoSize = true;
			this->labelSteps->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSteps->Location = System::Drawing::Point(46, 130);
			this->labelSteps->Name = L"labelSteps";
			this->labelSteps->Size = System::Drawing::Size(148, 17);
			this->labelSteps->TabIndex = 0;
			this->labelSteps->Text = L"Общее число шагов: ";
			// 
			// labelMaxL
			// 
			this->labelMaxL->AutoSize = true;
			this->labelMaxL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMaxL->Location = System::Drawing::Point(46, 160);
			this->labelMaxL->Name = L"labelMaxL";
			this->labelMaxL->Size = System::Drawing::Size(233, 17);
			this->labelMaxL->TabIndex = 0;
			this->labelMaxL->Text = L"Максимальная лок. погрешность: ";
			// 
			// labelMaxh
			// 
			this->labelMaxh->AutoSize = true;
			this->labelMaxh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMaxh->Location = System::Drawing::Point(46, 70);
			this->labelMaxh->Name = L"labelMaxh";
			this->labelMaxh->Size = System::Drawing::Size(148, 17);
			this->labelMaxh->TabIndex = 0;
			this->labelMaxh->Text = L"Общее число шагов: ";
			// 
			// labelMinh
			// 
			this->labelMinh->AutoSize = true;
			this->labelMinh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMinh->Location = System::Drawing::Point(46, 100);
			this->labelMinh->Name = L"labelMinh";
			this->labelMinh->Size = System::Drawing::Size(148, 17);
			this->labelMinh->TabIndex = 0;
			this->labelMinh->Text = L"Общее число шагов: ";
			// 
			// RefForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(432, 205);
			this->Controls->Add(this->labelMaxL);
			this->Controls->Add(this->labelMaxh);
			this->Controls->Add(this->labelMinh);
			this->Controls->Add(this->labelSteps);
			this->Controls->Add(this->labelDel);
			this->Controls->Add(this->labelUdv);
			this->Name = L"RefForm";
			this->Text = L"Справка";
			this->Load += gcnew System::EventHandler(this, &RefForm::RefForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RefForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
