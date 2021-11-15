// ---- Declaring methods and fields of the MyForm.h file (Header file) ----

    // Fields:
    private: double a, b, h;
    private: double x, y;

    // Button click handlers (need to be created by clicking on the buttons!)
    private: System::Void построитьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void очиститьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    // Additional method
    private: void DefaultParams();
// ---- ----

// ---- File Data MyForm.cpp (Executable file) ----
#include "MyForm.h"

// Required namespaces
using namespace System;
using namespace System::Windows::Forms;

// Application entry point
[STAThreadAttribute]
void main(array<String^>^ args) {
    // Initial Application Parameters:
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // ChartCPP - name of your project / namespace of your project
    // MyFormMyForm - name of the form to launch
    ChartCPP::MyForm form;
    Application::Run(% form);
}

System::Void ChartCPP::MyForm::построитьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_cos->Checked == false && checkBox_sin->Checked == false) {
        MessageBox::Show("Выберите хотя бы один график!","Внимание!");
        return;
    }

    if (textBox_a->Text == "" || textBox_b->Text == "" || textBox_h->Text == "") {
        MessageBox::Show("Параметры по умолчанию!","Внимание!");
        DefaultParams();
    }
    else {
        a = Convert::ToDouble(textBox_a->Text);
        b = Convert::ToDouble(textBox_b->Text);
        h = Convert::ToDouble(textBox_h->Text);
    }

    if (checkBox_cos->Checked) {
        x = a;
        this->chart->Series[0]->Points->Clear();
        while (x <= b)
        {
            y = Math::Cos(x);
            this->chart->Series[0]->Points->AddXY(x, y);
            x += h;
        }
    }

    if (checkBox_sin->Checked) {
        x = a;
        this->chart->Series[1]->Points->Clear();
        while (x <= b)
        {
            y = Math::Sin(x);
            this->chart->Series[1]->Points->AddXY(x, y);
            x += h;
        }
    }    
}

System::Void ChartCPP::MyForm::очиститьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (checkBox_cos->Checked == false && checkBox_sin->Checked == false) {
        MessageBox::Show("Выберите хотя бы один график!", "Внимание!");
        return;
    }

    if (checkBox_cos->Checked) {
        this->chart->Series[0]->Points->Clear();
    }

    if (checkBox_sin->Checked) {
        this->chart->Series[1]->Points->Clear();
    }
}

System::Void ChartCPP::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MessageBox::Show("Выйти?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
        Application::Exit();
   }
}

void ChartCPP::MyForm::DefaultParams()
{
    a = -10;
    b = 10;
    h = 0.1;
}
// ---- ----
