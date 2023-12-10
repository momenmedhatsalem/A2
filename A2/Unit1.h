//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <string>
#include "D:\Cs uni\Semester 3\CS213\Assignments\A2\A2_Task3_AllB_20221258.cpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Input;
	TButton *AddButton;
	TListBox *ListBox;
	TListBox *ListBox2;
	TButton *RunNextInstruction;
	TButton *RunAll;
	TListBox *ListBox3;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Display_button;
	TButton *Read_data;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall RunAllClick(TObject *Sender);
	void __fastcall RunNextInstructionClick(TObject *Sender);
	void __fastcall Display_buttonClick(TObject *Sender);
	void __fastcall Read_dataClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
