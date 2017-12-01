#pragma once
#include <cmath>
#include "Table.h"
#include "TableForm.h"
#include "RefForm.h"
#include "ErrorForm.h"
#include "schet.h"

namespace CHM9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const double PI = 3.14159265358979323846264;

	/// <summary>
	/// ������ ��� MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public: Table* table;
			bool flag;

	private:
		double test_X, main_X, test_U0, main_U0, test_h, main_h, test_eps, main_eps, test_L, main_L;
		int test_maxSteps, main_maxSteps;
		double *maxX, *minX;


	private: int test_NSeries, main_NSeries;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ComboBox^  test_comboBoxU0;
	private: System::Windows::Forms::TextBox^  main_textBoxX;
	private: System::Windows::Forms::ComboBox^  main_comboBoxU0;

	public:
		MainForm(void)
		{
			test_X = 1;
			main_X = 1.105;
			test_h = main_h = 0.0001;
			test_U0 = 1; 
			main_U0 = 0.5;
			test_L = main_L = 0.00001;
			test_maxSteps = main_maxSteps = 1000;
			test_eps = main_eps = 0.01;

			InitializeComponent();

			this->main_comboBoxMethod->SelectedIndex = 0;
			this->test_comboBoxMethod->SelectedIndex = 0;
			this->test_comboBoxU0->Text = test_U0.ToString();
			this->test_textBoxStep->Text = test_h.ToString();
			this->test_textBoxLocError->Text = test_L.ToString();
			this->test_textBoxAccurBoard->Text = test_eps.ToString();
			this->main_textBoxStep->Text = main_h.ToString();
			this->main_textBoxLocError->Text = main_L.ToString();
			this->main_textBoxMaxNumSteps->Text = main_maxSteps.ToString();
			this->main_textBoxX->Text = main_X.ToString();
			this->test_textBoxMaxNumSteps->Text = test_maxSteps.ToString();
			this->main_textBoxAccurBoard->Text = main_eps.ToString();
			this->test_comboBoxU0->SelectedIndex = 0;
			this->main_comboBoxU0->SelectedIndex = 1;

			main_NSeries =test_NSeries= 0;

			flag = false;
			table = 0;

			maxX = new double[2];
			minX = new double[2];
			maxX[MainTask] = main_X;
			maxX[TestTask] = 1;
			minX[MainTask] = minX[TestTask] = 0;
		}

	protected: void SetTable(Table& t) {
		t.Clear();

		Row row;

		row.i = 0;
		row.xi = 0;
		row.viItog = 1;
		row.s = 0;
		row.hi_1 = 0;
		row.stepDec = row.stepInc = 0;
		t.AddRow(row);

		row.i = 1;
		row.xi = 3;
		row.viItog = 17;
		row.s = -1E-10;
		row.hi_1 = 3;
		row.stepDec = 0;
		row.stepInc = 1;
		t.AddRow(row);

		row.i = 2;
		row.xi = 5;
		row.viItog = 12;
		row.s = 7E-10;
		row.hi_1 = 2;
		row.stepDec = 1;
		row.stepInc = 0;
		t.AddRow(row);

		row.i = 3;
		row.xi = 10;
		row.viItog = 15;
		row.s = 8E-10;
		row.hi_1 = 5;
		row.stepDec = 0;
		row.stepInc = 1;
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

				delete[] maxX;
				delete[] minX;

				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::ComboBox^  test_comboBoxMethod;
	private: System::Windows::Forms::ComboBox^  main_comboBoxMethod;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  test_chart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  main_chart;
	private: System::Windows::Forms::TabControl^  tabControl;
	private: System::Windows::Forms::TabPage^  testPage;
	private: System::Windows::Forms::TabPage^  mainPage;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  main_pictureBoxTask;

	private: System::Windows::Forms::GroupBox^  main_groupBoxParametrs;



	private: System::Windows::Forms::Label^  main_labelU0;
	private: System::Windows::Forms::Label^  main_labelX;
	private: System::Windows::Forms::Label^  main_labelLength;
	private: System::Windows::Forms::Label^  main_labelStep;
	private: System::Windows::Forms::Label^  main_labelMaxNumSteps;
	private: System::Windows::Forms::Label^  main_labelLocError;
	private: System::Windows::Forms::Label^  main_labelH;
	private: System::Windows::Forms::Label^  main_labelAccurBoard;

	private: System::Windows::Forms::Label^  main_labelParameters;




	private: System::Windows::Forms::TextBox^  main_textBoxStep;
	private: System::Windows::Forms::TextBox^  main_textBoxMaxNumSteps;
	private: System::Windows::Forms::TextBox^  main_textBoxLocError;
	private: System::Windows::Forms::TextBox^  main_textBoxAccurBoard;

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

	private: System::Windows::Forms::TextBox^  test_textBoxStep;
	private: System::Windows::Forms::TextBox^  test_textBoxMaxNumSteps;
	private: System::Windows::Forms::TextBox^  test_textBoxLocError;
	private: System::Windows::Forms::TextBox^  test_textBoxAccurBoard;


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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->testPage = (gcnew System::Windows::Forms::TabPage());
			this->test_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->test_buttonSolve = (gcnew System::Windows::Forms::Button());
			this->test_buttonClear = (gcnew System::Windows::Forms::Button());
			this->test_buttonTable = (gcnew System::Windows::Forms::Button());
			this->test_buttonError = (gcnew System::Windows::Forms::Button());
			this->test_buttonTrueSolution = (gcnew System::Windows::Forms::Button());
			this->test_buttonRef = (gcnew System::Windows::Forms::Button());
			this->test_groupBoxParametrs = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->test_comboBoxU0 = (gcnew System::Windows::Forms::ComboBox());
			this->test_comboBoxMethod = (gcnew System::Windows::Forms::ComboBox());
			this->test_labelStep = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->test_labelMaxNumSteps = (gcnew System::Windows::Forms::Label());
			this->test_labelLocError = (gcnew System::Windows::Forms::Label());
			this->test_labelH = (gcnew System::Windows::Forms::Label());
			this->test_labelAccurBoard = (gcnew System::Windows::Forms::Label());
			this->test_labelParameters = (gcnew System::Windows::Forms::Label());
			this->test_labelLenght = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->test_labelX = (gcnew System::Windows::Forms::Label());
			this->test_labelU0 = (gcnew System::Windows::Forms::Label());
			this->test_textBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxMaxNumSteps = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxLocError = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxAccurBoard = (gcnew System::Windows::Forms::TextBox());
			this->test_pictureBoxTask = (gcnew System::Windows::Forms::PictureBox());
			this->mainPage = (gcnew System::Windows::Forms::TabPage());
			this->main_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->main_buttonSolve = (gcnew System::Windows::Forms::Button());
			this->main_buttonClear = (gcnew System::Windows::Forms::Button());
			this->main_buttonTable = (gcnew System::Windows::Forms::Button());
			this->main_buttonError = (gcnew System::Windows::Forms::Button());
			this->main_buttonRef = (gcnew System::Windows::Forms::Button());
			this->main_groupBoxParametrs = (gcnew System::Windows::Forms::GroupBox());
			this->main_comboBoxU0 = (gcnew System::Windows::Forms::ComboBox());
			this->main_comboBoxMethod = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->main_labelStep = (gcnew System::Windows::Forms::Label());
			this->main_labelMaxNumSteps = (gcnew System::Windows::Forms::Label());
			this->main_labelLocError = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->main_labelH = (gcnew System::Windows::Forms::Label());
			this->main_labelAccurBoard = (gcnew System::Windows::Forms::Label());
			this->main_labelParameters = (gcnew System::Windows::Forms::Label());
			this->main_labelLength = (gcnew System::Windows::Forms::Label());
			this->main_labelX = (gcnew System::Windows::Forms::Label());
			this->main_labelU0 = (gcnew System::Windows::Forms::Label());
			this->main_textBoxStep = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxMaxNumSteps = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxLocError = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxAccurBoard = (gcnew System::Windows::Forms::TextBox());
			this->main_pictureBoxTask = (gcnew System::Windows::Forms::PictureBox());
			this->main_textBoxX = (gcnew System::Windows::Forms::TextBox());
			this->tabControl->SuspendLayout();
			this->testPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_chart))->BeginInit();
			this->test_groupBoxParametrs->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_pictureBoxTask))->BeginInit();
			this->mainPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_chart))->BeginInit();
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
			this->testPage->Controls->Add(this->test_chart);
			this->testPage->Controls->Add(this->test_buttonSolve);
			this->testPage->Controls->Add(this->test_buttonClear);
			this->testPage->Controls->Add(this->test_buttonTable);
			this->testPage->Controls->Add(this->test_buttonError);
			this->testPage->Controls->Add(this->test_buttonTrueSolution);
			this->testPage->Controls->Add(this->test_buttonRef);
			this->testPage->Controls->Add(this->test_groupBoxParametrs);
			this->testPage->Controls->Add(this->test_pictureBoxTask);
			this->testPage->Location = System::Drawing::Point(4, 22);
			this->testPage->Name = L"testPage";
			this->testPage->Padding = System::Windows::Forms::Padding(3);
			this->testPage->Size = System::Drawing::Size(860, 617);
			this->testPage->TabIndex = 0;
			this->testPage->Text = L"�������� ������";
			this->testPage->UseVisualStyleBackColor = true;
			// 
			// test_chart
			// 
			this->test_chart->BorderlineColor = System::Drawing::Color::Black;
			this->test_chart->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea1->Name = L"ChartArea1";
			this->test_chart->ChartAreas->Add(chartArea1);
			this->test_chart->Location = System::Drawing::Point(285, 180);
			this->test_chart->Name = L"test_chart";
			this->test_chart->Size = System::Drawing::Size(554, 420);
			this->test_chart->TabIndex = 17;
			this->test_chart->Text = L"test_chart";
			// 
			// test_buttonSolve
			// 
			this->test_buttonSolve->Location = System::Drawing::Point(25, 223);
			this->test_buttonSolve->Name = L"test_buttonSolve";
			this->test_buttonSolve->Size = System::Drawing::Size(228, 47);
			this->test_buttonSolve->TabIndex = 12;
			this->test_buttonSolve->Text = L"������";
			this->test_buttonSolve->UseVisualStyleBackColor = true;
			this->test_buttonSolve->Click += gcnew System::EventHandler(this, &MainForm::test_buttonSolve_Click);
			// 
			// test_buttonClear
			// 
			this->test_buttonClear->Location = System::Drawing::Point(25, 329);
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
			this->test_buttonError->Click += gcnew System::EventHandler(this, &MainForm::buttonError_Click);
			// 
			// test_buttonTrueSolution
			// 
			this->test_buttonTrueSolution->Location = System::Drawing::Point(25, 276);
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
			this->test_groupBoxParametrs->Controls->Add(this->label5);
			this->test_groupBoxParametrs->Controls->Add(this->test_comboBoxU0);
			this->test_groupBoxParametrs->Controls->Add(this->test_comboBoxMethod);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelStep);
			this->test_groupBoxParametrs->Controls->Add(this->label1);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelMaxNumSteps);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelLocError);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelH);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelAccurBoard);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelParameters);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelLenght);
			this->test_groupBoxParametrs->Controls->Add(this->label3);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelX);
			this->test_groupBoxParametrs->Controls->Add(this->test_labelU0);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxStep);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxMaxNumSteps);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxLocError);
			this->test_groupBoxParametrs->Controls->Add(this->test_textBoxAccurBoard);
			this->test_groupBoxParametrs->Location = System::Drawing::Point(285, 6);
			this->test_groupBoxParametrs->Name = L"test_groupBoxParametrs";
			this->test_groupBoxParametrs->Size = System::Drawing::Size(554, 156);
			this->test_groupBoxParametrs->TabIndex = 11;
			this->test_groupBoxParametrs->TabStop = false;
			this->test_groupBoxParametrs->Text = L"��������� ������";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(223, 53);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 19;
			// 
			// test_comboBoxU0
			// 
			this->test_comboBoxU0->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"1", L"0", L"-1" });
			this->test_comboBoxU0->Location = System::Drawing::Point(61, 47);
			this->test_comboBoxU0->Name = L"test_comboBoxU0";
			this->test_comboBoxU0->Size = System::Drawing::Size(106, 21);
			this->test_comboBoxU0->TabIndex = 18;
			this->test_comboBoxU0->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::test_comboBoxU0_SelectedIndexChanged);
			// 
			// test_comboBoxMethod
			// 
			this->test_comboBoxMethod->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->test_comboBoxMethod->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"�����-����� 4 �������" });
			this->test_comboBoxMethod->Location = System::Drawing::Point(376, 124);
			this->test_comboBoxMethod->Name = L"test_comboBoxMethod";
			this->test_comboBoxMethod->Size = System::Drawing::Size(162, 21);
			this->test_comboBoxMethod->TabIndex = 17;
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
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(372, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 13);
			this->label1->TabIndex = 8;
			this->label1->Text = L"�����";
			// 
			// test_labelMaxNumSteps
			// 
			this->test_labelMaxNumSteps->AutoSize = true;
			this->test_labelMaxNumSteps->Location = System::Drawing::Point(371, 62);
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
			this->test_labelAccurBoard->Location = System::Drawing::Point(371, 19);
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
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(201, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(22, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L" e=";
			// 
			// test_labelX
			// 
			this->test_labelX->AutoSize = true;
			this->test_labelX->Location = System::Drawing::Point(201, 53);
			this->test_labelX->Name = L"test_labelX";
			this->test_labelX->Size = System::Drawing::Size(29, 13);
			this->test_labelX->TabIndex = 5;
			this->test_labelX->Text = L" X=1";
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
			// test_textBoxStep
			// 
			this->test_textBoxStep->Location = System::Drawing::Point(61, 103);
			this->test_textBoxStep->Name = L"test_textBoxStep";
			this->test_textBoxStep->Size = System::Drawing::Size(106, 20);
			this->test_textBoxStep->TabIndex = 4;
			// 
			// test_textBoxMaxNumSteps
			// 
			this->test_textBoxMaxNumSteps->Location = System::Drawing::Point(376, 81);
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
			this->test_textBoxAccurBoard->Location = System::Drawing::Point(376, 36);
			this->test_textBoxAccurBoard->Name = L"test_textBoxAccurBoard";
			this->test_textBoxAccurBoard->Size = System::Drawing::Size(106, 20);
			this->test_textBoxAccurBoard->TabIndex = 4;
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
			this->mainPage->Controls->Add(this->main_chart);
			this->mainPage->Controls->Add(this->main_buttonSolve);
			this->mainPage->Controls->Add(this->main_buttonClear);
			this->mainPage->Controls->Add(this->main_buttonTable);
			this->mainPage->Controls->Add(this->main_buttonError);
			this->mainPage->Controls->Add(this->main_buttonRef);
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
			// main_chart
			// 
			this->main_chart->BorderlineColor = System::Drawing::Color::Black;
			this->main_chart->BorderlineDashStyle = System::Windows::Forms::DataVisualization::Charting::ChartDashStyle::Solid;
			chartArea2->AxisX->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea2->AxisY->MajorGrid->LineColor = System::Drawing::Color::LightGray;
			chartArea2->Name = L"ChartArea1";
			this->main_chart->ChartAreas->Add(chartArea2);
			this->main_chart->Location = System::Drawing::Point(285, 180);
			this->main_chart->Name = L"main_chart";
			this->main_chart->Size = System::Drawing::Size(554, 420);
			this->main_chart->TabIndex = 11;
			this->main_chart->Text = L"main_chart";
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
			this->main_buttonError->Click += gcnew System::EventHandler(this, &MainForm::buttonError_Click);
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
			// main_groupBoxParametrs
			// 
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxX);
			this->main_groupBoxParametrs->Controls->Add(this->main_comboBoxU0);
			this->main_groupBoxParametrs->Controls->Add(this->main_comboBoxMethod);
			this->main_groupBoxParametrs->Controls->Add(this->label2);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelStep);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelMaxNumSteps);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelLocError);
			this->main_groupBoxParametrs->Controls->Add(this->label4);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelH);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelAccurBoard);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelParameters);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelLength);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelX);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelU0);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxStep);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxMaxNumSteps);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxLocError);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxAccurBoard);
			this->main_groupBoxParametrs->Location = System::Drawing::Point(285, 6);
			this->main_groupBoxParametrs->Name = L"main_groupBoxParametrs";
			this->main_groupBoxParametrs->Size = System::Drawing::Size(554, 156);
			this->main_groupBoxParametrs->TabIndex = 8;
			this->main_groupBoxParametrs->TabStop = false;
			this->main_groupBoxParametrs->Text = L"��������� ������";
			// 
			// main_comboBoxU0
			// 
			this->main_comboBoxU0->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0", L"0,5", L"1", L"2", L"3" });
			this->main_comboBoxU0->Location = System::Drawing::Point(66, 55);
			this->main_comboBoxU0->Name = L"main_comboBoxU0";
			this->main_comboBoxU0->Size = System::Drawing::Size(106, 21);
			this->main_comboBoxU0->TabIndex = 20;
			this->main_comboBoxU0->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::main_comboBoxU0_SelectedIndexChanged);
			// 
			// main_comboBoxMethod
			// 
			this->main_comboBoxMethod->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->main_comboBoxMethod->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"�����-����� 4 �������" });
			this->main_comboBoxMethod->Location = System::Drawing::Point(376, 121);
			this->main_comboBoxMethod->Name = L"main_comboBoxMethod";
			this->main_comboBoxMethod->Size = System::Drawing::Size(162, 21);
			this->main_comboBoxMethod->TabIndex = 19;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(372, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(39, 13);
			this->label2->TabIndex = 18;
			this->label2->Text = L"�����";
			// 
			// main_labelStep
			// 
			this->main_labelStep->AutoSize = true;
			this->main_labelStep->Location = System::Drawing::Point(42, 92);
			this->main_labelStep->Name = L"main_labelStep";
			this->main_labelStep->Size = System::Drawing::Size(112, 13);
			this->main_labelStep->TabIndex = 8;
			this->main_labelStep->Text = L"��� ��������������";
			// 
			// main_labelMaxNumSteps
			// 
			this->main_labelMaxNumSteps->AutoSize = true;
			this->main_labelMaxNumSteps->Location = System::Drawing::Point(371, 18);
			this->main_labelMaxNumSteps->Name = L"main_labelMaxNumSteps";
			this->main_labelMaxNumSteps->Size = System::Drawing::Size(150, 13);
			this->main_labelMaxNumSteps->TabIndex = 8;
			this->main_labelMaxNumSteps->Text = L"������������ ����� �����";
			// 
			// main_labelLocError
			// 
			this->main_labelLocError->AutoSize = true;
			this->main_labelLocError->Location = System::Drawing::Point(372, 62);
			this->main_labelLocError->Name = L"main_labelLocError";
			this->main_labelLocError->Size = System::Drawing::Size(148, 13);
			this->main_labelLocError->TabIndex = 8;
			this->main_labelLocError->Text = L"�������� ���. �����������";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(203, 114);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(22, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L" e=";
			// 
			// main_labelH
			// 
			this->main_labelH->AutoSize = true;
			this->main_labelH->Location = System::Drawing::Point(42, 114);
			this->main_labelH->Name = L"main_labelH";
			this->main_labelH->Size = System::Drawing::Size(22, 13);
			this->main_labelH->TabIndex = 5;
			this->main_labelH->Text = L" h=";
			// 
			// main_labelAccurBoard
			// 
			this->main_labelAccurBoard->AutoSize = true;
			this->main_labelAccurBoard->Location = System::Drawing::Point(203, 94);
			this->main_labelAccurBoard->Name = L"main_labelAccurBoard";
			this->main_labelAccurBoard->Size = System::Drawing::Size(152, 13);
			this->main_labelAccurBoard->TabIndex = 8;
			this->main_labelAccurBoard->Text = L"�������� ������ �� �������";
			// 
			// main_labelParameters
			// 
			this->main_labelParameters->AutoSize = true;
			this->main_labelParameters->Location = System::Drawing::Point(41, 35);
			this->main_labelParameters->Name = L"main_labelParameters";
			this->main_labelParameters->Size = System::Drawing::Size(66, 13);
			this->main_labelParameters->TabIndex = 8;
			this->main_labelParameters->Text = L"���������";
			// 
			// main_labelLength
			// 
			this->main_labelLength->AutoSize = true;
			this->main_labelLength->Location = System::Drawing::Point(203, 35);
			this->main_labelLength->Name = L"main_labelLength";
			this->main_labelLength->Size = System::Drawing::Size(96, 13);
			this->main_labelLength->TabIndex = 8;
			this->main_labelLength->Text = L"����� ���������";
			// 
			// main_labelX
			// 
			this->main_labelX->AutoSize = true;
			this->main_labelX->Location = System::Drawing::Point(203, 58);
			this->main_labelX->Name = L"main_labelX";
			this->main_labelX->Size = System::Drawing::Size(23, 13);
			this->main_labelX->TabIndex = 5;
			this->main_labelX->Text = L" X=";
			// 
			// main_labelU0
			// 
			this->main_labelU0->AutoSize = true;
			this->main_labelU0->Location = System::Drawing::Point(42, 58);
			this->main_labelU0->Name = L"main_labelU0";
			this->main_labelU0->Size = System::Drawing::Size(25, 13);
			this->main_labelU0->TabIndex = 5;
			this->main_labelU0->Text = L"u0=";
			// 
			// main_textBoxStep
			// 
			this->main_textBoxStep->Location = System::Drawing::Point(66, 111);
			this->main_textBoxStep->Name = L"main_textBoxStep";
			this->main_textBoxStep->Size = System::Drawing::Size(106, 20);
			this->main_textBoxStep->TabIndex = 4;
			// 
			// main_textBoxMaxNumSteps
			// 
			this->main_textBoxMaxNumSteps->Location = System::Drawing::Point(376, 37);
			this->main_textBoxMaxNumSteps->Name = L"main_textBoxMaxNumSteps";
			this->main_textBoxMaxNumSteps->Size = System::Drawing::Size(106, 20);
			this->main_textBoxMaxNumSteps->TabIndex = 4;
			// 
			// main_textBoxLocError
			// 
			this->main_textBoxLocError->Location = System::Drawing::Point(376, 81);
			this->main_textBoxLocError->Name = L"main_textBoxLocError";
			this->main_textBoxLocError->Size = System::Drawing::Size(106, 20);
			this->main_textBoxLocError->TabIndex = 4;
			// 
			// main_textBoxAccurBoard
			// 
			this->main_textBoxAccurBoard->Location = System::Drawing::Point(226, 111);
			this->main_textBoxAccurBoard->Name = L"main_textBoxAccurBoard";
			this->main_textBoxAccurBoard->Size = System::Drawing::Size(106, 20);
			this->main_textBoxAccurBoard->TabIndex = 4;
			// 
			// main_pictureBoxTask
			// 
			this->main_pictureBoxTask->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"main_pictureBoxTask.BackgroundImage")));
			this->main_pictureBoxTask->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->main_pictureBoxTask->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->main_pictureBoxTask->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"main_pictureBoxTask.ErrorImage")));
			this->main_pictureBoxTask->Location = System::Drawing::Point(25, 12);
			this->main_pictureBoxTask->Name = L"main_pictureBoxTask";
			this->main_pictureBoxTask->Size = System::Drawing::Size(228, 150);
			this->main_pictureBoxTask->TabIndex = 2;
			this->main_pictureBoxTask->TabStop = false;
			// 
			// main_textBoxX
			// 
			this->main_textBoxX->Location = System::Drawing::Point(226, 56);
			this->main_textBoxX->Name = L"main_textBoxX";
			this->main_textBoxX->Size = System::Drawing::Size(106, 20);
			this->main_textBoxX->TabIndex = 21;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(863, 636);
			this->Controls->Add(this->tabControl);
			this->Name = L"MainForm";
			this->Text = L"������������ ������ 1, ������� 3";
			this->tabControl->ResumeLayout(false);
			this->testPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_chart))->EndInit();
			this->test_groupBoxParametrs->ResumeLayout(false);
			this->test_groupBoxParametrs->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_pictureBoxTask))->EndInit();
			this->mainPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_chart))->EndInit();
			this->main_groupBoxParametrs->ResumeLayout(false);
			this->main_groupBoxParametrs->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_pictureBoxTask))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void buttonTable_Click(System::Object^  sender, System::EventArgs^  e) {
		if (flag==false) {//������ �� NULL
			MessageBox::Show("���� ��� �� ������ �������");
			return;
		}
		const char* str = (tabControl->SelectedIndex == TestTask) ? "./test.txt" : "./main.txt";
		TableForm^ tableForm = gcnew TableForm(tabControl->SelectedIndex, str);
		tableForm->Show();
	}

	private: System::Void main_buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!CheckValues()) return;
		//����
		/*if (table[tabControl->SelectedIndex] == NULL) {//������ �� NULL
			MessageBox::Show("�� ����������� �������");
			return;
		}*/
		flag = true;

		table = new Table();
		Integrate(arrMethod[main_comboBoxMethod->SelectedIndex], Mainf, 0, main_X, main_U0, main_maxSteps, main_h, main_L, main_eps, table, 4);
		maxX[MainTask] = main_X;
		//minX[MainTask] = 0;

		//for (auto it = table->begin(); it != table->end(); it++) {
		//	if (it->xi > maxX[MainTask]) maxX[MainTask] = it->xi;
		//}

		const int n = (--table->end())->i + 1;
		array<double^>^ x = gcnew array<double^>(n);
		array<double^>^ y = gcnew array<double^>(n);
		int i = 0;
		for (auto it = table->begin(); it != table->end(); it++, i++) {
			x[i] = gcnew double;
			y[i] = gcnew double;
			x[i] = it->xi;
			y[i] = it->viItog;
		}

		Show(MainTask, x, y, minX[MainTask], maxX[MainTask]);

		std::ofstream f; 
		f.open("./main.txt");
		f << (*table);
		f.close();

		delete table;
		table = 0;
	}
	private: System::Void test_buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!CheckValues()) return;
		//����
		/*if (table[tabControl->SelectedIndex] == NULL) {//������ �� NULL
			MessageBox::Show("�� ����������� �������");
			return;
		}*/
		flag = true;

		table = new Table();
		Integrate(arrMethod[test_comboBoxMethod->SelectedIndex],Testf, 0, test_X, test_U0, test_maxSteps, test_h, test_L, test_eps, table, 4);

		//minX[TestTask] = 0;
		//for (auto it = table->begin(); it != table->end(); it++) {
		//	if (it->xi > maxX[TestTask]) maxX[TestTask] = it->xi;
		//}

		const int n = (--table->end())->i + 1;
		array<double^>^ x = gcnew array<double^>(n);
		array<double^>^ y = gcnew array<double^>(n);
		int i = 0;
		for (auto it = table->begin(); it != table->end(); it++, i++) {
			x[i] = gcnew double;
			y[i] = gcnew double;
			x[i] = it->xi;
			y[i] = it->viItog;
		}

		Show(TestTask, x,y, minX[TestTask], maxX[TestTask]);

		std::ofstream f;
		f.open("./test.txt");
		f << (*table);
		f.close();
		
		delete table;
		table = 0;
	}

	private: System::Void Show(int task, array<double^>^ x, array<double^>^ y, double _minX, double _maxX) {
		DataVisualization::Charting::Chart^ chart = (task == MainTask) ? main_chart : test_chart;
		DataVisualization::Charting::Series^ s = gcnew DataVisualization::Charting::Series;
		chart->Series->Add(s);

		s->BorderWidth = 2;

		s->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;

		chart->ChartAreas[0]->AxisX->LineWidth = 1;
		chart->ChartAreas[0]->AxisY->LineWidth = 1;

		chart->ChartAreas[0]->AxisX->Minimum = _minX;
		chart->ChartAreas[0]->AxisX->Maximum = _maxX;

		const int H = 20;//��� ��������
		chart->ChartAreas[0]->AxisX->MajorGrid->Interval = H*(_maxX - _minX) / chart->Width;

		interior_ptr<int> NSeries = (tabControl->SelectedIndex == TestTask) ? (&test_NSeries) : (&main_NSeries);
		chart->Series[*NSeries]->Points->DataBindXY(x, y);
		(*NSeries)++;
	}



	private: System::Void buttonError_Click(System::Object^  sender, System::EventArgs^  e) {
		if (flag == false) {//������ �� NULL
			MessageBox::Show("���� ��� �� ������ �������");
			return;
		}
		const char* str = (tabControl->SelectedIndex == TestTask) ? "./test.txt" : "./main.txt";
		double _X = tabControl->SelectedIndex == MainTask ? main_X : test_X;
		ErrorForm^ errorForm = gcnew ErrorForm(_X,str);
		errorForm->Show();
	}

	private: System::Void test_buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < test_NSeries; i++) test_chart->Series[i]->Points->Clear();
		test_NSeries = 0;
	}
	private: System::Void main_buttonClear_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < main_NSeries; i++) main_chart->Series[i]->Points->Clear();
		main_NSeries = 0;
	}

	private: System::Void test_buttonTrueSolution_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!CheckValues()) return;

		//minX[TestTask] = 0;
		//if (test_X > maxX[TestTask]) maxX[TestTask] = test_X;
		
		const int d = 2;
		const int n = test_chart->Width / d;
		const double dx = test_X / n;
	
		array<double^>^ x = gcnew array<double^>(n);
		array<double^>^ y = gcnew array<double^>(n);

		for (int i=0; i<n; i++) {
			x[i] = gcnew double;
			y[i] = gcnew double;
			x[i] = dx*i;
			y[i] = test_U0*exp(-3*(*(x[i])));
		}

		Show(TestTask, x,y,minX[TestTask], maxX[TestTask]);
	}

	private: System::Void buttonRef_Click(System::Object^  sender, System::EventArgs^  e) {
		if (flag==false) {//������ �� NULL
			MessageBox::Show("���� ��� �� ������ �������");
			return;
		}
		const char* str = (tabControl->SelectedIndex == TestTask) ? "./test.txt" : "./main.txt";
		int t = tabControl->SelectedIndex;
		double _X = (t == MainTask) ? main_X : test_X;
		double maxL= (t == MainTask) ? main_L : test_L;
		int N = (t == MainTask) ? main_maxSteps : test_maxSteps;
		double eps = (t == MainTask) ? main_eps : test_eps;
		double h0 = (t == MainTask) ? main_h : test_h;
		int p = 4;
		RefForm^ refForm = gcnew RefForm(str, t, _X, maxL, eps,N,p,h0);
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
			f = Int32::TryParse(test_textBoxMaxNumSteps->Text, i);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ������������� ���������� ����� ������ ���� ������");
				return false;
			}
			test_maxSteps = i;
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

			if (test_h < 10E-10) {
				MessageBox::Show("�������� ��������: ��� �������������� h �� ����� ���� ������ 10E-10");
				return false;
			}
			if (test_eps < 10E-7) {
				MessageBox::Show("�������� ��������: �������� �������� ������ �� ������� �� ����� ���� ������ 10�-7");
				return false;
			}
			return true;
		}
		if (tabControl->SelectedIndex == MainTask) {

			f = Double::TryParse(main_textBoxStep->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ���� �������������� h ������ ���� ������");
				return false;
			}
			main_h = d;
			f = Double::TryParse(main_textBoxX->Text, d);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ������� �������������� X ������ ���� ������");
				return false;
			}
			main_X = d;
			f = Int32::TryParse(main_textBoxMaxNumSteps->Text, i);
			if (!f) {
				MessageBox::Show("�������� ��������: �������� ������������� ���������� ����� ������ ���� ������");
				return false;
			}
			main_maxSteps = i;
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
			if (main_maxSteps > 10E7) {
				MessageBox::Show("�������� ��������: �������� ������������� ���������� ����� �� ����� ���� ������ 10�7");
				return false;
			}
			if (main_eps < 10E-7) {
				MessageBox::Show("�������� ��������: �������� �������� ������ �� ������� �� ����� ���� ������ 10�-7");
				return false;
			}
			return true;
		}
		return false;

	}
	
private: System::Void test_comboBoxU0_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	test_U0 = Double::Parse(test_comboBoxU0->Items[test_comboBoxU0->SelectedIndex]->ToString());
}
private: System::Void main_comboBoxU0_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	main_U0 = Double::Parse(main_comboBoxU0->Items[main_comboBoxU0->SelectedIndex]->ToString());
}
};
}
