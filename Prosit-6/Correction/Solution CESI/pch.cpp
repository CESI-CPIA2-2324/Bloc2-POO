
#include "pch.h"


// pch.cpp: Quelldatei, die dem vorkompilierten Header entspricht


// Bei der Verwendung vorkompilierter Header ist diese Quelldatei für eine erfolgreiche Kompilierung erforderlich.

using namespace System;

//int main(array<System::String ^> ^args)
//{
//    return 0;
//}

#include "MyForm.h"

using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew EIA2MININFPOOP6::MyForm());
	return 0;
}