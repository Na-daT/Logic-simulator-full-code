#ifndef _COPY_PASTE_H
#define _COPY_PASTE_H


#include "action.h"
#include "..\Components\Component.h"



class CopyPaste : public Action
{
private:
	int Vx, Vy;
	int m1, n1, m2, n2;

public:
	CopyPaste(ApplicationManager* pApp);
	virtual ~CopyPaste(void);

	//Reads parameters required for action to copy
	virtual void ReadCopiedCompParameters();
	//Execute action (code depends on action type)
	virtual void Copy();

	virtual void Undo();
	virtual void Redo();


};

#endif
