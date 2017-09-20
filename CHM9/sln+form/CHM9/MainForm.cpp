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

	double maxV, minV; 
	maxV = minV = (*table)[0].viItog;
	for (int i = 1; i < table->GetSize(); i++) {
		if ((*table)[i].viItog > maxV) maxV = (*table)[i].viItog;
		if ((*table)[i].viItog < minV) minV = (*table)[i].viItog;
	}

	const int offsetX = 60;
	const int offsetY = 40;

	const int width = p->Width - offsetX;
	const int height = p->Height - offsetY;

	const int dx = width / X;
	const int dy = height / (maxV-minV);

	const int h = 20;
	const int d = 15;

	const int n = width / h + 1;
	const int m = height / h + 1;

	//Markup
	for (int i = 0; i < n; i++)
		if (i % 5 == 0)
			g->DrawLine(gcnew Pen(Color::LightGray, 1), i*h + offsetX, 0, i*h + offsetX, p->Height - offsetY + d);
		else g->DrawLine(gcnew Pen(Color::LightGray, 1), i*h + offsetX, 0, i*h + offsetX, p->Height - offsetY);
	for (int i = 0; i < m; i++)
		if (i % 5 == 0)
			g->DrawLine(gcnew Pen(Color::LightGray, 1), 0 + offsetX-d, p->Height-(i*h+offsetY), p->Width+offsetX, p->Height-(i*h+offsetY));
		else g->DrawLine(gcnew Pen(Color::LightGray, 1), 0 + offsetX, p->Height - (i*h + offsetY), p->Width + offsetX, p->Height - (i*h + offsetY));

	//Drawing
	Pen^ pen = gcnew Pen(Color::Red, 2);

	for (int i = 0; i < table->GetSize() - 1; i++) {
		g->DrawLine(pen, (int)(*table)[i].xi*dx + offsetX, p->Height - ((int)((*table)[i].viItog - minV)*dy + offsetY), (int)(*table)[i + 1].xi*dx + offsetX, p->Height - ((int)((*table)[i + 1].viItog - minV)*dy + offsetY));
	}
}

