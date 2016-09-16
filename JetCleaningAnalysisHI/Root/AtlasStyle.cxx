#include "JetCleaningAnalysisHI/AtlasStyle.h"

void UseAtlasStyleCustom()
{  
   //@UseAtlasStyleCustomOld_begin

   // my addings:
   gStyle->SetPalette(1,0);
   gStyle->SetPaintTextFormat("4.2f");
   gStyle->SetTitleOffset(1.3,"y");

   // use plain black on white colors
   Int_t icol=0;
   gStyle->SetFrameBorderMode(icol);
   gStyle->SetCanvasBorderMode(icol);
   gStyle->SetPadBorderMode(icol);
   gStyle->SetPadColor(icol);
   gStyle->SetCanvasColor(icol);
   gStyle->SetStatColor(icol);
   //gStyle->SetFillColor(icol);

   gStyle->SetCanvasDefH(600);
   gStyle->SetCanvasDefW(700);
   
   // set the paper & margin sizes
   gStyle->SetPaperSize(20,26);	// 20, 26
   gStyle->SetPadTopMargin(0.04);
   gStyle->SetPadRightMargin(0.12);	// 0.15
   gStyle->SetPadBottomMargin(0.12);
   gStyle->SetPadLeftMargin(0.15);	

   // use large fonts
   //Int_t font=72;
   Int_t font=42;
   Double_t tsize=0.05;
   gStyle->SetTextFont(font);
   
   
   gStyle->SetTextSize(tsize);
   gStyle->SetLabelFont(font,"x");
   gStyle->SetTitleFont(font,"x");
   gStyle->SetLabelFont(font,"y");
   gStyle->SetTitleFont(font,"y");
   gStyle->SetLabelFont(font,"z");
   gStyle->SetTitleFont(font,"z");
   
   gStyle->SetLabelSize(tsize,"x");
   gStyle->SetTitleSize(tsize,"x");
   gStyle->SetLabelSize(tsize,"y");
   gStyle->SetTitleSize(tsize,"y");
   gStyle->SetLabelSize(tsize,"z");
   gStyle->SetTitleSize(tsize,"z");
   
   
   //use bold lines and markers
   gStyle->SetMarkerStyle(20);
   gStyle->SetMarkerSize(1.2); //1.2
   gStyle->SetHistLineWidth(2.);
   gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
   
   //get rid of X error bars and y error bar caps
   gStyle->SetErrorX(0.001);
   
   //do not display any of the standard histogram decorations
   gStyle->SetOptTitle(0);
   //gStyle->SetOptStat(1111);
   gStyle->SetOptStat(0);

   gStyle->SetStatFontSize(0.03);
   gStyle->SetFitFormat("2.2f");
   gStyle->SetStatX(0.8);
   gStyle->SetStatY(0.9);
   //gStyle->SetStatW(0.3);
   //gStyle->SetStatH(0.3);
   //gStyle->SetOptFit(11);
   gStyle->SetOptFit(0);
   
   // put tick marks on top and RHS of plots
//   gStyle->SetPadTickX(1);
//   gStyle->SetPadTickY(1);
   
//@!   gROOT->SetStyle("Plain");
   
   //gStyle->SetPadTickX(1);
   //gStyle->SetPadTickY(1);

   // my other addings concerning the broken offset of label on x-axis
   gStyle->SetTitleOffset(1.1,"x");
   gStyle->SetTitleXOffset(1.1);
   // but styl -- for some reason it does not work

   //@UseAtlasStyleCustomOld_end
}


