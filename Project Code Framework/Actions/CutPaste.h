/*#ifndef _CUT_PASTE_H
#define _CUT_PASTE_H


#include "action.h"
#include "..\Components\Component.h"



class CutPaste : public Action
{
private:
	int Vx, Vy;
	int m1, n1, m2, n2;

public:
	CutPaste(ApplicationManager* pApp);
	virtual ~CutPaste(void);

	//Reads parameters required for action to copy
	virtual void ReadCopiedCompParameters();
	//Execute action (code depends on action type)
	virtual void Cut();

	virtual void Undo();
	virtual void Redo();


};

#endif
*/
