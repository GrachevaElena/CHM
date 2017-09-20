#pragma once

namespace CHM9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� RefForm
	/// </summary>
	public ref class RefForm : public System::Windows::Forms::Form
	{
	public:
		RefForm(int udv, int del, int steps, double maxL)
		{
			InitializeComponent(udv, del, steps, maxL);
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
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
	protected:

	protected:




	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(int udv, int del, int steps, double maxL)
		{
			this->labelUdv = (gcnew System::Windows::Forms::Label());
			this->labelDel = (gcnew System::Windows::Forms::Label());
			this->labelSteps = (gcnew System::Windows::Forms::Label());
			this->labelMaxL = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelUdv
			// 
			this->labelUdv->AutoSize = true;
			this->labelUdv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelUdv->Location = System::Drawing::Point(46, 30);
			this->labelUdv->Name = L"labelUdv";
			this->labelUdv->Size = System::Drawing::Size(51, 20);
			this->labelUdv->TabIndex = 0;
			this->labelUdv->Text = L"����� ���������� ����: "+udv.ToString();
			// 
			// labelDel
			// 
			this->labelDel->AutoSize = true;
			this->labelDel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDel->Location = System::Drawing::Point(46, 70);
			this->labelDel->Name = L"labelDel";
			this->labelDel->Size = System::Drawing::Size(51, 20);
			this->labelDel->TabIndex = 0;
			this->labelDel->Text = L"����� ���������� ����: " + del.ToString();
			// 
			// labelSteps
			// 
			this->labelSteps->AutoSize = true;
			this->labelSteps->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelSteps->Location = System::Drawing::Point(46, 110);
			this->labelSteps->Name = L"labelSteps";
			this->labelSteps->Size = System::Drawing::Size(51, 20);
			this->labelSteps->TabIndex = 0;
			this->labelSteps->Text = L"����� ����� �����: " + steps.ToString();
			// 
			// labelMaxL
			// 
			this->labelMaxL->AutoSize = true;
			this->labelMaxL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMaxL->Location = System::Drawing::Point(46, 150);
			this->labelMaxL->Name = L"labelMaxL";
			this->labelMaxL->Size = System::Drawing::Size(51, 20);
			this->labelMaxL->TabIndex = 0;
			this->labelMaxL->Text = L"������������ ���. �����������: " + maxL.ToString();
			// 
			// RefForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(432, 205);
			this->Controls->Add(this->labelMaxL);
			this->Controls->Add(this->labelSteps);
			this->Controls->Add(this->labelDel);
			this->Controls->Add(this->labelUdv);
			this->Name = L"RefForm";
			this->Text = L"�������";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
