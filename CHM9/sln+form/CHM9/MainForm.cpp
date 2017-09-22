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
	PictureBox^ p = (PictureBox^)sender;

	Graphics^ g = e->Graphics;
	g->Clear(Color::White);

	int tabPage = tabControl->SelectedIndex;

	for (auto it = table_for_drawing[tabPage]->begin()->begin(); it != table_for_drawing[tabPage]->begin()->end(); it++) {
		if (it->x > maxX[tabPage]) maxX[tabPage] = it->x;
		if (it->v > maxV[tabPage]) maxV[tabPage] = it->v;
		if (it->v < minV[tabPage]) minV[tabPage] = it->v;
	}

	const int offsetX = 60;
	const int offsetY = 40;

	const int width = p->Width - offsetX;
	const int height = p->Height - offsetY;

	const int dx = width / maxX[tabPage];
	const int dy = height / (maxV[tabPage] - minV[tabPage]);

	const int h = 20;
	const int d = 15;

	const double dhx = h*maxX[tabPage] / width;
	const double dhy = h*(maxV[tabPage] -minV[tabPage]) / height;

	const int n = width / h + 1;
	const int m = height / h + 1;

	//Markup
	for (int i = 0; i < n; i++) {
		if (i % 5 == 0)
			g->DrawLine(gcnew Pen(Color::LightGray, 1), i*h + offsetX, 0, i*h + offsetX, p->Height - offsetY + d);
		else g->DrawLine(gcnew Pen(Color::LightGray, 1), i*h + offsetX, 0, i*h + offsetX, p->Height - offsetY);
	}
	for (int i = 0; i < m; i++) {
		if (i % 5 == 0)
			g->DrawLine(gcnew Pen(Color::LightGray, 1), 0 + offsetX - d, p->Height - (i*h + offsetY), p->Width + offsetX, p->Height - (i*h + offsetY));
		else g->DrawLine(gcnew Pen(Color::LightGray, 1), 0 + offsetX, p->Height - (i*h + offsetY), p->Width, p->Height - (i*h + offsetY));
	}

	g->DrawLine(gcnew Pen(Color::Black, 2), 0 + offsetX, p->Height - offsetY, 0 + offsetX, 0);
	g->DrawLine(gcnew Pen(Color::Black, 2), 0 + offsetX, p->Height - offsetY, p->Width, p->Height - offsetY);

	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 8, FontStyle::Bold);
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(Color::Black);

	g->DrawString("X", font, brush, PointF(p->Width - 20, p->Height - offsetY + 5));
	g->DrawString("U", font, brush, PointF(offsetX - 20, 20));

	font = gcnew System::Drawing::Font("Microsoft Sans Serif", 8, FontStyle::Regular);

	for (int i = 0; i < m / 5 + 1; i++)
		g->DrawString((Math::Round(minV[tabPage] +i*5*dhy,3)).ToString(), font, brush, PointF(offsetX / 5, p->Height - offsetY - i * 5 * h));
	for (int i = 0; i < n / 5 + 1; i++)
		g->DrawString((Math::Round(i * 5 * dhx, 3)).ToString(), font, brush, PointF(offsetX + i*5*h, p->Height - offsetY/1.8));


	//Drawing

	for (auto itL = table_for_drawing[tabPage]->begin(); itL != table_for_drawing[tabPage]->end(); itL++)//all tables
		for (auto it = itL->begin(); it != --(itL->end()); ) { //all rows
			g->DrawLine(gcnew Pen(Color::FromArgb(itL->GetColor()),2), (int)it->x*dx + offsetX, p->Height - ((int)(it->v - minV[tabPage])*dy + offsetY), (int)(++it)->x*dx + offsetX, p->Height - ((int)(it->v - minV[tabPage])*dy + offsetY));
		}
}

