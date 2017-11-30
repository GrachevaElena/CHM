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

	double test_ksi = 0.5, test_nu1=0, test_nu2=1;
	auto test_k = [](double x) { return (double) 1; };
	auto test_q = [](double x) { return (double) 1; };
	auto test_f = [](double x) { return (double)(x*x-2); };

	double main_ksi = 0.5, main_nu1 = 0, main_nu2 = 1;
	auto main_k = [](double x) { return (double)(x<main_ksi?(x*x+2):(x*x)); };
	auto main_q = [](double x) { return (double)(x<main_ksi ? (x) : (x*x)); };
	auto main_f = [](double x) { return (double)(x<main_ksi ? (x) : (sin(PI*x))); };

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public: Table* table;
			bool flag;

	private:
		double test_L, main_L;
		int test_NGrid, main_NGrid;
		double test_a = 0, test_b = /*2*/1, main_a = 0, main_b = 1;

	private: int test_NSeries, main_NSeries;
	private: System::Windows::Forms::GroupBox^  test_groupBoxParameters;
	private: System::Windows::Forms::Label^  test_labelNGrid;
	private: System::Windows::Forms::Label^  test_labelLocError;
	private: System::Windows::Forms::TextBox^  test_textBoxNGrid;
	private: System::Windows::Forms::TextBox^  test_textBoxLocError;
	private: System::Windows::Forms::PictureBox^  test_pictureBoxTask;
	public:
		MainForm(void)
		{
			main_NGrid = 10;
			test_NGrid = 10;
			test_L = main_L = 0.5*10e-6;

			InitializeComponent();

			this->test_textBoxLocError->Text = test_L.ToString();
			this->main_textBoxLocError->Text = main_L.ToString();
			this->main_textBoxNGrid->Text = main_NGrid.ToString();
			this->test_textBoxNGrid->Text = test_NGrid.ToString();

			main_NSeries =test_NSeries= 0;

			flag = false;
			table = 0;
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
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  test_chart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  main_chart;
	private: System::Windows::Forms::TabControl^  tabControl;
	private: System::Windows::Forms::TabPage^  testPage;
	private: System::Windows::Forms::TabPage^  mainPage;
	private: System::Windows::Forms::PictureBox^  main_pictureBoxTask;
	private: System::Windows::Forms::GroupBox^  main_groupBoxParametrs;
	private: System::Windows::Forms::Label^  main_labelNGrid;
	private: System::Windows::Forms::Label^  main_labelLocError;
	private: System::Windows::Forms::TextBox^  main_textBoxNGrid;
	private: System::Windows::Forms::TextBox^  main_textBoxLocError;
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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->testPage = (gcnew System::Windows::Forms::TabPage());
			this->test_groupBoxParameters = (gcnew System::Windows::Forms::GroupBox());
			this->test_labelNGrid = (gcnew System::Windows::Forms::Label());
			this->test_labelLocError = (gcnew System::Windows::Forms::Label());
			this->test_textBoxNGrid = (gcnew System::Windows::Forms::TextBox());
			this->test_textBoxLocError = (gcnew System::Windows::Forms::TextBox());
			this->test_pictureBoxTask = (gcnew System::Windows::Forms::PictureBox());
			this->test_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->test_buttonSolve = (gcnew System::Windows::Forms::Button());
			this->test_buttonClear = (gcnew System::Windows::Forms::Button());
			this->test_buttonTable = (gcnew System::Windows::Forms::Button());
			this->test_buttonError = (gcnew System::Windows::Forms::Button());
			this->test_buttonTrueSolution = (gcnew System::Windows::Forms::Button());
			this->test_buttonRef = (gcnew System::Windows::Forms::Button());
			this->mainPage = (gcnew System::Windows::Forms::TabPage());
			this->main_chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->main_buttonSolve = (gcnew System::Windows::Forms::Button());
			this->main_buttonClear = (gcnew System::Windows::Forms::Button());
			this->main_buttonTable = (gcnew System::Windows::Forms::Button());
			this->main_buttonError = (gcnew System::Windows::Forms::Button());
			this->main_buttonRef = (gcnew System::Windows::Forms::Button());
			this->main_groupBoxParametrs = (gcnew System::Windows::Forms::GroupBox());
			this->main_labelNGrid = (gcnew System::Windows::Forms::Label());
			this->main_labelLocError = (gcnew System::Windows::Forms::Label());
			this->main_textBoxNGrid = (gcnew System::Windows::Forms::TextBox());
			this->main_textBoxLocError = (gcnew System::Windows::Forms::TextBox());
			this->main_pictureBoxTask = (gcnew System::Windows::Forms::PictureBox());
			this->tabControl->SuspendLayout();
			this->testPage->SuspendLayout();
			this->test_groupBoxParameters->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_pictureBoxTask))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_chart))->BeginInit();
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
			this->testPage->Controls->Add(this->test_groupBoxParameters);
			this->testPage->Controls->Add(this->test_pictureBoxTask);
			this->testPage->Controls->Add(this->test_chart);
			this->testPage->Controls->Add(this->test_buttonSolve);
			this->testPage->Controls->Add(this->test_buttonClear);
			this->testPage->Controls->Add(this->test_buttonTable);
			this->testPage->Controls->Add(this->test_buttonError);
			this->testPage->Controls->Add(this->test_buttonTrueSolution);
			this->testPage->Controls->Add(this->test_buttonRef);
			this->testPage->Location = System::Drawing::Point(4, 22);
			this->testPage->Name = L"testPage";
			this->testPage->Padding = System::Windows::Forms::Padding(3);
			this->testPage->Size = System::Drawing::Size(860, 617);
			this->testPage->TabIndex = 0;
			this->testPage->Text = L"Тестовая задача";
			this->testPage->UseVisualStyleBackColor = true;
			// 
			// test_groupBoxParameters
			// 
			this->test_groupBoxParameters->Controls->Add(this->test_labelNGrid);
			this->test_groupBoxParameters->Controls->Add(this->test_labelLocError);
			this->test_groupBoxParameters->Controls->Add(this->test_textBoxNGrid);
			this->test_groupBoxParameters->Controls->Add(this->test_textBoxLocError);
			this->test_groupBoxParameters->Location = System::Drawing::Point(665, 6);
			this->test_groupBoxParameters->Name = L"test_groupBoxParameters";
			this->test_groupBoxParameters->Size = System::Drawing::Size(174, 156);
			this->test_groupBoxParameters->TabIndex = 19;
			this->test_groupBoxParameters->TabStop = false;
			this->test_groupBoxParameters->Text = L"Параметры задачи";
			// 
			// test_labelNGrid
			// 
			this->test_labelNGrid->AutoSize = true;
			this->test_labelNGrid->Location = System::Drawing::Point(22, 31);
			this->test_labelNGrid->Name = L"test_labelNGrid";
			this->test_labelNGrid->Size = System::Drawing::Size(107, 13);
			this->test_labelNGrid->TabIndex = 8;
			this->test_labelNGrid->Text = L"Размерность сетки";
			// 
			// test_labelLocError
			// 
			this->test_labelLocError->AutoSize = true;
			this->test_labelLocError->Location = System::Drawing::Point(24, 94);
			this->test_labelLocError->Name = L"test_labelLocError";
			this->test_labelLocError->Size = System::Drawing::Size(124, 13);
			this->test_labelLocError->TabIndex = 8;
			this->test_labelLocError->Text = L"Контроль погрешности";
			// 
			// test_textBoxNGrid
			// 
			this->test_textBoxNGrid->Location = System::Drawing::Point(27, 50);
			this->test_textBoxNGrid->Name = L"test_textBoxNGrid";
			this->test_textBoxNGrid->Size = System::Drawing::Size(106, 20);
			this->test_textBoxNGrid->TabIndex = 4;
			// 
			// test_textBoxLocError
			// 
			this->test_textBoxLocError->Location = System::Drawing::Point(28, 113);
			this->test_textBoxLocError->Name = L"test_textBoxLocError";
			this->test_textBoxLocError->Size = System::Drawing::Size(106, 20);
			this->test_textBoxLocError->TabIndex = 4;
			// 
			// test_pictureBoxTask
			// 
			this->test_pictureBoxTask->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"test_pictureBoxTask.BackgroundImage")));
			this->test_pictureBoxTask->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->test_pictureBoxTask->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->test_pictureBoxTask->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"test_pictureBoxTask.ErrorImage")));
			this->test_pictureBoxTask->Location = System::Drawing::Point(25, 12);
			this->test_pictureBoxTask->Name = L"test_pictureBoxTask";
			this->test_pictureBoxTask->Size = System::Drawing::Size(621, 150);
			this->test_pictureBoxTask->TabIndex = 18;
			this->test_pictureBoxTask->TabStop = false;
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
			this->test_buttonSolve->Text = L"Решить";
			this->test_buttonSolve->UseVisualStyleBackColor = true;
			this->test_buttonSolve->Click += gcnew System::EventHandler(this, &MainForm::test_buttonSolve_Click);
			// 
			// test_buttonClear
			// 
			this->test_buttonClear->Location = System::Drawing::Point(25, 329);
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
			this->test_buttonError->Text = L"Погрешность";
			this->test_buttonError->UseVisualStyleBackColor = true;
			this->test_buttonError->Click += gcnew System::EventHandler(this, &MainForm::buttonError_Click);
			// 
			// test_buttonTrueSolution
			// 
			this->test_buttonTrueSolution->Location = System::Drawing::Point(25, 276);
			this->test_buttonTrueSolution->Name = L"test_buttonTrueSolution";
			this->test_buttonTrueSolution->Size = System::Drawing::Size(228, 47);
			this->test_buttonTrueSolution->TabIndex = 16;
			this->test_buttonTrueSolution->Text = L"Показать истинное решение";
			this->test_buttonTrueSolution->UseVisualStyleBackColor = true;
			this->test_buttonTrueSolution->Click += gcnew System::EventHandler(this, &MainForm::test_buttonTrueSolution_Click);
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
			this->mainPage->Text = L"Основная задача";
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
			this->main_buttonError->Text = L"Погрешность";
			this->main_buttonError->UseVisualStyleBackColor = true;
			this->main_buttonError->Click += gcnew System::EventHandler(this, &MainForm::buttonError_Click);
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
			// main_groupBoxParametrs
			// 
			this->main_groupBoxParametrs->Controls->Add(this->main_labelNGrid);
			this->main_groupBoxParametrs->Controls->Add(this->main_labelLocError);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxNGrid);
			this->main_groupBoxParametrs->Controls->Add(this->main_textBoxLocError);
			this->main_groupBoxParametrs->Location = System::Drawing::Point(665, 6);
			this->main_groupBoxParametrs->Name = L"main_groupBoxParametrs";
			this->main_groupBoxParametrs->Size = System::Drawing::Size(174, 156);
			this->main_groupBoxParametrs->TabIndex = 8;
			this->main_groupBoxParametrs->TabStop = false;
			this->main_groupBoxParametrs->Text = L"Параметры задачи";
			// 
			// main_labelNGrid
			// 
			this->main_labelNGrid->AutoSize = true;
			this->main_labelNGrid->Location = System::Drawing::Point(22, 31);
			this->main_labelNGrid->Name = L"main_labelNGrid";
			this->main_labelNGrid->Size = System::Drawing::Size(107, 13);
			this->main_labelNGrid->TabIndex = 8;
			this->main_labelNGrid->Text = L"Размерность сетки";
			// 
			// main_labelLocError
			// 
			this->main_labelLocError->AutoSize = true;
			this->main_labelLocError->Location = System::Drawing::Point(24, 94);
			this->main_labelLocError->Name = L"main_labelLocError";
			this->main_labelLocError->Size = System::Drawing::Size(124, 13);
			this->main_labelLocError->TabIndex = 8;
			this->main_labelLocError->Text = L"Контроль погрешности";
			// 
			// main_textBoxNGrid
			// 
			this->main_textBoxNGrid->Location = System::Drawing::Point(27, 50);
			this->main_textBoxNGrid->Name = L"main_textBoxNGrid";
			this->main_textBoxNGrid->Size = System::Drawing::Size(106, 20);
			this->main_textBoxNGrid->TabIndex = 4;
			// 
			// main_textBoxLocError
			// 
			this->main_textBoxLocError->Location = System::Drawing::Point(28, 113);
			this->main_textBoxLocError->Name = L"main_textBoxLocError";
			this->main_textBoxLocError->Size = System::Drawing::Size(106, 20);
			this->main_textBoxLocError->TabIndex = 4;
			// 
			// main_pictureBoxTask
			// 
			this->main_pictureBoxTask->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"main_pictureBoxTask.BackgroundImage")));
			this->main_pictureBoxTask->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->main_pictureBoxTask->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->main_pictureBoxTask->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"main_pictureBoxTask.ErrorImage")));
			this->main_pictureBoxTask->Location = System::Drawing::Point(25, 12);
			this->main_pictureBoxTask->Name = L"main_pictureBoxTask";
			this->main_pictureBoxTask->Size = System::Drawing::Size(621, 150);
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
			this->Text = L"Лабораторная работа 1, вариант 3";
			this->tabControl->ResumeLayout(false);
			this->testPage->ResumeLayout(false);
			this->test_groupBoxParameters->ResumeLayout(false);
			this->test_groupBoxParameters->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_pictureBoxTask))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->test_chart))->EndInit();
			this->mainPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_chart))->EndInit();
			this->main_groupBoxParametrs->ResumeLayout(false);
			this->main_groupBoxParametrs->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_pictureBoxTask))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void buttonTable_Click(System::Object^  sender, System::EventArgs^  e) {
		if (flag==false) {//ссылка на NULL
			MessageBox::Show("Пока нет ни одного решения");
			return;
		}
		const char* str = (tabControl->SelectedIndex == TestTask) ? "./test.txt" : "./main.txt";
		TableForm^ tableForm = gcnew TableForm(tabControl->SelectedIndex, str);
		tableForm->Show();
	}

	private: System::Void main_buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!CheckValues()) return;
		//пока
		/*if (table[tabControl->SelectedIndex] == NULL) {//ссылка на NULL
			MessageBox::Show("Не реализована функция");
			return;
		}*/
		flag = true;

		table = new Table();
		Calculate(*table, main_k, main_q, main_f, main_nu1, main_nu2, main_ksi, main_a, main_NGrid, (main_b - main_a) / main_NGrid, main_L, MainTask);

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
			y[i] = it->vi;
		}

		Show(MainTask, x, y);

		std::ofstream f; 
		f.open("./main.txt");
		f << (*table);
		f.close();

		delete table;
		table = 0;
	}
	private: System::Void test_buttonSolve_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!CheckValues()) return;
		//пока
		/*if (table[tabControl->SelectedIndex] == NULL) {//ссылка на NULL
			MessageBox::Show("Не реализована функция");
			return;
		}*/
		flag = true;

		table = new Table();
		Calculate(*table, test_k, test_q, test_f, test_nu1, test_nu2, test_ksi, test_a, test_NGrid, (test_b-test_a)/test_NGrid, test_L, TestTask);

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
			y[i] = it->vi;
		}

		Show(TestTask, x,y);

		std::ofstream f;
		f.open("./test.txt");
		f << (*table);
		f.close();
		
		delete table;
		table = 0;
	}

	private: System::Void Show(int task, array<double^>^ x, array<double^>^ y) {
		DataVisualization::Charting::Chart^ chart = (task == MainTask) ? main_chart : test_chart;
		DataVisualization::Charting::Series^ s = gcnew DataVisualization::Charting::Series;
		chart->Series->Add(s);

		double _minX = (task == MainTask) ? main_a : test_a;
		double _maxX = (task == MainTask) ? main_b : test_b;

		s->BorderWidth = 2;

		s->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;

		chart->ChartAreas[0]->AxisX->LineWidth = 1;
		chart->ChartAreas[0]->AxisY->LineWidth = 1;

		chart->ChartAreas[0]->AxisX->Minimum = _minX;
		if ((double)(int)_maxX != _maxX)
			chart->ChartAreas[0]->AxisX->Maximum = (int)(_maxX)+1;
		else chart->ChartAreas[0]->AxisX->Maximum = (int)(_maxX);

		const int H = 20;//шаг разметки
		chart->ChartAreas[0]->AxisX->MajorGrid->Interval = H*(_maxX - _minX) / chart->Width;

		interior_ptr<int> NSeries = (tabControl->SelectedIndex == TestTask) ? (&test_NSeries) : (&main_NSeries);
		chart->Series[*NSeries]->Points->DataBindXY(x, y);
		(*NSeries)++;
	}



	private: System::Void buttonError_Click(System::Object^  sender, System::EventArgs^  e) {
		if (flag == false) {//ссылка на NULL
			MessageBox::Show("Пока нет ни одного решения");
			return;
		}
		const char* str = (tabControl->SelectedIndex == TestTask) ? "./test.txt" : "./main.txt";
		double _X = tabControl->SelectedIndex == MainTask ? main_b : test_b;
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
		const double dx = test_b / n;
	
		array<double^>^ x = gcnew array<double^>(n);
		array<double^>^ y = gcnew array<double^>(n);

		for (int i=0; i<n; i++) {
			x[i] = gcnew double;
			y[i] = gcnew double;
			x[i] = dx*i;
			y[i] = RetU((double)x[i]);
		}

		Show(TestTask, x,y);
	}

	private: double CalcEps(double&x, int _N) {

		double max = 0;
		Table::iterator it = table->begin();
		for (int i = 0; i <= _N; i++, it++) {
			if (it->diff_abs > max) {
				max = it->diff_abs;
				x = it->xi;
			}
		}
		return max;
	}
	private: System::Void buttonRef_Click(System::Object^  sender, System::EventArgs^  e) {
		if (flag==false) {//ссылка на NULL
			MessageBox::Show("Пока нет ни одного решения");
			return;
		}
		table = new Table();
		std::ifstream f;
		if (tabControl->SelectedIndex == TestTask) f.open("./test.txt");
		else if (tabControl->SelectedIndex == MainTask) f.open("./main.txt");
		f >> (*table);
		f.close();

		int t = tabControl->SelectedIndex;
		double _N = (--table->end())->i;
		double maxL= (t == MainTask) ? main_L : test_L;
		double x=0;
		double eps = CalcEps(x, _N);

		delete table;
		RefForm^ refForm = gcnew RefForm(t, _N, maxL, eps, x);
		refForm->Show();
	}	
	
	public: bool CheckValues() {
		bool f;
		double d;
		int i;
		if (tabControl->SelectedIndex == TestTask) {

			
			f = Int32::TryParse(test_textBoxNGrid->Text, i);
			if (!f) {
				MessageBox::Show("Неверное значение: разрешение сетки должно быть числом");
				return false;
			}
			test_NGrid = i;
			f = Double::TryParse(test_textBoxLocError->Text, d);
			if (!f) {
				MessageBox::Show("Неверное значение: значение контроля погрешности должно быть числом ");
				return false;
			}
			test_L = d;
			return true;
		}
		if (tabControl->SelectedIndex == MainTask) {

			f = Int32::TryParse(main_textBoxNGrid->Text, i);
			if (!f) {
				MessageBox::Show("Неверное значение: разрешение сетки быть числом");
				return false;
			}
			main_NGrid = i;
			f = Double::TryParse(main_textBoxLocError->Text, d);
			if (!f) {
				MessageBox::Show("Неверное значение: значение контроля локальной погрешности должно быть числом ");
				return false;
			}
			main_L = d;
			return true;
		}
		return false;

	}
};
}
