/*
 * $Revision: 3188 $
 *
 * last checkin:
 *   $Author: gutwenger $
 *   $Date: 2013-01-10 09:53:32 +0100 (Thu, 10 Jan 2013) $
 ***************************************************************/

/** \file
 * \brief Declaration of class MaximalPlanarSubgraphSimple
 *
 * \author Carsten Gutwenger
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


#ifndef OGDF_MAXIMAL_PLANAR_SUBGRAPH_SIMPLE_H
#define OGDF_MAXIMAL_PLANAR_SUBGRAPH_SIMPLE_H




#include <ogdf/module/PlanarSubgraphModule.h>


namespace ogdf {

//---------------------------------------------------------
// MaximalPlanarSubgraphSimple
// implements a maximal planar subgraph algorithm using
// planarity testing
//---------------------------------------------------------
class OGDF_EXPORT MaximalPlanarSubgraphSimple : public PlanarSubgraphModule
{
public:
	//! Creates an instance of the maximal planar subgraph simple algorithm with default settings.
	MaximalPlanarSubgraphSimple();

	//! Creates an instance of the maximal planar subgraph simple algorithm with the same settings as \a mps.
	MaximalPlanarSubgraphSimple(const MaximalPlanarSubgraphSimple &mps);

	//! Destructor
	~MaximalPlanarSubgraphSimple() { }

	//! Returns a new instance of maximal planar subgraph simple with the same option settings.
	virtual PlanarSubgraphModule *clone() const;

	//! Assignment operator. Copies option settings only.
	MaximalPlanarSubgraphSimple &operator=(const MaximalPlanarSubgraphSimple &mps);


protected:
	// computes set of edges delEdges, which have to be deleted
	// in order to get a planar subgraph; edges in preferedEdges
	// should be contained in planar subgraph
	ReturnType doCall(const Graph &G,
		const List<edge> &preferedEdges,
		List<edge> &delEdges,
		const EdgeArray<int>  *pCost,
		bool preferedImplyPlanar);
};


} // end namespace ogdf

#endif
