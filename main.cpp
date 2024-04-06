#include "main.h"
#include "mainwindow.h"
IMPLEMENT_APP(MyApp)
bool MyApp::OnInit()
{
  MainWindow *mainWindow = new MainWindow(wxT("Calculator"), 330, 60);
  mainWindow->Show(true);

  return true;
}
