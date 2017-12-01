#pragma once
#include "Table.h"
#include <fstream>
#include "schet.h"

namespace CHM {
	const double PI = 3.14159265358979323846264;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ TableForm
	/// </summary>
	public ref class DivForm : public System::Windows::Forms::Form
	{
		Function k, q, f;
		double ksi, nu1, nu2;

	public:
		DivForm(int task, Function _k, Function _q, Function _f, double _ksi, double _nu1, double _nu2)
		{
			k = _k; q = _q; f = _f; ksi = _ksi, nu1=_nu1, nu2=_nu2;
			InitializeComponent();

			ShowTable(task);
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~DivForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  n;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  s;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  div;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->n = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->s = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->div = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->n, this->s, this->div
			});
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(691, 520);
			this->dataGridView1->TabIndex = 0;
			// 
			// n
			// 
			this->n->HeaderText = L"n";
			this->n->Name = L"n";
			this->n->ReadOnly = true;
			// 
			// s
			// 
			this->s->HeaderText = L"погрешность";
			this->s->Name = L"s";
			this->s->ReadOnly = true;
			// 
			// div
			// 
			this->div->HeaderText = L"отношение погрешностей";
			this->div->Name = L"vi";
			this->div->ReadOnly = true;
			// 
			// TableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(350, 150);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"DivForm";
			this->Text = L"ќтношение погрешностей";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	public: double CalcEps(int _N, Table* table) {

		double max = 0;
		Table::iterator it = table->begin();
		for (int i = 0; i <= _N; i++, it++) {
			if (it->diff_abs > max) {
				max = it->diff_abs;
			}
		}
		return max;
	}
	private:
		double a = 0, b = 1;

	public: void ShowTable(int Task) {
		const int N = 5;
		const double n0 = 10;
		double s0, s1;
		for (int i = 0; i < N; i++) // ÷икл добавлени€ строк
		{
			Table table;
			int n = pow(2,i)*n0;
			Calculate(table, k, q, f, nu1, nu2, ksi, a, n, (b - a) / n, 10, MainTask);
			double x;
			s1 = CalcEps(n, &table);
			this->dataGridView1->Rows->Add();
			this->dataGridView1->Rows[i]->Cells[0]->Value = n;
			this->dataGridView1->Rows[i]->Cells[1]->Value = s1;
			if (i > 0) this->dataGridView1->Rows[i]->Cells[2]->Value = s0 / s1;
			s0 = s1;
		}
	}

	};
}
