/* tools.cpp - List & description of all supported tools
 * Copyright (C) 2009 The ScummVM project
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $URL
 * $Id
 *
 */

#include "wx/wxprec.h"

#ifdef __BORLANDC__
	#pragma hdrstop
#endif

#ifndef WX_PRECOMP
	#include "wx/wx.h"
#endif

#include <algorithm>

#include "tools.h"

Tools g_tools;

Tools::Tools() {

	// Compression tools

	// Compress agos also has a --mac parameter, need to add an additional page / option for this
	Tool compress_agos(wxT("compress_agos"), wxT("*."));
	compress_agos.addGame(wxT("Feeble Files")),
	compress_agos.addGame(wxT("Simon the Sorcerer I/II")),
	addTool(compress_agos);

	// compress_gob
	Tool compress_gob(wxT("compress_gob"), wxT("*.*"));
	addTool(compress_gob);

	// compress_kyra
	Tool compress_kyra(wxT("compress_kyra"), wxT("*.*"));
	compress_kyra.addGame(wxT("The Legend of Kyrandia")),
	compress_kyra.addGame(wxT("The Legend of Kyrandia: Hand of Fate")),
	compress_kyra.addGame(wxT("The Legend of Kyrandia: Malcolm's Revenge")),
	compress_kyra.addGame(wxT("Lands of Lore: The Throne of Chaos")),
	addTool(compress_kyra);

	// compress_queen
	Tool compress_queen(wxT("compress_queen"), wxT("queen.1"));
	compress_queen.addGame(wxT("Flight of the Amazon Queen")),
	addTool(compress_queen);

	// compress_saga
	Tool compress_saga(wxT("compress_saga"), wxT("*.*"));
	compress_saga.addGame(wxT("SAGA: Inherit The Earth")),
	compress_saga.addGame(wxT("I Have No Mouth and I Must Scream")),
	addTool(compress_saga);

	// compress_scumm_bun
	Tool compress_scumm_bun(wxT("compress_scumm_bun"), wxT("*.*"));
	compress_scumm_bun.addGame(wxT("The Secret of Monkey Island")),
	compress_scumm_bun.addGame(wxT("Monkey Island 2: LeChuck's Revenge")),
	compress_scumm_bun.addGame(wxT("The Curse of Monkey Island")),
	addTool(compress_scumm_bun);

	// compress_scumm_san
	Tool compress_scumm_san(wxT("compress_scumm_san"), wxT("*.*"));
	// Unsure of exact games...
	addTool(compress_scumm_san);

	// compress_scumm_sou
	Tool compress_scumm_sou(wxT("compress_scumm_san"), wxT("*.*"));
	// Unsure of exact games...
	addTool(compress_scumm_sou);

	// compress_sword1
	Tool compress_sword1(wxT("compress_sword1"), wxT("*.*"));
	compress_sword1.addGame(wxT("Broken Sword 1")),
	addTool(compress_sword1);

	// compress_sword2
	Tool compress_sword2(wxT("compress_sword2"), wxT("*.*"));
	compress_sword2.addGame(wxT("Broken Sword 2")),
	addTool(compress_sword2);

	// compress_touche
	Tool compress_touche(wxT("compress_touche"), wxT("*.*"));
	compress_touche.addGame(wxT("Touche: The Adventures of the Fifth Musketeer")),
	addTool(compress_touche);

	// compress_tucker
	Tool compress_tucker(wxT("compress_tucker"), wxT("*.*"));
	compress_tucker.addGame(wxT("Bud Tucker in Double Trouble")),
	addTool(compress_tucker);

	// Extraction tools

	// Compress agos also has a --mac parameter, need to add an additional page / option for this
	Tool extract_agos(wxT("extract_agos"), wxT("*."));
	extract_agos.addGame(wxT("Feeble Files")),
	extract_agos.addGame(wxT("Simon the Sorcerer I/II")),
	addTool(extract_agos);

	// extract_gob_stk
	Tool extract_gob_stk(wxT("extract_gob_stk"), wxT("*.*"));
	addTool(extract_gob_stk);

	// extract_kyra
	Tool extract_kyra(wxT("extract_kyra"), wxT("*.*"));
	extract_kyra.addGame(wxT("The Legend of Kyrandia")),
	extract_kyra.addGame(wxT("The Legend of Kyrandia: Hand of Fate")),
	extract_kyra.addGame(wxT("The Legend of Kyrandia: Malcolm's Revenge")),
	extract_kyra.addGame(wxT("Lands of Lore: The Throne of Chaos")),
	addTool(extract_kyra);

	// extract_loom_tg16
	Tool extract_loom_tg16(wxT("extract_loom_tg16"), wxT("*.iso")); // Unsure of extension?
	extract_loom_tg16.addGame(wxT("Loom")),
	addTool(extract_loom_tg16);

	// extract_mm_apple
	Tool extract_mm_apple(wxT("extract_mm_apple"), wxT("*.dsk"));
	extract_mm_apple.addGame(wxT("Maniac Mansion (Apple)")),
	addTool(extract_mm_apple);

	// extract_mm_nes
	Tool extract_mm_c64(wxT("extract_mm_c64"), wxT("*.d64"));
	extract_mm_c64.addGame(wxT("Maniac Mansion (Commodore 64)")),
	addTool(extract_mm_c64);

	// extract_mm_nes
	Tool extract_mm_nes(wxT("extract_mm_nes"), wxT("*.PRG"));
	extract_mm_nes.addGame(wxT("Maniac Mansion (NES)")),
	addTool(extract_mm_nes);

	// extract_sword2
	Tool extract_parallaction(wxT("extract_parallaction"), wxT("*.*"));
	extract_parallaction.addGame(wxT("Parallaction")),
	addTool(extract_parallaction);

	// extract_scumm_mac
	Tool extract_scumm_mac(wxT("extract_scumm_mac"));
	// Required for alot of games, but as ScummVM 0.6 + can read 
	// these files natively, it can remain an advanced option
	addTool(extract_scumm_mac);

	// extract_zak_c64
	Tool extract_zak_c64(wxT("extract_zak_c64"), wxT(".d64"));
	extract_zak_c64.addGame(wxT("Bud Tucker in Double Trouble")),
	addTool(extract_zak_c64);
}

