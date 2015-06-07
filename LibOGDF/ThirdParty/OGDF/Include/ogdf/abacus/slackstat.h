/*
 * $Revision: 3386 $
 *
 * last checkin:
 *   $Author: gutwenger $
 *   $Date: 2013-04-10 14:00:02 +0200 (Wed, 10 Apr 2013) $
 ***************************************************************/

/*!\file
 * \author Matthias Elf
 * \brief status of slack variables
 *
 * \par License:
 * This file is part of ABACUS - A Branch And CUt System
 * Copyright (C) 1995 - 2003
 * University of Cologne, Germany
 *
 * \par
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * \par
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * \par
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * \see http://www.gnu.org/copyleft/gpl.html
 */

#ifndef ABA__SLACKSTAT_H
#define ABA__SLACKSTAT_H


#include <ogdf/abacus/abacusroot.h>

namespace abacus {

class AbacusGlobal;


//! Status of slack variables.
/**
 * As for the structural variables the simplex method also assigns
 * a unique status to each slack variable. A slack variable can
 * be a basic or a nonbasic variable. If it is a nonbasic
 * variable, then we distinguish if the slack variable has value
 * zero or nonzero.
 */
class  SlackStat :  public AbacusRoot  {
public:

	//! The different statuses of a slack variable.
	enum STATUS {
		Basic,				//!< The slack variable belongs to the basis.
		NonBasicZero,		//!< The slack variable does not belong to the basis and has value zero.
		NonBasicNonZero,	//!< The slack variable does not belong to the basis and has a nonzero value.
		Unknown				//!< The status of the slack variable is not known since
							//!< no linear program with the corresponding constraint has been solved.
	};

	//! Initializes the status to \a Unknown.
	SlackStat() : status_(Unknown) { }

	//! Initializes the status to \a status.
	/**
	 * \param status The slack variable receives the status \a status.
	 */
	SlackStat(STATUS status) : status_(status) { }

	//! Output operator for slack statuses.
	/**
	 * The output operator writes the status to an output stream in the
	 * format <tt>Basic</tt>, <tt>NonBasicZero</tt>, <tt>NonBasicNonZero</tt>, or
	 * <tt>Unknown</tt>.
	 *
	 * \param out The output stream.
	 * \param rhs The status being output.
	 *
	 * \return A reference to the output stream.
	 */
	friend ostream  &operator<<(ostream& out, const SlackStat &rhs);

	//! Returns the status of the slack variable.
	STATUS status() const { return status_; }


	//! Sets the status of the slack variable to \a stat.
	/**
	 * \param stat The new status of the slack variable.
	 */
	void status(STATUS stat) { status_ = stat; }


	//! Sets the status to the status of \a stat.
	/**
	 * \param stat The status of the slack variable is set to \a *stat.
	 */
	void status(const SlackStat *stat) { status_ = stat->status_; }


private:

	STATUS status_; //!< The status of the slack variable.

	OGDF_NEW_DELETE
};

} //namespace abacus


#endif  // SlackStat_H
