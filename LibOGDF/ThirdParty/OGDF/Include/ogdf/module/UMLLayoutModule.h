/*
 * $Revision: 3188 $
 *
 * last checkin:
 *   $Author: gutwenger $
 *   $Date: 2013-01-10 09:53:32 +0100 (Thu, 10 Jan 2013) $
 ***************************************************************/

/** \file
 * \brief Declaration of interface for layout algorithms for
 *        UML diagrams.
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

#ifndef OGDF_UML_LAYOUT_MODULE_H
#define OGDF_UML_LAYOUT_MODULE_H


#include <ogdf/uml/UMLGraph.h>


namespace ogdf {


/**
 * \brief Interface of UML layout algorithms.
 */
class OGDF_EXPORT UMLLayoutModule
{
public:
	//! Initializes a UML layout module.
	UMLLayoutModule() { }

	virtual ~UMLLayoutModule() { }

	/**
	 * \brief Computes a layout of UML graph \a umlGraph
	 *
	 * Must be implemented by derived classes.
	 * @param umlGraph is the input UML graph and has to be assigned the UML layout.
	 */
	virtual void call(UMLGraph &umlGraph) = 0;

	/**
	 * \brief Computes a layout of UML graph \a umlGraph
	 *
	 * @param umlGraph is the input UML graph and has to be assigned the UML layout.
	 */
	void operator()(UMLGraph &umlGraph) { call(umlGraph); }

	OGDF_MALLOC_NEW_DELETE
};


} // end namespace ogdf


#endif
