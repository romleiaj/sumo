/****************************************************************************/
// Eclipse SUMO, Simulation of Urban MObility; see https://eclipse.org/sumo
// Copyright (C) 2001-2018 German Aerospace Center (DLR) and others.
// This program and the accompanying materials
// are made available under the terms of the Eclipse Public License v2.0
// which accompanies this distribution, and is available at
// http://www.eclipse.org/legal/epl-v20.html
// SPDX-License-Identifier: EPL-2.0
/****************************************************************************/
/// @file    GNEGenericParameterDialog.h
/// @author  Pablo Alvarez Lopez
/// @date    Jul 2018
/// @version $Id$
///
// Dialog for edit rerouters
/****************************************************************************/
#ifndef GNEGenericParameterDialog_h
#define GNEGenericParameterDialog_h

// ===========================================================================
// included modules
// ===========================================================================

#include <config.h>

#include <utils/common/SUMOVehicleClass.h>

// ===========================================================================
// class definitions
// ===========================================================================

class GNEAttributeCarrier;
class GNEViewNet;

// ===========================================================================
// class definitions
// ===========================================================================

/**
 * @class GNEGenericParameterDialog
 * @brief Dialog for edit rerouters
 */
class GNEGenericParameterDialog : public FXDialogBox {
    /// @brief FOX-declaration
    FXDECLARE(GNEGenericParameterDialog)

public:
    /// @brief Constructor
    GNEGenericParameterDialog(GNEViewNet* viewNet, std::vector<GNEAttributeCarrier::GenericParameter> *genericParameters);

    /// @brief destructor
    ~GNEGenericParameterDialog();

    /// @name FOX-callbacks
    /// @{
    /// @brief event when user press a enable/disable button
    long onCmdSetAttribute(FXObject*, FXSelector, void*);

    /// @brief event after press accept button
    long onCmdAccept(FXObject*, FXSelector, void*);

    /// @brief event after press cancel button
    long onCmdCancel(FXObject*, FXSelector, void*);

    /// @brief event after press reset button
    long onCmdReset(FXObject*, FXSelector, void*);
    /// @}

protected:
    /// @brief FOX needs this
    GNEGenericParameterDialog() {}

    /// @pointer to viewNet
    GNEViewNet* myViewNet;

    /// @brief edited generic parameters
    std::vector<GNEAttributeCarrier::GenericParameter> *myGenericParameters;

    /// @brief accept button
    FXButton* myAcceptButton;

    /// @brief cancel button
    FXButton* myCancelButton;

    /// @brief cancel button
    FXButton* myResetButton;

private:
    /// @brief struct for generic parameters Row
    struct GenericParameterRow {
        /// @brief 
        GenericParameterRow(GNEGenericParameterDialog * genericParametersEditor, FXVerticalFrame* frame);

        /// @brief disable row
        void disableRow();

        /// @brief enable rlow
        void enableRow(const std::string &parameter, const std::string &value) const;

        /// @brief toogle add button
        void toogleAddButton() const;

        /// @brief copy values of other parameter Row
        void copyValues(const GenericParameterRow & other);

        /// @brief TextField for parameter
        FXTextField *parameterField;

        /// @brief TextField for value
        FXTextField *valueField;

        /// @brief Button for remove parameter row
        FXButton *removeButton;

    private:
        /// @brief frame in which elements are placed
        FXHorizontalFrame* horizontalFrame;
    };

    /// @brief vector with the GenericParameterRows
    std::vector<GenericParameterRow> myGenericParameterRows;


    /// @brief Invalidated copy constructor.
    GNEGenericParameterDialog(const GNEGenericParameterDialog&) = delete;

    /// @brief Invalidated assignment operator.
    GNEGenericParameterDialog& operator=(const GNEGenericParameterDialog&) = delete;
};

#endif
