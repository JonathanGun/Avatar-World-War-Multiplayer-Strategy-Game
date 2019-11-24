#include "game_stackt.h"

void CreateEmptyStackt (GameStack *S)
{
	TopStackt(*S) = 0;
}

boolean IsEmptyStackt (GameStack S)
{
	return (TopStackt(S) == 0);
}

void PushStackt ()
{
	GameCondition newGc;
	CopyGameConditions(InfoTopStackt(G.GameConditions), &newGc);
	TopStackt(G.GameConditions)++;
	InfoTopStackt(G.GameConditions) = newGc; 
}

void PopStackt ()
{
	TopStackt(G.GameConditions)--;
}

void ResetStackt() {
	G.GameConditions.T[0] = InfoTopStackt(G.GameConditions);
	TopStackt(G.GameConditions) = 0;
}