#include "ErrorForm.h"
using namespace System;
using namespace System::Windows::Forms;

System::Void CHM9::ErrorForm::pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	PictureBox^ p = (PictureBox^)sender;

	Graphics^ g = e->Graphics;
	g->Clear(Color::White);

	const int OffsetX = 80;//отступ для разметки
	const int OffsetY = 30;

	const int Width = p->Width - OffsetX; //ширина(длина) области, в которой стоится график
	const int Height = p->Height - OffsetY;

	const int H = 20; //шаг разметки
	const int D = 15; //на сколько длиннее каждая LH строка(столбец) разметки
	const int LH = 5; //какая строка(столбец) по счету будет выделяться в разметке

	const int N = Width / H + 1; //число столбцов (строк) разметки
	const int M = Height / H + 1;

	double maxS = -10000000, minS=10000000;

	for (auto it = table->begin(); it != table->end(); it++) {
		if (it->s > maxS) maxS = it->s;
		if (it->s < minS) minS = it->s;
	}

	const double dx = Width / X; //сколько пикселей соответствует единице длины
	const double dy = Height / (maxS-minS);

	const double dhx = H*X / Width; //как изменится x за шаг H на графике
	const double dhy = H*(maxS-minS) / Height;


	//Markup
	for (int i = 0; i < N; i++) {
		if (i % LH == 0)
			g->DrawLine(gcnew Pen(Color::LightGray, 1), i*H + OffsetX, 0, i*H + OffsetX, p->Height - OffsetY + D);
		else g->DrawLine(gcnew Pen(Color::LightGray, 1), i*H + OffsetX, 0, i*H + OffsetX, p->Height - OffsetY);
	}
	for (int i = 0; i < M; i++) {
		if (i % LH == 0)
			g->DrawLine(gcnew Pen(Color::LightGray, 1), 0 + OffsetX - D, p->Height - (i*H + OffsetY), p->Width + OffsetX, p->Height - (i*H + OffsetY));
		else g->DrawLine(gcnew Pen(Color::LightGray, 1), 0 + OffsetX, p->Height - (i*H + OffsetY), p->Width, p->Height - (i*H + OffsetY));
	}

	g->DrawLine(gcnew Pen(Color::Black, 2), 0 + OffsetX, p->Height - OffsetY, 0 + OffsetX, 0);
	g->DrawLine(gcnew Pen(Color::Black, 2), 0 + OffsetX, p->Height - OffsetY, p->Width, p->Height - OffsetY);

	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 8, FontStyle::Bold);
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(Color::Black);

	g->DrawString("X", font, brush, PointF(p->Width - 20, p->Height - OffsetY + 5));
	g->DrawString("S", font, brush, PointF(OffsetX - 20, 10));

	font = gcnew System::Drawing::Font("Microsoft Sans Serif", 8, FontStyle::Regular);

	for (int i = 0; i < M / LH + 1; i++)
		g->DrawString((Math::Round(minS + i * 5 * dhy, 10)).ToString(), font, brush, PointF(3, p->Height - OffsetY - i * 5 * H));
	for (int i = 0; i < N / LH + 1; i++)
		g->DrawString((Math::Round(i * 5 * dhx, 3)).ToString(), font, brush, PointF(OffsetX + i * 5 * H, p->Height - 20));


	//Drawing

	for (auto it = table->begin(); it != --(table->end()); ) { //all rows
		g->DrawLine(gcnew Pen(Color::Blue, 1), (int)(it->xi*dx + OffsetX), (int)(p->Height - ((it->s - minS)*dy + OffsetY)), (int)((++it)->xi*dx + OffsetX), (int)(p->Height - ((it->s - minS)*dy + OffsetY)));
	}
}
