/*
 * $Revision: 3833 $
 *
 * last checkin:
 *   $Author: gutwenger $
 *   $Date: 2013-11-13 11:23:15 +0100 (Wed, 13 Nov 2013) $
 ***************************************************************/

/** \file
 * \brief Declaration of class GreedySwitchHeuristic
 *
 * \author Till Sch&auml;fer
 *
 * \par License:
 * This file is part of the Open Graph Drawing Framework (OGDF).
 *
 * \par
 * Copyright (C)<br>
 * See README.txt in the root directory of the OGDF installation for details.
 *
 * \par
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * Version 2 or 3 as published by the Free Software Foundation;
 * see the file LICENSE.txt included in the packaging of this file
 * for details.
 *
 * \par
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * \par
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 * \see  http://www.gnu.org/copyleft/gpl.html
 ***************************************************************/


#ifdef _MSC_VER
#pragma once
#endif

#ifndef OGDF_GREEDY_SWITCH_HEURISTIC_H
#define OGDF_GREEDY_SWITCH_HEURISTIC_H


#include <ogdf/module/LayerByLayerSweep.h>
#include <ogdf/layered/CrossingsMatrix.h>


namespace ogdf
{


//! The greedy-switch heuristic for 2-layer crossing minimization.
class OGDF_EXPORT GreedySwitchHeuristic : public LayerByLayerSweep
{
public:
	//! Creates a new instance of the greedy-switch heuristic.
	GreedySwitchHeuristic() { }

	//! Creates a new instance of the greedy-switch heuristic.
	GreedySwitchHeuristic(const GreedySwitchHeuristic &crossMin) { }

	//! Returns a new instance of the greed-switch heuristic with the same option settings.
	LayerByLayerSweep *clone() const { return new GreedySwitchHeuristic; }

	//! Initializes crossing minimization for hierarchy \a H.
	void init (const HierarchyLevels &levels);

	//! Calls the greedy switch heuristic for level \a L.
	void call (Level &L);

	//! Does some clean-up after calls.
	void cleanup ();

private:
	CrossingsMatrix *m_crossingMatrix;
};


} // end namespace ogdf

#endif
