#pragma once
#include <cmath>
#include "Table.h"
#include "Table_for_drawing.h"
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
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:

	public: array<std::list<Table_for_drawing>*>^ table_for_drawing;
	public: array<Table*>^ table;

	private:
		double test_X, main_X, test_U0, main_U0, test_h, main_h, test_eps, main_eps, test_L, main_L,  a1, a2, m;
		int test_maxSteps, main_maxSteps;
		double* maxV, *minV, *maxX;
		int a;

	public:
		MainForm(void)
		{

			test_X = main_X = 10;
			test_h = main_h = 0.001;
			test_U0 = main_U0 = -1;
			test_L = main_L = 0.00001;
			test_maxSteps = main_maxSteps = 1000;
			test_eps = main_eps = 0.01;
			a1 = a2 = m = 1;

			InitializeComponent();

			this->test_textBoxU0->Text = test_U0.ToString();
			this->test_textBoxStep->Text = test_h.ToString();
			this->test_textBoxLocError->Text = test_L.ToString();
			this->test_textBoxAccurBoard->Text = test_eps.ToString();
			this->test_textBoxLenght->Text = test_X.ToString();
			this->main_textBoxStep->Text = main_h.ToString();
			this->main_textBoxM->Text = m.ToString();
			this->main_textBoxA2->Text = a2.ToString();
			this->main_textBoxLocError->Text = main_L.ToString();
			this->main_textBoxA1->Text = a1.ToString();
			this->main_textBoxU0->Text = main_U0.ToString();
			this->main_textBoxMaxNumSteps->Text = main_maxSteps.ToString();
			this->main_textBoxLenght->Text = main_X.ToString();
			this->test_textBoxMaxNumSteps->Text = test_maxSteps.ToString();
			this->main_textBoxAccurBoard->Text = main_eps.ToString();


			table = gcnew array<Table*>(2);
			table[0] = new Table();
			table[1] = new Table();

			SetTable(*(table[MainTask]), 1);
			SetTable(*(table[TestTask]), 1);

			table_for_drawing = gcnew array<std::list<Table_for_drawing>*>(2);	
			table_for_drawing[MainTask] = new std::list<Table_for_drawing>;
			table_for_drawing[TestTask] = new std::list<Table_for_drawing>;

			maxV = new double[2];
			minV = new double[2];
			maxX = new double[2];
			maxX[MainTask] = maxX[TestTask] = maxV[MainTask] = maxV[TestTask] = -10000000;
			minV[MainTask] = minV[TestTask] = 10000000;

			a = 0;
		}

	protected: void SetTable(Table& t, int a) {
		t.Clear();

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
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete table[0];
				delete table[1];

				delete table_for_drawing[0];
				delete table_for_drawing[1];

				delete[] maxX;
				delete[] maxV;
				delete[] minV;

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
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
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
			this->testPage->Text = L"�������� ������";
			this->testPage->UseVisualStyleBackColor = true;
			// 
			// test_buttonSolve
			// 
			this->test_buttonSolve->Location = System::Drawing::Point(25, 209);
			this->test_buttonSolve->Name = L"test_buttonSolve";
			this->test_buttonSolve->Size = System::Drawing::Size(228, 47);
			this->test_buttonSolve->TabIndex = 12;
			this->test_buttonSolve->Text = L"������";
			this->test_buttonSolve->UseVisualStyleBackColor = true;
			this->test_buttonSolve->Click += gcnew System::EventHandler(this, &MainForm::test_buttonSolve_Click);
			// 
			// test_buttonClear
			// 
			this->test_buttonClear->Location = System::Drawing::Point(25, 315);
			this->test_buttonClear->Name = L"test_buttonClear";
			this->test_buttonClear->Size = System::Drawing::Size(228, 47);
			this->test_buttonClear->TabIndex = 13;
			this->test_buttonClear->Text = L"�������� �������";
			this->test_buttonClear->UseVisualStyleBackColor = true;
			this->test_buttonClear->Click += gcnew System::EventHandler(this, &MainForm::test_buttonClear_Click);
			// 
			// test_buttonTable
			// 
			this->test_buttonTable->Location = System::Drawing::Point(25, 451);
			this->test_buttonTable->Name = L"test_buttonTable";
			this->test_buttonTable->Size = System::Drawing::Size(228, 47);
			this->test_buttonTable->TabIndex = 14;
			this->test_buttonTable->Text = L"�������";
			this->test_buttonTable->UseVisualStyleBackColor = true;
			this->test_buttonTable->Click += gcnew System::EventHandler(this, &MainForm::buttonTable_Click);
			// 
			// test_buttonError
			// 
			this->test_buttonError->Location = System::Drawing::Point(25, 504);
			this->test_buttonError->Name = L"test_buttonError";
			this->test_buttonError->Size = System::Drawing::Size(228, 47);
			this->test_buttonError->TabIndex = 15;
			this->test_buttonError->Text = L"���. �����������";
			this->test_buttonError->UseVisualStyleBackColor = true;
			// 
			// test_buttonTrueSolution
			// 
			this->test_buttonTrueSolution->Location = System::Drawing::Point(25, 262);
			this->test_buttonTrueSolution->Name = L"test_buttonTrueSolution";
			this->test_buttonTrueSolution->Size = System::Drawing::Size(228, 47);
			this->test_buttonTrueSolution->TabIndex = 16;
			this->test_buttonTrueSolution->Text = L"�������� �������� �������";
			this->test_buttonTrueSolution->UseVisualStyleBackColor = true;
			this->test_buttonTrueSolution->Click += gcnew System::EventHandler(this, &MainForm::test_buttonTrueSolution_Click);
			// 
			// test_buttonRef
			// 
			this->test_buttonRef->Location = System::Drawing::Point(25, 398);
			this->test_buttonRef->Name = L"test_buttonRef";
			this->test_buttonRef->Size = System::Drawing::Size(228, 47);
			this->test_buttonRef->TabIndex = 16;
			this->test_buttonRef->Text = L"�������";
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
			this->test_groupBoxParametrs->Text = L"��������� ������";
			// 
			// test_labelStep
			// 
			this->test_labelStep->AutoSize = true;
			this->test_labelStep->Location = System::Drawing::Point(37, 84);
			this->test_labelStep->Name = L"test_labelStep";
			this->test_labelStep->Size = System::Drawing::Size(112, 13);
			this->test_labelStep->TabIndex = 8;
			this->test_labelStep->Text = L"��� ��������������";
			// 
			// test_labelMaxNumSteps
			// 
			this->test_labelMaxNumSteps->AutoSize = true;
			this->test_labelMaxNumSteps->Location = System::Drawing::Point(371, 85);
			this->test_labelMaxNumSteps->Name = L"test_labelMaxNumSteps";
			this->test_labelMaxNumSteps->Size = System::Drawing::Size(150, 13);
			this->test_labelMaxNumSteps->TabIndex = 8;
			this->test_labelMaxNumSteps->Text = L"������������ ����� �����";
			// 
			// test_labelLocError
			// 
			this->test_labelLocError->AutoSize = true;
			this->test_labelLocError->Location = System::Drawing::Point(201, 85);
			this->test_labelLocError->Name = L"test_labelLocError";
			this->test_labelLocError->Size = System::Drawing::Size(148, 13);
			this->test_labelLocError->TabIndex = 8;
			this->test_labelLocError->Text = L"�������� ���. �����������";
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
			this->test_labelAccurBoard->Text = L"�������� ������ �� �������";
			// 
			// test_labelParameters
			// 
			this->test_labelParameters->AutoSize = true;
			this->test_labelParameters->Location = System::Drawing::Point(37, 31);
			this->test_labelParameters->Name = L"test_labelParameters";
			this->test_labelParameters->Size = System::Drawing::Size(66, 13);
			this->test_labelParameters->TabIndex = 8;
			this->test_labelParameters->Text = L"���������";
			// 
			// test_labelLenght
			// 
			this->test_labelLenght->AutoSize = true;
			this->test_labelLenght->Location = System::Drawing::Point(201, 32);
			this->test_labelLenght->Name = L"test_labelLenght";
			this->test_labelLenght->Size = System::Drawing::Size(96, 13);
			this->test_labelLenght->TabIndex = 8;
			this->test_labelLenght->Text = L"����� ���������";
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
			this->mainPage->Text = L"�������� ������";
			this->mainPage->UseVisualStyleBackColor = true;
			// 
			// main_buttonSolve
			// 
			this->main_buttonSolve->Location = System::Drawing::Point(25, 209);
			this->main_buttonSolve->Name = L"main_buttonSolve";
			this->main_buttonSolve->Size = System::Drawing::Size(228, 47);
			this->main_buttonSolve->TabIndex = 10;
			this->main_buttonSolve->Text = L"������";
			this->main_buttonSolve->UseVisualStyleBackColor = true;
			this->main_buttonSolve->Click += gcnew System::EventHandler(this, &MainForm::main_buttonSolve_Click);
			// 
			// main_buttonClear
			// 
			this->main_buttonClear->Location = System::Drawing::Point(25, 262);
			this->main_buttonClear->Name = L"main_buttonClear";
			this->main_buttonClear->Size = System::Drawing::Size(228, 47);
			this->main_buttonClear->TabIndex = 10;
			this->main_buttonClear->Text = L"�������� �������";
			this->main_buttonClear->UseVisualStyleBackColor = true;
			this->main_buttonClear->Click += gcnew System::EventHandler(this, &MainForm::main_buttonClear_Click);
			// 
			// main_buttonTable
			// 
			this->main_buttonTable->Location = System::Drawing::Point(25, 407);
			this->main_buttonTable->Name = L"main_buttonTable";
			this->main_buttonTable->Size = System::Drawing::Size(228, 47);
			this->main_buttonTable->TabIndex = 10;
			this->main_buttonTable->Text = L"�������";
			this->main_buttonTable->UseVisualStyleBackColor = true;
			this->main_buttonTable->Click += gcnew System::EventHandler(this, &MainForm::buttonTable_Click);
			// 
			// main_buttonError
			// 
			this->main_buttonError->Location = System::Drawing::Point(25, 460);
			this->main_buttonError->Name = L"main_buttonError";
			this->main_buttonError->Size = System::Drawing::Size(228, 47);
			this->main_buttonError->TabIndex = 10;
			this->main_buttonError->Text = L"���. �����������";
			this->main_buttonError->UseVisualStyleBackColor = true;
			// 
			// main_buttonRef
			// 
			this->main_buttonRef->Location = System::Drawing::Point(25, 354);
			this->main_buttonRef->Name = L"main_buttonRef";
			this->main_buttonRef->Size = System::Drawing::Size(228, 47);
			this->main_buttonRef->TabIndex = 10;
			this->main_buttonRef->Text = L"�������";
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
			this->main_groupBoxParametrs->Text = L"��������� ������";
			// 
			// main_labelStep
			// 
			this->main_labelStep->AutoSize = true;
			this->main_labelStep->Location = System::Drawing::Point(207, 107);
			this->main_labelStep->Name = L"main_labelStep";
			this->main_labelStep->Size = System::Drawing::Size(112, 13);
			this->main_labelStep->TabIndex = 8;
			this->main_labelStep->Text = L"��� ��������������";
			// 
			// main_labelMaxNumSteps
			// 
			this->main_labelMaxNumSteps->AutoSize = true;
			this->main_labelMaxNumSteps->Location = System::Drawing::Point(371, 62);
			this->main_labelMaxNumSteps->Name = L"main_labelMaxNumSteps";
			this->main_labelMaxNumSteps->Size = System::Drawing::Size(150, 13);
			this->main_labelMaxNumSteps->TabIndex = 8;
			this->main_labelMaxNumSteps->Text = L"������������ ����� �����";
			// 
			// main_labelLocError
			// 
			this->main_labelLocError->AutoSize = true;
			this->main_labelLocError->Location = System::Drawing::Point(372, 106);
			this->main_labelLocError->Name = L"main_labelLocError";
			this->main_labelLocError->Size = System::Drawing::Size(148, 13);
			this->main_labelLocError->TabIndex = 8;
			this->main_labelLocError->Text = L"�������� ���. �����������";
			// 
			// main_labelH
			// 
			this->main_labelH->AutoSize = true;
			this->main_labelH->Location = System::Drawing::Point(207, 129);
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
			this->main_labelAccurBoard->Text = L"�������� ������ �� �������";
			// 
			// main_labelParameters
			// 
			this->main_labelParameters->AutoSize = true;
			this->main_labelParameters->Location = System::Drawing::Point(39, 20);
			this->main_labelParameters->Name = L"main_labelParameters";
			this->main_labelParameters->Size = System::Drawing::Size(66, 13);
			this->main_labelParameters->TabIndex = 8;
			this->main_labelParameters->Text = L"���������";
			// 
			// main_labelLength
			// 
			this->main_labelLength->AutoSize = true;
			this->main_labelLength->Location = System::Drawing::Point(207, 65);
			this->main_labelLength->Name = L"main_labelLength";
			this->main_labelLength->Size = System::Drawing::Size(96, 13);
			this->main_labelLength->TabIndex = 8;
			this->main_labelLength->Text = L"����� ���������";
			// 
			// main_labelX
			// 
			this->main_labelX->AutoSize = true;
			this->main_labelX->Location = System::Drawing::Point(207, 86);
			this->main_labelX->Name = L"main_labelX";
			this->main_labelX->Size = System::Drawing::Size(23, 13);
			this->main_labelX->TabIndex = 5;
			this->main_labelX->Text = L" X=";
			// 
			// main_labelU0
			// 
			this->main_labelU0->AutoSize = true;
			this->main_labelU0->Location = System::Drawing::Point(203, 41);
			this->main_labelU0->Name = L"main_labelU0";
			this->main_labelU0->Size = System::Drawing::Size(25, 13);
			this->main_labelU0->TabIndex = 5;
			this->main_labelU0->Text = L"u0=";
			// 
			// main_labelM
			// 
			this->main_labelM->AutoSize = true;
			this->main_labelM->Location = System::Drawing::Point(39, 131);
			this->main_labelM->Name = L"main_labelM";
			this->main_labelM->Size = System::Drawing::Size(24, 13);
			this->main_labelM->TabIndex = 7;
			this->main_labelM->Text = L" m=";
			// 
			// main_textBoxU0
			// 
			this->main_textBoxU0->Location = System::Drawing::Point(231, 38);
			this->main_textBoxU0->Name = L"main_textBoxU0";
			this->main_textBoxU0->Size = System::Drawing::Size(106, 20);
			this->main_textBoxU0->TabIndex = 4;
			// 
			// main_labelA2
			// 
			this->main_labelA2->AutoSize = true;
			this->main_labelA2->Location = System::Drawing::Point(39, 86);
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
			this->main_textBoxStep->Location = System::Drawing::Point(231, 126);
			this->main_textBoxStep->Name = L"main_textBoxStep";
			this->main_textBoxStep->Size = System::Drawing::Size(106, 20);
			this->main_textBoxStep->TabIndex = 4;
			// 
			// main_textBoxM
			// 
			this->main_textBoxM->Location = System::Drawing::Point(67, 126);
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
			this->main_textBoxLocError->Location = System::Drawing::Point(376, 125);
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
			this->main_textBoxA2->Location = System::Drawing::Point(67, 82);
			this->main_textBoxA2->Name = L"main_textBoxA2";
			this->main_textBoxA2->Size = System::Drawing::Size(106, 20);
			this->main_textBoxA2->TabIndex = 4;
			// 
			// main_textBoxLenght
			// 
			this->main_textBoxLenght->Location = System::Drawing::Point(231, 82);
			this->main_textBoxLenght->Name = L"main_textBoxLenght";
			this->main_textBoxLenght->Size = System::Drawing::Size(106, 20);
			this->main_textBoxLenght->TabIndex = 4;
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
			this->Text = L"������ 9, ������� 3";
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
		TableForm^ tableForm = gcnew TableForm(tabControl->SelectedIndex, *(table[tabControl->SelectedIndex]));
		tableForm->Show();
	}

	private: System::Void main_buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!CheckValues()) return;
		//call function

		Table_for_drawing t(*(table[MainTask]));
		table_for_drawing[MainTask]->push_front(t);

		this->main_pictureBoxGraphic->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBoxGraphic_Paint);
		main_pictureBoxGraphic->Refresh();
	}

	private: System::Void test_buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!CheckValues()) return;
		//call function

			Table_for_drawing t(*(table[TestTask]));
			table_for_drawing[TestTask]->push_front(t);

			this->test_pictureBoxGraphic->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBoxGraphic_Paint);
			test_pictureBoxGraphic->Refresh();
	}


	private: System::Void test_buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ g = test_pictureBoxGraphic->CreateGraphics();
		g->Clear(Color::White);
		table_for_drawing[TestTask]->clear();
		maxX[MainTask] = maxX[TestTask] = maxV[MainTask] = maxV[TestTask] = -10000000;
		minV[MainTask] = minV[TestTask] = 10000000;
	}

	private: System::Void main_buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
		Graphics^ g = main_pictureBoxGraphic->CreateGraphics();
		g->Clear(Color::White);
		table_for_drawing[MainTask]->clear();
		maxX[MainTask] = maxX[TestTask] = maxV[MainTask] = maxV[TestTask] = -10000000;
		minV[MainTask] = minV[TestTask] = 10000000;
	}

	private: System::Void test_buttonTrueSolution_Click(System::Object^  sender, System::EventArgs^  e) {
		const int OffsetX = 60;
		const int OffsetY = 40;

		const int Width = test_pictureBoxGraphic->Width - OffsetX;
		const int Height = test_pictureBoxGraphic->Height - OffsetY;

		int d = 5;
		double dx = test_X / Width * d;

		Table_for_drawing t;
		Row_for_drawing r;
		for (int i = 0; i < Width / d; i++) {
			r.x = dx*i;
			r.v = test_U0*exp(r.x);
			t.AddRow(r);
		}
		t.AddColor();
		table_for_drawing[TestTask]->push_front(t);

		test_pictureBoxGraphic->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::pictureBoxGraphic_Paint);
		test_pictureBoxGraphic->Refresh();
	}

	private: System::Void pictureBoxGraphic_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);

	private: System::Void buttonRef_Click(System::Object^  sender, System::EventArgs^  e) {
		RefForm^ refForm = gcnew RefForm(0,1,2,3.4);
		refForm->Show();
	}

	public: bool CheckValues() {
		bool f;
		double d;
		int i;
		if (tabControl->SelectedIndex == TestTask) {

			f = Double::TryParse(test_textBoxStep->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ���� �������������� h ������ ���� ������");
				return false;
			}
			test_h = d;
			f = Double::TryParse(test_textBoxLenght->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ����� ������� �������������� � ������ ���� ������");
				return false;
			}
			test_X = d;
			f = Int32::TryParse(test_textBoxMaxNumSteps->Text, i);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ������������� ���������� ����� ������ ���� ������");
				return false;
			}
			test_maxSteps = i;
			f = Double::TryParse(test_textBoxU0->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ���������� ������� U0 ������ ���� ������");
				return false;
			}
			test_U0 = d;
			f = Double::TryParse(test_textBoxAccurBoard->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ����������� ������ �� ������� ������ ���� ������");
				return false;
			}
			test_eps = d;
			f = Double::TryParse(test_textBoxLocError->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� �������� ��������� ����������� ������ ���� ������ ");
				return false;
			}
			test_L = d;
			if (test_h < 10E-7) {
				MessageBox::Show("�������� ��������: ��� �������������� h �� ����� ���� ������ 10E-7");
				return false;
			}
			if (test_L < 10E-10) {
				MessageBox::Show("�������� ��������: �������� �������� ��������� ����������� �� ����� ���� ������ 10�-10");
				return false;
			}
			if (test_maxSteps > 10E7) {
				MessageBox::Show("�������� ��������: �������� ������������� ���������� ����� �� ����� ���� ������ 10�7");
				return false;
			}
			if (test_eps < 10E-7) {
				MessageBox::Show("�������� ��������: �������� �������� ������ �� ������� �� ����� ���� ������ 10�-7");
				return false;
			}
			if (test_X < 0) {
				MessageBox::Show("�������� ��������: �������� ����� ������� �������������� �� ����� ���� ������������� ������");
				return false;
			}

		}
		if (tabControl->SelectedIndex == MainTask) {

			f = Double::TryParse(main_textBoxA1->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� a1 ������ ���� ������");
				return false;
			}
			a1 = d;
			f = Double::TryParse(main_textBoxA2->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� a2 ������ ���� ������");
				return false;
			}
			a2 = d;
			f = Double::TryParse(main_textBoxM->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� m ������ ���� ������");
				return false;
			}
			m = d;
			f = Double::TryParse(main_textBoxStep->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ���� �������������� h ������ ���� ������");
				return false;
			}
			main_h = d;
			f = Double::TryParse(main_textBoxLenght->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ����� ������� �������������� � ������ ���� ������");
				return false;
			}
			main_X = d;
			f = Int32::TryParse(main_textBoxMaxNumSteps->Text, i);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ������������� ���������� ����� ������ ���� ������");
				return false;
			}
			main_maxSteps = i;
			f = Double::TryParse(main_textBoxU0->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ���������� ������� U0 ������ ���� ������");
				return false;
			}
			main_U0 = d;
			f = Double::TryParse(main_textBoxAccurBoard->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ����������� ������ �� ������� ������ ���� ������");
				return false;
			}
			main_eps = d;
			f = Double::TryParse(main_textBoxLocError->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� �������� ��������� ����������� ������ ���� ������ ");
				return false;
			}
			main_L = d;
			if (main_h < 10E-7){
				MessageBox::Show("�������� ��������: ��� �������������� h �� ����� ���� ������ 10E-7");
				return false;
			}
			if (main_L < 10E-10){
				MessageBox::Show("�������� ��������: �������� �������� ��������� ����������� �� ����� ���� ������ 10�-10");
				return false;
			}
			if (main_maxSteps > 10E7) {
				MessageBox::Show("�������� ��������: �������� ������������� ���������� ����� �� ����� ���� ������ 10�7");
				return false;
			}
			if (main_eps < 10E-7) {
				MessageBox::Show("�������� ��������: �������� �������� ������ �� ������� �� ����� ���� ������ 10�-7");
				return false;
			}
			if (main_X < 0) {
				MessageBox::Show("�������� ��������: �������� ����� ������� �������������� �� ����� ���� ������������� ������");
				return false;
			}
			if (a1 <= 0) {
				MessageBox::Show("�������� ��������: �������� a1 �� ����� ���� ��������������� ������");
				return false;
			}
			if (a2 <= 0) {
				MessageBox::Show("�������� ��������: �������� a2 �� ����� ���� ��������������� ������");
				return false;
			}
			if (m <= 0) {
				MessageBox::Show("�������� ��������: �������� m �� ����� ���� ��������������� ������");
				return false;
			}
		}
		return false;

	}
};
}
