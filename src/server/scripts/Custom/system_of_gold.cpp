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
 
#include "../../../scripts/ScriptPCH.h"
#define FFA_ENTER_MSG "You entered a rivalry area."
#define KILL_MSG "Good job you killed someone."
#define LOST_GOLD_MSG "You lost the gold."
#define ERR_TOO_MUCH_MONEY "You have a lot of money."

enum Rewards
{
	FFA_REWARD    = 20000,
	NORMAL_REWARD = 10000,
	FFA_LOST      = 10000
};
class Gold_System : public PlayerScript
{
public:
	Gold_System() : PlayerScript("Gold_System") {}


	void OnUpdateZone(Player* player, uint32 zone, uint32 area)
	{
		if (player->pvpInfo.IsHostile) //gets updated by UpdatePvPState
		{
			ChatHandler handler(player->GetSession());
			handler.PSendSysMessage(FFA_ENTER_MSG);
		}
	}
	void OnPVPKill(Player* killer, Player* victim)
	{
		ChatHandler kHandler(killer->GetSession());
		ChatHandler vHandler(victim->GetSession());
		if (killer->pvpInfo.IsHostile && victim->pvpInfo.IsHostile) //gets updated by UpdatePvPState
		{
			if(killer->GetMoney() + FFA_REWARD < MAX_MONEY_AMOUNT)
			{
			killer->SetMoney(killer->GetMoney() + FFA_REWARD);
			kHandler.PSendSysMessage(KILL_MSG);
			}
			else
				kHandler.PSendSysMessage(ERR_TOO_MUCH_MONEY);
			if(victim->GetMoney() - FFA_LOST > 0)
			{
				victim->SetMoney(victim->GetMoney() - FFA_LOST);
				vHandler.PSendSysMessage(LOST_GOLD_MSG);
			}
		}
		else
		{
			if(killer->GetMoney() + NORMAL_REWARD < MAX_MONEY_AMOUNT)
			{
			killer->SetMoney(killer->GetMoney() + NORMAL_REWARD);
			kHandler.PSendSysMessage(KILL_MSG);
			}
			else
				kHandler.PSendSysMessage(ERR_TOO_MUCH_MONEY);
		}
	}
};

void AddSC_Gold_System()
{
	new Gold_System();
}
