// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

/*! \file cursorsdlg.h
 *  \author Christoph Schmidt-Hieber
 *  \date 2008-01-16
 *  \brief Declares wxStfCursorsDlg.
 */

#ifndef _CURSORSDLG_H
#define _CURSORSDLG_H

/*! \addtogroup wxstf
 *  @{
 */

#include "./../../core/stimdefs.h"
#include "wx/bookctrl.h"

class wxStfDoc;

//! Cursor settings non-modal dialog
class StfDll wxStfCursorsDlg : public wxDialog
{
    DECLARE_EVENT_TABLE()

private:
    wxNotebookPage* CreateMeasurePage();
    wxNotebookPage* CreatePeakPage();
    wxNotebookPage* CreateBasePage();
    wxNotebookPage* CreateDecayPage();
    wxNotebookPage* CreatePSlopePage();
    wxFlexGridSizer*
        CreateCursorInput( wxPanel* nbPage, wxWindowID textC1, wxWindowID textC2,
                           wxWindowID comboU1, wxWindowID comboU2, std::size_t c1,
                           std::size_t c2 );

    int ReadCursor(wxWindowID textId, bool isTime) const;
    int ReadDeltaT(wxWindowID textId) const;
    void UpdateUnits(wxWindowID comboId, bool& setTime, wxWindowID textID);
    bool cursorMIsTime,
    cursor1PIsTime,cursor2PIsTime,
    cursor1BIsTime,cursor2BIsTime,
    cursor1DIsTime,cursor2DIsTime,
    cursor1PSIsTime,cursor2PSIsTime;

    wxStfDoc* actDoc;
    wxNotebook* m_notebook;

    void OnPageChanged( wxNotebookEvent& event );
    void OnComboBoxUM( wxCommandEvent& event );
    void OnComboBoxU1P( wxCommandEvent& event );
    void OnComboBoxU2P( wxCommandEvent& event );
    void OnComboBoxU1B( wxCommandEvent& event );
    void OnComboBoxU2B( wxCommandEvent& event );
    void OnComboBoxU1D( wxCommandEvent& event );
    void OnComboBoxU2D( wxCommandEvent& event );
    void OnComboBoxU1PS( wxCommandEvent& event );
    void OnComboBoxU2PS( wxCommandEvent& event );

    void OnRadioPSManBeg( wxCommandEvent& event );
    void OnRadioPSEventBeg( wxCommandEvent& event );
    void OnRadioPSThrBeg( wxCommandEvent& event );
    void OnRadioPSt50Beg( wxCommandEvent& event );

    void OnRadioPSManEnd( wxCommandEvent& event );
    void OnRadioPSt50End( wxCommandEvent& event );
    void OnRadioPSDeltaT( wxCommandEvent& event );
    void OnRadioPSPeakEnd( wxCommandEvent& event );

    void OnRadioAll( wxCommandEvent& event );
    void OnRadioMean( wxCommandEvent& event );
    void OnPeakcalcexec( wxCommandEvent& event );
    void OnBasetoslope( wxCommandEvent& event );
    
    //! Only called when a modal dialog is closed with the OK button.
    /*! \return true if all dialog entries could be read successfully
     */
    bool OnOK();

public:
    //! Constructor
    /*! \param parent Pointer to parent window.
     *  \param initDoc Pointer to the document the call originated from.
     *  \param id Window id.
     *  \param title Dialog title.
     *  \param pos Initial position.
     *  \param size Initial size.
     *  \param style Dialog style.
     */
    wxStfCursorsDlg( wxWindow* parent, wxStfDoc* initDoc, int id = wxID_ANY,
                     wxString title = wxT("Cursor settings"), wxPoint pos = wxDefaultPosition,
                     wxSize size = wxDefaultSize, int style = wxCAPTION );

    //! Called upon ending a modal dialog.
    /*! \param retCode The dialog button id that ended the dialog
     *         (e.g. wxID_OK)
     */
    virtual void EndModal(int retCode);

    //! Called when data should be transferred from the non-modal dialog (e.g. when OK is pressed)
    /*! Note that a non-modal dialog won't be destroyed when OK is clicked,
     *  it will only disappear from sight. This function will then apply the current
     *  cursor settings and update the results table.
     *  \return The return value of the base class version wxWindow::TransferDataFromWindow()
     */
    virtual bool TransferDataFromWindow();

    //! Get the measurement cursor x-position
    /*! \return The measurement cursor x-position in units of sampling points.
     */
    int GetCursorM() const;

    //! Get the left peak cursor x-position
    /*! \return The left peak cursor x-position in units of sampling points.
     */
    int GetCursor1P() const;

