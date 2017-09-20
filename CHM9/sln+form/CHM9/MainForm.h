#pragma once
#include <cstdlib>
#include <ctime>
#include "Table.h"
#include "TableForm.h"
#include "RefForm.h"

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

	public: array<std::list<Table>*>^ table;
	public: std::list<int>** pens;

	private:
		double X;
		double* maxV, *minV, *maxX;
		Table* t1;
		Table* t2;
		int a;

	public:
		MainForm(void)
		{
			InitializeComponent();

			table = gcnew array<std::list<Table>*>(2);
			table[0] = new std::list<Table>();
			table[1] = new std::list<Table>();

			pens = new std::list<int>*[2];
			pens[0] = new std::list<int>();
			pens[1] = new std::list<int>();

			maxV = new double[2];
			minV = new double[2];
			maxX = new double[2];
			maxX[0] = maxX[1] = maxV[0] = maxV[1] = 0;
			minV[0] = minV[1] = 1000000;

			t1 = new Table();
			t2 = new Table();
			SetTable(*t1,1);
			table[0]->push_front(*t1);
			table[1]->push_front(*t1);
			X = 10;

			a = 0;
		}

	protected: void SetTable(Table& t, int a) {
		Row row;

		row.i = 0;
		row.xi = 0;
		row.viItog = 1*a;
		t.AddRow(row);

		row.i = 1;
		row.xi = 3;
		row.viItog = 17 * a;
		t.AddRow(row);

		row.i = 2;
		row.xi = 5;
		row.viItog = 12 * a;
		t.AddRow(row);

		row.i = 3;
		row.xi = 10;
		row.viItog = 15 * a;
		t.AddRow(row);
	}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete table[0];
				delete table[1];

				delete pens[0];
				delete pens[1];
				delete[] pens;

				delete[] maxX;
				delete[] maxV;
				delete[] minV;

				delete t1;
				delete t2;

				delete components;
			}
		}

	private: System::Windows::Forms::TabControl^  tabControl;
	private: System::Windows::Forms::TabPage^  testPage;
	private: System::Windows::Forms::TabPage^  mainPage;

	private: System::Windows::Forms::PictureBox^  main_pictureBoxTask;
	private: System::Windows::Forms::PictureBox^  main_pictureBoxGraphic;
	private: System::Windows::Forms::GroupBox^  main_groupBoxParametrs;
	private: System::Windows::Forms::Label^  main_labelM;
	private: System::Windows::Forms::Label^  main_labelA2;
	private: System::Windows::Forms::Label^  main_labelA1;
	private: System::Windows::Forms::Label^  main_labelU0;
	private: System::Windows::Forms::Label^  main_labelX;
	private: System::Windows::Forms::Label^  main_labelLength;
	private: System::Windows::Forms::Label^  main_labelStep;
	private: System::Windows::Forms::Label^  main_labelMaxNumSteps;
	private: System::Windows::Forms::Label^  main_labelLocError;
	private: System::Windows::Forms::Label^  main_labelH;
	private: System::Windows::Forms::Label^  main_labelAccurBoard;
	private: System::Windows::Forms::Label^  main_labelL;
	private: System::Windows::Forms::Label^  main_labelParameters;
	private: System::Windows::Forms::TextBox^ main_textBoxM;
	private: System::Windows::Forms::TextBox^  main_textBoxA2;
	private: System::Windows::Forms::TextBox^  main_textBoxA1;
	private: System::Windows::Forms::TextBox^  main_textBoxU0;
	private: System::Windows::Forms::TextBox^  main_textBoxStep;
	private: System::Windows::Forms::TextBox^  main_textBoxMaxNumSteps;
	private: System::Windows::Forms::TextBox^  main_textBoxLocError;
	private: System::Windows::Forms::TextBox^  main_textBoxAccurBoard;
	private: System::Windows::Forms::TextBox^  main_textBoxLenght;
	private: System::Windows::Forms::Button^  main_buttonSolve;
	private: System::Windows::Forms::Button^  main_buttonTable;
	private: System::Windows::Forms::Button^  main_buttonError;
	private: System::Windows::Forms::Button^  main_buttonRef;
	private: System::Windows::Forms::Button^  main_buttonClear;

	private: System::Windows::Forms::Button^  test_buttonSolve;
	private: System::Windows::Forms::Button^  test_buttonClear;
	private: System::Windows::Forms::Button^  test_buttonTable;
	private: System::Windows::Forms::Button^  test_buttonError;
	private: System::Windows::Forms::Button^  test_buttonRef;
	private: System::Windows::Forms::Button^  test_buttonTrueSolution;
	private: System::Windows::Forms::GroupBox^  test_groupBoxParametrs;
	private: System::Windows::Forms::Label^  test_labelStep;
	private: System::Windows::Forms::Label^  test_labelMaxNumSteps;
	private: System::Windows::Forms::Label^  test_labelLocError;
	private: System::Windows::Forms::Label^  test_labelH;
	private: System::Windows::Forms::Label^  test_labelAccurBoard;
	private: System::Windows::Forms::Label^  test_labelParameters;
	private: System::Windows::Forms::Label^  test_labelLenght;
	private: System::Windows::Forms::Label^  test_labelL;
	private: System::Windows::Forms::Label^  test_labelX;
	private: System::Windows::Forms::Label^  test_labelU0;
	private: System::Windows::Forms::TextBox^  test_textBoxU0;
	private: System::Windows::Forms::TextBox^  test_textBoxStep;
	private: System::Windows::Forms::TextBox^  test_textBoxMaxNumSteps;
	private: System::Windows::Forms::TextBox^  test_textBoxLocError;
	private: System::Windows::Forms::TextBox^  test_textBoxAccurBoard;
	private: System::Windows::Forms::TextBox^  test_textBoxLenght;
	private: System::Windows::Forms::PictureBox^  test_pictureBoxGraphic;
	private: System::Windows::Forms::PictureBox^  test_pictureBoxTask;

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
			this->test_buttonSolve = (gcnew System::Windows::Forms::Button());
			this->test_buttonClear = (gcnew System::Windows::Forms::Button());
			this->test_buttonTable = (gcnew System::Windows::Forms::Button());
			this->test_buttonError = (gcnew System::Windows::Forms::Button());
			this->test_buttonTrueSolution = (gcnew System::Windows::Forms::Button());
			this->test_buttonRef = (gcnew System::Windows::Forms::Button());
			this->test_groupBoxParametrs = (gcnew System::Windows::Forms::GroupBox());
			this->test_labelStep = (gcnew System::Windows::Forms::Label());
			this->test_labelMaxNumSteps = (gcnew System::Windows::Forms::Label());
			this->test_labelLocError = (gcnew System::Windows::Forms::Label());
			this->test_labelH = (gcnew System::Windows::Forms::Label());
			this->test_labelAccurBoard = (gcnew System::Windows::Forms::Label());
			this->test_labelParameters = (gcnew System::Windows::Forms::Label());
			this->test_labelLenght = (gcnew System::Windows::Forms::Label());
			this->test_labelL = (gcnew System::Windows::Forms::Label());
			this->test_labelX = (gcnew System::Windows::Forms::Label());
			this->test_labelU0 = (gcnew System::Windows::Forms::Label());
			this->test_textBoxU0 = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxMaxNumSteps = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxLocError = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxAccurBoard = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxLenght = (gcnew System::Windows::Forms::TextBox());
			this->test_pictureBoxGraphic = (gcnew System::Windows::Forms::PictureBox());
			this->test_pictureBoxTask = (gcnew System::Windows::Forms::PictureBox());
			this->mainPage = (gcnew System::Windows::Forms::TabPage());
			this->main_buttonSolve = (gcnew System::Windows::Forms::Button());
			this->main_buttonClear = (gcnew System::Windows::Forms::Button());
			this->main_buttonTable = (gcnew System::Windows::Forms::Button());
			this->main_buttonError = (gcnew System::Windows::Forms::Button());
			this->main_buttonRef = (gcnew System::Windows::Forms::Button());
			this->main_pictureBoxGraphic = (gcnew System::Windows::Forms::PictureBox());
			this->main_groupBoxParametrs = (gcnew System::Windows::Forms::GroupBox());
			this->main_labelStep = (gcnew System::Windows::Forms::Label());
			this->main_labelMaxNumSteps = (gcnew System::Windows::Forms::Label());
			this->main_labelLocError = (gcnew System::Windows::Forms::Label());
			this->main_labelH = (gcnew System::Windows::Forms::Label());
			this->main_labelAccurBoard = (gcnew System::Windows::Forms::Label());
			this->main_labelParameters = (gcnew System::Windows::Forms::Label());
			this->main_labelLength = (gcnew System::Windows::Forms::Label());
			this->main_labelL = (gcnew System::Windows::Forms::Label());
			this->main_labelX = (gcnew System::Windows::Forms::Label());
			this->main_labelU0 = (gcnew System::Windows::Forms::Label());
			this->main_labelM = (gcnew System::Windows::Forms::Label());
			this->main_textBoxU0 = (gcnew System::Windows::Forms::TextBox());
			this->main_labelA2 = (gcnew System::Windows::Forms::Label());
			this->main_labelA1 = (gcnew System::Windows::Forms::Label());
			this->main_textBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxM = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxMaxNumSteps = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxLocError = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxAccurBoard = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxA2 = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxLenght = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxA1 = (gcnew System::Windows::Forms::TextBox());
			this->main_pictureBoxTask = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl->SuspendLayout();
			this->testPage->SuspendLayout();
			this->test_groupBoxParametrs->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_pictureBoxGraphic))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_pictureBoxTask))->BeginInit();
			this->mainPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_pictureBoxGraphic))->BeginInit();
			this->main_groupBoxParametrs->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_pictureBoxTask))->BeginInit();
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
			this->testPage->Controls->Add(this->test_buttonSolve);
			this->testPage->Controls->Add(this->test_buttonClear);
			this->testPage->Controls->Add(this->test_buttonTable);
			this->testPage->Controls->Add(this->test_buttonError);
			this->testPage->Controls->Add(this->test_buttonTrueSolution);
			this->testPage->Controls->Add(this->test_buttonRef);
			this->testPage->Controls->Add(this->test_groupBoxParametrs);
			this->testPage->Controls->Add(this->test_pictureBoxGraphic);
			this->testPage->Controls->Add(this->test_pictureBoxTask);
			this->testPage->Location = System::Drawing::Point(4, 22);
			this->testPage->Name = L"testPage";
			this->testPage->Padding = System::Windows::Forms::Padding(3);
			this->testPage->Size = System::Drawing::Size(860, 617);
			this->testPage->TabIndex = 0;
			this->testPage->Text = L"Тестовая задача";
			this->testPage->UseVisualStyleBackColor = true;
			// 
			// test_buttonSolve
			// 
			this->test_buttonSolve->Location = System::Drawing::Point(25, 209);
			this->test_buttonSolve->Name = L"test_buttonSolve";
			this->test_buttonSolve->Size = System::Drawing::Size(228, 47);
			this->test_buttonSolve->TabIndex = 12;
			this->test_buttonSolve->Text = L"Решить";
			this->test_buttonSolve->UseVisualStyleBackColor = true;
			this->test_buttonSolve->Click += gcnew System::EventHandler(this, &MainForm::test_buttonSolve_Click);
			// 
			// test_buttonClear
			// 
			this->test_buttonClear->Location = System::Drawing::Point(25, 315);
			this->test_buttonClear->Name = L"test_buttonClear";
			this->test_buttonClear->Size = System::Drawing::Size(228, 47);
			this->test_buttonClear->TabIndex = 13;
			this->test_buttonClear->Text = L"Очистить область";
			this->test_buttonClear->UseVisualStyleBackColor = true;
			this->test_buttonClear->Click += gcnew System::EventHandler(this, &MainForm::test_buttonClear_Click);
			// 
			// test_buttonTable
			// 
			this->test_buttonTable->Location = System::Drawing::Point(25, 451);
			this->test_buttonTable->Name = L"test_buttonTable";
			this->test_buttonTable->Size = System::Drawing::Size(228, 47);
			this->test_buttonTable->TabIndex = 14;
			this->test_buttonTable->Text = L"Таблица";
			this->test_buttonTable->UseVisualStyleBackColor = true;
			this->test_buttonTable->Click += gcnew System::EventHandler(this, &MainForm::buttonTable_Click);
			// 
			// test_buttonError
			// 
			this->test_buttonError->Location = System::Drawing::Point(25, 504);
			this->test_buttonError->Name = L"test_buttonError";
			this->test_buttonError->Size = System::Drawing::Size(228, 47);
			this->test_buttonError->TabIndex = 15;
			this->test_buttonError->Text = L"Лок. погрешность";
			this->test_buttonError->UseVisualStyleBackColor = true;
			// 
			// test_buttonTrueSolution
			// 
			this->test_buttonTrueSolution->Location = System::Drawing::Point(25, 262);
			this->test_buttonTrueSolution->Name = L"test_buttonTrueSolution";
			this->test_buttonTrueSolution->Size = System::Drawing::Size(228, 47);
			this->test_buttonTrueSolution->TabIndex = 16;
			this->test_buttonTrueSolution->Text = L"Показать истинное решение";
			this->test_buttonTrueSolution->UseVisualStyleBackColor = true;
			// 
			// test_buttonRef
			// 
			this->test_buttonRef->Location = System::Drawing::Point(25, 398);
			this->test_buttonRef->Name = L"test_buttonRef";
			this->test_buttonRef->Size = System::Drawing::Size(228, 47);
			this->test_buttonRef->TabIndex = 16;
			this->test_buttonRef->Text = L"Справка";
			this->test_buttonRef->UseVisualStyleBackColor = true;
			this->test_buttonRef->Click += gcnew System::EventHandler(this, &MainForm::buttonRef_Click);
			// 
			// test_groupBoxParametrs
			// 
			this->test_groupBoxParametrs->Controls->Add(this->test_labelStep);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelMaxNumSteps);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelLocError);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelH);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelAccurBoard);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelParameters);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelLenght);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelL);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelX);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelU0);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxU0);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxStep);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxMaxNumSteps);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxLocError);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxAccurBoard);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxLenght);
			this->test_groupBoxParametrs->Location = System::Drawing::Point(285, 6);
			this->test_groupBoxParametrs->Name = L"test_groupBoxParametrs";
			this->test_groupBoxParametrs->Size = System::Drawing::Size(554, 156);
			this->test_groupBoxParametrs->TabIndex = 11;
			this->test_groupBoxParametrs->TabStop = false;
			this->test_groupBoxParametrs->Text = L"Параметры задачи";
			// 
			// test_labelStep
			// 
			this->test_labelStep->AutoSize = true;
			this->test_labelStep->Location = System::Drawing::Point(37, 84);
			this->test_labelStep->Name = L"test_labelStep";
			this->test_labelStep->Size = System::Drawing::Size(112, 13);
			this->test_labelStep->TabIndex = 8;
			this->test_labelStep->Text = L"Шаг интегрирования";
			// 
			// test_labelMaxNumSteps
			// 
			this->test_labelMaxNumSteps->AutoSize = true;
			this->test_labelMaxNumSteps->Location = System::Drawing::Point(371, 85);
			this->test_labelMaxNumSteps->Name = L"test_labelMaxNumSteps";
			this->test_labelMaxNumSteps->Size = System::Drawing::Size(150, 13);
			this->test_labelMaxNumSteps->TabIndex = 8;
			this->test_labelMaxNumSteps->Text = L"Максимальное число шагов";
			// 
			// test_labelLocError
			// 
			this->test_labelLocError->AutoSize = true;
			this->test_labelLocError->Location = System::Drawing::Point(201, 85);
			this->test_labelLocError->Name = L"test_labelLocError";
			this->test_labelLocError->Size = System::Drawing::Size(148, 13);
			this->test_labelLocError->TabIndex = 8;
			this->test_labelLocError->Text = L"Контроль лок. погрешности";
			// 
			// test_labelH
			// 
			this->test_labelH->AutoSize = true;
			this->test_labelH->Location = System::Drawing::Point(37, 106);
			this->test_labelH->Name = L"test_labelH";
			this->test_labelH->Size = System::Drawing::Size(22, 13);
			this->test_labelH->TabIndex = 5;
			this->test_labelH->Text = L" h=";
			// 
			// test_labelAccurBoard
			// 
			this->test_labelAccurBoard->AutoSize = true;
			this->test_labelAccurBoard->Location = System::Drawing::Point(371, 32);
			this->test_labelAccurBoard->Name = L"test_labelAccurBoard";
			this->test_labelAccurBoard->Size = System::Drawing::Size(152, 13);
			this->test_labelAccurBoard->TabIndex = 8;
			this->test_labelAccurBoard->Text = L"Точность выхода на границу";
			// 
			// test_labelParameters
			// 
			this->test_labelParameters->AutoSize = true;
			this->test_labelParameters->Location = System::Drawing::Point(37, 31);
			this->test_labelParameters->Name = L"test_labelParameters";
			this->test_labelParameters->Size = System::Drawing::Size(66, 13);
			this->test_labelParameters->TabIndex = 8;
			this->test_labelParameters->Text = L"Параметры";
			// 
			// test_labelLenght
			// 
			this->test_labelLenght->AutoSize = true;
			this->test_labelLenght->Location = System::Drawing::Point(201, 32);
			this->test_labelLenght->Name = L"test_labelLenght";
			this->test_labelLenght->Size = System::Drawing::Size(96, 13);
			this->test_labelLenght->TabIndex = 8;
			this->test_labelLenght->Text = L"Длина интервала";
			// 
			// test_labelL
			// 
			this->test_labelL->AutoSize = true;
			this->test_labelL->Location = System::Drawing::Point(201, 107);
			this->test_labelL->Name = L"test_labelL";
			this->test_labelL->Size = System::Drawing::Size(22, 13);
			this->test_labelL->TabIndex = 5;
			this->test_labelL->Text = L" L=";
			// 
			// test_labelX
			// 
			this->test_labelX->AutoSize = true;
			this->test_labelX->Location = System::Drawing::Point(201, 53);
			this->test_labelX->Name = L"test_labelX";
			this->test_labelX->Size = System::Drawing::Size(23, 13);
			this->test_labelX->TabIndex = 5;
			this->test_labelX->Text = L" X=";
			// 
			// test_labelU0
			// 
			this->test_labelU0->AutoSize = true;
			this->test_labelU0->Location = System::Drawing::Point(34, 53);
			this->test_labelU0->Name = L"test_labelU0";
			this->test_labelU0->Size = System::Drawing::Size(25, 13);
			this->test_labelU0->TabIndex = 5;
			this->test_labelU0->Text = L"u0=";
			// 
			// test_textBoxU0
			// 
			this->test_textBoxU0->Location = System::Drawing::Point(62, 50);
			this->test_textBoxU0->Name = L"test_textBoxU0";
			this->test_textBoxU0->Size = System::Drawing::Size(106, 20);
			this->test_textBoxU0->TabIndex = 4;
			// 
			// test_textBoxStep
			// 
			this->test_textBoxStep->Location = System::Drawing::Point(61, 103);
			this->test_textBoxStep->Name = L"test_textBoxStep";
			this->test_textBoxStep->Size = System::Drawing::Size(106, 20);
			this->test_textBoxStep->TabIndex = 4;
			// 
			// test_textBoxMaxNumSteps
			// 
			this->test_textBoxMaxNumSteps->Location = System::Drawing::Point(376, 104);
			this->test_textBoxMaxNumSteps->Name = L"test_textBoxMaxNumSteps";
			this->test_textBoxMaxNumSteps->Size = System::Drawing::Size(106, 20);
			this->test_textBoxMaxNumSteps->TabIndex = 4;
			// 
			// test_textBoxLocError
			// 
			this->test_textBoxLocError->Location = System::Drawing::Point(225, 104);
			this->test_textBoxLocError->Name = L"test_textBoxLocError";
			this->test_textBoxLocError->Size = System::Drawing::Size(106, 20);
			this->test_textBoxLocError->TabIndex = 4;
			// 
			// test_textBoxAccurBoard
			// 
			this->test_textBoxAccurBoard->Location = System::Drawing::Point(376, 49);
			this->test_textBoxAccurBoard->Name = L"test_textBoxAccurBoard";
			this->test_textBoxAccurBoard->Size = System::Drawing::Size(106, 20);
			this->test_textBoxAccurBoard->TabIndex = 4;
			// 
			// test_textBoxLenght
			// 
			this->test_textBoxLenght->Location = System::Drawing::Point(225, 49);
			this->test_textBoxLenght->Name = L"test_textBoxLenght";
			this->test_textBoxLenght->Size = System::Drawing::Size(106, 20);
			this->test_textBoxLenght->TabIndex = 4;
			this->test_textBoxLenght->Text = L"10";
			// 
			// test_pictureBoxGraphic
			// 
			this->test_pictureBoxGraphic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->test_pictureBoxGraphic->Location = System::Drawing::Point(285, 177);
			this->test_pictureBoxGraphic->Name = L"test_pictureBoxGraphic";
			this->test_pictureBoxGraphic->Size = System::Drawing::Size(554, 414);
			this->test_pictureBoxGraphic->TabIndex = 10;
			this->test_pictureBoxGraphic->TabStop = false;
			// 
			// test_pictureBoxTask
			// 
			this->test_pictureBoxTask->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"test_pictureBoxTask.BackgroundImage")));
			this->test_pictureBoxTask->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->test_pictureBoxTask->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"test_pictureBoxTask.ErrorImage")));
			this->test_pictureBoxTask->Location = System::Drawing::Point(25, 12);
			this->test_pictureBoxTask->Name = L"test_pictureBoxTask";
			this->test_pictureBoxTask->Size = System::Drawing::Size(228, 150);
			this->test_pictureBoxTask->TabIndex = 3;
			this->test_pictureBoxTask->TabStop = false;
			// 
			// mainPage
			// 
			this->mainPage->Controls->Add(this->main_buttonSolve);
			this->mainPage->Controls->Add(this->main_buttonClear);
			this->mainPage->Controls->Add(this->main_buttonTable);
			this->mainPage->Controls->Add(this->main_buttonError);
			this->mainPage->Controls->Add(this->main_buttonRef);
			this->mainPage->Controls->Add(this->main_pictureBoxGraphic);
			this->mainPage->Controls->Add(this->main_groupBoxParametrs);
			this->mainPage->Controls->Add(this->main_pictureBoxTask);
			this->mainPage->Location = System::Drawing::Point(4, 22);
			this->mainPage->Name = L"mainPage";
			this->mainPage->Padding = System::Windows::Forms::Padding(3);
			this->mainPage->Size = System::Drawing::Size(860, 617);
			this->mainPage->TabIndex = 1;
			this->mainPage->Text = L"Основная задача";
			this->mainPage->UseVisualStyleBackColor = true;
			// 
			// main_buttonSolve
			// 
			this->main_buttonSolve->Location = System::Drawing::Point(25, 209);
			this->main_buttonSolve->Name = L"main_buttonSolve";
			this->main_buttonSolve->Size = System::Drawing::Size(228, 47);
			this->main_buttonSolve->TabIndex = 10;
			this->main_buttonSolve->Text = L"Решить";
			this->main_buttonSolve->UseVisualStyleBackColor = true;
			this->main_buttonSolve->Click += gcnew System::EventHandler(this, &MainForm::main_buttonSolve_Click);
			// 
			// main_buttonClear
			// 
			this->main_buttonClear->Location = System::Drawing::Point(25, 262);
			this->main_buttonClear->Name = L"main_buttonClear";
			this->main_buttonClear->Size = System::Drawing::Size(228, 47);
			this->main_buttonClear->TabIndex = 10;
			this->main_buttonClear->Text = L"Очистить область";
			this->main_buttonClear->UseVisualStyleBackColor = true;
			this->main_buttonClear->Click += gcnew System::EventHandler(this, &MainForm::main_buttonClear_Click);
			// 
			// main_buttonTable
			// 
			this->main_buttonTable->Location = System::Drawing::Point(25, 407);
			this->main_buttonTable->Name = L"main_buttonTable";
			this->main_buttonTable->Size = System::Drawing::Size(228, 47);
			this->main_buttonTable->TabIndex = 10;
			this->main_buttonTable->Text = L"Таблица";
			this->main_buttonTable->UseVisualStyleBackColor = true;
			this->main_buttonTable->Click += gcnew System::EventHandler(this, &MainForm::buttonTable_Click);
			// 
			// main_buttonError
			// 
			this->main_buttonError->Location = System::Drawing::Point(25, 460);
			this->main_buttonError->Name = L"main_buttonError";
			this->main_buttonError->Size = System::Drawing::Size(228, 47);
			this->main_buttonError->TabIndex = 10;
			this->main_buttonError->Text = L"Лок. погрешность";
			this->main_buttonError->UseVisualStyleBackColor = true;
			// 
			// main_buttonRef
			// 
			this->main_buttonRef->Location = System::Drawing::Point(25, 354);
			this->main_buttonRef->Name = L"main_buttonRef";
			this->main_buttonRef->Size = System::Drawing::Size(228, 47);
			this->main_buttonRef->TabIndex = 10;
			this->main_buttonRef->Text = L"Справка";
			this->main_buttonRef->UseVisualStyleBackColor = true;
			this->main_buttonRef->Click += gcnew System::EventHandler(this, &MainForm::buttonRef_Click);
			// 
			// main_pictureBoxGraphic
			// 
			this->main_pictureBoxGraphic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->main_pictureBoxGraphic->Location = System::Drawing::Point(285, 177);
			this->main_pictureBoxGraphic->Name = L"main_pictureBoxGraphic";
			this->main_pictureBoxGraphic->Size = System::Drawing::Size(554, 414);
			this->main_pictureBoxGraphic->TabIndex = 9;
			this->main_pictureBoxGraphic->TabStop = false;
			// 
			// main_groupBoxParametrs
			// 
			this->main_groupBoxParametrs->Controls->Add(this->main_labelStep);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelMaxNumSteps);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelLocError);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelH);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelAccurBoard);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelParameters);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelLength);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelL);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelX);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelU0);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelM);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxU0);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelA2);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelA1);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxStep);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxM);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxMaxNumSteps);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxLocError);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxAccurBoard);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxA2);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxLenght);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxA1);
			this->main_groupBoxParametrs->Location = System::Drawing::Point(285, 6);
			this->main_groupBoxParametrs->Name = L"main_groupBoxParametrs";
			this->main_groupBoxParametrs->Size = System::Drawing::Size(554, 156);
			this->main_groupBoxParametrs->TabIndex = 8;
			this->main_groupBoxParametrs->TabStop = false;
			this->main_groupBoxParametrs->Text = L"Параметры задачи";
			// 
			// main_labelStep
			// 
			this->main_labelStep->AutoSize = true;
			this->main_labelStep->Location = System::Drawing::Point(207, 106);
			this->main_labelStep->Name = L"main_labelStep";
			this->main_labelStep->Size = System::Drawing::Size(112, 13);
			this->main_labelStep->TabIndex = 8;
			this->main_labelStep->Text = L"Шаг интегрирования";
			// 
			// main_labelMaxNumSteps
			// 
			this->main_labelMaxNumSteps->AutoSize = true;
			this->main_labelMaxNumSteps->Location = System::Drawing::Point(371, 62);
			this->main_labelMaxNumSteps->Name = L"main_labelMaxNumSteps";
			this->main_labelMaxNumSteps->Size = System::Drawing::Size(150, 13);
			this->main_labelMaxNumSteps->TabIndex = 8;
			this->main_labelMaxNumSteps->Text = L"Максимальное число шагов";
			// 
			// main_labelLocError
			// 
			this->main_labelLocError->AutoSize = true;
			this->main_labelLocError->Location = System::Drawing::Point(207, 62);
			this->main_labelLocError->Name = L"main_labelLocError";
			this->main_labelLocError->Size = System::Drawing::Size(148, 13);
			this->main_labelLocError->TabIndex = 8;
			this->main_labelLocError->Text = L"Контроль лок. погрешности";
			// 
			// main_labelH
			// 
			this->main_labelH->AutoSize = true;
			this->main_labelH->Location = System::Drawing::Point(207, 128);
			this->main_labelH->Name = L"main_labelH";
			this->main_labelH->Size = System::Drawing::Size(22, 13);
			this->main_labelH->TabIndex = 5;
			this->main_labelH->Text = L" h=";
			// 
			// main_labelAccurBoard
			// 
			this->main_labelAccurBoard->AutoSize = true;
			this->main_labelAccurBoard->Location = System::Drawing::Point(371, 20);
			this->main_labelAccurBoard->Name = L"main_labelAccurBoard";
			this->main_labelAccurBoard->Size = System::Drawing::Size(152, 13);
			this->main_labelAccurBoard->TabIndex = 8;
			this->main_labelAccurBoard->Text = L"Точность выхода на границу";
			// 
			// main_labelParameters
			// 
			this->main_labelParameters->AutoSize = true;
			this->main_labelParameters->Location = System::Drawing::Point(39, 20);
			this->main_labelParameters->Name = L"main_labelParameters";
			this->main_labelParameters->Size = System::Drawing::Size(66, 13);
			this->main_labelParameters->TabIndex = 8;
			this->main_labelParameters->Text = L"Параметры";
			// 
			// main_labelLength
			// 
			this->main_labelLength->AutoSize = true;
			this->main_labelLength->Location = System::Drawing::Point(207, 20);
			this->main_labelLength->Name = L"main_labelLength";
			this->main_labelLength->Size = System::Drawing::Size(96, 13);
			this->main_labelLength->TabIndex = 8;
			this->main_labelLength->Text = L"Длина интервала";
			// 
			// main_labelL
			// 
			this->main_labelL->AutoSize = true;
			this->main_labelL->Location = System::Drawing::Point(207, 84);
			this->main_labelL->Name = L"main_labelL";
			this->main_labelL->Size = System::Drawing::Size(22, 13);
			this->main_labelL->TabIndex = 5;
			this->main_labelL->Text = L" L=";
			// 
			// main_labelX
			// 
			this->main_labelX->AutoSize = true;
			this->main_labelX->Location = System::Drawing::Point(207, 41);
			this->main_labelX->Name = L"main_labelX";
			this->main_labelX->Size = System::Drawing::Size(23, 13);
			this->main_labelX->TabIndex = 5;
			this->main_labelX->Text = L" X=";
			// 
			// main_labelU0
			// 
			this->main_labelU0->AutoSize = true;
			this->main_labelU0->Location = System::Drawing::Point(39, 128);
			this->main_labelU0->Name = L"main_labelU0";
			this->main_labelU0->Size = System::Drawing::Size(25, 13);
			this->main_labelU0->TabIndex = 5;
			this->main_labelU0->Text = L"u0=";
			// 
			// main_labelM
			// 
			this->main_labelM->AutoSize = true;
			this->main_labelM->Location = System::Drawing::Point(39, 94);
			this->main_labelM->Name = L"main_labelM";
			this->main_labelM->Size = System::Drawing::Size(24, 13);
			this->main_labelM->TabIndex = 7;
			this->main_labelM->Text = L" m=";
			// 
			// main_textBoxU0
			// 
			this->main_textBoxU0->Location = System::Drawing::Point(67, 125);
			this->main_textBoxU0->Name = L"main_textBoxU0";
			this->main_textBoxU0->Size = System::Drawing::Size(106, 20);
			this->main_textBoxU0->TabIndex = 4;
			// 
			// main_labelA2
			// 
			this->main_labelA2->AutoSize = true;
			this->main_labelA2->Location = System::Drawing::Point(39, 67);
			this->main_labelA2->Name = L"main_labelA2";
			this->main_labelA2->Size = System::Drawing::Size(25, 13);
			this->main_labelA2->TabIndex = 6;
			this->main_labelA2->Text = L"a2=";
			// 
			// main_labelA1
			// 
			this->main_labelA1->AutoSize = true;
			this->main_labelA1->Location = System::Drawing::Point(39, 41);
			this->main_labelA1->Name = L"main_labelA1";
			this->main_labelA1->Size = System::Drawing::Size(25, 13);
			this->main_labelA1->TabIndex = 5;
			this->main_labelA1->Text = L"a1=";
			// 
			// main_textBoxStep
			// 
			this->main_textBoxStep->Location = System::Drawing::Point(231, 125);
			this->main_textBoxStep->Name = L"main_textBoxStep";
			this->main_textBoxStep->Size = System::Drawing::Size(106, 20);
			this->main_textBoxStep->TabIndex = 4;
			// 
			// main_textBoxM
			// 
			this->main_textBoxM->Location = System::Drawing::Point(67, 89);
			this->main_textBoxM->Name = L"main_textBoxM";
			this->main_textBoxM->Size = System::Drawing::Size(106, 20);
			this->main_textBoxM->TabIndex = 4;
			// 
			// main_textBoxMaxNumSteps
			// 
			this->main_textBoxMaxNumSteps->Location = System::Drawing::Point(376, 81);
			this->main_textBoxMaxNumSteps->Name = L"main_textBoxMaxNumSteps";
			this->main_textBoxMaxNumSteps->Size = System::Drawing::Size(106, 20);
			this->main_textBoxMaxNumSteps->TabIndex = 4;
			// 
			// main_textBoxLocError
			// 
			this->main_textBoxLocError->Location = System::Drawing::Point(231, 81);
			this->main_textBoxLocError->Name = L"main_textBoxLocError";
			this->main_textBoxLocError->Size = System::Drawing::Size(106, 20);
			this->main_textBoxLocError->TabIndex = 4;
			// 
			// main_textBoxAccurBoard
			// 
			this->main_textBoxAccurBoard->Location = System::Drawing::Point(376, 37);
			this->main_textBoxAccurBoard->Name = L"main_textBoxAccurBoard";
			this->main_textBoxAccurBoard->Size = System::Drawing::Size(106, 20);
			this->main_textBoxAccurBoard->TabIndex = 4;
			// 
			// main_textBoxA2
			// 
			this->main_textBoxA2->Location = System::Drawing::Point(67, 63);
			this->main_textBoxA2->Name = L"main_textBoxA2";
			this->main_textBoxA2->Size = System::Drawing::Size(106, 20);
			this->main_textBoxA2->TabIndex = 4;
			// 
			// main_textBoxLenght
			// 
			this->main_textBoxLenght->Location = System::Drawing::Point(231, 37);
			this->main_textBoxLenght->Name = L"main_textBoxLenght";
			this->main_textBoxLenght->Size = System::Drawing::Size(106, 20);
			this->main_textBoxLenght->TabIndex = 4;
			this->main_textBoxLenght->Text = L"10";
			// 
			// main_textBoxA1
			// 
			this->main_textBoxA1->Location = System::Drawing::Point(67, 37);
			this->main_textBoxA1->Name = L"main_textBoxA1";
			this->main_textBoxA1->Size = System::Drawing::Size(106, 20);
			this->main_textBoxA1->TabIndex = 9;
			// 
			// main_pictureBoxTask
			// 
			this->main_pictureBoxTask->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"main_pictureBoxTask.BackgroundImage")));
			this->main_pictureBoxTask->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->main_pictureBoxTask->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"main_pictureBoxTask.ErrorImage")));
			this->main_pictureBoxTask->Location = System::Drawing::Point(25, 12);
			this->main_pictureBoxTask->Name = L"main_pictureBoxTask";
			this->main_pictureBoxTask->Size = System::Drawing::Size(228, 150);
			this->main_pictureBoxTask->TabIndex = 2;
			this->main_pictureBoxTask->TabStop = false;
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
			this->testPage->ResumeLayout(false);
			this->test_groupBoxParametrs->ResumeLayout(false);
			this->test_groupBoxParametrs->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_pictureBoxGraphic))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_pictureBoxTask))->EndInit();
			this->mainPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_pictureBoxGraphic))->EndInit();
			this->main_groupBoxParametrs->ResumeLayout(false);
			this->main_groupBoxParametrs->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_pictureBoxTask))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void buttonTable_Click(System::Object^  sender, System::EventArgs^  e) {
		TableForm^ tableForm = gcnew TableForm(MainTask, *(table[tabControl->SelectedIndex]->begin()));
		tableForm->Show();
	}

	private: System::Void main_buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		//call function

		//for every table her own color
		srand(time(NULL));
		int color = rand() % 10;
		pens[tabControl->SelectedIndex]->push_front(color);

		this->main_pictureBoxGraphic->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBoxGraphic_Paint);
		main_pictureBoxGraphic->Refresh();
	}

	private: System::Void test_buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		//call function

		//for every table her own color
		srand(time(NULL));
		int color = rand() % 10;
		pens[tabControl->SelectedIndex]->push_front(color);

		if (a == 0) {
			this->test_pictureBoxGraphic->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBoxGraphic_Paint);
			test_pictureBoxGraphic->Refresh();
			a = 1;
		}
		else if (a==1) {
			SetTable(*t2, 2);
			table[tabControl->SelectedIndex]->push_front(*t2);
			this->test_pictureBoxGraphic->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBoxGraphic_Paint);
			test_pictureBoxGraphic->Refresh();
			a = 2;
		} else if (a == 2) {
			this->test_pictureBoxGraphic->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBoxGraphic_Paint);
			test_pictureBoxGraphic->Refresh();
		}
	}


	private: System::Void test_buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ g = test_pictureBoxGraphic->CreateGraphics();
		g->Clear(Color::White);
	}

	private: System::Void main_buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ g = main_pictureBoxGraphic->CreateGraphics();
		g->Clear(Color::White);
	}


	private: System::Void pictureBoxGraphic_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void buttonRef_Click(System::Object^  sender, System::EventArgs^  e) {
		RefForm^ refForm = gcnew RefForm(0,1,2,3.4);
		refForm->Show();
	}
};
}
