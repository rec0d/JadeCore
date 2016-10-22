/*
 * Copyright (C) 2013-2016 JadeCore <https://www.jadecore.tk/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

// This is where scripts' loading functions should be declared:
void AddSC_NoFarming();
void AddSC_System_Censure();
void AddSC_XpWeekend();
void AddSC_Reset();
void AddSC_TemplateNPC();
void AddSC_JC_NpcMorph();
void AddSC_JC_Tools_NPC();
void AddSC_JC_TopArena();
void AddSC_JC_TopHonor();
void AddSC_JC_TopKills();
void AddSC_transmogriefer();
void AddSC_NPC_VisualWeapon();
void AddSC_weptransmog();
void AddSC_Arena_AntiDraw();
void AddSC_Gold_System();
void AddSC_PvPTitles();
void AddSC_VIP_NPC();

// The name of this function should match:
// void Add${NameOfDirectory}Scripts()
void AddCustomScripts()
{
	
	AddSC_NoFarming();
	AddSC_System_Censure();
	AddSC_XpWeekend();
	AddSC_Reset();
	AddSC_TemplateNPC();
	AddSC_JC_NpcMorph();
	AddSC_JC_Tools_NPC();
	AddSC_JC_TopArena();
	AddSC_JC_TopHonor();
	AddSC_JC_TopKills();
	AddSC_transmogriefer();
	AddSC_NPC_VisualWeapon();
	AddSC_weptransmog();
	AddSC_Arena_AntiDraw();
	AddSC_Gold_System();
	AddSC_PvPTitles();
	AddSC_VIP_NPC();

}