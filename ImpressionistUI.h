//
// impressionistUI.h
//
// The header file for the UI part
//

#ifndef ImpressionistUI_h
#define ImpressionistUI_h

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_file_chooser.H>		// FLTK file chooser
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Value_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>

#include "Impressionist.h"
#include "OriginalView.h"
#include "PaintView.h"

#include "ImpBrush.h"

class ImpressionistUI {
public:
	ImpressionistUI();


	// The FLTK widgets
	Fl_Window*			m_mainWindow;
	Fl_Menu_Bar*		m_menubar;
								
	PaintView*			m_paintView;
	OriginalView*		m_origView;

// for brush dialog
	Fl_Window*			m_brushDialog;
	Fl_Window*			m_colorDialog;
	Fl_Window*			m_dissolveDialog;
	Fl_Window*			m_backgroundDialog;

	Fl_Choice*			m_BrushTypeChoice;
	Fl_Choice*			m_AngleTypeChoice;
	Fl_Choice*			m_AutoTypeChoice; // For autoDraw.


	enum anglemode{
		SLIDER_RIGHT_MOUSE = 0,
		GRADIENT,
		BRUSH_DIRECTION,
		FOLLOW_ANOTHER_IMAGE
	};

	enum automode {
		REGULAR = 0, //It is called sequential on the UI.
		RANDOM
	};

	Fl_Slider*			m_BrushSizeSlider;
	Fl_Slider*			m_BrushWidthSlider;
	Fl_Slider*			m_BrushAngleSlider;
	Fl_Slider*			m_BrushAlphaSlider;
	Fl_Slider*			m_EdgeThresholdSlider;
	Fl_Slider*			m_DissolveAlphaSlider;
	Fl_Slider*			m_backgroundAlphaSlider;

	Fl_Button*          m_ClearCanvasButton;
	Fl_Button*          m_autoPaintButton;
	Fl_Button*          m_multiResPaintButton;
	Fl_Button*          m_edgePaintButton;
	Fl_Button*          m_applyDissolveButton;
	Fl_Button*          m_importDissolveImgButton;
	//color control
	Fl_Slider*			m_redSlider;
	Fl_Slider*			m_greenSlider;
	Fl_Slider*			m_blueSlider;



	// Member functions
	void				setDocument(ImpressionistDoc* doc);
	ImpressionistDoc*	getDocument();

	void				show();
	void				resize_windows(int w, int h);

	// Interface to get attribute

	int					getSize();
	void				setSize(int size);

	int					getWidth();
	void				setWidth(int width);

	int					getAngle();
	void				setAngle(int angle);

	float               getAlpha();
	void                setAlpha(float alpha);

	float               getDissolveAlpha();
	void                setDissolveAlpha(float alpha);

	float               getBackgroundAlpha();
	void                setBackgroundAlpha(float alpha);

	int					getRed();
	int					getGreen();
	int					getBlue();

	bool				getColorControlMode();

	int					getEdgeThreshold();

	
	private:
	ImpressionistDoc*	m_pDoc;		// pointer to document to communicate with the document

	// All attributes here
	int		m_nSize;
	int     m_nWidth;
	int     m_nAngle;
	float     m_nAlpha;
	int		m_nEdgeThreshold;
	float	m_nDissolveAlpha;
	float	m_nbackgroundAlpha;


	int m_nRed, m_nGreen, m_nBlue;


	// This value will be true if the color is determined using color panel. 
	bool m_nManualColorControl = false;



	// Static class members
	static Fl_Menu_Item		menuitems[];
	static Fl_Menu_Item		brushTypeMenu[NUM_BRUSH_TYPE+1];
	static Fl_Menu_Item     AngleTypeMenu[];
	static Fl_Menu_Item     AutoTypeMenu[];

	static ImpressionistUI*	whoami(Fl_Menu_* o);

	// All callbacks here.  Callbacks are declared 
	// static
	static void	cb_load_image(Fl_Menu_* o, void* v);
	static void	cb_load_mural_image(Fl_Menu_* o, void* v);
	static void	cb_save_image(Fl_Menu_* o, void* v);
	static void	cb_brushes(Fl_Menu_* o, void* v);
	static void	cb_clear_canvas(Fl_Menu_* o, void* v);
	static void	cb_Color(Fl_Menu_* o, void* v);
	static void	cb_load_grad(Fl_Menu_* o, void* v);
	static void	cb_load_alpha(Fl_Menu_* o, void* v);
	static void	cb_exit(Fl_Menu_* o, void* v);
	static void	cb_undo(Fl_Menu_* o, void* v);
	static void	cb_dissolve(Fl_Menu_* o, void* v);
	static void	cb_swap(Fl_Menu_* o, void* v);
	static void	cb_about(Fl_Menu_* o, void* v);
	static void cb_background(Fl_Menu_* o, void* v);
	static void	cb_brushChoice(Fl_Widget* o, void* v);
	static void cb_angleChoice(Fl_Widget* o, void* v);
	static void	cb_clear_canvas_button(Fl_Widget* o, void* v);
	static void	cb_sizeSlides(Fl_Widget* o, void* v);
	static void	cb_widthSlides(Fl_Widget* o, void* v);
	static void	cb_angleSlides(Fl_Widget* o, void* v);
	static void	cb_alphaSlides(Fl_Widget* o, void* v);
	static void	cb_edgeThresholdSlides(Fl_Widget* o, void* v);
	static void	cb_DissolveAlphaSlides(Fl_Widget* o, void* v);
	static void	cb_backgroundAlphaSlides(Fl_Widget* o, void* v);
	static void	cb_redSlides(Fl_Widget* o, void* v);
	static void	cb_greenSlides(Fl_Widget* o, void* v);
	static void	cb_blueSlides(Fl_Widget* o, void* v);
	static void cb_auto_paint_button(Fl_Widget* o, void* v);
	static void cb_autoChoice(Fl_Widget* o, void* v);
	static void cb_multi_res_paint_button(Fl_Widget* o, void* v);
	static void cb_edge_paint_button(Fl_Widget* o, void* v);
	static void cb_importDissolveImg(Fl_Widget* o, void* v);
	static void cb_applyDissolve(Fl_Widget* o, void* v);
};

#endif
