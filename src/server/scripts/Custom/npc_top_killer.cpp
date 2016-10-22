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

class JC_TopKills : public CreatureScript
{
public:
	JC_TopKills() : CreatureScript("JC_TopKills") { }

	bool OnGossipHello(Player* player, Creature * creature)
	{
		AddGossipItemFor(player, 10, "|TInterface\\icons\\Achievement_BG_winWSG:35:35:-14|tTop 5 Total Kills", GOSSIP_SENDER_MAIN, 1);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\INV_Sword_27:35:35:-14|tWarrior", GOSSIP_SENDER_MAIN, 2);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\Spell_Holy_DivineIntervention:35:35:-14|tPaladin", GOSSIP_SENDER_MAIN, 3);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\INV_Weapon_Bow_07:35:35:-14|tHunter", GOSSIP_SENDER_MAIN, 4);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\INV_ThrowingKnife_04:35:35:-14|tRogue", GOSSIP_SENDER_MAIN, 5);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\INV_Staff_30:35:35:-14|tPriest", GOSSIP_SENDER_MAIN, 6);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\Spell_Deathknight_ClassIcon:35:35:-14|tDeath Knight", GOSSIP_SENDER_MAIN, 7);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\Spell_Nature_BloodLust:35:35:-14|tShaman", GOSSIP_SENDER_MAIN, 8);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\INV_Staff_13:35:35:-14|tMage", GOSSIP_SENDER_MAIN, 9);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\Spell_Nature_Drowsy:35:35:-14|tWarlock", GOSSIP_SENDER_MAIN, 10);
		AddGossipItemFor(player, 10, "|TInterface\\icons\\INV_Misc_MonsterClaw_04:35:35:-14|tDruid", GOSSIP_SENDER_MAIN, 11);
		SendGossipMenuFor(player, 1, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 actions)
	{
		if (sender == GOSSIP_SENDER_MAIN)
		{
			switch (actions)
			{

			case 1: // TOP 5 TOTAL
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\Achievement_BG_winWSG:20:20|t |cffFF0000Top 5 Total Kills|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 2: // TOP 5 WARRIOR
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='1' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\INV_Sword_27:20:20|t |cffFF0000Top 5 Warrior|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 3: // TOP 5 PALADIN
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='2' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\Spell_Holy_DivineIntervention:20:20|t |cffFF0000Top 5 Paladin|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 4: // TOP 5 HUNTER
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='3' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\INV_Weapon_Bow_07:20:20|t |cffFF0000Top 5 Hunter|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 5: // TOP 5 ROGUE
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='4' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\INV_ThrowingKnife_04:20:20|t |cffFF0000Top 5 Rogue|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 6: // TOP 5 PRIEST
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='5' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\INV_Staff_30:20:20|t |cffFF0000Top 5 Priest|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 7: // TOP 5 DEATH KNIGHT
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='6' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\Spell_Deathknight_ClassIcon:20:20|t |cffFF0000Top 5 Death Knight|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 8: // TOP 5 SHAMAN
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='7' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\Spell_Nature_BloodLust:20:20|t |cffFF0000Top 5 Shaman|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 9: // TOP 5 MAGE
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='8' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\INV_Staff_13:20:20|t |cffFF0000Top 5 Mage");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 10: // TOP 5 WARLOCK
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='9' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\Spell_Nature_Drowsy:20:20|t |cffFF0000Top 5 Warlock|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;

			case 11: // TOP 5 DRUID
			{
				QueryResult result = CharacterDatabase.Query("SELECT name,totalKills FROM characters WHERE class='11' ORDER BY totalKills DESC LIMIT 5");
				if (!result)
					return false;

				Field * fields = NULL;
				ChatHandler(player->GetSession()).SendSysMessage("|TInterface\\icons\\INV_Misc_MonsterClaw_04:20:20|t |cffFF0000Top 5 Druid|r");
				do
				{
					fields = result->Fetch();
					string arena_name = fields[0].GetString();
					uint32 rating = fields[1].GetUInt32();
					char msg[250];
					snprintf(msg, 250, "Name: |cffFF0000%s|r Kills: |cffFF0000%u|r ", arena_name.c_str(), rating);
					ChatHandler(player->GetSession()).SendSysMessage(msg);
					player->PlayerTalkClass->SendCloseGossip();
				} while (result->NextRow());
			}
			break;


			}
		}

		return true;
	}
};

void AddSC_JC_TopKills()
{
	new JC_TopKills;
}