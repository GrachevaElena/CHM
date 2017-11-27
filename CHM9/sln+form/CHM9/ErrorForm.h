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
	/// —водка дл€ ErrorForm
	/// </summary>
	public ref class ErrorForm : public System::Windows::Forms::Form
	{
	public:

	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart;
	public:
		double X;
		ErrorForm(double _X, const char* str)
		{
			X = _X;
			
			std::ifstream f;
			f.open(str);
			Table table;
			f >> table;
			f.close();

			InitializeComponent();

			Show(table);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~ErrorForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

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
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// chart
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			this->chart->Location = System::Drawing::Point(0, 0);
			this->chart->Name = L"chart";
			this->chart->Size = System::Drawing::Size(1041, 261);
			this->chart->TabIndex = 0;
			this->chart->Text = L"chart";
			// 
			// ErrorForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1041, 261);
			this->Controls->Add(this->chart);
			this->Name = L"ErrorForm";
			this->Text = L"Ћокальна€ погрешность";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Show(Table& table) {
		DataVisualization::Charting::Series^ s = gcnew DataVisualization::Charting::Series;
		chart->Series->Add(s);

		s->Color = Color::Blue;
		s->BorderWidth = 2;

		s->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;

		const int n = (--table.end())->i + 1;

		chart->ChartAreas[0]->AxisX->Minimum = 0;
		chart->ChartAreas[0]->AxisX->Maximum = X;

		array<double^>^ x = gcnew array<double^>(n);
		array<double^>^ y = gcnew array<double^>(n);
		int i = 0;
		for (auto it = table.begin(); it != table.end(); it++, i++) {
			x[i] = gcnew double;
			y[i] = gcnew double;
			x[i] = it->xi;
			y[i] = it->diff_abs;
		}

		const int H = 20;//шаг разметки
		chart->ChartAreas[0]->AxisX->MajorGrid->Interval = H*n / chart->Width;

		chart->Series[0]->Points->DataBindXY(x, y);
	}
	};
}
