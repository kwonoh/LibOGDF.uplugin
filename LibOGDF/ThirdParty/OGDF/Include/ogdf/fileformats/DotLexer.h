/*
 * $Revision: 3837 $
 *
 * last checkin:
 *   $Author: gutwenger $
 *   $Date: 2013-11-13 15:19:30 +0100 (Wed, 13 Nov 2013) $
 ***************************************************************/

/** \file
 * \brief Declares stuff related to DOT format lexical analysis.
 *
 * \author Łukasz Hanuszczak
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

#ifndef OGDF_DOT_LEXER_H
#define OGDF_DOT_LEXER_H


#include <iostream>
#include <sstream>
#include <vector>


namespace ogdf {

namespace dot {


//! Just a simple token struct representing a DOT file fragment.
/**
 * Each token is represented by type: its either \a special string (a keyword
 * or punctuation character) or identifier (which is \a normal string).
 *
 * Additionaly, each token have its row and column fields indicating where
 * it appeared. This information could be useful for displaying useful debug
 * messages.
 *
 * \sa dot::Lexer
 */
struct Token {

	enum Type {
		// Operators
		assignment, colon, semicolon, comma, edgeOpDirected, edgeOpUndirected,
		// Brackets
		leftBracket, rightBracket,
		leftBrace, rightBrace,
		// Keywords
		graph, digraph, subgraph, node, edge,
		strict,
		// Values
		identifier
	};

	//! The type of an field.
	Type type;
	//! Indicates a token row (line).
	size_t row;
	//! Indicated a token column;
	size_t column;
	//! Identifier content (NULL for non-id tokens).
	std::string *value;

	Token(size_t row, size_t column, std::string *value = NULL);

	//! Returns string representation of given token type.
	static std::string toString(const Type &type);
};


//! Lexical analysis tool.
/**
 * This class reads the given input and generates a token list. Token list
 * representation of DOT file is much easier for further processing (like
 * parsing) as it automatically gets rid of comments and deals with various
 * identifier representations in DOT format (C-like identifier, double-quoted
 * strings, number literals).
 *
 * \sa dot::Parser
 */
class Lexer {
private:
	std::istream &m_input;

	std::string m_buffer; // Current line of given file.
	size_t m_row, m_col; // Current position in parsed file.

	std::vector<Token> m_tokens;

	bool tokenizeLine();

	//! Checks if \a head matches given token. Advances \a head on success.
	/**
	 * @param type A type of token being matched.
	 * @return True if matches, false otherwise.
	 */
	bool match(const Token::Type &type);
	//! Checks if \a head matches given string. Advances \a head on success.
	/**
	 * @param str A string being matched.
	 * @return True if matches, false otherwise.
	 */
	bool match(const std::string &str);
	//! Checks whether \a head is an identifier.
	/**
	 * @param token Function fills it with identifier value and col/row info.
	 * @return True if matches, false otherwise.
	 */
	bool identifier(Token &token);

public:
	//! Initializes lexer with given input (but does nothing to it).
	Lexer(std::istream &input);
	~Lexer();

	//! Scans input and turns it into token list.
	/**
	 * @return True if success, false otherwise.
	 */
	bool tokenize();
	//! Returns list of tokens (first use Lexer#tokenize())
	const std::vector<Token> &tokens() const;
};


} // end namespace dot

} // end namespace ogdf


#endif