void UseAtlasStyleForTwoPads()
{  
   // my addings:
   gStyle->SetPalette(1,0);
   gStyle->SetPaintTextFormat("4.2f");
   gStyle->SetTitleOffset(1.3,"y");

   // use plain black on white colors
   Int_t icol=0;
   gStyle->SetFrameBorderMode(icol);
   gStyle->SetCanvasBorderMode(icol);
   gStyle->SetPadBorderMode(icol);
   gStyle->SetPadColor(icol);
   gStyle->SetCanvasColor(icol);
   gStyle->SetStatColor(icol);
   //gStyle->SetFillColor(icol);
   
   // set the paper & margin sizes
   //gStyle->SetPaperSize(20,26);
   //gStyle->SetPadTopMargin(0.05);
   //gStyle->SetPadRightMargin(0.15);
   gStyle->SetPadBottomMargin(0.16);
   //gStyle->SetPadLeftMargin(0.15);

   // use large fonts
   //Int_t font=72;
   Int_t font=42;
   Double_t tsize=0.05;
   gStyle->SetTextFont(font);
   
   
   gStyle->SetTextSize(tsize);
   gStyle->SetLabelFont(font,"x");
   gStyle->SetTitleFont(font,"x");
   gStyle->SetLabelFont(font,"y");
   gStyle->SetTitleFont(font,"y");
   gStyle->SetLabelFont(font,"z");
   gStyle->SetTitleFont(font,"z");
   
   gStyle->SetLabelSize(tsize,"x");
   gStyle->SetTitleSize(tsize,"x");
   gStyle->SetLabelSize(tsize,"y");
   gStyle->SetTitleSize(tsize,"y");
   gStyle->SetLabelSize(tsize,"z");
   gStyle->SetTitleSize(tsize,"z");
   
   
   //use bold lines and markers
   gStyle->SetMarkerStyle(20);
   gStyle->SetMarkerSize(1.2); //1.2
   gStyle->SetHistLineWidth(2.);
   gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
   
   //get rid of X error bars and y error bar caps
   gStyle->SetErrorX(0.001);
   
   //do not display any of the standard histogram decorations
   gStyle->SetOptTitle(0);
   //gStyle->SetOptStat(1111);
   gStyle->SetOptStat(0);

   gStyle->SetStatFontSize(0.03);
   gStyle->SetFitFormat("2.2f");
   gStyle->SetStatX(0.8);
   gStyle->SetStatY(0.9);
   //gStyle->SetStatW(0.3);
   //gStyle->SetStatH(0.3);
   //gStyle->SetOptFit(11);
   gStyle->SetOptFit(0);
   
   // put tick marks on top and RHS of plots
//   gStyle->SetPadTickX(1);
//   gStyle->SetPadTickY(1);
   
//@!   gROOT->SetStyle("Plain");
   
   //gStyle->SetPadTickX(1);
   //gStyle->SetPadTickY(1);

   // my other addings concerning the broken offset of label on x-axis
   gStyle->SetTitleOffset(1.1,"x");
   gStyle->SetTitleXOffset(1.1);
   // but styl -- for some reason it does not work

   //@UseAtlasStyleCustomOld_end
}



void UseAtlasStyleFirst()
{
   //TStyle *atlasStyle= new TStyle("ATLAS","Atlas style");
   
   // use plain black on white colors
   Int_t icol=0;
   gStyle->SetFrameBorderMode(icol);
   gStyle->SetCanvasBorderMode(icol);
   gStyle->SetPadBorderMode(icol);
   gStyle->SetPadColor(icol);
   gStyle->SetCanvasColor(icol);
   gStyle->SetStatColor(icol);
   //gStyle->SetFillColor(icol);
   
   // set the paper & margin sizes
   gStyle->SetPaperSize(20,26);
   gStyle->SetPadTopMargin(0.05);
   gStyle->SetPadRightMargin(0.05);
   gStyle->SetPadBottomMargin(0.16);
   gStyle->SetPadLeftMargin(0.12);
   
   // use large fonts
   //Int_t font=72;
   Int_t font=42;
   Double_t tsize=0.05;
   gStyle->SetTextFont(font);
   
   
   gStyle->SetTextSize(tsize);
   gStyle->SetLabelFont(font,"x");
   gStyle->SetTitleFont(font,"x");
   gStyle->SetLabelFont(font,"y");
   gStyle->SetTitleFont(font,"y");
   gStyle->SetLabelFont(font,"z");
   gStyle->SetTitleFont(font,"z");
   
   gStyle->SetLabelSize(tsize,"x");
   gStyle->SetTitleSize(tsize,"x");
   gStyle->SetLabelSize(tsize,"y");
   gStyle->SetTitleSize(tsize,"y");
   gStyle->SetLabelSize(tsize,"z");
   gStyle->SetTitleSize(tsize,"z");
   
   
   //use bold lines and markers
   gStyle->SetMarkerStyle(20);
   gStyle->SetMarkerSize(1.2);
   gStyle->SetHistLineWidth(2.);
   gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
   
   //get rid of X error bars and y error bar caps
   //gStyle->SetErrorX(0.001);
   
   //do not display any of the standard histogram decorations
   gStyle->SetOptTitle(0);
   //gStyle->SetOptStat(1111);
   gStyle->SetOptStat(0);
   //gStyle->SetOptFit(1111);
   gStyle->SetOptFit(0);
   
   // put tick marks on top and RHS of plots
   gStyle->SetPadTickX(1);
   gStyle->SetPadTickY(1);
   
//@!?   gROOT->SetStyle("Plain");
   
   //gStyle->SetPadTickX(1);
   //gStyle->SetPadTickY(1);


  // Some other possible improvements
/*
   gStyle->SetLineWidth(2.);
   gStyle->SetTextSize(1.1);
   gStyle->SetLabelSize(0.06,"xy");
   gStyle->SetTitleSize(0.06,"xy");
   gStyle->SetTitleOffset(1.2,"x");
   gStyle->SetTitleOffset(1.0,"y");
   gStyle->SetPadTopMargin(0.1);
   gStyle->SetPadRightMargin(0.1);
   gStyle->SetPadBottomMargin(0.16);
   gStyle->SetPadLeftMargin(0.12);
*/

}


