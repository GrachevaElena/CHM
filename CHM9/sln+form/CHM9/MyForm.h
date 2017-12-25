#pragma once
#include "Interpolation.h"
#include <fstream>
#include <string>
#using <System.Windows.Forms.DataVisualization.dll>


namespace CHM9 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int N = 10;
	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			Double arr[2][N];
			ReadFile(arr);
			SetTable(arr);
			SetChart(arr);
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: 
		void SetTable(Double arr[2][N]) {
			Double diff[N];
			Diff(arr, diff); 
			Label^ textBox1 = gcnew Label(), ^textBox2 = gcnew Label(), ^textBox3 = gcnew Label();
			System::Drawing::Font^ font = gcnew System::Drawing::Font("TimesNewRoman", 10);
			textBox1->Font = font;
			textBox2->Font = font;
			textBox3->Font = font;
			textBox1->Text = "     x[i]";
			textBox2->Text = "     f[i]";
			textBox3->Text = "     f'[i]";
			tableLayoutPanel1->Controls->Add(textBox1);
			tableLayoutPanel1->Controls->Add(textBox2);
			tableLayoutPanel1->Controls->Add(textBox3);
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < 3; j++)
				{
					TextBox^ textBox = gcnew TextBox();
					tableLayoutPanel1->Controls->Add(textBox);
					switch (j) {
					case 2:
						textBox->Text = (diff[i]).ToString("F4");
						break;
					default: 
						textBox->Text = (arr[j][i]).ToString();
						break;
					}
				}

			}
			
		}
		void Diff(Double arr[2][N], Double diff[N]) {
			Polinom p = Interpolation(N, arr[0], arr[1]);
			p = p.Diff();
			for (int i = 0; i < N; i++)
				diff[i] = p.calc(arr[0][i]);
		}
		void ReadFile(Double arr[2][N]) {
			std::ifstream f;
			f.open("chm.txt");
			char str[100];
			for (int i = 0; i<N; i++)
				for (int j = 0; j < 2; j++) {
					f.getline(str,100);
					arr[j][i] = atof(str);
				}
			f.close();
		}
		void SetChart(Double arr[2][N]) {
			array<double^>^ x = gcnew array<double^>(N);
			array<double^>^ y = gcnew array<double^>(N);
			for (int i = 0; i < N; i++)
			{
				x[i] = arr[0][i];
				y[i] = arr[1][i];
			}

			series2->Points->DataBindXY(x, y);

			Polinom p = Interpolation(N, arr[0], arr[1]);
			int NG = 1000;
			array<double^>^ x1 = gcnew array<double^>(NG);
			array<double^>^ y1 = gcnew array<double^>(NG);
			for (int i = 0; i < NG; i++) {
				x1[i] = arr[0][N - 1] / NG*i+arr[0][0];
				y1[i] = p.calc((double)x1[i]);
			}

			series1->Points->DataBindXY(x1, y1);

		}

	private: System::Windows::Forms::Panel^  panel1;
	protected:
		System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
		System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Controls->Add(this->chart1);
			this->panel1->Location = System::Drawing::Point(0, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(685, 482);
			this->panel1->TabIndex = 0;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 3;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40.60151F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				59.39849F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				77)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 11;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 48.57143F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 51.42857F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 41)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 43)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 42)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 45)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 46)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 40)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(219, 476);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// chart1
			// 
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::DarkGray;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(198, 3);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Name = L"Series2";
			chart1->Series->Add(series1);
			chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(486, 478);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(685, 479);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"»нтерпол€ци€";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
};
}
