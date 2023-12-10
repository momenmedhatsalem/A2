//---------------------------------------------------------------------------

#include <fmx.h>

#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
Machine machine;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TForm1::AddButtonClick(TObject *Sender)
{
	if(Input->Text == "")
	{
	return;
	}
	ListBox->Items->Add( Input->Text.c_str());
	Input->Text = "";

}
//---------------------------------------------------------------------------


void __fastcall TForm1::RunAllClick(TObject *Sender)
{

	for( auto i : ListBox->Items)
	{


		machine.Rad_append (string(AnsiString(i).c_str()));
		machine.run_all();


	}

	for( auto x : machine.m.getMemory())
		{
		ListBox2->Items->Add( x.second);

		}
		for( auto x : machine.R.getMemory())
		{
		ListBox3->Items->Add( x.second);

		}
									  }
//---------------------------------------------------------------------------



void __fastcall TForm1::RunNextInstructionClick(TObject *Sender)
{


machine.executeNextInstruction() ;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Display_buttonClick(TObject *Sender)
{
		   ListBox2->Items->Clear() ;
		   ListBox3->Items->Clear() ;
		for( auto x : machine.m.getMemory())
		{
		ListBox2->Items->Add(x.second);

		}
		for( auto x : machine.R.getMemory())
		{
		ListBox3->Items->Add( x.second);

		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Read_dataClick(TObject *Sender)
{
machine.instructions .clear();
				for( auto i : ListBox->Items)
	{


		machine.Rad_append (string(AnsiString(i).c_str()));



	}
}
//---------------------------------------------------------------------------

