#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CHM9::MainForm form;
	Application::Run(%form);
}


System::Void CHM9::MainForm::pictureBoxGraphic_Paint(System::Object ^ sender, System::Windows::Forms::PaintEventArgs ^ e)
{
	if (table_for_drawing[tabControl->SelectedIndex]->size()==0) return;
	PictureBox^ p = (PictureBox^)sender;

	Graphics^ g = e->Graphics;
	g->Clear(Color::White);

	int tabPage = tabControl->SelectedIndex;

	for (auto it = table_for_drawing[tabPage]->begin()->begin(); it != table_for_drawing[tabPage]->begin()->end(); it++) {
		if (it->x > maxX[tabPage]) maxX[tabPage] = it->x;
		if (it->v > maxV[tabPage]) maxV[tabPage] = it->v;
		if (it->v < minV[tabPage]) minV[tabPage] = it->v;
	}

	const int OffsetX = 60;
	const int OffsetY = 40;

	const int Width = p->Width - OffsetX;
	const int Height = p->Height - OffsetY;

	const int H = 20;
	const int D = 15;

	const int N = Width / H + 1;
	const int M = Height / H + 1;

	const double dx =Width/maxX[tabPage];//сколько пикселей соответствует единице длины
	const double dy = Height/(maxV[tabPage] - minV[tabPage]);

	const double dhx = H*maxX[tabPage] / Width;
	const double dhy = H*(maxV[tabPage] -minV[tabPage]) / Height;


	//Markup
	for (int i = 0; i < N; i++) {
		if (i % 5 == 0)
			g->DrawLine(gcnew Pen(Color::LightGray, 1), i*H + OffsetX, 0, i*H + OffsetX, p->Height - OffsetY + D);
		else g->DrawLine(gcnew Pen(Color::LightGray, 1), i*H + OffsetX, 0, i*H + OffsetX, p->Height - OffsetY);
	}
	for (int i = 0; i < M; i++) {
		if (i % 5 == 0)
			g->DrawLine(gcnew Pen(Color::LightGray, 1), 0 + OffsetX - D, p->Height - (i*H + OffsetY), p->Width + OffsetX, p->Height - (i*H + OffsetY));
		else g->DrawLine(gcnew Pen(Color::LightGray, 1), 0 + OffsetX, p->Height - (i*H + OffsetY), p->Width, p->Height - (i*H + OffsetY));
	}

	g->DrawLine(gcnew Pen(Color::Black, 2), 0 + OffsetX, p->Height - OffsetY, 0 + OffsetX, 0);
	g->DrawLine(gcnew Pen(Color::Black, 2), 0 + OffsetX, p->Height - OffsetY, p->Width, p->Height - OffsetY);

	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 8, FontStyle::Bold);
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(Color::Black);

	g->DrawString("X", font, brush, PointF(p->Width - 20, p->Height - OffsetY + 5));
	g->DrawString("U", font, brush, PointF(OffsetX - 20, 20));

	font = gcnew System::Drawing::Font("Microsoft Sans Serif", 8, FontStyle::Regular);

	for (int i = 0; i < M / 5 + 1; i++)
		g->DrawString((Math::Round(minV[tabPage] +i*5*dhy,3)).ToString(), font, brush, PointF(3, p->Height - OffsetY - i * 5 * H));
	for (int i = 0; i < N / 5 + 1; i++)
		g->DrawString((Math::Round(i * 5 * dhx, 3)).ToString(), font, brush, PointF(OffsetX + i*5*H, p->Height - 35));


	//Drawing

	for (auto itL = table_for_drawing[tabPage]->begin(); itL != table_for_drawing[tabPage]->end(); itL++)//all tables
		for (auto it = itL->begin(); it != --(itL->end()); ) { //all rows
			g->DrawLine(gcnew Pen(Color::FromArgb(itL->GetColor()),2), (int)(it->x*dx + OffsetX), (int)(p->Height - ((it->v - minV[tabPage])*dy + OffsetY)), (int)((++it)->x*dx + OffsetX), (int)(p->Height - ((it->v - minV[tabPage])*dy + OffsetY)));
		}
}

