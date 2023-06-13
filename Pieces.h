#pragma once

//	------------------------------------------------------
//	Pieces Class
//
// 
//	Class that stores the 7 different types of tetris pieces:
// 
//	Square (Yellow), Line (Cyan), T (Purple), L (Orange), J (Blue),
//  S (Green), and Z (Red).
//	------------------------------------------------------

class Pieces {
public:
	// Returns one of 3:
	// 0 = no blocks
	// 1 = normal block
	// 2 = pivot block (block that pieces rotates around)
	int getBlockType(int pPiece, int pRotation, int pX, int pY);
};

