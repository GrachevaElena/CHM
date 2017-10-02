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
	/// Сводка для RefForm
	/// </summary>
	public ref class RefForm : public System::Windows::Forms::Form
	{
	public:
		RefForm(Table & table, int task, double X, double maxL, double eps, int N, int p, double h0)
		{
			InitializeComponent();

			this->labelTask->Text = L"Тип задачи: " + ((task == MainTask) ? L"основная" : L"тестовая");
			this->labelP->Text = L"Порядок метода: p=" + p.ToString();
			this->labelX0->Text = L"x0=" + table.begin()->xi.ToString() + L", u0=" + table.begin()->ui.ToString() + L", b=" + X.ToString();
			this->labelH0->Text = L"h0=" + h0.ToString() + L", e=" + maxL.ToString() + L", Nmax=" + N.ToString() + L", eps=" + eps.ToString();
			this->labelUdv->Text = L"Ув. шага=" + findUdv(table).ToString() + L", ум. шага=" + findDel(table).ToString();
			this->labelBoard->Text = L"n=" + findN(table).ToString() + L", |b-x[n]|=" + findBoard(table, X).ToString();
			this->labelMaxL->Text = L"Max|S|=" + findMaxS(table).ToString() + L" при x=" + findMaxSX(table).ToString();
			this->labelMinL->Text = L"Min|S|=" + findMinS(table).ToString() + L" при x=" + findMinSX(table).ToString();
			this->labelMaxh->Text = L"Max h[i]=" + findHMax(table).ToString() + L" при x[i+1]=" + findHMaxX(table).ToString();
			this->labelMinh->Text = L"Min h[i]=" + findHMin(table).ToString() + L" при x[i+1]=" + findHMinX(table).ToString();
			if (task == TestTask) this->labelGlobErr->Text = L"Max |U[i]-V[i]|=" + findMaxDiffUV(table).ToString() + L" при x[i]=" + findMaxDiffUVX(table).ToString();
			else this->labelGlobErr->Text = "";
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~RefForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelBoard;
	protected:



	private: System::Windows::Forms::Label^  labelMaxL;
	private: System::Windows::Forms::Label^  labelMaxh;
	private: System::Windows::Forms::Label^  labelMinh;
	private: System::Windows::Forms::Label^  labelP;
	private: System::Windows::Forms::Label^  labelTask;


	private: System::Windows::Forms::Label^  labelX0;
	private: System::Windows::Forms::Label^  labelH0;
	private: System::Windows::Forms::Label^  labelMinL;
	private: System::Windows::Forms::Label^  labelGlobErr;
	private: System::Windows::Forms::Label^  labelUdv;






	protected:

	protected:




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
		void InitializeComponent()
		{
			this->labelBoard = (gcnew System::Windows::Forms::Label());
			this->labelMaxL = (gcnew System::Windows::Forms::Label());
			this->labelMaxh = (gcnew System::Windows::Forms::Label());
			this->labelMinh = (gcnew System::Windows::Forms::Label());
			this->labelP = (gcnew System::Windows::Forms::Label());
			this->labelTask = (gcnew System::Windows::Forms::Label());
			this->labelX0 = (gcnew System::Windows::Forms::Label());
			this->labelH0 = (gcnew System::Windows::Forms::Label());
			this->labelMinL = (gcnew System::Windows::Forms::Label());
			this->labelGlobErr = (gcnew System::Windows::Forms::Label());
			this->labelUdv = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// labelBoard
			// 
			this->labelBoard->AutoSize = true;
			this->labelBoard->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelBoard->Location = System::Drawing::Point(46, 130);
			this->labelBoard->Name = L"labelBoard";
			this->labelBoard->Size = System::Drawing::Size(129, 17);
			this->labelBoard->TabIndex = 0;
			this->labelBoard->Text = L"Выход на границу:";
			// 
			// labelMaxL
			// 
			this->labelMaxL->AutoSize = true;
			this->labelMaxL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMaxL->Location = System::Drawing::Point(46, 160);
			this->labelMaxL->Name = L"labelMaxL";
			this->labelMaxL->Size = System::Drawing::Size(233, 17);
			this->labelMaxL->TabIndex = 0;
			this->labelMaxL->Text = L"Максимальная лок. погрешность: ";
			// 
			// labelMaxh
			// 
			this->labelMaxh->AutoSize = true;
			this->labelMaxh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMaxh->Location = System::Drawing::Point(46, 250);
			this->labelMaxh->Name = L"labelMaxh";
			this->labelMaxh->Size = System::Drawing::Size(139, 17);
			this->labelMaxh->TabIndex = 0;
			this->labelMaxh->Text = L"Максимальный шаг:";
			// 
			// labelMinh
			// 
			this->labelMinh->AutoSize = true;
			this->labelMinh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMinh->Location = System::Drawing::Point(46, 280);
			this->labelMinh->Name = L"labelMinh";
			this->labelMinh->Size = System::Drawing::Size(133, 17);
			this->labelMinh->TabIndex = 0;
			this->labelMinh->Text = L"Минимальный шаг:";
			// 
			// labelP
			// 
			this->labelP->AutoSize = true;
			this->labelP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelP->Location = System::Drawing::Point(46, 40);
			this->labelP->Name = L"labelP";
			this->labelP->Size = System::Drawing::Size(121, 17);
			this->labelP->TabIndex = 1;
			this->labelP->Text = L"Порядок метода:";
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
			this->labelTask->Text = L"Тип задачи:";
			// 
			// labelX0
			// 
			this->labelX0->AutoSize = true;
			this->labelX0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelX0->Location = System::Drawing::Point(46, 70);
			this->labelX0->Name = L"labelX0";
			this->labelX0->Size = System::Drawing::Size(62, 17);
			this->labelX0->TabIndex = 1;
			this->labelX0->Text = L"x0= u0= ";
			// 
			// labelH0
			// 
			this->labelH0->AutoSize = true;
			this->labelH0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelH0->Location = System::Drawing::Point(46, 100);
			this->labelH0->Name = L"labelH0";
			this->labelH0->Size = System::Drawing::Size(36, 17);
			this->labelH0->TabIndex = 1;
			this->labelH0->Text = L"h0= ";
			// 
			// labelMinL
			// 
			this->labelMinL->AutoSize = true;
			this->labelMinL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMinL->Location = System::Drawing::Point(46, 190);
			this->labelMinL->Name = L"labelMinL";
			this->labelMinL->Size = System::Drawing::Size(227, 17);
			this->labelMinL->TabIndex = 0;
			this->labelMinL->Text = L"Минимальная лок. погрешность: ";
			// 
			// labelGlobErr
			// 
			this->labelGlobErr->AutoSize = true;
			this->labelGlobErr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelGlobErr->Location = System::Drawing::Point(46, 310);
			this->labelGlobErr->Name = L"labelGlobErr";
			this->labelGlobErr->Size = System::Drawing::Size(133, 17);
			this->labelGlobErr->TabIndex = 2;
			this->labelGlobErr->Text = L"Глоб. погрешность";
			// 
			// labelUdv
			// 
			this->labelUdv->AutoSize = true;
			this->labelUdv->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelUdv->Location = System::Drawing::Point(46, 220);
			this->labelUdv->Name = L"labelUdv";
			this->labelUdv->Size = System::Drawing::Size(175, 17);
			this->labelUdv->TabIndex = 0;
			this->labelUdv->Text = L"Число увеличений шага: ";
			// 
			// RefForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(432, 339);
			this->Controls->Add(this->labelGlobErr);
			this->Controls->Add(this->labelTask);
			this->Controls->Add(this->labelH0);
			this->Controls->Add(this->labelX0);
			this->Controls->Add(this->labelP);
			this->Controls->Add(this->labelMinL);
			this->Controls->Add(this->labelMaxL);
			this->Controls->Add(this->labelMaxh);
			this->Controls->Add(this->labelMinh);
			this->Controls->Add(this->labelUdv);
			this->Controls->Add(this->labelBoard);
			this->Name = L"RefForm";
			this->Text = L"Справка";
			this->Load += gcnew System::EventHandler(this, &RefForm::RefForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void RefForm_Load(System::Object^  sender, System::EventArgs^  e) {}

	private: int findN(Table&t) {
		return (--t.end())->i;
	}

	private: double findBoard(Table&t, double b) {
		return abs(b - (--t.end())->xi);
	}

	private: double findMaxS(Table&t) {
		double s = (++t.begin())->s;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->s > s) {
				s = it->s;
			}
		return s;
	}
	private: double findMaxSX(Table&t) {
		double s = (++t.begin())->s;
		double x = (++t.begin())->xi;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->s > s) {
				s = it->s;
				x = it->xi;
			}
		return x;
	}

	private: double findMinS(Table&t) {
		double s = (++t.begin())->s;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->s < s) {
				s = it->s;
			}
		return s;
	}
	private: double findMinSX(Table&t) {
		double s = (++t.begin())->s;
		double x = (++t.begin())->xi;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->s < s) {
				s = it->s;
				x = it->xi;
			}
		return x;
	}

	private: int findUdv(Table&t) {
		int n = 0;
		for (auto it = t.begin(); it != t.end(); it++)
			n += it->stepInc;
		return n;
	}

	private: int findDel(Table&t) {
		int n = 0;
		for (auto it = t.begin(); it != t.end(); it++)
			n += it->stepDec;
		return n;
	}

	private: double findHMax(Table&t) {
		double h = (++t.begin())->hi_1;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->hi_1 > h) {
				h = it->hi_1;
			}
		return h;
	}
	private: double findHMaxX(Table&t) {
		double h = (++t.begin())->hi_1;
		double x = (++t.begin())->xi;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->hi_1 > h) {
				h = it->hi_1;
				x = it->xi;
			}
		return x;
	}

	private: double findHMin(Table&t) {
		double h = (++t.begin())->hi_1;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->hi_1 < h) {
				h = it->hi_1;
			}
		return h;
	}
	private: double findHMinX(Table&t) {
		double h = (++t.begin())->hi_1;
		double x = (++t.begin())->xi;
		for (auto it = ++t.begin(); it != t.end(); it++)
			if (it->hi_1 < h) {
				h = it->hi_1;
				x = it->xi;
			}
		return x;
	}

	private: double findMaxDiffUV(Table&t) {
		double d = t.begin()->abs_ui_vi;
		for (auto it = t.begin(); it != t.end(); it++)
			if (it->abs_ui_vi > d) {
				d = it->abs_ui_vi;
			}
		return d;
	}
	private: double findMaxDiffUVX(Table&t) {
		double d = t.begin()->abs_ui_vi;
		double x = t.begin()->xi;
		for (auto it = t.begin(); it != t.end(); it++)
			if (it->abs_ui_vi > d) {
				d = it->abs_ui_vi;
				x = it->xi;
			}
		return x;
	}

	};
}
