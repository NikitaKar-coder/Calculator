#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <wx/wx.h>
class MainWindow : public wxFrame
{
public:
  MainWindow(const wxString& title, int width, int height);
  
private:
  wxPanel * panel_ans; 
  wxTextCtrl * Entry_I;
  wxTextCtrl * Entry_II;
  wxTextCtrl * Result_is;
  wxButton * get_ans_button;
  wxComboBox * combo_box;
  wxTextCtrl * ans;
  void OnButtonClick(wxCommandEvent & event);
  
};

#endif