void Tools::addTool(const Tool& tool) {
	tools[tool._name] = tool;
}

wxArrayString Tools::getToolList(ToolType tt) const {
	wxArrayString l;
	for(std::map<wxString, Tool>::const_iterator iter = tools.begin(); iter != tools.end(); ++iter)
		if(tt == TOOLTYPE_ALL || iter->second._type == tt)
			l.Add(iter->first);
	l.Sort();
	std::unique(l.begin(), l.end());
	return l;
}

wxArrayString Tools::getGameList(ToolType tt) const {
	wxArrayString l;
	for(std::map<wxString, Tool>::const_iterator iter = tools.begin(); iter != tools.end(); ++iter)
		if(tt == TOOLTYPE_ALL || iter->second._type == tt)
			for(wxArrayString::const_iterator citer = iter->second._games.begin(); citer != iter->second._games.end(); ++citer)
				l.Add(*citer);
	l.Sort();
	std::unique(l.begin(), l.end());
	return l;
}

const Tool &Tools::operator[](const wxString& name) const {
	std::map<wxString, Tool>::const_iterator iter = tools.find(name);

	wxASSERT_MSG(iter != tools.end(), wxT("All tools should be added, never try to access a tool that does not exist."));

	return iter->second;
}

const Tool *Tools::get(const wxString& name) const {
	std::map<wxString, Tool>::const_iterator iter = tools.find(name);

	if(iter == tools.end())
		return NULL;

	return &iter->second;
}

const Tool *Tools::getByGame(const wxString &gamename) const {
	for(std::map<wxString, Tool>::const_iterator iter = tools.begin(); iter != tools.end(); ++iter)
		for(wxArrayString::const_iterator citer = iter->second._games.begin(); citer != iter->second._games.end(); ++citer)
			if(*citer == gamename)
				return &iter->second;
	return NULL;
}


// The Tool class

Tool::Tool() {
	// Seems std is allowed to create dummy objects in maps.
	//wxLogError(wxT("Created empty tool, should never happened."));
}

Tool::Tool(wxString name, wxString input_extensions) {
	_name = name;

	if(name.Find(wxT("extract")) != wxNOT_FOUND)
		_type = TOOLTYPE_EXTRACTION;
	else if(name.Find(wxT("compress")) != wxNOT_FOUND)
		_type = TOOLTYPE_COMPRESSION;
	else {
		wxLogError(wxT("Tools with unknown type shouldn't exist."));
		_type = TOOLTYPE_UNKNOWN;
	}
	
	// Sensible defaults
	_supportedFormats = AUDIO_ALL;
	ToolInput input;
	input._extension = input_extensions;
	input._file = true;
	_inputs.push_back(input);

	_outputToDirectory = true;
	_inoutHelpText = wxT("Output files produced by the tool will be put in this directory.");
}

void Tool::addGame(const wxString &game_name) {
	_games.Add(game_name);
}

bool Tool::supportsAudioFormat(AudioFormat format) {
	return (_supportedFormats & format) == format;
}

bool Tool::pickFiles() {
	for(ToolInputs::const_iterator iter = _inputs.begin(); iter != _inputs.end(); ++iter)
		if(iter->_file)
			return true;
	return false;
}

bool Tool::pickDirs() {
	return !pickFiles();
}

wxString Tool::getExecutable() {
#ifdef WIN32
	return _name + wxT(".exe");
#else
	return _name;
#endif
}
