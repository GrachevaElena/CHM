#pragma once
#include "Table.h"
#include <cmath>

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
		RefForm(int task, double NGrid, double maxL, double eps, double x)
		{
			InitializeComponent();
			this->labelTask->Text = L"��� ������: " + ((task==MainTask)?"��������":"��������");
			this->labelNGrid->Text = L"����� ��������� =" + NGrid;
			this->labelMaxL->Text = L"������������ ���������� ����������� =" + maxL;
			this->labelEps->Text = L"������������ ����������� =" + eps + L" ��� x=" + x.ToString();
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
	protected:
	private: System::Windows::Forms::Label^  labelMaxL;
	private: System::Windows::Forms::Label^  labelNGrid;
	private: System::Windows::Forms::Label^  labelTask;
	private: System::Windows::Forms::Label^  labelEps;
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
		void InitializeComponent()
		{
			this->labelMaxL = (gcnew System::Windows::Forms::Label());
			this->labelNGrid = (gcnew System::Windows::Forms::Label());
			this->labelTask = (gcnew System::Windows::Forms::Label());
			this->labelEps = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelMaxL
			// 
			this->labelMaxL->AutoSize = true;
			this->labelMaxL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMaxL->Location = System::Drawing::Point(46, 70);
			this->labelMaxL->Name = L"labelMaxL";
			this->labelMaxL->Size = System::Drawing::Size(186, 17);
			this->labelMaxL->TabIndex = 0;
			this->labelMaxL->Text = L"���������� �����������: ";
			// 
			// labelNGrid
			// 
			this->labelNGrid->AutoSize = true;
			this->labelNGrid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelNGrid->Location = System::Drawing::Point(46, 40);
			this->labelNGrid->Name = L"labelNGrid";
			this->labelNGrid->Size = System::Drawing::Size(128, 17);
			this->labelNGrid->TabIndex = 1;
			this->labelNGrid->Text = L"����� ���������:";
			// 
			// labelTask
			// 
			this->labelTask->AutoSize = true;
			this->labelTask->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTask->Location = System::Drawing::Point(46, 10);
			this->labelTask->Name = L"labelTask";
			this->labelTask->Size = System::Drawing::Size(88, 17);
			this->labelTask->TabIndex = 1;
			this->labelTask->Text = L"��� ������:";
			// 
			// labelEps
			// 
			this->labelEps->AutoSize = true;
			this->labelEps->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelEps->Location = System::Drawing::Point(46, 99);
			this->labelEps->Name = L"labelEps";
			this->labelEps->Size = System::Drawing::Size(103, 17);
			this->labelEps->TabIndex = 2;
			this->labelEps->Text = L"�����������: ";
			// 
			// RefForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(566, 142);
			this->Controls->Add(this->labelEps);
			this->Controls->Add(this->labelTask);
			this->Controls->Add(this->labelNGrid);
			this->Controls->Add(this->labelMaxL);
			this->Name = L"RefForm";
			this->Text = L"�������";
			this->Load += gcnew System::EventHandler(this, &RefForm::RefForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RefForm_Load(System::Object^  sender, System::EventArgs^  e) {}

	};
}