void UseAtlasStyle()
{

   //@UseAtlasStyleCustom_begin

   // atlasstyle-00-02-04, 6.2.2010
   // downloaded form https://twiki.cern.ch/twiki/bin/view/AtlasProtected/PubComPlotStyle

   // my changes: atlasStyle -> gStyle
   //

  // use plain black on white colors
  Int_t icol=0; // WHITE
  gStyle->SetFrameBorderMode(icol);
  gStyle->SetFrameFillColor(icol);
  gStyle->SetCanvasBorderMode(icol);
  gStyle->SetCanvasColor(icol);
  gStyle->SetPadBorderMode(icol);
  gStyle->SetPadColor(icol);
  gStyle->SetStatColor(icol);
  //gStyle->SetFillColor(icol); // don't use: white fill color for *all* objects

  // set the paper & margin sizes
  gStyle->SetPaperSize(20,26);

  // set margin sizes
  gStyle->SetPadTopMargin(0.05);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetPadBottomMargin(0.16);
  gStyle->SetPadLeftMargin(0.16);

  // set title offsets (for axis label)
  gStyle->SetTitleXOffset(1.4);
  gStyle->SetTitleYOffset(1.4);

  // use large fonts
  //Int_t font=72; // Helvetica italics
  Int_t font=42; // Helvetica
  Double_t tsize=0.05;
  gStyle->SetTextFont(font);

  gStyle->SetTextSize(tsize);
  gStyle->SetLabelFont(font,"x");
  gStyle->SetTitleFont(font,"x");
  gStyle->SetLabelFont(font,"y");
  gStyle->SetTitleFont(font,"y");
  gStyle->SetLabelFont(font,"z");
  gStyle->SetTitleFont(font,"z");

  gStyle->SetLabelSize(tsize,"x");
  gStyle->SetTitleSize(tsize,"x");
  gStyle->SetLabelSize(tsize,"y");
  gStyle->SetTitleSize(tsize,"y");
  gStyle->SetLabelSize(tsize,"z");
  gStyle->SetTitleSize(tsize,"z");

  // use bold lines and markers
  gStyle->SetMarkerStyle(20);
  gStyle->SetMarkerSize(1.2);
  gStyle->SetHistLineWidth(2.);
  gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes

  // get rid of X error bars
  gStyle->SetErrorX(0.001);
  // get rid of error bar caps
  gStyle->SetEndErrorSize(0.);

  // do not display any of the standard histogram decorations
  gStyle->SetOptTitle(0);
  //gStyle->SetOptStat(1111);
  gStyle->SetOptStat(0);
  //gStyle->SetOptFit(1111);
  gStyle->SetOptFit(0);

  // put tick marks on top and RHS of plots
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);


   //@UseAtlasStyleCustom_end

}
