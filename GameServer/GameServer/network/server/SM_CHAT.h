////////////////////////////////////////////////
// Authors: Tahoma, Karyzir, Lastfun
////////////////////////////////////////////////

#ifndef _SM_CHAT_H_
#define _SM_CHAT_H_

inline void SM_CHAT(PACKET* pck, char* str, bool isGMmsg = false)
{
	pck->CreateBufForSend();
	if (isGMmsg)
	{
		pck->writeB(CHAT_BULLHORN);
		pck->writeB(0); // unk
		WCHAR strSystem[] = L"GM";
		pck->writeBuf(strSystem, 20);
	}
	else
	{
		pck->writeB(CHAT_WHITEMESSAGE);
		pck->writeB(0); // unk
		pck->writeBuf(mychar->charname, 20);
	}
	pck->writeW(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(1);
	pck->writeD(mychar->id);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0xff);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeD(0);
	pck->writeW(0);
	pck->writeTstr(str, true);
	pck->writeD(0);
	pck->PackSend(OPCODE_SM_CHAT);
}
/*
1103 0000
014E
5400610068006F006D0061003200000000000000
0000
00000000
00000000
00000000
00000000
05000000   ................
0FFB0480
00000000
FF000000
00000000   ................
00000000
00000000
00000000
0287813F   ...............?
01000000
6045D46F
0100
1000
31 31 31 31   ....`E.o....1111
31 31 31 31 31 31 31 31 31 31 31 31 00 00 00 00   111111111111....
*/
#endif

