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
	/// Сводка для TableForm
	/// </summary>
	public ref class TableForm : public System::Windows::Forms::Form
	{

		int Task;
	public:
		TableForm(int task, const char* str)
		{
			Task = task;
			InitializeComponent();

			std::ifstream f;
			f.open(str);
			Table table;
			f >> table;
			f.close();

			ShowTable(table);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~TableForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ui;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  xi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  vi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  v2i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  diff_abs;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->xi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->vi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->v2i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->diff_abs = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ui = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			if (Task == TestTask) {
				this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
					this->i, this->xi, this->ui, this->vi, this->diff_abs
				});
			}
			else if (Task == MainTask) {
				this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
					this->i, this->xi, this->vi, this->v2i, this->diff_abs
				});
			}
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(691, 520);
			this->dataGridView1->TabIndex = 0;
			// 
			// i
			// 
			this->i->HeaderText = L"i";
			this->i->Name = L"i";
			this->i->ReadOnly = true;
			// 
			// xi
			// 
			this->xi->HeaderText = L"x[i]";
			this->xi->Name = L"xi";
			this->xi->ReadOnly = true;
			// 
			// vi
			// 
			this->vi->HeaderText = L"v[i]";
			this->vi->Name = L"vi";
			this->vi->ReadOnly = true;
			// 
			// diff_abs
			// 
			if (Task == MainTask) this->diff_abs->HeaderText = L"|V[i]-V2[2i]|";
			else this->diff_abs->HeaderText = L"|u[i]-v[i]|";
			this->diff_abs->Name = L"diff_abs";
			this->diff_abs->ReadOnly = true;

			if (Task == TestTask) {
				// 
				// ui
				// 
				this->ui->HeaderText = L"u[i]";
				this->ui->Name = L"ui";
				this->ui->ReadOnly = true;
			}
			else {
				// 
				// v2i
				// 
				this->v2i->HeaderText = L"v2[2i]";
				this->v2i->Name = L"v2i";
				this->v2i->ReadOnly = true;
			}
			// 
			// TableForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 520);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"TableForm";
			this->Text = L"Таблица";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	protected: void ShowTable(Table& table) {
		int i = 0;
		for (auto it = table.begin(); it!=table.end(); it++, i++) // Цикл добавления строк
		{
			this->dataGridView1->Rows->Add();
			this->dataGridView1->Rows[i]->Cells[0]->Value = it->i;
			this->dataGridView1->Rows[i]->Cells[1]->Value = it->xi;
			this->dataGridView1->Rows[i]->Cells[2]->Value = it->vi;
			this->dataGridView1->Rows[i]->Cells[4]->Value = it->diff_abs;
			if (Task == TestTask) {
				this->dataGridView1->Rows[i]->Cells[3]->Value = it->ui;
			}
			else {
				this->dataGridView1->Rows[i]->Cells[3]->Value = it->v2i;
			}
		}
	}

	};
}
