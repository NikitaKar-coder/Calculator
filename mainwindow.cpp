#include "mainwindow.h"
#include <iomanip>
#include <sstream>


using namespace std;
template <class Val>

string ToString(Val val, size_t decimal_digits = 2)
{
ostringstream oss;
    oss << fixed << setprecision(decimal_digits) << val << ends;
    return oss.str();
}
void MainWindow::OnButtonClick(wxCommandEvent & event)
{
    try{
    if(combo_box->GetValue() == "+"){
    ans->SetValue(wxString::Format(wxT("%f"), (stod(std::string(Entry_I -> GetValue().mb_str())) + (stod(std::string(Entry_II -> GetValue().mb_str()))))));
    } else if(combo_box->GetValue() == "-"){
        ans->SetValue(wxString::Format(wxT("%f"), (stod(std::string(Entry_I -> GetValue().mb_str())) - (stod(std::string(Entry_II -> GetValue().mb_str()))))));
    }else if (combo_box->GetValue() == "*"){
        ans->SetValue(wxString::Format(wxT("%f"), (stod(std::string(Entry_I -> GetValue().mb_str())) * (stod(std::string(Entry_II -> GetValue().mb_str()))))));
    }else if (combo_box->GetValue() == "/"){
        ans->SetValue(wxString::Format(wxT("%f"), (stod(std::string(Entry_I -> GetValue().mb_str())) / (stod(std::string(Entry_II -> GetValue().mb_str()))))));
    }else if (strcmp(combo_box->GetValue(), "Возведение в степень")){
        ans->SetValue(wxString::Format(wxT("%f"), pow((stod(std::string(Entry_I -> GetValue().mb_str()))), (stod(std::string(Entry_II -> GetValue().mb_str()))))));
        }
    } catch (exception){
        ans ->SetValue("Error!");
        }
}


MainWindow::MainWindow(const wxString& title, int width, int height)
  : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(width, height))
{
wxArrayString strings;
strings.Add(wxT("+"));
strings.Add(wxT("-"));
strings.Add(wxT("*"));
strings.Add(wxT("/"));
strings.Add(wxT("Возведение в степень"));


    
  Centre();
  panel_ans = new wxPanel(this, wxID_ANY);
  Result_is = new wxTextCtrl(panel_ans, wxID_ANY, wxString(""), wxPoint(5, 30), wxSize(90, 25));
  Result_is -> SetValue(wxString::FromUTF8("Результат:"));
  ans = new wxTextCtrl(panel_ans, wxID_ANY, wxString(""), wxPoint(95, 30), wxSize(230, 25));
  Entry_I = new wxTextCtrl(panel_ans, wxID_ANY, wxString(""), wxPoint(5, 5), wxSize(80, 25));
  Entry_II = new wxTextCtrl(panel_ans, wxID_ANY, wxString(""), wxPoint(165, 5), wxSize(80, 25));
    get_ans_button = new wxButton(panel_ans, wxID_ANY, wxT("="), 
                          wxPoint(245,5), wxSize(80, 25));
    combo_box = new wxComboBox(panel_ans, wxID_ANY, wxString(""), wxPoint(85, 5), wxSize(80, 25), strings);
    get_ans_button->Bind(wxEVT_BUTTON, &MainWindow::OnButtonClick, this);
    


}