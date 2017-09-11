#pragma once
#include "Table.h"

namespace CHM9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl;
	private: System::Windows::Forms::TabPage^  testPage;
	private: System::Windows::Forms::TabPage^  mainPage;
	private: System::Windows::Forms::PictureBox^  pictureBoxMainTask;
	private: System::Windows::Forms::GroupBox^  groupBoxParametrs;


	private: System::Windows::Forms::Label^  labelM;

	private: System::Windows::Forms::Label^  labelA2;

	private: System::Windows::Forms::Label^  labelA1;
	private: System::Windows::Forms::TextBox^  textBoxM;


	private: System::Windows::Forms::TextBox^  textBoxA2;

	private: System::Windows::Forms::TextBox^  textBoxA1;

	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::Label^  labelU0;
	private: System::Windows::Forms::TextBox^  textBoxU0;










	private: System::Windows::Forms::Label^  labelX;

	private: System::Windows::Forms::Label^  labelLength;
	private: System::Windows::Forms::Label^  labelStep;
	private: System::Windows::Forms::Label^  labelMaxNumSteps;
	private: System::Windows::Forms::Label^  labelLocError;
	private: System::Windows::Forms::Label^  labelH;
	private: System::Windows::Forms::Label^  labelAccurBoard;
	private: System::Windows::Forms::Label^  labelL;
	private: System::Windows::Forms::TextBox^  textBoxStep;
	private: System::Windows::Forms::TextBox^  textBoxMaxNumSteps;
	private: System::Windows::Forms::TextBox^  textBoxLocError;
	private: System::Windows::Forms::TextBox^  textBoxAccurBoard;
	private: System::Windows::Forms::TextBox^  textBoxLenght;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;





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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->testPage = (gcnew System::Windows::Forms::TabPage());
			this->mainPage = (gcnew System::Windows::Forms::TabPage());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBoxParametrs = (gcnew System::Windows::Forms::GroupBox());
			this->labelStep = (gcnew System::Windows::Forms::Label());
			this->labelMaxNumSteps = (gcnew System::Windows::Forms::Label());
			this->labelLocError = (gcnew System::Windows::Forms::Label());
			this->labelH = (gcnew System::Windows::Forms::Label());
			this->labelAccurBoard = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelLength = (gcnew System::Windows::Forms::Label());
			this->labelL = (gcnew System::Windows::Forms::Label());
			this->labelX = (gcnew System::Windows::Forms::Label());
			this->labelU0 = (gcnew System::Windows::Forms::Label());
			this->labelM = (gcnew System::Windows::Forms::Label());
			this->textBoxU0 = (gcnew System::Windows::Forms::TextBox());
			this->labelA2 = (gcnew System::Windows::Forms::Label());
			this->labelA1 = (gcnew System::Windows::Forms::Label());
			this->textBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->textBoxM = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMaxNumSteps = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLocError = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAccurBoard = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA2 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxLenght = (gcnew System::Windows::Forms::TextBox());
			this->textBoxA1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBoxMainTask = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl->SuspendLayout();
			this->mainPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBoxParametrs->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMainTask))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->testPage);
			this->tabControl->Controls->Add(this->mainPage);
			this->tabControl->Location = System::Drawing::Point(-2, 2);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(868, 643);
			this->tabControl->TabIndex = 0;
			// 
			// testPage
			// 
			this->testPage->Location = System::Drawing::Point(4, 22);
			this->testPage->Name = L"testPage";
			this->testPage->Padding = System::Windows::Forms::Padding(3);
			this->testPage->Size = System::Drawing::Size(860, 617);
			this->testPage->TabIndex = 0;
			this->testPage->Text = L"Тестовая задача";
			this->testPage->UseVisualStyleBackColor = true;
			// 
			// mainPage
			// 
			this->mainPage->Controls->Add(this->button2);
			this->mainPage->Controls->Add(this->button3);
			this->mainPage->Controls->Add(this->button5);
			this->mainPage->Controls->Add(this->button4);
			this->mainPage->Controls->Add(this->button1);
			this->mainPage->Controls->Add(this->pictureBox1);
			this->mainPage->Controls->Add(this->groupBoxParametrs);
			this->mainPage->Controls->Add(this->pictureBoxMainTask);
			this->mainPage->Location = System::Drawing::Point(4, 22);
			this->mainPage->Name = L"mainPage";
			this->mainPage->Padding = System::Windows::Forms::Padding(3);
			this->mainPage->Size = System::Drawing::Size(860, 617);
			this->mainPage->TabIndex = 1;
			this->mainPage->Text = L"Основная задача";
			this->mainPage->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(25, 209);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(228, 47);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Решить";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(25, 262);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(228, 47);
			this->button3->TabIndex = 10;
			this->button3->Text = L"Очистить область";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(25, 407);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(228, 47);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Таблица";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(25, 460);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(228, 47);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Лок. погрешность";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(25, 354);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(228, 47);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Справка";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox1->Location = System::Drawing::Point(285, 177);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(554, 414);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// groupBoxParametrs
			// 
			this->groupBoxParametrs->Controls->Add(this->labelStep);
			this->groupBoxParametrs->Controls->Add(this->labelMaxNumSteps);
			this->groupBoxParametrs->Controls->Add(this->labelLocError);
			this->groupBoxParametrs->Controls->Add(this->labelH);
			this->groupBoxParametrs->Controls->Add(this->labelAccurBoard);
			this->groupBoxParametrs->Controls->Add(this->label2);
			this->groupBoxParametrs->Controls->Add(this->labelLength);
			this->groupBoxParametrs->Controls->Add(this->labelL);
			this->groupBoxParametrs->Controls->Add(this->labelX);
			this->groupBoxParametrs->Controls->Add(this->labelU0);
			this->groupBoxParametrs->Controls->Add(this->labelM);
			this->groupBoxParametrs->Controls->Add(this->textBoxU0);
			this->groupBoxParametrs->Controls->Add(this->labelA2);
			this->groupBoxParametrs->Controls->Add(this->labelA1);
			this->groupBoxParametrs->Controls->Add(this->textBoxStep);
			this->groupBoxParametrs->Controls->Add(this->textBoxM);
			this->groupBoxParametrs->Controls->Add(this->textBoxMaxNumSteps);
			this->groupBoxParametrs->Controls->Add(this->textBoxLocError);
			this->groupBoxParametrs->Controls->Add(this->textBoxAccurBoard);
			this->groupBoxParametrs->Controls->Add(this->textBoxA2);
			this->groupBoxParametrs->Controls->Add(this->textBoxLenght);
			this->groupBoxParametrs->Controls->Add(this->textBoxA1);
			this->groupBoxParametrs->Controls->Add(this->label1);
			this->groupBoxParametrs->Location = System::Drawing::Point(285, 6);
			this->groupBoxParametrs->Name = L"groupBoxParametrs";
			this->groupBoxParametrs->Size = System::Drawing::Size(554, 156);
			this->groupBoxParametrs->TabIndex = 8;
			this->groupBoxParametrs->TabStop = false;
			this->groupBoxParametrs->Text = L"Параметры задачи";
			// 
			// labelStep
			// 
			this->labelStep->AutoSize = true;
			this->labelStep->Location = System::Drawing::Point(207, 106);
			this->labelStep->Name = L"labelStep";
			this->labelStep->Size = System::Drawing::Size(112, 13);
			this->labelStep->TabIndex = 8;
			this->labelStep->Text = L"Шаг интегрирования";
			// 
			// labelMaxNumSteps
			// 
			this->labelMaxNumSteps->AutoSize = true;
			this->labelMaxNumSteps->Location = System::Drawing::Point(371, 62);
			this->labelMaxNumSteps->Name = L"labelMaxNumSteps";
			this->labelMaxNumSteps->Size = System::Drawing::Size(150, 13);
			this->labelMaxNumSteps->TabIndex = 8;
			this->labelMaxNumSteps->Text = L"Максимальное число шагов";
			// 
			// labelLocError
			// 
			this->labelLocError->AutoSize = true;
			this->labelLocError->Location = System::Drawing::Point(207, 62);
			this->labelLocError->Name = L"labelLocError";
			this->labelLocError->Size = System::Drawing::Size(148, 13);
			this->labelLocError->TabIndex = 8;
			this->labelLocError->Text = L"Контроль лок. погрешности";
			// 
			// labelH
			// 
			this->labelH->AutoSize = true;
			this->labelH->Location = System::Drawing::Point(207, 128);
			this->labelH->Name = L"labelH";
			this->labelH->Size = System::Drawing::Size(22, 13);
			this->labelH->TabIndex = 5;
			this->labelH->Text = L" h=";
			// 
			// labelAccurBoard
			// 
			this->labelAccurBoard->AutoSize = true;
			this->labelAccurBoard->Location = System::Drawing::Point(371, 20);
			this->labelAccurBoard->Name = L"labelAccurBoard";
			this->labelAccurBoard->Size = System::Drawing::Size(152, 13);
			this->labelAccurBoard->TabIndex = 8;
			this->labelAccurBoard->Text = L"Точность выхода на границу";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(39, 20);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Параметры";
			// 
			// labelLength
			// 
			this->labelLength->AutoSize = true;
			this->labelLength->Location = System::Drawing::Point(207, 20);
			this->labelLength->Name = L"labelLength";
			this->labelLength->Size = System::Drawing::Size(96, 13);
			this->labelLength->TabIndex = 8;
			this->labelLength->Text = L"Длина интервала";
			// 
			// labelL
			// 
			this->labelL->AutoSize = true;
			this->labelL->Location = System::Drawing::Point(207, 84);
			this->labelL->Name = L"labelL";
			this->labelL->Size = System::Drawing::Size(22, 13);
			this->labelL->TabIndex = 5;
			this->labelL->Text = L" L=";
			// 
			// labelX
			// 
			this->labelX->AutoSize = true;
			this->labelX->Location = System::Drawing::Point(207, 41);
			this->labelX->Name = L"labelX";
			this->labelX->Size = System::Drawing::Size(23, 13);
			this->labelX->TabIndex = 5;
			this->labelX->Text = L" X=";
			// 
			// labelU0
			// 
			this->labelU0->AutoSize = true;
			this->labelU0->Location = System::Drawing::Point(39, 128);
			this->labelU0->Name = L"labelU0";
			this->labelU0->Size = System::Drawing::Size(25, 13);
			this->labelU0->TabIndex = 5;
			this->labelU0->Text = L"u0=";
			// 
			// labelM
			// 
			this->labelM->AutoSize = true;
			this->labelM->Location = System::Drawing::Point(39, 94);
			this->labelM->Name = L"labelM";
			this->labelM->Size = System::Drawing::Size(24, 13);
			this->labelM->TabIndex = 7;
			this->labelM->Text = L" m=";
			// 
			// textBoxU0
			// 
			this->textBoxU0->Location = System::Drawing::Point(67, 125);
			this->textBoxU0->Name = L"textBoxU0";
			this->textBoxU0->Size = System::Drawing::Size(106, 20);
			this->textBoxU0->TabIndex = 4;
			// 
			// labelA2
			// 
			this->labelA2->AutoSize = true;
			this->labelA2->Location = System::Drawing::Point(39, 67);
			this->labelA2->Name = L"labelA2";
			this->labelA2->Size = System::Drawing::Size(25, 13);
			this->labelA2->TabIndex = 6;
			this->labelA2->Text = L"a2=";
			// 
			// labelA1
			// 
			this->labelA1->AutoSize = true;
			this->labelA1->Location = System::Drawing::Point(39, 41);
			this->labelA1->Name = L"labelA1";
			this->labelA1->Size = System::Drawing::Size(25, 13);
			this->labelA1->TabIndex = 5;
			this->labelA1->Text = L"a1=";
			// 
			// textBoxStep
			// 
			this->textBoxStep->Location = System::Drawing::Point(231, 125);
			this->textBoxStep->Name = L"textBoxStep";
			this->textBoxStep->Size = System::Drawing::Size(106, 20);
			this->textBoxStep->TabIndex = 4;
			// 
			// textBoxM
			// 
			this->textBoxM->Location = System::Drawing::Point(67, 89);
			this->textBoxM->Name = L"textBoxM";
			this->textBoxM->Size = System::Drawing::Size(106, 20);
			this->textBoxM->TabIndex = 4;
			// 
			// textBoxMaxNumSteps
			// 
			this->textBoxMaxNumSteps->Location = System::Drawing::Point(376, 81);
			this->textBoxMaxNumSteps->Name = L"textBoxMaxNumSteps";
			this->textBoxMaxNumSteps->Size = System::Drawing::Size(106, 20);
			this->textBoxMaxNumSteps->TabIndex = 4;
			// 
			// textBoxLocError
			// 
			this->textBoxLocError->Location = System::Drawing::Point(231, 81);
			this->textBoxLocError->Name = L"textBoxLocError";
			this->textBoxLocError->Size = System::Drawing::Size(106, 20);
			this->textBoxLocError->TabIndex = 4;
			// 
			// textBoxAccurBoard
			// 
			this->textBoxAccurBoard->Location = System::Drawing::Point(376, 37);
			this->textBoxAccurBoard->Name = L"textBoxAccurBoard";
			this->textBoxAccurBoard->Size = System::Drawing::Size(106, 20);
			this->textBoxAccurBoard->TabIndex = 4;
			// 
			// textBoxA2
			// 
			this->textBoxA2->Location = System::Drawing::Point(67, 63);
			this->textBoxA2->Name = L"textBoxA2";
			this->textBoxA2->Size = System::Drawing::Size(106, 20);
			this->textBoxA2->TabIndex = 4;
			// 
			// textBoxLenght
			// 
			this->textBoxLenght->Location = System::Drawing::Point(231, 37);
			this->textBoxLenght->Name = L"textBoxLenght";
			this->textBoxLenght->Size = System::Drawing::Size(106, 20);
			this->textBoxLenght->TabIndex = 4;
			// 
			// textBoxA1
			// 
			this->textBoxA1->Location = System::Drawing::Point(67, 37);
			this->textBoxA1->Name = L"textBoxA1";
			this->textBoxA1->Size = System::Drawing::Size(106, 20);
			this->textBoxA1->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(30, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 3;
			// 
			// pictureBoxMainTask
			// 
			this->pictureBoxMainTask->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxMainTask.BackgroundImage")));
			this->pictureBoxMainTask->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBoxMainTask->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBoxMainTask.ErrorImage")));
			this->pictureBoxMainTask->Location = System::Drawing::Point(25, 12);
			this->pictureBoxMainTask->Name = L"pictureBoxMainTask";
			this->pictureBoxMainTask->Size = System::Drawing::Size(228, 150);
			this->pictureBoxMainTask->TabIndex = 2;
			this->pictureBoxMainTask->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(863, 636);
			this->Controls->Add(this->tabControl);
			this->Name = L"MainForm";
			this->Text = L"Задача 9, вариант 3";
			this->tabControl->ResumeLayout(false);
			this->mainPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBoxParametrs->ResumeLayout(false);
			this->groupBoxParametrs->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBoxMainTask))->EndInit();
			this->ResumeLayout(false);

		}
};
}
