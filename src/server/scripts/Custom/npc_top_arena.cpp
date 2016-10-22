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

#include "ScriptMgr.h"
#include "Player.h"
using namespace std;

class JC_TopArena : public CreatureScript
{
public:
	JC_TopArena() : CreatureScript("JC_TopArena") { }

	bool OnGossipHello(Player* player, Creature * creature)
	{
		AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\icons\\Achievement_BG_trueAVshutout:35:35:-14|tTop 5 Arena 1v1", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\icons\\Achievement_Arena_2v2_7:35:35:-14|tTop 5 Arena 2v2", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		AddGossipItemFor(player, GOSSIP_ICON_CHAT, "|TInterface\\icons\\Achievement_Arena_3v3_7:35:35:-14|tTop 5 Arena 3v3", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
		SendGossipMenuFor(player, 1, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 actions)
	{
		if (sender == GOSSIP_SENDER_MAIN)
		{
			switch (actions)
			{
				// ARENA 1v1
			case GOSSIP_ACTION_INFO_DEF + 1:
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,rating FROM arena_team WHERE type='1' ORDER BY rating DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\Achievement_BG_trueAVshutout:15:15|t |cffFF0000Top 5 Arena 1v1|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Team: |cffFF0000%s|r Rating: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}break;

				// ARENA 2v2
			case GOSSIP_ACTION_INFO_DEF + 2:
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,rating FROM arena_team WHERE type='2' ORDER BY rating DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\Achievement_Arena_2v2_7:15:15|t |cffFF0000Top 5 Arena 2v2|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Team: |cffFF0000%s|r Rating: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}break;

				// ARENA 3v3
			case GOSSIP_ACTION_INFO_DEF + 3:
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,rating FROM arena_team WHERE type='3' ORDER BY rating DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\Achievement_Arena_3v3_7:15:15|t |cffFF0000Top 5 Arena 3v3|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Team: |cffFF0000%s|r Rating: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}break;

			}
		}

		return true;
	}
};

void AddSC_JC_TopArena()
{
	new JC_TopArena;
}