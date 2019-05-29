/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef SUPERNOVA2_STATE_H
#define SUPERNOVA2_STATE_H

#include "common/events.h"
#include "common/rect.h"
#include "common/keyboard.h"
#include "supernova2/rooms.h"
//#include "supernova2/sound.h"

namespace Supernova2 {

const int32 kMaxTimerValue = 0x7FFFFFFF;

struct GameState {
};

class GameManager {
public:
	GameManager(Supernova2Engine *vm);
	~GameManager();

	void updateEvents();
	void processInput(Common::KeyState &state);
	//void processInput();
	void executeRoom();

	Supernova2Engine *_vm;
	Common::KeyState _key;
	Common::EventType _mouseClickType;
	bool _mouseClicked;
	bool _keyPressed;
	int _mouseX;
	int _mouseY;
	Room *_currentRoom;
	bool _newRoom;
	Room *_rooms[NUMROOMS];
	GameState _state;
	bool _processInput;
	bool _guiEnabled;
	bool _animationEnabled;
	uint _timePaused;
	bool _timerPaused;
	int32 _messageDuration;
	int32 _animationTimer;
	int _inventoryScroll;
	int _exitList[25];
	// Dialog
	int _currentSentence;
	int _sentenceNumber[6];
	byte _rows[6];
	byte _rowsStart[6];

	void initState();
	void initRooms();
	void getInput();
	void changeRoom(RoomId id);
	void wait(int ticks);
	void waitOnInput(int ticks);
	bool waitOnInput(int ticks, Common::KeyCode &keycode);
	void resetInputState();

private:
	int _prevImgId;
};

}

#endif // SUPERNOVA2_STATE_H