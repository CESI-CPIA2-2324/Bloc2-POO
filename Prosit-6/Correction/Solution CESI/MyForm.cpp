//#include "pch.h"
//
//using namespace System;
//using namespace System::Windows::Forms;
//#include "MyForm.h"
//
//
//[STAThreadAttribute]
//int __clrcall WinMain(array<String^>^ args)
//{
//    Application::EnableVisualStyles();
//    Application::SetCompatibleTextRenderingDefault(false);
//    EIA2MININFPOOP6::MyForm mainFRM;
//    Application::Run(% mainFRM);
//}
//
//
#include "pch.h"

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