    //! Get the right peak cursor x-position
    /*! \return The right peak cursor x-position in units of sampling points.
     */
    int GetCursor2P() const;

    //! Get the left base cursor x-position
    /*! \return The left base cursor x-position in units of sampling points.
     */
    int GetCursor1B() const;

    //! Get the right base cursor x-position
    /*! \return The right base cursor x-position in units of sampling points.
     */
    int GetCursor2B() const;

    //! Get the left fit cursor x-position
    /*! \return The left fit cursor x-position in units of sampling points.
     */
    int GetCursor1D() const;

    //! Get the right fit cursor x-position
    /*! \return The right fit cursor x-position in units of sampling points.
     */
    int GetCursor2D() const;

    //! Get the left PSlope cursor x-position
    /*! \return The left fit cursor x-position in units of sampling points.
     */
    int GetCursor1PS() const;

    //! Get the right PSlope cursor x-position
    /*! \return The right fit cursor x-position in units of sampling points.
     */
    int GetCursor2PS() const;

    //! Gets the number of points used for the binned average during peak detection.
    /*! \return The number of points used for the binned average during peak detection.
     */

    int GetPeakPoints() const;

    //! Sets the number of points used for the binned average during peak detection.
    /*! \param peakPoints The number of points used for the binned average during peak detection.
     */
    void SetPeakPoints(int peakPoints);

    //! Gets the distance to the first PSlope cursor in number of points.
    /*! \return The distance to the first PSlope cursor in number of points. 
     */
    int GetDeltaT() const;

    //! Sets the number of points used for the distance from the first PSlope cursor.
    /*! \param peakPoints The number of points used for the distance from the first PSlope cursor.
     */
    void SetDeltaT(int DeltaT);

    //! Gets the direction of peak calculations.
    /*! \return The current direction of peak calculations.
     */
    stf::direction GetDirection() const;

    //! Gets the mode of measure for the beginning of the slope cursor.
    /*! \return The current mode for the beginning slope cursor.
     */
    stf::pslope_mode_beg GetPSlopeBegMode() const;

    //! Gets the mode of measure for the end of the slope cursor.
    /*! \return The current mode for the end slope cursor.
     */
    stf::pslope_mode_end GetPSlopeEndMode() const;

    //! Indicates whether to use the baseline as a reference for AP kinetics.
    /*! \return true if the baseline should be used, false if the threshold should be used.
     */
    bool GetFromBase() const;
    
    //! Sets the direction of peak calculations.
    /*! \param direction The new direction of peak calculations.
     */
    void SetDirection(stf::direction direction);

    //! Sets the mode of the right slope cursor.
    /*! \param pslopeEndMode The new mode for the slope cursor.
     */
    void SetPSlopeEndMode(stf::pslope_mode_end pslopeEndMode);

    //! Sets the mode of the left slope cursor.
    /*! \param pslopeBegMode The new mode for the slope cursor.
     */
    void SetPSlopeBegMode(stf::pslope_mode_beg pslopeBegMode);

    //! Sets the reference for AP kinetics measurements.
    /*! \param frombase true if the baseline should be used, false if the threshold should be used.
     */
    void SetFromBase(bool frombase);
    
    //! Indicates whether the right peak cursor should always be at the end of the trace.
    /*! \return true if the peak cursor should always be at the end of the trace.
     */
    bool GetPeakAtEnd() const;

    //! Indicates whether to always start a fit at the current peak position.
    /*! \return true if the fit should always be started at the current peak position.
     */
    bool GetStartFitAtPeak() const;

    //! Updates the cursor entries in the Cursors Settings menu.
    void UpdateCursors();

    //! Retrieve the current cursor notebook page.
    /*! \return The cursor corresponding to the currently selected notebook page.
     */
    stf::cursor_type CurrentCursor() const;

    //! Get the slope at which the baseline should be fixed.
    /*! \return The slope at which the baseline should be fixed.
     */
    double GetSlope() const;

    //! Set the threshold slope.
    /*! \param slope The new threshold slope.
     */
    void SetSlope( double slope );

    //! Set the units of the slope.
    /*! \param units The units of the slope.
     */
    void SetSlopeUnits(const wxString& units);

    //! Indicates whether the baseline should be fixed to a certain slope.
    /*! \return true if the baseline should be fixed, false otherwise.
     */
    bool GetBaseToSlope() const;

    //! Indicates whether an additional vertical ruler should be drawn through the baseline.
    /*! \return true if an additional ruler should be drawn.
     */
    bool GetRuler() const;

    //! Sets the currently active document.
    /*! \param actDoc_ A pointer to the currently active document.
     */
    void SetActiveDoc(wxStfDoc* actDoc_) { actDoc = actDoc_; }
};

/* @} */

#endif

